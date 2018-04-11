//
//  zadanie1.h
//  lista4
//
//  Created by Jan Śnieg on 03/04/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef zadanie1_h
#define zadanie1_h

int* counting_sort(int t[], int n, int c)
{
    int count_arr[10] = {0};
    int divider = pow(10,c);
    //counting elements
    for (int i=0; i<n; i++)
        count_arr[(t[i]/divider)%10]++;
    
    //changing count so it will contain actual position of element in output arr
    for (int j=1; j<=10; ++j)
        count_arr[j] += count_arr[j-1];
    
    int output_arr[n];
    for (int k=n-1; k>=0; k--)
    {
        int curr = (t[k]/divider)%10;
        output_arr[count_arr[curr]-1] = t[k];
        count_arr[curr]--;
    }
    
    for (int i = 0; i<n; i++)
        t[i] = output_arr[i];
    
    return t;
}

void zadanie1()
{
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{0,1000};
    int arr_size = 20;
    int t[arr_size];
    std::cout << "BEFORE:\n";
    for (int i=0; i<arr_size; i++)
    {
        t[i] = generate(gen);
        std::cout << t[i] << ", ";
    }
    int *sorted_arr = counting_sort(t, arr_size, 2);
    sorted_arr = counting_sort(sorted_arr, arr_size, 1);
    sorted_arr = counting_sort(sorted_arr, arr_size, 0);
    for (int i=0; i<arr_size; i++)
    {
        std::cout << sorted_arr[i];
    }
}
#endif /* zadanie1_h */
