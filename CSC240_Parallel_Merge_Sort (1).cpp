//
//  main.cpp
//  Thread_Sort
//
//  Created by Charles Weems on 1/12/16.
//  Copyright © 2016 Charles Weems. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <thread>
#include <chrono>

using namespace std;

const int MAX_ITEMS = 20000000;  //twenty million
int numbers[MAX_ITEMS];
int temp[MAX_ITEMS];
int chunk;
unsigned int maxthreads = thread::hardware_concurrency();// 5.2


template<class ItemType>
void Merge(ItemType values[], int leftFirst, int leftLast,
           int rightFirst, int rightLast, ItemType tempArray[])
// Post: values[leftFirst]..values[leftLast] and
//       values[rightFirst]..values[rightLast] have been merged.
//       values[leftFirst]..values[rightLast] are now sorted.
{
    int index = leftFirst;
    int saveFirst = leftFirst;
    while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
    {
        if (values[leftFirst] < values[rightFirst])
        {

            tempArray[index] = values[leftFirst];
            leftFirst++;
        }
        else
        {
            tempArray[index] = values[rightFirst];
            rightFirst++;
        }
        index++;
    }
    while (leftFirst <= leftLast)
        // Copy remaining items from left half.
    {
        tempArray[index] = values[leftFirst];
        leftFirst++;
        index++;
    }
    while (rightFirst <= rightLast)
        // Copy remaining items from right half.
    {
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
    }
    for (index = saveFirst; index <= rightLast; index++)
        values[index] = tempArray[index];
}

template<class ItemType>
void SerialMergeSort(ItemType values[], int first, int last, ItemType tempArray[])
// Post: The elements in values are sorted by key.
{
    if (first < last)
    {
        int middle = (first + last) / 2;
        SerialMergeSort<ItemType>(values, first, middle, tempArray);
        SerialMergeSort<ItemType>(values, middle + 1, last, tempArray);
        Merge<ItemType>(values, first, middle, middle + 1, last, tempArray);
    }
}

template<class ItemType>
void ParallelMergeSort(ItemType values[], int first, int last, ItemType tempArray[], int chunkSize, int numThreads)
{
    if (first < last)
    {
        int middle = (first + last) / 2;
        if (last - first > chunkSize && numThreads > 1) // If enough work left, launch more threads
        {
            int leftLast = middle;
            int rightFirst = middle + 1;


            int leftR = middle - first + 1;
            int rightR = last - middle;


            int leftThreads = std::min(numThreads / 2, leftR / chunkSize);
            int rightThreads = std::min(numThreads - leftThreads, rightR / chunkSize);


            std::thread left(ParallelMergeSort<ItemType>, values, first, leftLast, tempArray, chunkSize, leftThreads);
            std::thread right(ParallelMergeSort<ItemType>, values, rightFirst, last, tempArray, chunkSize, rightThreads);


            left.join();
            right.join();
        }else {                                          // Otherwise finish sorting locally
            // Otherwise finish sorting locally
            SerialMergeSort<ItemType>(values, first, middle, tempArray);
            SerialMergeSort<ItemType>(values, middle + 1, last, tempArray);
        }

        Merge<ItemType>(values, first, middle, middle + 1, last, tempArray);
    }
}


int main(int argc, const char * argv[]) {
    chrono::time_point<chrono::system_clock> start;
    chrono::time_point<chrono::system_clock> end;

    // Initialize the array with random integers
    for (int index = 0; index < MAX_ITEMS; index++) {
        numbers[index] = rand() % 1000000000;
    }

    cout << "Enter chunk size (<= " << MAX_ITEMS / maxthreads << "): ";
    cin >> chunk;

    start = chrono::system_clock::now();           // Record start time

    ParallelMergeSort<int>(numbers, 0, MAX_ITEMS - 1, temp, chunk, maxthreads);         // Run the sort

    end = chrono::system_clock::now();             // Record end time

    chrono::duration<float> elapsed = end - start;   // Calculate and report time
    cout << "Done sorting\n";
    cout << "Execution time in seconds = " << elapsed.count() << "\n";

    return 0;

}
