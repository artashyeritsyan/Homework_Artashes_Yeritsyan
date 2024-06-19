#pragma once
#include <iostream>
#include <cstdlib>
#include <stdexcept>

template <typename T>
class MyAllocator {
public:

    MyAllocator() noexcept;
    MyAllocator(const MyAllocator&) noexcept;
    MyAllocator(MyAllocator&&) noexcept;

    template <typename U>
    MyAllocator(const MyAllocator<U>&) noexcept;

    T* allocate(size_t);
    T* allocate(size_t, const void*);

    void deallocate(T*, size_t) noexcept;

    size_t maxSize() const noexcept;

    void construct(T*, const T&);

    template<typename U, typename... Args>
    void construct(U*, Args&&...);

    void destroy(T*);
    template <typename U>
    void destroy(U*);

    template<typename U>
    bool operator==(const MyAllocator<U>&) const noexcept {
        return true;
    }

    template<typename U>
    bool operator!=(const MyAllocator<U>&) const noexcept {
        return false;
    }
};


