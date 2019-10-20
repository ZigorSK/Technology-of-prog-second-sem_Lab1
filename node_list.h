#pragma once

class node_list
{
	int data;
	node_list *next_ptr;
public:
	node_list() : data(0),  next_ptr(nullptr) {};
	node_list(const node_list &obg);


	int get_data() { return data; }
	void set_data(int d) { data = d; }

	node_list *get_next_ptr() { return next_ptr; }
	void set_next_ptr(node_list *d) { next_ptr = d; }
};