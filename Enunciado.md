# Árbol Binario de Búsqueda

Se pide implementar una Árbol Binario de Búsqueda (ABB) en el lenguaje
de programación C. Para ello se brindan las firmas de las funciones
públicas a implementar y **se deja a criterio del alumno la creación de
las funciones privadas del TDA** para el correcto funcionamiento del
**ABB** cumpliendo con las buenas prácticas de programación.
Adicionalmente se pide la creación de un iterador interno que sea capaz
de realizar diferentes recorridos en el árbol y una funcione que guarda
la información almacenada en el árbol en un vector.

El TDA entregado deberá compilar y **pasar las pruebas dispuestas por la 
cátedra sin errores**, adicionalmente estas pruebas deberán ser ejecutadas
sin pérdida de memoria.

A **modo de demostración**, se brindará al alumno un archivo simple de
"ejemplo". **Este archivo no es mas que un programa mínimo de ejemplo de
utilización del TDA a implementar** y es provisto sólo a fines
ilustrativos como una ayuda extra para entender el funcionamiento del
mismo. No es necesario modificar ni entregar el archivo de minidemo,
pero si la implementación es correcta, debería correr con valgrind sin
errores de memoria.

Para la resolución de este trabajo se recomienda utilizar una
**metodología orientada a pruebas**. A tal fín, se incluye un archivo
**pruebas_alumno.c** que debe ser completado con las pruebas pertinentes de
cada una de las diferentes primitivas del TDA. **El archivo de pruebas
forma parte de la entrega y por lo tanto de la nota final.** Aún mas
importante, las pruebas van a resultar fundamentales para lograr no
sólamente una implementación correcta, si no también una experiencia de
desarrollo menos turbulenta.

# Aclaraciones de la implementación

Esta implementación de **ABB** incluye una función de comparación que
permite insertar cualquier tipo de puntero en el mismo. **El ABB no
tiene idea de qué es lo que almacena el usuario**, simplemente es un
contenedor de datos que sigue reglas definidas. Mediante el comparador
el **ABB** es capaz de establecer la relación de orden de los diferentes
punteros, sin necesidad de tener información extra. **Recuerde que los
comparadores devuelven 0, >0 o <0** según la relación de los elementos comparados
(no necesariamente 0, 1, -1).

Otra característica distintiva de esta implementación es el uso de
**funciones de destrucción**. Recuerde que el **ABB** no es mas que un
contenedor de datos y no conoce nada acerca del contenido del mismo.
Recuerde también que en **C**, quien reserva la memoria es el
responsable de liberarla. Brindándole una función de destrucción al
**ABB**, podemos pedirle al mismo que se haga cargo de destruir los
elementos que almacena una vez que este es destruido. Tenga en cuenta
que si el usuario de la implementación no quiere delegar esta
responsabilidad al **ABB** puede pasarle una función de destrucción
**NULL** o directamente invocar al destructor simple.

Por último, tenga en cuenta que las pruebas de de la cátedra suponen
que la implementación acomoda **los elementos menores del ABB del lado
izquierdo y los mayores del lado derecho**, y que al borrar nodos con dos
hijos no nulos, **se reemplaza dicho nodo con el predecesor inorden**.

Si bien no es usual hacerlo, las pruebas de la cátedra verifican la integridad de la estructura del **ABB**, por este motivo se incluye un archivo *.h* separado con la definición de la estructura interna.

# Consejos para la elaboración del trabajo
**NO** escriba código a lo loco sin compilar cada tanto. Implemente la
solución de a poco y compilando a cada paso. Dejar la compilación para
el final es uno de los peores errores que puede cometer. Para la
compilación del trabajo se provee un **Makefile**. Utilice el comando
**make** frecuentemente para compilar y correr su programa.

**NO** avance en la implementación si le quedan errores sin resolver en
alguna prueba. Cada vez que escriba una prueba implemente toda la
funcionalidad necesaria para que funcione correctamente. Esto incluye
liberar memoria y accesos inválidos a la misma. Sólamente una vez que
haya logrado que la prueba pase exitosamente es que puede comenzar a
escribir la próxima prueba para continuar el trabajo.

**NO** está permitido modificar los archivos **.h**.

# A incluír en el informe

-   Explique teóricamente (y utilizando gráficos) qué es una árbol, árbol binario y árbol
    binario de búsqueda. Explique cómo funcionan, cuáles son sus operaciones básicas
    (incluyendo el análisis de complejidad de cada una de ellas) y por qué es
    importante la distinción de cada uno de estos diferentes tipos de
    árboles. Ayúdese con diagramas para explicar.

-   Explique su implementación y decisiones de diseño (por ejemplo, si
    tal o cuál funciones se plantearon de forma recursiva, iterativa o
    mixta y por qué, que dificultades encontró al manejar los nodos y
    punteros, reservar y liberar memoria, etc).
