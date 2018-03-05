#include <iostream>

int main ()
{
    /*
     Zadanie 1
     Ilość porównań przy szukaniu sposobem bisekcji to: sqrt(n)
     
     Zadanie 2
        a. n-1 porównań, tyle pamieci co tablica.
        b. n porównań, n * 20 bitów
        c. 2*sqrt(n), 2*sqrt(n) pamięci
     
     Zadanie 3
        a. n mnożeń (a1*b1 + a2*b2 + ... an*bn)
        b. n mnożeń, n dodawań (x(x(x(x*2)-5)+4)+1)
        c. n*n mnożeń (każdy z każdym)
        d. n^3 (istnieje algorytm n^2.376)
        e. n!
     
     Zadanie 4
     a. int temp1 = t[0];
        for (int i=0; i < n; i++)
            t[i] = t[n-(i+k)];
        t[n] = temp1;
        b.
     */
    const int n = 10;
    int k = 3;
    int t[n] = {};
    std::cout << "Normal array:\n";
    for (int i=0; i<n; i++)
    {
        t[i] = i;
        std::cout << t[i] << ",";
    }
    int temp1 = t[k];
    std::cout << "\nChanged array:\n";
    int i = k;
    do
    {
        if (i == n-k)
            i = 1;
        t[i] = t[(n - k) + i];
        std::cout << t[i] << ",";
        i++;
    } while(i <= n-k-1);
    t[n-1] = temp1;
    std::cout<<std::endl;
    
    return 0;
}


