/*
 * sum.cxx
 * 
 * Copyright 2019 Eduardo Hermosilla <eduardohermosilla@iMac-de-Eduardo.local>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 */

#include <iostream> 
/* 
 * Simple main function:  
 * C++ Primer, Fifth Edition
 * Read two numbers and write their sum
 */
int main()
{
	// prompt user to enter two numbers
	std::cout << "Enter two numbers:" << std::endl; 
	int v1 = 0, v2 = 0; // variables to hold the input we read 
	std::cin >> v1 >> v2; // read input
	std::cout << "The sum of " << v1 << " and " << v2 
	<< " is " << v1 + v2 << std::endl;
	return 0; 
}
