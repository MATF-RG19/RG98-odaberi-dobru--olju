#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "draw.h"

void init(){
    //poromenjiva koja oznacava pocetak kreteanja vode kad loptica upadne u nju
    talasanje=0;
    //parametar pomeranja
    t=0.0; 

    animation_ongoing=0;
    animation_ongoing2=0;

    padanje_loptica=0;
    pocinje_pad=0;

    // pocetne koordinate pozicije kamere
    X = 10;
    Y = 5;
    Z = 3;
    i=3;

    //duzina stola
    duzina = 3.0;

    //inicijalizujemo pocetne vrednosti za polozaje solja

    a1=0.0;
    a2=0.0;
    a3=0.0;
    b1=0.0; 
    b2=2.5;
    b3=0.0;
    c1=0.0;
    c2=-2.5;
    c3=0.0;

    //vrednosti y kordinate pre kretanja
    apoc=0.0;
    bpoc=2.5;
    cpoc=-2.5;
    // koeficijent kretanja
    pom=0.5;
    //promenljiva koja odlucuje koja ce se zamena solja desiti
    prom_odlucivanja=1;
    //promenjiva koja okrece promenljivu odlucivanja
    moze=1;
    //promaenjiva koja predstavlja moguci broj rotacija
    broj_rotacija=7;
    // ugao za poneranje ruke
    ugao=0;
    //promenjiva koja nam signalzira da mozemo da krenemo da pomeramo
    pomeri_ruku=0;
    //drugi ugao za okretanje ruke ka stomaku
    ugao2=0;
    //trci ugao koji vodi ruku ka glavi
    ugao3=0;
    //promenjiva koja kaze da treba da se spusta
    suprotno=0;
    //ugao za padanje coveka
    ugao4=0;
    //ugao koji sluzi da priblizi ruku uz telo
    ugao5=0;
    //pokece pdadanje coveka ako je izbor netacan
    netacno=0;
    //pomeranje solje ka gore
    gore=0;
    //promenjiva koja spusta kliping region kako bi se pojavio osmeh
    osmeh=0;
    //cuva vrednost animation ongoing2 za slucaj pauze
    staro2=0;
}

void set_vertex_and_normal(float u, float v){
    float diff_u, diff_v;

    /* Racunamo priblizne vrednosti izvoda funkcije u tacki u, v */
    diff_u = (function(u + 1, v)
             - function(u - 1, v)) / 2.0;
    diff_v = (function(u, v + 1)
             - function(u, v - 1)) / 2.0;

    /* Postavljamo normalu - vektor normalan na tangentnu ravan */
    /* Racuna se priblizan vektor normale: */
    glNormal3f(-diff_u, 1, -diff_v);

    /* Racuna se priblizan vektor normale.
     * Primenom sinusa se postize efekat presijavanja
     */
    /* glNormal3f(sin(-diff_u), 1, sin(-diff_v)); */

    /* Postavljamo verteks */
    glVertex3f(u, function(u, v), v);
}

//dodate funkcije za vodu
float function(float u, float v){
	if(talasanje){
		float parameter = (u*u + v*v +t) / 300 ;
		return  3.5*sin(parameter) * exp(2 - parameter/10);
	}
	else{
		return 0;
	}
}

/* Crtamo funkciju */
void plot_function(){
    float scale;
    int u, v;

    glPushMatrix();
    
    /* Racunamo faktor skaliranja tako da cela funkcija bude prikazana */
    scale = 2.0 / max( U_TO - U_FROM, V_TO - V_FROM );
    glScalef(scale, scale, scale);
  
    /* Crtamo funkciju strip po strip */
    for (u = U_FROM; u < U_TO; u++) {
        glBegin(GL_TRIANGLE_STRIP);
        for (v = U_FROM; v <= U_TO; v++) {
            set_vertex_and_normal(u, v);
            set_vertex_and_normal(u + 1, v);
        }
        glEnd();
    }

    glPopMatrix();
}

