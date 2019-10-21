#include "node_queue.h"

node_queue::node_queue(char d)
{
	try
	{
		if (d == 's')//stack
		{
			struct_of_data = new stack;
			struct_of_data->set_my_name(d);
		}
		else
		{
			if (d == 'd')//deque
			{
				struct_of_data = new deque;
				struct_of_data->set_my_name(d);
			}
			else
			{
				if (d == 'l')//list
				{
					struct_of_data = new list;
					struct_of_data->set_my_name(d);
				}
				else
				{
					throw (d);
				}
			}
		}
	}
	catch(char d)
	{
		cout << " Неверно передан параметр имени структуры данных:" << d << endl;
		struct_of_data = nullptr;
	}
}

node_queue::~node_queue()
{
	delete struct_of_data;
}
