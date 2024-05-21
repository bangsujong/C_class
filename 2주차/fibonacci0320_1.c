# include <stdio.h>




int fibonacci_rec(int n)
{
    printf("f(%d)   ",n);
    if (n ==0) return 0;
    else if (n ==1) return 1;
    else return (fibonacci_rec(n-1) + fibonacci_rec(n-2));

}

int main()
{
    int fibonnacci = 0;
    fibonnacci = fibonacci_rec(6);
    printf("Fibonacci 6 = %d\n", fibonnacci);
}