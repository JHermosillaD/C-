#include <stdio.h> 
#include <math.h>
float P[5000];
int main() 
{ 
//funciones para i´ y v´ respectivamente
float f_funx (float t, float I, float z, float E, float k, float R, float C) //E,k,R,C son constantes
{
	return z;
}
float g_funx (float t, float I, float z, float E, float k, float R, float C)
{
	float termino1, termino2, termino3, termino4; //términos de la ecuación diferencial
	termino1=(E*(cos(t))/(2*k*I));
	termino2=(-z*z)/I;
	termino3=(-R*z)/(2*k*I);
	termino4=(-1)/(2*k*C);
	return termino1+termino2+termino3+termino4;
}
	float t,I,z,E,k,R,C,h;
	//condiciones iniciales
	printf("Constantes requeridas: \n");
	printf("E (voltaje máximo): ");
	scanf("%f",&E);
	printf("k (inductor): ");
	scanf("%f",&k);
	printf("R (resistencia): ");
	scanf("%f",&R);
	printf("C (capacitancia): ");
	scanf("%f",&C); 
	printf("Condiciones iniciales del problema: \n");
	printf("Corriente inicial I(0): ");
	scanf("%f",&I);
	printf("Variable z inicial z(0): ");
	scanf("%f",&z);
	printf("Intervalos de tiempo: ");
	scanf("%f",&h);
	t=0;
	float Y[3] = {t,I,z}; 
	float A,Z,W;
	float G[2];
	A=0.5;
	Z=0.166667;
	W=2;
	int l;
	l=0;
	printf("Los 5000 puntos son: \n");
	while (l<5000)
	{
		float F1[3] = {1, f_funx(Y[0],Y[1],Y[2],E,k,R,C),g_funx(Y[0],Y[1],Y[2],E,k,R,C)}; 
		float K1[3];
		float K2[3];
		float K3[3];
		float K4[3];
	//Primer K
		for (int i=0;i<3;i++) 
			{
			K1[i]=h*F1[i];
			}
	//Segunda K
		//argumento
		float ARG2[3];
		for (int i=0;i<3;i++)
			{
			ARG2[i]=Y[i]+A*K1[i];
			}
		float F2[3]={1,f_funx(ARG2[0],ARG2[1],ARG2[2],E,k,R,C),g_funx(ARG2[0],ARG2[1],ARG2[2],E,k,R,C)};
		for (int i=0;i<3;i++) 
			{
			K2[i]=h*F2[i];
			}
	//Tercera K
		//argumento
		float ARG3[3];
		for (int i=0;i<3;i++)
			{
			ARG3[i]=Y[i]+A*K2[i];
			}
		float F3[3]={1,f_funx(ARG3[0],ARG3[1],ARG3[2],E,k,R,C),g_funx(ARG3[0],ARG3[1],ARG3[2],E,k,R,C)};
		for (int i=0;i<3;i++) 
			{
			K3[i]=h*F3[i];
			}
	//Cuarta K
		//argumento
		float ARG4[3];
		for (int i=0;i<3;i++)
			{
			ARG4[i]=Y[i]+K3[i];
			}
		float F4[3]={1,f_funx(ARG4[0],ARG4[1],ARG4[2],E,k,R,C),g_funx(ARG4[0],ARG4[1],ARG4[2],E,k,R,C)};
		for (int i=0;i<3;i++) 
			{
			K4[i]=h*F4[i];
			}
	//Y	
		for (int i=0;i<3;i++) 
			{
			Y[i]= Y[i] + Z*(K1[i]+W*K2[i]+W*K3[i]+K4[i]);
			//printf("%f ", Y[i]);   //imprime los 5000 puntos de tres componente tiempo, corriente y corriente prima.
			}
		for (int i=0;i<2;i++)
			{
			G[i]=Y[i];
			printf("%f ",G[i]);      //imprime los 5000 puntos de dos componente tiempo y corriente.
			}
		printf("\n");
		P[l]=G[1];
		l=l+1;
	}
	// Integral de los 5000 puntos.
	// se usa el método de simpson de orden 4, ya que se utilizan 5 puntos y así tomar los 5000 datos en grupos de 5
	float p,suma,a,b,c;
	int i;
	a=7;
	b=32;
	c=12;
	p=0.04444;
	i=0;
	suma=0;
	printf("La integral es: ");
	while (i<4996)
	{
		suma=suma+p*h*(a*P[i]+b*P[i+1]+c*P[i+2]+b*P[i+3]+a*P[i+4]);
		i=i+5;
	}
	printf("%f",suma);
	printf(" Coulombs ");		
}
