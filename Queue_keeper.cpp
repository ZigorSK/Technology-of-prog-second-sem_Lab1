#include "Queue_keeper.h"

queue_keeper::~queue_keeper()
{
	node_queue *ptr = end_ptr;

	while ((ptr = end_ptr) != nullptr)
	{
		end_ptr = end_ptr->get_prev_ptr();
		delete ptr;
	}
	end_ptr = nullptr;
}

void queue_keeper::add(char c)
{
	node_queue *ptr = nullptr;

	if (end_ptr)
	{
		ptr = new node_queue(c);
		ptr->set_prev_ptr( end_ptr );
		end_ptr = ptr;
	}
	else//���������� ������� �������� � �������
	{
		end_ptr = new node_queue(c);
		end_ptr->set_prev_ptr(nullptr);
	}
}

void queue_keeper::del(void)
{
	//���� � ���� prev_ptr = nullptr, �� ������ ���� � ������� - ������� �� ������
	if (end_ptr != nullptr)//���� � ������� ���� ��������
	{
		node_queue *ptr = end_ptr, *next_ptr = end_ptr;


		while (ptr->get_prev_ptr())
		{
			next_ptr = ptr;
			ptr = ptr->get_prev_ptr();
		}

		if (ptr != end_ptr)//� ������� ������ ������ ��������
		{
			cout << "�� ������� ����� ������� -  ";
			char c = ptr->get_struct_of_data()->say_my_name();
			if (c == 's')
			{
				cout << "Stack:" << endl;
			}
			else
			{
				if (c == 'd')
				{
					cout << "Deque:" << endl;
				}
				else
				{
					cout << "List:" << endl;
				}
			}
			ptr->get_struct_of_data()->show();

			delete ptr;
			next_ptr->set_prev_ptr( nullptr);
		}
		else//� ������� ������� 1 �������
		{
			cout << "�� ������� ����� ������� -  ";
			char c = ptr->get_struct_of_data()->say_my_name();
			if (c == 's')
			{
				cout << "Stack:" << endl;
			}
			else
			{
				if (c == 'd')
				{
					cout << "Deque:" << endl;
				}
				else
				{
					cout << "List:" << endl;
				}
			}
			ptr->get_struct_of_data()->show();

			delete ptr;
			end_ptr = nullptr;
		}

	}
	else
	{
		cout << "� ������� ��� �� ������ ��������!!!" << endl;
	}
}

void queue_keeper::show()
{
	node_queue *ptr = end_ptr;

	cout << setw(15) << "����� �������";
	cout << setw(5) << "|" << endl;

	while (ptr)
	{
		ptr->get_struct_of_data()->show();
		ptr = ptr->get_prev_ptr();
		cout << endl << endl << endl;
	}
	cout << setw(15) << "������ �������";
	cout << setw(5) << "V" << endl;
}

void queue_keeper::menu(int num)
{
	node_queue *ptr = end_ptr;
	int count = 0;

	while (ptr)
	{
		count++;
		ptr = ptr->get_prev_ptr();
	}
	try
	{
		if (num > count)
			throw(num);

		ptr = end_ptr;
		while (num != count)
		{
			ptr = ptr->get_prev_ptr();
			count--;
		}
		ptr->get_struct_of_data()->menu();

	}
	catch (int num)
	{
		cout << "� ������� ��� �������� � ����� �������!!!" << endl;
		system("pause");
	}
}

void queue_keeper::read_from_file()
{
	int flag;
	ifstream input("file_of_data.txt");
	node_queue *ptr = end_ptr;
	char c;

	cout << "������ �� ���� �� ��������� ������?" << endl << "[1] ��." << endl << "[0] ���." << endl;
	cin >> flag;

	try
	{
		input.open("file_of_data.txt");
		if (!input.is_open())
			throw(flag);

		while (ptr)
		{
			ptr = ptr->get_prev_ptr();
		}

		input >> c;


		input.close();
		//clear of file
		if (flag == 1)
		{
			ofstream o;
			o.open("file_of_data.txt");
			o.close();
		}
		//
			
	}
	catch (int flag)
	{
		cout << "������� ����������, �� ������� ������� ����" << endl;
		system("pause");
		system("cls");
	}


}

void queue_keeper::write_of_file()
{
	ofstream fout;
	int flag;
	node_queue *ptr = end_ptr;
	//������ �� ���� �� ���������� ������?
	cout << "������ �� ���� �� ���������� ������?" << endl << "[1] ��." << endl << "[0] ���." << endl;
	cin >> flag;
	try
	{
		if (flag)
		{
			fout.open("file_of_data.txt");
			if (!fout.is_open())
				throw(flag);
		}
		else
		{
			fout.open("file_of_data.txt", ios_base::app);
			if (!fout.is_open())
				throw(flag);
		}

		while (ptr)
		{
			fout << ptr->get_struct_of_data()->say_my_name() << " ";
			//������ ���� ������ ��������� ������
		    ptr->get_struct_of_data()->write_of_file(fout);
			//
			fout << endl;
			ptr = ptr->get_prev_ptr();
			
		}
		fout.close();
	}
	catch (int flag)
	{
		cout << "������� ����������, �� ������� ������� ����" << endl;
		system("pause");
		system("cls");
	}
}


