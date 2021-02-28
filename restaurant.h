typedef struct restaurant
{
char denumire [100];
char adresa [100];
char specializare [100];
int nr_loc;
int telefonul;
int categoria;
struct disciplina *next;
}restaurant;
restaurant* head;


/* 
typedef struct disciplina
{
char denumire [100];
char universitatea [100];
char profesor [100];
char specialitatea [100];
int numaruldecredite;
struct disciplina *next;
}disciplina;
disciplina* head;

*/
