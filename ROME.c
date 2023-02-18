//-----------------------------------------------------------------| ROME Romberg-Extrapolation (ROMBERG Integration)  //
//                                                                 | von Dietmar SCHRAUSSER 2011                       //              
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "ROME.h"

void _profil();
void _head();

long double main(int argc, char *argv[])
{
	int  j_,k_;
	long double A_, B_, H_, N_=1, X_, I_[17], E_=1e-17, F1_, S_, Q_, Ia ;
	
	if (argc != 3) { printf("\nArgument n .0\n"); _profil(); }
	
	formel();
	_head();
	
	      A_  =atof(argv[1]);           // integrations minimum a
	   B_     =atof(argv[2]);           // integrations maxmum  b
	H_=B_-A_;
	                            X_=A_;
	                F_=funktion(X_);    // funktion y=f(x=a)
	            F1_=F_;
	                            X_=B_;
	                F_=funktion(X_);    // funktion y=f(x=b)
				
	I_[0]=  H_*(F1_+F_)/2;

	for(k_=1;k_<=17;k_++)
	{
		S_=0;H_/=2;N_*=2;Q_=1;
		
		for(j_=1;j_<=N_-1;j_+=2)
		{
			                X_=A_+j_*H_;
			    F_=funktion(X_);        // funktion f(x)dx	
			S_+=F_;
		}
		
		I_[k_]=I_[k_-1]/2+S_*H_;

		for(j_=k_-1;j_>=0;j_--)
		{
			                                   Q_*=4;
			I_[j_]=I_[j_+1]+(I_[j_+1]-I_[j_])/(Q_-1);
		}

		printf("\nT[n,%i]= %.16f",k_,I_[0]); // bildschirmausgabe

		                        Ia=fabs(I_[0]);
		                     if(Ia<1)Ia=1;
		if(fabs(I_[1]-I_[0])<E_*Ia)break;
	}

	//printf("\nT[n,%i]= %.16f\n",k_,I_[0]);
	printf("\n");

	return I_[0];
};

void _profil()
{
	printf("--------------------------------\n");
	printf("Gebrauch: ROME [a] [b]\n");
	printf("[a] ..... Integrations Minimum a\n");
	printf("[b] ......Integrations Maximum b\n");
	printf("--------------------------------\n");
	printf("ROME Romberg-Extrapolation von Dietmar Schrausser\n");
	printf("compiliert: %s @ %s\n", __DATE__, __TIME__);
	exit(0);
};

void _head()
{
	printf("\nROME Romberg-Extrapolation von Dietmar Schrausser\n");
	printf("compiliert: %s @ %s\n", __DATE__, __TIME__);
	printf("berechne ROMBERG Integral:\n");
	printf("\nf(x)= %s\n",fx);
};
