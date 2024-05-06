#include "Vector.hpp"

void print(My_Vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) 
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main () {

    My_Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    
    print(v);
    std::cout << "size = " << v.size() << "   capacity = " << v.capacity() << std::endl;

    v.pop_back();
    print(v);


    v.insert(2, 7);
    print(v);

    std::cout << v.empty() << std::endl;

    v.erase(1);
    print(v);


    v.swap(0, 3);
    print(v);

    v.resize(3);
    print(v);

    v.resize(15, 100);
    print(v);

    std::cout << "size = " << v.size() << "   capacity = " << v.capacity() << std::endl;


    v.shrink_to_fit();
    v[6] = 14;
    print(v);
    std::cout << "size = " << v.size() << "   capacity = " << v.capacity() << std::endl;

    v.front() = 111;
    v.back() = 999;
    v.at(10) = 555;
    print(v);


    int* p = v.data();

    *p = 222;
    ++p;
    *p = 224;
    p[2] = 444;

    print(v);


    return 0;
}