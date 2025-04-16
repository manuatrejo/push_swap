/*
según voy haciendo los bloques tengo que delimitarlos e ir haciendo los movimientos 

lo mejor que puedo hacer para tener las ideas claras es seguir el algoritmo

primera fase todo al b menos el último bloque 

1 saber donde está la mitad y para el b los bajos, para saber la mitad que si son 16 el octavo es el séptimo índice que es un n/2 -1

una  vez marcado el primer límite cuando esté comparando los elementos 

el problema aquí pasa a ser que el índice no es el delimitador, el limitador es que hay un índice por debajo del límite, me refiero a que como están desordenados dentro del bloque no se sabe cuando deja de

pertenecer un número a este grupo hasta que abajo hay un número que ya no pertenece entonces se puede marcar el índice que pone el límite incluyéndolo en uno de los dos grupos ese índice ya veré como lo hago

para facilitar el proceso de comparación lo máximo posible se puede tener dos valores de índice guardados: 

EL INDICE MEDIO DE EL STACK Y EL INDICE DEL NÚMERO MÁS BAJO

puedo definir los bloques cuando los separe o puedo comprobar luego donde está la separación entre bloques pero como podría hacer esto?

en dos bloques separados si o si hay un salto ordenado de índice y no se vuelve atrás desde ahí




ejemplos: en un  stack de 300 se empieza a empujar los menores a 150, siempre vamos a tener el índice mayor y 

puedo hacer una función que tenga de input los límites de un bloque y se puede ejecutar de forma recursiva hasta que esté todo el bloque en el otro stack

otra función para medir distancias hasta números que luego seguro que va a ser útil para optimizar y llevar directamente números a donde les toca

y luego hacer funciones intermedias que ayuden siempre a cosas concretas o que en general ahorren movimientos en todos los casos vigilando siempre bien que ayuden en todos los casos que se use

otra función para cuando tenga los bloques 1 y 4 aislados en cada stack y dividirlo recursivamente para ahorrar movimientos

entonces lo mejor seguramente sea marcar los límites con una flag, buscar las flags antes de dividir un bloque y guardarlas en una función


recapitulando: una función para empujar al otro stack dividiendo stacks desde el número mayor del actual, tiene que buscar el índice inferior con flag y desde el actual calcular hasta qué índice es la 
mitad del stack y a partir de aquí empujar los elementos dependiendo de a donde vayan de una forma u otra manejar el código para que se puedan manda del a al b o del b al a, además 
marcar los índices que delimiten los bloques antes de que termine la función

tengo que hacer al menos una vez la división recurrente de bloques

es conveniente que en el código que haga se puedan añadir casos para el caso de tener que optimizarlo

por cada cambio de stack que haga un elemento hará de media dos movimientos, teniendo esto en cuenta si mis stacks son de 125 pueden cambiar de lista hasta siete veces que serían 14 movimientos por elemento
así que cuando el siguiente elemento mayor de la lista b esté a menos de 7 posiciones supondrá un ahorro, esto se podría aplicar cuando está ordenado el stack contrario y habría que redefinir el límite
esto aplicarlo con una distancia menor ya que en casos con menos elementos podría añadir más movimientos de los necesarios

además, al pasar de un stack a otro si después de un push encaja un swapr hacerlo Y SI AL SEGUNDO DE A HAY QUE PUSH ENTONCES SWAPA-R Y PUSH 

si hago ese swap los mayores van a tender a estar abajo en a y arriba en b pero para el caso de que estén abajo como los muevo para no desperdiciar movimientos?
lo mejor es rotarlos en un distinto stack después del push

siempre que se encuentre el índice siguiente al menor ordenado lo mejor es rotarlo al fondo del stack y cuando termine la división ponerlo, esto en caso de que no se ordene con un pusha
si rotamos en la misma lista esto no se podría
pero esto depende de si es el menor ordenado del a o el mayor ordenado del b y de si el elemento está en el stack objetivo o el otro
si está en el stack objetivo mejor manda el resto a el otro y rotarlos ahí, si no está en el objetivo hacerlo al revés 


resumen final: empieza, manda 2 mitades menores al b, manda mitad menor de lo que queda en a al b, manda recursivamente la mitad de lo que le queda hasta que le quede un grupo de cuatro o menor, lo ordena
y coloca ordenadamente los stacks que hay encima del b.
manda al a divididos todos los bloques del b menos el último del cual manda recursivamente sus mitades hasta que quede un grupo de 4 o menos el cual ordena y pone encima los siguientes elementos que 
estén en el top del a
manda dividido todo lo que no esté ordenado al b y al a y así recursivamente hasta que los grupos no sean mayores de 4-8 y si a y b están ordenados hasta el mismo índice hace pushb hasta que se vacíe

*/
#include "push_swap.h"

