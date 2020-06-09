#include<stdio.h>
#include<GL/glut.h>
#include<windows.h>
#include<math.h>

#define BALLOON_SIZE 3
#define ARROW_SIZE 7
int shoot=0;
float y_position=0; 
float x_position=0; // speed of arrow
int count_arrow=7;	//speed of balloon
bool set_arrow_flag=false;
int someval;
int score_here=0;

int arrows=10;	//no_of_arrows
int balloons=10;	//no_of_balloons



///text area

int i;
char buffer[10];
int score = 0;//for score counting
char str1[30]="Arrows Left: ";
char str2[30]="Balloons Left: ";
char str3[30]="Score: ";
char str4[30]="GAME OVER";
char str5[30]="Your Score is: ";
char str6[50]="WELCOME TO BALLOON SHOOTING!!!";
char str7[30]="Press Right arrow key [-->]";
char str8[30]="to shoot arrows"; 
char str9[30]="Press Esc to Quit";




void text_box()
{
      glutPostRedisplay();
      glColor3f(1,0,0); // to draw rectangle box
      glBegin(GL_LINE_LOOP);
      glLineWidth(1);
      glVertex2f(100,50);
      glVertex2f(100,150);
      glVertex2f(450,150);
      glVertex2f(450,50);
      glEnd();

      int a,p,b,o;
      int numofchar;

      glColor3f(0.6,0.8,0.7);
      glRasterPos2i(500,600); //WELCOME TO BALLOON SHOOTING!!!
      for( a=0;a<strlen(str6);a++)
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str6[a]);

      glColor3f(1.0,0.8,0.4); 
      glRasterPos2i(120,300); //Press Right arrow key [-->]
      for( a=0;a<strlen(str7);a++)
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15,str7[a]);
      glRasterPos2i(120,275);//to shoot arrows
      for( a=0;a<strlen(str8);a++)
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15,str8[a]);
      glRasterPos2i(120,225);//Press Esc to Quit
      for( a=0;a<strlen(str9);a++)
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15,str9[a]);
	
	
      glColor3f(1.0,0.0,0.0);
      glRasterPos2i(130,125);//Arrows Left:
      for( a=0;a<strlen(str1);a++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str1[a]);
      glRasterPos2i(130,100);//Balloons Left: 
      for( a=0;a<strlen(str2);a++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str2[a]);
      glColor3f(1.0,1.0,0.0);
      glRasterPos2i(130,70);//Score:
      for( a=0;a<strlen(str3);a++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str3[a]);
	
	
      itoa (score, buffer, 10);    
      numofchar = strlen(buffer); //score_points
      glRasterPos2f( 350,70);
      for (i = 0; i <= numofchar - 1; i++)
      { 
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer[i]);
      }

      itoa (arrows, buffer, 10);	//no_of_arrows
      numofchar = strlen(buffer);
      glRasterPos2f( 350,125);
      for (i = 0; i <= numofchar - 1; i++)
      { 
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer[i]);
      }

      itoa (balloons, buffer, 10);	//no_of_balloons
      numofchar = strlen(buffer);
      glRasterPos2f( 350,100);
      for (i = 0; i <= numofchar - 1; i++)
      {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer[i]);
      } 
    
      glFlush();
      glutSwapBuffers();
}


void end()
{
      int a,numofchar;

      glColor3f(0.7,0.6,0.1);
      glRasterPos2i(600,320);//GAME OVER
      for( a=0;a<strlen(str4);a++)
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str4[a]);	

      glRasterPos2i(600,260); // Your Score is
      for( a=0;a<strlen(str5);a++)
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str5[a]);

      glColor3f(0.1,0.9,1);
      itoa (score, buffer, 10);    
      numofchar = strlen(buffer); //score_points
      glRasterPos2f(760,260);
      for (i = 0; i <= numofchar - 1; i++)
      { 
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer[i]);
      }	
      glFlush();
      glutSwapBuffers();
      getchar();
}

//end of text area



