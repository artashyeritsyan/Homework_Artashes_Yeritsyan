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

private:

    T* _data;
    size_t _size;
    size_t _capacity;

};

template <typename T>
My_Vector<T>::My_Vector (size_t size) {
    this->_size = size;
    this->_capacity = size;

    _data = (T*) malloc(sizeof(T) * _capacity > 0 ? _capacity : 1);
    if(_data == NULL) {
        std::cerr << "Bad allocation" << std::endl;
        return;
    }
}

template <typename T>
My_Vector<T>::My_Vector(const My_Vector<T>& obj) {
    _size = obj._size;
    _capacity = obj._capacity;
    _data = new T[_capacity];
    
    for (size_t i = 0; i < _size; ++i) {
        _data[i] = obj._data[i];
    }
}

template <typename T>
My_Vector<T>:: ~My_Vector () {
    free(_data);
    _data = NULL;
}

template <typename T>
void My_Vector<T>::push_back(T value) {
    if (_size >= _capacity) {
        _capacity = _capacity == 0 ? 1 : _capacity * 2;

        T* tmp_data = (T*)realloc(_data, sizeof(T) * _capacity);

        if (tmp_data == NULL) {
            tmp_data = (T*) malloc(sizeof(T) * _capacity);
            if(tmp_data == NULL) {
                std::cerr << "Bad allocation" << std::endl;
                return;
            }

            for (size_t i = 0; i < _size; ++i) {
                tmp_data[i] = _data[i];
            }

            free(_data);
        }

        _data = tmp_data;
        tmp_data = NULL;
    }

    _data[_size] = value;
    ++_size;
}

template <typename T>
void My_Vector<T>::pop_back() {
    if (_size > 0) {
        --_size;
    }
}

template <typename T>
void My_Vector<T>::insert(size_t position, T value) {

    if (_size >= _capacity) {
        _capacity = _capacity == 0 ? 1 : _capacity * 2;

        T* tmp_data = (T*)realloc(_data, sizeof(T) * _capacity);

        if (tmp_data == NULL) {
            tmp_data = (T*) malloc(sizeof(T) * _capacity);
            if(tmp_data == NULL) {
                std::cerr << "Bad allocation" << std::endl;
                return;
            }

            for (size_t i = 0; i < position; ++i) {
                tmp_data[i] = _data[i];
            }
            tmp_data[position] = value;
            for (size_t i = position + 1; i < _size + 1; ++i) {
                tmp_data[i] = _data[i - 1];
            }

            free(_data);
            _data = tmp_data;
            tmp_data = NULL;
            ++_size;
            
            return;
        }

        _data = tmp_data;
        tmp_data = NULL;
    }
    
    for (size_t i = _size - 1; i >= position; --i) {
        _data[i + 1] = _data[i];
    }
    _data[position] = value;

    ++_size;
}

// Removes element from chosen position
template <typename T>
void My_Vector<T>::erase(size_t position) {
    if (position < _size) {    
        for (size_t i = position; i < _size - 1; ++i) {
            _data[i] = _data[i+1];
        }

        --_size;
    }
}

template <typename T>
void My_Vector<T>::clear() {
    _size = 0;
}

template <typename T>
void My_Vector<T>::swap(size_t first_position, size_t second_position) {   

    T tmp_value = _data[first_position];
    _data[first_position] = _data[second_position];
    _data[second_position] = tmp_value;
}




template <typename T>
bool My_Vector<T>:: empty() {
    return !_size;
    // return _size > 0 ? false : true;
}

template <typename T>
size_t My_Vector<T>:: size() {
    return _size;
}

template <typename T>
size_t My_Vector<T>:: capacity() {
    return _capacity;
}

template <typename T>
void My_Vector<T>:: reserve(size_t new_capacity) {
    if (new_capacity > _capacity) {
        _capacity = new_capacity;

        T* tmp_data = (T*)realloc(_data, sizeof(T) * _capacity);

        if (tmp_data == NULL) {
            tmp_data = (T*) malloc(sizeof(T) * _capacity);
            if(tmp_data == NULL) {
                std::cerr << "Bad allocation" << std::endl;
                return;
            }

            for (size_t i = 0; i < _size; ++i) {
                tmp_data[i] = _data[i];
            }

            free(_data);
        }

        _data = tmp_data;
        tmp_data = NULL;
    }
}

template <typename T>
void My_Vector<T>::resize(size_t size, T value) {
    if(size < _size) {
        _size = size;
    }
    else {
        for (size_t i = 0; i < _size - size; i++)
        {
            push_back(value);
        }
    }
}

template <typename T>
void My_Vector<T>::shrink_to_fit() {
    if(_size != _capacity) {
        _capacity = _size;
        T* tmp_data = (T*)realloc(_data, sizeof(T) * _size);

        if (tmp_data == NULL) {
            tmp_data = (T*) malloc(sizeof(T) * _size);
            if(tmp_data == NULL) {
                std::cerr << "Bad allocation" << std::endl;
                return;
            }

            for (size_t i = 0; i < _size; ++i) {
                tmp_data[i] = _data[i];
            }

            free(_data);
        }

        _data = tmp_data;
        tmp_data = NULL;
    }
}




template <typename T>
T& My_Vector<T>::operator[] (size_t index) {
    if(index < _size) {
        return _data[index];
    }
    else {
        throw("Index is out of range");
    }
}

template <typename T>
T& My_Vector<T>::at(size_t position) {
    if(position < _size) {
        return _data[position];
    }
    else {
        throw("Index is out of range");
    }
}

template <typename T>
T& My_Vector<T>::front() {
    return _data[0];
}

template <typename T>
T& My_Vector<T>::back() {
    return _data[_size - 1];
}

template <typename T>
T* My_Vector<T>::data() {
    return _data;
}

template <typename T>
My_Vector<T>& My_Vector<T>::operator= (My_Vector<T>& obj) {
    if(this != obj) {
        free(_data);
        _size = obj._size;
        _capacity = obj._capacity;
        _data = (T*) malloc(sizeof(T) * _capacity);
            if(_data == NULL) {
                throw("Bad allocation");
            }
        
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = obj._data[i];
        }
    }

    return *this;
}
// template <typename T>
// T My_Vector<T>::operator= (size_t index) {
//     if(index < _size) {
//         return data[index];
//     }
//     else {
//         throw("Index is out of range");
//     }
// }

#include "Vector.inl"

#endif // VECTOR_HPP
