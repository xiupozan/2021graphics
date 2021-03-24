#include <GL/glut.h>
int N=0,vx[3000],vy[3000];
float angle=0;
void dispaly()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef(angle,0,0,1);
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<N;i++){
            glVertex2f((vx[i]-150)/150.0,-(vy[i]-150)/150.0);
        }
        glEnd();
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard( unsigned char key,int x,int y)
{
    angle++;
    display();
}
void motion(int x,int y)
{
    vx[N]=x;
    vy[N]=y;
    N++;
    dispaly();
}
int main(int argc, char ** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_DEPTH);
    glutCreateWindow("Hello world");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMotionFunc(motion);
    glutMainLoop()
}
