#pragma once
#include<fstream>
//********   --> stack
//         /
//***Base *---> list                
//         \
//********   -- > deque

class Base
{
	char name;// s -stack; d -deque; l -list
public:
	Base(char d = 's') : name(d) {};
	virtual ~Base() {};	

	virtual void add(int, int ) = 0;
	virtual int del(int) = 0;
	virtual void show() = 0;
	virtual void menu() = 0;
	virtual void write_of_file(std::ofstream & stream) = 0;

	char say_my_name() { return name; };
	void set_my_name(char d) { name = d; };
	
};
