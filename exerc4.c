#include <stdio.h>

main(){

    int numero;

    printf("Digite um numero positivo: ");
    scanf("%d", &numero);

    if (numero <= 0) {
        printf("Por favor, insira um numero positivo.\n");
    } else {
        printf("Os divisores do numero %d são: ", numero);
        
        for (int i = 1; i <= numero; i++) {
            if (numero % i == 0) {
                printf("%d", i);
                
                if (i < numero) {
                    printf(", ");
                }
            }
        }

        printf("\n");
    }

    
}