#pragma once

#include <string>

using namespace std;

class BookItem
{
protected:
    int id;
    string title;
    int year;

    static int nextId;

public:
    BookItem(string title, int year);
    
    string getTitle() const;
    
    virtual void display() = 0;

    int getId() const;
};