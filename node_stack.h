#pragma once


class node_stack
{
	int data;
	node_stack *next_ptr;
public:
	node_stack() : data(0), next_ptr(nullptr) {};//Конструктор по умолчанию
	node_stack(const node_stack &obg);

	//getters
	int get_data() { return data; };
	node_stack *get_next_ptr() { return next_ptr;}	
	
	//setters
	void set_data(int d) { data = d; };
	void set_next_ptr(node_stack *d) { next_ptr = d; };
};