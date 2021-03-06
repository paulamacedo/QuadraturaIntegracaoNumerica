/*
Sobre o programa principal: Consiste em oferecer ao usuário um menu, descrevendo o programa e explicando o 
algoritmo. Permite, ao usário, selecionar as opções que deseja utilizar, sendo possível escolher executar um
programa sequencial ou concorrente

Autores: Daniel La Rubia e Paula Macedo

 */

#include <stdio.h>
#include <stdlib.h>
#include "quadraturaAlgorithm.c"
#include "funcoes.c"
#include "textos.c"
#include "timer.h"


double inicio, fim, inicioGlobal, fimGlobal;
void execucaoComparativa();
void execucaoSequencial();
void execucaoConcorrente();
void execucaoConcorrenteDesbalanceada();

int main () {
	int opcao;
	

	exibeMenu();
	scanf("%d", &opcao);
	system("clear");
	
	while(opcao != 9) {
		system("clear");
		switch (opcao) {
			
			case 0:
				exibeMenu();
				scanf("%d", &opcao);
				break;
			
			case 1:
				textoDescricao();
				printf("\n      *** Digite 0 para exibir o menu ou 9 para encerrar a aplicação ***\n");
				scanf("%d", &opcao);
				system("clear");
				break;

			case 2:
				textoImplementacao();
				printf("\n      *** Digite 0 para exibir o menu ou 9 para encerrar a aplicação ***\n");
				scanf("%d", &opcao);
				break;
			
			case 3:
				recebeParametros();
				execucaoSequencial();	
				limpaLixo();
				printf("\n      *** Digite 0 para exibir o menu, 3 para repetir a operação ou 9 para encerrar a aplicação ***\n");
				scanf("%d", &opcao);
				system("clear");
				break;
			
			case 4:
				recebeNTHREADS();
				recebeParametros();
				execucaoConcorrente();			
				limpaLixo();
				printf("\n      *** Digite 0 para exibir o menu, 4 para repetir a operação ou 9 para encerrar a aplicação ***\n");
				scanf("%d", &opcao);
				system("clear");
				break;

			case 5:
				recebeNTHREADS();
				recebeParametros();
				execucaoConcorrenteDesbalanceada();			
				limpaLixo();
				printf("\n      *** Digite 0 para exibir o menu, 5 para repetir a operação ou 9 para encerrar a aplicação ***\n");
				scanf("%d", &opcao);
				system("clear");
				break;
			
			case 6:
				recebeNTHREADS();
				recebeParametros();
				execucaoComparativa();
				limpaLixo();
				printf("\n      *** Digite 0 para exibir o menu, 6 para repetir a operação ou 9 para encerrar a aplicação ***\n");
				scanf("%d", &opcao);
				system("clear");
				break;
			
			case 7:
				textoInfoGrupo();
				printf("\n      *** Digite 0 para exibir o menu ou 9 para encerrar a aplicação ***\n");
				scanf("%d", &opcao);
				system("clear");
				break;
			
			default:
				printf("Opção inválida.\n");
				printf("\n *** Digite 0 para exibir o menu ou 9 para encerrar a aplicação ***\n\n");
				scanf("%d", &opcao);
				system("clear");
				break;
		}
	}

	return 0;
}


