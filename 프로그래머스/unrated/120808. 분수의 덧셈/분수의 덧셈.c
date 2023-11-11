#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int* solution(int numer1, int denom1, int numer2, int denom2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(1);
    int number = denom1 * numer2 + denom2 * numer1 ;
    int demon = denom1*denom2;
    int c = 1;
    for(int i = 1; i<=number; i++){
        if(number%i==0&&demon%i==0){
            c = i;
        }
    }
    answer[0] = number/c;
    answer[1] = demon/c;

    return answer;
}