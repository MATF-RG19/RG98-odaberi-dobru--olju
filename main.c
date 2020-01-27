#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include "draw.h"

#define ESC 27

/* Definisemo osobine tajmera */
#define TIMER_INTERVAL 5
#define TIMER_ID 0

// dimenzije prozora
static int window_width, window_height;

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
				//dozvoljava se da se rendom izabere sledeca zamena;
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
			pomeri_ruku=1;
		}		
	}
	
	if(bpoc==2.5){
			
		if(b1!=1.5 && b2==2.5){
			b1+=pom;
		}else if(b2>-2.5 && b1==1.5 ){
		    b2-=pom;
		}else{
			pomeri_ruku=1;
		}
	}
	
	if(apoc==2.5){
			
		if(a1!=1.5 && a2==2.5){
			a1+=pom;
		}else if(a2>-2.5 && a1==1.5 ){
		    a2-=pom;
		}else{
			pomeri_ruku=1;
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
			pomeri_ruku=1;
		}		
	}
	
	if(bpoc==0){
		if(b1!=1.5 && b2==0){
			b1+=pom;
		}else if(b2>-2.5 && b1==1.5 ){
		    b2-=pom;
		}else{
			pomeri_ruku=1;
		}
	}
	
	if(apoc==0){
			
		if(a1!=1.5 && a2==0){
			a1+=pom;
		}else if(a2>-2.5 && a1==1.5 ){
		    a2-=pom;
		}else{
			pomeri_ruku=1;
		}
	}
}

//funkcija koja pomera prvu solju ka coveku pritiskom na taster a
void ka_coveku_a(){
	//ukoliko se
	if(cpoc==-2.5){	
		if(c1!=1.5 && c2==-2.5){
			c1+=pom;
		}else if(c2>-2.5 && c1==1.5 ){
		    c2-=pom;
		}else{
			pomeri_ruku=1;
		}
	}
	
	if(bpoc==-2.5){
			
		if(b1!=1.5 && b2==-2.5){
			b1+=pom;
		}else if(b2>-2.5 && b1==1.5 ){
		    b2-=pom;
		}else{
			pomeri_ruku=1;
		}
	}
	
	if(apoc==-2.5){
			
		if(a1!=1.5 && a2==-2.5){
			a1+=pom;
		}else if(a2>-2.5 && a1==1.5 ){
		    a2-=pom;
		}else{
			pomeri_ruku=1;
		}
	}
}

