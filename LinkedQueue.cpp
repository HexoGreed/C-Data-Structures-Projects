#include "LinkedQueue.h"
#include <iostream>

LinkedQueueType::LinkedQueueType() : rear(nullptr), length(0) {}

LinkedQueueType::LinkedQueueType(const LinkedQueueType& qt) {
    rear = nullptr;
    length = 0;
    *this = qt; // Use assignment operator
}

LinkedQueueType LinkedQueueType::operator=(const LinkedQueueType& rhs) {
    if (this != &rhs) {
        MakeEmpty();
        if (!rhs.IsEmpty()) {
            NodeType* rhsCurrent = rhs.rear->next; // Starts at the front
            do {
                Enqueue(rhsCurrent->info);
                rhsCurrent = rhsCurrent->next;
            } while (rhsCurrent != rhs.rear->next); // Loop until we circle back
        }
    }
    return *this;
}

LinkedQueueType::~LinkedQueueType() {
    MakeEmpty();
}

void LinkedQueueType::MakeEmpty() {
    if (IsEmpty()) return;

    NodeType* current = rear->next; // Start at front
    rear->next = nullptr; // Break the circle to prevent infinite loops

    while (current != nullptr) {
        NodeType* temp = current;
        current = current->next;
        delete temp;
    }

    rear = nullptr;
    length = 0;
}


bool LinkedQueueType::IsEmpty() const {
    return rear == nullptr;
}

bool LinkedQueueType::IsFull() const {
    NodeType* temp;
    try {
        temp = new NodeType;
        delete temp;
        return false;
    }
    catch (std::bad_alloc&) {
        return true;
    }
}

void LinkedQueueType::Enqueue(ItemType newItem) {
    if (IsFull()) {
        throw FullQueue();
    }

    NodeType* newNode = new NodeType;
    newNode->info = newItem;

    if (IsEmpty()) {
        newNode->next = newNode; // Point to self
        rear = newNode;
    }
    else {
        newNode->next = rear->next; // New node points to front
        rear->next = newNode;       // Current rear points to new node
        rear = newNode;             // Update rear to new node
    }
    length++;
}

void LinkedQueueType::Dequeue(ItemType& item) {
    if (IsEmpty()) {
        throw EmptyQueue();
    }

    NodeType* front = rear->next;
    item = front->info;

    if (front == rear) { // Only one item
        delete front;
        rear = nullptr;
    }
    else {
        rear->next = front->next;
        delete front;
    }
    length--;
}

void LinkedQueueType::Print() {
    if (IsEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }

    NodeType* current = rear->next; // Start at front
    do {
        std::cout << current->info << " ";
        current = current->next;
    } while (current != rear->next); // Loop until we circle back
    std::cout << std::endl;
}
