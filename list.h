#pragma once
//Список
#include"Base.h"
#include"node_list.h"
#include"iostream"
#include"iomanip"

using namespace std;

class list :public Base
{
	node_list *head;
	int size;
public:
	list() :head(nullptr), size(0) {};
	list(int d) :head(nullptr)//парамет конструктора единственный новый элемент списка
	{
		
		size = 0;
		if (head == nullptr)
		{
			node_list *new_node;
			new_node = new node_list;
			new_node->set_data(d);
			new_node->set_next_ptr(nullptr);
			size++;
		}

	};

	list(const list &A);//НАписать
	~list();

	void set_head(node_list *h) { head = h; };
	node_list *get_head() { return head; };

	void set_size(int s) {size = s;};
	int get_size() { return size; };

	void add(int data, int pos) ;
	int del(int pos) ;
	void show() override;
	void menu() override;
	void write_of_file(ofstream &fout);

};

