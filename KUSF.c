//-----------------------------------------------------------------| KUSF Kubische Spline Funktion    //
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
	FILE *inF, *in, *out;

	int N_=0, M_=0,I_, K_;
	double  x_, y_,  a_, b_, d_, X_[1000], Y_[1000], B_[1000], C_[1000], D_[1000],  Q_;
	char cb_[30], cc_[30], cd_[30];

	if (argc != 5) { printf("\nArgument n .0\n"); _profil(); }

	a_=atof(argv[2]);
	b_=atof(argv[3]);
	d_=atof(argv[4]);


	inF = fopen( argv[1], "r" ); if(inF == 0) { printf("\nEingabe Datei .0\n"); _profil(); }
	
	in = fopen( "KUSI.txt", "r" ); if(in == 0) { printf("\nEingabe Datei .0\n"); _profil(); }

	out = fopen( "KUSF.txt", "w");

	_head();
	
	// einlesen von Funktionsmatrix (F)=(x|y)  
	
	while (feof (inF) == 0) // über N von (A)
	{	
		fscanf(inF,"%s%s\n",cb_,cc_); 
			    X_[N_]=atof(cb_);
			    Y_[N_]=    atof(cc_);  
				   N_++; //zähler
	}

	fclose( inF );   //(F)

	

	// einlesen von Koeffizientenmatrix (A)=(b|c|d)  
	
	while (feof (in) == 0) // über N von (A)
	{	
		fscanf(in,"%s%s%s\n",cb_,cc_,cd_); 
			   B_[M_]=atof(cb_);
			   C_[M_]=    atof(cc_); 
			   D_[M_]=            atof(cd_); 
				  M_++; //zähler
	}
	 
	
	fclose( in );   //(A)


	// berechnung von (S)=(x|s(x)) über die interpolations-funktion
	
	for(x_=a_;x_<=b_;x_+=d_) //über [a, b] bei d
	{
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

		fprintf(out,"%f\t%f\n", x_, y_); // ausgabe von Funktionsmatrix (S)
	}

	fclose( out );
	
	return 0;
};

void _profil()
{
	printf("----------------------------------------------------\n");
	printf("Gebrauch: KUSF [f] [a] [b] [d]\n");
	printf("[f] ......... Funktionsmatrix (F)\n");
	printf("[a] ......... (x) Minimum a\n");
	printf("[b] ......... (x) Maximum b\n");
	printf("[d] ......... Delta x\n");
	printf("----------------------------------------------------\n");
	printf("KUSF Kubische Spline Funktion von Dietmar Schrausser\n");
	printf("compiliert: %s @ %s\n", __DATE__, __TIME__);
	exit(0);

};

void _head()
{
	printf("\nKUSF Kubische Spline Funktion von Dietmar Schrausser\n");
	printf("compiliert: %s @ %s\n", __DATE__, __TIME__);
	printf("berechne KUSF:\n");
};

