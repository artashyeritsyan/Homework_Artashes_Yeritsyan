#include "string.hpp"


myString::myString():m_size(1){
    stackBuffer[0] = '\0';
    m_size = 0;
    m_size =(m_size << 1) | 1;
}

myString::myString(std::initializer_list<char> u):m_size(u.size()){
    if(m_size < DEFAULT_CAPACITY){
        m_size = (m_size << 1) | 1;
        for(size_t i = 0; i < this->size(); ++i){
            stackBuffer[i] = u.begin()[i];
        }
        
    } else{
        m_size = (m_size << 1);

        heapBuffer._capacity = size() * 2;
        heapBuffer._data = static_cast<char*>(malloc(heapBuffer._capacity*sizeof(char)));

        for(size_t i = 0; i < this->size(); ++i){
            heapBuffer._data[i] = u.begin()[i]; 
        }
    }
}


myString::myString(const char *n){
    if(n){
        m_size = std::strlen(n);
        
        if(m_size < DEFAULT_CAPACITY){

            m_size = (m_size << 1) | 1;
            for(size_t i = 0; i < this->size(); ++i){
                stackBuffer[i] = n[i];
            }
        }else{
            m_size = (m_size << 1);

            heapBuffer._capacity = size() * 2;
            heapBuffer._data = static_cast<char*>(malloc(heapBuffer._capacity*sizeof(char)));

            for(size_t i = 0; i < this->size(); ++i){
                heapBuffer._data[i] = n[i]; 
            }
        }
    } else {
        myString();
    }
}

size_t myString::size(){ 
    return m_size >> 1;
}

bool myString::is_sso(){
    return m_size & 1;
}

size_t myString::capacity(){
    if(is_sso()){
        return DEFAULT_CAPACITY;
    }else{
        return heapBuffer._capacity;
    }
}

myString::myString(myString& other){
    if(is_sso()){
        for(size_t i = 0; i < size(); ++i){
            stackBuffer[i] = other.stackBuffer[i]; 
        }
    } else {
        for(size_t i = 0; i < size(); ++i){
            heapBuffer._data[i] = other.heapBuffer._data[i];
        }
    }
}

myString::myString(myString&& other){
    if(is_sso()){
        for(size_t i = 0; i < size(); ++i){
            other.stackBuffer[i] =  stackBuffer[i]; 
        }
    } else {
        for(size_t i = 0; i < size(); ++i){
            other.heapBuffer._data[i] = heapBuffer._data[i];
        }
    }
}

void myString::pushback(const char *u){
    if(is_sso()){
        if(size() > DEFAULT_CAPACITY){
            myString newStr(*this);
        }
    }
}


char& myString::operator[](size_t i){
    if(is_sso()){
        return stackBuffer[i];
    }else{
        return heapBuffer._data[i];
    }
}

std::ostream& operator<<(std::ostream &out, myString &u){
    if(u.is_sso()){
        for(size_t i = 0; i < u.size(); ++i){
            out << u.stackBuffer[i];
        }
    }else{
        for(size_t i = 0; i < u.size(); ++i){
            out << u.heapBuffer._data[i];
        }
    }
    return out;
}

myString::Iterator myString::begin(){
    if(is_sso()){
        return Iterator(stackBuffer);
    } else {
        return Iterator(heapBuffer._data);
    }
}

myString::Iterator myString::end(){
    if(is_sso()){
        *stackBuffer = stackBuffer[size() - 1];
        return Iterator(stackBuffer);
    }else{
        *heapBuffer._data = heapBuffer._data[size() - 1];
        return Iterator(heapBuffer._data); 
    }
}
