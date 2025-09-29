#include <stdio.h>
#include <math.h>

int temp, length[3];
int is_triangle(int a, int b, int c);

int main(){
    for(int i = 0; i < 3; i++)
        scanf("%d", &length[i]);

    for(int i = 0; i < 3-1; i++){
        for(int j = 0; j < 3-1-i; j++){
            if(length[j] > length[j+1]){
                temp = length[j];
                length[j] = length[j+1];
                length[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < 3; i++)
            printf("%d ", length[i]);
    printf("\n");

    if(!is_triangle(length[0], length[1], length[2]))
        printf("No");
    else{
        if(pow(length[0], 2) + pow(length[1], 2) < pow(length[2], 2))
            printf("Obtuse\n");
        else if(pow(length[0], 2) + pow(length[1], 2) > pow(length[2], 2))
            printf("Acute\n");
        else
            printf("Right\n");
    }
}


int is_triangle(int a, int b, int c){
        return ((a + b > c) && (b + c > a) && (a + c > b));
}
