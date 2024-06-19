#pragma once
#include <iostream>
#include <exception>

#include "/home/artash/Homework/Homework_Artashes_Yeritsyan/Linked_List/List.hpp"

template <typename T>
class MyQueue {
public:
    MyQueue();
    MyQueue(const MyQueue& obj);
    // MyQueue(MyQueue&& obj);


    void push(const T& value); 
    void pop();
    T& front();
    T& back();
    bool empty() const;
    size_t size();
    void swap(MyQueue& other);
    
    bool operator==(const MyQueue<T>& other) const;
    bool operator!=(const MyQueue<T>& other) const;
    bool operator<(const MyQueue<T>& other) const;
    bool operator<=(const MyQueue<T>& other) const;
    bool operator>(const MyQueue<T>& other) const;
    bool operator>=(const MyQueue<T>& other) const;


private:
    List<T> data;
};


#include "Queue.inl"

