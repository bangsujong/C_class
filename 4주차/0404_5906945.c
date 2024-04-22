                                                                            // swap.c포인터를 함수의 매개변수로 사용하는 프로그램

#include <stdio.h>

// int main()
// {
//     int i = 10;
//     int j;
//     int *iptr;
//     //j=i;
//     iptr = &i;          // &i = i의 주소
//     j = *iptr;
//     printf("variable i = %d, variable j = %d\n", i, j);

// }
void swap(int *first, int *second)
{
    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
    printf("first = %d, second = %d\n", *first, *second);
}

// int main()
// {
//     int i = 10;
//     int j = 20;
//     int k = 30;
//     int l = 40;
//     int temp;

//     // temp = i;
//     // i = j;
//     // j = temp;
//     swap(&i,&j);

//     // temp = k;
//     // k = l;
//     // l = temp;
//     swap(&k, &l);
//     // printf("variable k = %d, variable l = %d\n", k, l);
// }

int sumofArray(int *sptr, int *eptr);


int main()
{
    int i = 10;
    int j = 20;
    int sum = 0;
    int *iptr;
    int iArray[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};



    swap(&i, &j);

    for (int k=0; k<20; k++)
    {
        sum = sum + iArray[k];
    }

    for (iptr = &iArray[0]; iptr < &iArray[20]; iptr++)
    {
        sum = sum + *iptr;
    }



    printf("sum of iArray = %d\n", sum);
    printf("variable i = %d, variable j = %d\n", i, j);
    printf("sum of iArray = %d\n", sumofArray(iArray, &iArray[19]));
}

int sumofArray(int *sptr, int *eptr)
{
    int sum = 0;

    while (sptr<=eptr)
    {
        sum = sum + *sptr;
        sptr++;
    }
    return sum;
}

