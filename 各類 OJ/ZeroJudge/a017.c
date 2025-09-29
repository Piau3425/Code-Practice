#include <stdio.h>
#include <string.h>

int sum, num, add = 0, minus = 0;
char oper;

int main(){
    while(scanf("%d", &sum) != EOF){
        while(scanf("%c", &oper) != EOF){
            if(oper == '+'){
                scanf("%d", &num);
                add += num;
            }
            if(oper == '-'){
                scanf("%d", &num);
                minus += num;
            }
            if(oper == '*'){
                scanf("%d", &num);
                sum *= num;
            }
            if(oper == '/'){
                scanf("%d", &num);
                sum /= num;
            }

            if(oper == '('){
                scanf("%d", &sum);
                while(scanf("%c", &oper) != ')'){
                    if(oper == '+'){
                        scanf("%d", &num);
                        sum += num;
                    }
                    if(oper == '-'){
                        scanf("%d", &num);
                        sum -= num;
                    }
                    if(oper == '*'){
                        scanf("%d", &num);
                        sum *= num;
                    }
                    if(oper == '/'){
                        scanf("%d", &num);
                        sum /= num;
                    }
                }
            }
        }
        printf("%d\n", sum+add-minus);
    }
}
