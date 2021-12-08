#include <iostream>
#include<string>
#include <cstdlib>
#include <ctime> 
#include<windows.h>
using namespace std;

int main()
{
	//������� ����
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//������������ ������������
	cout << "����� ���������� � ���� ***����������***!\n\n���������� ������� ����� �� ������������ ������\n���� ������ �����, �� �������� '�����'";
	cout << "\n���� ������ ���������, �������� '���������'\n\n";

	//�������� ����� ���������
	string words[] = { "�����������", "�����", "������", "������", "����" };
	string hints[] = { "��������� ���� ��������� - ...", "������ �� ������� ��", "���� �������, � ���� ...", "������������ ��������� ������������ � ����", "�� ����� �� ����� ��" };

	bool play = true;
	string again;
	int points = 0;
	while (play)
	{
		//�������� �����
		srand(static_cast<unsigned int>(time(0)));
		int wordN = rand() % 5;
		string word = words[wordN];
		int lettersN = word.size();
		//������������ �����
		for (; word.empty() == false;)
		{
			int lettersN = word.size();
			int randP = rand() % lettersN;
			char randL = word[randP];
			cout << randL;
			word.erase(randP, 1);
		}

		//���������� ������������
		string userWord;
		while (play)
		{
			cout << "\n\n������� ��� �������: ";
			cin >> userWord;

			//���������
			if (userWord == "���������")
			{
				cout << hints[wordN];
				points -= 2;
				continue;
			}
			//�����
			if (userWord == "�����")
			{
				play = false;
			}
			//������
			else if (userWord == words[wordN])
			{
				cout << "�� ��������!";
				points += lettersN;
				break;
			}

			//�� ������
			else
			{
				cout << "�������";
				--points;
			}
		}
		//������?
		while (play)
		{
			cout << "\n\n������?(��/���): ";
			cin >> again;
			if (again == "��")
			{
				break;
			}
			if (again == "���")
			{
				play = false;
			}
		}
	}
	cout << "\n������� �� ����!" << endl;
	cout << "�� ������� " << points << " �����";
	return 0;
}