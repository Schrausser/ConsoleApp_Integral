//-----------------------------------------------------------------| NWTI Newton Polynomial Interpolation    //
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
	FILE *in, *tmpx, *tmpy, *tmp_,*out;

	int Lauf[3], N_=0, n_=0, sw=0;
	double x_1, y_1, x_2, y_2, a_, p_=0, x_, xn, xp;
	char cx_1[30], cy_1[30], cx_2[30], cy_2[30];

	if (argc != 3) { printf("\nArgument n .0\n"); _profil(); }

	x_=atof(argv[2]); // funktionswert x'
	
	in = fopen( argv[1], "r" ); if(in == 0) { printf("\nEingabe Datei .0\n"); _profil(); }

	tmpx = fopen( "~tmpx.txt", "w");
	tmpy = fopen( "~tmpy.txt", "w");
	out = fopen( "nwti.txt", "w");

	_head();

	// einlesen von funktionsmatrix (F)=(x|y)  
	
	while (feof (in) == 0) // über N von (F)
	{	
		          fscanf(in,"%s%s\n",cx_1,cy_1); // funktionsmatrix (F)
				            x_1=atof(cx_1);
		fprintf(tmpx,"%f\n",x_1);                // funktionsvektor (x)
                                 y_1=atof(cy_1);
		     fprintf(tmpy,"%f\n",y_1);           // funktionsvektor (y)
		
		N_++; //zähler
		
		if(sw==0)fprintf(out,"%f\n",y_1); // erstellung von koeffizientenvektor (a): a0
		   sw= 1;
	}
	       sw= 0;
	
	fclose( in );   //(F)
	fclose( tmpx ); //(x)
	fclose( tmpy ); //(y)

	// berechnung von koeffizientenvektor (a)
	
	for(Lauf[1]=0;Lauf[1]<N_-1;Lauf[1]++) // über N von (F)
	{	
		tmpy = fopen( "~tmpy.txt", "r"); //(y)
		tmp_ = fopen( "~tmp_.txt", "w"); //(y')	

		while (feof (tmpy) == 0) // über N von (y)
		{	
			tmpx = fopen( "~tmpx.txt", "r"); //(x)

			for(Lauf[2]=0;Lauf[2]<n_;Lauf[2]++)fscanf(tmpx,"%s\n",cx_1); // x start lag 
	
			fscanf(tmpx,"%s\n",cx_1); // x1 von funktionsvektor (x)
					  x_1=atof(cx_1);

			for(Lauf[2]=0;Lauf[2]<Lauf[1];Lauf[2]++)fscanf(tmpx,"%s\n",cx_1); // x zwischen lag  

			fscanf(tmpx,"%s\n",cx_2); // x2 von funktionsvektor (x)
					  x_2=atof(cx_2);

			if(n_==0)
			{
				fscanf(tmpy,"%s\n%s\n",cy_1,cy_2); // y1,y2 von funktions- bzw zwischenkoeffizientenvektor (y)
							  y_1=atof(cy_1);
					               y_2=atof(cy_2);
			}
			
			if(n_>0)
			{
				fscanf(tmpy,"%s\n",cy_2); // y2 von funktions- bzw zwischenkoeffizientenvektor (y)
				          y_2=atof(cy_2);
			}	  
			                    a_=(y_2-y_1)/(x_2-x_1); // berechnung von koeffizient a
			fprintf(tmp_,"%f\n",a_);                    // tmp zwischenkoeffizientenvektor (y')

					  y_1=y_2;
	
			fclose( tmpx ); //(x)
				n_++;
					  
			if(sw==0)fprintf(out,"%f\n",a_);            // erstellung von koeffizientenvektor (a): an
			   sw= 1;
		}
		       sw= 0;
			   n_= 0;

		
		fclose( tmpy ); //(y)
		fclose( tmp_ ); //(y')

		tmp_ = fopen( "~tmp_.txt", "r"); //(y')
		tmpy = fopen( "~tmpy.txt", "w"); //(y)

		while (feof (tmp_) == 0) //tmp_ -> tmpy
		{
			          fscanf(tmp_,"%s\n",cy_1);
			                    y_1=atof(cy_1);
			fprintf(tmpy,"%f\n",y_1); // zwischenkoeffizientenvektor (y)	
		}

		fclose( tmpy ); //(y)
		fclose( tmp_ ); //(y')
	}

	fclose( out );
	
	// berechnung von p(x) über das interpolations-polynom

	in = fopen( "nwti.txt", "r"); //(a)
	
	fscanf(in,"%s\n",cx_1); // a0
	        p_+=atof(cx_1);
	n_=1;

	while (feof (in) == 0) // über n von (a)
	{
		                      xp=1;
		for(xn=1;xn<=n_;xn++) xp*=(x_-xn); //(x-1)*...*(x-n)

		 fscanf(in,"%s\n",cx_1); // ai
	            p_+=(atof(cx_1)*xp);
		n_++;
	}

	fclose( in );

	printf("\np(x=%f)= %f\n",x_,p_); // bildschirmausgabe von p(x)

	system("del ~tmpx.txt");
	system("del ~tmpy.txt");
	system("del ~tmp_.txt");

	return p_;
};

void _profil()
{
	printf("------------------------------------------------\n");
	printf("Gebrauch: NWTI [f] [x]\n");
	printf("[f] ......... Funktionsmatrix Datei (F)\n");
	printf("[x] ......... Funktionswert x\n");
	printf("------------------------------------------------\n");
	printf("NWTI Newton Interpolation von Dietmar Schrausser\n");
	printf("compiliert: %s @ %s\n", __DATE__, __TIME__);
	exit(0);
};

void _head()
{
	printf("\nNWTI Newton Interpolation von Dietmar Schrausser\n");
	printf("compiliert: %s @ %s\n", __DATE__, __TIME__);
	printf("berechne NWTI:\n");
};

