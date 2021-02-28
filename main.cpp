#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "restaurant.cpp"
int main()
{
restaurant *a=NULL;/*element pentru sortare/interschimbare*/
restaurant *b=NULL;/*element pentru sortare/interschimbare*/
restaurant *head2=NULL;;/*element cap pentru divizare*/
char a1[100];/*string 1 pentru interschimbare*/
char b1[100];/*string 2 pentru interschimbare*/
char srch[100];/*string pentru cautare*/
char savef[100];/*string pentru salvare*/
char loadf[100];/*string pentru incarcare*/
int n;/*numarul de elemente in lista*/
int m;/*ciclu infinit meniu principal*/
int com1;/*indice pentru meniu pricipal*/
int mod;/*indice pentru modificare*/
int id_devide;/*indice pentru devizare*/
int id_before;/*indice pentru adaugare inaintea indicelui*/
int id_after;/*indice pentru adaugare dupa indice*/
int id_delete;/*indice pentru stergere a elemenentului*/
while(1)
{
{
system("cls");
printf("/t1.Crearea listei si introducerea datelor manual\n");
printf("/t2.Crearea listei si introducerea datelor din fisier\n\n");
printf("/t3.Afisarea listei\n");
printf("/t4.Sortarea listei dupa numarul de credite\n");
printf("/t5.Modificarea unui element\n");
printf("/t6.Interschimbarea elementelor\n");
printf("/t7.Cautarea unui element\n");
printf("/t8.Devizarea elementelor in doua liste\n");
printf("/t9.Unirea a doua liste cu elemente\n\n");
printf("/t10.Adaugarea elementului  inaintea indicelui\n");
printf("/t11.Adaugarea elementului dupa indice\n");
printf("/t12.Adaugarea elementului la sfirsitul listei\n");
printf("/t13.Stergea unui element\n\n");
printf("/t14.Salvarea in fisier\n");
printf("/t15.Iesire\n");
printf("\n Dati comanda\n>");
scanf("%d",&com1);
switch(com1)
{
case 1:
system("cls");
if(head)
{
printf("Memoria este deja alocata\n");
system("pause");
m=1;
break;
}
system("cls");
printf("\tDati numarul de elemente in lista\n>");
scanf("%d",&n);
create(n);
read();
if(head)
{
system("cls");
printf("\tLista a fost creata cu succes!\a\n");
system("pause");
m=1;
break;
}
case 2:
system("cls");
if(head)
{
printf("\tMemoria este deja alocata\n");
system("pause");
m=1;
break;
}
printf("\tDati numele fisierului\n>");
fflush(stdin);
gets(loadf);
strcat(loadf,".txt");
load(loadf);
printf("\a\tIntroducerea a fost efectuata cu succes!\n");
m=1;
system("pause");
break;
case 3:
system("cls");
if(!head)
{
printf("\tLista nu exista!\a\n");
m=1;
system("pause");
break;
}
show(head);
system("pause");
m=1;
break;
case 4:
system("cls");
if(!head)
{
printf("\tLista nu exista!\a\n");
m=1;
system("pause");
break;
}
sort();
printf("\tLista a fost sortata cu succes!\a\n");
system("pause");
m=1;
break;
case 5:
system("cls");
if(!head)
{
printf("\tLista nu exista!\a\n");
m=1;
system("pause");
break;
}
show(head);
printf("\n\tDati indicile elementului pentru modificare\n>");
scanf("%d",&mod);
system("cls");
modif(mod);
printf("\tModificara a avut loc cu succes!\a\n");
m=1;
system("pause");
break;
case 6:
system("cls");
if(!head)
{
printf("\tLista nu exista!\a\n");
m=1;
system("pause");
break;
}
show(head);
printf("\tDati numele primului element pentru interschimbare\n>");
fflush(stdin);
gets(a1);
a=search(a1);
printf("\tDati numele aldoilea element pentru interschimbare\n>");
fflush(stdin);
gets(b1);
b=search(b1);
system("cls");
swap(a,b);
printf("\tInterschimbarea a avut loc cu succes!\a\n");
m=1;
system("pause");
break;
case 7:
system("cls");
if(!head)
{
printf("\tLista nu exista!\a\n");
m=1;
system("pause");
break;
}
printf("\tDati denumirea\\adresa\\specializare\\Numarul de locuri\\Telefonul\\ categoria\\ pentru cautare\n>");
fflush(stdin);
gets(srch);
show_search(srch);
m=1;
system("pause");
break;
case 8:
system("cls");
if(!head)
{
printf("\tLista nu exista!\a\n");
m=1;
system("pause");
break;
}
show(head);
printf("\n\tIntrodu indicile de unde lista v-a fi despartita\n");
scanf("%d",&id_devide);
if(lenght() > 1 && id_devide>0 && id_devide < lenght()){
devide(id_devide,&head2);
}
printf("\tDevizarea a fost efectuata cu succes!\a\n");
show(head);
show(head2);
m=1;
system("pause");
break;
case 9:
system("cls");
if(!head){
printf("Lista nu exista!\a\n");
m=1;
system("pause");
break;
}
if(head2){
join(&head2);
printf("\tUnirea a avut loc cu succes\n");
}
else {
printf("\a\tMai intii lista trebuie despartita!\n");
}
m=1;
system("pause");
break;
case 10:
system("cls");
if(!head){
printf("\tLista nu exista!\a\n");
m=1;
system("pause");
break;
}
show(head);
printf("\n\tIntrodu numarul de ordine:\n");
scanf("%d",&id_before);
if(id_before > 0 && id_before <= lenght() ){
system("cls");
add_before_id(id_before);
}
else {
printf("\a\tAti introdus un numar iesit din intervalul existent\n");
}
system("cls");
printf("\tAdaugarea s-a efectuat cu succes!\a\n");
m=1;
system("pause");
break;
case 11:
system("cls");
if(!head){
printf("\tLista nu exista!\a\n");
m=1;
system("pause");
break;
}
show(head);
printf("\n\tIntrodu numarul de ordine:\n");
scanf("%d",&id_after);
if(id_after > 0 && id_after <= lenght() ){
system("cls");
add_after_id(id_after);
}
else {
printf("\a\tAti introdus un numar iesit din intervalul existent\n");
}
system("cls");
printf("\tAdaugarea s-a efectuat cu succes!\a\n");
m=1;
system("pause");
break;
case 12:
system("cls");
if(!head){
printf("\tLista nu exista!\a\n");
m=1;
system("pause");
break;
}
add_to_end();
system("cls");
printf("\tAdaugarea s-a efectuat cu succes!\a\n");
m=1;
system("pause");
break;
case 13:
system("cls");
if(!head){
printf("\tLista nu exista!\a\n");
m=1;
system("pause");
break;
}
show(head);
printf("\tDati indicele elementului pentru stergere\n");
scanf("%d",&id_delete);
delete_id(id_delete);
system("cls");
printf("\tStergerea a fost efectuata cu succes!\a\n");
m=1;
system("pause");
break;
case 14:
system("cls");
printf("\tDati numele fisierului\n>");
fflush(stdin);
gets(savef);
save(savef);
printf("\a\tSalvarea a fost efectuata cu succes!\n");
m=1;
system("pause");
break;
case 15:
system("cls");
if(head)
{
printf("\a\tToate operatiunile au fost efectuate cu succes!\n");
puts("GOOD BYE");
system("pause");
freem();
exit(1);
}
break;

default:
system("cls");
printf("\tAti introdus o tasta incorecta!\a\n");
m=1;
system("pause");
break;
}
}
}
return 0;
}
