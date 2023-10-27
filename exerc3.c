#include <stdio.h>

main(){

    int n;
    printf("Digite um numero inteiro maior ou igual a zero: ");
    scanf("%d", &n);

    int primeiroTermo = 0, segundoTermo = 1, termoAtual;

    if (n == 0) {
        termoAtual = primeiroTermo;
    } else if (n == 1) {
        termoAtual = segundoTermo;
    } else {
        for (int i = 2; i <= n; i++) {
            termoAtual = primeiroTermo + segundoTermo;
            primeiroTermo = segundoTermo;
            segundoTermo = termoAtual;
        }
    }

    printf("O enésimo termo da sequência de Fibonacci é: %d\n", termoAtual);


}