//tajmer za padanje loptice i talasanje vode
static void on_timer(int value){
	if(value>=9){
		pocinje_pad=1; //krece pad bombona u case
	}
	else{
		//pomera se kamera  
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
		//kad loptice upadnu u case porece se talasanje vode
		talasanje=1;
	}	

    if(talasanje){
	   	t += 400;

    	/* Forsira se ponovno iscrtavanje prozora. */
    	glutPostRedisplay();
	}
	   
	   
	if(t>=1500 && broj_rotacija){
		
		if(moze){
			//random se bira sledeca zamena solja
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

//tajmer za solju koja ide ka coveku nakom odabira i reakcija coveka 
//ono sto je popio
static void on_timer_ka_coveku(int value){
	//u zavusnosti koju solju je covek izabrao, tj. od promenljive
	//value bira se koja ce se solja pokrenuti ka coveku
	if(pomeri_ruku==0 ){
		if(value==1)
			ka_coveku_d();
		else if(value==2)
			ka_coveku_s();
		else
			ka_coveku_a();
	}
		
	if(pomeri_ruku ){
		//kad solja dodje do covekove ruke
		//pomeramo kameru	
		if(X<=9){
			X++;
		}
		else{
			//rotacija ruke ka solji	
			if( ugao<30 && !suprotno){
				ugao+=10;
			}
			//rotacija ruke i solje ka stomaku	 
			else if(ugao2<120 && !suprotno){
				ugao2+=10;
			}
			//pomeranje ka covekovoj glavi solje i ruke 
			else if(ugao3<90 && !suprotno){
				ugao3+=10;
				gore+=0.18;
			}
			else{
				//pokrecemo inverzne operacije kako bi solju vratili na sto
				suprotno=1;
			}
			//inverzne operacije	  	 
			if(ugao3>0 && suprotno==1){
				ugao3-=10;
				gore-=0.18;
			}
			else if(ugao2>0 && suprotno==1){
				ugao2-=10;
			}
			else if( ugao>0 && suprotno==1){
				ugao-=10;
			}
			//stavljanje ruke uz telo
			else if(ugao5<=20 && suprotno==1){
				ugao5+=5;
			}
			else if(suprotno==1){
				suprotno=2;
			}	 
			//padanje coveka u nesvest	
			if(netacno && ugao4<90 && suprotno==2){
				ugao4+=10;
			}
			//poera se kliping ravan kako bi se covek nasmejao
			if(osmeh>0 && osmeh<1 && suprotno==2){
				osmeh+=0.1;
			}
		}
	}

	if (animation_ongoing2) {
        glutTimerFunc(TIMER_INTERVAL, on_timer_ka_coveku, value);
    }
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
	glPushMatrix();
	glTranslatef(-0.17,-0.2,0); 
	glTranslatef(2.5,-6.10,-1.3);
	glRotatef(-ugao4, 0,1,0);
	glTranslatef(-2.5,6.10,1.3);
	covek();
   	glPopMatrix();
   
    //prve se solje
    solje_u_startnoj_poziciji();
    // nova slika se salje na ekran
    
    glPushMatrix();
   	glTranslatef(0,0,-padanje_loptica);
    loptice();
   	glPopMatrix();
   
	//iscrtavanje stolice
	glPushMatrix();
	glTranslatef(0,-11,0);
	glRotatef(125, 0,0,1);
	glRotatef(90, 1,0,0);
	glScalef(0.7,0.7,0.7);
	stolica();
	glPopMatrix();
	
	//cajnik
	glPushMatrix();
	glTranslatef(0,-11,0.7);
	glRotatef(125, 0,0,1);
	glRotatef(90, 1,0,0);
	glutSolidTeapot(0.7);
	glPopMatrix();
	
	glutSwapBuffers();
}

static void on_keyboard(unsigned char key, int x, int y){
    
    switch(key){
    
        // pritiskom na taster 'Esc' program se zavrsava
        case ESC:
            exit(0);
            break;
		case 'G':
		case 'g':
			//ako je pritisnuta pauza a timer ka coveku je radio ponovo
			//cemo ga pokrenuti
			animation_ongoing2=staro2;
			if(staro2==1){
				glutTimerFunc(20, on_timer_ka_coveku, izabrana_solja);
			}
			if (!animation_ongoing) {
				glutTimerFunc(20, on_timer, i);
				animation_ongoing = 1;
			}
			break;
		case 'P':		
		case 'p':
			//pauza
			animation_ongoing=0;
			staro2=animation_ongoing2;
			animation_ongoing2=0;
			break;
		case 'A':	
		case 'a':
			//izbrana prva solja
			if(broj_rotacija==0){
				
				if (!animation_ongoing2) {
					izabrana_solja=3;
					glutTimerFunc(20, on_timer_ka_coveku, 3);
					animation_ongoing2 = 1;
				}
				if(a2==-2.5)
				//ukoliko je prva solja ona u kojoj je pala roza bombona
					osmeh=0.001;
				else
				//ukoliko je u nju pala crvena bombona
					netacno=1;
			} 
			break;	
		case 'S':
		case 's':
			//bira se srednja solja
			if(broj_rotacija==0){
				
				if (!animation_ongoing2) {
					izabrana_solja=2;
					glutTimerFunc(20, on_timer_ka_coveku, 2);
					animation_ongoing2 = 1;
				}
				
				if(a2==0)
				//u nju je pala roza bombona
					osmeh=0.001;
				else
				//u nju je pala crvena bombona
					netacno=1;
			}  
			break;
		case 'D':
		case 'd':
			//bira se treca solja
			if(broj_rotacija==0){
				
				if (!animation_ongoing2) {
					izabrana_solja=1;
					glutTimerFunc(20, on_timer_ka_coveku, 1);
					animation_ongoing2 = 1;
				}	
					
				if(a2==2.5)
					osmeh=0.001;
				else
					netacno=1;
			}  
			break; 
		case 'r':
		case 'R':
			//vracamo animaciju na pocetak
			init();
			//broj_rotacija=10;
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

	init();
 
    // ulazak u glavnu petlju
    glutMainLoop();
    
    return 0;
}