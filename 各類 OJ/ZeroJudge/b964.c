#include <stdio.h>
#include <stdlib.h>

int student, temp, good, bad;

int main(){
    scanf("%d", &student);
    int *grade = malloc(student*sizeof(int));

    for(int i = 0; i < student; i++){
        scanf("%d", &grade[i]);
    }

    for(int i = 0; i < student-1; i++){
        for(int j = 0; j < student-i-1; j++){
            if(grade[j] > grade[j+1]){
                temp = grade[j];
                grade[j] = grade[j+1];
                grade[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < student; i++)
        printf("%d ", grade[i]);
    printf("\n");

    if(grade[0] >= 60)
        printf("best case\n");
    else{
        for(bad = student-1; grade[bad] >= 60; bad--){}
        printf("%d\n", grade[bad]);
    }

    if(grade[student-1] < 60)
        printf("worst case\n");
    else{
        for(good = 0; grade[good] < 60; good++){}
        printf("%d\n", grade[good]);
    }
}
