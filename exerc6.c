#include <stdio.h>

main() {

    char continuar;

    do {
        int ano, mes, dias;

        printf("Digite o ano: ");
        scanf("%d", &ano);

        printf("Digite o mes (1 a 12): ");
        scanf("%d", &mes);

        
        int bissexto = ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0);

        
        switch (mes) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                dias = 31;
                break;
            case 4: case 6: case 9: case 11:
                dias = 30;
                break;
            case 2:
                if (bissexto) {
                    dias = 29;
                } else {
                    dias = 28;
                }
                break;
            default:
                printf("Mes inválido. Por favor, digite um valor entre 1 e 12.\n");
                continue;
        }

        printf("O mes %d/%d tem %d dias.\n", mes, ano, dias);

        printf("VOCÊ DESEJA OUTRAS ENTRADAS (S/?)? ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

}