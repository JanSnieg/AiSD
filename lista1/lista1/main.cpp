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

std::vector<int> convertToBinary(unsigned int n)
{
    std::vector<int> binarna;
    if (n / 2 != 0) {
        convertToBinary(n / 2);
    }
    binarna.push_back(n%2);
//    std::cout << n%2 << ",";
    return binarna;
}

int zad1Rekurencyjnie(int x, int n)
{
    if (n==0)
        return 1;
    else if (n%2 != 0)
        return x * (pow(zad1Rekurencyjnie(x, (n-1)/2), 2));
    else
        return pow(zad1Rekurencyjnie(x, n/2),2);
}

int zad1Binarnie(int x, int n)
{
    int result = 1;
    while (n>0)
    {
        if (n%2 == 0)
        {
            n /= 2;
            x = x*x;
        }
        else
        {
            n -= 1;
            result *= x;
            n /= 2;
            x *= x;
        }
    }
    return result;
}

double func(double x)
{
    return x*x*x - x*x + 2;
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
    } while (b-a >= 0.01);
    return c;
}
double zad3(double a[], int n, double x)
{
    double result = 0;
    int count =0;
    for (int i=n; i>0; i--)
    {
        result += a[i]*x;
        count++;
    }
    result += a[0];
//    std::cout << "\nWynik:\t" << result << std::endl;
    return count;
}

long zad4(int k, int n, double p)
{
//        Dla i=0 P=1
    long result = 1;
    int tempresult = 1;
    for (int i=1; i<=k; i++)
    {
        tempresult *= n/i;
        result += tempresult * pow(p, i) ; //* pow(q,n-1)
        n--;
    }
    return result;
}

struct lnode
{
    int key;
    lnode *next;
};

int zad5(int n, lnode *l)
{
    int key = 0;
    return key;
}

int main(int argc, const char * argv[]) {
    std::cout << "Zad1:\t" << zad1Rekurencyjnie(2, 10) << std::endl;
    std::cout << "Zad1:\t" << zad1Binarnie(2, 10) << std::endl;
    std::cout << "Zad2:\t" << zad2(400, -25) << std::endl;
    double a[] = {1.,5.,7.,8.,1.,1.,4.,5.,7.,7.,7.,8.,10.,20.};
    int a_length = sizeof(a)/sizeof(a[0]);
    std::cout << "Zad3: \nLiczba mnożeń:\t" << zad3(a, a_length, 3) << "\nDlugość wielomianu:\t" << a_length << std::endl;
    std::cout << "Zad4:\t" << zad4(3, 20, 2) << std::endl;
    return 0;
}
