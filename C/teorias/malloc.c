#include <stdio.h>
#include <stdlib.h>

int main(){
    //malloc retorna um ponteiro para a região da memória alocada, caso não consiga alocar retorna null
    int *x;
    x = malloc(sizeof(int));
    *x = 50;
}