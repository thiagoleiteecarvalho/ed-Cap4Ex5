/*
 * main.c
 * Resposta do exercício 5 do capítulo 4.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void) {

	char aux;

	Pilha *pilha_inicial = iniciar();
	Pilha *pilha_auxiliar = iniciar();
	Pilha *pilha_resultante = iniciar();

	push(pilha_inicial, '@');
	push(pilha_inicial, '&');
	push(pilha_inicial, '@');
	push(pilha_inicial, '#');
	push(pilha_inicial, '%');
	push(pilha_inicial, '&');
	push(pilha_inicial, '$');

	exibir(pilha_inicial);

	do {
		char topo_inicial = top(pilha_inicial);

		while (!empty(pilha_inicial)) {

			char topo_corrente = top(pilha_inicial);

			if (topo_inicial == topo_corrente) {
				aux = pop(pilha_inicial);
			} else {
				aux = pop(pilha_inicial);
				push(pilha_auxiliar, aux);
			}
		}

		push(pilha_resultante, topo_inicial);

		while (!empty(pilha_auxiliar)) {
			aux = pop(pilha_auxiliar);
			push(pilha_inicial, aux);
		}
	} while (!empty(pilha_inicial));

	while (!empty(pilha_resultante)) {
		aux = pop(pilha_resultante);
		push(pilha_inicial, aux);
	}

	exibir(pilha_inicial);

}
