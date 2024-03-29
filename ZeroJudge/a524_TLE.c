#include <stdio.h>
#include <math.h>
#include <time.h>

int digit;

int main(){
    while(scanf("%d", &digit) != EOF){

        int temp, max = 0, digit_maxSum = 0, min = 0;
        float start = clock(), end;
        for(int i = 1; i <= digit; i++){
            min += i*pow(10, digit-i);
            max += i*pow(10, i-1);
        }

        for(int i = 1; i <= digit; i++){
            digit_maxSum += i;
        }

        for(int i = max; i >= min; i--){
            int temp = i, digit_sum = 0, record[10] = {0}, recSum = 0;
            while(temp > 0){
                digit_sum += temp%10;
                record[temp%10] = 1;
                temp /= 10;
            }

            if(digit_sum == digit_maxSum){
                for(int j = 1; j <= digit; j++){
                    recSum += record[j];
                }
                if(recSum == digit)
                    printf("%d\n", i);
            }

        }

        end = clock();
        printf("程式尋找密碼耗費 %g 秒", (end-start)/CLOCKS_PER_SEC);
    }
}
