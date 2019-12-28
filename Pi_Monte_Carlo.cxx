/*
 * Calculate pi with Monte Carlo
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
 * Supongamos un cuadrado de lado 2 con un circulo unitario circunscito,
 */

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	double puntos_cuadrado = 100000000;  
	int punto_circulo = 0;     		              // inicializando puntos dentro del circulo
	double radio_cuadrado = double(RAND_MAX);    		  // asigna el valor random maximo al cuadrado del radio
	for (int i = 0; i < puntos_cuadrado; ++i) {   // A lo mas puede haber un punto menos en el circulo que en el cuadro  
		double x = rand()/radio_cuadrado;				  // De esta forma los puntos siempre seran menores que uno
		double y = rand()/radio_cuadrado;
		if (x*x + y*y < 1 ) punto_circulo = punto_circulo + 1; // si cae dentro del circulo cuenta
	}
	cout << "Pi es aprox " << 4*punto_circulo/puntos_cuadrado << endl; 
	return 0;
}
