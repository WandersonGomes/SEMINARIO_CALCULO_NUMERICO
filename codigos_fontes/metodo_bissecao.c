/*
Aluna: Antonia Estefane Ribeiro Veras
Instituicao: IFCE – Campus Tiangua
Disciplina: Calculo Numerico
Professor: Lucas Campos Freitas
Semestre: 2021.1

Descricao: Implementacao do algoritmo do metodo da bisseccao.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) {
	double y;
	y = sin(x) - pow(x,3) - 2;
	
	return y;
}

int main() {
	double a = 0.00, b = 0.00, c = 0.00, x = 0.00;
	int cont = 0;
	//Numero maximo de interacoes
	const int max = 100;
	//amplitude final, serve para criterio de parada
	const double I = 0.001;
	//precisao
	const double erro = 0.0001;
	
	printf("METODO DA BISSECAO.\n\n");
	
	printf("a = ");
	scanf("%lf", &a);

	printf("b = ");
	scanf("%lf", &b);

	c = b - a;
	x = (a + b)/2.0;
	
	while (fabs(f(x)) > erro || c > I) {
		if (f(a)*f(x) < 0.0) {
			b = x;
		}
		else{
			a = x;
		}
		c = b - a;
		x = (a + b)/2.0;
		cont++;
		
		if (cont >= max) {
			break;
		}
		printf("Iteracao = %d, a = %f, b = %f, f(a) = %f, f(b) = %f, f(x%d) = %f\n", cont, a, b, f(a), f(b), cont, f(x));
	} 
	printf("\nRaiz: %f\nInteracoes: %d\n f(%f) = %f\n", x, cont, x, f(x));
	return 0;
}