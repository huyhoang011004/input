#include <stdio.h>
#include <string.h>
int sodu(int m, int e, int n)
{
	
	int a[1000], i;
	long long du=1;
	for(i=0; e>0; i++)
	{
		a[i]=e%2;
		e=e/2;
	}
	for(i; i>=0; i--)
	{
		du = du*du;
		du = du % n;
		if(a[i]==1)
		{
			du = du*m;
			du = du % n;
		}
	}
	return du;
}
int main()
{
	int p, q, e, m, c, n, on, z, d=1;
	printf("Nhap p = "); scanf("%d",&p);
	printf("Nhap q = "); scanf("%d",&q);
	printf("Nhap e = "); scanf("%d",&e);
	n = p*q;
	on = (p-1)*(q-1);
	while(true)
		{
			if((e*d)%on==(1%on))
				break;
			d++;	
		}
		printf("Khoa cong khai Kp = {%d, %d}\n", e, n);
		printf("Khoa bi mat Ks = {%d, %d}\n", d, n);
	while(true)
	{
		printf("Ma hoa (1), Giai ma (2) hoac ket thuc (3) "); scanf("%d", &z);
		if (z==1)
		{
			printf("Nhap ban ro: "); scanf("%d",&m);
			printf("Ban ma la: %d\n", sodu(m, e, n));
		}
		else if (z==2)
		{
			printf("Nhap ban ma: "); scanf("%d",&c);
			printf("Ban ro la: %d\n", sodu(c, d, n));
		}
		else if (z==3) 
			break;
	}	
	return 0;
}
