# include <stdio.h>
# include <time.h>


// 재귀 함수
long factorial_rec(int n)
{
    if(n <= 1)return 1;
    else return n*factorial_rec(n-1);
}

// 반복 함수

long long factorial_iter(int n) 
{
    long long result = 1;
    for (int i = 2; i <= n; i++) 
    {
        result *= i;
    }
    return result;
}


int main()
{
    clock_t start, stop; // clock 함수
    double duration;


    start = clock();    // 시작
    int n = 5;
    factorial_rec(n);
    printf("factorial Recursive Result: %ld\n", factorial_rec(n));

    stop = clock(); // 종료
    duration = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("Time : %f\n", duration);

    start = clock(); // 시작
    factorial_iter(n);
    printf("factorial Iterator Result: %lld\n", factorial_iter(n));

    stop = clock(); // 종료
    duration = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("Time : %f\n", duration);


}