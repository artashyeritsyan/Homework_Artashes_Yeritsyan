#pragma once
#include "List.hpp"

template<typename T>
List<T>::List() : head(nullptr), tail(nullptr), _size(0) {}

template<typename T>
List<T>::List(size_t NewSize, const T& value) : head(nullptr), tail(nullptr), _size(0){
    for(size_t i = 0; i < NewSize; ++i){
        push_back(value);
    }
}

template<typename T>
List<T>::List(const List<T>& obj) : head(nullptr), tail(nullptr), _size(0) {
    Node *current = obj.head;
    while(current){
        this -> push_back(current -> data);
        current = current -> next;
    }
}

template<typename T>
template<typename MyIterator>
List<T>::List(MyIterator first, MyIterator second) : head(nullptr), tail(nullptr), _size(0){
    while(first != second){
        push_back(*first);
        ++first;
    }
}


template<typename T>
List<T>::~List(){
   clear();
}

template<typename T>
void List<T>::push_back(const T& value){
    Node *tmp_node = new Node(value);
    if(!tmp_node){
        std::bad_alloc();
    }

    if(!head){
        head = tail = tmp_node;
    }
    else{
        tmp_node -> prev = tail;
        tail -> next = tmp_node;
        tail = tmp_node;
    }
    
    _size++;
}

template<typename T>
void List<T>::push_front(const T& value){
    Node *tmp_node = new Node(value);
    if(!tmp_node){
        std::bad_alloc();
    }

    if(!head){
        head = tail = tmp_node;
    }
    else{
        tmp_node -> next = head;
        head -> prev = tmp_node;
        head = tmp_node;
    }
    
    _size++;
}

template<typename T>
T& List<T>::front(){
    return head -> data;
}

template<typename T>
T& List<T>::back(){
    return tail -> data;
}

template<typename T>
T* List<T>::Data(size_t index){
    if(index >= _size){
        std::out_of_range(" Index is out of size");
    }

    Node *tmp = head;

    for(size_t i = 0; i < index; ++i){
        tmp = tmp -> next;
    }

    return tmp -> data;
}

template<typename T>
bool List<T>::empty() const {
    return _size == 0;
}

template<typename T>
size_t List<T>::size() const{
    return this -> _size;
}

template<typename T>
void List<T>::insert(size_t index, const T& value){

    if(index >= _size){
        std::out_of_range("Index is out of size");
    }

    else if(index == _size){
        push_back(value);
        return;
    }
    else{
        Node *current = head;
        for(size_t i = 0; i < index; ++i){
            current = current -> next;
        }
        Node *tmp_node = new Node(value);

        if(!tmp_node){
            std::bad_alloc();
        }

        tmp_node -> prev = current -> prev;
        tmp_node -> next = current;

        if(current -> prev){
            current -> prev -> next = tmp_node;
        }
        else{
            head = tmp_node;
        }

        current -> prev = tmp_node;
        _size++;
    }
}

template<typename T>
void List<T>::pop_back(){

    if(!tail){
        std::cerr<<"List is empty";
    }

    Node *prevTail = tail -> prev;

    if(prevTail){
        prevTail -> next = nullptr;
    }
    else{
        head = nullptr;
    }

    delete tail;
    tail = prevTail;
    _size--;

    if(!tail){
        head = nullptr;
    }

}
template<typename T>
void List<T>::pop_front(){

    if(!tail){
        std::cerr<<"List is empty";
    }

    Node *nextHead = head -> next;

    if(nextHead){
        nextHead -> prev = nullptr;
    }
    else{
        tail = nullptr;
    }

    delete head;
    head = nextHead;
    _size--;

    if(!head){
        tail = nullptr;
    }
}

template<typename T>
void List<T>::erase(size_t index){

    Node* current = head;

    for(size_t i = 0; i < index; ++i){
        current = current -> next;
    }

    if(current -> prev){
        current -> prev -> next = current -> next;
    }
    else{
        head = current -> next;
    }

    if(current -> next){
        current -> next -> prev = current -> prev;
    }
    else{
        tail = current -> prev;
    }

    delete current;
    _size--;
}

template<typename T>
void List<T>::resize(size_t newSize, const T& value){
    if(newSize < _size){
        while(_size > newSize){
            pop_back();
        }
    }
    else if(newSize > _size){
        while(_size < newSize){
            push_back(value);
        }
    }
}

template<typename T>
void List<T>::resize(size_t newSize){

    if(newSize < _size){
        while(_size > newSize){
            pop_back();
        }
    }
    else if(newSize > _size){
        while(_size < newSize){
            push_back(T());
        }
    }
}

