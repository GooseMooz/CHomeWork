#include <stdio.h>
#include <string.h>

int main() {
    char all[100];
    fgets(all, 100, stdin);
    puts(all);
    int i;
    int len = strlen(all);
    int lCount = 0;
    int wCount = 0;
    for (i = 0; i < len; i++) {
        if(all[i] != ' ' && all[i] != '\n') {
            lCount++;
            printf("'%c'\n", all[i]);
        }
        else if(all[i] == ' ' || all[i] == '\n') {
            wCount++;
            printf("big plusi \n");
        };
    };
    float ans = ((float)lCount / wCount);
    printf("%f", ans);
};