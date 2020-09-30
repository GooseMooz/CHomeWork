#include <stdio.h>

int main() {
    int month_start;
    int month_days;
    int delay;
    int post_delay;
    scanf("%d", &month_start);
    scanf("%d", &month_days);
    delay = 7 - month_start;
    post_delay = month_days - month_start - 21;
    int day = 1;
    int i;
    for(i = 0; i < month_days + 1; i ++){
        if(i % 7 == 0) {
            printf("\n");
        };
        if(i < month_start + 1) {
            printf("# ");
        };
        if(i > month_start) {
            printf("%2d ", day);
            day++;
        };
    }
}