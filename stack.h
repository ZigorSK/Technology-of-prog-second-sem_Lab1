#pragma once
//����
#include"Base.h"
#include"node_stack.h"
#include"iostream"
#include"iomanip"


using namespace std;

class stack :public Base
{
	node_stack *hight_stack_ptr;// �������� �����

public:
	stack() : hight_stack_ptr(nullptr) {};
	stack(const stack &obg);
	~stack();

	void set_hight_stack_ptr(node_stack *h) { hight_stack_ptr = h; };
	node_stack *get_hight_stack_ptr() { return hight_stack_ptr; };

	void add(int d , int flag) override;// ����� ���������� �������� � ����
	int del(int ) override;//���������� �������� �� �����
	void show() override;//
	void menu() override;
	void write_of_file(ofstream &fout);

};