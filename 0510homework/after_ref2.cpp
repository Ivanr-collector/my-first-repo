#include <iostream>
#include <cstdlib>


void process(int number, float arr[], int n);


int main()
{
    const int mas_len = 10;
    float a[mas_len], b[mas_len], c[mas_len];

    for (int i = 1; i < 4; i ++)
    {
        process(i, a, mas_len);
        
    }
    
    return 0;
}


void process(int number, float arr[], int n) 
{
    double sum = 0;
    std::cout << number << " Последовательность" << std::endl;

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10;
        std::cout << arr[i] << ' ';
        sum = sum + arr[i];
    }

    std::cout << std::endl << std::endl;
    
    std::cout << "Среднее равно: " << sum / n << std::endl << std::endl;

}