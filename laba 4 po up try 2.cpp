/*
Вариант 7.
Входные данные содержат упорядоченные по ФИО сведения об абонентах телефонной станции. Данные об абоненте содержат:
•	ФИО;
•	семизначный номер телефона.
Программа должна обеспечивать выполнение следующих действий со списком:
•	по номеру телефона найти ФИО;
•	по ФИО получить список номеров телефонов.
В случае невозможности выполнения операции должно быть выдано сообщение об ошибке.

*/


#include "pch.h"
#include <iostream>
#include "Header2.h"
#include <string>
using namespace std;
LQueue q;
void printNode(const Node & n)
{
	cout << "ФИО: " << n.fio << endl;
	cout << "Номер: " << n.num << endl;
	cout << "___________________________________\n";
}

void print(Node in)
{
	printNode(in);
	cout << endl;
}

void findBySurname(string fio) {
	cout << "Введите фамилию для поиска соответсвующей ей номера телефона\n";
	bool flag_ = true;
	for (unsigned int i = 0; i < q.GetSize(); ++i)
	{
		if (q.GetByIndex(i).fio == fio)
		{
			cout << "У человека " << fio << " номер телефона ";
			cout << q.GetByIndex(i).num << endl;
			flag_ = false;
		}
	}
	if (flag_) cout << "В списке нет такого человека!\n";
}

void findByNumber(int number) {
	cout << "Введите номер телефона для поиска соответсвующей ему фамилии\n";
	bool flag = true;
	for (unsigned int i = 0; i < q.GetSize(); ++i)
	{
		if (q.GetByIndex(i).num == number)
		{
			cout << "Номер телефона " << number << " встречается у ";
			cout << q.GetByIndex(i).fio << endl;
			flag = false;
		}
	}
	if (flag) cout << "Ни у кого в списке нет такого номера телефона!\n";
}

int main()
{
	system("chcp 1251");
	cout << endl;
	
	int num;
	string tmp;
	Node abonent;
	const int n = 8;
	string xPrmt[n] = {
	 "1 - Записать человека и его номер. ",
	 "2 - Найти по фамилии. ",
	 "3 - Найти по телефону. ",
	 "4 - Вывести весь список.",
	 "5 - Удалить первый элемент. ",
	 "6 - Показать элемент по индексу ",
	 "0 - Завершить ",
	 "Выбери пункт меню, указав соответствующее число : "
	};
	for (;;) {
		for (int i = 0; i < n; ++i)
			cout << xPrmt[i] << endl;
		cout << endl;
		int nMenu;
		cin >> nMenu;
		switch (nMenu) {
		case 0:
			break;
		case 1: 
			getline(cin, abonent.fio, '\n');
			cin >> abonent.num;
			q.Push(abonent);
			q.SortQueue(q);
			break;
		case 2: 
			getline(cin, tmp, '\n');
			findBySurname(tmp);
			tmp.erase();
			break;
		case 3: 
			cin >> num;
			findByNumber(num);
			break;
		case 4: 
			q.SortQueue(q);
			q.Browse(print);
			break;
		case 5: 
			q.Pop();
			q.SortQueue(q);
			q.Browse(print);
			break;
		case 6: 
			cout << "Введите индекс: " << endl;
			cin >> num;
			printNode(q.GetByIndex(num));
			break;
		}
		if (nMenu == 0) break;
	}

	


	

	

	
}