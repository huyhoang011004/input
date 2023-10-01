#include <stdio.h>
#include <string.h>
int mod26(int a){
	if (a>=0) a= a%26;
	else a= 26-(-a)%26;
	return a;
}
void inso(char *x, int i, int m){
	if(x[i]>9) printf("%d ",x[i]);
	else printf("%d  ", x[i]);
	if((i>0)&&((i+1)%m==0)) printf("	 ");
}
void mahoa(char *k, char *x, char *y, int m)
{
	char t[100];
	int i, lx, lk;
	lx = strlen(x); lk = strlen(k);
	for (i=0; i<lx-1; i++)
		t[i]=x[i];
// k = ( so cua tung ki tu trong k )
	printf("\nk = (");
	for (i=0; i<lk-1; i++)
	{
		if (k[i]>='A' && k[i]<='Z')
        	k[i]=k[i]-'A';
        else if (k[i]>='a' && k[i]<='z')
        	k[i]=k[i]-'a';
		if (i==0) printf("%d",k[i]);
		else printf(", %d",k[i]);
	}
	printf(")\n");
//tach ban ro thanh tung chuoi co do dai m
	printf("\n     ");
	for (i=0; i<lx-1; i++)
	{
		printf("%c  ",x[i]);
		if((i>0)&&((i+1)%m==0)) printf("	 ");
	}
//so cua tung ki tu trong ban ro
	printf("\n     ");
	for (i=0; i<lx-1; i++)
	{	
		if (x[i]>='A' && x[i]<='Z')
        	x[i] = x[i]-'A';
    	else if (x[i]>='a' && x[i]<='z')
        	x[i] = x[i]-'a';
		inso(x, i, m);
	}
	printf("\n  +  ");
//so cua tung ki tu trong khoa k
	printf("\n     ");
	for (i =0 ; i < lx -lk; i++ )
 	  	k[i+lk-1] = k[i];
 	for (i=0; i<lx-1; i++)
	{
		inso(k, i, m);
	}
	printf("\n_____");
	for (i=0; i<lx; i++) 
	{
		printf("___");
		if((i>0)&&((i+1)%m==0)) printf("______");
	}
	printf("\n     ");
	for (i=0; i<lx-1; i++)
	{
		y[i] = x[i] + k[i];
		inso(y, i, m);
	}
	printf("\nmod26");
	printf("\n     ");
	for (i=0; i<lx-1; i++)
	{
		y[i]= y[i] % 26;
		inso(y, i, m);
	}
	printf("\n     ");
	for (i=0; i<lx-1; i++)
	{
		if (t[i]>='A' && t[i]<='Z')
        	y[i] = y[i]+'A';
    	else if (t[i]>='a' && y[i]<='z')
        	y[i] = y[i]+'a';
		printf("%c  ",y[i]);
		if((i>0)&&((i+1)%m==0)) printf("	 ");
	}
	printf("\n\nBan ma la: %s\n\n", y);
}

