#pragma once
#include "node_queue.h"
#include <iostream>
#include<iomanip>
#include<fstream>

using namespace std;

class queue_keeper
{
	node_queue *end_ptr;

public:
	queue_keeper() : end_ptr(nullptr) {};
	~queue_keeper();

	void set_end_ptr(node_queue *d)  { end_ptr = d; };
	node_queue *get_end_ptr(void) { return end_ptr; };

	void add(char c);
	void del(void);
	void show();
	void menu(int num);
	void write_of_file();
	void read_from_file();
	
};

