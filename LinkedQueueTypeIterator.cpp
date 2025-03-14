
///////////////////////////////////////////////////////////////////////////////
//
// IMPLEMENTATION
//
///////////////////////////////////////////////////////////////////////////////
#include "LinkedQueueTypeIterator.h"
#include <iostream>
LinkedQueueTypeIterator::LinkedQueueTypeIterator(NodeType* startnode, int loc)
{
	item = startnode;
	start = startnode;
	location = loc;
	
	//Complete this.
}

ItemType& LinkedQueueTypeIterator::operator*()
{
	
	return item->info;
	//Complete this.
}

LinkedQueueTypeIterator& LinkedQueueTypeIterator::operator++()
{
	if (item != nullptr) {
		item = item->next; // move to next node
		location++;
		if (item == start) //check if we at the begining
			item = nullptr;
	}
	return *this;
}

bool LinkedQueueTypeIterator::operator!=(const LinkedQueueTypeIterator &it) const
{
	return item != it.item;
	//Complete this.
}



