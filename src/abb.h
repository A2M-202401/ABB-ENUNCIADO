#ifndef __ABB__H__
#define __ABB__H__

#include <stdbool.h>
#include <stdlib.h>

typedef enum { INORDEN, PREORDEN, POSTORDEN } abb_recorrido;

/**
 * Comparador de elementos. Recibe dos elementos y devuelve 0 en caso de ser
 * iguales, >0 si el primer elemento es mayor al segundo o <0 si el primer
 * elemento es menor al segundo.
 */
typedef int (*abb_comparador)(void *, void *);

typedef struct nodo_abb nodo_abb_t;

typedef struct abb abb_t;

/**
 * Crea un arbol binario de búsqueda. Comparador es una función que se utiliza
 * para comparar dos elementos. La funcion de comparación no puede ser nula.
 *
 * Devuelve un puntero al arbol creado o NULL en caso de error.
 */
abb_t *abb_crear(abb_comparador comparador);

/**
 * Inserta un elemento en el arbol.
 * El arbol admite elementos con valores repetidos.
 *
 * Devuelve el arbol en caso de exito o NULL en caso de error.
 */
abb_t *abb_insertar(abb_t *arbol, void *elemento);

/**
 * Busca en el arbol un elemento igual al provisto (utilizando la funcion de
 * comparación) y si lo encuentra lo quita del arbol y lo devuelve.
 *
 * (Recordá que en este caso, las pruebas de chanutron suponen que al eliminar
 * con dos hijos, se reemplaza el nodo con el predecesor inorden.)
 *
 * Devuelve el elemento extraido del árbol o NULL en caso de error.
 */
void *abb_quitar(abb_t *arbol, void *elemento);

/**
 * Busca en el arbol un elemento igual al provisto (utilizando la
 * funcion de comparación).
 *
 * Devuelve el elemento encontrado o NULL si no lo encuentra.
 */
void *abb_buscar(abb_t *arbol, void *elemento);

/**
 * Determina si el árbol está vacío.
 *
 * Devuelve true si está vacío o el arbol es NULL, false si el árbol tiene al
 * menos un elemento.
 */
bool abb_vacio(abb_t *arbol);

/**
 * Devuelve la cantidad de elementos almacenados en el arbol o 0 si el arbol es
 * NULL.
 */
size_t abb_tamanio(abb_t *arbol);

/**
 * Recorre el arbol e invoca la funcion con cada elemento almacenado en el mismo
 * como primer parámetro. El puntero aux se pasa como segundo parámetro a la
 * función. Si la función devuelve false, se finaliza el recorrido aun si quedan
 * elementos por recorrer. Si devuelve true se sigue recorriendo mientras queden
 * elementos.
 *
 * Recorrido especifica el tipo de recorrido a realizar.
 *
 * Devuelve la cantidad de veces que fue invocada la función.
*/
size_t abb_con_cada_elemento(abb_t *arbol, abb_recorrido recorrido,
			     bool (*funcion)(void *, void *), void *aux);

/**
 * Recorre el arbol según el recorrido especificado y va almacenando los
 * elementos en el array hasta completar el recorrido o quedarse sin espacio en
 * el array.
 *
 * El array tiene un tamaño maximo especificado por tamanio_array.
 *
 * Devuelve la cantidad de elementos que fueron almacenados exitosamente en el
 * array.
 */
size_t abb_recorrer(abb_t *arbol, abb_recorrido recorrido, void **array,
		    size_t tamanio_array);

/**
 * Destruye el arbol liberando la memoria reservada por el mismo.
 */
void abb_destruir(abb_t *arbol);

/**
 * Destruye el arbol liberando la memoria reservada por el mismo.
 *
 * Adicionalmente invoca el destructor en cada uno de los elementos almacenados
 * en el arbol (si la funcion destructor no es NULL).
 */
void abb_destruir_todo(abb_t *arbol, void (*destructor)(void *));

#endif /* __ABB__H__ */
