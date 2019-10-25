#include "deque.h"
// left_p <->... prev_p(node)next_p...<-> right_p
deque::deque(const deque & obg)
{
	node_deque *ptr = obg.head;
	while (ptr != nullptr)
	{
		add(0, ptr->get_data());
		ptr->get_prev_ptr();
	}
}

deque::~deque()
{
	node_deque *ptr = head;

	while (ptr)
	{
		head = ptr->get_next_ptr();
		delete ptr;
		ptr = head;
	}
	head = nullptr;
}

void deque::add(int data, int flag )//if flag, then add elem of right, else add of left
{
	if (head == nullptr)// the first elem of deque
	{
		node_deque *ptr = nullptr;
		ptr = new node_deque;
		ptr->set_next_ptr(nullptr);
		ptr->set_prev_ptr(nullptr);
		ptr->set_data(data);
		head = ptr;
	}
	else
	{

		if (flag)//add an elem of right
		{
			node_deque *ptr = nullptr, *p = head;
			ptr = new node_deque;
			ptr->set_next_ptr(nullptr);

			while (p->get_next_ptr() != nullptr)
			{
				p = p->get_next_ptr();
			}
			p->set_next_ptr(ptr);
			ptr->set_prev_ptr(p);
			ptr->set_data(data);
		}
		else//add an elem of left
		{
			node_deque *ptr = nullptr;
			ptr = new node_deque;
			ptr->set_prev_ptr(nullptr);
			ptr->set_next_ptr(head);
			head->set_prev_ptr(ptr);
			ptr->set_data(data);
			head = ptr;
		}
	}
}

int deque::del(int flag)//flag = 1 - delete elem of right, flag = 0 - delete elem of left
{
	int d = 0;
	if ((head->get_next_ptr() == nullptr) && (head->get_prev_ptr() == nullptr))// the last elem of deque
	{
		 d = head->get_data();
		delete head;
		head = nullptr;
		cout << "Из дэка извлечён элемент" << d << endl;
		system("pause");
		return d;
	}

	//delete other elem
	if (flag)//del rigtht elem
	{
		// ptr1-> ptr2
		node_deque *ptr1 = head, *ptr2 = head;

		while (ptr2->get_next_ptr() != nullptr)
		{
			ptr2 = ptr2->get_next_ptr();
			ptr1 = ptr2->get_prev_ptr();
		}
		d = ptr2->get_data();
		delete ptr2;
		ptr1->set_next_ptr(nullptr);
		cout << "Из дэка извлечён элемент" << d << endl;
		system("pause");
		return d;
	}
	else//del left elem
	{
		node_deque *ptr = nullptr;
		ptr = head->get_next_ptr();
		d = head->get_data();
		delete head;
		head = ptr;
		cout << "Из дэка извлечён элемент" << d << endl;
		system("pause");
		return d;
	}
}

void deque::show()
{
	node_deque *ptr = head;

	cout << setw(20) << "Begin of deque:" << endl;
	while (ptr)
	{
		cout << setw(20) << ptr->get_data() << endl;
		ptr = ptr->get_next_ptr();
	}
	cout << setw(20) << "End of deque:" << endl;
}

void deque::menu()
{
	int choice = 0, dat = 0, flag = 0;
	system("cls");

	do
	{
		cout << "[1] Добавить элемент в дэк." << endl << "[2] Извлечение элемента из дэка." << endl << "[3] Вывод дэка на экран."
			<< endl << "[0] Выход из меню дэка." << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			cout << "[1] Добавление элемента справа." << endl << "[0] Добавление элемента слева." << endl;
			cin >> flag;

			cout << "Введить значение, добавляемое в дэк" << endl;
			cin >> dat;

			add(dat, flag);

			system("cls");
			break;

		case 2:

			system("cls");
			cout << "[1] Удаление элемента справа." << endl << "[0] Удаление элемента слева." << endl;
			cin >> flag;
			del(flag);
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

void deque::write_of_file(ofstream & fout)
{
	node_deque *ptr = head;

	try
	{
		if (ptr == nullptr)
			throw(ptr);
		while (1)
		{
			fout << ptr->get_data();
			ptr = ptr->get_next_ptr();
			if (ptr == nullptr)
				break;
			fout << "|";
		}
	}
	catch (node_deque *ptr)
	{
		cout << "Вызвано исключение. Дэк пуст. В файл он записан не будет. Выполнение программы продолжится." << endl;
		system("pause");
		system("cls");
	}

}
