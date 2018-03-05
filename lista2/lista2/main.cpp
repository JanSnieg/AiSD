#include <iostream>

int main ()
{
    /*
     Zadanie 1
     Ilość porównań przy szukaniu sposobem bisekcji to: log2(n)
     
     Zadanie 2
        a. n-1 porównań, (n+1) * 4 bity.
        b. n porównań, 20! * 4 bity
        c. log2(n), log2(n) * 4 bity pamięci
     
     Zadanie 3
        a. n mnożeń (a1*b1 + a2*b2 + ... an*bn)
        b. n mnożeń, n dodawań (x(x(x(x*2)-5)+4)+1)
        c. n^2 mnożeń (każdy z każdym)
        d. n^3 (istnieje algorytm n^2.376)
        e. n!
     
     Zadanie 4
     
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


