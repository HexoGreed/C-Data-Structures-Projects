//============================================================================
// Name        : CSC240SortedArray.cpp
// Author      : Ivan Temesvari
// Date        : 2/24/2020
//============================================================================

#include <iostream>
#include "sorted.h"

using namespace std;

int main() {

	SortedType myList;
	cout << "Initial capacity: " << myList.GetCapacity() << endl;



	ItemType item1;
	item1.Initialize(12);
	myList.PutItem(item1);

	ItemType item2;
	item2.Initialize(19);
	myList.PutItem(item2);

	ItemType item3;
	item3.Initialize(26);
	myList.PutItem(item3);

	ItemType item4;
	item4.Initialize(45);
	myList.PutItem(item4);

	ItemType item5;
	item5.Initialize(80);
	myList.PutItem(item5);



	cout << "List after adding 5 items: " << myList << endl;
	cout << "Current capacity: " << myList.GetCapacity() << endl;


	ItemType item6;
	item6.Initialize(100);
	myList.PutItem(item6);


	cout << "List after adding 6th item: " << myList << endl;
	cout << "Current capacity: " << myList.GetCapacity() << endl;



	ItemType item7;
	item1.Initialize(1122);
	myList.PutItem(item1);

	ItemType item8;
	item2.Initialize(1129);
	myList.PutItem(item2);

	ItemType item9;
	item3.Initialize(2326);
	myList.PutItem(item3);

	ItemType item10;
	item4.Initialize(4523);
	myList.PutItem(item4);

	cout << "List after adding 10 items: " << myList << endl;
	cout << "Current capacity: " << myList.GetCapacity() << endl; 


	ItemType item11;
	item5.Initialize(8090213);
	myList.PutItem(item5);

	cout << "List after adding 11th item: " << myList << endl;
	cout << "Current capacity: " << myList.GetCapacity() << endl;


	return 0;




	/*SortedType myList;
	cout << myList.GetMaxLength() << endl;
	++myList;    //unary operator, pre-increment operator++. The size of the list is increased by 1.
	myList++;     //unary operator, post-increment operator++. The size of the list is increased by 1.
	cout << myList.GetMaxLength() << endl;

	ItemType item1;
	item1.Initialize(12);
	ItemType item2;
	item2.Initialize(19);
	ItemType item3;
	item3.Initialize(26);
	ItemType item4;
	item4.Initialize(45);
	ItemType item5;
	item5.Initialize(80);


	myList.PutItem(item1);
	myList.PutItem(item2);
	myList.PutItem(item3);
	myList.PutItem(item4);
	myList.PutItem(item5);
	cout << "myList: " << myList << endl;
	cout << "myList length: " << myList.GetMaxLength() << endl;

	//Find an item in the list.
	bool foundFlag = false;
	ItemType item;
	item.Initialize(45);
	myList.GetItem(item, foundFlag).Print(cout);
	if(foundFlag){
		cout << "\nThe item was found." << endl;
	}
	else{
		cout << "\nThe item was NOT found." << endl;
	}

	myList.DeleteItem(item3);
	cout << myList;

	/*
	ItemType delItem;
	delItem.Initialize(99);
	//What happens if I attempt to delete an item that is not stored in the array?
	myList.DeleteItem(delItem);
	cout << "The length of the list is: " << myList.GetLength() << endl;
	



	ItemType item7;
	item7.Initialize(2);
	myList.PutItem(item7);
	cout << myList;
	cout << myList.GetMaxLength() << endl;

	//Copy Constructor********
	//SortedType list(myList);
	SortedType list;
	//************************

	//operator=***************
	list = myList;
	//************************

	int dotProduct = myList*list;
	cout << "Dot product = " << dotProduct << endl;

	SortedType list2;
	list2.PutItem(item1);
	list2.PutItem(item2);
	list2.PutItem(item3);
	list2.PutItem(item4);

	int dotProduct2 = myList*list2;
	cout << "Dot product = " << dotProduct2 << endl;

	return 0;
	*/
}
