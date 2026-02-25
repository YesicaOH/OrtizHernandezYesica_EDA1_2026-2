/*Este programa permite ingresar 7 calificaciones de 10 alumnos, haciendo uso de punteros, matrices y funciones
para sus multiples procesos, como es el llenado de la matriz, el calculo del promedio individual de cada estudiante
y el promedio del grupo*/

#include <stdio.h>

void llenarCalificaciones(float matriz[10][7]) //esta funcion nos ayuda a llenar el arreglo
{
    for(int i = 0; i < 10; i++) //este ciclo recorre los alumnos
    {
        printf("\nAlumno %d\n", i+1);

        for(int j = 0; j < 7; j++) //este recorre las calificaciones de los alumnos
        {
            int error; /*hacemos uso de una variable como "bandera" de errores, se declara dentro de la funcion y
            no en la funcion main ya que solo se usa aqui*/

            do {
                error = 0; //la inicializamos en cero dentro del do
                printf("Calificacion %d (0-10): ", j+1);

                if(scanf("%f", &matriz[i][j]) != 1)
                {
                    printf("Dato invalido. El valor debe ser un numero.\n"); /*si el usuario intenta ingresar un dato
                    como char, el programa lo rechaza y vuelve a pedir un dato valido*/
                    while(getchar() != '\n'); /*hacemos uso de getchar para deshacernos de datos "basura" no deseados*/
                    error = 1; //en caso de que haya un error la bandera cambia a 1 para marcarlo
                }
            
                else if(matriz[i][j] < 0 || matriz[i][j] > 10) /*si el usuario intenta ingresar un valor menor a 0  o mayor
                a 10, el programa no lo permite*/
                {
                    printf("La calificacion debe estar entre 0 y 10.\n");
                    error = 1; //nuevamente la bandera indica que hat errores
                }

            } while(error == 1); //este ciclo continuara mientras el usuario continue añadiendo datos erroneos
        }
    }
}

void promedioAlumno(float matriz[10][7], float promedios[10]) //esta funcion hace el calculo del promedio de cada alumno
{
    for(int i = 0; i < 10; i++) //se recorren las filas, cada alumno
    {
        float suma = 0; //se declara una variable que solo se usara aqui

        for(int j = 0; j < 7; j++) //se recorren las calificaciones
        {
            suma += matriz[i][j]; // se van acumulando los valores (las calificaciones de cada alumno)
        }

        promedios[i] = suma / 7; //se obtiene el promedio de cada alumno y se guarda en el arreglo llamado promedios
    }
}

void promedioGrupo(float promedios[10], float *promGrupo) //nos ayuda a obtener el promedio del grupo
{
    float sumaG = 0; //se declara una variable para solo usarla dentro de la funcion

    for(int i = 0; i < 10; i++)
    {
        sumaG += promedios[i]; //acumula solo los promedios ya calculados
    }

    *promGrupo = sumaG / 10; //obtiene el promedio grupal
}

int main()
{
    float calificaciones[10][7]; //se declaran todos los arreglos y variables a utilizar
    float promedios[10];
    float promedioGeneral;

    llenarCalificaciones(calificaciones); //llama a las funciones respetando un orden para que no haya errores
    promedioAlumno(calificaciones, promedios);
    promedioGrupo(promedios, &promedioGeneral);

    printf("\nPromedio de los estudiantes.\n");
    for(int i = 0; i < 10; i++)
    {
        printf("Alumno %d: %.2f\n", i+1, promedios[i]); //se imprimen todos los promedios
    }

    printf("\nPromedio general del grupo: %.2f\n", promedioGeneral); //se imprime el promedio de todo el grupo

    return 0;
}