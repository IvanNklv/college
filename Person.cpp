#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include "Person.h"

int main()
{
    // КОНСТРУКТОР:
    std::cout << "--- Constructors ---\n";

    // 1. КОНСТРУКТОР ЗА УМОВЧАННЯМ
    Person p1;
    std::cout << "p1 - Age: " << p1.Age() << ", Name: " << p1.Name() << "\n";

    // 2. ПАРАМЕТР: std::initializer_list
    std::vector<int> vec1 = { 1, 2, 3 };
    Show(vec1);

    // 3. КОНСТРУКТОР КОПІЇ
    Person p2(25, "John");
    Person p3(p2);
    std::cout << "p3 - Age: " << p3.Age() << ", Name: " << p3.Name() << "\n";

    // 4. КОНСТРУКТОР ПЕРЕНОСУ
    Person p4(std::move(p2));
    std::cout << "p4 - Age: " << p4.Age() << ", Name: " << p4.Name() << "\n";

    // 5. ПАРАМЕТР: iterator begin, iterator end
    std::list<int> list1 = { 10, 20, 30 };
    std::list<int> list2(list1.begin(), list1.end());
    Show(list2);

    // 6. ПАРАМЕТР: size_t включить_элементы
    std::deque<int> deque1(5);
    Show(deque1);

    // 7. ПАРАМЕТР: size_t включить_элементы, const T& значение
    std::vector<int> vec2(3, 42);
    Show(vec2);

    // Деструктор:
    std::cout << "--- Destructor ---\n";
    {
        std::deque<int> deque{ 1, 2, 3 };
        std::deque<int> otherDeque{ 1, 2, 3 };
        Show(deque); // 1 2 3

        deque = { 10, 20, 30, 40, 50 };
        Show(deque); // 10 20 30 40 50

        deque = otherDeque; // copy deque
        Show(deque); // 1 2 3

        deque = std::deque<int>{ 100, 100, 100 }; // move deque
        Show(deque); // 100 100 100
    }

    // Методи:
    std::cout << "--- Methods ---\n";

    // 8. begin - повертає ітератор на початок
    // 9. end - повертає ітератор на кінець
    {
        std::deque<int> deque{ 10, 20, 30, 40, 50 };
        for (auto iter = deque.begin(); iter != deque.end(); ++iter)
        {
            std::cout << *iter << " "; // 10 20 30 40 50
        }
        std::cout << "\n";
    }

    // 10. rbegin - повертає обернений ітератор на початок
    // 11. rend - повертає обернений ітератор на кінець
    {
        std::deque<int> deque{ 10, 20, 30, 40, 50 };
        for (auto iter = deque.rbegin(); iter != deque.rend(); ++iter)
        {
            std::cout << *iter << " "; // 50 40 30 20 10
        }
        std::cout << "\n";
    }

    // 12. cbegin - повертає константний ітератор на початок
    // 13. cend - повертає константний ітератор на кінець
    {
        std::deque<int> deque{ 10, 20, 30, 40, 50 };
        for (auto iter = deque.cbegin(); iter != deque.cend(); ++iter)
        {
            std::cout << *iter << " "; // 10 20 30 40 50
        }
        std::cout << "\n";
    }

    // 14. crbegin - повертає константний обернений ітератор на початок
    // 15. crend - повертає константний обернений ітератор на кінець
    {
        std::deque<int> deque{ 10, 20, 30, 40, 50 };
        for (auto iter = deque.crbegin(); iter != deque.crend(); ++iter)
        {
            std::cout << *iter << " "; // 50 40 30 20 10
        }
        std::cout << "\n";
    }

    // 16. empty - повертає true, якщо контейнер пустий
    {
        std::deque<int> deque1;
        std::deque<int> deque2{ 1, 2, 3 };
        std::cout << "deque1 is " << (deque1.empty() ? "empty" : "not empty") << "\n"; // empty
        std::cout << "deque2 is " << (deque2.empty() ? "empty" : "not empty") << "\n"; // not empty
    }

    // 17. size - повертає розмір контейнера
    {
        std::deque<int> deque{ 1, 2, 3 };
        std::cout << "deque size: " << deque.size() << "\n"; // 3
    }

    // 18. max_size - повертає максимальний можливий розмір контейнера
    {
        std::deque<int> deque;
        std::cout << "deque max_size: " << deque.max_size() << "\n"; // Залежить від реалізації
    }

    // 19. resize - змінює розмір контейнера
    {
        std::deque<int> deque{ 1, 2, 3 };
        deque.resize(5, 0); // Додаємо 2 елементи зі значенням 0
        Show(deque); // 1 2 3 0 0
        deque.resize(2); // Зменшуємо до 2 елементів
        Show(deque); // 1 2
    }
// 20. push_back - додає елемент у кінець
    {
        std::deque<int> deque{ 1, 2, 3 };
        deque.push_back(4);
        Show(deque); // 1 2 3 4
    }

    // 21. push_front - додає елемент на початок
    {
        std::deque<int> deque{ 1, 2, 3 };
        deque.push_front(0);
        Show(deque); // 0 1 2 3
    }

    // 22. pop_back - видаляє елемент з кінця
    {
        std::deque<int> deque{ 1, 2, 3 };
        deque.pop_back();
        Show(deque); // 1 2
    }

    // 23. pop_front - видаляє елемент з початку
    {
        std::deque<int> deque{ 1, 2, 3 };
        deque.pop_front();
        Show(deque); // 2 3
    }

    // 24. front - повертає перший елемент
    {
        std::deque<int> deque{ 1, 2, 3 };
        std::cout << "Front element: " << deque.front() << "\n"; // 1
    }

    // 25. back - повертає останній елемент
    {
        std::deque<int> deque{ 1, 2, 3 };
        std::cout << "Back element: " << deque.back() << "\n"; // 3
    }

    // 26. clear - очищає контейнер
    {
        std::deque<int> deque{ 1, 2, 3 };
        deque.clear();
        std::cout << "After clear, deque is " << (deque.empty() ? "empty" : "not empty") << "\n"; // empty
    }

    // 27. swap - обмінює вміст двох контейнерів
    {
        std::deque<int> deque1{ 1, 2, 3 };
        std::deque<int> deque2{ 4, 5, 6 };
        deque1.swap(deque2);
        std::cout << "deque1 after swap: ";
        Show(deque1); // 4 5 6
        std::cout << "deque2 after swap: ";
        Show(deque2); // 1 2 3
    }

    return 0;
}
