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
	ptr = obg.hight_stack_ptr;//записываем значения стэка в массив 1 эл -дно последний - верхушка
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

	if (hight_stack_ptr != nullptr)//Если ранее были добавлены элементы
	{
		node_stack *ptr = nullptr;

		ptr = new node_stack;

		ptr->set_next_ptr(hight_stack_ptr);
		ptr->set_data(d);
		hight_stack_ptr = ptr;
	}
	else//Если добавляемый элемент первый
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
		if (hight_stack_ptr != nullptr)//Если элементы ещё есть
			throw(hight_stack_ptr);

		int d = 0;

		
			d = hight_stack_ptr->get_data();
			cout << "Элемент " << d << "Извлечён из стэка" << endl;
			node_stack *ptr = hight_stack_ptr->get_next_ptr();

			delete hight_stack_ptr;
			hight_stack_ptr = ptr;
		
		return d;
	}
	catch (node_stack hight_stack_ptr)
	{
		cout << "В стэке больше нет элементов!!!" << endl;	
	}
}


void stack::show()//Вывод стэка на экран
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
		cout << "[1] Добавить элемент в стэк." << endl << "[2] Извлечение элемента из стэка." << endl << "[3] Вывод стэка на экран."
	         << endl << "[0] Выход из меню стэка." << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Введить значение, добавляемое в стэк" << endl;
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
		default: cout << "Введена неправильная команда!!!!" << endl;
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
