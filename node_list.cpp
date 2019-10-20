#include "node_list.h"

node_list::node_list(const node_list & obg)
{
	data = obg.data;
	next_ptr = nullptr;
}

