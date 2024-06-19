#pragma once
#include <exception>

template<typename T>
class List
{

private:
    struct Node {
        Node *next = nullptr;
        Node *prev = nullptr;
        T data;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node *head;
    Node *tail;
    size_t _size;

public:
    template<typename MyIterator>
    List(MyIterator, MyIterator);
    List();
    List(size_t, const T&);
    List(const List<T>&);
    ~List();
    
    void push_back(const T&);
    void push_front(const T&);
    void pop_back();
    void pop_front();
    bool empty() const;
    void insert(size_t, const T&);
    void erase(size_t);
    void resize(size_t);
    void resize(size_t, const T&);
    void swap(List<T>&);
    void sort(List<T>&);
    void print() const;
    void clear();
    size_t size() const;
    T& front();
    T& back();
    T* Data(size_t);

    List& operator=(const List<T>&);
    bool operator==(const List<T>&) const;
    bool operator!=(const List<T>&) const;
    bool operator<(const List<T>&) const;
    bool operator<=(const List<T>&) const;
    bool operator>(const List<T>&) const;
    bool operator>=(const List<T>&) const;

    class My_iterator{
        private:
            Node* ptr = nullptr;
            Node* prev;
        public:
            My_iterator() = default;
            My_iterator(Node*);
            My_iterator(Node*, Node*);

            My_iterator& operator++();
            My_iterator& operator++(int);
            My_iterator& operator--(); 
            My_iterator& operator--(int); 
            T& operator*() const;
            T& operator*();
            bool operator==(const My_iterator&);
            bool operator!=(const My_iterator&);
    };

    My_iterator Begin() const;
    My_iterator End() const;

};

#include "List.inl"


