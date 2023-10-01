#include<stdio.h>
int gcd(int a, int b)
{
	if (a==0 || b==0) 
		return a+b;
	while (a!=b)
	{
		if (a > b) a-=b;
		else b-=a;
	}
	return a;
}
int main () 
{
	unsigned int n, b, k;
	int a, c; 
	printf("Nhap N = "); scanf("%d", &n);
	do 
	{
	printf("Nhap a = "); scanf("%d", &a);
	if ((a>=n)||(a<0)) printf("Nhap lai a\n"); 
	}
	while ((a>=n)||(a<0)); 
	if (gcd(a,n)!=1)
		printf("Khong ton tai phan tu nghich dao");
	else
	{
		k = 1; 
		do
		{ 
			c = (k*n+1)%a ;
			if ( c==0 ) 
			{
				b = (k*n+1)/a ;
				printf("Kha nghich cua a la: %d ", b); 
			}
		k++; 
		}
		while (c!=0);
	}
	return 0; 
} 
