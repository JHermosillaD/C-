/*El movimiento de un péndulo simple de longitud L y con constante de fricción k está descrito por la ecuación diferencial
θ''[t] = - g/L Sen(θ[t]) - kL θ'[t]. Resuelva la ecuación diferencial por el método de Euler y grafique el resultado. */

#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <cmath> 
using namespace std;

double g = 9.8;
//  g=9.8, L=1, k=0.5.
//  theta(0) = 1
//  x(0) = 0
// 1 a 10 
double xPrime(double l, double k, double theta, double x)  
{
    return -(g/l)*sin(theta)  - k*l*x;
}
void eulersmethod(int maxIter, double l, double k, double theta0, double thetaDot0)
{
    double theta = theta0;
    double x = thetaDot0;
    for(int h=0; h<=maxIter; h+=1)
    {
        x = x + h*xPrime(l,k,theta,x);
        theta = theta + h*x;
        cout << "Iteracion | x" << endl;
        cout << "-------------" << endl;
        cout << h << ", " << x << "\n" << endl;
    }
    
}

int main()
{
    double l,k,x,theta0,thetaDot0;
    int maxIter;
    cout << "Introduce la longitud del péndulo: \n" ;
    cin >> l;
    cout << "Introduce la constante de fricción: \n" ;
    cin >> k;
    cout << "Introduce theta0: \n";
    cin >> theta0;
    cout << "Introduce thetaDot0: \n";
    cin >> thetaDot0;
    cout << "Número de iteraciones: \n";
    cin >> maxIter;
    eulersmethod(maxIter,l,k,theta0,thetaDot0);
}