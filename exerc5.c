#include <stdio.h>
#include <string.h>

main() {
    
    char jogadoras[4][50] = {"Sam Kerr - Austrália", "Alex Morgan - Estados Unidos", "Dzsenifer Henry - França", "Marta Vieira - Brasil"};
    int votos[4] = {0};
    char nome[300][100];
    int idade[300];
    char sexo[300];
    char voto[300][50];

    int num_entrevistados = 0;
    int num_mulheres = 0;
    int num_maiores_idade = 0;

    char continuar = 'S';

    while ((continuar == 'S' || continuar == 's') && num_entrevistados < 300) {
        printf("Informe o nome: ");
        scanf("%s", nome[num_entrevistados]);

        printf("Informe a idade: ");
        scanf("%d", &idade[num_entrevistados]);

        if (idade[num_entrevistados] <= 12) {
            printf("A idade deve ser maior que 12 anos. Tente novamente.\n");
            continue;
        }

        printf("Informe o sexo (M/F): ");
        scanf(" %c", &sexo[num_entrevistados]);

        if (sexo[num_entrevistados] == 'F' || sexo[num_entrevistados] == 'f') {
            num_mulheres++;
        }

        printf("Informe o voto (Sam Kerr - Austrália, Alex Morgan - Estados Unidos, Dzsenifer Henry - França, Marta Vieira - Brasil): ");
        scanf("%s", voto[num_entrevistados]);

        int voto_valido = 0;
        for (int i = 0; i < 4; i++) {
            if (strcmp(voto[num_entrevistados], jogadoras[i]) == 0) {
                votos[i]++;
                voto_valido = 1;
                break;
            }
        }

        if (!voto_valido) {
            printf("Voto invalido. Tente novamente.\n");
            continue;
        }

        num_entrevistados++;

        if (num_entrevistados >= 50) {
            printf("Deseja encerrar a pesquisa? (S/N): ");
            scanf(" %c", &continuar);
        }
    }

    
    int max_votos = 0;
    printf("\nJogadoras mais votadas:\n");
    for (int i = 0; i < 4; i++) {
        if (votos[i] == max_votos) {
            printf("%s\n", jogadoras[i]);
        } else if (votos[i] > max_votos) {
            max_votos = votos[i];
            printf("%s\n", jogadoras[i]);
        }
    }

   
    printf("\nQuantidade de votos para cada jogadora:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s: %d votos\n", jogadoras[i], votos[i]);
    }

    printf("\nPessoas que participaram da pesquisa:\n");
    printf("Nome\tIdade\tSexo\n");
    for (int i = 0; i < num_entrevistados; i++) {
        printf("%s\t%d\t%c\n", nome[i], idade[i], sexo[i]);
        if (idade[i] >= 18) {
            num_maiores_idade++;
        }
    }

    printf("\nPessoas maiores de idade que votaram em Marta Vieira:\n");
    for (int i = 0; i < num_entrevistados; i++) {
        if (idade[i] >= 18 && strcmp(voto[i], "Marta Vieira - Brasil") == 0) {
            printf("%s\n", nome[i]);
        }
    }

    
    printf("\nQuantidade de mulheres que participaram da pesquisa: %d\n", num_mulheres);

    
}