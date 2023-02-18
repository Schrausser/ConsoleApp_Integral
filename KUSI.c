//-----------------------------------------------------------------| KUSI Kubische Spline Interpolation    //
//                                                                 | von Dietmar SCHRAUSSER 2011  //              
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void _profil();
void _head();

double main(int argc, char *argv[])
{
	FILE *in, *out;

	int iLauf, N_=0, M_,I_, K_;
	double  x_, y_, X_[1000], Y_[1000], B_[1000], C_[1000], D_[1000], S_=0,  R_, Q_;
	char cx_[30], cy_[30];

	if (argc != 3) { printf("\nArgument n .0\n"); _profil(); }

	x_=atof(argv[2]); // funktionswert x'
	
	in = fopen( argv[1], "r" ); if(in == 0) { printf("\nEingabe Datei .0\n"); _profil(); }

	out = fopen( "KUSI.txt", "w");

	_head();

	// einlesen von funktionsmatrix (F)=(x|y)  
	
	while (feof (in) == 0) // über N von (F)
	{	
		fscanf(in,"%s%s\n",cx_,cy_); // funktionsmatrix (F)
			   X_[N_]=atof(cx_);
			   Y_[N_]=    atof(cy_); // vektoren
				  N_++; //zähler
	}
	 
	
	fclose( in );   //(F)

	// berechnung der koeffizienten

	M_=N_-1;
	
	for(iLauf=0;iLauf<=M_;iLauf++) // über M 
	{
		                                     D_[iLauf]=X_[iLauf+1]-X_[iLauf];
		          R_=(Y_[iLauf+1]-Y_[iLauf])/D_[iLauf];
		C_[iLauf]=R_-S_;
		             S_=R_;
	}

	                 S_= R_=C_[0]=C_[N_]=0;
	
	for(iLauf=1;iLauf<=M_;iLauf++) // über M 
	{
		                        C_[iLauf]=C_[iLauf]+R_*C_[iLauf-1];
		      B_[iLauf]=(X_[iLauf-1]-X_[iLauf+1])*2-R_*S_;

		   S_=D_[iLauf];
		R_=S_/B_[iLauf];
	}

	for(iLauf=M_;iLauf>=1;iLauf--) // über M rekursiv 
	{
		C_[iLauf]=(D_[iLauf]*C_[iLauf+1]-C_[iLauf])/B_[iLauf];	
	}

	for(iLauf=0;iLauf<=M_;iLauf++) // über M 
	{
		                                   S_=D_[iLauf];
		                                R_=    C_[iLauf+1]-C_[iLauf];
		                      D_[iLauf]=R_/S_; 
		                                       C_[iLauf]=C_[iLauf]*3;

		 B_[iLauf]=(Y_[iLauf+1]-Y_[iLauf])/S_-(C_[iLauf]+R_)*S_;
	}

	for(iLauf=0;iLauf<=M_;iLauf++) // über M 
	{
		fprintf(out,"%f\t%f\t%f\n", B_[iLauf],C_[iLauf],D_[iLauf]); //koeffizientenmatrix
			
	}

	// berechnung von s(x) über die interpolations-matrix
	
	Q_=(X_[N_]-X_[0])/fabs(X_[N_]-X_[0]);//sgn

	                  K_=-1;
	while(1)
	{
		           I_=K_;
		              K_++;
		if(Q_*x_<Q_*X_[K_]||
			          K_==N_)break;
	}

	Q_=x_-X_[I_];

	y_=((D_[I_]*Q_+C_[I_])*Q_+B_[I_])*Q_+Y_[I_];

	printf("\ns(x)=%f\n\n", y_);

	fclose( out );
	
	return y_;
};

void _profil()
{
	printf("---------------------------------------------------------\n");
	printf("Gebrauch: KUSI [f] [x]\n");
	printf("[f] ......... Funktionsmatrix Datei (F)\n");
	printf("[x] ......... Funktionswert x\n");
	printf("---------------------------------------------------------\n");
	printf("KUSI Kubische Spline Interpolation von Dietmar Schrausser\n");
	printf("compiliert: %s @ %s\n", __DATE__, __TIME__);
	exit(0);
};

void _head()
{
	printf("\nKUSI Kubische Spline Interpolation von Dietmar Schrausser\n");
	printf("compiliert: %s @ %s\n", __DATE__, __TIME__);
	printf("berechne KUSI:\n");
};

