#include <stdio.h>

int loop;
int check_A(), check_B(), check_C();

int main(){

    scanf("%d", &loop);

    for(int j = 0; j < loop; j++){
        int A[7] = {0}, B[7] = {0};
        for(int i = 0; i < 7; i++)
            scanf("%d", &A[i]);
        for(int i = 0; i < 7; i++)
            scanf("%d", &B[i]);

        if(!check_A(A, B))
            printf("A");
        if(!check_B(A, B))
            printf("B");
        if(!check_C(A, B))
            printf("C");
        if(check_A(A, B) && check_B(A, B) && check_C(A, B))
            printf("None");

        printf("\n");
    }

}


int check_A(int *A, int *B){
    return (A[1] != A[3] && B[1] != B[3] && A[1] == A[5] && B[1] == B[5]);
}
int check_B(int *A, int *B){
    return (A[6] == 1 && B[6] == 0);
}
int check_C(int *A, int *B){
    return (A[1]!=B[1] && A[3]!=B[3] && A[5]!=B[5]);
}
