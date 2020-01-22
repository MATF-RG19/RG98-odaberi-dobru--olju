#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <time.h>


#define ESC 27



//poromenjiva koja oznacava pocetak kreteanja vode kad loptica upadne u nju
int talasanje=0;
//parametar pomeranja
static float t=0.0; 

static int animation_ongoing=0;
static int animation_ongoing2=0;

static float padanje_loptica=0;
static float pocinje_pad=0;

// dimenzije prozora
static int window_width, window_height;


#define U_FROM -50
#define V_FROM -50
#define U_TO 50
#define V_TO 50


#define PI 3.1415926535
#define EPSILON 0.01

/* Definisemo osobine tajmera */
#define TIMER_INTERVAL 5
#define TIMER_ID 0

/* Definisemo makro koji vraca maksimalnu vrednost */
#define max(A, B) (((A) > (B)) ? (A) : (B))

// pocetne koordinate pozicije kamere
int X = 10;
int Y = 5;
int Z = 3;
int i=3;

//duzina stola
const double duzina = 3.0;

//inicijalizujemo pocetne vrednosti za polozaje solja

static float a1=0.0, a2=0.0, a3=0.0;
static float b1=0.0, b2=2.5, b3=0.0;
static float c1=0.0, c2=-2.5, c3=0.0;

//vrednosti y kordinate pre kretanja
static float apoc=0.0, bpoc=2.5, cpoc=-2.5;
// koeficijent kretanja
static float pom=0.5;

//promenljiva koja odlucuje koja ce se zamena solja desiti
int prom_odlucivanja=1;

//promenjiva koja okrece promenljivu odlucivanja
int moze=1;

//promaenjiva koja predstavlja moguci broj rotacija
int broj_rotacija=10;






