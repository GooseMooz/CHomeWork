#include <stdio.h>
#include <math.h>
#define N 100

int fact(int n)
{
    if (n == 0 || n==1)
        return 1;
    else
    {
        return n * fact(n - 1);
    }
}

int pointer = 0;
float stack[N];

float pop(void)
{
    if (pointer > 0)
    {
        return stack[--pointer];
    }
}

void push(int number)
{
    stack[pointer++] = number;
}

int empty(void)
{
    return (pointer == 0);
}

int main()
{
restart:
    int ops = 0;
    int nums = 0;
    int eq = 0;
    int err = 0;
    int min = 1;
    while (!feof(stdin))
    {
        int c = getchar();
        float x;
        switch (c)
        {
        case '\n':
        case '_':
            min = -1;
            break;
        case ' ':
            break;
        case '=':
            eq++;
            if(eq != 1){
                printf("MORE THAN ONE '=' ERROR\n");
                err = 1;
            }
            if(ops+1 != nums){
                printf("TOO MUCH OPERATIONS ERROR\n");
                err = 1;
            }
            if(err == 1){
                return -1;
            }
            else{
                printf("Result = %.3f\n", pop());
                goto restart;
            }
            break;
        case '+':
            ops++;
            push(pop()*min + pop());
            break;
        case '-':
            ops++;
            push(-pop()*min + pop());
            break;
        case '*':
            ops++;
            push(pop()*min * pop());
            break;
        case '/':
            ops++;
            if(stack[pointer-1] == 0){
                printf("DIVISION BY ZERO ERROR!");
                return -1;
            }
            push(pop()*min / pop());
            break;
        case '^':
            ops++;
            push(pow(pop()*min, pop()));
            break;
        case '!':
            push(fact(pop()*min));
            break;
        default:
            ungetc(c, stdin);
            if (scanf("%f", &x) != 1)
            {
                fprintf(stderr, "Can't read integer\n");
                return -1;
            }
            else
            {
                push(x);
                nums++;
            }
            break;
        }
    }
    return 0;
}
