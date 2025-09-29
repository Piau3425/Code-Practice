#include <stdio.h>

int y1, y2, m1, m2, d1, d2, gap;
void rotate(int *y1, int *m1, int *d1, int *y2, int *m2, int *d2);

int main(){
    while(scanf("%d %d %d %d %d %d", &y1, &m1, &d1, &y2, &m2, &d2) != EOF){
        if(y1 > y2)
            rotate(&y1, &m1, &d1, &y2, &m2, &d2);
        else if(y1 == y2 && m1 > m2)
            rotate(&y1, &m1, &d1, &y2, &m2, &d2);
        else if(y1 == y2 && m1 == m2 && d1 > d2)
            rotate(&y1, &m1, &d1, &y2, &m2, &d2);

        gap = 0;

        if(y1 == y2){
            if(m1 == m2){ // 同年同月
                printf("%d\n", d2-d1);
            }
            else{ // 同年不同月
                switch(m1){
                    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        gap += 31-d1;
                        break;
                    case 2:
                        if((y1%4 == 0 && y1%100 != 0) || y1%400 == 0)
                            gap += 29-d1;
                        else
                            gap += 28-d1;
                        break;
                    default:
                        gap += 30-d1;
                }

                m1++;

                for(int i = m1; i < m2; i++){
                    switch(i){
                        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                            gap += 31;
                            break;
                        case 2:
                            if((y1%4 == 0 && y1%100 != 0) || y1%400 == 0)
                                gap += 29;
                            else
                                gap += 28;
                            break;
                        default:
                            gap += 30;
                    }
                }

                gap += d2;
                printf("%d\n", gap);
            }
        }
        else{ // 不同年
            switch(m1){
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    gap += 31-d1;
                    break;
                case 2:
                    if((y1%4 == 0 && y1%100 != 0) || y1%400 == 0)
                        gap += 29-d1;
                    else
                        gap += 28-d1;
                    break;
                default:
                    gap += 30-d1;
            }

            m1++;

            for(int i = m1; i <= 12; i++){
                switch(i){
                    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        gap += 31;
                        break;
                    case 2:
                        if((y1%4 == 0 && y1%100 != 0) || y1%400 == 0)
                            gap += 29;
                        else
                            gap += 28;
                        break;
                    default:
                        gap += 30;
                }
            }

            y1++;

            for(int i = y1; i < y2; i++){
                if((i%4 == 0 && i%100 != 0) || i%400 == 0)
                    gap += 366;
                else
                    gap += 365;
            }

            if(m2 != 1){
                for(int i = 1; i < m2; i++){
                    switch(i){
                        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                            gap += 31;
                            break;
                        case 2:
                            if((y2%4 == 0 && y2%100 != 0) || y2%400 == 0)
                                gap += 29;
                            else
                                gap += 28;
                            break;
                        default:
                            gap += 30;
                    }
                }
            }
            gap += d2;
            printf("%d\n", gap);
        }
    }
}


void rotate(int *y1, int *m1, int *d1, int *y2, int *m2, int *d2){
    int temp;

    temp = *y1;
    *y1 = *y2;
    *y2 = temp;

    temp = *m1;
    *m1 = *m2;
    *m2 = temp;

    temp = *d1;
    *d1 = *d2;
    *d2 = temp;
}
