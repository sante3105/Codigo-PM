#include <iostream>
#include <cmath>
#include <cstdlib>

double f(double x);
template <class fptr>
double bisection(double xl, double xu, fptr fun, double eps, int & niter);

int main(int argc, char **argv)
{
  std::cout.precision(16); std::cout.setf(std::ios::scientific);
  
  const double XL = std::atof(argv[1]);
  const double XU = std::atof(argv[2]);

  int counter = 0;
  for(double Eps=0.1; Eps>=1.0e-8;){
  std::cout << bisection(XL, XU, f, Eps,counter) << "\t";
  std::cout << Eps<< "\t";
  std::cout << counter << "\n";
  Eps=Eps/10;
  }
  return 0;
}

double f(double x)
{
  return 9.81*(68.1)*(1 - std::exp(-x*10/68.1))/x - 40;
}

template <class fptr>
double bisection(double xl, double xu, fptr fun, double eps, int & niter)
{
 double  xr=(xl+xu)/2;
  if(std::fabs(fun(xr))<=eps)
    {
    return xr;
    }
    else
      if(fun(xr)*fun(xl)<0)
	{
	niter++;
	return	bisection(xr,xl,fun,eps,niter);
	}
	else
	  niter++;
	return	bisection(xu,xr,fun,eps,niter);
}
