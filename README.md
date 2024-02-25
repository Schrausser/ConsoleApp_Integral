# ConsoleApp_Integral
Console applications for *integral* and *interpolation* (German):
## ROMI

Approximiert (a) Flächen- oder (b) Kurven-Integrale 

$$\int\limits_a^bf(x)dx$$

mittels Romberg Methode, dabei 
ggf. Dateiausgabe nach `romi.txt` von Funkionsmatrix 

$$(F)=(x|y)$$

bei 

$$x=\frac{x+d}{2},y=\int\limits_a^b{f(x)dx}$$.

- Ausführung von `ROMI.bat`:
- Definition von $f(x)$ in `ROMI.h`;
 - Compilieren von `ROMI.c`; 
- Ausführung von `ROMI.exe`.

## ROME 

Approximiert das Integral ∫[a,b]f(x)dx mittels Romberg-Extrapolation 
(ROMBERG Integration nach Meyberg & Vachenauer, 2001, S. 209).

- Ausführung von `ROME.bat`:
- Definition von $f(x)$ in `ROME.h`;
- Compilieren von `ROME.c`; 
- Ausführung von `ROME.exe`.

## KUSI 

Kubische Spline Interpolation: Berechnung der Koeffizientenmatrix $(A)=(b|c|d)$ sowie $s(x)$ zu einer (empirischen) Funktionsmatrix $(F)=(x|y)$, wobei

    si(x)= yi + bi(x-xi) + ci(x-xi)^2 + di(x-xi)^3; i= 0,1,...,n-1. 

- Übernahme einer ASCII Funktionsmatrix Datei $(F)$;
- Ausgabe der ASCII Koeffizientenmatrix Datei $(A)$ (`KUSI.txt`);
- Berechnung von $s(x)$ über die Interpolations-Funktion.

## KUSF 

Kubische Spline Funktion: Berechnung einer Funktionsmatrix $(S)=(x|s(x))$ zu Koeffizientenmatrix $(A)=(b|c|d)$, wobei

    si(x)= yi + bi(x-xi) + ci(x-xi)^2 + di(x-xi)^3; i= 0,1,...,n-1. 

- Übernahme einer ASCII Funktionsmatrix Datei $(F)$;
- Übernahme der ASCII Koeffizientenmatrix Datei $(A)$ (`KUSI.txt`);
- Ausgabe der ASCII Funktionsmatrix Datei $(S)$ (`KUSF.txt`).

## NWTI 

Newton Interpolation: Berechnung des Koeffizientenvektors $(a)$ sowie $p(x)$ zu einer (empirischen) Funktionsmatrix $(F)=(x|y)$, wobei

    p(x)= a0 + a1(x-1) + a2(x-1)(x-2) ... an(x-1)(x-2) ... (x-n). 

- Übernahme einer ASCII Funktionsmatrix Datei $(F)$;
- Ausgabe einer ASCII Koeffizientenvektor Datei $(a)$ (`nwti.txt`);
- Berechnung von $p(x)$ über das Interpolations-Polynom.

## NWTP

Newton Interpolations Polynom: Berechnung einer Funktionsmatrix $(F)=(x|p(x))$ zu Koeffizientenvektor $(a)$, wobei

    p(x)= a0 + a1(x-1) + a2(x-1)(x-2) ... an(x-1)(x-2) ... (x-n).

- Übernahme der ASCII Koeffizientenvektor Datei $(a)$ (`nwti.txt`);
- Ausgabe der ASCII Funktionsmatrix Datei $(F)$ (`nwtp.txt`).

## References
Meyberg, K., & Vachenauer, P. (2001). Integration. In *Höhere Mathematik 1*. Springer-Lehrbuch. Springer, Berlin, Heidelberg. https://doi.org/10.1007/978-3-642-56654-7_4
