/*
Разработать класс Keeper, который реализует контейнер для хранения и обработки объектов. 
Класс Keeper должен обеспечивать следующие функции: 
? добавление и удаление производных
объектов абстрактного класса Base (базовый класс определяется согласно варианту задания); 
? полное сохранение себя в файле;
? полное восстановление себя из файла;

Класс Очередь содержит данные о списке, деке и стеке. В каждом хранятся числа. 
Необходимо реализовать функционал каждого контейнера на основе очереди.
*/

#include"Header.h"
#include<iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	queue_keeper obg;
	int choice = 0, type_struct = 0, num = 0;

	system("cls");

	do
	{
		cout << "[1] Добавление элемента очереди." << endl << "[2] Извлечение элемента очереди." << endl << "[3] Вывод очереди на экран."
			<< endl <<"[4] Меню элемента очереди."<< endl <<"[5] Запись всех элементов очереди в файл" << endl << "[6] Получить из файла элементы и запистаь в очередь" << endl <<"[0] Завершить работу." << endl;
		cin >> choice;
		
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "[1] ADD Stack." << endl << "[2] ADD Deque" << endl << "[3] ADD List" << endl;
			cin >> type_struct;

			try
			{
				if (type_struct == 1)
				{
					obg.add('s');
				}
				else
				{
					if (type_struct == 2)
					{
						obg.add('d');
					}
					else
					{
						if (type_struct == 3)
						{
							obg.add('l');
						}
						else
						{
							throw(type_struct);
						}
					}
				}
			}
			catch (int type_struct)
			{
				cout << "Вызвано исключение! Неверно введён номер типа добавляемой структуры данных в очередь. " << endl << "Выполнение программы продожится без добавления элемента." << endl;
				system("pause");
			}

			system("cls");
			break;

		case 2:

			system("cls");
			obg.del();
			system("pause");
			system("cls");
			break;

		case 3:
			system("cls");
			obg.show();
			system("pause");
			cout << endl << endl;
			break;
		case 4:
			system("cls");
			cout << " Введите номер элемента в очереди!" << endl;
			cin >> num;
			obg.menu(num);
			system("cls");
			break;
		case 5:
			system("cls");
			obg.write_of_file();
			system("cls");
			break;
		case 6:
			system("cls");
			obg.read_from_file();
			system("cls");
			break;
		case 0:
			break;
		default: cout << "Введена неправильная команда!!!!" << endl;
			system("pause");
			system("cls");
			break;

		}
	} while (choice);

	return 0;
}
