#include "Queue.hpp"

template <typename T>
inline MyQueue<T>::MyQueue()
{
}

template <typename T>
inline MyQueue<T>::MyQueue(const MyQueue &obj) {
    this -> data = obj.data;
}

template <typename T>
void MyQueue<T>::push(const T &value)
{
    data.push_back(value);
}

template <typename T>
void MyQueue<T>::pop() {
    if (data.empty()) {
        throw std::out_of_range("MyQueue is empty");
    }
    data.pop_front();
}

template <typename T>
T& MyQueue<T>::front() {
    if (data.empty()) {
        throw std::out_of_range("MyQueue is empty");
    }
    return data.front();
}

template <typename T>
T& MyQueue<T>::back() {
    if (data.empty()) {
        throw std::out_of_range("MyQueue is empty");
    }
    return data.back();
}

template <typename T>
bool MyQueue<T>::empty() const {
    return data.empty();
}

template <typename T>
size_t MyQueue<T>::size() {
    return data.size();
}

template <typename T>
void MyQueue<T>::swap(MyQueue<T>& other)
{
    MyQueue<T> tmp_obj = other;
    other = *this;
    *this = tmp_obj;
}

template <typename T>
bool MyQueue<T>::operator==(const MyQueue<T> &other) const
{
    return *this->q == other.q;
}

template <typename T>
bool MyQueue<T>::operator!=(const MyQueue<T>& other) const {
    return *this->q != other.q;
}

template <typename T>
bool MyQueue<T>::operator<(const MyQueue<T>& other) const {
    return *this->q < other.q;
}

template <typename T>
bool MyQueue<T>::operator<=(const MyQueue<T>& other) const {
    return *this->q <= other.q;
}

template <typename T>
bool MyQueue<T>::operator>(const MyQueue<T>& other) const {
    return *this->q > other.q;
}

template <typename T>
bool MyQueue<T>::operator>=(const MyQueue<T>& other) const {
    return *this->q >= other.q;
}

