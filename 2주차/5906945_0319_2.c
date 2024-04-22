# include <stdio.h>
# include <time.h>


// 반복문
long long power_iter(int x, int y)
{
    long long result = 1;
    for (int i = 0; i < y; i++)
    {
        result *= x;
    }
    return result;
}

// 재귀 함수
long long power_rec(int x, int y) 
{
    if (y == 0) return 1;
    return x * power_rec(x, y - 1);
}

int main() 
{
    clock_t start, stop; // clock 함수
    double duration;


    int x = 13;
    int y = 21;

    // 반복문

    start = clock();    // 시작
    long long result_iterative = power_iter(x, y);
    printf("power Iteractive result : %lld\n", result_iterative);
    stop = clock(); // 종료
    duration = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("Time : %f\n", duration);

    // 재귀 함수

    start = clock(); // 시작
    long long result_recursive = power_rec(x, y);
    printf("power Recursive result :  %lld\n", result_recursive);
    stop = clock();
    duration = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("Time : %f\n", duration);

    return 0;
}
