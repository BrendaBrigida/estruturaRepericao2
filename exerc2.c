#include <stdio.h>

main(){

    int totalMoradores = 50;
    int contA_M = 0, contA_V = 0, contA_N = 0;
    int contB_M = 0, contB_V = 0, contB_N = 0;
    int contC_M = 0, contC_V = 0, contC_N = 0;
    char elevador, periodo;

    for (int i = 1; i <= totalMoradores; i++) {
        printf("Informe o elevador mais utilizado pelo morador %d (A/B/C): ", i);
        scanf(" %c", &elevador);
        printf("Informe o período mais utilizado pelo morador %d (M/V/N): ", i);
        scanf(" %c", &periodo);

        switch (elevador) {
            case 'A':
                if (periodo == 'M') contA_M++;
                else if (periodo == 'V') contA_V++;
                else contA_N++;
                break;
            case 'B':
                if (periodo == 'M') contB_M++;
                else if (periodo == 'V') contB_V++;
                else contB_N++;
                break;
            case 'C':
                if (periodo == 'M') contC_M++;
                else if (periodo == 'V') contC_V++;
                else contC_N++;
                break;
            default:
                printf("Elevador invalido para o morador %d. Use A, B ou C.\n", i);
                i--; 
        }
    }

    int totalM = contA_M + contB_M + contC_M;
    int totalV = contA_V + contB_V + contC_V;
    int totalN = contA_N + contB_N + contC_N;

    char periodoMaisUsado;
    int totalPeriodoMaisUsado;
    if (totalM >= totalV && totalM >= totalN) {
        periodoMaisUsado = 'M';
        totalPeriodoMaisUsado = totalM;
    } else if (totalV >= totalM && totalV >= totalN) {
        periodoMaisUsado = 'V';
        totalPeriodoMaisUsado = totalV;
    } else {
        periodoMaisUsado = 'N';
        totalPeriodoMaisUsado = totalN;
    }


    int totalA = contA_M + contA_V + contA_N;
    int totalB = contB_M + contB_V + contB_N;
    int totalC = contC_M + contC_V + contC_N;

    char elevadorMaisFrequentado;
    int totalElevadorMaisFrequentado;
    if (totalA >= totalB && totalA >= totalC) {
        elevadorMaisFrequentado = 'A';
        totalElevadorMaisFrequentado = totalA;
    } else if (totalB >= totalA && totalB >= totalC) {
        elevadorMaisFrequentado = 'B';
        totalElevadorMaisFrequentado = totalB;
    } else {
        elevadorMaisFrequentado = 'C';
        totalElevadorMaisFrequentado = totalC;
    }

    
    int minTotal = totalM;
    if (totalV < minTotal) minTotal = totalV;
    if (totalN < minTotal) minTotal = totalN;

    float diferencaPercentual = ((float)(totalPeriodoMaisUsado - minTotal) / minTotal) * 100;

    int totalMedio = (totalA + totalB + totalC) - totalElevadorMaisFrequentado;
    float percentagemMedio = ((float)totalMedio / (totalA + totalB + totalC)) * 100;

    printf("Período mais usado de todos: %c (Total de usos: %d)\n", periodoMaisUsado, totalPeriodoMaisUsado);
    printf("Elevador mais frequentado: %c (Total de usos: %d)\n", elevadorMaisFrequentado, totalElevadorMaisFrequentado);
    printf("Diferença percentual entre o mais usado e o menos usado: %.2f%%\n", diferencaPercentual);
    printf("Percentagem sobre o total de serviços prestados do elevador de média utilização: %.2f%%\n", percentagemMedio);

}