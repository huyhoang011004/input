#include <stdio.h>
#include <string.h>
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
int nghichdao(int a)
{
	int k, du, ngd;
	k = 1; 
		do
		{ 
			du = (k*26+1)%a ;
			if ( du==0 ) 
				ngd = (k*26+1)/a ; 
			k++; 
		} 
		while (du!=0);
	return ngd;
}
int mod26(int a){
	if (a>=0) a= a%26;
	else a= 26-(-a)%26;
	return a;
}
void mahoa(char *x, int a[][5])
{
	int l = strlen(x), j=0, n=1;
	char t[100], y[100];
	int detk = a[1][1] * a[2][2] - a[2][1] * a[1][2];
	printf("\nDetK = (%d*%d-%d*%d)mod26 = (%d)mod26 = %d\n", a[1][1], a[2][2], a[2][1], a[1][2], detk, mod26(detk));
	mod26(detk);
	if (l%2==0) x[l-1] = 'a';
	for (int i=0; i<l-1; i++)
		t[i]=x[i];
	if (gcd(detk,26)!=1)
		printf("Khong ma hoa duoc\n");
	else
	{
		for (int i=0; i<l; i++)
			if (x[i]>='A' && x[i]<='Z')
        	x[i] = x[i]-'A';
    		else if (x[i]>='a' && x[i]<='z')
        	x[i] = x[i]-'a';
		for (int i=0; i<=l-2; i+=2)
			{
				y[i]= (x[i]*a[1][1]+x[i+1]*a[2][1])%26;
				y[i+1]= (x[i]*a[1][2]+x[i+1]*a[2][2])%26;
			}	
		while (j<=l-2)
		{
			printf("Voi P%d = (%d %d) ta co C%d = P%d * K = (%d %d) (%d %d) = (%d %d) = ",
					n, x[j], x[j+1], n, n, x[j], x[j+1], a[1][1], a[1][2], y[j], y[j+1]);
			if (t[j]>='A' && t[j]<='Z' && y[j]>=0 && y[j]<=25)
        	{
        		y[j] = y[j]+'A';
        		y[j+1] = y[j+1]+'A';
			}	
    		else if (t[j]>='a' && y[j]<='z' && y[j]>=0 && y[j]<=25)
        	{
        		y[j] = y[j]+'a';
        		y[j+1] = y[j+1]+'a';
			}
        	printf("(%c %c)\n", y[j], y[j+1]); 
        	if (x[j]>9) printf("  "); 
        	if (x[j+1]>9) printf("  ");
			printf("                                         (%d %d)\n", a[2][1], a[2][2]);
			j+=2; n++;
		}
	y[l-1]='\0';
	printf("Ban ma la: %s\n", y);	
	}
}
void giaima(char *x, int a[][5])
{
	int l = strlen(x), j=0, n=1, tg, detk1;
	char t[100], y[100];
	int detk = a[1][1] * a[2][2] - a[2][1] * a[1][2];
	printf("\nDetK = (%d*%d-%d*%d)mod26 = (%d)mod26 = %d\n", a[1][1], a[2][2], a[2][1], a[1][2], detk, mod26(detk));
	mod26(detk);
	for (int i=0; i<l-1; i++)
		t[i]=x[i];
	if (gcd(detk,26)!=1)
		printf("Khong giai ma duoc\n");
	else
	{
		tg = a[1][1]; a[1][1] = a[2][2]; a[2][2] = tg; 
		a[1][2] = -a[1][2]; a[2][1] = - a[2][1];
		printf("GCD(%d,26) = 1, ta co det(K)-1 = %d\n", detk, nghichdao(detk));
		detk1 = nghichdao(detk);
		printf("Ma tran phu hop cua K\n");
		printf("(K)ph = (%d %d) mod 26 = (%d %d)\n", a[1][1], a[1][2], mod26(a[1][1]), mod26(a[1][2]));
		printf("        (%d %d)", a[2][1], a[2][2]);
		printf("          (%d %d)", mod26(a[2][1]), mod26(a[2][2]));
		mod26(a[1][1]); mod26(a[1][2]); mod26(a[2][1]); mod26(a[2][2]);
		printf("\nTa co (K)-1 = %d * (%d %d) = (%d %d)", detk1, a[1][1], a[1][2], mod26(detk1*a[1][1]), mod26(detk1*a[1][2]));
		printf("\n                 ");
		if (detk1 <=9) printf(" ");
		printf("(%d %d)   (%d %d)\n", detk1, a[2][1], a[2][2], mod26(detk1*a[2][1]), mod26(detk1*a[2][2]));
		a[1][1] = mod26(detk1*a[1][1]); a[1][2] = mod26(detk1*a[1][2]);
		a[2][1] = mod26(detk1*a[2][1]); a[2][2] = mod26(detk1*a[2][2]);
		for (int i=0; i<l; i++)
			if (x[i]>='A' && x[i]<='Z')
        	x[i] = x[i]-'A';
    		else if (x[i]>='a' && x[i]<='z')
        	x[i] = x[i]-'a';
		for (int i=0; i<=l-2; i+=2)
			{
				y[i]= (x[i]*a[1][1]+x[i+1]*a[2][1])%26;
				y[i+1]= (x[i]*a[1][2]+x[i+1]*a[2][2])%26;
			}	
		while (j<=l-2)
		{
			printf("Voi P%d = (%d %d) ta co C%d = P%d * K = (%d %d) (%d %d) = (%d %d) = ",
					n, x[j], x[j+1], n, n, x[j], x[j+1], a[1][1], a[1][2], y[j], y[j+1]);
			if (t[j]>='A' && t[j]<='Z' && y[j]>=0 && y[j]<=25)
        	{
        		y[j] = y[j]+'A';
        		y[j+1] = y[j+1]+'A';
			}	
    		else if (t[j]>='a' && y[j]<='z' && y[j]>=0 && y[j]<=25)
        	{
        		y[j] = y[j]+'a';
        		y[j+1] = y[j+1]+'a';
			}
        	printf("(%c %c)\n", y[j], y[j+1]); 
        	if (x[j]>9) printf("  ");
			if (x[j+1]>9) printf("  "); 
			printf("                                         (%d %d)\n", a[2][1], a[2][2]);
			j+=2; n++;
		}
	y[l-1]='\0';
	printf("Ban ro la: %s\n", y);	
	}
}
void mahoa3(char *x, int a[][5], int detk)
{
	int l = strlen(x), j=0, n=1;
	char t[100], y[100];
	if ((l-1)%3==1) 
	{
		x[l-1] = 'a';
		x[l] = 'a';
	}
	else if ((l-1)%3==2) 
		x[l-1] = 'a';
	for (int i=0; i<l+1; i++)
		t[i]=x[i];
	if (gcd(detk,26)!=1)
		printf("Khong ma hoa duoc\n");
	else
	{
		for (int i=0; i<=l+1; i++)
			if (x[i]>='A' && x[i]<='Z')
        	x[i] = x[i]-'A';
    		else if (x[i]>='a' && x[i]<='z')
        	x[i] = x[i]-'a';
		for (int i=0; i<l; i+=3)
			{
				y[i]  = (x[i]*a[1][1] + x[i+1]*a[2][1] + x[i+2]*a[3][1])%26;
				y[i+1]= (x[i]*a[1][2] + x[i+1]*a[2][2] + x[i+2]*a[3][2])%26;
				y[i+2]= (x[i]*a[1][3] + x[i+1]*a[2][3] + x[i+2]*a[3][3])%26;
			}	
		while (n<=(l+1)/3)
		{
			printf("Voi P%d = (%d %d %d) ta co C%d = P%d * K = (%d %d %d) (%d %d %d) = (%d %d %d) = ",
					n, x[j], x[j+1], x[j+2], n, n, x[j], x[j+1], x[j+2], a[1][1], a[1][2], a[1][3], y[j], y[j+1], y[j+2]);
			if (t[j]>='A' && t[j]<='Z' && y[j]>=0 && y[j]<=25)
        	{
        		y[j] = y[j]+'A';
        		y[j+1] = y[j+1]+'A';
        		y[j+2] = y[j+2]+'A';
			}	
    		else if (t[j]>='a' && y[j]<='z' && y[j]>=0 && y[j]<=25)
        	{
        		y[j] = y[j]+'a';
        		y[j+1] = y[j+1]+'a';
        		y[j+2] = y[j+2]+'a';
			}
        	printf("(%c %c %c)\n", y[j], y[j+1], y[j+2]); 
        	if (x[j]>9) printf("  "); 
        	if (x[j+1]>9) printf("  ");
        	if (x[j+2]>9) printf("  ");
			printf("                                             (%d %d %d)\n", a[2][1], a[2][2], a[2][3]);
			if (x[j]>9) printf("  "); 
        	if (x[j+1]>9) printf("  ");
        	if (x[j+2]>9) printf("  ");
			printf("                                             (%d %d %d)\n", a[3][1], a[3][2], a[3][3]);
			j+=3; n++;
		}
	y[l-1]='\0';
	printf("Ban ma la: %s\n", y);	
	}
}
int main()
{
	char x[100];
	int idx=1, z1, z2, m, a[5][5], detk;
	while (true)
	{
		if (idx==1)
			printf("Xin chao, toi la chuong trinh giai bai tap ma hill, ban muon giai dang bai tap nao ?\n");
		else 
		{
			printf("\nBan co tiep tuc giai bai tap khong ?\n");
			printf("1. Co\n2. Khong\n"); scanf("%d", &z1);
			if (z1==2) break;
			printf("\nMoi ban chon dang bai tap:\n");
		}
		idx =2;
		printf("1. Kiem tra ma tran K co the lam khoa khong? \n2. Ma hoa\n3. Giai ma\n"); scanf("%d", &z2); printf("\n");
		printf("Nhap M = "); scanf("%d", &m);
		if (m==2)
		{
			printf("Nhap k = (k11 k12) = "); scanf("%d", &a[1][1]); scanf("%d", &a[1][2]); 
			printf("         (k21 k22) = "); scanf("%d", &a[2][1]); scanf("%d", &a[2][2]);	
			getchar();
			if(z2==1) 
			{
				detk = a[1][1] * a[2][2] - a[2][1] * a[1][2];
				printf("\nDetK = (%d*%d-%d*%d)mod26 = (%d)mod26 = %d\n", a[1][1], a[2][2], a[2][1], a[1][2], detk, mod26(detk));
				mod26(detk);
				if(gcd(detk,26)==1) printf("Ma tran K thoa man dieu kien lam khoa cua he ma\n");
				else printf("Ma tran K khong thoa man dieu kien lam khoa cua he ma\n");
			}
			else if(z2==2)
			{
				printf("Nhap ban ro: "); fgets(x,sizeof(x),stdin);
				mahoa(x, a);
			}
			else if(z2==3)
			{
				printf("Nhap ban ma: "); fgets(x,sizeof(x),stdin);
				giaima(x, a);
			}	
		}
		else if (m==3)
		{
			printf("Nhap k = (k11 k12 k13) = "); scanf("%d", &a[1][1]); scanf("%d", &a[1][2]); scanf("%d", &a[1][3]);
			printf("         (k21 k22 k23) = "); scanf("%d", &a[2][1]); scanf("%d", &a[2][2]); scanf("%d", &a[2][3]);
			printf("         (k31 k32 k33) = "); scanf("%d", &a[3][1]); scanf("%d", &a[3][2]); scanf("%d", &a[3][3]);
			getchar();
			detk = a[1][1]*a[2][2]*a[3][3] + a[1][2]*a[2][3]*a[3][1] + a[2][1]*a[3][2]*a[1][3] 
				 - a[3][1]*a[2][2]*a[1][3] - a[2][1]*a[1][2]*a[3][3] - a[3][2]*a[2][3]*a[1][1];
			printf("DetK = (%d*%d*%d + %d*%d*%d + %d*%d*%d - %d*%d*%d - %d*%d*%d - %d*%d*%d)mod26 = (%d)mod26 = %d\n",
			       a[1][1],a[2][2],a[3][3] , a[1][2],a[2][3],a[3][1] , a[2][1],a[3][2],a[1][3], 
				   a[3][1],a[2][2],a[1][3] , a[2][1],a[1][2],a[3][3] , a[3][2],a[2][3],a[1][1],
				   detk, mod26(detk));
			detk = mod26(detk);
			if (z2==1)
			{
				if(gcd(detk,26)==1) printf("Ma tran K thoa man dieu kien lam khoa cua he ma\n");
				else printf("Ma tran K khong thoa man dieu kien lam khoa cua he ma\n");
			}
			else if (z2==2)
			{
				printf("Nhap ban ro: "); fgets(x, sizeof(x), stdin);
				mahoa3(x, a, detk);
			}
			else if (z2==3) printf("Khong giai duoc, ma tran phu hop qua phuc tap\n");
		}
	}
	return 0;
}
