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

//this function will return f(x)/f'(x) where f(x)=x+sqrt(x^2+ax)-1 the zero of f gives us sin(theta)^2
double newton_ratio(double x, double a) {
  double b=sqrt(x*x+a*x);
  return b*(b+x-1)/(b+1+a/2);
}




main{int argc, char ** argv) {
  
  return 0;
}
  