void draw_burst ( int x, int y )
{

      glBegin(GL_LINE_LOOP);
      glVertex2f ( x - 16, y - 12);
      glVertex2f( x - 10, y - 2 ) ;
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex2f( x - 10, y - 2);
      glVertex2f( x - 16, y ) ;
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex2f ( x - 16, y);
      glVertex2f( x - 10, y + 2 ) ;
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex2f ( x - 10, y + 2);
      glVertex2f( x - 16, y + 12 ) ;
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex2f ( x - 16, y + 12);
      glVertex2f( x - 6, y + 2 ) ;
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex2f ( x - 6, y + 2);
      glVertex2f( x, y + 12 ) ;
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex2f( x, y + 12);
      glVertex2f( x + 6, y + 2 ) ;
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex2f( x + 6, y + 2);
      glVertex2f( x + 16, y + 12 ) ;
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex2f ( x - 16, y - 12);
      glVertex2f( x - 6, y - 2 ) ;
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex2f ( x - 6, y - 2);
      glVertex2f( x, y - 12 ) ;
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex2f ( x, y - 12);
      glVertex2f( x + 6, y - 2 ) ;
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex2f( x + 6, y - 2);
      glVertex2f(x + 16, y - 12 ) ;
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex2f ( x + 16, y - 12);
      glVertex2f( x + 10, y - 2 ) ;
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex2f ( x + 10, y - 2);
      glVertex2f(x + 16, y ) ;
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex2f( x + 16, y);
      glVertex2f( x + 10, y + 2 ) ;
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex2f ( x + 10, y + 2);
      glVertex2f( x + 16, y + 12 ) ;
      glEnd();
      
}



void draw_balloon(int x,int y)
{
      float j,k;
      float theta;
      static int i;
      glPushMatrix();
      glTranslatef(0,y_position,0);
      glBegin(GL_POLYGON);
      for( i=0;i<360;i++) // to draw circle
      {
            theta=i*3.142/180;
            glVertex2f(x+13*cos(theta),y+17*sin(theta));
            if(i==270)
            {
                  j=x+5*cos(theta);
                  k=y+7*sin(theta);
            }		
	    }
      glEnd();

      glColor3f(0.9,0.2,0.5);
      glBegin(GL_LINE_LOOP); //	to draw thread of balloon
      glVertex2f ( j,k);
      glVertex2f( j,(y+6*BALLOON_SIZE)-55 );
      glEnd();
      glPopMatrix();
}



void __draw_arc(int x,int y,int st_ang,int end_ang,int r)
{
      float j,k;
      float theta;
      glBegin(GL_LINE_LOOP);
      for(int i=0;i<360;i++)
      {
            theta=i*3.142/180;
            if(i<=st_ang && i>=end_ang)
            {
            }
            else
                  glVertex2f(x+r*cos(theta),y+r*sin(theta));
      }
      glEnd();
}



void draw_bow(int x,int y)
{
      glColor3f(0.8,0.4,0.2);
      glBegin(GL_LINE_LOOP);
      glVertex2f (x+32,y-49);
      glVertex2f(x+32,y+49) ;
      glEnd();
      glColor3f(0.8,0.4,0.2);
      __draw_arc(x,y,300,60,60);	//	mid arc
      __draw_arc(x+34,y-56,100,220,4); // below circle
      __draw_arc(x+34,y+56,140,260,4); // above circle
}



void draw_arrow(int x, int y)
{
      glColor3f(0.2,0.5,0);
      glLineWidth(3);//for line width
      glPushMatrix();
      glTranslatef(x_position,0,0); 
      glBegin(GL_LINE_LOOP); // for middle line
      glVertex2f (x-32,y+49);
      glVertex2f(x+25,y+49) ;
      glEnd();

      glColor3f(0.5,0.6,0.6);
      glBegin(GL_LINE_LOOP);	//	for upper shaft
      glVertex2f(x+25,y+49) ;
      glVertex2f (x+12,y+62);
      glEnd();

      glBegin(GL_LINE_LOOP); // 	for below shaft
      glVertex2f(x+25,y+49) ;
      glVertex2f (x+12,y+36);
      glEnd();
      glPopMatrix();
	
}

