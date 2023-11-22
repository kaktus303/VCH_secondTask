#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
# define M_PI 3.14159265359
//#define N 17
double f(double x)
{
	return sin(M_PI * x);
}
double F(double x)
{
	return (-1 * (1/M_PI) * cos(M_PI * x));
}
double Simpson(int N, double a1, double b1)
{

	double sum = 0.0, step = (b1-a1)/N,a = a1,b = b1;
	printf("%lg\n", step);
	for (int i = 1; i <= ((N) / 2) - 1; ++i)
	{
		sum = sum + 2 * f(a + step*(2*i));
	}
	printf("%lf\n", sum);
	for (int i = 1; i <= (N) / 2; ++i)
	{
		sum = sum + 4 * f(a + step*((2 * i) - 1));
	}
	printf("%lf\n", sum);
	sum += f(a);
	sum += f(b);
	sum *= step/3;
	return sum;
}
double Gauss(int N, double a, double b)
{
	double sum = 0.0, step = (b - a) / N,a1,b1,sum1 = 0.0;
	for (int i = 1; i < N; ++i)
	{
		sum1 = 0.0;
		a1 = a + step * i;
		b1 = a1 + step;
		sum1 += f((a1 + b1) / 2 + ((b1 - a1)/2) * (-1/sqrt(3)));
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
	//double a = -1.0, b = 1.0, size = 2.0, Knots[N], step, FKnots[N], Divdif1[N], sum = 0.0, x, val = 1.0, step1 = 4.0 / 500, b1, sum1 = 0.0, val1 = 1.0, pol0[N], pol1[N], c;
	int i, j, k, o;
	//step = size / (N - 1);
	/*for (i = 0; i < N; ++i)
	{
		Knots[i] = a + step * i;
		FKnots[i] = f(Knots[i]);
	}
	PrintMassive(Knots, N);
	PrintMassive(FKnots, N);
	printf("\n");
	for (i = 1; i <= ((N - 1) / 2)-1; ++i)
	{
		sum = sum + FKnots[2 * i];
	}
	sum = sum * 2;
	for (i = 1; i <= (N - 1) / 2; ++i)
	{
		sum = sum + FKnots[(2 * i) - 1];
	}
	sum = sum * 4;
	sum += FKnots[0];
	sum += FKnots[N-1];
	sum *= step;
	sum = sum / 3;
	printf("**%f**\n", sum);
	printf("%f\n%f\n", F(b) - F(a),f(1) - f(-1));*/
	printf("\n%lf\n%f\n%lf", Simpson(6000, 4,9), F(9) - F(4),Gauss(6000,4,9));
}
