//
//  zadanie4.h
//  lista4
//
//  Created by Jan Śnieg on 03/04/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef zadanie4_h
#define zadanie4_h

int partition (int n, double t[])
{
    int k = -1;
    int ile = n;
    double x = t[n / 2];
    while (true)
    {
        while (t[--n] > x);
        while (t[++k] < x);
        if (n > k)
        {
            double y = t[k];
            t[k] = t[n];
            t[n] = y;
        }
        else
            return k;
    }
}
int katy(
printf("Podaj liczbe elementow ciagu\n");
scanf("%d",&n);
for (i=0; i<n; i++)
{
    printf("Podaj %d element ciagu\n", i+1);
    scanf("%d",&c[i]);
}
printf("Podaj ktory element obliczyc\n");
scanf("%d",&w);

//algorytm Hoare'a
i=0;
j=n-1;
n=w;
while (i!=j)
{
    k=partition(c,i,j);
    k=k-i+1;
    if (k>=w) j=i+k-1;
        if (k<w)
        {
            w-=k;
            i+=k;
        }
}
printf("%d element ciagu to %d", n, c[i]);

#endif /* zadanie4_h */
