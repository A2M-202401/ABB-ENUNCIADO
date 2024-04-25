#include "pa2m.h"

void prueba_simple()
{
	int i = 14;
	int j = 18;
	pa2m_afirmar(i != j, "i=14 es diferente de j=16");
}

int main()
{
	pa2m_nuevo_grupo(
		"\n======================== XXX ========================");
	prueba_simple();

	return pa2m_mostrar_reporte();
}
