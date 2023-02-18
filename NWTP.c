//-----------------------------------------------------------------| NWTP Newton Polynom          //
//                                                                 | von Dietmar SCHRAUSSER 2011  //              
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void _profil();
void _head();

main(int argc, char *argv[])
{
	FILE *in, *out;

	int n_=0;
	double x_, a_, b_, d_, p_=0, xn, xp;

	char cx_[30];

	
	if (argc != 4) { printf("\nArgument n .0\n"); _profil(); }

	        in = fopen( "nwti.txt", "r" ); if(in == 0) { printf("\nKoeffizientenvektor Datei (a) .0\n"); _profil(); } 
	fclose( in );
	
	out = fopen( "nwtp.txt", "w"); // (F)=(x|p(x))

	a_=atof(argv[1]);
	b_=atof(argv[2]);
	d_=atof(argv[3]);

	_head();

	for(x_=a_;x_<=b_;x_+=d_) //über (x) bei d
	{		
		in = fopen( "nwti.txt", "r");  // (a)

		        p_=0;
		fscanf(in,"%s\n",cx_); // a0
	            p_+=atof(cx_);
		
		n_=1;
		while (feof (in) == 0) // über n von (a)
		{
								  xp=1;
			for(xn=1;xn<=n_;xn++) xp*=(x_-xn); //(x-1)*...*(x-n)

			 fscanf(in,"%s\n",cx_); // ai
					p_+=(atof(cx_)*xp);
			n_++;
		}

		fclose( in );

		printf("\np(x=%.3f)= %f",x_,p_); // bildschirmausgabe von p(x)

		fprintf(out,"%f\t%f\n",x_,p_); // dateiausgabe von p(x)

	}

	fclose( out );

	printf("\n"); // bildschirmausgabe von p(x)


	return 0;
};

void _profil()
{
	printf("------------------------------------------\n");
	printf("Gebrauch: NWTP [a] [b] [d]\n");
	printf("[a] ......... (x) Minimum\n");
	printf("[b] ......... (x) Maximum\n");
	printf("[d] ......... Intervall d\n");
	printf("------------------------------------------\n");
	printf("NWTP Newton Polynom von Dietmar Schrausser\n");
	printf("compiliert: %s @ %s\n", __DATE__, __TIME__);
	exit(0);
};

void _head()
{
	printf("\nNWTP Newton Polynom von Dietmar Schrausser\n");
	printf("compiliert: %s @ %s\n", __DATE__, __TIME__);
	printf("berechne NWTP:\n");
};
