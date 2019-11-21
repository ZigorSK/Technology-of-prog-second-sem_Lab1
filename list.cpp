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
				if (pos == (size + 1))//���� ����������� ���� � ����� ������
				{
					while (prev_node->get_next_ptr() != nullptr)//���� ���� ����� �����������
						prev_node = prev_node->get_next_ptr();

					next_node = new node_list;//�������� ������ ��� ����� ����
					prev_node->set_next_ptr(next_node);//��������� ���������� � ����� ����
					next_node->set_next_ptr(nullptr);//�.�. ���� ������ ��������� ��������� �� ��������� null
					next_node->set_data(d);
					size++;
				}
				else//���������� ���� � �������� ������
				{

					for (int i = 1; i < pos; i++)//���� ���������� � ��������� ���� ��� ������������
					{
						prev_node = next_node;
						next_node = next_node->get_next_ptr();
					}
					node_list *new_node;
					new_node = new node_list;
					prev_node->set_next_ptr(new_node);//��������� ��������� ����������� ���� ����� ������
					new_node->set_next_ptr(next_node);//��������� ��������� ������ ����� ����������
					size++;
					new_node->set_data(d);
				}
			}
		}
		else//���������� ���� � ������ ������ � � ������ ������ ��� ���������
		{ 
			head = new node_list;
			head->set_data(d);
			head->set_next_ptr(nullptr);
			size++;
		}
	}
	catch (int pos)
	{
		cout << "��������� ������ ������, ��� size+1 � ������ 1!!! ������ �� ����� ���������!!! ��������� ��������� ������������!" << endl;
		system("pause");
	}
}

int list::del(int pos)
{
	try
	{
		if ((pos > size) || (pos < 1))
			throw pos;

		int ret;
		
		if (head->get_next_ptr() != nullptr)
		{
			node_list *del_node = nullptr, *prev_node = nullptr, *next_node = nullptr;
			if (pos != 1)
			{
				if (pos == size)//���� ��������� ��������� ������� � ������
				{
					del_node = head;
					for (int i = 1; i < pos; i++)//���� ���������� � ��������� ���� 
					{
						prev_node = del_node;
						del_node = del_node->get_next_ptr();
					}
					ret = del_node->get_data();
					delete del_node;
					prev_node->set_next_ptr(nullptr);
					size--;

				}
				else//��������� ������� � �������� ������
				{
					for (int i = 1; i < pos; i++)//���� ���������� � ��������� ���� 
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
			else//�������� ������� �������� � ������
			{
				del_node = head;
				head = head->get_next_ptr();
				ret = del_node->get_data();
				delete del_node;
				size--;
			}

		}
		else
		{
			ret = head->get_data();
			delete head;
			head = nullptr;
			size--;
		}
		cout << "�� ������ ��������� ����� " << ret << ", �������" << pos<<endl;
		system("pause");
		system("cls");
		return ret;
	}
	catch (int pos)
	{
		cout << "��������� ������ ������, ��� size � ������ 1!!! ������ �� ����� ���������!!! ��������� ��������� ������������!" << endl;
		system("pause");
		return 0;
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
		cout << "[1] �������� ������� � ������." << endl << "[2] ���������� �������� �� ������." << endl << "[3] ����� ������ �� �����."
			<< endl << "[0] ����� �� ���� ������." << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			cout << "������� ������� � ������, ��� ���������� � ����" << endl;
			cin >> pos;

			cout << "������� ��������, ����������� � ������" << endl;
			cin >> dat;

			add(dat, pos);

			system("cls");
			break;

		case 2:

			system("cls");
			cout << "������� ������� � ������, ��� �������� �� ���� ������� ��������" << endl;
			cin >> pos;
			del(pos);
			system("cls");
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

void list::write_of_file(ofstream & fout)
{
	node_list *ptr = head;

	try
	{
		if (ptr == nullptr)
			throw(ptr);
		fout << "<";
		while (1)
		{
			fout << ptr->get_data();
			ptr = ptr->get_next_ptr();
			if (ptr == nullptr)
				break;
			fout << "|";
		}
		fout << ">";
	}
	catch (node_list *ptr)
	{
		fout << "_";
	}

}
