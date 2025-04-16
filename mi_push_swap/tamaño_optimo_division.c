#include <stdio.h>

int	total_movimientos(int stack, int de5x, int grup_max, int flag)
{
	int stack_resto;
	int stack_inicial;
	static int	movimientos;
	int movimientos_temporales;

	stack_inicial = stack;
	while (stack > grup_max - 1)
	{
		stack_resto = (stack * (grup_max - de5x)) / grup_max;
		stack = (stack * de5x) / grup_max;
		if (stack_resto > grup_max - 1)
		{
			movimientos_temporales += total_movimientos(stack_resto, de5x, grup_max, 1);//empieza el el bucle si el stack es más grande que grupmax
			printf("movimientos actuales = %d\n", movimientos);
		}
		movimientos += stack;
	}
	if (!(stack_resto > grup_max - 1) && flag)
		return (movimientos);
	if (flag)
		return (movimientos);
	movimientos += stack_inicial;
	printf("hace grupos máximos de: %d\n", grup_max);
	printf("de %d conserva  %d\n",grup_max, de5x);
	printf("movimientos totales = %d\n", movimientos);
	return(movimientos);
}

int main()
{
	int de5_conservax = 7;
	int grup_max = 20;
	
	total_movimientos(500, de5_conservax, grup_max, 0);
	return (0);
}
//no puede ser ni demasiado grande ni demasiado pequeño ya que si solo quita un 10% de cada bloque el bloque máximo que dividirá será  10
//los movimientos que hay que hacer depende de cuantas veces haya que dividir ejemplo si sacas 1 de 5 te quedan 2 stacks uno con 1/5 y otro con 4/5 entonces
//al igual que los problemas de probabilidad hay que hacer un arbol de probabilidades y tamaños y de cada rama del stack total salen 2, una con 4/5 partes del stack el final del arbol tendrá: ....
//n / número mínimo de elementos que se sacan cada rama terminará en un punto distinto
// si 1/2 del contenido hace  2**x grupos sin llegar a n que es 2**x-2<=n y cada grupo luego hace 2**x-1-2 así hasta 2**2

//tengo que guardar el número de movimientos cuando el flag es 1 y que se sumen recursivamente
//cada vez que divides