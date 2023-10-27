#include <stdio.h>

int main(){
    
    int totalPessoas = 10;
    int numHomens = 0, numMulheres = 0;
    float alturaTotalHomens = 0, alturaTotalMulheres = 0, alturaTotalGrupo = 0;
    float pesoTotalHomens = 0, pesoTotalMulheres = 0, pesoTotalGrupo = 0;

    for (int i = 1; i <= totalPessoas; i++) {
        char nome[100];
        char sexo;
        float altura, peso;

        printf("Informe o nome da pessoa %d: ", i);
        scanf("%s", nome);

        printf("Informe o sexo da pessoa %d (M/F): ", i);
        scanf(" %c", &sexo);

        printf("Informe a altura da pessoa %d (em metros): ", i);
        scanf("%f", &altura);

        printf("Informe o peso da pessoa %d (em quilogramas): ", i);
        scanf("%f", &peso);

        
        if (sexo == 'M' || sexo == 'm') {
            numHomens++;
            alturaTotalHomens += altura;
            pesoTotalHomens += peso;
        } else if (sexo == 'F' || sexo == 'f') {
            numMulheres++;
            alturaTotalMulheres += altura;
            pesoTotalMulheres += peso;
        } else {
            printf("Sexo inválido para a pessoa %d. Use M ou F.\n", i);
            i--; 
        }

        alturaTotalGrupo += altura;
        pesoTotalGrupo += peso;
    }

    
    float alturaMediaHomens = (numHomens > 0) ? (alturaTotalHomens / numHomens) : 0;
    float alturaMediaMulheres = (numMulheres > 0) ? (alturaTotalMulheres / numMulheres) : 0;
    float alturaMediaGrupo = (totalPessoas > 0) ? (alturaTotalGrupo / totalPessoas) : 0;
    float pesoMediaHomens = (numHomens > 0) ? (pesoTotalHomens / numHomens) : 0;
    float pesoMediaMulheres = (numMulheres > 0) ? (pesoTotalMulheres / numMulheres) : 0;
    float pesoMediaGrupo = (totalPessoas > 0) ? (pesoTotalGrupo / totalPessoas) : 0;

    printf("Numero de homens: %d\n", numHomens);
    printf("Numero de mulheres: %d\n", numMulheres);
    printf("Altura media dos homens: %.2f metros\n", alturaMediaHomens);
    printf("Altura media das mulheres: %.2f metros\n", alturaMediaMulheres);
    printf("Altura media do grupo: %.2f metros\n", alturaMediaGrupo);
    printf("Peso medio dos homens: %.2f quilogramas\n", pesoMediaHomens);
    printf("Peso medio das mulheres: %.2f quilogramas\n", pesoMediaMulheres);
    printf("Peso medio do grupo: %.2f quilogramas\n", pesoMediaGrupo);

   
}