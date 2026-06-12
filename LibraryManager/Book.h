#pragma once

#include "BookItem.h"

class Book : public BookItem
{
private:
    string author;

public:
    Book(string title, int year, string author);

    void display() override;
};