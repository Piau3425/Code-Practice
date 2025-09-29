#include <stdio.h>
#include <string.h>

int i;
char s[30001] = {0};

int main(){
    while(scanf("%s", &s) != EOF){
            printf("%s", s);
        for(i = 0; s[i] != '\0'; i++){
            if(s[i] == '!'){
                printf("YES\n");
                memset(s, 0, 30001);
                break;
            }
        }
        if(s[i] != '!'){
            printf("NO\n");
            memset(s, 0, 30001);
        }
    }
}
