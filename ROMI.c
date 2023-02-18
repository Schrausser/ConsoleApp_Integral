//-----------------------------------------------------------------| ROMI ROMBERG Integration    //
//                                                                 | von Dietmar SCHRAUSSER 2011 //              
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "ROMI.h"

int sw1, sw2;

void _profil();
void _head();

long double main(int argc, char *argv[])
{
	FILE *out;
	
	long double i_, a_, b_, d_, y_1, y_2, I_=0, I_2=0 ;
	
	if (argc != 6) { printf("\nArgument n .0\n"); _profil(); }

	out = fopen( "romi.txt", "w" );
	
	a_  =atof(argv[1]);           // integrations minimum a
	b_  =atof(argv[2]);           // integrations maxmum  b
	d_  =atof(argv[3]);           // delta d
	sw1 =atoi(argv[4]);           // Integralsmodus schalter
	sw2 =atoi(argv[5]);           // Funktionsmatrix schalter
	
	formel();
	_head();

	for(i_=a_;i_<=b_-d_;i_+=d_) // Integration im Intervall [a,b]
	{
		if(i_==a_)y_1=funktion(i_);    //bei i1
		          y_2=funktion(i_+d_); 

		if(sw1==0)I_+= y_1*d_ + ((y_2-y_1)*d_)/2;        //Flächenintegral
		if(sw1==1)I_+=  sqrt(pow((y_2-y_1),2)+pow(d_,2)); //Kurvenintegral
		                   
		                              y_1=y_2;

		// y
		// |             .yb'
		// |          .'  |
		// |       .y2----+
		// |    .'  |     |
		// |  y1----+     |
		// |  |     |     |
		// |.'|     |     |
		// |  |     |     |
		// |  |     |     |
		// +--i1-d--i2-d--ib--x
		//    a           b
		
		if(sw2==1)fprintf(out,"%g\t%.39f\n",(i_+d_)/2, I_);
	}

	printf("\nI[%g,%g]f(x)= %.8f\n",a_, b_, I_);

	printf("\n");

	fclose(out);

	return I_;
};

void _profil()
{
	printf("-----------------------------------------------\n");
	printf("Gebrauch: ROMI [a] [b] [d] [m] [F]\n");
	printf("[a] ..... Integrations Minimum a\n");
	printf("[b] ......Integrations Maximum b\n");
	printf("[d] ......Delta d\n");
	printf("[m] ......Modus: (0)Flaechen.I (1)Kurven.I\n");
	printf("[F] ......Funktionsmatrix: (0)keine (1)romi.txt\n");
	printf("-----------------------------------------------\n");
	printf("ROMI Romberg Integration von Dietmar Schrausser\n");
	printf("compiliert: %s @ %s\n", __DATE__, __TIME__);
	exit(0);
};

void _head()
{
	printf("\nROMI Romberg Integration von Dietmar Schrausser\n");
	printf("compiliert: %s @ %s\n", __DATE__, __TIME__);
	printf("berechne ROMBERG Integral");
	if(sw1==0)printf(" (Flaeche)");
	if(sw1==1)printf(" (Kurve)");
	printf(":\n");
	printf("\nf(x)= %s\n",fx);
};
