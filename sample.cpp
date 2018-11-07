#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#define PI 3.141592653589793
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
using namespace std;
static const double epsilon = std::numeric_limits<double>::min();
void imprimir(double *u,int n,double mu,double sigma);
double _rn(void);
double gg(double mu, double sigma);
time_t t;

int main (int argc, char *argv[] )
{
	if( argc != 4 ) 
	{
		cout << "La entrada debe ser de la forma N mu sigma\n", argv[0];
		exit(0);
  }
  int N = atoi(argv[1]);
	int mu = atoi(argv[2]);
	int sigma = atoi(argv[3]);
  srand((unsigned) time(&t));
	double n[N]={};
	ofstream myfile ("sample.dat");

	int i;
	for(i=0;i<N+1;i++)
	{
		
		n[i]=gg(mu,sigma);
  }
  imprimir(n,N,mu,sigma);
  return 0;
}
double _rn(void)
{
    return (double) rand()/(RAND_MAX*1.0);
}


void imprimir(double *u,int n,double mu,double sigma)
{
	ofstream myfile ("sample.dat");
  if (myfile.is_open())
  {
		int i;
		for(i=0;i<n+1;i++)
		{
			myfile << u[i] << '\n';
		}
		myfile<< n << '\n';
		myfile<< mu << '\n';
		myfile<< sigma << '\n'; 
    myfile.close();
  }
  else cout << "Unable to open file";
}

double gg(double mu, double sigma)
{
	static const double epsilon = std::numeric_limits<double>::min();
	static const double two_pi = 2.0*3.14159265358979323846;

	thread_local double z1;
	thread_local bool generate;
	generate = !generate;

	if (!generate)
	   return z1 * sigma + mu;

	double u1, u2;
	do
	 {
	   u1 = _rn();
	   u2 = _rn();
	 }
	while ( u1 <= epsilon );

	double z0;
	z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
	z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
	return z0 * sigma + mu;
}