//modelovanje stolice
void stolica(){
	
	glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
 
    //Front
        glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-2.0f, -0.2f, 2.0f);
    glVertex3f(2.0f, -0.2f, 2.0f);
    glVertex3f(2.0f, 0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, 2.0f);
    
    //Right
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(2.0f, -0.2f, -2.0f);
    glVertex3f(2.0f, 0.2f, -2.0f);
    glVertex3f(2.0f, 0.2f, 2.0f);
    glVertex3f(2.0f, -0.2f, 2.0f);
    
    //Back
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-2.0f, -0.2f, -2.0f);
    glVertex3f(-2.0f, 0.2f, -2.0f);
    glVertex3f(2.0f, 0.2f, -2.0f);
    glVertex3f(2.0f, -0.2f, -2.0f);
    
    //Left
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-2.0f, -0.2f, -2.0f);
    glVertex3f(-2.0f, -0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, -2.0f);
    
    //top
    glNormal3f(0.0f,1.0f,0.0f);
    
    glVertex3f(2.0f, 0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, -2.0f);
    glVertex3f(2.0f, 0.2f, -2.0f);
    
        //bottom
    glNormal3f(0.0f,-1.0f,0.0f);
    glVertex3f(2.0f, -0.2f, 2.0f);
    glVertex3f(-2.0f, -0.2f, 2.0f);
    glVertex3f(-2.0f, -0.2f, -2.0f);
    glVertex3f(2.0f, -0.2f, -2.0f);
    
        //table front leg
        //front
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.8f,-0.2f,1.6f);
    glVertex3f(1.4f, -0.2f, 1.6f);
    glVertex3f(1.4f, -3.0f, 1.6f);
    glVertex3f(1.8f, -3.0f, 1.6f);
    
        //back
        glNormal3f(0.0f, 0.0f, -1.0f);
    
    glVertex3f(1.8f,-0.2f,1.2f);
    glVertex3f(1.4f, -0.2f, 1.2f);
    glVertex3f(1.4f, -3.0f, 1.2f);
    glVertex3f(1.8f, -3.0f, 1.2f);
    
        //right
        glNormal3f(1.0f, 0.0f, 0.0f);
    
    glVertex3f(1.8f,-0.2f,1.6f);
    glVertex3f(1.8f, -0.2f, 1.2f);
    glVertex3f(1.8f, -3.0f, 1.2f);
    glVertex3f(1.8f, -3.0f, 1.6f);
    
        //left
        glNormal3f(-1.0f, 0.0f, 0.0f);
    
    glVertex3f(1.4f,-0.2f,1.6f);
    glVertex3f(1.4f, -0.2f, 1.2f);
    glVertex3f(1.4f, -3.0f, 1.2f);
    glVertex3f(1.4f, -3.0f, 1.6f);
    
    //back leg back
    //front
    glNormal3f(0.0f, 0.0f, -1.0f);
    
    glVertex3f(1.8f,-0.2f,-1.2f);
    glVertex3f(1.4f, -0.2f, -1.2f);
    glVertex3f(1.4f, -3.0f, -1.2f);
    glVertex3f(1.8f, -3.0f, -1.2f);
    
    //back
    glNormal3f(0.0f, 0.0f, -1.0f);
    
    glVertex3f(1.8f,-0.2f,-1.6f);
    glVertex3f(1.4f, -0.2f, -1.6f);
    glVertex3f(1.4f, -3.0f, -1.6f);
    glVertex3f(1.8f, -3.0f, -1.6f);
    
        //right
        glNormal3f(1.0f, 0.0f, 0.0f);
    
    glVertex3f(1.8f,-0.2f,-1.6f);
    glVertex3f(1.8f, -0.2f, -1.2f);
    glVertex3f(1.8f, -3.0f, -1.2f);
    glVertex3f(1.8f, -3.0f, -1.6f);
    
    //left
        glNormal3f(1.0f, 0.0f, 0.0f);
    
    glVertex3f(1.4f,-0.2f,-1.6f);
    glVertex3f(1.4f, -0.2f, -1.2f);
    glVertex3f(1.4f, -3.0f, -1.2f);
    glVertex3f(1.4f, -3.0f, -1.6f);
    
        //leg left front
    glNormal3f(0.0f, 0.0f, 1.0f);
    
    glVertex3f(-1.8f,-0.2f,1.6f);
    glVertex3f(-1.4f, -0.2f, 1.6f);
    glVertex3f(-1.4f, -3.0f, 1.6f);
    glVertex3f(-1.8f, -3.0f, 1.6f);
    
        //back
        glNormal3f(0.0f, 0.0f, -1.0f);
    
    glVertex3f(-1.8f,-0.2f,1.2f);
    glVertex3f(-1.4f, -0.2f, 1.2f);
    glVertex3f(-1.4f, -3.0f, 1.2f);
    glVertex3f(-1.8f, -3.0f, 1.2f);
    
    //right
    glNormal3f(1.0f, 0.0f, 0.0f);
    
    glVertex3f(-1.8f,-0.2f,1.6f);
    glVertex3f(-1.8f, -0.2f, 1.2f);
    glVertex3f(-1.8f, -3.0f, 1.2f);
    glVertex3f(-1.8f, -3.0f, 1.6f);
    
        //left
        glNormal3f(-1.0f, 0.0f, 0.0f);
    
    glVertex3f(-1.4f,-0.2f,1.6f);
    glVertex3f(-1.4f, -0.2f, 1.2f);
    glVertex3f(-1.4f, -3.0f, 1.2f);
    glVertex3f(-1.4f, -3.0f, 1.6f);
    
    //left leg back front
    
        //front
        glNormal3f(0.0f, 0.0f, -1.0f);
    
    glVertex3f(-1.8f,-0.2f,-1.2f);
    glVertex3f(-1.4f, -0.2f, -1.2f);
    glVertex3f(-1.4f, -3.0f, -1.2f);
    glVertex3f(-1.8f, -3.0f, -1.2f);
    
        //back
        glNormal3f(0.0f, 0.0f, -1.0f);
    
    glVertex3f(-1.8f,-0.2f,-1.6f);
    glVertex3f(-1.4f, -0.2f, -1.6f);
    glVertex3f(-1.4f, -3.0f, -1.6f);
    glVertex3f(-1.8f, -3.0f, -1.6f);
    
        //right
        glNormal3f(1.0f, 0.0f, 0.0f);
    
    glVertex3f(-1.8f,-0.2f,-1.6f);
    glVertex3f(-1.8f, -0.2f, -1.2f);
    glVertex3f(-1.8f, -3.0f, -1.2f);
    glVertex3f(-1.8f, -3.0f, -1.6f);
    
        //left
        glNormal3f(-1.0f, 0.0f, 0.0f);
    
    glVertex3f(-1.4f,-0.2f,-1.6f);
    glVertex3f(-1.4f, -0.2f, -1.2f);
    glVertex3f(-1.4f, -3.0f, -1.2f);
    glVertex3f(-1.4f, -3.0f, -1.6f);
    
    //deo stolice gde se nalsanjaju ledja
    //front
    glColor3f(0.6,0,0);
    //glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.8f, 0.2f, -1.8f);
    glVertex3f(1.8f, 0.2f, -1.8f);
    glVertex3f(1.8f, 3.5f, -1.8f);
    glVertex3f(-1.8f, 3.5f, -1.8f);
    
    //back
    //glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.8f, 0.2f, -2.0f);
    glVertex3f(1.8f, 0.2f, -2.0f);
    glVertex3f(1.8f, 3.5f, -2.0f);
    glVertex3f(-1.8f, 3.5f, -2.0f);
    
    //  glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.8f, 0.2f, -2.0f);
    glVertex3f(-1.8f, 3.5f, -2.0f);
    glVertex3f(-1.8f, 3.5f, -1.8f);
    glVertex3f(-1.8f, 0.2f, -1.8f);
    
    glVertex3f(1.8f, 0.2f, -2.0f);
    glVertex3f(1.8f, 3.5f, -2.0f);
    glVertex3f(1.8f, 3.5f, -1.8f);
    glVertex3f(1.8f, 0.2f, -1.8f);
    
    glVertex3f(-1.8f, 3.5f, -2.0f);
    glVertex3f(-1.8f, 3.5f, -1.8f);
    glVertex3f(1.8f, 3.5f, -1.8f);
    glVertex3f(1.8f, 3.5f, -2.0f);
        
    glEnd();
}

