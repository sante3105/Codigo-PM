/*                     tarea 2 de programacion
nombre: Santiago Escobar
Cual es el divisor mas grande del numero N=600851475147, que no sea el mismo N?*/
#include <iostream>

int main()
{
  long long int N, i; //declaramos las variables tipo long long int debido al tamaño de los datos

  for(N=2; N<600851475147; N++) {//Abrimos un loop tipo for inicializado en 2, que tenga como condicion que sea menor al numero N y que vaya creciendo 
	if(600851475147%N==0)
	{i=600851475147/N;
	N=600851475147;
	} /*lo que hacemos en estas lineas es determinar el divisor  mas pequeño de N y sabemos entonces que el divisor  mas pequeño debe multiplicarse por el}               mas grande para que de como resultado N por lo que de esta forma encontramos i, ademas cuando este se encuentra se iguala N a un valor igual o mayor al dato
        problema para cerrar loop creado por el for  */
}
  std::cout<<"El Divisor mas grande del numero 600851475147 es: " <<i;
	return 0;
}
