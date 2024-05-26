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

    size_t size() const;
    size_t capacity();
    bool empty();
    void reserve(size_t new_capacity);
    void resize(size_t size, T value = 0);
    void shrink_to_fit();

    void push_back(T value);
    void pop_back();
    void insert(size_t position, T value = 0);
    void erase(size_t position);
    void clear();
    void swap(My_Vector& obj);

    T& operator[] (size_t index);
    const T& operator[] (size_t index) const;
    My_Vector<T>& operator= (My_Vector<T>& obj);
    bool operator!=(const My_Vector<T>& obj) const;
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

    T* _data = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;
};


#include "Vector.inl"

#endif // VECTOR_HPP
