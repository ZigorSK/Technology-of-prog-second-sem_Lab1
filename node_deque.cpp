#include "node_deque.h"

node_deque::node_deque(const node_deque & obg)
{
	next_ptr = nullptr;
	prev_ptr = nullptr;
	data = obg.data;
}

