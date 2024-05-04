#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct Book
{
	int year = 0;
	string name;
	string author;
	int id = 0;
};

class Library
{
public:
	void AddBook(const Book& book);

	void AddBook(const int year, const string& name, const string& author);

	void AddReview(const string& name, const string& author, const string& review);

	void RemoveBook(const string& name, const string& author);
	
	vector<Book> GetSelectBooksByDate(const int year) const;
	
	vector<Book> GetSelectBooksByName(const string& name) const;
	
	vector<Book> GetSelectBooksByAuthor(const string& author) const;

	vector<string> GetReviews(const string& name, const string& author);

private:
	vector<Book> books_;
	map<int, vector<string>> reviews_;
};