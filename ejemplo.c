#include "src/abb.h"
#include <stdio.h>

typedef struct cosa {
	int clave;
	char contenido[10];
} cosa;

cosa *crear_cosa(int clave)
{
	cosa *c = (cosa *)malloc(sizeof(cosa));
	if (c)
		c->clave = clave;
	return c;
}

void destruir_cosa(cosa *c)
{
	free(c);
}

int comparar_cosas(void *c1, void *c2)
{
	cosa *cosa1 = c1;
	cosa *cosa2 = c2;
	return cosa1->clave - cosa2->clave;
}

void destructor_de_cosas(void *c)
{
	cosa *cosa = c;
	if (!cosa)
		printf("El destructor del árbol intenta destruir una cosa NULL D:\n");
	else {
		printf("El destructor del árbol destruye una cosa con clave %d\n",
		       cosa->clave);
		destruir_cosa(c);
	}
}

bool mostrar_elemento(void *elemento, void *extra)
{
	extra = extra; //para que no se queje el compilador, gracias -Werror -Wall
	if (elemento)
		printf("%i ", ((cosa *)elemento)->clave);
	return true;
}

bool mostrar_hasta_5(void *elemento, void *extra)
{
	extra = extra; //para que no se queje el compilador, gracias -Werror -Wall
	if (elemento) {
		printf("%i ", ((cosa *)elemento)->clave);
		if (((cosa *)elemento)->clave == 5)
			return false;
	}
	return true;
}

bool mostrar_acumulado(void *elemento, void *extra)
{
	if (elemento && extra) {
		*(int *)extra += ((cosa *)elemento)->clave;
		printf("%i ", *(int *)extra);
	}
	return true;
}

int main()
{
	abb_t *arbol = abb_crear(comparar_cosas);

	cosa *c1 = crear_cosa(1);
	cosa *c2 = crear_cosa(2);
	cosa *c3 = crear_cosa(3);
	cosa *c4 = crear_cosa(4);
	cosa *c5 = crear_cosa(5);
	cosa *c6 = crear_cosa(6);
	cosa *c7 = crear_cosa(7);
	cosa *auxiliar = crear_cosa(0);

	abb_insertar(arbol, c4);
	abb_insertar(arbol, c2);
	abb_insertar(arbol, c6);
	abb_insertar(arbol, c1);
	abb_insertar(arbol, c3);
	abb_insertar(arbol, c5);
	abb_insertar(arbol, c7);

	printf("El arbol tiene %zu elementos, debería tener 7\n",
	       abb_tamanio(arbol));

	auxiliar->clave = 5;
	printf("Busco el elemento 5: %s\n",
	       abb_buscar(arbol, auxiliar) == c5 ? "OK" : "ERROR");

	auxiliar->clave = 7;
	printf("Quito nodo hoja (7): %s\n",
	       abb_quitar(arbol, auxiliar) == c7 ? "OK" : "ERROR");
	destruir_cosa(c7);

	printf("El arbol tiene %zu elementos, debería tener 6\n",
	       abb_tamanio(arbol));

	auxiliar->clave = 6;
	printf("Quito nodo con un hijo (6): %s\n",
	       abb_quitar(arbol, auxiliar) == c6 ? "OK" : "ERROR");
	destruir_cosa(c6);

	printf("El arbol tiene %zu elementos, debería tener 5\n",
	       abb_tamanio(arbol));

	auxiliar->clave = 2;
	printf("Quito nodo con dos hijos (2): %s\n",
	       abb_quitar(arbol, auxiliar) == c2 ? "OK" : "ERROR");
	destruir_cosa(c2);

	printf("El arbol tiene %zu elementos, debería tener 4\n",
	       abb_tamanio(arbol));

	auxiliar->clave = 4;
	printf("Quito la raiz (4): %s\n",
	       abb_quitar(arbol, auxiliar) == c4 ? "OK" : "ERROR");
	destruir_cosa(c4);

	printf("El arbol tiene %zu elementos, debería tener 3\n",
	       abb_tamanio(arbol));

	auxiliar->clave = 3;
	printf("Busco el elemento 3: %s\n",
	       abb_buscar(arbol, auxiliar) == c3 ? "OK" : "ERROR");

	destruir_cosa(auxiliar);

	cosa *elementos[10];

	printf("Recorrido inorden (deberian salir en orden 1 3 5): ");
	size_t cantidad = abb_recorrer(arbol, INORDEN, (void **)elementos, 10);
	for (size_t i = 0; i < cantidad; i++)
		printf("%i ", elementos[i]->clave);
	printf("\n");

	printf("\n\nInserto mas valores y pruebo el iterador interno\n\n");
	abb_insertar(arbol, crear_cosa(15));
	abb_insertar(arbol, crear_cosa(0));
	abb_insertar(arbol, crear_cosa(9));
	abb_insertar(arbol, crear_cosa(7));
	abb_insertar(arbol, crear_cosa(4));

	printf("Recorrido inorden iterador interno: ");
	abb_con_cada_elemento(arbol, INORDEN, mostrar_elemento, NULL);
	printf("\n");

	printf("Recorrido preorden iterador interno: ");
	abb_con_cada_elemento(arbol, PREORDEN, mostrar_elemento, NULL);
	printf("\n");

	printf("Recorrido postorden iterador interno: ");
	abb_con_cada_elemento(arbol, POSTORDEN, mostrar_elemento, NULL);
	printf("\n");

	printf("\nRecorrido inorden hasta encontrar el 5: ");
	abb_con_cada_elemento(arbol, INORDEN, mostrar_hasta_5, NULL);
	printf("\n");

	printf("Recorrido preorden hasta encontrar el 5: ");
	abb_con_cada_elemento(arbol, PREORDEN, mostrar_hasta_5, NULL);
	printf("\n");

	printf("Recorrido postorden hasta encontrar el 5: ");
	abb_con_cada_elemento(arbol, POSTORDEN, mostrar_hasta_5, NULL);
	printf("\n");

	int acumulador = 0;
	printf("\nRecorrido inorden acumulando los valores: ");
	abb_con_cada_elemento(arbol, INORDEN, mostrar_acumulado, &acumulador);
	printf("\n");

	acumulador = 0;
	printf("Recorrido preorden acumulando los valores: ");
	abb_con_cada_elemento(arbol, PREORDEN, mostrar_acumulado, &acumulador);
	printf("\n");

	acumulador = 0;
	printf("Recorrido postorden acumulando los valores: ");
	abb_con_cada_elemento(arbol, POSTORDEN, mostrar_acumulado, &acumulador);
	printf("\n\n");

	abb_destruir_todo(arbol, destructor_de_cosas);
	return 0;
}