//modelovanje stola
void sto(){
   
    //materijal stola
    GLfloat ambijent_stola[] = { 0.3, 0.3, 0.5, 1};
    GLfloat difuznost_stola[] = { 0.01, 0.01, 0.01, 1 };
    GLfloat spekularnost_stola[] = { 0.01, 0.1, 0.3, 1 };
    GLfloat osvetljenje_stola = 0.2;
    
    //postavljanje materijala stola
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambijent_stola);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, difuznost_stola);
    glMaterialfv(GL_FRONT, GL_SPECULAR, spekularnost_stola);
    glMaterialf(GL_FRONT, GL_SHININESS, osvetljenje_stola);
    
    glTranslatef(-5,2,0);
   
    //pocinjemo pravljenje stola
    glPushMatrix();
    glColor3f(0.4,0.2,0);
    glTranslated(0,0,duzina/2);
    //pravi se ploca stola
    glPushMatrix();
    glScaled(duzina, duzina, 0.05*duzina);
    glTranslated(0,0,-4*duzina);
    glutSolidCube(duzina);
    glPopMatrix();
    
    //prave se nogare, razlika je samo u translaciji
    glPushMatrix();
    glTranslated(-duzina,duzina,-duzina-0.4);
    glScaled(0.06*duzina, 0.06*duzina, duzina/3);
    glutSolidCube(duzina);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(-duzina,-duzina,-duzina-0.4);
    glScaled(0.06*duzina, 0.06*duzina, duzina/3);
    glutSolidCube(duzina);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(duzina,-duzina,-duzina-0.4);
    glScaled(0.06*duzina, 0.06*duzina, duzina/3);
    glutSolidCube(duzina);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(duzina,duzina,-duzina-0.4);
    glScaled(0.06*duzina, 0.06*duzina, duzina/3);
    glutSolidCube(duzina);
    glPopMatrix();
    
    glPopMatrix();
}