template<typename T>
void List<T>::swap(List<T>& obj){
    std::swap(this -> head, obj.head);
    std::swap(this -> tail, obj.tail);
    std::swap(this -> _size, obj._size);
}

template<typename T>
void List<T>::sort(List<T>& obj){
    if(_size <= 1)
        return;
    
    bool swapped;
    Node *current;
    Node *LastSwap;

    do{
        swapped = false;
        current = head;

        while(current -> next != LastSwap){
            if(current -> data > current -> next -> data){
                std::swap(current -> data, current -> next -> data);
                swapped = true;
            }
            current = current -> next;
        }
        LastSwap = current;
    }
    while(swapped);

}

template<typename T>
void List<T>::clear(){

Node *tmp = head;

    while(tmp){
        Node *Next = tmp -> next;
        delete tmp;
        tmp = Next;
    }
    head = tail = nullptr;
    _size = 0;
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& obj){
    if(*this != obj){
        clear();

        Node* tmp = obj.head;
            while(tmp){
                push_back(tmp -> data);
                tmp = tmp -> next;
            }
    }
    return *this;
}


template<typename T>
bool List<T>::operator==(const List<T>& obj) const {
    if(this -> _size != obj._size){
        return false;
    }

    Node* current1 = this -> head;
    Node* current2 = obj.head;

    while(current1 && current2){
        if(current1 -> data != current2 -> data){
            return false;
        }
        current1 = current1 -> next;
        current2 = current2 -> next;
    }
    return true;
}

template<typename T>
bool List<T>::operator!=(const List<T>& obj) const {

    return !(*this == obj);
}

template<typename T>
bool List<T>::operator<(const List<T>& obj) const {

    Node* current1 = this -> head;
    Node* current2 = obj.head;

    while(current1 && current2){
        if(current1 -> data < current2 -> data){
            return true;
        }
        else if(current1 -> data > current2 -> data){
            return false;
        }
        current1 = current1 -> next;
        current2 = current2 -> next;
    }
    return (this -> _size < obj._size);;
}

template<typename T>
bool List<T>::operator>(const List<T>& obj) const {

    Node* current1 = this -> head;
    Node* current2 = obj.head;

    while(current1 && current2){
        if(current1 -> data > current2 -> data){
            return true;
        }
        else if(current1 -> data < current2 -> data){
            return false;
        }
        current1 = current1 -> next;
        current2 = current2 -> next;
    }
    return (this -> _size > obj._size);;
}

template<typename T>
bool List<T>::operator<=(const List<T>& obj) const {
    return (*this < obj) || (*this == obj);
}

template<typename T>
bool List<T>::operator>=(const List<T>& obj) const {
    return (*this > obj) || (*this == obj);
}



template<typename T>
List<T>::My_iterator::My_iterator(Node* obj) : ptr(obj) {prev = ptr -> prev;}

template<typename T>
List<T>::My_iterator::My_iterator(Node* obj1, Node* obj2) : ptr(obj1), prev(obj2) {}

template<typename T>
T& List<T>::My_iterator::operator*(){
    assert(ptr);
    if(ptr)
        return ptr -> data;
    T t;
    return t;
}

template<typename T>
T& List<T>::My_iterator::operator*() const{
    assert(ptr);
    if(ptr)
        return ptr -> data;
    T t;
    return t;
}

template<typename T>
typename List<T>::My_iterator& List<T>::My_iterator::operator++(){
    assert(ptr);
    if(!ptr)
        return *this;

    prev = ptr;
    ptr = ptr -> next;
    return *this;
}

template<typename T>
typename List<T>::My_iterator& List<T>::My_iterator::operator++(int){
    auto ret = *this;
    this -> operator++();
    return ret;
}

template<typename T>
typename List<T>::My_iterator& List<T>::My_iterator::operator--(){
    assert(prev);
    if(!prev)
        return *this;

    ptr = prev;
    prev = prev -> prev;
    return *this;
}

template<typename T>
typename List<T>::My_iterator& List<T>::My_iterator::operator--(int){
    assert(prev);
    if(!prev)
        return *this;

    ptr = prev;
    prev = prev -> prev;
    return *this;
}

template<typename T>
bool List<T>::My_iterator::operator!=(const My_iterator& obj) {
    return this -> ptr != obj.ptr;
}

template<typename T>
bool List<T>::My_iterator::operator==(const My_iterator& obj) {
    return this -> ptr == obj.ptr;
}

template<typename T>
typename List<T>::My_iterator List<T>::Begin() const {
    return My_iterator(head);
}

template<typename T>
typename List<T>::My_iterator List<T>::End() const {
    return My_iterator(nullptr, tail);
}

template<typename T>
void List<T>::print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }





