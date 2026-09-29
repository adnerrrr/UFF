#include <stdio.h>
int quantia = 5, idade;
float media;
int main(void){
    for (int i = 0; i < quantia; i++){
        printf("Digite a idade: ");
        scanf("%d", &idade);
        media += idade;
    }
    media = media / quantia;
    
    if (media <= 20) {
        printf("Baixa");
    }
    else{
        if (media <= 60) {
            printf("Media");
        }
        else {
            printf("Alta");
        }
    }
    return 0;
}

