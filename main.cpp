/*
Une fusée explose à 100m de hauteur, 
des débris partent dans toutes les directions à 20m/s dans un champ gravitationel uniforme de 9.81m/s^2 (on néglige les frotements).
Quel est le volume couvert par les débris ?
https://projecteuler.net/problem=317
*/


#include <iostream>
#include <unistd.h>
#include <math.h>

#include "parametres.h"


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
  while (f(x, a)*f(x, a)>=PREC){
    x=x-newton_ratio(x, a);
  }
  return x;
}



main{int argc, char ** argv) {
  
  
  
  return 0;
}
  
