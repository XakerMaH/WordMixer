#include <iostream>
#include<string>
#include <cstdlib>
#include <ctime> 
#include<windows.h>
using namespace std;

int main()
{
	//русский язык
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//приветствуем пользователя
	cout << ""Добро пожаловать в игру ***Словомеска***!\n\nПопробуйте угадать слово по перемешанным буквам\nЕсли хотите выйти, то напишите 'выход'";
	cout << "\nЕсли хотите подсказку, напишите 'подсказка'\n\n;

	//варианты слов и подсказки
	string words[] = { "программист", "книга", "строка", "ошибка", "файл" };
	string hints[] = { "Создатель этой программы - ...", "Иногда вы читаете их", "Есть колонна, а есть ...", "Программисты постоянно сталкиваются с ними", "Их полно на вашем ПК" };

	bool play = true;
	string again;
	int points = 0;
	while (play)
	{
		//выбираем слово
		srand(static_cast<unsigned int>(time(0)));
		int wordN = rand() % 5;
		string word = words[wordN];
		int lettersN = word.size();
		//перемешиваем буквы
		for (; word.empty() == false;)
		{
			int lettersN = word.size();
			int randP = rand() % lettersN;
			char randL = word[randP];
			cout << randL;
			word.erase(randP, 1);
		}

		//спрашиваем пользователя
		string userWord;
		while (play)
		{
			cout << "\n\nВведите ваш вариант: ";
			cin >> userWord;

			//подсказка
			if (userWord == "подсказка")
			{
				cout << hints[wordN];
				points -= 2;
				continue;
			}
			//выход
			if (userWord == "выход")
			{
				play = false;
			}
			//угадал
			else if (userWord == words[wordN])
			{
				cout << "Вы победили!";
				points += lettersN;
				break;
			}

			//íå óãàäàë
			else
			{
				cout << "íåâåðíî";
				--points;
			}
		}
		//заного?
		while (play)
		{
			cout << "\n\nЗаного?(да/нет): ";
			cin >> again;
			if (again == "да")
			{
				break;
			}
			if (again == "нет")
			{
				play = false;
			}
		}
	}
	cout << "\nСпасибо за игру!" << endl;
	cout << "Вы набрали " << points << " очков";
	return 0;
}
