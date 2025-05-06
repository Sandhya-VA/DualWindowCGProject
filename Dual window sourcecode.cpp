
#include <stdlib.h>

#include <stdio.h>

#include <GL/glut.h>

#include <math.h>

GLfloat planes[]={-1.0,0.0,1.0,0.0};

GLfloat planet[]={0.0,-1.0,0.0,1.0};



int sel;

int abc,efg;



        GLfloat vertices[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},

        {1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0}, 

        {1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0}};



        GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},

        {1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0}, 

        {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};



        void square_plate()

        {

                        glTranslatef(-0.5,-0.5,0.0);

                         glBegin(GL_QUADS);

                        glColor3f(0.0,1.0,1.0);

                        glTexCoord2f(0.0,0.0);

                        glVertex3f(0.0,0.0,0.0);

                        glTexCoord2f(1.0,0.0);

                        glVertex3f(0.0,1.0,0.0);

                        glTexCoord2f(1.0,1.0);

                        glVertex3f(1.0,1.0,1.0);

                        glTexCoord2f(0.0,1.0);

                        glVertex3f(1.0,0.0,1.0);

                glEnd();

                

        }

        void triangle_plate()

        {

                glTranslatef(-0.5,-0.5,0.0);

                glBegin(GL_TRIANGLES);

                glColor3f(0.0,0.0,1.0);

                glTexCoord2f(0.0,0.0);

                glVertex3f(0.0,0.0,0.0);

                glTexCoord2f(1.0,0.0);

                glVertex3f(0.5,1.0,1.0);

                glTexCoord2f(1.0,1.0);

                glVertex3f(1.0,0.0,0.0);

                glEnd();

        }



        void polygon(int a, int b, int c , int d)

{

		       glBegin(GL_POLYGON);

                glColor3fv(colors[a]);

                glTexCoord2f(0.0,0.0);

                glVertex3fv(vertices[a]);

                glColor3fv(colors[b]);

                glTexCoord2f(0.0,1.0);

                glVertex3fv(vertices[b]);

                glColor3fv(colors[c]);

                glTexCoord2f(1.0,1.0);

                glVertex3fv(vertices[c]);

                glColor3fv(colors[d]);

                glTexCoord2f(1.0,0.0);

                glVertex3fv(vertices[d]);

        glEnd();

}



void colorcube(void)

{


        polygon(0,3,2,1);

        polygon(2,3,7,6);

        polygon(0,4,7,3);

        polygon(1,2,6,5);

        polygon(4,5,6,7);

        polygon(0,1,5,4);

}

void pyramid()

{

glBegin(GL_TRIANGLES);

 

    glColor3f(1.0f,1.0f,1.0f); 

        glTexCoord4f(0.0,0.0,0.0,1.0); 

        glVertex3f( 0.0f, 1.0f, 0.0f);   

    glColor3f(0.0f,1.0f,0.0f); 

        glTexCoord4f(0.0,1.0,1.0,0.0); 

        glVertex3f(-1.0f,-1.0f, 1.0f);   

    glColor3f(0.0f,0.0f,1.0f); 

        glTexCoord4f(0.0,1.0,1.0,1.0); 

        glVertex3f( 1.0f,-1.0f, 1.0f);   

  
    glColor3f(1.0f,1.0f,0.0f); 

        glTexCoord3f(0.0,0.0,0.0); 

        glVertex3f( 0.0f, 1.0f, 0.0f);   
    glColor3f(0.0f,1.0f,1.0f); 

        glTexCoord3f(0.0,1.0,0.0); 

        glVertex3f( 1.0f,-1.0f, 1.0f);   

    glColor3f(0.0f,1.0f,0.0f); 

        glTexCoord3f(1.0,0.0,1.0); 

        glVertex3f( 1.0f,-1.0f,-1.0f);   

    glColor3f(1.0f,0.0f,0.0f); 

        glTexCoord2f(0.0,0.0); 

        glVertex3f( 0.0f, 1.0f, 0.0f);   

    glColor3f(1.0f,1.0f,0.0f); 

        glTexCoord2f(0.0,1.0); 

        glVertex3f( 1.0f,-1.0f,-1.0f);   
    glColor3f(0.0f,0.0f,1.0f); 

        glTexCoord2f(1.0,1.0); 

        glVertex3f(-1.0f,-1.0f,-1.0f);   

  

    glColor3f(1.0f,0.0f,0.0f); 

        glTexCoord1f(0.0); 

        glVertex3f( 0.0f, 1.0f, 0.0f);   

    glColor3f(0.0f,0.0f,1.0f); 

        glTexCoord1f(1.0); 

        glVertex3f(-1.0f,-1.0f,-1.0f);   

    glColor3f(1.0f,1.0f,0.0f); 

        glTexCoord1f(1.0); 

        glVertex3f(-1.0f,-1.0f, 1.0f);   
glEnd();



}



static GLfloat theta[] = {0.0,0.0,0.0};

static GLint axis = 2;



void display()

{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();

        glRotatef(theta[0], 1.0, 0.0, 0.0);

        glRotatef(theta[1], 0.0, 1.0, 0.0);

        glRotatef(theta[2], 0.0, 0.0, 1.0);

        

        

        switch(sel)

        {

        case 1:square_plate();

                        break;

        case 2:triangle_plate();

                        break;

        case 3:colorcube();

                        break;

        case 4:pyramid();

                        break;

        }

        glutSwapBuffers();

}

