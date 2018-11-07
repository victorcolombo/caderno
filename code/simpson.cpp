#include <bits/stdc++.h>
const double eps = 1e-7;

//INTEGRAL NUMERICA PELO METODO DE SIMPSON

// funcao a ser integrada
double f(double x){
    return x*x;
}

//aproximacao da integral no intervalo a,b de Simpson (nao o Homer)
//funciona muito bem para intervalos pequenos
double simpson(double a, double b) {
    return (f(a) + 4*f((a+b)/2) + f(b))*(b-a)/6;
} 

//a ideia eh quebrar o intervalo a,b em duas metades e verificar se a aproximacao
//ja esta boa o suficiente. se nao estiver, integramos as metades recursivamente.
double integrate(double a, double b) {
    double m = (a+b)/2;
    double l = simpson(a,m), r = simpson(m,b), tot = simpson(a,b);
    if(fabs(l+r-tot) < eps) return tot;
    return integrate(a,m) + integrate(m,b);
}
