#include "BookItem.h"

int BookItem::nextId = 1;

BookItem::BookItem(string title, int year)
{
    id = nextId++;
    this->title = title;
    this->year = year;
}

int BookItem::getId() const
{
    return id;
}

string BookItem::getTitle() const
{
    return title;
}