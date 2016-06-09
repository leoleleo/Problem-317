/*
Une fusée explose à 100m de hauteur, 
des débris partent dans toutes les directions à 20m/s dans un champ gravitationel uniforme de 9.81m/s^2 (on néglige les frotements).
Quel est le volume couvert par les débris ?
https://projecteuler.net/problem=317
*/


#include <iostream>
#include <unistd.h>
#include <cmath>

#include "parametres.h"

using namespace std


//the zero of f gives us sin(theta)^2
double f(double x, double a){
  return x+sqrt(x*x+x*a)-1;
}

//this function will return f(x)/f'(x) used in newton's method
double newton_ratio(double x, double a) {
  double b=sqrt(x*x+a*x);
  return b*(b+x-1)/(b+1+a/2);
}

//here we iterate newton's method to find the zero of f
double newton_suite(double a){
  double x=a;
  while (abs(f(x, a))>=PREC){
    x=x-newton_ratio(x, a);
  }
  return x;
}

//phi is the function we will integrate, if y=sin(theta)^2, phi(y) is r^2 (without some constants terms)
double phi(double y){
  return (1-y*y)/(1.*y);
}


main{int argc, char ** argv) {
  
  double V; //the volume we are looking for
  
  double const C=( (V0*V0)/(2.*GRAV) )*( (V0*V0)/(2.*GRAV) )*( (V0*V0)/(2.*GRAV) ); //a constant term that appears in the integral
  
  double a=-1; //This is the integral parameter : a=2g(zo-h)/vo^2 (it is -1 when h is maximal)
  
  double k1=0, k2=0, k3=0, k4=0; //parameters we will add up in the simpson method to get the integral
  double const a_max = 2.*GRAV/(1.*V0*V0); //correspond to h=0
  double const h=(a_max+1)/(1.*N)
  
  double buff; //a buffer parameter
  
  k1=phi(newton_suite (a));
  
  for (i=1, i<N, i++ ){
    a=a+h;
    buff=phi(newton_suite(a));
    
    if (i%2){
      k2=k2+buff;
    }
    else k3=k3+buff;
  }
  k4=phi(newton_suite (a_max));
  
  V=C*(h/3.)*( k1+2*k2+4*k3+k4);
  
  cout<<"volume recherché V="<< V << endl;
  
  return 0;
}
  
