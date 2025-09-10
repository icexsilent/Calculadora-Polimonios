#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max_tam 100 // define o tamanho maximo para o polinomio

int calc_polinomio(int polinomio[], int grau, int num) { // Função para calcular o valor do polinomio para determinado x(1° opção)
    int resultado = 0, i; // Definindo variaveis de contagem e resultado

    for (i = 0; i <= grau; i++) { // Criação de laço de repetição para percorrer o vetor onde esta o polinomio
        int elevado; // Criação de variavel para determinar a que valor x sera elevado
        elevado = abs(i - grau); // Determinando o valor de elevado
        resultado = (polinomio[i] * (pow(num, elevado))) + resultado; // Fazendo o calculo para atribuir na soma
    }
    return resultado; // retorno do resultado após percorrer o laço
}

void soma_polinomios(int polinomio1[], int grau1, int polinomio2[], int grau2, int resultado[]) { // Função para calcular a soma de polinomios
    int i, max_grau, cont = 0; // Definindo as variaveis
    if (grau1 >= grau2) { // Comparação para definir o grau do resultado
        max_grau = grau1; // Atribuição do grau para o resultado
        cont = grau1 - grau2; // Definindo valor da variavel de contagem para auxilio na soma
    } else {
        max_grau = grau2; // Atribuição do grau para o resultado
        cont = grau2 - grau1; // Definindo valor da variavel de contagem para auxilio na soma
    }

    for (i = 0; i <= max_grau; i++) { // Laço de repetição para percorrer o polinomio
        if (grau1 == grau2) { // Comparação para escolha de caminho da soma
            resultado[i] = polinomio1[i] + polinomio2[i]; // Graus iguais soma a mesma posição de cada vetor e gera resultado
        } else if (grau1 > grau2) { // Comparação para escolha de caminho da soma
            if (i >= cont) { // Comparação para escolha de caminho da soma
                resultado[i] = polinomio1[i] + polinomio2[i - cont]; // Expoentes iguais soma a mesma posição de cada vetor e gera resultado
            } else {
                resultado[i] = polinomio1[i]; // Expoentes diferentes soma apenas o valor do vetor maior
            }
        } else {
            if (i >= cont) { // Comparação para escolha de caminho da soma
                resultado[i] = polinomio1[i - cont] + polinomio2[i]; // Expoentes iguais soma a mesma posição de cada vetor e gera resultado
            } else {
                resultado[i] = polinomio2[i]; // Expoentes diferentes soma apenas o valor do vetor maior
            }
        }
    }
}

void multiplicacao_polinomios(int polinomio1[], int grau1, int polinomio2[], int grau2, int resultado[]) {
    int max_grau = grau1 + grau2; // Grau maximo da multiplicacao

    // crio um array de zeros
    for (int i = 0; i <= max_grau; i++) {
        resultado[i] = 0;
    }

    // faço 2 loopings para multiplicar os polinomios, assim cada elemento do polinomio1 será multiplicado pelo polinomio2
    for (int i = 0; i <= grau1; i++) {
        for (int n = 0; n <= grau2; n++) {
            resultado[i + n] += polinomio1[i] * polinomio2[n]; // acumulo e somo, pensando como se fossem lista dentro de lista
        }
    }
}

int leitura_vetor(int grau, int polinomio[max_tam]) { // Função para leitura do valor do polinomio
    int i; // Variavel para contagem
    for (i = 0; i <= grau; i++) { // Criação de laço de repetição para percorrer o vetor onde estara o polinomio
        int valor; // Variavel para armazenar o valor que vai acompanhar cada posição de x no polinomio
        printf("Insira o valor que acompanha x^%d: ", abs(i - grau)); // Print para informar o que o usuario deve fazer
        scanf("%d", &valor); // Scan do valor digitado pelo usuario para cada posição
        polinomio[i] = valor; // Atribuindo a posição respectiva o valor digitado pelo usuario
    }
}

void representa_polinomios(int polinomio1[], int grau) { // Função para realizar o print do polinomio apartir da leitura da lista
    int i; // Variavel para contagem
    int primeiro_elemento = 1; // Variavel para definir se é o primeiro valor inteiro diferente de 0 a ser printado

    int todos_zeros = 1; // Definindo variavel
    for (i = 0; i <= grau; i++) { // Verifica se todos os elementos são zero
        if (polinomio1[i] != 0) { // Caso o valor seja diferente de zero
            todos_zeros = 0; // Todos zero vira falso
            break; // Sai do laço
        }
    }
    if (todos_zeros) { // Caso todos zero seja verdadeiro
        printf("!!!Todos os elementos do polinomio sao 0!!!\n"); // Printa que todos os elementos são zero
        return; // Sai da função, pois o polinômio é zero
    }
    for (i = 0; i <= grau; i++) { // Criação de laço de repetição para percorrer o vetor onde esta o polinomio
        int expoente = abs(i - grau); // Criação de variavel para determinar a que valor x sera elevado

        if (polinomio1[i] == 0) { // Comparação para ver se o valor no vetor é 0
            continue; // Caso seja pula para a proxima execução
        } else if (polinomio1[i] != 0) { // Caso seja diferente de 0
            if (primeiro_elemento) { // Verifica se é o primeiro elemento a ser printado
                if (expoente == 0) { // Caso o ultimo elemento do vetor
                    printf("%d", polinomio1[i]); // Printa apenas o valor inteiro
                } else if (polinomio1[i] == 1) { // Para ver se o valor é igual a 1
                    printf("x^%d", expoente); // Printa apenas x^ ao expoente
                } else if (polinomio1[i] == -1) { // Para ver se o valor é igual a -1
                    printf("-x^%d", expoente); // Printa apenas -x^ ao expoente
                } else {
                    printf("%dx^%d", polinomio1[i], expoente); // Printa o valor correspondente
                }
                primeiro_elemento = 0; // Define que o primeiro elemento ja foi printado
            } else {
                if (expoente == 0) { // Verifica se o expoente é 0, ultimo elemento do vetor
                    if (polinomio1[i] > 0) { // Verifica se é positivo
                        printf(" + %d", polinomio1[i]); // Se for positivo printa + e apenas o valor inteiro
                    } else if (polinomio1[i] < 0) { // Verifica se é negativo
                        printf(" %d", polinomio1[i]); // Se for negativo printa - e apenas o valor inteiro
                    }
                } else {
                    if (polinomio1[i] == 1) { // Verifica se o valor é 1
                        printf(" + x^%d", expoente); // Printa apenas o + x^ao expoente
                    } else if (polinomio1[i] == -1) { // Verifica se o valor é -1
                        printf(" - x^%d", expoente); // Printa apenas o - x^ao expoente
                    } else if (polinomio1[i] < -1) { // Verifica se o valor é negativo
                        printf(" %dx^%d", polinomio1[i], expoente); // Printa apenas o valor acompanhado de x^ao expoente
                    } else if (polinomio1[i] > 1) { // Verifica se o valor é positivo
                        printf(" + %dx^%d", polinomio1[i], expoente); // Printa + o valor acompanhado de x^ao expoente
                    }
                }
            }
        }
    }

    printf("\n"); // Printa uma nova linha
}

void main() { // Definição da função main
    int escolha; // Definindo a variavel de escolha

    do { // Definindo um laço de repetição do while para rodar até o usuario digitar 4 para sair do programa
        printf("\n[1]-Calcular o valor do polinomio(x)\n[2]-Adicao de Polinomios(+)\n[3]-Multiplicacao de Polinomios(*)\n[4]-Sair\n"); // Print do Menu de seleções disponiveis para o usuario
        printf("\")

