#ifndef MAIN_HPP
#define MAIN_HPP

#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class Array {
public:
    T* a;
    int length;
    Array(int len) : length(len){
        a = new T[length];
    }
    Array(const Array<T>& other) : length(other.length) {
        a = new T[length];
        for (int i = 0; i < length; ++i)
            a[i] = other.a[i];
    }

    ~Array(){
        if (a){
            delete[] a;
            a = nullptr;
        }
    }
    T& operator[](int i){
        assert(i >= 0 && i < length);
        return a[i];
    }

    const T& operator[](int i) const {
        assert(i >= 0 && i < length);
        return a[i];
    }
    Array<T>& operator=(const Array<T>& b) {
        if (this == &b)
            return *this;
        if (a != nullptr){
            delete[] a;
            a = nullptr;
        }
        length = b.length;
        a = new T[length];
        for (int i = 0; i < length; ++i)
            a[i] = b.a[i];
        return *this;
    }
};

template <typename T>
class ArrayList{
    Array<T> arr;
    int n;
    int capacity;

    void resize(){
        int newCap = std::max(2 * capacity, 1);
        Array<T> newArr(newCap);
        for (int i = 0; i < n; i++){
            newArr[i] = arr[i];
        }
        arr = newArr;
        capacity = newCap;
    }

public:
    ArrayList() : arr(1), n(0), capacity(1){}

    int size() const { return n; }

    T get(int i) const{
        assert(i >= 0 && i < n);
        return arr[i];
    }

    void set(int i, T x){
        assert(i >= 0 && i < n);
        arr[i] = x;
    }
    
    void add(int i, T x){
        assert(i >= 0 && i <= n);
        if (n == capacity)
            resize();
        for (int j = n; j > i; j--){
            arr[j] = arr[j - 1];
        }
        arr[i] = x;
        n++;
    }

    void remove(int i){
        assert(i >= 0 && i < n);
        for (int j = i; j < n - 1; j++){
            arr[j] = arr[j + 1];
        }
        n--;
        if (capacity >= 3 * n){
            int newCap = std::max(2 * n, 1);
            Array<T> newArr(newCap);
            for (int k = 0; k < n; k++){
                newArr[k] = arr[k];
            }
            arr = newArr;
            capacity = newCap;
        }
    }
    
    void print() const{
        for (int i = 0; i < n; i++){
            cout << arr[i];
            if (i < n - 1)
                cout << ", ";
        }
        cout << endl;
    }
};

#endif // MAIN_HPP