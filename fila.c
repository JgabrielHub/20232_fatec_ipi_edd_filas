#include "fila.h"

void inicia_fila (t_fila *f) {
    f->primeiro = f->ultimo = NULL;
}

int esta_vazia (t_fila *f) {
    return f->primeiro == NULL;
}

void enfileirar (int i, t_fila *f) {
    struct no * novo = cria_no(i);
    if(esta_vazia(f)) {
        f->primeiro = f->ultimo = novo;
    }
    else {
        f->ultimo->proximo = novo;
        f->ultimo = novo;
    }
}

int desenfileirar (t_fila *f) {
    int i = f->primeiro->info;
    struct no * aux = f->primeiro;
    f->primeiro = f->primeiro->proximo;
    if(esta_vazia(f)) {
        f->ultimo = NULL;
    }
    return i;
    free(aux);
}

void exibe_fila(t_fila *f) {
    struct no * aux;
    if (esta_vazia(f))
    {
        printf("\nfila vazia\n");
    }
    else {
        aux = f->primeiro;
        do {
            printf("%d ", aux->info);
            aux = aux->proximo;
        } while (aux != NULL);
    }
    printf("\n");   
}