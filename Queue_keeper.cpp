#include "Queue_keeper.h"

queue_keeper::queue_keeper(const queue_keeper & obg)
{
	node_queue *ptr = obg.end_ptr;

	while (ptr)
	{
		add(ptr->get_struct_of_data()->say_my_name());//создаёт пустые оъекты внутри новой очереди(Не копирует данные)
		ptr = ptr->get_prev_ptr();
	}
}

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
	else//Добавление первого элемента в очередь
	{
		end_ptr = new node_queue(c);
		end_ptr->set_prev_ptr(nullptr);
	}
}

void queue_keeper::del(void)
{
	//Если в узле prev_ptr = nullptr, то данный узел в очереди - элемент на выходе
	if (end_ptr != nullptr)//если в очереди есть элементы
	{
		node_queue *ptr = end_ptr, *next_ptr = end_ptr;


		while (ptr->get_prev_ptr())
		{
			next_ptr = ptr;
			ptr = ptr->get_prev_ptr();
		}

		if (ptr != end_ptr)//В очереди больше одного элемента
		{
			cout << "Из очереди изъят элемент -  ";
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
		else//В очереди остался 1 элемент
		{
			cout << "Из очереди изъят элемент -  ";
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
		cout << "В очереди нет ни одного элемента!!!" << endl;
	}
}

void queue_keeper::show()
{
	node_queue *ptr = end_ptr;

	cout << setw(15) << "Конец очереди";
	cout << setw(5) << "|" << endl;

	while (ptr)
	{
		ptr->get_struct_of_data()->show();
		ptr = ptr->get_prev_ptr();
		cout << endl << endl << endl;
	}
	cout << setw(15) << "Начало очереди";
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
		cout << "В очереди нет элемента с таким номером!!!" << endl;
		system("pause");
	}
}

void queue_keeper::read_from_file()
{
	int flag, dat = 0, arr[10000], count = 0;
	ifstream input;
	node_queue *ptr = end_ptr;
	char c, simv;

	cout << "Хотите ли очистить файл от считанных данных?" << endl << "[1] Да." << endl << "[0] Нет." << endl;
	cin >> flag;

	try
	{
		input.open("file_of_data.txt", std::ios::in);
		if (!input.is_open())
			throw(flag);



		do
		{
			input >> c;
			if (input.eof())
				break;
			do
			{
				input >> simv;
				if (simv == '>')
				{
					//input >> simv;//for endl
					break;
				}

				input >> dat;
				arr[count] = dat;
				count++;

			} while (1);

			//вносим данные в струтуру данных
			if (c == 's')//stack
			{
				add('s');
				ptr = end_ptr;

				for (int i = 0; i < count; i++)
				{
					ptr->get_struct_of_data()->add(arr[count - i-1], 0);
				}
			}
			else
			{
				if (c == 'd')//deque
				{
					add('d');
					ptr = end_ptr;


					for (int i = 0; i < count; i++)
					{
						ptr->get_struct_of_data()->add(arr[i], 1);
					}
				}
				else
				{
					if (c == 'l')
					{
						add('l');

						ptr = end_ptr;

						for (int i = 0; i < count; i++)
						{
							ptr->get_struct_of_data()->add(arr[i], i + 1);
						}
					}
					else
					{
						cout << "В файле неверно указан тип структуры данных!!!" << endl;
						system("pause");
						system("cls");
					}
				}
			}
			c == 'a';
			count = 0;
		} while (!input.eof());

		
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
		cout << "Вызвано исключение, не удалось открыть файл" << endl;
		system("pause");
		system("cls");
	}


}

queue_keeper & queue_keeper::operator--()
{
	del();
	return *this;
}

queue_keeper & queue_keeper::operator+(char c)
{
	add(c);
	return *this;
}

void queue_keeper::write_of_file()
{
	ofstream fout;
	int flag, count = 0;
	node_queue *ptr = end_ptr;
	//Хотите ли файл от предыдущих данных?
	cout << "Хотите ли очистить файл от предыдущих данных?" << endl << "[1] Да." << endl << "[0] Нет." << endl;
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
			count++;
			ptr = ptr->get_prev_ptr();
		}



		while (count)
		{
			ptr = end_ptr;
			for (int i = 0; i < count-1; i++)
			{
				ptr = ptr->get_prev_ptr();
			}
			fout << ptr->get_struct_of_data()->say_my_name();
			//запись всех данных структуры данных
			fout << "<";
		    ptr->get_struct_of_data()->write_of_file(fout);
			fout << ">";
			//
			fout << endl;
			count--;
		}
		fout.close();
	}
	catch (int flag)
	{
		cout << "Вызвано исключение, не удалось открыть файл" << endl;
		system("pause");
		system("cls");
	}
}

queue_keeper & operator+(char c, queue_keeper & obg)
{
	obg.add(c);
	return obg;
}
