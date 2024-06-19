#pragma once
#include <cstddef>
#include <initializer_list>
#include <stdlib.h>
#include <cstring>
#include <ostream>
#include <assert.h>


const size_t DEFAULT_CAPACITY = 15;

class myString{
public:
    class Iterator{
        char * current;
    public:
        Iterator(char * n){current = n;}

        char& operator*()const{return *current;}
        char* operator->(){return current;}

        friend std::ostream& operator<<(std::ostream& out, Iterator it){
            out << *it.current;
            return out;
        }

        Iterator& operator++(){
            assert(current);
            if(!current){
                return *this;
            }
            ++current;
            return *this;
        }

        Iterator& operator--(){
            assert(current);
            if(!current){
                return *this; 
            }
            --current;
            return *this;
        }

        bool operator==(Iterator &other){
            return this->current == other.current;
        }

        bool operator!=(Iterator &other){
            return this->current != other.current;
        }
    };

    myString();
    myString( std::initializer_list<char> u);
    myString( const char* n);
    myString( myString& other);
    myString( myString&& other);

    size_t size();
    size_t capacity();
    void pushback(const char* u);

    Iterator begin();
    Iterator end();

    char& operator[](size_t i);

    friend std::ostream& operator<<(std::ostream &out, myString &u);

private:
   size_t m_size;
    union {
        struct {
            char *_data;
            size_t _capacity;
        } heapBuffer;

        char stackBuffer[sizeof(heapBuffer)];
    };

    bool is_sso();
};