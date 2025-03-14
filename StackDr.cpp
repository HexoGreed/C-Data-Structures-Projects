#include <iostream>
#include <fstream>
#include "StackTypeArr.h"
using namespace std;
//Implement ReplaceItem and Identical here in the driver file.


template <class ItemType>
void ReplaceItem(StackTypeArr<ItemType>& stack, ItemType oldItem, ItemType newItem) {
	// Create a temporary stack to hold items
	StackTypeArr<ItemType> tempStack(stack.GetMaxStack());

	// Pop items from the original stack and pushes them onto the temp stack
	// replacws old item with new item
	while (!stack.IsEmpty()) {
		ItemType item = stack.Top();
		stack.Pop();
		if (item == oldItem) {
			tempStack.Push(newItem);
		}
		else {
			tempStack.Push(item);
		}
	}

	// Pop items from the temporary stack and push them back onto the original stack
	while (!tempStack.IsEmpty()) {
		stack.Push(tempStack.Top());
		tempStack.Pop();
	}
}


	// Pop items from the temporary stack and push them back onto the original stack
	template <class ItemType>
	bool Identical(const StackTypeArr<ItemType>& stack1, const StackTypeArr<ItemType>& stack2) {
		if (stack1.top != stack2.top) {
			return false;
		}

		for (int i = 0; i <= stack1.top; i++) {
			if (stack1.items[i] != stack2.items[i]) {
				return false;
			}
		}

		return true;
	}




int main()
{
	try {
		StackTypeArr<int> stack;
		stack.Print();

		stack.Push(4);
		stack.Push(4);
		stack.Push(5);
		stack.Push(4);
		stack.Push(3);
		stack.Push(4);
		stack.Print();
		ReplaceItem(stack, 4, 8);
		stack.Print();
		StackTypeArr <int> myStack;
		myStack.Print();
		myStack.Push(4);
		myStack.Push(4);
		myStack.Push(5);
		myStack.Push(4);
		myStack.Push(3);
		myStack.Push(4);
		myStack.Print();
		if (Identical(stack, myStack)) {
			cout << "The stacks are identical." << endl;
		}
		else {
			cout << "The stacks are NOT identical." << endl;
		}
	}
	catch (const FullStack& e)
	{
		cout << "Stack is full!" << endl;
	}
	catch (const EmptyStack& e) {
		cout << "Stack is empty!" << endl;
	}
	return 0;
}