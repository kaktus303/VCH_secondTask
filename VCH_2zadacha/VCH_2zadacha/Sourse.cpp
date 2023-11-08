#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
# define M_PI 3.14159265359
#define N 17
double f(double x)
{
	return sin(M_PI * x);
}
double F(double x)
{
	return M_PI * cos(M_PI * x);
}
int main()
{
double a = -1.0, b = 1.0, size = 2.0, Knots[N], step, FKnots[N], Divdif1[N], sum = 0.0, x, val = 1.0, step1 = 4.0 / 500, b1, sum1 = 0.0, val1 = 1.0, pol0[N], pol1[N], c;
int i, j, k, o;
step = size / (N - 1);
for (i = 0; i < N; ++i)
{
	Knots[i] = a + step * i;
	FKnots[i] = f(Knots[i]);
}
for (i = 1; i < ((N - 1) / 2) - 1; ++i)
{
	sum += FKnots[2 * i]*2;
}
for (i = 1; i < ((N - 1) / 2); ++i)
{
	sum += FKnots[(2 * i) - 1]*4;
}
sum += FKnots[0];
sum += FKnots[N];
sum *= step / 3;
}