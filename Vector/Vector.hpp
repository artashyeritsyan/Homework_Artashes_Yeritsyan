#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class My_Vector {
public:

    My_Vector():_data(nullptr), _size(0), _capacity(0) {}
    My_Vector (size_t size);
    My_Vector(const My_Vector<T>& obj);
    ~My_Vector ();

    // Capacity

    size_t size();
    size_t capacity();
    bool empty();
    void reserve(size_t new_capacity);
    void resize(size_t size, T value = 0);
    void shrink_to_fit();

    // Modifiers

    void push_back(T value);
    void pop_back();
    void insert(size_t position, T value = 0);
    void erase(size_t position);
    void clear();
    void swap(size_t first_position, size_t second_position);

    T& operator[] (size_t index);
    My_Vector<T>& operator= (My_Vector<T>& obj);
    T& at(size_t position);
    T& front();
    T& back();
    T* data();
  
    class My_Iterator {
    private:
        T* my_iter;
    public:
        My_Iterator(T* p) { my_iter = p;}

        My_Iterator& operator++() { ++my_iter; return *this; }
        My_Iterator operator++(int){ My_Iterator tmp = *this; ++my_iter; return tmp; } 
        My_Iterator& operator--() { --my_iter; return *this; }
        T& operator*() { return *my_iter; }
        const T& operator*() const { return *my_iter; }
        bool operator==(const My_Iterator& other) const { return my_iter == other.my_iter; }
        bool operator!=(const My_Iterator& other) const { return !(*this == other); }
    };

    My_Iterator begin();
    My_Iterator end();
private:

    T* _data;
    size_t _size;
    size_t _capacity;
};

#include "Vector.inl"

#endif // VECTOR_HPP
