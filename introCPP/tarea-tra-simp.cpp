/*Una fuerza variable de forma F⃗ =(2xsin(x),−24) N actúa sobre un cuerpo. El desplazamiento del mismo está dado por d⃗ =(4,0) m. Si la masa del cuerpo es m=1.25 Kg, calcule la rapidez final de la partícula asumiendo que esta es la única fuerza presente. Para esto aplique el teorema del trabajo - energía cinética usando integración por trapecio y por simpson con 10 y con 1000 intervalos. Compárelo porcentualmente con el valor exacto. Su programa debe imprimir la diferencia porcentual de cada método con cada uno de los intervalos así:

N1 DeltaTrap1 DeltaSimp1
N2 DeltaTrap2 DeltaSimp2

Del anterior enunciado podemos deducir que el procedimiento a seguir es encontrar  la variacion de la enegia cinetica calculando la integral desde 0 hasta 4 de 2xsin(x) dx y a partir de ahi calcular la rapidez */
#include <cmath>
#include <iostream>
//funciones
double func(double x);
template <typename fptr>
double trapezoid(double a, double b, double h, fptr f);
template <typename fptr>
double simpson(double a, double b, double h, fptr f);
//main
int main()
{std::cout.precision(15); std::cout.setf(std::ios::scientific);
  double Xmin=0,Xmax=4, h=0.4,H=0.004;
  double   exact=2*(std::sin(4)-4*std::cos(4));
  std::cout<<"N1: "<< 10 <<"   Delta trap \t";
  std::cout<< (1-trapezoid(Xmin, Xmax, h, func )/exact)<< "\t";
	      std::cout<<"Delta simp \t";
	      std::cout<<(1-simpson(Xmin, Xmax, h, func)/exact)<<"\n";
  std::cout<<"N2: "<<1000<<" Delta trap \t";
  std::cout<< (1-trapezoid(Xmin, Xmax, H, func )/exact)<< "\t";
	      std::cout<<"Delta simp \t";
	      std::cout<<(1-simpson(Xmin, Xmax, H, func )/exact)<<"\n";
	      std::cout<< "Otros resultados asociados a este problema:\n";
	      std::cout<< "\n";
	      std::cout<< "Resultado mas preciso de la integral \t";
	      std::cout<< simpson(Xmin, Xmax, H, func )<<"\n";
	      std::cout<< "Sabemos que la integral es igual a W=ec, siendo ec la energia cinetica \n";
	      double v=  simpson(Xmin, Xmax, H, func )*2/1.25;
	      std::cout<< "Y ec=(m*v²)/2 entonces v²=" <<v <<"\n";
	      std::cout<< "por lo que v= "<<sqrt(v);
                 
}
double func(double x)
{
  return 2*x*std::sin(x);
}
template <typename fptr>
double trapezoid(double a, double b, double h, fptr f)
{
  const int n = std::floor((b-a)/h); // warning: (b-a)/h not integer
  double result = 0.0;
  for(int ii = 1; ii <= n-1; ++ii) {
    double xi = a + ii*h; // uniform spacing
    result += f(xi);
  }
  result += 0.5*(f(a) + f(b));
  result *= h;
  
return result;
}


  
  
template <typename fptr>
double simpson(double a, double b, double h, fptr f)
{
  const int n = 4/h;
  double result2=0.0;
  double p=f(a);
  double q=f(b);
  double s1=0.0;
  for(int i=1;i<=(n-2)/2;++i){
    double xi=a+2*i*h;
    s1 += f(xi);
  }
 double s2=0.0;
 for(int j=1; j<=(n/2); ++j){
   double xj = a + (2*j-1)*h;
   s2+= f(xj);
 }
result2 =(h/3)*(p+2*(s1)+4*(s2)+q);

 return result2;
}


  
