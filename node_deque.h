#pragma once
// left_p <->... prev_p(node)next_p...<-> right_p
class node_deque
{
	int data;
	node_deque *next_ptr;
	node_deque *prev_ptr;
public:
	node_deque() : data(0), next_ptr(nullptr) {};//Конструктор по умолчанию
	node_deque(const node_deque &obg);

	//getters
	int get_data() { return data; };
	node_deque *get_next_ptr() { return next_ptr; }
	node_deque *get_prev_ptr() { return prev_ptr; }

	//setters
	void set_data(int d) { data = d; };
	void set_next_ptr(node_deque *d) { next_ptr = d; };
	void set_prev_ptr(node_deque *d) { prev_ptr = d; };
};