/*
// Optional
void init()
{
      glClearColor(0,0,1,0);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0,1350,0,680);
      glMatrixMode(GL_MODELVIEW);	
}
*/


void timer(int)
{
      glutPostRedisplay();
      glutTimerFunc(1000/860,timer,0);
      someval=x_position;
      int h,j;
      // for checking the condition - if balloon is been hit by the arrow
      if(shoot==1 && y_position>=495 && y_position<=530 && x_position>=980 && x_position<=1080) 
      {
              score_here=5;
              score+=1;
      }

      if(someval== 1100 && set_arrow_flag)
      {
            arrows-=1;
      }

      set_arrow_flag=false;
	
      if(x_position<=1350 && y_position<=680) // balloon and arrow have not crossed the screen
      {
            x_position+=0.40;
            y_position+=0.55;
      }

      else if(x_position<=1350 && y_position>=680)	// balloon has crossed the screen
      {
            x_position+=0.40;
            y_position=0;
            balloons-=1;
      }

      else if(x_position>=1350 && y_position<=680)	// arrow has croseed the screen
      {
            x_position=0;
            shoot=0;
            score_here=0;
            y_position+=0.55;
      }

      else if(x_position>=1350 && y_position>=680) //	// balloon and arrow have crossed the screen
      {
            x_position=0;
            shoot=0;
            score_here=0;
            y_position=0;
            balloons-=1;
      }

      else
      {

      }

      if(balloons==0 || arrows==0) // to end game
      {
            end();
      }
}


// On Pressing Right Arrow key 
void processSpecialKeys(int key, int x, int y) 
{
      switch(key)
      {
            case GLUT_KEY_RIGHT: shoot=1;	// to release the arrow
                   break;
      }
      glutPostRedisplay();
}


// On Pressing Escape key 
void Normalkey(unsigned char key, int x, int y)
{
        switch(key)
        {
              case 27:exit(0); // to exit the screeen
        }
} 



void display()
{
      int q,a;
      glClear(GL_COLOR_BUFFER_BIT);
      glClearColor(0,0,0.2,0); // Background Color for navy blue -- glClearColor(0,0,0.2,0);
      glDepthFunc(GL_NEVER);

      //	text box 
      glColor3f(1,0,0);
      glPushMatrix();
      text_box();
      glutSwapBuffers();
      glPopMatrix();

      glDepthFunc(GL_NEVER);

      glColor3f(0.9,0.2,0.5);// Balloon color
      draw_balloon(1000,100); 

      //TEST
      glColor3f(0,0,0);
      glBegin(GL_LINE_LOOP);
      glVertex2f(1000,460);
      glVertex2f(1000,540);
      glEnd();
      glBegin(GL_LINE_LOOP);
      glVertex2f(900,500);
      glVertex2f(1100,500);
      glEnd();
      //END

      glColor3f(0.8,0.4,0.2);// Bow Color
      draw_bow(300,500);
      glColor3f(1,0,1);

      if(shoot==1)
      {
            draw_arrow(380,450);
            x_position+=1.30;// speed of arrow
            set_arrow_flag=true;
      }

      if(score_here==5)
      {
            glColor3f(0.9,0.2,0.5);
            draw_burst(1000,500);
      }
      glutSwapBuffers();
	
}


int main(int argc, char** argv)
{ 
       glutInit(&argc, argv);
       glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
       glutInitWindowSize(1350,680);
       glutCreateWindow("Balloon Shooting Game");
      // glutDisplayFunc(init); //	Optional
       glutDisplayFunc(display);
       glutKeyboardFunc(Normalkey);
       glutSpecialFunc(processSpecialKeys);
       glutTimerFunc(0,timer,0);
       gluOrtho2D(0,680,0,680);
       glutMainLoop();
       return 0;
}
