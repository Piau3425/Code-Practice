#include <stdio.h>

float w, h;

int main(){
    scanf("%f %f", &w, &h);
    printf("%.1f", w/(h*h));
}