//kretanje solja
//0-zamena prve i druge solje
//1-zamena druge i trece solje
//2-zamena prve i trece solje
void pokret(int prom_odlucivanja){
	
	
	
	//obrce se prve i druga
	if(prom_odlucivanja==0){
		moze=0;
		//1
		//c a b
		if(apoc==0 && bpoc==2.5 && cpoc==-2.5){
			if(c1!=1.5 && c2==-2.5){
			c1+=pom;
			a1-=pom;
		}else if(c2!=0 && c1==1.5 ){
		    c2+=pom;
		    a2-=pom;
		}else if(c1!=0 && c2==0){
			c1-=pom;
			a1+=pom;		
			}else {
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				//ovaj return sprecava da funkcija udje u neko naredno if dole vec je vraca nazad na rando
				return;
				}
		
	   }
	   
	   //2
	   //a c b
	   if(apoc==-2.5 && bpoc==2.5 && cpoc==0){
		  
			if(a1<1.5 && a2==-2.5){
			a1+=pom;
			c1-=pom;
		}else if(a2<0 && a1==1.5 ){
		    a2+=pom;
		    c2-=pom;
		}else if(a1>0 && a2==0){
			a1-=pom;
			c1+=pom;		
			}else{
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	   
	   //3
	   //b a c
	   if(apoc==0 && bpoc==-2.5 && cpoc==2.5){
			if(b1<1.5 && b2==-2.5){
			b1+=pom;
			a1-=pom;
		}else if(b2<0 && b1==1.5 ){
		    b2+=pom;
		    a2-=pom;
		}else if(b1>0 && b2==0){
			b1-=pom;
			a1+=pom;		
			}else {
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	   
		//4
	     //b c a
	   if(apoc==2.5 && bpoc==-2.5 && cpoc==0){
			if(b1<1.5 && b2==-2.5){
			b1+=pom;
			c1-=pom;
		}else if(b2<0 && b1==1.5 ){
		    b2+=pom;
		    c2-=pom;
		}else if(b1>0 && b2==0){
			b1-=pom;
			c1+=pom;		
			}else {
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	   
	   
	   //5
	   //a b c
	   if(apoc==-2.5 && bpoc==0 && cpoc==2.5){
		  
			if(a1<1.5 && a2==-2.5){
			a1+=pom;
			b1-=pom;
		}else if(a2<0 && a1==1.5 ){
		    a2+=pom;
		    b2-=pom;
		}else if(a1>0 && a2==0){
			a1-=pom;
			b1+=pom;		
			}else{
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	   
	   
		//6
		//c b a
		if(apoc==2.5 && bpoc==0 && cpoc==-2.5){
			if(c1<1.5 && c2==-2.5){
			c1+=pom;
			b1-=pom;
		}else if(c2<0 && c1==1.5 ){
		    c2+=pom;
		    b2-=pom;
		}else if(c1>0 && c2==0){
			c1-=pom;
			b1+=pom;		
			}else {
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	   
	   
	}
	
	
	
	//okretanje druge i trece
	if(prom_odlucivanja==1){
		moze=0;
	    //1
		//c a b
		if(apoc==0 && bpoc==2.5 && cpoc==-2.5){
			if(b1<1.5 && b2==2.5){
			b1+=pom;
			a1-=pom;
		}else if(b2>0 && b1==1.5 ){
		    b2-=pom;
		    a2+=pom;
		}else if(b1>0 && b2==0){
			b1-=pom;
			a1+=pom;		
			}else {
				moze=1;
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				broj_rotacija--;
                return;
				}
		
	   }
	   //2
	   //c b a
	   if(apoc==2.5 && bpoc==0 && cpoc==-2.5){
			if(a1<1.5 && a2==2.5){
			a1+=pom;
			b1-=pom;
		}else if(a2>0 && a1==1.5 ){
		    a2-=pom;
		    b2+=pom;
		}else if(a1>0 && a2==0){
			a1-=pom;
			b1+=pom;		
			}else{
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	   
	     //3
	   	//b a c
		if(apoc==0 && bpoc==-2.5 && cpoc==2.5){
			if(c1<1.5 && c2==2.5){
			c1+=pom;
			a1-=pom;
		}else if(c2>0 && c1==1.5 ){
		    c2-=pom;
		    a2+=pom;
		}else if(c1>0 && c2==0){
			c1-=pom;
			a1+=pom;		
			}else {
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	   
	   
	   
	     //4
		//a b c
		if(apoc==-2.5 && bpoc==0 && cpoc==2.5){
			if(c1<1.5 && c2==2.5){
			c1+=pom;
			b1-=pom;
		}else if(c2>0 && c1==1.5 ){
		    c2-=pom;
		    b2+=pom;
		}else if(c1>0 && c2==0){
			c1-=pom;
			b1+=pom;		
			}else {
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	   
	   //5
	   //a c b
		if(apoc==-2.5 && bpoc==2.5 && cpoc==0){
			if(b1<1.5 && b2==2.5){
			b1+=pom;
			c1-=pom;
		}else if(b2>0 && b1==1.5 ){
		    b2-=pom;
		    c2+=pom;
		}else if(b1>0 && b2==0){
			b1-=pom;
			c1+=pom;		
			}else {
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	   
	   	//6
	   // c b a
	   if(apoc==2.5 && bpoc==-2.5 && cpoc==0){
		  
			if(a1<1.5 && a2==2.5){
			a1+=pom;
			c1-=pom;
		}else if(a2>0 && a1==1.5 ){
		    a2-=pom;
		    c2+=pom;
		}else if(a1>0 && a2==0){
			a1-=pom;
			c1+=pom;		
			}else{
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	   
	   
	   
	}
	
	
	
	//okretanje prve i trece
	if(prom_odlucivanja==2){
		moze=0;
		//1
		//c a b
		if(apoc==0 && bpoc==2.5 && cpoc==-2.5){
			if(b1<1.5 && b2==2.5){
			b1+=pom;
			c1-=pom;
		}else if(b2>-2.5 && b1==1.5 ){
		    b2-=pom;
		    c2+=pom;
		}else if(b1>0 && b2==-2.5){
			b1-=pom;
			c1+=pom;		
			}else {
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	   //2
	   //b a c
	   if(apoc==0 && bpoc==-2.5 && cpoc==2.5){
		  
			if(c1<1.5 && c2==2.5){
			c1+=pom;
			b1-=pom;
		}else if(c2>-2.5 && c1==1.5 ){
		    c2-=pom;
		    b2+=pom;
		}else if(c1>0 && c2==-2.5){
			c1-=pom;
			b1+=pom;		
			}else{
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	
	
	
		//3
		//c b a
		if(apoc==2.5 && bpoc==0 && cpoc==-2.5){
			if(a1<1.5 && a2==2.5){
			a1+=pom;
			c1-=pom;
		}else if(a2>-2.5 && a1==1.5 ){
		    a2-=pom;
		    c2+=pom;
		}else if(a1>0 && a2==-2.5){
			a1-=pom;
			c1+=pom;		
			}else {
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	
	
		//4
		//b c a
		if(apoc==2.5 && bpoc==-2.5 && cpoc==0){
			if(a1<1.5 && a2==2.5){
			a1+=pom;
			b1-=pom;
		}else if(a2>-2.5 && a1==1.5 ){
		    a2-=pom;
		    b2+=pom;
		}else if(a1>0 && a2==-2.5){
			a1-=pom;
			b1+=pom;		
			}else {
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	       //5
			//a c b
		if(apoc==-2.5 && bpoc==2.5 && cpoc==0){
			if(b1<1.5 && b2==2.5){
			b1+=pom;
			a1-=pom;
		}else if(b2>-2.5 && b1==1.5 ){
		    b2-=pom;
		    a2+=pom;
		}else if(b1>0 && b2==-2.5){
			b1-=pom;
			a1+=pom;		
			}else {
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	
		//6
	   //a b c
	   if(apoc==-2.5 && bpoc==0 && cpoc==2.5){
		  
			if(c1<1.5 && c2==2.5){
			c1+=pom;
			a1-=pom;
		}else if(c2>-2.5 && c1==1.5 ){
		    c2-=pom;
		    a2+=pom;
		}else if(c1>0 && c2==-2.5){
			c1-=pom;
			a1+=pom;		
			}else{
				
				apoc=a2;
				bpoc=b2;
				cpoc=c2;
				moze=1;
				broj_rotacija--;
				return;
				}
		
	   }
	
}
	 
	}
	

//funkcija koja pomera trecu solju ka coveku pritiskom na taster d
void ka_coveku_d(){
	if(cpoc==2.5){	
		if(c1!=1.5 && c2==2.5){
			c1+=pom;
		}else if(c2>-2.5 && c1==1.5 ){
		    c2-=pom;
		}else{
			animation_ongoing2=0;
			}
		
		
	}
	
		if(bpoc==2.5){
			
			
		if(b1!=1.5 && b2==2.5){
			b1+=pom;
		}else if(b2>-2.5 && b1==1.5 ){
		    b2-=pom;
		}else{
			animation_ongoing2=0;
			}
	
	}
	
		if(apoc==2.5){
			
		if(a1!=1.5 && a2==2.5){
			a1+=pom;
		}else if(a2>-2.5 && a1==1.5 ){
		    a2-=pom;
		}else{
			animation_ongoing2=0;
			}
	}
	
}



//funkcija koja pomera drugu solju ka coveku pritiskom na taster s
void ka_coveku_s(){
	if(cpoc==0){	
		if(c1!=1.5 && c2==0){
			c1+=pom;
		}else if(c2>-2.5 && c1==1.5 ){
		    c2-=pom;
		}else{
			animation_ongoing2=0;
			}
		
		
	}
	
		if(bpoc==0){
		if(b1!=1.5 && b2==0){
			b1+=pom;
		}else if(b2>-2.5 && b1==1.5 ){
		    b2-=pom;
		}else{
			animation_ongoing2=0;
			}
	
	}
	
		if(apoc==0){
			
		if(a1!=1.5 && a2==0){
			a1+=pom;
		}else if(a2>-2.5 && a1==1.5 ){
		    a2-=pom;
		}else{
			animation_ongoing2=0;
			}
	}
	
}



//funkcija koja pomera prvu solju ka coveku pritiskom na taster a
void ka_coveku_a(){
	if(cpoc==-2.5){	
		if(c1!=1.5 && c2==-2.5){
			c1+=pom;
		}else if(c2>-2.5 && c1==1.5 ){
		    c2-=pom;
		}else{
			animation_ongoing2=0;
			}
		
		
	}
	
		if(bpoc==-2.5){
			
			
		if(b1!=1.5 && b2==-2.5){
			b1+=pom;
		}else if(b2>-2.5 && b1==1.5 ){
		    b2-=pom;
		}else{
			animation_ongoing2=0;
			}
	
	}
	
		if(apoc==-2.5){
			
		if(a1!=1.5 && a2==-2.5){
			a1+=pom;
		}else if(a2>-2.5 && a1==1.5 ){
		    a2-=pom;
		}else{
			animation_ongoing2=0;
			}
	}
	
}


//tajmer za padanje loptice i talasanje vode

static void on_timer(int value)
{
  if(value>=9){pocinje_pad=1;}
  else{
  Y=Y-1;
  X=X-1;
 
  i++;
   glutPostRedisplay();
}
if(pocinje_pad){
	padanje_loptica++;
	glutPostRedisplay();
	}
if(padanje_loptica==9){
	pocinje_pad=0;
	padanje_loptica=100;
	talasanje=1;
	}	

   if(talasanje){
	   t += 400;

    /* Forsira se ponovno iscrtavanje prozora. */
    glutPostRedisplay();
	   }
	   
	   
	if(t>=1500 && broj_rotacija){
		
		
		if(moze){
			srand(time(NULL));
		prom_odlucivanja=rand()%3;
	}
		pokret(prom_odlucivanja);
		
		
		glutPostRedisplay();
		
		}   
   
   if(animation_ongoing){
		glutTimerFunc(20, on_timer, i);
		}

    
}

//tajmer za solju koja ide ka coveku nakom odabira
static void on_timer_ka_coveku(int value){
	
	if(value==1)
		ka_coveku_d();
	else if(value==2)
		ka_coveku_s();
	else
		ka_coveku_a();
	
	if (animation_ongoing2) {
        glutTimerFunc(TIMER_INTERVAL, on_timer_ka_coveku, value);
    }
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


void set_vertex_and_normal(float u, float v)
{
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

/* Crtamo funkciju */
void plot_function()
{
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
	
	
	//loptica
void loptice(){
	glPushMatrix();
	glColor3f(0.5,0,0);
	glTranslatef(0.75,-2.5,10);
	glutSolidSphere(0.2, 30, 30);
	glPopMatrix();	
	
	
	glPushMatrix();
	glColor3f(0.909, 0.58, 0.79);
	glTranslatef(0.75,0,10);
	glutSolidSphere(0.2, 30, 30);
	glPopMatrix();	
	
	
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
    
    glPushMatrix();
   glTranslatef(0,0,-padanje_loptica);
     loptice();
   glPopMatrix();
    glutSwapBuffers();
}

static void on_keyboard(unsigned char key, int x, int y){
    
    switch(key){
    
        // pritiskom na taster 'Esc' program se zavrsava
        case ESC:
            exit(0);
            break;
		
		case 'g':
		   if (!animation_ongoing) {
			glutTimerFunc(20, on_timer, i);
            animation_ongoing = 1;
				}
			break;	
		case 'p':
		animation_ongoing=0;
		break;
		
	case 'a':
        if(broj_rotacija==0){
			
			if (!animation_ongoing2) {
				glutTimerFunc(20, on_timer_ka_coveku, 3);
				animation_ongoing2 = 1;
        }
        if(a2==-2.5)
			printf("Tacno\n");
        else
			printf("Netacno\n");
	} 
	break;
	
	case 's':
        if(broj_rotacija==0){
			
			if (!animation_ongoing2) {
				glutTimerFunc(20, on_timer_ka_coveku, 2);
				animation_ongoing2 = 1;
        }
			
			
        if(a2==0)
			printf("Tacno\n");
        else
			printf("Netacno\n");
	}  
	break;
	
	case 'd':
        if(broj_rotacija==0){
			
			 if (!animation_ongoing2) {
				glutTimerFunc(20, on_timer_ka_coveku, 1);
				animation_ongoing2 = 1;
			}	
				
			if(a2==2.5)
				printf("Tacno\n");
			else
				printf("Netacno\n");
	}  
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
