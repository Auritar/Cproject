#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#define N 50
#define MSG puts("Tastati pentru a reveni la meniu"); system("pause > nul"); system("cls")
#define MSGEX system("cls"); puts("Graful este deja in baza de date!!!")
#define MSGIN system("cls"); puts("Graful nu a fost introdus in baza de date!!!")
void setcolor(unsigned short color)
{
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon,color);
}

typedef char string[N];

int caractere(int);
void del(string,int,int);
int citMI(int[N][N]);
int citMA(int[N][N]);
int citLA(int[N][N]);
void afMI(int[N][N],int);
void afMA(int[N][N],int);
void afLA(int[N][N],int);
int addV(int[N][N],int,int);
void addA(int[N][N],int,int,int);
int delV(int[N][N],int,int);
void delA(int[N][N],int,int,int);

int main(){
	int opt,virf,dest,n,i,j;
	int graf[N][N];
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			graf[i][j]=0;
	while(opt!=10){
		setcolor(2);
		puts("Meniu:\n");
		puts("\nCitirea grafului:");
		puts("\t0-Matricea de Incidenta");
		puts("\t1-Matricea de Adiacenta");
		puts("\t2-Lista de Adiacenta");
		puts("\nAfisarea grafului:");
		puts("\t3-Matricea de Incidenta");
		puts("\t4-Matricea de Adiacenta");
		puts("\t5-Lista de Adiacenta");
		puts("\nGestionarea grafului:");
		puts("\t6-Adauga virf");
		puts("\t7-Adauga arc");
		puts("\t8-Sterge virf");
		puts("\t9-Sterge arc");
		puts("\t10-Iesire");
		puts("\nIntroduceti optiunea:");
		scanf("%d",&opt);
		switch(opt){
			case 0:
				if(n==0){
					n=citMI(graf);
				}else{
					MSGEX;
					MSG;
				}
				break;
			case 1:
				if(n==0){
					n=citMA(graf);
				}else{
					MSGEX;
					MSG;
				}
				break;
			case 2:
				if(n==0){
					n=citLA(graf);
				}else{
					MSGEX;
					MSG;
				}
				break;
			case 3:afMI(graf,n);break;
			case 4:afMA(graf,n);break;
			case 5:afLA(graf,n);break;
			case 6:
				printf("Introduceti numarul virfului:");
				scanf("%d",&virf);
				if(virf<=n+1)
					n=addV(graf,n,virf);
				else{
					puts("Virful nu poate fi adaugat!!!");
					MSG;
				}
				break;
			case 7:
				if(n!=0){
					printf("Introduceti virful de pornire:");
					scanf("%d",&virf);
					printf("Introduceti virful destinatie:");
					scanf("%d",&dest);
					addA(graf,n,virf,dest);
				}else{
					MSGIN;
					MSG;
				}
				break;
			case 8:
				if(n!=0){
					printf("Introduceti numarul virfului:");
					scanf("%d",&virf);
					n=delV(graf,n,virf);
				}else{
					MSGIN;
					MSG;
				}
				break;
			case 9:
				if(n!=0){
					printf("Introduceti virful de pornire:");
					scanf("%d",&virf);
					printf("Introduceti virful destinatie:");
					scanf("%d",&dest);
					delA(graf,n,virf,dest);
				}else{
					MSGIN;
					MSG;
				}
				break;
		}
	}
}
int citMI(int graf[N][N]){
	int n,arce,i,j,k;
	string linie;
	system("cls");
	printf("Introduceti n:");
	scanf("%d",&n);
	printf("Introduceti numarul arcelor:");
	scanf("%d",&arce);
	fseek(stdin,0,SEEK_END);
	puts("Introduceti matricea de incidenta separata prin spatii");
	for(i=0;i<arce;i++){
		gets(linie);
		for(j=0;j<strlen(linie);j++)
			if((linie[j]=="-") && (linie[j+1]=="1")){
				linie[j]="0";
				linie[j+1]="0";
				break;
			}
		for(k=0;k<strlen(linie);k++)
			switch(linie[k]){
				case "1":
					graf[j/2][k/2]=1;
					break;
				case "2":
					graf[k/2][k/2]=1;
					break;
			}
	}
	puts("Graful a fost introdus cu succes in baza de date");
	MSG;
	return n;
}
int citMA(int graf[N][N]){
	int n,i,j;
	string linie;
	system("cls");
	printf("Introduceti n:");
	scanf("%d",&n);
	fseek(stdin,0,SEEK_END);
	puts("Introduceti matricea de adiacenta separata prin spatii");
	for(i=0;i<n;i++){
		gets(linie);
		for(j=0;j<strlen(linie);j+=2)
			if(linie[j]=="1")
				graf[i][j/2]=1;
	}
	puts("Graful a fost introdus cu succes in baza de date");
	MSG;
	return n;
}
int citLA(int graf[N][N]){
	int n,i,temp;
	string linie;
	system("cls");
	printf("Introduceti n:");
	scanf("%d",&n);
	fseek(stdin,0,SEEK_END);
	puts("Introduceti lista de adiacenta separata prin spatii");
	for(i=0;i<n;i++){
		gets(linie);
		while(linie[0]!="0"){
			temp=atoi(linie);
			graf[i][temp-1]=1;
			del(linie,0,caractere(temp)+1);
		}
	}
	puts("Graful a fost introdus cu succes in baza de date");
	MSG;
	return n;
}
void afMI(int graf[N][N], int n){
	int i,j,k;
	string linie,temp="";
	system("cls");
	if(n!=0){
		for(i=0;i<n;i++){
			strcat(temp," 0 ");
		}
		strcpy(linie,temp);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(graf[i][j]==1){
					if(i!=j){
						linie[i*3]="-";
						linie[i*3+1]="1";
						linie[j*3+1]="1";
						puts(linie);
					}else{
						linie[i*3+1]="2";
						puts(linie);
					}
					strcpy(linie,temp);
				}
	}else{
		MSGIN;
	}
	MSG;
}
void afMA(int graf[N][N], int n){
	int i,j;
	system("cls");
	if(n!=0)
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				printf("%2d",graf[i][j]);
			printf("\n");
		}
	else{
		MSGIN;
	}
	MSG;
}
void afLA(int graf[N][N], int n){
	int i,j;
	system("cls");
	if(n!=0)
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				if(graf[i][j]==1)
					printf("%d_",j+1);
			printf("0\n");
		}
	else{
		MSGIN;
	}
	MSG;
}
int addV(int graf[N][N], int n, int a){
	int i,j;
	system("cls");
	for(i=0;i<n;i++)
		for(j=n-1;j>=a-1;j--)
			if(graf[i][j]==1){
				graf[i][j]=0;
				graf[i][j+1]=1;
			}
	for(i=n;i>=a;i--)
		for(j=0;j<=n;j++)
			graf[i][j]=graf[i-1][j];
	for(i=0;i<=n;i++)
		graf[a-1][i]=0;
	puts("Virful a fost adaugat cu succes");
	MSG;
	return n+1;
}
void addA(int graf[N][N],int n, int v, int d){
	system("cls");
	if(v<=n && d<=n){
		if(graf[v-1][d-1]==1)
			puts("Arcul deja exista!!!");
		else{
			graf[v-1][d-1]=1;
			puts("Arcul a fost adaugat cu succes");
		}
	}else{
		puts("Arcul nu poate fi adaugat!!!");
	}
	MSG;
}
int delV(int graf[N][N], int n, int x){
	int i,j;
	system("cls");
	for(i=0;i<n;i++)
		if(graf[i][x-1]==1)
			graf[i][x-1]=0;
	for(i=x-1;i<n-1;i++)
		for(j=0;j<n;j++)
			graf[i][j]=graf[i+1][j];
	for(i=0;i<n;i++)
		graf[n-1][i]=0;
	
	for(i=0;i<n-1;i++)
		for(j=x-1;j<n;j++)
			if(graf[i][j]==1){
				graf[i][j]=0;
				graf[i][j-1]=1;
			}
			

	puts("Virful a fost sters cu succes");
	MSG;
	return n-1;
}
void delA(int graf[N][N],int n, int v, int d){
	int i;
	system("cls");
	if(v<=n && d<=n){
		if(graf[v-1][d-1]==1){
			graf[v-1][d-1]=0;
			puts("Arcul a fost sters cu succes");
		}else
			puts("Arcul nu a fost gasit!!!");
	}else
		puts("Arcul nu poate fi gasit!!!");
	MSG;
}
void del(string s,int a,int b){
	int i,n;
	n=strlen(s);
	for(i=a;i<=n-b;i++)
		s[i]=s[i+b];
}
int caractere(int nr){
	int i=0;
	do{
		nr=nr/10;
		i++;
	}while(nr!=0);
	return i;
}
