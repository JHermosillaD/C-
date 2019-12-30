/*
 * newton_raphson.cxx
 * 
 * Copyright 2019 Eduardo Hermosilla <eduardohermosilla@iMac-de-Eduardo.local>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include<cmath> 
#define EPSILON 0.001 
using namespace std; 
  
double f(double x) // definir el polinomio
{ 
    return x*x*x - 4*x*x + 2; 
} 
  
double df(double x) // la derivada del polinomio
{ 
    return 3*x*x - 8*x; 
} 
  
void newtonRaphson(double x) 
{ 
    //double h = f(x) / df(x); 
    while (abs(x*x*x - 4*x*x + 2) >= EPSILON) 
    { 
	//	h = f(x)/df(x); 
   
        // x(i+1) = x(i) - f(x) / f'(x)   
        x = x - f(x)/df(x); 
    } 
  
    cout << "LA solución es: " << x; 
} 

int main() 
{ 
	cout << "Valor inicial: " << endl; 
	double x0 = 0; // variables to hold the input we read 
	cin >> x0; // read input
    newtonRaphson(x0); 
    return 0; 
} 
