#include "manifold_plane_wiggle.h"

#include <math.h>

using namespace LAMMPS_NS;

manifold_plane_wiggle::manifold_plane_wiggle( LAMMPS *lmp, int argc, char **argv ) :
  Pointers(lmp)
{}


double manifold_plane_wiggle::g( const double *x )
{
  double a = params[0];
  double w = params[1];
  return x[2] - a*sin(w*x[0]);
}


void manifold_plane_wiggle::n( const double *x, double *n )
{
  double a = params[0];
  double w = params[1];
  n[2] = 1;
  n[1] = 0.0;
  n[0] = -a*w*cos(x[0]);
}
