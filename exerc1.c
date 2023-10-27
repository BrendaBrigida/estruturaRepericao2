#include <stdio.h>

main() {

    int capacidade = 100;
    char opcao;
    int idade, totalIdadeRuim = 0, totalIdadeOtimo = 0;
    int contOtimo = 0, contBom = 0, contRegular = 0, contRuim = 0, contPessimo = 0;
    int maiorIdadeOtimo = 0, maiorIdadeRuim = 0;

    for (int i = 1; i <= capacidade; i++) {
        printf("Informe a idade do espectador %d: ", i);
        scanf("%d", &idade);

        printf("Informe a opção (A/B/C/D/E) em relação ao filme para o espectador %d: ", i);
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'A':
                contOtimo++;
                totalIdadeOtimo += idade;
                if (idade > maiorIdadeOtimo) {
                    maiorIdadeOtimo = idade;
                }
                break;
            case 'B':
                contBom++;
                break;
            case 'C':
                contRegular++;
                break;
            case 'D':
                contRuim++;
                totalIdadeRuim += idade;
                if (idade > maiorIdadeRuim) {
                    maiorIdadeRuim = idade;
                }
                break;
            case 'E':
                contPessimo++;
                if (idade > maiorIdadeRuim) {
                    maiorIdadeRuim = idade;
                }
                break;
            default:
                printf("Opção invalida para o espectador %d. Use A, B, C, D ou E.\n", i);
                i--; 
        }
    }

    printf("Quantidade de respostas otimo: %d\n", contOtimo);
    
    if (contBom > 0 && contRegular > 0) {
        float diferencaPercentual = 100.0 * (contBom - contRegular) / (contBom + contRegular);
        printf("Diferença percentual entre respostas Bom e Regular: %.2f%%\n", diferencaPercentual);
    } else {
        printf("Nao ha respostas Bom ou Regular para calcular a diferença percentual.\n");
    }

    if (contRuim > 0) {
        float mediaIdadeRuim = (float)totalIdadeRuim / contRuim;
        printf("Media de idade das pessoas que responderam Ruim: %.2f\n", mediaIdadeRuim);
    } else {
        printf("Nso há respostas Ruim para calcular a media de idade.\n");
    }

    if (contPessimo > 0) {
        float percentagemPessimo = 100.0 * contPessimo / capacidade;
        printf("Percentagem de respostas Pessimo: %.2f%%\n", percentagemPessimo);
        printf("Maior idade que utilizou a opção Pessimo: %d\n", maiorIdadeRuim);
    } else {
        printf("Não ha respostas Péssimo para calcular a percentagem ou a maior idade.\n");
    }

    if (contOtimo > 0 && contRuim > 0) {
        int diferencaIdade = maiorIdadeOtimo - maiorIdadeRuim;
        printf("Diferença de idade entre a maior idade que respondeu Ótimo e a maior idade que respondeu Ruim: %d\n", diferencaIdade);
    } else {
        printf("Não ha respostas otimo ou Ruim para calcular a diferença de idade.\n");
    }


}