void	algorithm(t_list **stack_a, t_list **stack_b)
{
/*vamos a echarle una pensadita rápida, para pasar dividiendo usar los flags

es más fácil que haya un límite o dos?
en el caso de que haya uno qué problemas puedo tener
creo que ninguno, solo con un límite se puede hacer, entonces usar dos es
complicarlo

si uso uno como lo hago? lo más facil es hacer size / 2
con una función específica para que vaya buscando límites y marcando ese índice
y para hacerlo fácil simplemente dejo el substack pequeño con un elemento menos

después de saber el límite del substack es solo push o push rotate y
dejar guardado el número de rotates para luego

*/
}

void	three_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		limit1;
	int		limit2;

	limit1 = make_one_limit(&stack_a);
	limit2 = make_one_limit(&stack_a);
	temp = *stack_a;
	while (temp)
	{
		if (temp->content <= limit1 && limit2 > temp->content)
			pb(&stack_a, &stack_b);
		else if (temp->content <= limit1 && limit2 <= temp->content)
			(pb(&stack_a, &stack_b), rb(&stack_b));
		else
			ra(&stack_a);
		temp = temp->next;
	}
	sort_biggest(&stack_a, &stack_b);
	if ((*stack_b)->flag == 1)
		(*stack_b)->flag = 0;
}

void	triplicate_b_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		*limits[2];

	*limits = make_two_limits(&stack_b);
	temp = *stack_a;
	while (temp)
	{
		if (temp->content <= limits[0] && temp->content > limits[1])
			pb(&stack_a, &stack_b);
		else if (temp->content <= limit1 && temp->content <= limit2)
			(pb(&stack_a, &stack_b), rb(&stack_b));
		else
			ra(&stack_a);
		temp = temp->next;
	}

}

void	triplicate_a_to_b(t_list **stack_a, t_list **stack_b)
{

}

void	sort_biggest(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		limit;
	//hacer límite y dividir hasta que dos grupos =< 4
	//que es llamar recurrentemente a duplicate_a_to_b
	while (stack_size(&stack_a) > 2)
	{
		limit = make_one_limit(&stack_a);
		if (temp->content <= limit)
			pb(&stack_a, &stack_b);
		else
			ra(&stack_a);
		temp = temp->next;
	}
}

void	sort_lowest(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		limit;
	//hacer límite y dividir hasta que dos grupos =< 4
	//que es llamar recurrentemente a duplicate_a_to_b
	while (stack_size(&stack_b) > 2)
	{
		limit = make_one_limit(&stack_b);
		if (temp->content <= limit)
			pa(&stack_b, &stack_a);
		else
			rb(&stack_b);
		temp = temp->next;
	}
}

int	*make_two_limits(t_list **stack )
{
	t_list	*temp;
	int		size;
	int		*limits[2];
	int		limit;

	size = stack_size(stack);
	while (temp)
	{
		if (temp->flag == 1)
			limit = temp->content;
		if (temp->flag == 1)
			break;
		temp = temp->next;
	}
	if (limit > (*stack)->content)
	{
		limits[0] = put_flag(&stack, limit - (size / 3));
		limits[1] = put_flag(&stack, limit - (size / 3 * 2));
	}
	else
	{
		limits[0] = put_flag(&stack, limit + (size / 3));
		limits[1] = put_flag(&stack, limit + (size / 3 * 2));
	}
	return (limits);
}

int	make_one_limit(t_list **stack)
{
	t_list	*temp;
	int		size;
	int		limit;
	int		new_limit;

	size = stack_size(stack);
	while (temp)
	{
		if (temp->flag == 1)
		{
			limit = temp->content;
			break;
		}
		temp = temp->next;
	}
	if (limit > (*stack)->content)
		new_limit = put_flag(&stack, limit - (size / 2));
	else
		new_limit = put_flag(&stack, limit + (size / 2));
	return (new_limit);
}

int	stack_size(t_list *stack)
{
	t_list	*temp;
	int		size;

	temp = stack;
	size = 0;
	while (temp)
	{
		size++;
		if (temp->flag == 1)
			break;
	}
	if (size == 0)
		return (-1);
	return (size);
}

int	put_flag(t_list **stack, int index)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		if (index == temp->content)
			{
				temp->flag = 1;
				return (temp->content);
			}
		temp = temp->next;
	}
}

void	sort_triplicating_b_to_a(t_list **stack_a, t_list **stack_b)
{

}

void	sort_triplicating_a_to_b(t_list **stack_a, t_list **stack_b)
{

}

void	intermediate_steps(t_list **stack_a, t_list **stack_b)
{

}

void	simple_sort(t_list **list)
{
	if (lst_size(list) == 3)
	{
		if ((*list)->content - 2 == (*list)->next->content
			|| (*list)->content - 2 == (*list)->next->next->content)
			ra(&list);
		else if ((*list)->next->content - 2 == (*list)->content
			|| (*list)->next->content - 2 == (*list)->content)
			rra(&list);
	}
	else if (lst_size(list) == 4 || lst_size(list) == 5)
	{
		while (lst_size(list) > 3)
		{
			if ((*list)->content < 2)
				pb(&list);
			else
				ra(&list);
		}
		simple_sort(&list);
		pa(&list);
	}
	if (!is_sorted(&list))
		sa(&list);
}
