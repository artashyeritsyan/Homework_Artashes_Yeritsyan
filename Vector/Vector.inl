#ifndef VECTOR_INL
#define VECTOR_INL

#include "Vector.hpp"

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

    _data = (T*) malloc(sizeof(T) * _capacity > 0 ? _capacity : 1);
    if(_data == NULL) {
        std::cerr << "Bad allocation" << std::endl;
        return;
    }
    
    for (size_t i = 0; i < _size; ++i) {
        _data[i] = obj._data[i];
    }
}

template <typename T>
My_Vector<T>:: ~My_Vector () {
    if (data) {
        free(_data);
        _data = NULL;
    }
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
    free(_data);
    _data = nullptr;
    _size = 0;
    _capacity = 0;
}

template <typename T>
void My_Vector<T>::swap(My_Vector& obj) {   
    My_Vector<T> tmp = obj;
    obj = *this;
    *this = tmp;
}

template <typename T>
bool My_Vector<T>:: empty() {
    return !_size;
}

template <typename T>
size_t My_Vector<T>:: size() const {
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
        for (size_t i = 0; i < _size - size; i++) {
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
        return _data[index];
}

template <typename T>
const T& My_Vector<T>::operator[] (size_t index) const {
        return _data[index];
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
    if(this != &obj) {
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

template <typename T>
bool My_Vector<T>::operator!=(const My_Vector<T>& obj) const {
    if (_size != obj._size) {
        return true;
    }
    for (size_t i = 0; i < _size; ++i) {
        if (_data[i] != obj._data[i]) {
            return true;
        }
    }
    return false;
}

template <typename T>
typename My_Vector<T>::My_Iterator My_Vector<T>::begin() {
        return My_Iterator(_data);
    }

template <typename T>
typename My_Vector<T>::My_Iterator My_Vector<T>::end() {
    return My_Iterator(_data + _size);
}

#endif // VECTOR_INL