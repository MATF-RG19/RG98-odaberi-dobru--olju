#ifndef DRAW
#define DRAW

//poromenjiva koja oznacava pocetak kreteanja vode kad loptica upadne u nju
int talasanje;
//parametar pomeranja
float t; 

int animation_ongoing;
int animation_ongoing2;
float padanje_loptica;
float pocinje_pad;

#define U_FROM -50
#define V_FROM -50
#define U_TO 50
#define V_TO 50

#define PI 3.1415926535
#define EPSILON 0.01


/* Definisemo makro koji vraca maksimalnu vrednost */
#define max(A, B) (((A) > (B)) ? (A) : (B))

// pocetne koordinate pozicije kamere
int X;
int Y;
int Z;
int i;

//duzina stola
double duzina;

//inicijalizujemo pocetne vrednosti za polozaje solja

float a1, a2, a3;
float b1, b2, b3;
float c1, c2, c3;

//vrednosti y kordinate pre kretanja
float apoc, bpoc, cpoc;
// koeficijent kretanja
float pom;
//promenljiva koja odlucuje koja ce se zamena solja desiti
int prom_odlucivanja;
//promenjiva koja okrece promenljivu odlucivanja
int moze;
//promaenjiva koja predstavlja moguci broj rotacija
int broj_rotacija;
// ugao za poneranje ruke
int ugao;
//promenjiva koja nam signalzira da mozemo da krenemo da pomeramo
int pomeri_ruku;
//drugi ugao za okretanje ruke ka stomaku
int ugao2;
//trci ugao koji vodi ruku ka glavi
int ugao3;
//promenjiva koja kaze da treba da se spusta
int suprotno;
//ugao za padanje coveka
int ugao4;
//ugao koji sluzi da priblizi ruku uz telo
int ugao5;
//pokece pdadanje coveka ako je izbor netacan
int netacno;
//pomeranje solje ka gore
float gore;
//promenjiva koja spusta kliping region kako bi se pojavio osmeh
float osmeh;
//cuva vrednost animation ongoing2 za slucaj pauze
int staro2;
//cuva koju solju je izabrao korisnik
int izabrana_solja;

void init();

void set_vertex_and_normal(float u, float v);
float function(float u, float v);
void plot_function();

void stolica();
void sto();
void covek();
void loptice();
void solja();
void solje_u_startnoj_poziciji();

#endif