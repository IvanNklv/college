#pragma once
#include <string>

class Person {
public:
    Person()
        : age(1), name("Unknown")
    {
        std::cout << "Default constructor\n";
    }

    Person(int age, const std::string& name)
        : age(age), name(name)
    {
        std::cout << "2param constructor\n";
    }

    Person(const Person& other)
        : age(other.age), name(other.name)
    {
        std::cout << "Copy constructor\n";
    }

    Person(Person&& other) noexcept
        : age(other.age), name(other.name)
    {
        std::cout << "Move constructor\n";
    }

    Person& operator=(const Person& other)
    {
        if (this != &other) {
            std::cout << "copy operator=\n";
            age = other.age;
            name = other.name;
        }
        return *this;
    }

    Person& operator=(Person&& other) noexcept
    {
        if (this != &other) {
            std::cout << "move operator=\n";
            age = std::move(other.age);
            name = std::move(other.name);
        }
        return *this;
    }

    ~Person()
    {
        std::cout << "Destructor\n";
    }

    const std::string& Name() const
    {
        return name;
    }

    int Age() const
    {
        return age;
    }

private:
    int age;
    std::string name;
};

bool operator==(const Person& person1, const Person& person2)
{
    return person1.Age() == person2.Age() && person1.Name() == person2.Name();
}

template<typename Container>
void Show(const Container& container)
{
    if (container.empty()) {
        std::cout << "empty";
    }
    else {
        typename Container::const_iterator iter = container.cbegin();
        for (; iter != container.cend(); ++iter)
            std::cout << *iter << " ";
    }
    std::cout << std::endl;
}
