
#include <iostream>

struct Vector {

  double V[3], S; //se agreag variable S para operaciones que operen vectores y den como resultado escalares

  Vector() {    //Constructor default con valores iniciales El valor inicial de S es un numero que se considera improbable que se obtenga en una operacion
    V[0] = 0;
    V[1] = 0;
    V[2] = 0;
    S = 102667.104729;
  }
  Vector(double X, double Y, double Z) {   //constructor para valores definidos
    V[0] = X;
    V[1] = Y;
    V[2] = Z;
    S = 102667.104729;
  }



  Vector operator+(Vector const &obj) {  //definicion operacion suma de vectores
    Vector v;
    v.V[0] = V[0] + obj.V[0];
    v.V[1] = V[1] + obj.V[1];
    v.V[2] = V[2] + obj.V[2];
    return v;
  }
  Vector operator*(Vector const &obj) { //definicion operacion producto escalar de vectores (se guarda en la variable S)
    Vector v, s;
    v.V[0] = V[0] * obj.V[0];
    v.V[1] = V[1] * obj.V[1];
    v.V[2] = V[2] * obj.V[2];
    s.S = v.V[0] + v.V[1] + v.V[2];
    return s;
  }
  void imprimir() {         //funcion imprimir 
    std::cout << "(";
    if (S != 102667.104729) {
      std::cout << S;
    } else {
      for (int i = 0; i < 3; i++) {
        std::cout << V[i];
        if (i < 2)
          std::cout << ",";
      }
    }
    std::cout << ")";
  }
  ~Vector(){};   //destructor defaul
};

int main() {
  Vector v1(1, 2, 3), v2(4,5, 6);
  std::cout<<"El vector 1 es: ";
  v1.imprimir();
  std::cout<<" y el vector 2 es: ";
  v2.imprimir();
  std::cout<< std::endl;
  Vector v3 = v1 + v2;
  v1.imprimir();
  std::cout<<"+";
  v2.imprimir();
  std::cout<<"=";
  v3.imprimir();
  std::cout<<std::endl;
  Vector v4 = v1 * v2;
    v1.imprimir();
  std::cout<<"*";
  v2.imprimir();
  std::cout<<"=";
  v4.imprimir();
}
