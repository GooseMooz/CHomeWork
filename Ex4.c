#include <stdio.h>
#include <string.h>
int repeatChecker(char*word)
{
    char letters[2];
    int len = strlen(word);
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            if(j != i){
                if(word[i] == word[j]) {
                    letters[0] = word[i];
                    letters[1] = word[j];
                };
            };
        };
    };
    return letters;
};

int repeatFix(char*firstWord, char*secondWord) {
    int ok = 0;
    int len = strlen(firstWord);
    char letters[2];
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            if(j != i){
                if(firstWord[i] == firstWord[j]) {
                    // Повторение есть
                }
            }
        };
    };
    return ok;
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