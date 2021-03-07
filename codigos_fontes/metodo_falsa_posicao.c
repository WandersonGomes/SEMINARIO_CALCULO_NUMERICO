/*
Aluno: Wanderson Gomes da Costa
Instituicao: IFCE - Campus Tiangua
Disciplina: Calculo Numerico
Professor: Lucas Campos Freitas
Semestre: 2021.1

Descricao:
Implementacao do algoritmo do metodo da Falsa Posicao
*/
#include <stdio.h>
#include <math.h>

#define MAX_ITERACOES 100

//FUNCAO QUE RETORNA O MODULO DE UM NUMERO
double modulo(double numero) {
    return (numero < 0) ? (-1)*numero : numero;
}

//FUNCAO ANALISADA
double funcao(double x) {
    return sin(x) - (x*x*x) - 2;
}

//FUNCAO QUE IMPRIME A LINHA COM OS DADOS NECESSARIOS
void imprimeLinha(int iteracao, double a, double b, double x) {
    double erro = modulo(funcao(x));
    printf("iteracao = %02d, a = %lf, b = %lf, f(a) = %lf, f(b) = %lf, x%02d = %lf, f(x%02d) = %lf, error = %lf\n", 
            iteracao, a, b, funcao(a), funcao(b), iteracao, x, iteracao, funcao(x), erro);
}

//FUNCAO QUE IMPLEMENTA O METODO DA FALSA POSICAO
double metodoFalsaPosicao(double a, double b, double precisao1, double precisao2, int max_iteracoes) {
    //variavies auxiliares para o calculo
    int iteracao = 0;
    double M = 0.00, x = 0.00;

    //apresenta uma linha com os dados iniciais
    printf("iteracao = 00, a = %lf, b = %lf, f(a) = %lf, f(b) = %lf, x00 =          , f(x00) =          , error = \n", 
            a, b, funcao(a), funcao(b));

    //passo 02
    if ((b - a) < precisao1) {
        return (a+b)/2;
    }

    if (modulo(funcao(a)) < precisao2) {
        return a;
    } else if (modulo(funcao(b)) < precisao2) {
        return b;
    }

    //passo 03
    iteracao = 1;

    while (iteracao <= max_iteracoes) {
        //passo 04
        x = (a*funcao(b) - b*funcao(a))/(funcao(b) - funcao(a));

        //apresenta os dados
        imprimeLinha(iteracao, a, b, x);
        
        //passo 05
        if ((funcao(a)*funcao(x)) > 0) {
            a = x;
        } else {
            //passo 06
            b = x;
        }

        //passo 07
        if (modulo(funcao(x)) < precisao2) {
            return x;
        }

        //passo 08
        if ((b - a) < precisao1) {
            return (a + b)/2;
        }

        //passo 09
        iteracao = iteracao + 1;
    }

    //caso ultrapasse o maximo de iteracoes
    return (a + b)/2;
}


//PROGRAMA PRINCIPAL
int main() {
    double a = 0.00, b = 0.00, precisao = 0.00;
    double raiz = 0.00;

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
    raiz = metodoFalsaPosicao(a, b, precisao, precisao, MAX_ITERACOES);

    //apresenta a raiz encontrada
    printf("\nRaiz encontrada: %lf\n", raiz);

    return 0;
}