//-----------------------------------------------------------------| ROME Romberg-Extrapolation (ROMBERG Integration)  //
//                                                                 | Funktions Header ROME.h                           //  
//                                                                 | von Dietmar SCHRAUSSER 2011                       // 

long double F_;
char fx[300];
                                                                
double funktion(long double X_) // Funktionsdefinition f(x)dx  //
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//     F_ = FUNKTION hier einf�gen   

           F_=  log(X_)/X_;
	return F_;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void formel() //  Formelausgabe, optional //
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//          FORMEL hier einf�gen, optional  

         sprintf(fx,  "log(X_)/X_"  );

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//          Beispiel Funktionen           
	//                                        
	//          F_=  log(X_)/X_;              
	//          F_=  2*X_;                    
	//          F_=  (1/sqrt(2* 3.1415926535897932384626433832795 ))*pow(2.7182818284590452353602874713527,(-(pow(X_,2)/2)));  // f(z)dz
	//										  
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

