#include <stdlib.h>
#include <stdio.h>

typedef struct s_struct
{
    int tiempo;
    int espacio;
}   t_velocidad;

void    init_vel(t_velocidad *v)
{
    v->tiempo = 1;
    v->espacio = 0;
}

void    set_tiempo(t_velocidad *v, int tiempo)
{
    v->tiempo = tiempo;
}

void    reset_values(t_velocidad *v)
{
    v = malloc(sizeof(t_velocidad));
    v->tiempo = 0;
    v->espacio = 0;
}
void    reset_values(t_velocidad **v)
{
    *v = malloc(sizeof(t_velocidad));
    (*v)->tiempo = 0;
    (**v).tiempo = 0;
    (*v)->espacio = 0;
}

int main(void)
{
    t_velocidad *v;
    v = malloc(sizeof(t_velocidad));
    init_vel(v);
    printf("v tiemmpo: %d\n", v->tiempo);
    set_tiempo(v, 12);
    printf("v tiemmpo: %d\n", v->tiempo);
    reset_values(v);
    printf("v tiemmpo: %d\n", v->tiempo);
}