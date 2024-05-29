#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Vector {
public:
    Vector(int initCapacity = 16) {
        size = 0;
        capacity = initCapacity;
        array = new T[capacity]; 
    } 

    ~Vector() {
        delete[] array;
    }

    Vector& operator=(const Vector& rhs) {
        if (this != &rhs) {
            delete[] array;
            size = rhs.size;
            capacity = rhs.capacity;
            array = new T[capacity];

            for (int i = 0; i < size; i++) {
                array[i] = rhs.array[i];
            }
        }
        return *this;
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return array[index];
    }

    void pushBack(const T& value) {
        if (size == capacity) {
            expand(2 * capacity);
        }
        array[size++] = value;
    }

    void insert(int index, const T& value) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }
        if (size == capacity) {
            expand(2 * capacity);
        }
        for (int i = size; i > index; --i) {
            array[i] = array[i - 1];
        }
        array[index] = value;
        ++size;
    }

    void popBack() {
        if (size > 0) {
            --size;
        }
    }

    void clear() {
        size = 0;
    }

    void erase(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; ++i) {
            array[i] = array[i + 1];
        }
        --size;
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void expand(int newCapacity) {
        if (newCapacity <= size) {
            return;
        }
        T* old = array;
        array = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            array[i] = old[i];
        }
        delete[] old;
        capacity = newCapacity;
    }

private:
    T* array;
    int size;
    int capacity;
};

int main() {
    Vector<int> v;
    v.pushBack(6);
    v.pushBack(2);
    v.pushBack(9);
    v.pushBack(1);
    v.pushBack(8);

    cout << "Cac phan tu: ";
    v.print(); 

    cout << "Kich thuoc: " << v.getSize() << endl; 

    v.insert(2, 7);

    cout << "Sau khi chen 7 vao vi tri 2: ";
    v.print(); 

    v.popBack();
    v.erase(1);

    cout << "Sau khi xoa 2 va 8: ";
    v.print();

    return 0;
}
