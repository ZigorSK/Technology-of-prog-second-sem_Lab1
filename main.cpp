/*
����������� ����� Keeper, ������� ��������� ��������� ��� �������� � ��������� ��������. 
����� Keeper ������ ������������ ��������� �������: 
? ���������� � �������� �����������
�������� ������������ ������ Base (������� ����� ������������ �������� �������� �������); 
? ������ ���������� ���� � �����;
? ������ �������������� ���� �� �����;

����� ������� �������� ������ � ������, ���� � �����. � ������ �������� �����. 
���������� ����������� ���������� ������� ���������� �� ������ �������.
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
		cout << "[1] ���������� �������� �������." << endl << "[2] ���������� �������� �������." << endl << "[3] ����� ������� �� �����."
			<< endl <<"[4] ���� �������� �������."<< endl <<"[5] ������ ���� ��������� ������� � ����" << endl << "[6] �������� �� ����� �������� � �������� � �������" << endl <<"[0] ��������� ������." << endl;
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
					obg + 's';
				}
				else
				{
					if (type_struct == 2)
					{
						obg + 'd';
					}
					else
					{
						if (type_struct == 3)
						{
							obg + 'l';
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
				cout << "������� ����������! ������� ����� ����� ���� ����������� ��������� ������ � �������. " << endl << "���������� ��������� ���������� ��� ���������� ��������." << endl;
				system("pause");
			}

			system("cls");
			break;

		case 2:

			system("cls");
			--obg;
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
			cout << " ������� ����� �������� � �������!" << endl;
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
		default: cout << "������� ������������ �������!!!!" << endl;
			system("pause");
			system("cls");
			break;

		}
	} while (choice);

	return 0;
}