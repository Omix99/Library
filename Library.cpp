#include "Library.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

void Library::AddBook(const Book& book)
{
	books_.push_back(book);
	books_.back().id = books_.size();
}

void Library::AddBook(const int year, const string& name, const string& author)
{
	Book book = { year, name, author };
	books_.push_back(book);
}

vector<Book> Library::GetSelectBooksByDate(const int year) const
{
	vector<Book> temp;
	for (size_t i = 0; i < books_.size(); i++)
	{
		if (books_[i].year == year)
		{
			temp.push_back(books_[i]);
		}
	}
	return temp;
}

vector<Book> Library::GetSelectBooksByName(const string& name) const
{
	vector<Book> temp;
	for (size_t i = 0; i < books_.size(); i++)
	{
		if (books_[i].name == name)
		{
			temp.push_back(books_[i]);
		}
	}
	return temp;
}

vector<Book> Library::GetSelectBooksByAuthor(const string& author) const
{
	vector<Book> temp;
	for (size_t i = 0; i < books_.size(); i++)
	{
		if (books_[i].author == author)
		{
			temp.push_back(books_[i]);
		}
	}
	return temp;
}

void Library::AddReview(const string& name, const string& author, const string& review)
{
	for (size_t i = 0; i < books_.size(); i++)
	{
		if (books_[i].name == name && books_[i].author == author)
		{
			reviews_[books_[i].id].push_back(review);
			break;
		}
	}
}

vector<string> Library::GetReviews(const string& name, const string& author)
{
	for (size_t i = 0; i < books_.size(); i++)
	{
		if (books_[i].name == name && books_[i].author == author)
		{
			return reviews_[books_[i].id];

		}
	}
}

void Library::RemoveBook(const string& name, const string& author)
{
	for (auto it = books_.begin(); it != books_.end(); ++it)
	{
		if (it->name == name && it->author == author)
		{
			books_.erase(it);
			return;
		}
	}
}