void execucaoSequencial() {

	printf("\n\nRESULTADOS DO PROGRAMA SEQUENCIAL: \n\n");
	GET_TIME(inicioGlobal);
	
	GET_TIME(inicio);
	printf("Integral de a(x) = 1 + x ==> %f\n", integralRecursiva(a, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);
	
	if(intervalo_a < -1 || intervalo_b > 1) {
		printf("A função b(x) = sqrt(1 - x²) só está definida no intervalo -1 < x < 1\n\n");
	}
	else {
	GET_TIME(inicio);
	printf("Integral de b(x) = sqrt(1 - x²) ==> %f\n", integralRecursiva(b, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);
	}
	
	GET_TIME(inicio);
	printf("Integral de c(x) = sqrt(1 + x⁴) ==> %f\n", integralRecursiva(c, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	GET_TIME(inicio);
	printf("Integral de d(x) = sen(x²) ==> %f\n", integralRecursiva(d, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	GET_TIME(inicio);
	printf("Integral de e(x) = cos(e^-x) ==> %f\n", integralRecursiva(e, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);
	
	GET_TIME(inicio);
	printf("Integral de f(x) = cos(e^-x) * x ==> %f\n", integralRecursiva(f, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	GET_TIME(inicio);
	printf("Integral de g(x) = cos(e^-x) * (0.005 * cos(x³) + 1) ==> %f\n", integralRecursiva(g, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	GET_TIME(fimGlobal);
	printf("Tempo necessário para o cálculo de todas as funções: %f\n\n", fimGlobal - inicioGlobal);
}


void execucaoConcorrente() {

	printf("\n\nRESULTADOS CONCORRENTE: \n\n");
	GET_TIME(inicioGlobal);
	
	GET_TIME(inicio);
	printf("Integral de a(x) = 1 + x ==> %f\n", integralConcorrente(a, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	if(intervalo_a < -1 || intervalo_b > 1) {
		printf("A função b(x) = sqrt(1 - x²) só está definida no intervalo -1 < x < 1\n\n");
	}
	else {
		GET_TIME(inicio);
		printf("Integral de b(x) = sqrt(1 - x²) ==> %f\n", integralConcorrente(b, intervalo_a, intervalo_b));
		GET_TIME(fim);
		printf("Tempo necessário: %f\n\n", fim - inicio);
	}

	GET_TIME(inicio);
	printf("Integral de c(x) = sqrt(1 + x⁴) ==> %f\n", integralConcorrente(c, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	GET_TIME(inicio);
	printf("Integral de d(x) = sen(x²) ==> %f\n", integralConcorrente(d, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	GET_TIME(inicio);
	printf("Integral de e(x) = cos(e^-x) ==> %f\n", integralConcorrente(e, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	GET_TIME(inicio);
	printf("Integral de f(x) = cos(e^-x) * x ==> %f\n", integralConcorrente(f, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	GET_TIME(inicio);
	printf("Integral de g(x) = cos(e^-x) * (0.005 * cos(x³) + 1) ==> %f\n", integralConcorrente(g, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	GET_TIME(fimGlobal);
	printf("Tempo necessário para o cálculo de todas as funções: %f\n\n", fimGlobal - inicioGlobal);
}


void execucaoConcorrenteDesbalanceada() {

	printf("\n\nRESULTADOS CONCORRENTE DESBALANCEADA RECURSIVA: \n\n");
	GET_TIME(inicioGlobal);
	
	GET_TIME(inicio);
	printf("Integral de a(x) = 1 + x ==> %f\n", integralConcorrenteDesbalanceadaRecursiva(a, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	if(intervalo_a < -1 || intervalo_b > 1) {
		printf("A função b(x) = sqrt(1 - x²) só está definida no intervalo -1 < x < 1\n\n");
	}
	else {
		GET_TIME(inicio);
		printf("Integral de b(x) = sqrt(1 - x²) ==> %f\n", integralConcorrenteDesbalanceadaRecursiva(b, intervalo_a, intervalo_b));
		GET_TIME(fim);
		printf("Tempo necessário: %f\n\n", fim - inicio);
	}

	GET_TIME(inicio);
	printf("Integral de c(x) = sqrt(1 + x⁴) ==> %f\n", integralConcorrenteDesbalanceadaRecursiva(c, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	GET_TIME(inicio);
	printf("Integral de d(x) = sen(x²) ==> %f\n", integralConcorrenteDesbalanceadaRecursiva(d, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	GET_TIME(inicio);
	printf("Integral de e(x) = cos(e^-x) ==> %f\n", integralConcorrenteDesbalanceadaRecursiva(e, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	GET_TIME(inicio);
	printf("Integral de f(x) = cos(e^-x) * x ==> %f\n", integralConcorrenteDesbalanceadaRecursiva(f, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	GET_TIME(inicio);
	printf("Integral de g(x) = cos(e^-x) * (0.005 * cos(x³) + 1) ==> %f\n", integralConcorrenteDesbalanceadaRecursiva(g, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	GET_TIME(fimGlobal);
	printf("Tempo necessário para o cálculo de todas as funções: %f\n\n", fimGlobal - inicioGlobal);
}


void execucaoComparativa() {
	
	printf("\n      --- Integral de a(x) = 1 + x ---\n\n");
	GET_TIME(inicio);
	printf("Algoritmo SEQUENCIAL:  Resultado ==> %f   ---   ", integralRecursiva(a, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n", fim - inicio);
	GET_TIME(inicio);
	printf("Algoritmo CONCORRENTE: Resultado ==> %f   ---   ", integralConcorrente(a, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	printf("\n      --- Integral de b(x) = sqrt(1 - x²) ---\n\n");
	if(intervalo_a < -1 || intervalo_b > 1) {
		printf("A função b(x) = sqrt(1 - x²) só está definida no intervalo -1 < x < 1\n\n");
	}
	else {
		GET_TIME(inicio);
		printf("Algoritmo SEQUENCIAL:  Resultado ==> %f   ---   ", integralRecursiva(b, intervalo_a, intervalo_b));
		GET_TIME(fim);
		printf("Tempo necessário: %f\n", fim - inicio);
		GET_TIME(inicio);
		printf("Algoritmo CONCORRENTE: Resultado ==> %f   ---   ", integralConcorrente(b, intervalo_a, intervalo_b));
		GET_TIME(fim);
		printf("Tempo necessário: %f\n\n", fim - inicio);
	}

	printf("\n      --- Integral de c(x) = sqrt(1 + x⁴) ---\n\n");
	GET_TIME(inicio);
	printf("Algoritmo SEQUENCIAL:  Resultado ==> %f   ---   ", integralRecursiva(c, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n", fim - inicio);
	GET_TIME(inicio);
	printf("Algoritmo CONCORRENTE: Resultado ==> %f   ---   ", integralConcorrente(c, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	printf("\n      --- Integral de d(x) = sen(x²) ---\n\n");
	GET_TIME(inicio);
	printf("Algoritmo SEQUENCIAL:  Resultado ==> %f   ---   ", integralRecursiva(d, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n", fim - inicio);
	GET_TIME(inicio);
	printf("Algoritmo CONCORRENTE: Resultado ==> %f   ---   ", integralConcorrente(d, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	printf("\n      --- Integral de e(x) = cos(e^-x) ---\n\n");
	GET_TIME(inicio);
	printf("Algoritmo SEQUENCIAL:  Resultado ==> %f   ---   ", integralRecursiva(e, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n", fim - inicio);
	GET_TIME(inicio);
	printf("Algoritmo CONCORRENTE: Resultado ==> %f   ---   ", integralConcorrente(e, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);
	
	printf("\n      --- Integral de f(x) = cos(e^-x) ---\n\n");
	GET_TIME(inicio);
	printf("Algoritmo SEQUENCIAL:  Resultado ==> %f   ---   ", integralRecursiva(f, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n", fim - inicio);
	GET_TIME(inicio);
	printf("Algoritmo CONCORRENTE: Resultado ==> %f   ---   ", integralConcorrente(f, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);

	printf("\n      --- Integral de g(x) = cos(e^-x) * (0.005 * cos(x³) + 1) ---\n\n");
	GET_TIME(inicio);
	printf("Algoritmo SEQUENCIAL:  Resultado ==> %f   ---   ", integralRecursiva(g, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n", fim - inicio);
	GET_TIME(inicio);
	printf("Algoritmo CONCORRENTE: Resultado ==> %f   ---   ", integralConcorrente(g, intervalo_a, intervalo_b));
	GET_TIME(fim);
	printf("Tempo necessário: %f\n\n", fim - inicio);
}