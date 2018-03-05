//
//  main.cpp
//  lista1
//
//  Created by Jan Śnieg on 25/02/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//
#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <time.h>

int zad1Rekurencyjnie(int x, int n)
{
    if (n==0)
        return 1;
    else if (n%2 != 0)
        return x * (pow(zad1Rekurencyjnie(x, (n-1)/2), 2));
    else
        return pow(zad1Rekurencyjnie(x, n/2),2);
}

int zad1Iteracyjnie(int x, int n)
{
    int result = 1;
    while (n>0)
    {
        if (n%2 != 0)
            result *= x;
        n /= 2;
        x *= x;
    }
    return result;
}

double func(double x)
{
    return sin(x);
}

double zad2(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        std::cout << "Wrong functions" << std::endl;
    }
    double c = a;
    do
    {
        c = (b+a)/2; //middle point
        if (func(c) == 0)
            return c;
        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    } while (b-a >= 0.000000000001);
    return c;
}
double zad3(double a[], int n, double x)
{
    double result = a[n];
    int count =0;
    while (n)
    {
        result *= x + a[--n];
        count++;
    }
    return count;
}

double zad4(int k, int n, double p)
{
//        Dla i=0 P=1
    double q = 1-p;
    double p_q = p/q;
    double result = 0;
    int tempresult = pow(q, n);;
    for (int i=1; i<=k; i++)
    {
        result += tempresult;
        tempresult *= (p_q) * (n-i)/(i+1);
    }
    return result;
}

struct lnode
{
    int key;
    lnode *next;
    
    //constructor
    lnode(int value, lnode *l = nullptr)
    {
        key = value;
        next = l;
    }
};

int zad5(int n, lnode *l)
{
    int _n = 1;
    while (l != nullptr)
    {
        if (_n == n)
            return l->key;
        else
        {
            _n++;
            l = l->next;
        }
    }
    return 0;
}

void zad6(int N)
{
    int Z[N+1], minZ, maxZ;
    int count = 0;
    
    srand((unsigned)time(NULL));
    for(int i = 0; i < N; i++)
        Z[i] = rand() % 10000;
    if(N % 2)
    {
        count ++;
        Z[N] = Z[N-1];
    }
    minZ = 10000;
    maxZ = -1;
    for(int i = 0; i < N; i += 2)
        if(Z[i] > Z[i+1])
        {
            count ++;
            if(Z[i]   > maxZ)
            {
                count ++;
                maxZ = Z[i];
            }
            if(Z[i+1] < minZ)
            {
                count ++;
                minZ = Z[i+1];
            }
        }
        else
        {
            if(Z[i]   < minZ)
            {
                count ++;
                minZ = Z[i];
            }
            if(Z[i+1] > maxZ)
            {
                count ++;
                maxZ = Z[i+1];
            }
        }
    for(int i = 0; i < N; i++)
        std::cout << std::setw(4) << Z[i] << std::endl;
    std::cout << std::endl <<  minZ << " : " << maxZ << std::endl;
    std::cout << "Liczba porównań:\t" << count <<std::endl;
}

int main(int argc, const char * argv[]) {
//    std::cout << "Zad1:\t" << zad1Rekurencyjnie(2, 16) << std::endl;
//    std::cout << "Zad1:\t" << zad1Iteracyjnie(2, 16) << std::endl;
//    std::cout << "Zad2:\t" << zad2(-0.7, 0.5) << std::endl;
    double a[] = {1.,5.,7.,8.,1.,1.,4.,5.,7.,7.,7.,8.,10.,20.};
    int a_length = sizeof(a)/sizeof(a[0]);
//    std::cout << "Zad3: \nLiczba mnożeń:\t" << zad3(a, a_length, 3) << "\nDlugość wielomianu:\t" << a_length << std::endl;
//    std::cout << "Zad4:\t" << zad4(3, 20, 2) << std::endl;
    
    lnode third(3);
    lnode second(2, &third);
    lnode first(1, &second);
    
//    std::cout << "Zad5:\t" << zad5(1, &first) << "\t" << zad5(2, &first)
//    << "\t" << zad5(3, &first) << "\t" << zad5(4, &first) << std::endl;
    zad6(15);

    return 0;
}
