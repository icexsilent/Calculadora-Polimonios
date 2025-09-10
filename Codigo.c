#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max_tam 100 // define o tamanho máximo para o polinômio

int calc_polinomio(int polinomio[], int grau, int num) {
    int resultado = 0, i;
    for (i = 0; i <= grau; i++) {
        int elevado = abs(i - grau);
        resultado = (polinomio[i] * (pow(num, elevado))) + resultado;
    }
    return resultado;
}

void soma_polinomios(int polinomio1[], int grau1, int polinomio2[], int grau2, int resultado[]) {
    int i, max_grau, cont = 0;
    if (grau1 >= grau2) {
        max_grau = grau1;
        cont = grau1 - grau2;
    } else {
        max_grau = grau2;
        cont = grau2 - grau1;
    }

    for (i = 0; i <= max_grau; i++) {
        if (grau1 == grau2) {
            resultado[i] = polinomio1[i] + polinomio2[i];
        } else if (grau1 > grau2) {
            if (i >= cont) {
                resultado[i] = polinomio1[i] + polinomio2[i - cont];
            } else {
                resultado[i] = polinomio1[i];
            }
        } else {
            if (i >= cont) {
                resultado[i] = polinomio1[i - cont] + polinomio2[i];
            } else {
                resultado[i] = polinomio2[i];
            }
        }
    }
}

void multiplicacao_polinomios(int polinomio1[], int grau1, int polinomio2[], int grau2, int resultado[]) {
    int max_grau = grau1 + grau2;
    for (int i = 0; i <= max_grau; i++) {
        resultado[i] = 0;
    }
    for (int i = 0; i <= grau1; i++) {
        for (int n = 0; n <= grau2; n++) {
            resultado[i + n] += polinomio1[i] * polinomio2[n];
        }
    }
}

int leitura_vetor(int grau, int polinomio[max_tam]) {
    for (int i = 0; i <= grau; i++) {
        int valor;
        printf("Insira o valor que acompanha x^%d: ", abs(i - grau));
        scanf("%d", &valor);
        polinomio[i] = valor;
    }
}

void representa_polinomios(int polinomio1[], int grau) {
    int primeiro_elemento = 1;
    int todos_zeros = 1;

    for (int i = 0; i <= grau; i++) {
        if (polinomio1[i] != 0) {
            todos_zeros = 0;
            break;
        }
    }

    if (todos_zeros) {
        printf("!!!Todos os elementos do polinomio sao 0!!!\n");
        return;
    }

    for (int i = 0; i <= grau; i++) {
        int expoente = abs(i - grau);

        if (polinomio1[i] == 0) {
            continue;
        } else {
            if (primeiro_elemento) {
                if (expoente == 0) {
                    printf("%d", polinomio1[i]);
                } else if (polinomio1[i] == 1) {
                    printf("x^%d", expoente);
                } else if (polinomio1[i] == -1) {
                    printf("-x^%d", expoente);
                } else {
                    printf("%dx^%d", polinomio1[i], expoente);
                }
                primeiro_elemento = 0;
            } else {
                if (expoente == 0) {
                    if (polinomio1[i] > 0) {
                        printf(" + %d", polinomio1[i]);
                    } else {
                        printf(" %d", polinomio1[i]);
                    }
                } else {
                    if (polinomio1[i] == 1) {
                        printf(" + x^%d", expoente);
                    } else if (polinomio1[i] == -1) {
                        printf(" - x^%d", expoente);
                    } else if (polinomio1[i] < -1) {
                        printf(" %dx^%d", polinomio1[i], expoente);
                    } else if (polinomio1[i] > 1) {
                        printf(" + %dx^%d", polinomio1[i], expoente);
                    }
                }
            }
        }
    }
    printf("\n");
}

void main() {
    int escolha;
    do {
        printf("\n[1]-Calcular o valor do polinomio(x)\n[2]-Adicao de Polinomios(+)\n[3]-Multiplicacao de Polinomios(*)\n[4]-Sair\n");
        printf("\nEscolha a operacao:\n");
        scanf("%d", &escolha);

        if (escolha == 1) {
            int num, resultado, polinomio1[max_tam], grau;
            printf("\nA escolha foi Calcular o Valor do polinomio!\n\n");
            printf("Informe o grau do polinomio: ");
            scanf("%d", &grau);
            leitura_vetor(grau, polinomio1);
            printf("Qual o valor de x: ");
            scanf("%d", &num);
            printf("\nPara o polinomio: ");
            representa_polinomios(polinomio1, grau);
            resultado = calc_polinomio(polinomio1, grau, num);
            printf("Sendo x = %d Resultado = %d.\n", num, resultado);

        } else if (escolha == 2) {
            int polinomio1[max_tam], grau1, polinomio2[max_tam], grau2, resultado[max_tam];
            printf("\nA escolha foi Adicao de Polinomios!\n\n");
            printf("Informe o grau do PRIMEIRO polinomio: ");
            scanf("%d", &grau1);
            leitura_vetor(grau1, polinomio1);
            printf("Informe o grau do SEGUNDO polinomio: ");
            scanf("%d", &grau2);
            leitura_vetor(grau2, polinomio2);
            soma_polinomios(polinomio1, grau1, polinomio2, grau2, resultado);
            printf("A soma dos polinomios: \nPolinomio 1: ");
            representa_polinomios(polinomio1, grau1);
            printf("Polinomio 2: ");
            representa_polinomios(polinomio2, grau2);
            printf("Resultado: ");
            if (grau1 >= grau2) {
                representa_polinomios(resultado, grau1);
            } else {
                representa_polinomios(resultado, grau2);
            }

        } else if (escolha == 3) {
            int polinomio1[max_tam], grau1, polinomio2[max_tam], grau2, resultado[max_tam];
            printf("\nA escolha foi Multiplicacao de Polinomios!\n\n");
            printf("Informe o grau do PRIMEIRO polinomio: ");
            scanf("%d", &grau1);
            leitura_vetor(grau1, polinomio1);
            printf("Informe o grau do SEGUNDO polinomio: ");
            scanf("%d", &grau2);
            leitura_vetor(grau2, polinomio2);
            multiplicacao_polinomios(polinomio1, grau1, polinomio2, grau2, resultado);
            printf("A multiplicacao dos polinomios: \nPolinomio 1: ");
            representa_polinomios(polinomio1, grau1);
            printf("Polinomio 2: ");
            representa_polinomios(polinomio2, grau2);
            printf("Resultado: ");
            representa_polinomios(resultado, grau1 + grau2);
        } else if (escolha != 4) {
            printf("\n!!!!!OPCAO INVALIDA ESCOLHA NOVAMENTE!!!!!\n");
        }
    } while (escolha != 4);

    printf("\n!!!Obrigado por usar a Calculadora de Polinomios do Rodrigo, Vinicius e Pedro!!!\n");
}