void display1()

{

       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();

        

        switch(sel)

        {

        case 1:square_plate();

                        break;

        case 2:triangle_plate();

                        break;

        case 3:colorcube();

                        break;

        case 4:pyramid();

                        break;

        }

        glutSwapBuffers();

}

void displaya()

{

        glClear (GL_COLOR_BUFFER_BIT);

        square_plate();

        triangle_plate();

        colorcube();

        pyramid();

        glutSwapBuffers();

}

void displayb()

{

        glClear (GL_COLOR_BUFFER_BIT);

        square_plate();

        triangle_plate();

        colorcube();

        pyramid();

        glutSwapBuffers();

        glFinish();

}



void spinCube()

{

		theta[axis] += 0.1;

        if( theta[axis] > 360.0 ) theta[axis] -= 360.0;        

        glutSetWindow(abc);

        glutPostRedisplay();

        glutSetWindow(efg);

        glutPostRedisplay();

}



void myMenu(int s)

{

        sel=s;

        glutPostRedisplay();

}





void myReshape(int w, int h)

{

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    if (w <= h)

        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,

            2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);

    else

        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,

            2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);

    glMatrixMode(GL_MODELVIEW);

}

void keys(unsigned char key,int x,int y)

{

        switch(key)

        {

        case '1':

                sel=1;

                break;

        case '2':

                sel=2;

                break;

        case '3':

                sel=3;

                break;

        case '4':

                sel=4;

                break;

        case 'q':

                exit(0);

                break;

        }

        glutPostRedisplay();



}

void mySpecialKey(int k, int x, int y)

{

        switch(k)

        {

        case GLUT_KEY_LEFT:

                axis=0;

                break;

        case GLUT_KEY_RIGHT:

                axis=1;

                break;

        case GLUT_KEY_UP:

                axis=2;

                break;

        case GLUT_KEY_DOWN:

                exit(0);

        }

        glutPostRedisplay();



}
int main(int argc, char **argv)

{

        GLubyte image[64][64][3];

        int i,j,c;

        for(i=0;i<64;i++)

        {

                        for(j=0;j<64;j++)

                        {

                                c=(((i&0x8)==0)^((j&0x8))==0)*255;

                                image[i][j][0]=(GLubyte) c;

                                image[i][j][1]=(GLubyte) c;

                                image[i][j][2]=(GLubyte) c;

                        }

        }



        glutInit(&argc, argv);

		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

        glutInitWindowPosition(100,100);

        glutInitWindowSize(400,400);

        abc=glutCreateWindow("FIRST WINDOW");

        glutDisplayFunc(displaya);

        glutReshapeFunc(myReshape);

        glutIdleFunc(spinCube);

        glutDisplayFunc(display1);

        glEnable (GL_DEPTH_TEST);

        glutKeyboardFunc(keys);

        glutSpecialFunc(mySpecialKey);

        glutCreateMenu(myMenu);

        glutAddMenuEntry("Square",1);

        glutAddMenuEntry("Triangle",2);

        glutAddMenuEntry("Colorcube",3);

        glutAddMenuEntry("Pyramid",4);

        glutAttachMenu(GLUT_RIGHT_BUTTON);

        glEnable(GL_DEPTH_TEST);

        glEnable(GL_TEXTURE_2D);

        glTexImage2D(GL_TEXTURE_2D,0,3,64,64,0,GL_RGB,GL_UNSIGNED_BYTE,image);

        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);

        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);

        glClearColor(1.0,1.0,1.0,1.0);



         



        glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);

        glutInitWindowPosition(520,100);

        glutInitWindowSize(400,400);

        efg=glutCreateWindow("SECOND WINDOW");

        glutDisplayFunc(displayb);

        glutReshapeFunc(myReshape);

        glutDisplayFunc(display);

        glEnable (GL_LIGHT5);

        glShadeModel (GL_SMOOTH);

        glEnable (GL_DEPTH_TEST);

        glutKeyboardFunc(keys);

        glutSpecialFunc(mySpecialKey);

        glutCreateMenu(myMenu);

        glutAddMenuEntry("Square",1);

        glutAddMenuEntry("Triangle",2);

        glutAddMenuEntry("Colorcube",3);

        glutAddMenuEntry("Pyramid",4);

        glutAttachMenu(GLUT_RIGHT_BUTTON);

        glEnable(GL_DEPTH_TEST); 

        glEnable(GL_TEXTURE_2D);

        glTexImage2D(GL_TEXTURE_2D,0,3,64,64,0,GL_RGB,GL_UNSIGNED_BYTE,image);

        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);

        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);

        glClearColor(1.0,1.0,1.0,1.0);

        printf("\nLEFT DIRECTIONAL BUTTON ==> : AXIS-0\n");

        printf("\nRIGHT DIRECTIONAL BUTTON ==> : AXIS-1\n");

        printf("\nUP DIRECTIONAL BUTTON ==> : AXIS-2\n");

        printf("\nDOWN DIRECTIONAL BUTTON ==> : QUIT\n");

        printf("\n1==> : SQUARE PLATE WITH TEXTURE\n");

        printf("\n2==> : TRIANGLE PLATE WITH TEXTURE\n");

        printf("\n3==> : COLORCUBE WITH TEXTURE\n");

        printf("\n4==> : PYRAMID WITH TEXTURE\n");

        glutMainLoop();

        return 0;

}

