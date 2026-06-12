#include <iostream>
#include "Magazine.h"

using namespace std;

Magazine::Magazine(string title, int year, int issueNumber)
    : BookItem(title, year)
{
    this->issueNumber = issueNumber;
}

void Magazine::display()
{
    cout << "[ЖУРНАЛ] "
        << "ID: " << id
        << " | Название: " << title
        << " | Номер выпуска: " << issueNumber
        << " | Год: " << year
        << endl;
}