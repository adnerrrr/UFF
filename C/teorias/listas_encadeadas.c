#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
    int info;
    struct lista *prox;
}no;

int buscaElemento(no *L, int elem, no **pre){
    //L é o endereço inicial da lista, elem é o elemento que é procurado e pre retorna o endereço do nó anterior
    no *aux, *preL;
    aux = L;
    preL = NULL;
    while (aux != NULL && aux->info < elem){
        preL = aux;
        aux = aux->prox;
    }

    (*pre) = preL;

    if (aux != NULL && aux->info == elem){
        printf("Elemento ja esta na lista.");
        return 1;
    }
    return 0; 
}

no *insere(no *L, int elem){
    //L é o endereço inicial da lista e elem é o item a ser inserido
    no *pre, *el;
    //el é o nó que será inserido, pre é o endereço do nó anterior ao que será inserido
    if (!buscaElemento(L, elem, &pre)){
        el = (no*)malloc(sizeof(no));
        if (pre == NULL){
            el->info = elem;
            el->prox = L;
            L = el;
        }

        else{
            el->info = elem;
            el->prox = pre->prox;
            pre->prox = el;
        }
    }
    return L;
}

no *removeElem(no *L, int elem){
    no *pre, *lixo;
    if (buscaElemento(L, elem, &pre)){
        if (pre == NULL){
            lixo = L;
            L = lixo->prox;
            free(lixo);
        }
        else{
            lixo = pre->prox;
            pre->prox = lixo->prox;
            free(lixo);
        }
    }
    return L;
}

int menu()
{
    int op;
    printf("\n===MENU===\n[1]Print the List\n[2]Search for a element\n[3]Insert an element\n[4]Remove an element\n[5]Leave\n-> ");
    scanf("%d", &op);
    if (op >= 1 && op <= 5)
        return op;
    else
        return 0;
}

int main()
{
    no *L = malloc(sizeof(no));
    L->prox = NULL;

    int op, elem;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            // so muda na chamada da funcao, comecando depois da cabeca
            //print_lista(L->prox);
            printf("\n");
            break;

        case 2:
            // printf("Type the element to search: ");
            // scanf("%d", &elem);

            //pos = posicaoElem(L, elem);
            // if (pos)
            //     printf("Elemento ENCONTRADO!\nPosicao = %d\n", pos);
            // else
            //     printf("Elemento NAO encontrado!\n");

            // break;

        case 3:
            printf("Type the element to insert: ");
            scanf("%d", &elem);

            L = insere(L, elem);

            break;
        case 4:
            printf("Type the element to remove: ");
            scanf("%d", &elem);

            L = removeElem(L, elem);

            break;

        default:
            printf("End of progam.\n");
            op = 0;
            break;
        }

    } while (op);

    getchar();
    getchar();
}