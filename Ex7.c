#include <stdio.h>
#include <string.h>
#define MAX 100

int main() {
    char exp[MAX];
    scanf("%s", &exp);
    printf("%s \n", exp);
    int stack[MAX] = {};
    int len = strlen(exp);
    int cnt = 0;
    int numb_cnt = 0;
    int more_cnt = -1;

    for(int i = 0; i < len; i++) {
        if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/' && exp[i] != '_') {
            if (exp[i - 1] == '_') {
                more_cnt++;
                stack[more_cnt] = exp[i] - '0';
                cnt = 0;
                numb_cnt++;
                printf("Number \n");
            } else {
                cnt++;
                int a = 10 * cnt;
                stack[more_cnt] = (stack[more_cnt] ) * a + (exp[i] - '0');
                printf("Neighboring number \n");
            }
        } else if (exp[i] == '_') {
            cnt = 0;
            printf("Space \n");
        } else if (exp[i] == '+') {
            printf("%d, %d \n", stack[numb_cnt - 2], stack[numb_cnt - 1]);
            if (numb_cnt >= 2) {
                stack[numb_cnt - 2] = (stack[numb_cnt - 2] ) + (stack[numb_cnt - 1] );
                numb_cnt = numb_cnt - 1;
                printf("Plus \n");
            }
        } else if (exp[i] == '-') {
            if (numb_cnt >= 2) {
                stack[numb_cnt - 2] = (stack[numb_cnt - 2] ) - (stack[numb_cnt - 1] );
                numb_cnt = numb_cnt - 1;
            }
        } else if (exp[i] == '*') {
            if (numb_cnt >= 2) {
                stack[numb_cnt - 2] = (stack[numb_cnt - 2] ) * (stack[numb_cnt - 1] );
                numb_cnt = numb_cnt - 1;
                printf("Pow \n");
            }
        }
        else if(exp[i] == '/') {
            if(numb_cnt >= 2) {
                stack[numb_cnt - 2] = (stack[numb_cnt - 2] ) / (stack[numb_cnt - 1] );
                numb_cnt = numb_cnt - 1;
            }
        }
    }

    printf("%d", stack[0]);
}