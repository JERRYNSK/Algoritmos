#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 20
int isPalin(char* word);
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void strToLower(char text[MAX]){
    for(int i = 0; i < MAX; i++){
        if(isalpha(text[i]) && isupper(text[i])){
            text[i] = tolower(text[i]);
        }
    }
}

void readParag(char text[MAX]){
    printf("COLOQUE VOSSO PARAGRAFO: \n");
    fgets(text, MAX, stdin);
    //printf("texto tem %d letras\n", strlen(text));
    if (strlen(text) >= MAX - 1){
        clearBuffer();
    }

}
void countWords(char text[MAX], int* words){
    char *textCpy = (int*) malloc(MAX * sizeof(char));
        if(textCpy != NULL){
        strncpy(textCpy, text, MAX);
        textCpy = strtok(textCpy, " ");
        while(textCpy != NULL){
            textCpy = strtok(NULL, " ");
            *words += 1;
        }
    }
}
void countVogals(char text[MAX], int* countVogals){
    char *textCpy = (char*) malloc(MAX * sizeof(char));
        if(textCpy != NULL){
        strncpy(textCpy, text, MAX);
        textCpy = strtok(textCpy,"bcdfghjklmnpqrstvwyxz\n ");

        //printf("vogal(fora): %s\n", textCpy);
        while(textCpy != NULL){
            *countVogals += strlen(textCpy);
            //printf("vogal(dentro): %s\n len[%d]\n", textCpy, strlen(textCpy));
            textCpy = strtok(NULL, "bcdfghjklmnpqrstvwyxz\n ");
        }
    }
}
void countConsonant(char text[MAX], int* countConsonant){
    char *textCpy = (char*) malloc(MAX * sizeof(char));
        if (textCpy != NULL){
        strncpy(textCpy, text, MAX);
        textCpy = strtok(textCpy,"aeiou\n ");

        //printf("vogal(fora): %s\n", textCpy);
        while(textCpy != NULL){
            *countConsonant += strlen(textCpy);
            //printf("vogal(dentro): %s\n len[%d]\n", textCpy, strlen(textCpy));
            textCpy = strtok(NULL, "aeiou\n ");
        }
    }
}
//para encontrar palindromos
void getWord(char text[MAX]){
    char *textCpy = (char*) malloc(MAX * sizeof(char));
    strncpy(textCpy, text, MAX);
    textCpy = strtok(textCpy, " ");
    while(textCpy != NULL){
        if(isPalin(textCpy)) printf("palindromo: %s\n", textCpy);
        textCpy = strtok(NULL, " ");
    }

}
void noBreakLine(char text[MAX]){
    char* breakLine = strchr(text, '\n');
    if(breakLine != NULL) breakLine[0] = ' ';
}
void switchWord(char text[MAX]){
    char wordForSubs[MAX];
    char newString[MAX];
    printf("QUAL PALAVRA QUER MUDAR?\n");
    fgets(wordForSubs,MAX, stdin);
    printf("PARA QUAL QUER MUDAR?\n");
    fgets(newString,MAX, stdin);
    strtok(newString, "\n");
    strtok(wordForSubs, "\n");
    char* pos = strstr(text, wordForSubs);
   if(pos != NULL){
        //se a palavra anterior for maior que a nova palavra
        if(strlen(wordForSubs) >= strlen(newString)){
            for(int i = 0; i < strlen(wordForSubs); i++){
                if(i < strlen(newString)) pos[i] = newString[i];
                else pos[i] = ' ';
            }
        } else {
            //deslocamento pra direita
            int mod = strlen(newString) % strlen(wordForSubs);
            //apaga o conteudo
            for(int i = 0; i < strlen(wordForSubs) && strlen(pos); i++){
                pos[i] = ' ';
            }
            //desloca mod vezes os caracteres para a direita
            for(int i= 0;i < mod;i++){
                for(int j = strlen(pos) - 1; j > strlen(wordForSubs);j--){
                    if(j < strlen(pos)) pos[j] = pos[j - 1];

                }
            }
            //copiar palavra
            for(int i = 0; i < strlen(newString) && i < strlen(pos);i++){
                pos[i] = newString[i];
            }
        }


   } else {
        printf("ERROR! OU nao encontrado\n");
   }
}
char* rle_comprimer(char text[MAX]){
    int n = strlen(text);
    int outIdx = 0;
    char* comprimer = (char*) malloc( (2 * MAX + 1) * sizeof(char));
    if(comprimer == NULL) return NULL;

    for(int i = 0; i < n; ){
        char cur = text[i];

        int count = 0;
        while((i + count) < n && cur == text[i + count]){
            count++;
        }
        if(cur != '\n')
        outIdx += sprintf(comprimer + outIdx, "%d%c", count, cur);
        i += count;
    }

    comprimer[MAX] = '\0';
    return comprimer;
}
//zero para falso, senao verdadeiro
int isPalin(char* word){
    int i = 0;
    int j = strlen(word) - 1;

    while(i < j){
        if(word[i] != word[j]) return 0;
        i++;
        j--;
    }
    return 1;
}
int main(){


    int vogals = 0;
    int consonant = 0;
    int words = 0;
    char text[MAX];
    char* textComprimed;

    readParag(text);
    noBreakLine(text);
    printf("{%s}\n", text);
    printf("comprimed text: \n");
    textComprimed = rle_comprimer(text);
    printf("%s\n", textComprimed);

    printf("LISTA DE PALINDROMOS: \n");

    getWord(text);
    strToLower(text);
    countWords(text, &words);
    countVogals(text, &vogals);
    countConsonant(text, &consonant);
    printf("consoantes:%d \nvogais: %d\n", consonant, vogals);
    printf("palavras: %d\n", words);
    switchWord(text);
    printf("{%s}\n", text);


    return 0;

}
