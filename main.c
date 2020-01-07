#include <GL/glut.h>

#define ESC 27

// dimenzije prozora
static int window_width, window_height;

// pocetne koordinate pozicije kamere
int X = 10;
int Y = 5;
int Z = 3;

//duzina stola
const double duzina = 3.0;

//inicijalizujemo pocetne vrednosti za polozaje solja

static float a1=0.0, a2=0.0, a3=0.0;
static float b1=0.0, b2=2.5, b3=0.0;
static float c1=0.0, c2=-2.5, c3=0.0;

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
  
	
	//glColor3f(0.25,0,0.5);
	//glava
	    glPushMatrix();
     glColor3f(0.843, 0.424, 0.357);
    glTranslatef(2.5,-5.5,3);
	glutSolidSphere(0.7, 10, 200);
	glPopMatrix();
	//telo
	 glPushMatrix();
	  glColor3f(0,0,0.2);
	 glTranslatef(2.5,-5.5,1);
	 glScalef(0.5,0.5,1);
	glutSolidCube(2.5);
	glPopMatrix();
	
	//ruke
	//gornji deo ruke
	 glPushMatrix();
	 glColor3f(0.843, 0.424, 0.357);
	 glTranslatef(2.5,-4.2,1.9);
	 glRotatef(25,1,0,0);
	 glScalef(0.5,0.53,1.1);
	glutSolidCube(1);
	glPopMatrix();
	
	//donji deo ruke
	glPushMatrix();
	 glColor3f(0.843, 0.424, 0.357);
	 glTranslatef(2.5,-3.77,1); 
	 glRotatef(25,1,0,0);
	 glScalef(0.5,0.53,1.1);
	glutSolidCube(1);
	glPopMatrix();
	
    
     glPushMatrix();
	 glColor3f(0.843, 0.424, 0.357);
	 glTranslatef(2.5,-7.05,1.5);
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
    
    
	}	




//soljice :)
void solje_u_startnoj_poziciji(){
	glPushMatrix();
	glTranslatef(1,0,0);
	
	//srednja
	glPushMatrix();
	glColor3f(0,0,0.2);
	glTranslatef(a1,a2,a3);
	solja();
	glPopMatrix();
	
	//desna
	glPushMatrix();
	glTranslatef(b1,b2,b3);
	solja();
	glPopMatrix();
	
	//leva
	glPushMatrix();
	glTranslatef(c1,c2,c3);
	solja();
	glPopMatrix();
	glPopMatrix();
}
	


static void on_display(void){

    // brise se prethodni sadrzaj prozora
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // podesava se viewport
    glViewport(0, 0, window_width, window_height);
    
    // podesava se projekcija
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, window_width/(float)window_height, 1, 50);
    
    // podesava se vidna tacka
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(X, Y, Z, -2, 0, 0, 0, 0, 1);
    
    // omogucava se upotreba svetlosti i prvog svetla
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    // podesavanja svetla
    /*GLfloat pozicija_svetla[] = { 5, 6, 12, 1 };
    GLfloat ambijent_svetla[] = { 0.1, 0.0, 0.0, 1 };
    GLfloat difuznost_svetla[] = { 0.5,0.25,0.1, 1 };
    GLfloat spekularnost_svetla[] = { 2.2, 1.5, 1, 1 }; */
    
        GLfloat pozicija_svetla[] = { 1, 1, 1, 0};
    GLfloat ambijent_svetla[] = { 0.1, 0.1, 0.1, 1 };
    GLfloat difuznost_svetla[] = { 0.5,0.25,0.1, 1 };
    GLfloat spekularnost_svetla[] = { 0.9, 0.9, 0.9, 1 }; 
    
    // postavlja se svetlo
    glLightfv(GL_LIGHT0, GL_POSITION, pozicija_svetla);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambijent_svetla);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, difuznost_svetla);
    glLightfv(GL_LIGHT0, GL_SPECULAR, spekularnost_svetla);
    
    //pravi se sto
    sto();
    
    //pravi se covek
    covek();
    
    //prve se solje
    solje_u_startnoj_poziciji();
    // nova slika se salje na ekran
    glutSwapBuffers();
}

static void on_keyboard(unsigned char key, int x, int y){
    
    switch(key){
    
        // pritiskom na taster 'Esc' program se zavrsava
        case ESC:
            exit(0);
            break;
      
    }
}

static void on_reshape(int width, int height){
    
    // cuvaju se sirina i visina prozora
    window_width = width;
    window_height = height;
}

int main(int argc, char** argv){
    
    // inicijalizuje se GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    // kreira se prozor
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("Izaberi pravu solju");
    
    // registrovanje callback funkcija
    glutDisplayFunc(on_display);
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    
    // obavlja se OpenGL inicijalizacija
    glClearColor(0.5, 0.5, 0.5, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    
    // ulazak u glavnu petlju
    glutMainLoop();
    
    return 0;
    
}
