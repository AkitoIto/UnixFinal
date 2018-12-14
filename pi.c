#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <math.h>

int main(int argc, char * argv[])
{
  //gsl random number generator with seed 0
  const gsl_rng_type * T;
  gsl_rng * r;
  gsl_rng_env_setup();
  T = gsl_rng_default;
  r = gsl_rng_alloc (T);
  
  int numPoints;
  double x;
  double y;
  double add;
  double distance;
  int isCircle = 0;
  int i;
  //getting number of points from command line argument
  numPoints = atoi(argv[1]);

  for(i=0; i<numPoints; i++)
  {
    x = gsl_rng_uniform (r);
    y = gsl_rng_uniform (r);
    add = (x*x)+(y*y);
    distance = sqrt(add);
    if(distance <= 1)
         isCircle++;
  }
  gsl_rng_free (r);

  //calculating result
  double pi;
  pi = 4.0 * (isCircle/(double)numPoints);
  printf("Pi: %.5f\n", pi);
  
return 0;
}
