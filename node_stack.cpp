#include "node_stack.h"

node_stack::node_stack(const node_stack & obg)
{
	data = obg.data;
	next_ptr = nullptr;
}


