/*
 * sum_for.cxx
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

int main()
{
	std::cout << "Suma de la secuencia entre 2 numeros " << std::endl; 
	int l1 = 0, l2 = 0;  
	std::cin >> l1 >> l2; 
	
	//std::cout << "al: " << std::endl; 
	//int l2 = 0;  
	//std::cin >> l2; 
	
	int sum=0;

	for (int val = l1; val <= l2; ++val)
		sum += val; // equivalent to sum = sum + val

	std::cout << "la suma de los numeros del " << l1 << " al "<< l2 << " es: " << sum << std::endl; 
	
	return 0;
}

 
