#include <iostream>

template <typename KEY, typename VALUE>
class HashTable
{
private:
    struct Node
    {
        KEY key;
        VALUE value;
        Node* next;

        Node(const KEY& k, const VALUE& v) : key(k), value(v), next(nullptr) {}
    };

    static const int TABLE_SIZE = 10;
    Node* m_table[TABLE_SIZE]; // Статичний масив указівників на Node

    // Проста хеш-функція
    int HashFunction(const KEY& key) const
    {
        return key % TABLE_SIZE; // Проста хеш-функція для числових ключів
    }

public:
    HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            m_table[i] = nullptr;
        }
    }

    ~HashTable()
    {
        Clear();
    }

    void Clear()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            Node* current = m_table[i];
            while (current != nullptr)
            {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            m_table[i] = nullptr;
        }
    }

    void Insert(const KEY& key, const VALUE& value)
    {
        int index = HashFunction(key);
        if (m_table[index] == nullptr)
        {
            m_table[index] = new Node(key, value);
        }
        else
        {
            Node* current = m_table[index];
            while (current->next != nullptr)
            {
                if (current->key == key)
                {
                    current->value = value; // Оновлюємо значення, якщо ключ уже існує
                    return;
                }
                current = current->next;
            }
            if (current->key == key)
            {
                current->value = value;
            }
            else
            {
                current->next = new Node(key, value);
            }
        }
    }

    bool Remove(const KEY& key)
    {
        int index = HashFunction(key);
        if (m_table[index] == nullptr)
        {
            return false;
        }

        Node* prev = nullptr;
        Node* curr = m_table[index];

        while (curr != nullptr)
        {
            if (curr->key == key)
            {
                if (prev == nullptr)
                {
                    m_table[index] = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    const VALUE& Search(const KEY& key) const
    {
        int index = HashFunction(key);
        Node* node = m_table[index];
        while (node != nullptr)
        {
            if (node->key == key)
            {
                return node->value;
            }
            node = node->next;
        }
        throw "Key not found";
    }
};

// Функція ShowValue поза класом
template <typename KEY, typename VALUE>
void ShowValue(const HashTable<KEY, VALUE>& table, const KEY& key)
{
    try
    {
        const VALUE& value = table.Search(key);
        std::cout << "Value for key " << key << ": " << value << std::endl;
    }
    catch (const char* e)
    {
        std::cout << "Key doesn't exist.\n";
    }
}

int main()
{
    HashTable<int, int> table;
    table.Insert(1, 100);
    table.Insert(2, 200);
    table.Insert(3, 300);

    ShowValue(table, 2);

    if (!table.Remove(2))
    {
        std::cout << "Key doesn't exist.\n";
    }

    ShowValue(table, 2); // Перевірка після видалення

    return 0;
}