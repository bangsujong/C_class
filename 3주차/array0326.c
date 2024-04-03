#include <stdio.h>

int main()
{
    int i = 10, j = 12, k = 13, l = 19, m =21;

    int intarray[5][10] = {{10, 12, 13, 19, 21, 33},
                            {13, 45, 56}};
    printf("intarray 크기는 %lu입니다.\n", sizeof(intarray));
    printf("정수형 변수의 크기는 %lu입니다\n", sizeof(i));
    printf("intarray  배열 변수에는 %lu개의 정수를 저장할 수 있습니다.\n", sizeof(intarray)/sizeof(int));

    printf("변수 j의 값은 %d입니다.\n", j);

    i = 11;
    j = k;
    printf("배열 intarray[1][3] 값은 %d입니다.\n", intarray[1][3]);
    intarray[1][3] =11;
    printf("배열 intarray[1][3] 값은 %d입니다.\n", intarray[1][3]);
    intarray[1][3] =k;

    m = intarray[1][5];
    //intarray[-1]  -> 영역에서 벗어나서 사용 불가능
    // intarray[]   -> 사이즈를 주지 않아도 자동으로 입력한 값만큼 사이즈 입력이됨


}