void covek(){
	glPushMatrix();
	    //materijal stola
    GLfloat ambijent_coveka[] = { 0.4, 0.4, 0.8, 1};
    GLfloat difuznost_coveka[] = { 0.3, 0.06, 0.3, 1 };
    GLfloat spekularnost_coveka[] = { 0.06, 0.07, 0, 1 };
    GLfloat osvetljenje_coveka = 0.2;
    
    //postavljanje materijala coveka
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambijent_coveka);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, difuznost_coveka);
    glMaterialfv(GL_FRONT, GL_SPECULAR, spekularnost_coveka);
    glMaterialf(GL_FRONT, GL_SHININESS, osvetljenje_coveka);
  
	//glava
	glPushMatrix();
	glColor3f(0.843, 0.424, 0.357);
    glTranslatef(2.5,-5.5,3);
	glutSolidSphere(0.7, 10, 200);
	glPopMatrix();
	
	//desno oko
	glPushMatrix();
	glColor3f(1, 1, 1);
    glTranslatef(3.17,-5.65,3.2);
    glScalef(0.05, 0.2,0.2);
	glutSolidSphere(0.7, 10, 200);
	glPopMatrix();
	
	//levo oko
	glPushMatrix();
	glColor3f(1, 1, 1);
    glTranslatef(3.17,-5.25,3.2);
    glScalef(0.05, 0.2,0.2);
	glutSolidSphere(0.7, 10, 200);
	glPopMatrix();
	
	//desna zenica
	glPushMatrix();
	glColor3f(0, 0, 0);
    glTranslatef(3.185,-5.65,3.22);
    glScalef(0.05, 0.15,0.15);
	glutSolidSphere(0.7, 10, 200);
	glPopMatrix();
	
	//leva zenica
	glPushMatrix();
	glColor3f(0, 0, 0);
    glTranslatef(3.185,-5.25,3.22);
    glScalef(0.05, 0.15,0.15);
	glutSolidSphere(0.7, 10, 200);
	glPopMatrix();
	
	//usta
	glPushMatrix();
	//pomocu dve kliping ravni pravimo coveka koji se osmehuje
	GLdouble plane0[] = {0,0,-1, 2.8};//prekriva gornji deo kruga
	GLdouble plane1[] = {0, 0, 1, -2.7+osmeh};//spusta se ako je takmicar pogodio

    glEnable(GL_CLIP_PLANE0);
    glEnable(GL_CLIP_PLANE1);

    glClipPlane(GL_CLIP_PLANE0, plane0);
    glClipPlane(GL_CLIP_PLANE1, plane1);
	glColor3f(0,0,0);
	glTranslatef(3.185,-5.5,2.8);
    glScalef(0.05, 0.4,0.4);
    glutSolidSphere(0.7, 10, 30);

    glDisable(GL_CLIP_PLANE0);
    glDisable(GL_CLIP_PLANE1);
	
	glPopMatrix();
	//telo
	glPushMatrix();
	glColor3f(0,0,0.2);
	glTranslatef(2.5,-5.5,1);
	glScalef(0.5,0.5,1);
	glutSolidCube(2.5);
	glPopMatrix();
	
	//ruke
	//pocetak rotacije 
	glPushMatrix();
	glTranslatef(0, -ugao5/90.0,-ugao5/90.0);
	glTranslatef(2.5,-4.2,1.9);
	//stavljanje ruke uz telo
	glRotatef(-ugao5,1,0,0);
	
	//rotacije ruke ka glavi
	glRotatef(-ugao3, 0,1,0);
	glTranslatef(-2.5, 4.2, -1.9);
	//
	
	//gornji deo ruke
	glPushMatrix();
	glColor3f(0.843, 0.424, 0.357);
	glTranslatef(2.5,-4.4,1.9);
	glRotatef(25,1,0,0);
	glScalef(0.5,0.53,1.1);
	glutSolidCube(1);
	glPopMatrix();
	
	//donji deo ruke
	glPushMatrix();
	glColor3f(0.843, 0.424, 0.357);
	glTranslatef(2.5,-3.97,1);
	
	//ovde je implementirana rotacija ruke nakon
	//sto korisnik izabere solju
	glTranslatef(0,-0.25,0.5);
	//ka stomaku
	glRotatef(-ugao2,0,0,1);
	//gore ka solji
	glRotatef(ugao,1,0,0);
	glTranslatef(0,0.25,-0.5);
	//
	 
	glRotatef(25,1,0,0);
	glScalef(0.5,0.53,1.1);
	glutSolidCube(1);
	glPopMatrix();
	
	glPopMatrix();
    
    //desna ruka
	glPushMatrix();
	glColor3f(0.843, 0.424, 0.357);
	glTranslatef(2.5,-6.9,1.5);
	glRotatef(-25,1,0,0);
	glScalef(0.5,0.5,2);
	glutSolidCube(1);
	glPopMatrix();
    
    //noge
    glPushMatrix();
	glColor3f(0.843, 0.424, 0.357);
	glTranslatef(2.5,-6.10,-1.3);
	glScalef(0.40,0.40,2.1);
	glutSolidCube(1);
	glPopMatrix();
	
    glPushMatrix();
	glColor3f(0.843, 0.424, 0.357);
	glTranslatef(2.5,-5.10,-1.3);
	glScalef(0.40,0.40,2.1);
	glutSolidCube(1);
	glPopMatrix();
	
	glPopMatrix();
}