void giaima(char *k, char *x, char *y, int m)
{
	char t[100];
	int i, lx, lk;
	lx = strlen(x); lk = strlen(k);
	for (i=0; i<lx-1; i++)
		t[i]=x[i];
// k = ( so cua tung ki tu trong k )
	printf("\nk = (");
	for (i=0; i<lk-1; i++)
	{
		if (k[i]>='A' && k[i]<='Z')
        	k[i]=k[i]-'A';
        else if (k[i]>='a' && k[i]<='z')
        	k[i]=k[i]-'a';
		if (i==0) printf("%d",k[i]);
		else printf(", %d",k[i]);
	}
	printf(")\n");
//tach ban ma thanh tung chuoi co do dai m
	printf("\n     ");
	for (i=0; i<lx-1; i++)
	{
		printf("%c  ",x[i]);
		if((i>0)&&((i+1)%m==0)) printf("	 ");
	}
//so cua tung ki tu trong ban ro
	printf("\n     ");
	for (i=0; i<lx-1; i++)
	{	
		if (x[i]>='A' && x[i]<='Z')
        	x[i] = x[i]-'A';
    	else if (x[i]>='a' && x[i]<='z')
        	x[i] = x[i]-'a';
		inso(x, i, m);
	}
	printf("\n  -  ");
//so cua tung ki tu trong khoa k
	printf("\n     ");
	for (i =0 ; i < lx -lk; i++ )
 	  	k[i+lk-1] = k[i];
 	for (i=0; i<lx-1; i++)
	{
		inso(k, i, m);
	}
	printf("\n_____");
	for (i=0; i<lx; i++) 
	{
		printf("___");
		if((i>0)&&((i+1)%m==0)) printf("______");
	}
	printf("\n     ");
//kqpheptru
	for (i=0; i<lx-1; i++)
	{
		y[i] = x[i] - k[i];
		if(y[i]>9 || (y[i]>=-9 && y[i] <0)) printf("%d ",y[i]);
		else if(y[i]>=0 && y[i]<=9)printf("%d  ", y[i]);
		else printf("%d", y[i]);
		if((i>0)&&((i+1)%m==0)) printf("	 ");
	}
	printf("\nmod26");
//kqmod26
	printf("\n     ");
	for (i=0; i<lx-1; i++)
	{
		y[i]= mod26(y[i]);
		inso(y, i, m);
	}
	printf("\n     ");
	for (i=0; i<lx-1; i++)
	{
		if (t[i]>='A' && t[i]<='Z')
        	y[i] = y[i]+'A';
    	else if (t[i]>='a' && y[i]<='z')
        	y[i] = y[i]+'a';
		printf("%c  ",y[i]);
		if((i>0)&&((i+1)%m==0)) printf("	 ");
	}
	printf("\n\nBan ro la: %s\n\n", y);
}
void timk(char *y, char *x, int m)
{
	char k[100];
	int i;
	x[m]='\0'; y[m]='\0';
	printf("     ");
	for (i=0; i<m; i++)
		printf("%c  ",y[i]);
	printf("  =  ");
	for (i=0; i<m; i++)
	{	
		if (y[i]>='A' && y[i]<='Z')
        	y[i] = y[i]-'A';
    	else if (y[i]>='a' && y[i]<='z')
        	y[i] = y[i]-'a';
		inso(y, i, m);
	}
	printf("\n  -  ");
	printf("\n     ");
	for (i=0; i<m; i++)
		printf("%c  ",x[i]);
	printf("  =  ");
	for (i=0; i<m; i++)
	{	
		if (x[i]>='A' && x[i]<='Z')
        	x[i] = x[i]-'A';
    	else if (x[i]>='a' && x[i]<='z')
        	x[i] = x[i]-'a';
		inso(x, i, m);
	}
	printf("\n     ");
	for (i=0; i<m; i++) printf("   ");
	printf("  _____");
	for (i=0; i<m; i++) printf("___");
	printf("\n       ");
	for (i=0; i<m; i++) printf("   ");
	for (i=0; i<m; i++) 
	{
		k[i] = y[i]-x[i];
		inso(k, i, m);
	}
	printf("\n");
	for (i=0; i<m; i++) printf("   ");
	printf("mod26");
	printf("\n       ");
	for (i=0; i<m; i++) printf("   ");
	for (i=0; i<m; i++) 
	{
		k[i] = mod26(k[i]);
		inso(k, i, m);
	}
	printf("\n       ");
	for (i=0; i<m; i++) printf("   ");
	for (i=0; i<m; i++) 
	{
		k[i] = k[i]+'A';
		printf("%c  ", k[i]);
	}
	printf("\nKhoa k can tim la: %s\n\n", k);
}
int main()
{
	char k[100], x[100], t[100], y[100];
	int m, i, lx, lk, z1, z2, idx =1; 
	while (true)
	{
		if (idx==1)
			printf("Xin chao, toi la chuong trinh giai bai tap ma vigenere, ban muon giai dang bai tap nao ?\n");
		else 
		{
			printf("Ban co tiep tuc giai bai tap khong ?\n");
			printf("1. Co\n2. Khong\n"); scanf("%d", &z1);
			if (z1==2) break;
			printf("\nMoi ban chon dang bai tap:\n");
		}
		idx =2;
		printf("1. Ma hoa\n2. Giai ma\n3. Tim khoa k\n"); scanf("%d", &z2); printf("\n");
		if (z2==1)
		{
			printf("Nhap M = "); scanf("%d", &m); getchar();
			printf("Nhap k: "); fgets(k,sizeof(k),stdin);
			printf("Nhap ban ro: "); fgets(x,sizeof(x),stdin);
			mahoa(k, x, y, m);
		}
		else if (z2==2)
		{
			printf("Nhap M = "); scanf("%d", &m); getchar();
			printf("Nhap k: "); fgets(k,sizeof(k),stdin);
			printf("Nhap ban ma: "); fgets(x,sizeof(x),stdin);
			giaima(k, x, y, m);
		}
		else if (z2==3)
		{
			printf("Nhap M = "); scanf("%d", &m); getchar();
			printf("Nhap ban ma: "); fgets(y,sizeof(y),stdin);
			printf("Nhap ban ro: "); fgets(x,sizeof(x),stdin);
			timk(y, x, m);			
		}		
		else if (z2==4) break;
	}
	return 0; 
}
