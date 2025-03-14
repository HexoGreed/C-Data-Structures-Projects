#ifndef STACKTYPEITERATOR_H
#define STACKTYPEITERATOR_H

#include <stddef.h>

//class FullStack {};
// Exception class thrown by Push when stack is full.

//class EmptyStack {};
// Exception class thrown by Pop and Top when stack is empty.

class OutOfBounds {};
// Exception class thrown by operator[] when a bad index is attempted.

// A template for an iterator that implements the contract required by the
// range-based for-loop. The name of the Iterator class would be customized
// to be XIterator where X is the name of the ADT that the iterator iterates
// over.
template <class ItemType>
class StackTypeArrIterator
{
public:
  // Customize the constructor to work with the ADT.
  StackTypeArrIterator(int location);

  //Dereference operator for the iterator.
  ItemType operator*();

  // Customize to return the proper iterator class.
  StackTypeArrIterator& operator++();

  // Customize to receive the correct Iterator class.
  bool operator!=(const StackTypeArrIterator& it) const;

private:
  // The start of the linked list.
  int index;
};

template <class ItemType>
StackTypeArrIterator<ItemType>::StackTypeArrIterator(int location)
{
  this->index = location;
}

template <class ItemType>
ItemType StackTypeArrIterator<ItemType>::operator*()
{
  return index;
}

template <class ItemType>
StackTypeArrIterator<ItemType>& StackTypeArrIterator<ItemType>::operator++()
{
	index++;
	return *this;
}

template <class ItemType>
bool StackTypeArrIterator<ItemType>::operator!=(const StackTypeArrIterator<ItemType>& it) const
{
  return index != it.index;
}


#endif
