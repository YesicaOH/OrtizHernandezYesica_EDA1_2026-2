//Este programa es una calculadora con diferentes funciones donde el usuario puede elegir que hacer

#include <stdio.h>

/*se declaran diferentes funciones, que con ayuda del apuntador *res ya sea int o float, podemos "escribir" un valor
directamente en la direccion de memoria de la variable en nuestra funcion main*/
void suma(float a, float b, float *res)
{
    *res = a + b;
}

void resta(float a, float b, float *res)
{
    *res = a - b;
}

void multiplicacion(float a, float b, float *res)
{
    *res = a * b;
}

void division(float a, float b, float *res)
{
    *res = a / b;
}

void modulo(int a, int b, int *res) //se hace uso de una variable int ya que el resultado debe ser el residuo
{
    *res = a % b;
}

void divisionEntera(int a, int b, int *res) //se usa int, como el nombre lo indica, para realizar una division con enteros
{
    *res = a / b;
}

int main()
{
    //se declaran todas las variables a utilizar
    char opcion;
    float num1, num2, resultado;
    int num1Int, num2Int, resultadoInt;

    do //se hace uso de un ciclo do while para que el menu se siga mostando hasta que el usuario decida salir
    {
        printf("\nCALCULADORA\n"); //se imrpime el menu
        printf("a) Suma\n");
        printf("b) Resta\n");
        printf("c) Multiplicacion\n");
        printf("d) Division\n");
        printf("e) Modulo\n");
        printf("f) Division Entera\n");
        printf("g) Salir\n");
        printf("Seleccione una opcion: ");
        scanf(" %c", &opcion); //se lee la opcion que el usuario desea usar

        switch(opcion) /*se usa para tener las multiples opciones, permitiendo el uso de mayusculas y minusculas como 
                        valores validos*/
        {
            case 'a': case 'A':
                printf("Ingrese dos numeros: ");
                if(scanf("%f %f", &num1, &num2) != 2) /*se hace uso de un verificador, donde el usuario debe ingresar
                dos valores, en caso de que uno, o ambos, no sea valido el programa le hace saber al usuario que el tipo
                de dato que esta ingresando no es valido*/
                {
                    printf("Tipo de dato invalido\n");
                    while(getchar() != '\n'); //se limpia el buffer con getchar para evitar mas errores
                    continue;
                }

                suma(num1, num2, &resultado); //se llama a la funcion cuando los datos son validos para realizar la operacion
                printf("El resultado de la suma es: %.2f\n", resultado); //se imprime el resultado
                break; //sale del case y vuelve al menu

            case 'b': case 'B':
                printf("Ingrese dos numeros: ");
                if(scanf("%f %f", &num1, &num2) != 2) //validacion
                {
                    printf("Tipo de dato invalido\n");
                    while(getchar() != '\n'); //limpieza de buffer
                    continue;
                }

                resta(num1, num2, &resultado); //se llama a la funcion
                printf("El resultado de la resta es: %.2f\n", resultado); //se imprime el resultado
                break;

            case 'c': case 'C':
                printf("Ingrese dos numeros: ");
                if(scanf("%f %f", &num1, &num2) != 2) //validacion
                {
                    printf("Tipo de dato invalido\n");
                    while(getchar() != '\n'); //limpieza de buffer
                    continue;
                }

                multiplicacion(num1, num2, &resultado); //se llama a la funcion
                printf("El resultado de la multiplicacion es: %.2f\n", resultado);
                break;

            case 'd': case 'D':
                printf("Ingrese dos numeros: ");
                if(scanf("%f %f", &num1, &num2) != 2) //validacion
                {
                    printf("Tipo de dato invalido\n");
                    while(getchar() != '\n'); //limpieza de buffer
                    continue;
                }

                if(num2 == 0) /*en el caso de las divisiones se restringe que el denominador, no puede ser cero
                ya que no es posible dividir entre cero, lo cual causaria otro error en la ejecucion*/
                {
                    printf("No es posible dividir entre 0\n");
                    continue;
                }

                division(num1, num2, &resultado); //se llama a la funcion
                printf("El resultado de la division es: %.2f\n", resultado);
                break;


            case 'e': case 'E':
                printf("Ingrese dos numeros enteros: ");
                if(scanf("%d %d", &num1Int, &num2Int) != 2) //validacion
                {
                    printf("Tipo de dato invalido\n");
                    while(getchar() != '\n'); //limpieza de buffer
                    continue;
                }

                if(num2Int == 0)
                {
                    printf("No es posible dividir entre 0\n");
                    continue;
                }

                modulo(num1Int, num2Int, &resultadoInt); //se llama a la funcion
                printf("El reusltado del modulo es: %d\n", resultadoInt);
                break;


            case 'f': case 'F':
                printf("Ingrese dos numeros enteros: ");
                if(scanf("%d %d", &num1Int, &num2Int) != 2) //validacion
                {
                    printf("Tipo de dato invalido\n");
                    while(getchar() != '\n'); //limpieza de buffer
                    continue;
                }

                if(num2Int == 0)
                {
                    printf("No es posible dividir entre 0\n");
                    continue;
                }

                divisionEntera(num1Int, num2Int, &resultadoInt); //se llama a la funcion
                printf("El resultado de la division entera es: %d\n", resultadoInt);
                break;


            case 'g': case 'G': //al elegir esta opcion sale del programa
                printf("Adios.\n");
                break;

            default:
                printf("Esta opcion no es valida\n"); //el programa rechaza datos no validos en el menu
        }

    } while(opcion != 'g' && opcion != 'G');

    return 0;
}
