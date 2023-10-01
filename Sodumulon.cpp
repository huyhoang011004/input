#include <stdio.h>
#include <string.h>
int main(){
	int m,e,n;
	printf("Nhap co so M = "); scanf("%d", &m);
	printf("Nhap so mu e = "); scanf("%d", &e);
	printf("Nhap so mod n = "); scanf("%d", &n);
	int a[1000], i, p=1 ;
	for(i=0; e>0; i++)
	{
		a[i]=e%2;
		e=e/2;
	}
	for(i; i>=0; i--)
	{
		p = p*p;
		p = p % n;
		if(a[i]==1)
		{
			p = p*m;
			p = p % n;
		}
	}
	printf("So du la: %d",p);
	return 0;
}
