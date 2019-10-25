#pragma once
#include"Base.h"
#include"node_deque.h"
#include<iostream>
#include<iomanip>
//δύκ
// left_p <->... prev_p(node)next_p...<-> right_p
using namespace std;
class deque :public Base
{
	node_deque *head;
public:
	deque() : head(nullptr) {};
	deque(const deque &obg);
	~deque();

	void set_head(node_deque *h) { head = h; };
	node_deque *get_head() { return head; };

	void add(int flag, int data) override;// flag - 0 add_left, flag !=0 -add_right
	int del(int flag) override;// flag - 0 del_left, flag !=0 -del_right
	void show() override;
	void menu() override;
	void write_of_file(ofstream &fout);

};