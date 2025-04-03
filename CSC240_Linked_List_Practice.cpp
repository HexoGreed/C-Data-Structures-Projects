//============================================================================
// Name        : CSC240_Linked_List_Practice.cpp
// Author      : Ivan Temesvari
// Version     : 2/11/2019
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "unsorted.h"
using namespace std;
//This function removes all instances of ItemType item from list,
//and returns a list without those items.
UnsortedType DeleteAllItems(UnsortedType& list, ItemType item){
	UnsortedType listWithoutItem;
	list.ResetList();
	for(int i = 0; i < list.GetLength(); i++){
		ItemType temp = list.GetNextItem();
		if(temp.ComparedTo(item) != EQUAL){
			listWithoutItem.PutItem(temp);
		}
	}
	return listWithoutItem;
}


//Write a function that returns a list of all instances of item
//found in an UnsortedType linked-list.
UnsortedType FindAllItems(UnsortedType& list, ItemType item){
	UnsortedType itemsFound;
	list.ResetList();
	for(int i = 0; i < list.GetLength(); i++){
		ItemType temp = list.GetNextItem();
		if(temp.ComparedTo(item) == EQUAL){
			itemsFound.PutItem(temp);
		}
	}
	return itemsFound;
}

int main() {
	/*
	UnsortedType myList;
	myList.PutItem(ItemType(8));
	myList.PutItem(ItemType(5));
	myList.PutItem(ItemType(2));
	myList.PutItem(ItemType(5));
	myList.PutItem(ItemType(7));
	myList.PutItem(ItemType(3));
	myList.PutItem(ItemType(5));
	myList.Print();
	FindAllItems(myList, ItemType(5)).Print();
	DeleteAllItems(myList, ItemType(5)).Print();
	UnsortedType newList;
	newList.PutItem(ItemType(9));
	newList.PutItem(ItemType(7));
	newList.PutItem(ItemType(2));
	newList.PutItem(ItemType(3));
	newList.PutItem(ItemType(4));
	newList.PutItem(ItemType(6));
	newList.PutItem(ItemType(1));
	cout << "Before assignment: " << endl;
	newList.Print();
	newList = myList;   //use the overloaded assignment operator
	cout << "After assignment: " << endl;
	newList.Print();
	myList.Print();
	UnsortedType copy(myList);   //use the copy constructor
	copy.Print();
	//if the copy constructor is not implemented, the following assignment will be shallow copy
	UnsortedType otherList = copy;   //NOT the assignment operator, but copy constructor
	cout << "otherList should have the same contents of copy." << endl;
	otherList.Print();
	cout << "copy." << endl;
	copy.DeleteItem(ItemType(3));
	copy.Print();
	cout << "otherList should NOT have the same contents of copy." << endl;
	otherList.Print();
	return 0;
	*/

	UnsortedType testList;
	int testValues[] = {5, -12, 34, 34, 5, 45, 8, -6, 15, 40, 20, 2, 1, 12};

	for (int val : testValues) {
		testList.PutItem(ItemType(val));
	}//filling the list with test vals

	UnsortedType list1, list2;
	ItemType splitItem(15);

	cout << "Original list: ";
	testList.Print();

	testList.SplitLists(testList, splitItem, list1, list2);

	cout << "List1 (<= 15): ";
	list1.Print();

	cout << "List2 (> 15): ";
	list2.Print();

	return 0;

}
