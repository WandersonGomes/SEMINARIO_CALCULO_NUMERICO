/*
Aluno: Anna Zenaide Dias Alves
Instituicao: IFCE - Campus Tiangua
Disciplina: Calculo Numerico
Professor: Lucas Campos Freitas
Semestre: 2021.1

Descricao:
Implementacao do algoritmo do metodo de Newton-Raphson
*/
#include <stdio.h>
#include <math.h>

#define MAX_ITERACOES 100

double funcao(double);
double derivada(double);
double Newton(double, double, double, double, int);
void imprimeLinha(int, double, double, double);

int main() {
    //Programa principal
    double a, b, precisao;
    double raiz;

    //solicita os dados para o calculo
    printf("Informe o valor de a: ");
    scanf("%lf", &a);
    printf("Informe o valor de b: ");
    scanf("%lf", &b);

    //solicita uma precisao
    do {
        printf("Informe o valor da precisao desejada: ");
        scanf("%lf", &precisao);
        if (precisao <= 0)
            printf("Error: valor invalido! Tente novamente.\n");
    } while (precisao <= 0);

    //chama o metodo para realizar os calculos
    printf("\n");
    raiz = Newton(a, b, precisao, precisao, MAX_ITERACOES);

    //apresenta a raiz encontrada
    printf("\nRaiz encontrada: %lf\n", raiz);
    return 0;
}

double funcao(double x) {
    //Funcao Analisada;
    return sin(x) - (x*x*x) - 2;
}

double derivada(double x) {
    //Derivada da funcao analisada
    return cos(x) - (3*x*x);
}

void imprimeLinha(int iteracao, double x0, double x1, double erro) {
    //Imprime uma linha com dados em cada iteracao
    printf("iteracao = %d, x%d = %lf, f(x%d) = %lf, x%d = %lf, error = %lf\n", iteracao, iteracao, x0, iteracao, funcao(x0), iteracao + 1, x1, erro);
}

double Newton(double a, double b, double precisao1, double precisao2, int max_iteracoes) {
    //Implementacao do metodo de Newton-Raphson
    //variaveis auxiliares para o calculo
    int iteracao = 0;
    double x0, x1;
    x0 = (double)(a + b)/2.0;
    printf("a = %lf, b = %lf, precisao =  %lf, x0 = %lf\n\n", a, b, precisao1, x0);
    //apresenta uma linha com os dados iniciais
    printf("iteracao = %d, x0 = %lf,  f(x0) = %lf, x%d = %lf, error = %lf\n", iteracao, x0, funcao(x0), iteracao+1, x0 - funcao(x0)/derivada(x0), fabs(funcao(x0)));
    
    //passo 02
    if (fabs(funcao(x0)) < precisao1) {
        return x0;
    }

    //passo 03
    iteracao = 1;

    while (iteracao <= max_iteracoes) {
        //passo 04
        x1 = x0 - (funcao(x0)/derivada(x0));

        //apresenta os dados
        imprimeLinha(iteracao, x1, x1-funcao(x1)/derivada(x1), fabs(funcao(x1)));

        //passo 05
        if ((fabs(funcao(x1)) < precisao1) || (fabs(x1 - x0) < precisao2)) {
            return x1;
        }
        //passo 6
        x0 = x1;
        //passo 07
        ++iteracao;
    }

    //caso ultrapasse o maximo de iteracoes
    return x1;
}