#include <stdio.h>
#include <string.h>
int repeatChecker(char*word)
{
    char letter;
    int len = strlen(word);
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            if(j != i){
                if(word[i] == word[j]) {
                    letter = word[i];
                };
            };
        };
    };
    return letter;
};

int main() {
    char word1[100];
    char word2[100];
    int cnt = 0;
    fgets(word1, 100, stdin);
    fgets(word2, 100, stdin);
    int len = strlen(word1);
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            if(word1[i] == word2[j]) {
                cnt++;
                break;
            };
        };
    };
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            if(word2[i] == word1[j]) {
                cnt++;
                break;
            };
        };
    };
    if(cnt / 2 == len) {
        printf("+");
    }
    else {
        printf("-");
    };
}