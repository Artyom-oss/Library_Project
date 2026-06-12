#include <iostream>
#include <windows.h>
#include <vector>
#include <clocale>
#include <limits>
#include "Book.h"
#include "Magazine.h"

using namespace std;

int main()
{
    // Настройка консоли для корректного ввода и вывода русского текста
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    // Контейнер для хранения всех изданий библиотеки
    vector<BookItem*> library;

    int choice;

    do
    {
        // Главное меню программы
        cout << "\n===== LIBRARY MANAGER =====\n";
        cout << "1. Добавить книгу\n";
        cout << "2. Добавить журнал\n";
        cout << "3. Показать все издания\n";
        cout << "4. Удалить по ID\n";
        cout << "5. Искать по названию\n";
        cout << "6. Статистика\n";
        cout << "0. Выход\n";

        cin >> choice;

        // Добавление книги
        if (choice == 1)
        {
            string title;
            string author;
            int year;

            cin.ignore();

            cout << "Название: ";
            getline(cin, title);

            cout << "Автор: ";
            getline(cin, author);

            cout << "Год: ";
            cin >> year;

            library.push_back(
                new Book(title, year, author)
            );
        }

        // Добавление журнала
        else if (choice == 2)
        {
            string title;
            int year;
            int issue;

            cin.ignore();

            cout << "Название журнала: ";
            getline(cin, title);

            cout << "Год: ";
            cin >> year;

            cout << "Номер выпуска: ";
            cin >> issue;

            library.push_back(
                new Magazine(title, year, issue)
            );
        }

        // Вывод списка всех изданий
        else if (choice == 3)
        {
            cout << "\n===== СПИСОК =====\n";

            for (BookItem* item : library)
            {
                item->display();
            }
        }

        // Удаление издания по ID
        else if (choice == 4)
        {
            int id;

            cout << "Введите ID: ";
            cin >> id;

            for (auto it = library.begin(); it != library.end(); ++it)
            {
                if ((*it)->getId() == id)
                {
                    delete* it;
                    library.erase(it);

                    cout << "Удалено.\n";
                    break;
                }
            }
        }

        else if (choice == 5)
        {
            string search;

            cin.ignore();

            cout << "Введите название для поиска: ";
            getline(cin, search);

            cout << "Ищу: [" << search << "]\n";

            bool found = false;

            for (BookItem* item : library)
            {
                cout << "Есть: [" << item->getTitle() << "]\n";

                if (item->getTitle() == search)
                {
                    item->display();
                    found = true;
                }
            }

            if (!found)
            {
                cout << "Не найдено!\n";
            }
        }

        // Вывод статистики библиотеки
        else if (choice == 6)
        {
            int books = 0;
            int magazines = 0;

            for (BookItem* item : library)
            {
                if (dynamic_cast<Book*>(item))
                {
                    books++;
                }
                else if (dynamic_cast<Magazine*>(item))
                {
                    magazines++;
                }
            }

            cout << "\n===== СТАТИСТИКА =====\n";
            cout << "Количество книг: " << books << endl;
            cout << "Количество журналов: " << magazines << endl;
            cout << "Всего изданий: " << library.size() << endl;
        }

    } while (choice != 0);

    // Освобождение памяти перед завершением программы
    for (BookItem* item : library)
    {
        delete item;
    }

    return 0;
}