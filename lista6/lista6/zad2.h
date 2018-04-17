//
//  zad2.h
//  lista6
//
//  Created by Jan Śnieg on 16/04/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef zad2_h
#define zad2_h
#include <string>
#include <iostream>

const int TABLE_SIZE = 1000;

template <class T>
class haszer
{
public:
    haszer *next;
    T value;
    int key;
    haszer(int key, T value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

template <class T>
class haszMap {
    haszer<T> **htable;
    
public:
    haszMap();
    ~haszMap();
    int haszFunc(int key);
    void insert(int key, T value);
    void remove(int key);
    int search(int key);
};

#endif /* zad2_h */
