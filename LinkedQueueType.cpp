#include "LinkedQueueType.h"
#include <iostream>
using namespace std;

LinkedQueueType::LinkedQueueType(const LinkedQueueType& qt) {
	// copy constructor
	if (qt.rear != nullptr) {
		NodeType* originalNode = qt.rear->next; // start
		do {
			Enqueue(originalNode->info); // Enqueue each thing in the q
			originalNode = originalNode->next;
		} while (originalNode != qt.rear->next); // Stop at front 
	}
}



LinkedQueueType LinkedQueueType::operator=(const LinkedQueueType& rhs){
	//assignment operator=
	if (this != &rhs) { 
		MakeEmpty(); // Clear the Q

		if (rhs.rear != nullptr) {
			NodeType* originalNode = rhs.rear->next;//front 
			do {
				Enqueue(originalNode->info); // inserting element into q
				originalNode = originalNode->next;
			} while (originalNode != rhs.rear->next); // stop when front
		}
	}
	return *this;
}

LinkedQueueType::LinkedQueueType()          // Default class constructor
// Post: rear has been initialized.
{
	rear = nullptr;
	length = 0;
}
LinkedQueueType::~LinkedQueueType()         // Class destructor
{
	MakeEmpty();
}

void LinkedQueueType::MakeEmpty()
// Post: rear and length have been reset to the empty state.
{
	while (!IsEmpty()) {
		ItemType temp;
		Dequeue(temp);
	}
}

bool LinkedQueueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (length == 0);
}

bool LinkedQueueType::IsFull() const
// This structure can not get full.
{
  return false;
}

void LinkedQueueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue; newItem's next is front
//       otherwise a FullQueue exception is thrown.  
{

	NodeType* newNode = new NodeType;
	newNode->info = newItem;
	if (IsEmpty()) {
		rear = newNode;
		rear->next = rear;
	}
	else {
		newNode->next = rear->next;
		rear->next = newNode;
		rear = newNode;
	}
	length++;



}

void LinkedQueueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
	if (IsEmpty()) {
		throw "EmptyQueue exception";
	}
	NodeType* temp = rear->next;
	item = temp->info;
	if (rear == rear->next) {
		rear = nullptr;
	}
	else {
		rear->next = temp->next;
	}
	delete temp;
	length--;

}

void LinkedQueueType::Print(){
	if (IsEmpty()) {
		cout << "Queue is empty." << endl;
		return;
	}

	NodeType* node = rear->next;
	int count = 0;
	while(count < length){
		cout << node->info << " ";
		node = node->next;
		count++;
	}
	cout << endl;
}

//
// The methods below provide the range-based for loop support. These would
// be customized with the companion LinkedQueueTypeIterator class that is returned.
//
LinkedQueueTypeIterator LinkedQueueType::begin()
{
	//Complete this.
	if (rear == nullptr) {
		return LinkedQueueTypeIterator(nullptr, 0); // Empty queue
	}
	return LinkedQueueTypeIterator(rear->next, 0);

}

LinkedQueueTypeIterator LinkedQueueType::end()
{
	return LinkedQueueTypeIterator(nullptr, length);
	//Complete this.
}
