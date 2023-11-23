#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
# define M_PI 3.14159265359
//#define N 17
double f(double x)
{
	return sin(M_PI * x);
}
double F(double x)
{
	return (-1 * (1 / M_PI) * cos(M_PI * x));
}
double Leib(double a, double b)
{
	return(F(b) - F(a));
}
double Simpson(int N, double a1, double b1)
{
	double sum = 0.0, step = (b1 - a1) / N, a = a1, b = b1,N1,N2;
	N1 = ((N) / 2) - 1;
	N2 = (N) / 2;
	for (int i = 1; i <= N1; ++i)
	{
		sum = sum + 2 * f(a + step * (2 * i));
	}
	for (int i = 1; i <= N2; ++i)
	{
		sum = sum + 4 * f(a + step * ((2 * i) - 1));
	}
	sum += f(a);
	sum += f(b);
	sum *= step / 3;
	return sum;
}
double Gauss(int N, double a, double b)
{
	double sum = 0.0, step = (b - a) / N, a1, b1, sum1 = 0.0;
	for (int i = 1; i < N; ++i)
	{
		sum1 = 0.0;
		a1 = a + step * i;
		b1 = a1 + step;
		sum1 += f((a1 + b1) / 2 + ((b1 - a1) / 2) * (-1 / sqrt(3)));
		sum1 += f((a1 + b1) / 2 + ((b1 - a1) / 2) * (1 / sqrt(3)));
		sum1 *= (b1 - a1) / 2;
		sum += sum1;
	}
	return sum;
}
void PrintMassive(double* A, int n)
{
	int i;
	for (int i = 0; i < n; ++i)
	{
		printf("\n%f", A[i]);
	}
}
int main()
{
	int N = 80;
	double p,a = -1,b = 1.5,r;
	clock_t start, end, diff;
	start = clock();
	r = Simpson(N, a, b);
	diff = clock() - start;
	printf("%d  %d\n", diff, start);
	start = clock();
	r = Gauss(N, a, b);
	diff = clock() - start;
	printf("%d  %d\n", diff, start);
	printf("Integral: %lf\n", Leib(a,b));
	printf("Integral Simpson: %lf\n", Simpson(N, a, b));
	printf("Integral Gauss: %f\n", Gauss(N, a, b));
	p = log2(((Simpson(N, a, b) - Leib(a, b)) / (Simpson(N * 2, a, b) - Leib(a, b))));
	printf("Porydok Simpson: %f\n",p);
	p = log2(((Gauss(N, a, b) - Leib(a, b)) / (Gauss(N * 2, a, b) - Leib(a, b))));
	printf("Porydok Gauss: %lf\n", p);
	printf("Pogreshnoct Simpson: %lg\n", fabs(Simpson(N, a, b) - Leib(a, b)));
	printf("Pogreshnoct Gauss: %lg\n", fabs(Gauss(N,a,b) - Leib(a, b)));
	printf("Pogreshnost teor Simpson: %lg\n",((pow(2,p)/(pow(2,p) - 1)) * (Simpson(N,a,b) - Simpson(N*2,a,b))));
	printf("Pogreshnost teor Gauss: %lg", fabs((pow(2, p) / (pow(2, p) - 1)) * (Gauss(N, a, b) - Gauss(N * 2, a, b))));
	printf("Gauss: 2n + 2; Simpson: 2n + 9");
}

