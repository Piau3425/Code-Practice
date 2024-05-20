#include <stdio.h>
#include <ctype.h>
#include <string.h>

char text[1001];

int main(){
    while(scanf("%s", &text) != EOF){
        int eng[26] = {0}, filter = 0;

        for(int i = 0; text[i] != '\0'; i++){
            if(ispunct(text[i]))
                text[i] = ' ';
        }

        for(int i = 0; text[i] != '\0'; i++){
            if(text[i] >= 97 && text[i] <= 122)
                text[i] = text[i]-32;
        }

        for(int i = 0; text[i] != '\0'; i++){
            if(text[i] == ' ')
                continue;
            eng[text[i]-65] += 1;
        }

        for(int i = 0; i < 26; i++){
            if(eng[i]%2 == 1){
                filter += 1;
            }
        }
        //printf("%d", filter);
        if(filter > 1)
            printf("no...\n");

        else
            printf("yes !\n");
        memset(text, '\0', 1001);
    }
}
