#include <stdio.h>
#include <math.h>

#define PI 3.141592

int main(void)
{
  double deg = 30;
  double len = 2;
  double rad = deg * PI / 180.0;

  double x = len * cos( rad );
  double y = len * sin( rad );
  printf( "X=%f Y=%f¥n", x, y );

  return 0;
}
