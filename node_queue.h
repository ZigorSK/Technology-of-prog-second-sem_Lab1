#pragma once
//keeper-> &base
#include"Base.h"
#include"Stack.h"
#include"list.h"
#include"deque.h"
#include"iostream"

using namespace std;

class node_queue
{
	Base *struct_of_data;
	node_queue *prev_ptr;

public:
	node_queue(char d = 's');
	~node_queue();

	void set_prev_ptr(node_queue *h) { prev_ptr = h; };
	node_queue *get_prev_ptr() { return prev_ptr; };

	void set_struct_of_data(Base *h) { struct_of_data = h; };
	Base *get_struct_of_data() { return struct_of_data; };

};

