/*Practica de variables 
  nombre:Santiago Escobar Celedon 
  curso de programacion
  objetivos: Declare un variable tipo float, sin inicializar, e imprima su valor
             
             Declare una variable tipo bool, la inicialize en false e imprima la  variables

	     Declare una variable tipo double e imprima su direccion de memoria (use el operador & justo antes de la variable al imprimirla) y los bytes que ocupa                 (use el operador sizeof, basicamente debe escribir sizeof(double))
	     
	     Declare una variable tipo float con el valor inicial 1.0e40 e imprimala a la pantalla: ¿porque cree que imprime eso? Coloquelo como comentario en el                  codigo*/

#include <iostream>
int main()
{
 float A, D=1.0e40;
 bool  B{false};
 double C=3.14, E=1.0e40;

 std::cout<< "Variable tipo float sin inicializar: "<<A <<std::endl;
 std::cout<< "Variable tipo bool inicializada en false "<<B <<std::endl ;
 std::cout<< "Variable tipo double "<<C << "su direccion de memoria "<<&C <<" Bytes que ocupa "<<sizeof(double) <<std::endl;
 std::cout<< "variable tipo float inicializada con el valor 1.0e40 "<<D <<std::endl;//lo que aparece en el codigo es un inf el cual probablemente haga referencia al infinito lo que puede significar que puede que el valor haya excedido la cantidad que puede ser representado por la variable
 std::cout<< "Una variable tipo double si puede representar el valor " <<E <<std::endl;
 std::cout<< "lo anterior es debido a que la cantidad de bytes que ocupa una variable float es de "<< sizeof(float) <<"\n" <<"mientras que una variable double ocupa " <<sizeof(double) <<" por lo que la variable double tendra mas espacio para ocupar este tipo de valores";
 return 0;
 
  
    }

            
