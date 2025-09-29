#include <stdio.h>

int sum = 0, cardinal, cmtCount;

int main(){
    scanf("%d", &cmtCount);

    int rand[cmtCount];
    for(int i = 0; i < cmtCount; i++)
        scanf("%d", &rand[i]);

    cardinal = rand[cmtCount-1];
    for(int i = 1; i <= cmtCount; i++){
        if(i%cardinal == 1)
            sum += rand[i-1];
    }

    if(sum%cmtCount == 0)
        printf("%d %d", cmtCount, rand[cmtCount-1]);
    else
        printf("%d %d", sum%cmtCount, rand[sum%cmtCount-1]);
}
