#include "list.h"

list::list(const list & A)
{
	head = nullptr;
	size = 0;
	node_list *ptr = A.head;
	for (int i = 1; ptr != nullptr; i++, ptr = ptr->get_next_ptr())
	{
		add(ptr->get_data(), i);
	}

}

list::~list()
{
	node_list *ptr = head;

	while (head != nullptr)
	{		ptr = head;		head = head->get_next_ptr();
		size--;
		delete ptr;
	}
}

void list::add(int d, int pos)
{
	try
	{
		if ((pos > size + 1) || (pos < 1))
			throw(pos);

		node_list *prev_node = head, *next_node = head;

		if (head != nullptr)
		{
			if (pos == 1)
			{
				node_list *ptr;
				ptr = new node_list;
				ptr->set_data(d);
				ptr->set_next_ptr(head);
				head = ptr;
				size++;

			}
			else
			{
				if (pos == (size + 1))//если добавляемый узел в конце списка
				{
					while (prev_node->get_next_ptr() != nullptr)//Ищем узел перед добавляемым
						prev_node = prev_node->get_next_ptr();

					next_node = new node_list;//выделяем память под новый узел
					prev_node->set_next_ptr(next_node);//связываем предыдущий и новый узел
					next_node->set_next_ptr(nullptr);//т.к. узел теперь последний указатель на следующий null
					next_node->set_data(d);
					size++;
				}
				else//добаляемый узел в середине списка
				{

					for (int i = 1; i < pos; i++)//ищем предыдущий и следующий узел для добавляемого
					{
						prev_node = next_node;
						next_node = next_node->get_next_ptr();
					}
					node_list *new_node;
					new_node = new node_list;
					prev_node->set_next_ptr(new_node);//следующий указатель предыдущего узла равен новому
					new_node->set_next_ptr(next_node);//следующий указатель нового равен следующему
					size++;
					new_node->set_data(d);
				}
			}
		}
		else//добаляемый узел в начале списка и в списке больше нет элементов
		{
			head = new node_list;
			head->set_data(d);
			head->set_next_ptr(nullptr);
			size++;
		}
	}
	catch (int pos)
	{
		cout << "Переданый размер больше, чем size+1 и меньше 1!!! Ничего не будет выполнено!!! Выполнени программы продолжается!" << endl;
		system("pause");
	}
}

int list::del(int pos)
{
	try
	{
		if ((size < pos) || (size < 1))
			throw pos;
		int ret;
		if (head->get_next_ptr() != nullptr)
		{
			node_list *del_node = nullptr, *prev_node = nullptr, *next_node = nullptr;
			if (pos != 1)
			{
				if (pos == size)//если удаляется последний элемент в списке
				{
					del_node = head;
					for (int i = 1; i < pos; i++)//ищем предыдущий и последний узел 
					{
						prev_node = del_node;
						del_node = del_node->get_next_ptr();
					}
					ret = del_node->get_data();
					delete del_node;
					prev_node->set_next_ptr(nullptr);
					size--;

				}
				else//удаляется элемент в середине списка
				{
					for (int i = 1; i < pos; i++)//ищем предыдущий и последний узел 
					{
						prev_node = del_node;
						del_node = del_node->get_next_ptr();
					}
					next_node = del_node->get_next_ptr();
					ret = del_node->get_data();
					delete del_node;
					prev_node->set_next_ptr(next_node);
					size--;
				}
			}
			else//удаление первого элемента в списке
			{
				del_node = head;
				head = head->get_next_ptr();
				ret = del_node->get_data();
				delete del_node;
				size--;
			}
			return ret;
		}
		else
		{
			ret = head->get_data();
			delete head;
			head = nullptr;
			size--;
		}
	}
	catch (int pos)
	{
		cout << "Переданый размер больше, чем size и меньше 1!!! Ничего не будет выполнено!!! Выполнени программы продолжается!" << endl;
		system("pause");
	}

}

void list::show()
{
	node_list *ptr = head;

	cout << setw(20) << "Begin of list:" << endl;
	while (ptr)
	{
		cout << setw(20) << ptr->get_data() << endl;
		ptr = ptr->get_next_ptr();
	}
	cout << setw(20) << "End of list:" << endl;
}

void list::menu()
{
	int choice = 0, dat = 0, pos = 0;
	system("cls");

	do
	{
		cout << "[1] Добавить элемент в список." << endl << "[2] Извлечение элемента из списка." << endl << "[3] Вывод списка на экран."
			<< endl << "[0] Выход из меню списка." << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Введить позицию в списке, для добавления в него" << endl;
			cin >> pos;

			cout << "Введить значение, добавляемое в список" << endl;
			cin >> dat;

			add(dat, pos);

			system("cls");
			break;

		case 2:

			system("cls");
			cout << "Введить позицию в списке, для удаления из него данного элемента" << endl;
			cin >> pos;
			del(pos);
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

void list::write_of_file(ofstream & fout)
{
	node_list *ptr = head;

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
			fout << " ";
		}
	}
	catch (node_list *ptr)
	{
		cout << "Вызвано исключение. Список пуст. В файл он записан не будет. Выполнение программы продолжится." << endl;
		system("pause");
		system("cls");
	}

}
