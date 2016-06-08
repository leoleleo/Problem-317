#include <iostream>
#include <unistd.h>
#include <math.h>

//the zero of f will give us the sin(theta) that maximise r for a given a
double f(double x, double a){
  return x*x+x*sqrt(x*x+a)-1;
}

//the derivative of f, used in the Newton's method to find the zero of f
double df(double x, double a) {
  double b=sqrt(x*x+a);
  return 2*x+b+x*x/b;
}

main{int argc, char ** argv) {
  
  return 0;
}
  
