#include <iostream>
#include "Book.h"

using namespace std;

Book::Book(string title, int year, string author)
    : BookItem(title, year)
{
    this->author = author;
}

void Book::display()
{
    cout << "[КНИГА] "
        << "ID: " << id
        << " | Название: " << title
        << " | Автор: " << author
        << " | Год: " << year
        << endl;
}