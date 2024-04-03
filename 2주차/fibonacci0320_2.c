# include <stdio.h>


int fibonacci_itr(int n);


int main()
{
    int fibonnaci = 0;

    fibonnaci = fibonacci_itr(6);
    printf(" Fibonacci 6 = %d\n", fibonnaci);
    
}

int fibonacci_itr(int n)
{
    int result =0;
    int n_2 = 0, n_1 = 1;

    if ( n <= 1 ) return n;

    for (int i = 2; i <= n; i++)
    {
        result = n_1 + n_2;
        n_2 = n_1;
        n_1 = result;
    }
    return result;
}