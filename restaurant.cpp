#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "restaurant.h"
int create(int n)
{
int i;
restaurant *c,*p;
for(i=0;i<n;i++)
{
c=(restaurant*)malloc(sizeof(restaurant));
if(c == NULL) return 0;
if(i == 0)
{
head=c;
p=c;
}
else
{
p->next=c;
p=c;
}
}
p->next=NULL;
return 1;
}
void read()
{
restaurant *c=head;
int i=0;
while(c)
{
printf("Introdu datele restaurantului %d\n",i+1);
printf("Denumire: ");
scanf("%s",&c->denumire);
printf("Adresa: ");
scanf("%s",&c->adresa);
printf("Specializare: ");
scanf("%s",&c->specializare);
printf("Numarul de locuri: ");
scanf("%d",&c->nr_loc);
printf("Telefonul: ");
scanf("%d",&c->telefonul);
printf("Categoria: ");
scanf("%d",&c->categoria); 
c=c->next;
i++;
}
}
void show(restaurant* head)
{
restaurant* c=head;
int i=0;
while(c)
{
printf("Datele :                          [%d]\n",i+1);
printf("Denumire:                         %s\n",c->denumire);
printf("Universitatea:                    %s\n",c->adresa);
printf("Profesor:                         %s\n",c->specializare);
printf("Specialitatea:                    %d\n",c->nr_loc);
printf("Telefonul:                        %d\n\n",c->telefonul);
printf("Categoria:                        %d\n\n",c->categoria);
printf("Adresa curenta:                   %p\n",c);
printf("Adresa elementului urmator:       %p\n",c->next);
c=c->next;
i++;
}
}
void show_search(char* s)
{
restaurant *c=head;
int i=0,k=0;
while(c)
{
if((strcmp(s,c->denumire)==0) || (strcmp(s,c->adresa)==0 ) || (strcmp(s,c->specializare)==0))
{

printf("Datele disciplinei:         %d\n",i+1);
printf("Denumire:                   %s\n",c->denumire);
printf("Adresa:                     %s\n",c->adresa);
printf("Specializare:               %s\n",c->specializare);
printf("Numarul de locuri:          %d\n\n",c->nr_loc);
printf("Telefonul:                  %d\n",c->telefonul);
printf("Categoria:                  %d\n",c->categoria);
k++;
}
c=c->next;
i++;
}
if(k==0)
printf("\tElementul nu a fost gasit!\n");
}
restaurant* search(char* s)
{
restaurant* c;
c=head;
int k=0;
while(c)
{
if((stricmp(c->denumire,s)==0) || (stricmp(c->adresa,s)==0) || (stricmp(c->specializare,s)==0))
{return c;}
c=c->next;
if(c==head) break;
k++;
}
printf("\tNu exista asa disciplini!\n");
return NULL ;}
void swap(restaurant *a,restaurant *b)
{
restaurant t,*na,*nb;
na=a->next;
nb=b->next;
t=*a;
*a=*b;
*b=t;
a->next=na;
b->next=nb;
return;
}
int lenght()
{
restaurant *c=head;
int i=0;
while(c)
{
i++;
c=c->next;
}
return i;
}
void sort()
{
restaurant *a,*b;
int i,k,l;
l=lenght();
for(i=0;i<l-1;i++)
{
a=head;
b=a->next;
for(k=0;k<l-1-i;k++)
{
if(a->telefonul < b->telefonul)
{
swap(a,b);
}
a=a->next;
b=b->next;
}
}
}
restaurant* end()
{
restaurant* c;
c=head;
while(c->next)
{
c=c->next;
}
return c;
}
void modif(int id)
{
restaurant* c=head;
int i=0;
int f;
while(c)
{
if(i+1 == id)
{
printf("\tDatele Restaurantului pentru modificare:%d\n",i+1);
	puts("\tDoriti sa mofificati denumirea? 1/0");
	scanf("%d",&f);
	if (f==1){
	printf("\tDenumire: ");
	scanf("%s",&c->denumire);
	}
	puts("\tDoriti sa mofificati adresa? 1/0");
	scanf("%d",&f);
	if (f==1){
	printf("\tAdresa: ");
	scanf("%s",&c->adresa);	
	}
	puts("\tDoriti sa mofificati specializarea? 1/0");
	scanf("%d",&f);
	if (f==1){
	printf("\tSpecializarea: ");
	scanf("%s",&c->specializare);	
	}
	puts("\tDoriti sa mofificati numarul de locuri? 1/0");
	scanf("%d",&f);
	if (f==1){
	printf("\tNumarul de locuri: ");
	scanf("%d",&c->nr_loc);	
	}
	puts("\tDoriti sa mofificati telefonul? 1/0");
	scanf("%d",&f);
	if (f==1){
	printf("\tTelefonul: ");
	scanf("%d",&c->telefonul);
	puts("\tDoriti sa mofificati categoria? 1/0");
	scanf("%d",&f);
	if (f==1){
	printf("\tCategoria: ");
	scanf("%d",&c->categoria);
	}


}
c=c->next;
i++;
}
}
void add_after_id(int id)
{
restaurant *c=head,*p;
int i=0;
while(c){
if(i == id-1){
p=c;
c=(restaurant*)malloc(sizeof(restaurant));
printf("Introdu datele disciplinei %d\n",i+2);
printf("Denumire: ");
scanf("%s",&c->denumire);
printf("Adresa: ");
scanf("%s",&c->adresa);
printf("Specializare: ");
scanf("%s",&c->specializare);
printf("Numarul de locuri ");
scanf("%d",&c->nr_loc);
printf("Telefonul: ");
scanf("%d",&c->telefonul);
printf("Categoria: ");
scanf("%d",&c->categoria);
c->next=p->next;
p->next=c;
break;
}
i++;
c=c->next;
}
}
void add_before_id(int id){
restaurant *c=head,*p;
int i=0;
while(c){
if(i == id-1){
p=c;
c=(restaurant*)malloc(sizeof(restaurant));
printf("Introdu datele disciplinei\n");
printf("Denumire: ");
scanf("%s",&c->denumire);
printf("Adresa: ");
scanf("%s",&c->adresa);
printf("Specializare: ");
scanf("%s",&c->specializare);
printf("Numarul de locuri ");
scanf("%d",&c->nr_loc);
printf("Telefonul: ");
scanf("%d",&c->telefonul);
printf("Categoria: ");
scanf("%d",&c->categoria);
if(p == head){
c->next=head;
head=c;
break;
}
else {
c->next=p;
i=0;
p=head;
while(p){
if(i == id-2){
p->next=c;
}
i++;
p=p->next;
}
break;
}
}
i++;
c=c->next;
}
}
void add_to_end(){
restaurant *c=head,*p;
while(c){
if(c->next == NULL){
p=c;
c=(restaurant*)malloc(sizeof(restaurant));
printf("Introdu datele disciplinei\n");
printf("Denumire: ");
scanf("%s",&c->denumire);
printf("Adresa: ");
scanf("%s",&c->adresa);
printf("Specializare: ");
scanf("%s",&c->specializare);
printf("Numarul de locuri ");
scanf("%d",&c->nr_loc);
printf("Telefonul: ");
scanf("%d",&c->telefonul);
printf("Categoria: ");
scanf("%d",&c->categoria);
p->next=c;
c->next=NULL;
break;
}
c=c->next;
}
}
void delete_id(int id){
restaurant *c=head,*p;
int i=0;
while(c){
if(i == id-1){
if(c == head){
head=c->next;
free(c);
break;
} else if(c->next == NULL){
p=head;
while(p){
if(p->next == c){
free(c);
p->next=NULL;
break;
}
p=p->next;
}
} else {
p=head;
while(p){
if(p->next == c){
p->next=c->next;
free(c);
break;
}
p=p->next;
}   }
}
i++;
c=c->next;
}
}
void devide(int id,restaurant** head2){
restaurant *c=head;
int i=0;
while(c){
if(i == id-1){
*head2=c->next;
c->next=NULL;
break;
}
i++;
c=c->next;
}
}
void join(restaurant** head2){
restaurant *c=head;
while(c){
if(c->next == NULL){
c->next=*head2;
break;
}
c=c->next;
}
*head2=NULL;
}

void freem()
{
restaurant *c=head,*p;
while(c)
{
p=c;
c=c->next;
free(p);
if(c == NULL)
{
break;
}
}
head=NULL;
}
void save(char* fname)
{
restaurant*c=head;
FILE *txt=fopen(fname,"wt");
while(c)
{
fprintf(txt,"%s%s%s%d%d%d",&c->denumire,&c->adresa,&c->specializare,&c->nr_loc,&c->telefonul, &c->categoria);
if(c->next != NULL)
{
fprintf(txt, "\n");
}
c=c->next;
}
fclose(txt);
}
void load(char* fname)
{
restaurant* c,*p;
int i=0;
FILE *txt=fopen(fname,"r");
if(!txt)
{
printf("Fisierul nu exista!\a\n");
}
while(!feof(txt))
{
c=(restaurant*)malloc(sizeof(restaurant));
if(c == NULL)
{
printf("\aMemoria nu a fost alocata\n");
}
if(i == 0)
{
head=c;
p=c;
}
else
{
p->next=c;
p=c;
}
fscanf(txt,"%s%s%s%d%d%d",&c->denumire,&c->adresa,&c->specializare,&c->nr_loc,&c->telefonul, &c->categoria);
i++;

p->next=NULL;
fclose(txt);
}
}
