#include "stack.h"

stack::stack(const stack & obg)
{
	hight_stack_ptr = nullptr;

	node_stack *ptr = obg.hight_stack_ptr;


	int count = 0;
	double *arr = nullptr;

	while (ptr)
	{
		count++;
		ptr = ptr->get_next_ptr();
	}
	arr = new double[count];
	ptr = obg.hight_stack_ptr;//���������� �������� ����� � ������ 1 �� -��� ��������� - ��������
	for (int i = 0; i < (count); i++)
	{
		*(arr + count - i - 1) = ptr->get_data();
		ptr = ptr->get_next_ptr();
	}

	for (int i = 0; i < count; i++)
	{
		add(*(arr + i) , 0);
	}

	delete arr;

	
}

stack::~stack()
{
	node_stack *ptr = hight_stack_ptr;

	while (ptr)
	{
		hight_stack_ptr = ptr->get_next_ptr();
		delete ptr;
		ptr = hight_stack_ptr;
	}
}

void stack::add(int d, int flag = 0)
{

	if (hight_stack_ptr != nullptr)//���� ����� ���� ��������� ��������
	{
		node_stack *ptr = nullptr;

		ptr = new node_stack;

		ptr->set_next_ptr(hight_stack_ptr);
		ptr->set_data(d);
		hight_stack_ptr = ptr;
	}
	else//���� ����������� ������� ������
	{
		hight_stack_ptr = new node_stack;
		hight_stack_ptr->set_next_ptr(nullptr);
		hight_stack_ptr->set_data(d);
	}
}

int stack::del(int m = 0)
{
	try
	{
		if (hight_stack_ptr != nullptr)//���� �������� ��� ����
			throw(hight_stack_ptr);

		int d = 0;

		
			d = hight_stack_ptr->get_data();
			cout << "������� " << d << "�������� �� �����" << endl;
			node_stack *ptr = hight_stack_ptr->get_next_ptr();

			delete hight_stack_ptr;
			hight_stack_ptr = ptr;
		
		return d;
	}
	catch (node_stack hight_stack_ptr)
	{
		cout << "� ����� ������ ��� ���������!!!" << endl;	
	}
}


void stack::show()//����� ����� �� �����
{
	node_stack *ptr = hight_stack_ptr;

	cout << setw(20) << "Top of stack:" << endl;
	while (ptr)
	{
		cout << setw(20) << ptr->get_data() << endl;
		ptr = ptr->get_next_ptr();
	}
	cout << setw(20) << "Bottom of stack:" << endl;

}

void stack::menu()
{
	int choice = 0, dat = 0;
	system("cls");

	do
	{
		cout << "[1] �������� ������� � ����." << endl << "[2] ���������� �������� �� �����." << endl << "[3] ����� ����� �� �����."
	         << endl << "[0] ����� �� ���� �����." << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			cout << "������� ��������, ����������� � ����" << endl;
			cin >> dat;

			add(dat);

			system("cls");
			break;

		case 2:

			system("cls");
			del();
			system("pause");
			break;

		case 3:
			system("cls");
			show();
			system("pause");
			break;
	
		case 0:
			break;
		default: cout << "������� ������������ �������!!!!" << endl;
			system("pause");
			break;

		}

	} while (choice);
}

void stack::write_of_file(ofstream &fout)
{
	node_stack *ptr = hight_stack_ptr;

	while (ptr)
	{
		fout << ptr->get_data();
		fout << " ";
		ptr = ptr->get_next_ptr();
	}

}
