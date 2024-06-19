#include "allocator.hpp"

template <typename T>
MyAllocator<T>::MyAllocator() noexcept = default;

template<typename T>
MyAllocator<T>::MyAllocator(const MyAllocator&) noexcept {}

template<typename T>
MyAllocator<T>::MyAllocator(MyAllocator&&) noexcept {}

template <typename T>
template <typename U>
MyAllocator<T>::MyAllocator(const MyAllocator<U>&) noexcept {}


template<typename T>
T* MyAllocator<T>::allocate(size_t n)
{
  return static_cast<T*>(::operator new(n * sizeof(T)));
}

template<typename T>
T* MyAllocator<T>::allocate(size_t n, const void* hint)
{
  (void)hint;
  return Allocate(n);
}

template<typename T>
void MyAllocator<T>::deallocate(T* ptr, size_t n) noexcept
{
  ::operator delete(ptr, n * sizeof(T));
}

template<typename T>
size_t MyAllocator<T>::maxSize() const noexcept
{
  return static_cast<size_t>(-1) / sizeof(value_type);
}

template<typename T>
void MyAllocator<T>::construct(T* ptr, const T& value)
{
  new (ptr) T(value);
}


template<typename T>
template<typename U, typename ...Args>
void MyAllocator<T>::construct(U* ptr, Args &&... args)
{
  new (ptr) U(std::forward<Args>(args)...);
}

template<typename T>
template<typename U>
void MyAllocator<T>::destroy(U* ptr)
{
  if (std::is_same_v<U, T>) {
    ptr->T();
  }
}


template<typename T>
void MyAllocator<T>::destroy(T* ptr)
{
  ptr -> ~T();
}