//loptica
void loptice(){
	//prva loptica
	glPushMatrix();
	glColor3f(0.5,0,0);
	glTranslatef(0.75,-2.5,10);
	glutSolidSphere(0.2, 30, 30);
	glPopMatrix();	
	
	//druga
	glPushMatrix();
	glColor3f(0.909, 0.58, 0.79);
	glTranslatef(0.75,0,10);
	glutSolidSphere(0.2, 30, 30);
	glPopMatrix();	
	
	//treca
	glPushMatrix();
	glColor3f(0.5,0,0);
	glTranslatef(0.75,2.5,10);
	glutSolidSphere(0.2, 30, 30);
	glPopMatrix();	
}	
	
//solja
void solja(){
	
	GLUquadricObj* quadratic = gluNewQuadric();
    gluCylinder(quadratic, 0.35, 0.6, 1.3, 32, 32);
    glPushMatrix();
    glTranslatef(0,-0.77,1);
    glRotatef(90,0,1,0);
    glScalef(0.2,0.2,0.2);
    glutSolidTorus(0.4, 0.8, 10, 50);
    glPopMatrix();
    
    //dodatna povrasina ispod talasa koja daje ovu kul zalakenstu boju
    glPushMatrix();	     
     
    glTranslatef(0,0.0,1.2);
	glRotatef(90,1,0,0);
    glScalef(0.25,0.55,0.3);
    glColor3f(0, 0.7, 0.98);
    glutSolidSphere(2, 2,30);
    glPopMatrix();
    
    //voda
    glPushMatrix();
    glTranslatef(0,0,1.2);
	glScalef(0.32,0.32,0.32);
	glRotatef(90,1,0,0);
    glColor3f(0,0.03,0.2);
	plot_function();
    glPopMatrix();
}	

