#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Library.h"

using namespace std;

void selectBooksByDate(const Library& lib)
{
	int date;
	cout << "УКАЖИТЕ ГОД КНИГИ" << endl;
	cin >> date;
	vector<Book> temp = lib.GetSelectBooksByDate(date);
	for (size_t i = 0; i < temp.size(); i++)
	{
		cout << temp[i].name << " --- " << temp[i].author << endl;
	}
}

void selectBooksByName(const Library& lib)
{
	string name;
	cout << "УКАЖИТЕ НАЗВАНИЕ КНИГИ" << endl;
	cin >> name;
	vector<Book> temp = lib.GetSelectBooksByName(name);
	for (size_t i = 0; i < temp.size(); i++)
	{
		cout << temp[i].year << " --- " << temp[i].author << endl;
	}
}

void selectBooksByAuthor(const Library& lib)
{
	string author;
	string review;
	cout << "УКАЖИТЕ НАЗВАНИЕ КНИГИ" << endl;
	cin >> author;
	vector<Book> temp = lib.GetSelectBooksByAuthor(author);
	for (size_t i = 0; i < temp.size(); i++)
	{
		cout << temp[i].year << " --- " << temp[i].name << endl;
	}
}

void selectBooksByReview(Library& lib)
{
	string name;
	string author;
	string review;

	cout << "ВВЕДИТЕ НАЗВАНИЕ КНИГИ" << endl;
	cin >> name;
	cout << "ВВЕЕДИТЕ АВТОРА" << endl;
	cin >> author;
	vector<string> temp = lib.GetReviews(name, author);
	for (size_t i = 0; i < temp.size(); i++)
	{
		cout << temp[i] << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	Library lib;
	
	while (true)
	{
		int choice = 0;
		string name;
		string author;
		string review;

		cout << "1) Найти книгу" << endl;
		cout << "2) Добавить книгу" << endl;
		cout << "3) Удалить книгу" << endl;
		cout << "4) Добавить рецензию" << endl;
		cout << "5) Просмотр рецензии" << endl;
		cout << "0) Выход из программы" << endl;

		cin >> choice;

		if (choice == 1)
		{
			char subChoice = ' ';
			cout << "a) по дате" << endl;
			cout << "b) по названию" << endl;
			cout << "c) автору" << endl;
			cin >> subChoice;
			if (subChoice == 'a')
				selectBooksByDate(lib);
			if (subChoice == 'b')
				selectBooksByName(lib);
			if (subChoice == 'c')
				selectBooksByAuthor(lib);
		}
		if (choice == 2)
		{
			int year;
			string name;
			string author;
			cout << "УКАЖИТЕ ГОД ИЗДАНИЯ" << endl;
			cin >> year;
			cout << "УКАЖИТЕ НАЗВАНИЕ КНИГИ" << endl;
			cin >> name;
			cout << "УКАЖИТЕ АВТОРА" << endl;
			cin >> author;
			lib.AddBook(year, name, author);
			cout << "КНИГА ДОБАВЛЕНА" << endl;
		}
		if (choice == 3)
		{
			string name, author;
			cout << "УКАЖИТЕ НАЗВАНИЕ КНИГИ" << endl;
			cin >> name;
			cout << "УКАЖИТЕ АВТОРА КНИГИ" << endl;
			cin >> author;

			lib.RemoveBook(name, author);

			cout << "КНИГА УДАЛЕНА" << endl;
		}
		if (choice == 4)
		{
			string name;
			string author;
			string review;
			cout << "ВВЕДИТЕ НАЗВАНИЕ КНИГИ" << endl;
			cin >> name;
            cout << "ВВЕЕДИТЕ АВТОРА" << endl;
			cin >> author;
			cout << "ВВЕДИТЕ РЕЦЕНЗИЮ" << endl;
			cin >> review;
			lib.AddReview(name, author, review);
		}
		if (choice == 5)
		{
			
			if (true)
				selectBooksByReview(lib);
		
		}
		if (choice == 0)
		{
			break;
		}


	}

}
