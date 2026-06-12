#pragma once

#include "BookItem.h"

class Magazine : public BookItem
{
private:
    int issueNumber;

public:
    Magazine(string title, int year, int issueNumber);

    void display() override;
};