//soljice :)
void solje_u_startnoj_poziciji(){
	glPushMatrix();
	glTranslatef(1,0,0);
	
	//srednja
	glPushMatrix();
	
	//Ovaj deo sluzi za rotaciju solje
	if(a1==1.5 && a2==-2.5 && a3==0){
        //translacija solje ka glavi i od glave
        glTranslatef(gore/3,-gore/10,gore);
        
        //rotacija solje od stomaka i do stomaka	
        glTranslatef(1.5,-4,0);
        glRotatef(-ugao2, 0,0,1);
        glTranslatef(-1.5,4,0);
	}
	
	glColor3f(0,0,0.2);
	glTranslatef(a1,a2,a3);
	solja();
	glPopMatrix();
	
	//desna
	glPushMatrix();
	
	//Ovaj deo sluzi za rotaciju solje
	if(b1==1.5 && b2==-2.5 && b3==0){
	
        glTranslatef(gore/3,-gore/10,gore);
            
        glTranslatef(1.5,-4,0);
        glRotatef(-ugao2, 0,0,1);
        glTranslatef(-1.5,4,0);
	}
	
	glTranslatef(b1,b2,b3);
	solja();
	glPopMatrix();
	
	//leva
	glPushMatrix();
	
	//Ovaj deo sluzi za rotaciju solje
	if(c1==1.5 && c2==-2.5 && c3==0){
	
        glTranslatef(gore/3,-gore/10,gore);
            
        glTranslatef(1.5,-4,0);
        glRotatef(-ugao2, 0,0,1);
        glTranslatef(-1.5,4,0);
	}
	
	glTranslatef(c1,c2,c3);
	//iscrtavanje solje
	solja();
	glPopMatrix();
	glPopMatrix();
}