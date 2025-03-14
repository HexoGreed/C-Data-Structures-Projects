#ifndef STACK_TYPE_H
#define STACK_TYPE_H
#include "StackTypeArrIterator.h"
#include <iostream>
using namespace std;
class FullStack{};
class EmptyStack{};

//   
//   Class specification for Stack ADT in file Stack1.h
//Edit: Ivan Temesvari 2/11/201

template <class ItemType>
class StackTypeArr {
	public:

		StackTypeArr(int max); // max is stack size
		StackTypeArr();  // Default size is 500



		// Rest of the prototypes go here.
		bool IsFull() const;
		// Function: Determines whether the stack is full.
		// Pre:  Stack has been initialized.
		// Post: Function value = (stack is full)
		bool IsEmpty() const;
		// Function: Determines whether the stack is empty.
		// Pre:  Stack has been initialized.
		// Post: Function value = (stack is empty)
		void Push(ItemType item);
		// Function: Adds newItem to the top of the stack.
		// Pre:  Stack has been initialized.
		// Post: If (stack is full), FullStack exception is thrown;
		//     otherwise, newItem is at the top of the stack.
		void Pop();
		// Function: Removes top item from the stack.
		// Pre:  Stack has been initialized.
		// Post: If (stack is empty), EmptyStack exception is thrown;
		//     otherwise, top element has been removed from stack.
		ItemType Top();
		// Function: Returns a copy of top item on the stack.
		// Pre:  Stack has been initialized.
		// Post: If (stack is empty), EmptyStack exception is thrown;
		//     otherwise, top element has been removed from stack.
		~StackTypeArr();
		//Destructor. Reallocate the memory reserved for ItemType* items.
		void Print();
		//Print the stack

		int GetMaxStack();
		//gets he max stack size;

		ItemType& operator[](int);



		StackTypeArrIterator<ItemType> begin();
		StackTypeArrIterator<ItemType> end();


		//Friend functions
		template <class IT>
		friend bool Identical(const StackTypeArr<IT>& stack1, const StackTypeArr<IT>& stack2);
	

		private:
		int top;
		int	maxStack; // Maximum number of stack items.
		ItemType* items; //ptr for dynamic mem alloc
};

//Overload the operator[]
template <class ItemType>
ItemType& StackTypeArr<ItemType>::operator[](int index){
	if(index < 0 or index > top){
		throw OutOfBounds();
	}
	else{
		return items[index];
	}
}

template <class ItemType>
StackTypeArr<ItemType>::StackTypeArr(int max)
{
  maxStack = max;
  top = -1;
  items = new ItemType[maxStack];
}

template <class ItemType>
StackTypeArr<ItemType>::StackTypeArr()
{
  maxStack = 500;
  top = -1;
  items = new ItemType[maxStack];
}

template <class ItemType>
bool StackTypeArr<ItemType>::IsEmpty() const
{
  return (top == -1);
}

template <class ItemType>
bool StackTypeArr<ItemType>::IsFull() const
{
  return (top == maxStack-1);
}

template <class ItemType>
void StackTypeArr<ItemType>::Push(ItemType newItem)
{
  if (IsFull())
    throw FullStack();
  top++;
  items[top] = newItem;
}

template <class ItemType>
void StackTypeArr<ItemType>::Pop()
{
  if( IsEmpty() )
    throw EmptyStack();
  top--;
}



template <class ItemType>
int StackTypeArr<ItemType>::GetMaxStack() {
	return maxStack;
}



template <class ItemType>
ItemType StackTypeArr<ItemType>::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}

template <class ItemType>
StackTypeArr<ItemType>::~StackTypeArr()
{
  delete [] items;
}

template <class ItemType>
StackTypeArrIterator<ItemType> StackTypeArr<ItemType>::begin(){
	StackTypeArrIterator<ItemType> it(0);
	 return it;
}

template <class ItemType>
StackTypeArrIterator<ItemType> StackTypeArr<ItemType>::end(){
	StackTypeArrIterator<ItemType> it(top+1);
	 return it;
}

template <class ItemType>
void StackTypeArr<ItemType>::Print(){
	cout << "Top:" << endl;
	if(!IsEmpty()){
		for(StackTypeArrIterator<ItemType> it = begin(); it != end(); ++it){
			cout << items[*it] << endl;
		}
	}
	cout << ":Bottom" << endl;
}










#endif
