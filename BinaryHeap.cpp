
#include<iostream>
#include<climits>
using namespace std;

// Прототип ф-ції для обміну двох цілих чисел
void swap(int* x, int* y);


class MinHeap
{
    int* harr; // вказівник на масив елементів у кучі
    int capacity; // макс. розмір кучі
    int heap_size; // к-ть елементів кучі
public:
    
    MinHeap(int capacity);

    // перетворює піддерево на мінімальну кучу
    void MinHeapify(int i);

    int parent(int i) { return (i - 1) / 2; }

    //індекс лівого нащадка
    int left(int i) { return (2 * i + 1); }

    // індекс правого нащадка
    int right(int i) { return (2 * i + 2); }

    // видаляємо корінь
    int extractMin();

    // зменшуємо значення ключа у вузлі i до new_vaл
    void decreaseKey(int i, int new_val);

    // повертаємо мінімальний ключ у корені
    int getMin() { return harr[0]; }

    // видаляємо ключ з індексом і
    void deleteKey(int i);

    // додаємо новий ключ 'k'
    void insertKey(int k);
};

// констурктор. створюємо порожню кучу з заданим розміром
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // вставляємо новий ключ у кінець масиву
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // відновлюємо властивість мінімальної кучі
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// припускаємо,що 
// new_val< за поточне значення harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// видаляємо корінь (мінімальнй елемент) з кучі
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    // зберігаємо та видаляємо мінімальне значення
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}


// видаляємо ключ з index i. Зменшуємо значення до манамально можливого і видаляємо його
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

// Рекурсивна функція для перетворення піддерева з коренем в і на кучу. Припускаємо, що піддерева вже є кучами
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// ф-ція для обміну двох елементів
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}