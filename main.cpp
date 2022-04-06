#include<windows.h>
#include <GL/glut.h>
#include<iostream>
#include <stdlib.h>



using namespace std;

void Translation(int x1, int y1, int x2, int y2)
{

}

void handleKeypress(unsigned char key, int x, int y)
{
switch(key)
{
case 27:
exit(0);
}
}
void initRendering()
{
glEnable(GL_DEPTH_TEST);
}



void handleResize(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0,(double)w/(double)h,1.0,200.0);
}



float _angle=0.0;
float _cameraangle=30.0;



void drawScene()
{





glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glRotatef(_cameraangle,0.0f,1.0f,0.0f); //rotate object by 30 degree with respect to y-axis
glTranslatef(0.0f, 0.0f, -10.0f);



glPushMatrix();
glTranslatef(5.0f, -1.0f, 0.0f);
glScalef(2.0f,2.0f,2.0f);





glRotatef(_angle,25.0f,25.0f,25.0f); //rotating object continuously by 25 degree
glBegin(GL_TRIANGLES);



glVertex3f(-0.7f,0.0f,0.0);
glVertex3f(0.7f,0.0f,0.0);
glVertex3f(0.5f,2.0f,0.0);
glVertex3f(-0.5f,2.0f,0.0);



glEnd();



glPopMatrix();
glutSwapBuffers();




}
void update(int value)
{
_angle+=2.0f;
if(_angle>360.f)
{
_angle-=360;
}
glutPostRedisplay();
glutTimerFunc(25,update,0);
}



int main(int argc,char**argv)
{
    int a;
    cout << "Enter your choice" << endl;
    cout << "1. Translation" << endl;
    cout << "2. Scaling" << endl;
    cout << "3. Rotation" << endl;
    cout << "4. Mirror Reflection" << endl;
    cout << "5. Shearing" << endl;
    cout << "6. Exit" << endl;
    cin>>a;
    if (1==a)
    {
        int x1, y1, x2, y2;
        cout<<"Enter Old Coordinates:"<<endl;
        cin>>x1;
        cin>>y1;
        cout<<"Enter New Points: "<<endl;
        cin>>x2;
        cin>>y2;
        int Xn = x1+x2;
    int Yn = y1+y2;

    cout<<"New Coordinates : "<<endl;
    cout<<"X new : "<<Xn<<endl;
    cout<<"Y new : "<<Yn<<endl;

    }
    if (2==a)
    {
         int x1, y1, x2, y2;
        cout<<"Enter Old Coordinates:"<<endl;
        cin>>x1;
        cin>>y1;
        cout<<"Enter New Points: "<<endl;
        cin>>x2;
        cin>>y2;
         int Xn = x1*x2;
    int Yn = y1*y2;

    cout<<"New Coordinates : "<<endl;
    cout<<"X new : "<<Xn<<endl;
    cout<<"Y new : "<<Yn<<endl;
    }
    if(3==a)
    {
       glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(600,600);




glutCreateWindow("rotate");
initRendering();






glutDisplayFunc(drawScene);
glutKeyboardFunc(handleKeypress);
glutReshapeFunc(handleResize);



glutTimerFunc(25,update,0);
//this call the function update in every 25 millsecond
//so value of angle of rotation change and object rotates continuously
glutMainLoop();

    }

    if(4==a)
    {
         int x1, y1,a;
         cout<<"1.Respect to X"<<endl;
         cout<<"2.Respect to y"<<endl;
         cin>>a;
         if(1==a){
               cout<<"Enter Old Coordinates:"<<endl;
        cin>>x1;
        cin>>y1;

int Xn = x1;
int Yn = -y1;
    cout<<"New Coordinates : "<<endl;
    cout<<"X new : "<<Xn<<endl;
    cout<<"Y new : "<<Yn<<endl;
         }
         if(2==a){
            cout<<"Enter Old Coordinates:"<<endl;
        cin>>x1;
        cin>>y1;

int Xn = -x1;
int Yn = y1;
    cout<<"New Coordinates : "<<endl;
    cout<<"X new : "<<Xn<<endl;
    cout<<"Y new : "<<Yn<<endl;
         }

    }

if(5==a)
{

    int x1, y1, x2, y2, a;
         cout<<"1.Shearing in X"<<endl;
         cout<<"2.Shearing in y"<<endl;
         cin>>a;
         if(1==a){
               cout<<"Enter Old Coordinates:"<<endl;
        cin>>x1;
        cin>>y1;
cout<<"Enter Shearing Points: "<<endl;
        cin>>x2;
        cin>>y2;
int Xn = x1+x2*y1;
int Yn = y1;
    cout<<"New Coordinates : "<<endl;
    cout<<"X new : "<<Xn<<endl;
    cout<<"Y new : "<<Yn<<endl;
         }
         if(2==a)
            {
            cout<<"Enter Old Coordinates:"<<endl;
        cin>>x1;
        cin>>y1;
cout<<"Enter Shearing Points: "<<endl;
        cin>>x2;
        cin>>y2;
int Xn = x1;
int Yn = y1+y2*x1;
    cout<<"New Coordinates : "<<endl;
    cout<<"X new : "<<Xn<<endl;
    cout<<"Y new : "<<Yn<<endl;
         }

}



return 0;
}
