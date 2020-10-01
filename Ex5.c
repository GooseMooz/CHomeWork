#include <stdio.h>
#include <string.h>

int findereplacer(char *smth, int symb, int a) {
    int wordik;
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for(int i = 0; i< 26; i++) {
        if(alphabet[i] == smth[symb]) {
            wordik = alphabet[i + a];
        }
    }
    return wordik;
};

int main() {
    char word[100];
    char caesars[100];
    int shift;
    char choice;
    printf("[Y] if Word to Caesars and [N] if Caesars to word \n=== \n");
    scanf("%s", &choice);
    printf("===Shift: \n");
    scanf("%d", &shift);
    printf("===");
    int normalShift = shift % 26;

    if(choice == 'Y') {
        printf("\nType your word: \n");
        scanf("%s", &word);
        printf("==Caesars==\n");
        int len = strlen(word);
        for(int i = 0; i < len; i++) {
            caesars[i] = findereplacer(word, i, normalShift);
            printf("%c", caesars[i]);
        }

    }
    if(choice == 'N') {
        printf("Type your caesars: \n");
        scanf("%s", &caesars);
        printf("==Word==\n");
        int len = strlen(caesars);
        for(int i = 0; i < len; i++) {
            word[i] = findereplacer(caesars, i, -normalShift);
            printf("%c", word[i]);
        }
    };
}