#include <stdio.h>

char idEng[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int id, check, sum = 0, temp, num[] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};

int main(){
    scanf("%d", &id);

    check = id%10;
    id /= 10;

    // �p�⨭���Ҹ��X�e�E��Ʀr���[�v�M
    for(int i = 1; i <= 8; i++){
        sum += id%10*i;
        id /= 10;
    }

    // �Τ@�Ӿ�ư}�C�x�s�C�ӭ^��r���ҹ������Ʀr
    // �Ҧp A->10�BB->11�BC->12�A�H������
    // �γo�Ӱ}�C�M�����Ҹ��X�p��X���[�v�M�B�̫�@��Ʀr
    // �ӧP�_�����Ҹ��X�O�_���T
    for(int i = 0; i < 26; i++){
        temp = num[i]%10*9 + num[i]/10;

        if(check == 10-(sum+temp)%10)
            printf("%c", idEng[i]);
        else if((sum+temp)%10 == 0 && check == (sum+temp)%10)
            printf("%c", idEng[i]);
    }
}
