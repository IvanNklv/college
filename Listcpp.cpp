#include "List.h"
#include <iostream>

List::List(const List& other) : head(nullptr), tail(nullptr), size(0) {
    Copy(other);
}

List::List(List&& other) noexcept : head(other.head), tail(other.tail), size(other.size) {
    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
}

List::~List() {
    Clear();
}

List& List::operator=(const List& other) {
    if (this != &other) {
        Clear();
        Copy(other);
    }
    return *this;
}

List& List::operator=(List&& other) noexcept {
    if (this != &other) {
        Clear();
        head = other.head;
        tail = other.tail;
        size = other.size;
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }
    return *this;
}

void List::Copy(const List& other) {
    Node* current = other.head;
    while (current != nullptr) {
        PushBack(current->data);
        current = current->next;
    }
}

void List::Move(List&& other) noexcept {
    Clear();
    head = other.head;
    tail = other.tail;
    size = other.size;
    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
}

void List::PushBack(const int& value) {
    Node* newNode = new Node{ value, tail, nullptr };
    if (tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
    size++;
}

void List::PushFront(const int& value) {
    Node* newNode = new Node{ value, nullptr, head };
    if (head) {
        head->previous = newNode;
    }
    else {
        tail = newNode;
    }
    head = newNode;
    size++;
}

void List::PopBack() {
    if (!tail) return;
    Node* temp = tail;
    tail = tail->previous;
    if (tail) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }
    delete temp;
    size--;
}

void List::PopFront() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) {
        head->previous = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete temp;
    size--;
}

int& List::Back() {
    if (!tail) throw std::runtime_error("List is empty");
    return tail->data;
}

const int& List::Back() const {
    if (!tail) throw std::runtime_error("List is empty");
    return tail->data;
}

void List::Remove(const int& value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            Node* prevNode = current->previous;
            Node* nextNode = current->next;
            if (prevNode) prevNode->next = nextNode;
            else head = nextNode;
            if (nextNode) nextNode->previous = prevNode;
            else tail = prevNode;
            delete current;
            size--;
            current = nextNode;
        }
        else {
            current = current->next;
        }
    }
}

bool List::Find(const int& value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

void List::Reverse() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current->next;
        current->next = current->previous;
        current->previous = temp;
        current = temp;
    }
    Node* temp = head;
    head = tail;
    tail = temp;
}

void List::Clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

bool List::IsEmpty() const {
    return size == 0;
}

size_t List::Size() const {
    return size;
}

void List::Show() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}