#pragma once
class List
{
private:
	struct Node
	{
		int data;
		Node* previous;
		Node* next;
	};
	Node* head;
	Node* tail;
	size_t size;

	void Copy(const List& other);
	void Move(List&& other) noexcept;

public:
    List(const List& other);
    List(List&& other) noexcept;
    ~List();

    List& operator=(const List& other);
    List& operator=(List&& other) noexcept;

    void PushBack(const int& value);
    void PushFront(const int& value);

    void PopBack();
    void PopFront();

    int& Back();
    const int& Back() const;

    void Remove(const int& value);
    bool Find(const int& value);

    void Reverse();
    void Clear();

    bool IsEmpty() const;
    size_t Size() const;

    void Show() const;
};