#include <stdio.h>
#include <stdlib.h>
#include "Gcofo.h"
#include <string.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define MAXSIZENAME 10

int criarCofo(GCOFO** gcof);
int inserirNoCofo(GCOFO** gcof);
int listarCofo(GCOFO** gcof);
int removerDoCofo(GCOFO** gcof);
int esvaziarCofo(GCOFO** gcof);
int consulta(GCOFO** gcof);
typedef struct _rb_ RBAND;
struct _rb_ {
    char name[MAXSIZENAME];
    int idade;
    float relevancia;//de 0 a 100
};
void limparBuffer(){
    char c;
    while(c = getchar() != '\n' && c != EOF);
}
int cmpBand(void* gcofElm, void* key, char type){
    RBAND* band = (RBAND*) gcofElm;
    switch(type){
        case 'n':
        //ccompara nomes
        char* nome2 = (char*) key;
        return strcmp(band->name, nome2) == 0;
        break;
        case 'i':
        //compara inteiros
        int* idd2 = (int*) key;
        return band->idade == (*idd2);

        break;
        case 'r':
        //compara a diferenca da relevancia
        float* rel2 = (float*) key;
        return fabs(band->relevancia - (*rel2)) < 1e-5;
        break;
        default: return FALSE;
    }
}


RBAND*  criarBanda(){
    RBAND* rband = NULL;
    while(rband == NULL){
        rband = (RBAND*) malloc(sizeof(RBAND));
        if(rband == NULL) return NULL;
        printf("diga o nome da banda\n");
        fgets(rband ->name, sizeof(rband->name), stdin);
        printf("diga a idade da banda\n");
        scanf("%d", &rband -> idade);
        printf("o quao relevante a banda eh?[0 a 100]:\n");
        scanf("%f", &rband -> relevancia);
    }
    return rband;
}
int main(){
    int escolha = 0;
    GCOFO* gcof = NULL;
    while(escolha != 8){

        printf("o que quer fazer? \n 1 - criar cofo \n 2 - inserir no cofo \n 3 - remover do cofo \n 4 - listar elementos do cofo \n 5 - esvaziar cofo\n 6 - destruir cofo \n 7 - consultar do cofo\n8 - sair \n");
        scanf("%d", &escolha);
        //tem que limpar o buffer aq
        limparBuffer();
        switch(escolha){
            case 1: if(criarCofo(&gcof)) printf("cofo criado\n"); else printf("nao foi possivel criar\n\n"); break;
            case 2: if (inserirNoCofo(&gcof)) printf("elemento inserido com sucesso.\n\n"); else printf("Não foi possível inserir\n\n"); break;
            case 3: removerDoCofo(&gcof); break;
            case 4: if(listarCofo(&gcof) == FALSE) printf("NÃO FOI POSSÍVEL LISTAR\n"); break;
            case 5: esvaziarCofo(&gcof); break;
            case 6: if(gcofDestroy(gcof)) printf("destruido com sucesso\n"); else printf("nao foi possivel destrui-lo\n"); escolha = 8; break;
            case 7: consulta(&gcof);
        }


    }



    return 0;
}
//cuidado com a copia de um ponteiro
//retorna o sucesso
int criarCofo(GCOFO** gcof){
    int len;
    while(*gcof == NULL){

        printf("QUAL O TAMANHO DO COFO?\n");
        scanf("%d", &len);
        if(len > 0) {
            *gcof = gcofCreate(len);
            return TRUE;
        }

    }
    return FALSE;
}

//
int inserirNoCofo(GCOFO** gcof){

    if (*gcof != NULL){
        if(!gcofIsFull(*gcof)) {
            RBAND* rb = criarBanda();
            if(gcofInsert(*gcof, (void*) rb)) return TRUE;
            else return FALSE;
        }
    }
    return FALSE;
}

int listarCofo(GCOFO** gcof){
    if(*gcof != NULL){
        int idx = 0;
        RBAND* rb = NULL;
        rb = (RBAND*) gcofGetNext(*gcof);
        while( rb != NULL){
            printf("banda == [%d]\n", idx);
            printf("name = %s\n", rb ->name);
            printf("idade = %d\n", rb ->idade);
            printf("relevancia = %f\n", rb ->relevancia);
            printf("=========================================\n\n");
            idx++;
            rb = (RBAND*)gcofGetNext(*gcof);
        }
        if(gcofIsEmpty(*gcof)) printf("colecao vazia\n");
        else return TRUE;
    }
    return FALSE;
}


int removerDoCofo(GCOFO** gcof){
    if(*gcof != NULL){
        char type;
        int i;
        char nome[MAXSIZENAME];
        RBAND* rb;
        float rel;
        void* key;
        printf("Insira qual campo quer remover['n' para nome, i' para idade, 'r' para relevancia]\n");
        scanf(" %c", &type);
        printf("Insira o dado que quer procurar:\n");
        limparBuffer();
        switch(type){
        case 'n':
        fgets(nome, sizeof(nome), stdin);
        key = (void*) nome;
        break;
        case 'i':
            scanf("%d", &i);
            key = (void*) &i;
        break;
        case 'r':
            scanf("%f", &rel);
            key = (void*)&rel;
        break;
        }
        rb = (RBAND*) gcofRemove(*gcof, key, type, cmpBand);
        if(rb != NULL) printf("encontrado com sucesso\n");
        else printf("naum foi encontrado\n");
        free(rb);

    }
}
int esvaziarCofo(GCOFO** gcof){
    if(*gcof != NULL){
        if(gcofEsvaziar(*gcof)) printf("ESVAZIADO COM SUCESSO\n");
        else printf("NÃO FOI POSSIVEL\n");
    }
    return FALSE;
}
int consulta(GCOFO** gcof){
    if(*gcof != NULL){
        char type;
        int i;
        char nome[MAXSIZENAME];
        RBAND* rb;
        float rel;
        void* key;
        printf("Insira qual campo quer consultar['n' para nome, i' para idade, 'r' para relevancia]\n");
        scanf(" %c", &type);
        printf("Insira o dado que quer procurar:\n");
        limparBuffer();
        switch(type){
        case 'n':
        fgets(nome, sizeof(nome), stdin);
        key = (void*) nome;
        break;
        case 'i':
            scanf("%d", &i);
            key = (void*) &i;
        break;
        case 'r':
            scanf("%f", &rel);
            key = (void*)&rel;
        break;
        }
        rb = gcofConsultar(*gcof, key, type, cmpBand);
        if(rb != NULL) printf("estah na colecao\n");
        else printf("nao estah na colecao");
        }
}
