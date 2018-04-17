//
//  zad2.cpp
//  lista6
//
//  Created by Jan Śnieg on 16/04/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#include <stdio.h>
#include "zad2.h"

template <class T> haszMap<T>::haszMap()
{
    htable = new haszer<T>*[TABLE_SIZE];
    for (int i=0; i<TABLE_SIZE; i++)
        htable[i] = nullptr;
}

template <class T> haszMap<T>::~haszMap()
{
    for (int i=0; i<TABLE_SIZE; ++i)
    {
        haszer<T> entry = htable[i];
        while (entry)
        {
            haszer<T> prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete[] htable;
}

template <class T> int haszMap<T>::haszFunc(int key)
{
    return key % TABLE_SIZE;
}

template <class T> void haszMap<T>::insert(int key, T value)
{
    T hasz_value = haszFunc(key);
    haszer<T> *prev = nullptr;
    haszer<T> *entry = htable[hasz_value];
    while (entry)
    {
        prev = entry;
        entry = entry->next;
    }
    if (!entry)
    {
        entry = new haszer<T>(key, value);
        if (!prev)
            htable[hasz_value] = entry;
        else
            entry->value = value;
    }
}

template <class T> void haszMap<T>::remove(int key)
{
    T hasz_value = haszFunc(key);
    haszer<T> *entry = htable[hasz_value];
    haszer<T> *prev = nullptr;
    if (!entry || entry->key != key)
    {
        std::cout << "Nie ma elementu o takim kluczu:" << key << std::endl;
        return;
    }
    while (entry->next)
    {
        prev = entry;
        entry = entry->next;
    }
    if (prev)
        prev->next = entry->next;
    delete entry;
    std::cout << "Element usuniety" << std::endl;
}

template <class T> int haszMap<T>::search(int key)
{
    bool flag = false;
    T hasz_value = haszFunc(key);
    haszer<T> entry = htable[hasz_value];
    while (entry)
    {
        if(entry->key == key)
        {
            std::cout << entry->value << " ";
            flag = true;
        }
        entry = entry->next;
    }
    if(!flag)
        return  -1;
}
