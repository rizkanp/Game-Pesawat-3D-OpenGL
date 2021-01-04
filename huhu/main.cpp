
/*KELOMPOK 5
- Ivan Fredy Pratama    4611418053
- Endi Adika Tama       4611418073
- Rizka Nur Pratama     4611418078
*/

#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#define EN_SIZE 20

//mendefinisikan variabel yang dibutuhkan pada program
float zoom=4;
int tola[5000][5000];
float tX=0,tY=0,tZ=-8,rX=0,rY=0,rZ=4; 
float tZ1=-20,tZ2=-40,tZ3=-60,tZ4=-80,tZ5=-100,tZ6=-120;
float rotX=0,rotY=0,rotZ=0;
float speed = 0.3;
float angleBackFrac = 0.2;
bool saheedMinarVisible = false;
float r[] = {0.1,0.4,0.0,0.9,0.2,0.5,0.0,0.7,0.5,0.0};
float g[] = {0.2,0.0,0.4,0.5,0.2,0.0,0.3,0.9,0.0,0.2};
float b[] = {0.4,0.5,0.0,0.7,0.9,0.0,0.1,0.2,0.5,0.0};
int TIME=0;
bool START = false;
bool rot = false;
static int horizontal = 0;
static int vertical = 0;

//prosedur resize untuk mengatur ukuran objek
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//prosedur kipas pesawat(baling-baling)
void kipasPesawat(){
	glPushMatrix();
        glTranslated(0,0,0); // translasi mengubah ukuran    
        glScaled(1,1,0.7); // menggeser seluruh pemandangan ke kiri-kanan, atas-bawah, maju-mundur tergantung nilai
        glutSolidSphere(0.8,30,30); //membuat objek berpusat pada asal pemodelan sistem koordinat
    glPopMatrix();

	glPushMatrix();
        glTranslated(0,0,0);        
        glRotated(5,0,1,0); //memutar seluruh obyek dengan sudut angle (0–359) dan vektor yang dinyatakan dengan nilai x, y, dan z
        glScaled(0.5,2.5,0.05);
        glutSolidSphere(1,30,30);
    glPopMatrix();

	glPushMatrix();
        glTranslated(0,0,0);
        glRotated(-5,0,1,0);
        glRotated(90,0,0,1);
        glScaled(0.5,2.5,0.05);
        glutSolidSphere(1,30,30);
    glPopMatrix();
}

//prosedur pesawat
void pesawat(){
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;

    /// Main body
    glColor3d(1,0,0); //warna
    glPushMatrix();
        glTranslated(0,0,0);
        glScaled(3,0.6,0.5);
        glutSolidSphere(1,30,30);
    glPopMatrix();

    glColor3d(0,1,0);
    glPushMatrix();
        glTranslated(1.7,0.21,0);
        glScaled(1.5,0.7,0.8);
        glutSolidSphere(0.45,30,30);
    glPopMatrix();

    ///sayap depan kanan
    glColor3d(1,0.75,0);
    glPushMatrix();
        glTranslated(0,0,1.2);
        glRotated(-50,0,1,0);
        glScaled(0.7,0.1,3);
        glRotated(25,0,1,0);
        glutSolidCube(1); // bentuk kubus
    glPopMatrix();

    ///Baling-baling
    glPushMatrix();
        glTranslated(-0.3,-0.15,1.5);
        glRotated(90,0,1,0);

        ///baling-baling depan sayap depan kanan 1
        glPushMatrix();
            glTranslated(0,0,0.6);
            glRotated(10*a,0,0,1);
            glScaled(0.05,0.05,0.05);
            kipasPesawat();
        glPopMatrix();

        ///baling-baling belakang sayap depan kanan 1
        glPushMatrix();
            glTranslated(0,0,-0.6);
            glRotated(10*a,0,0,1);
            glScaled(0.05,0.05,0.05);
            kipasPesawat();
        glPopMatrix();

        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.7,1,50,50); // bentuk torus
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.2,-0.15,0.9);
        glRotated(90,0,1,0);

        ///baling-baling depan sayap depan kanan 2
        glPushMatrix();
            glTranslated(0,0,0.6);
            glRotated(10*a,0,0,1);
            glScaled(0.05,0.05,0.05);
            kipasPesawat();
        glPopMatrix();

        ///baling-baling belakang sayap depan kanan 2
        glPushMatrix();
            glTranslated(0,0,-0.6);
            glRotated(10*a,0,0,1);
            glScaled(0.05,0.05,0.05);
            kipasPesawat();
        glPopMatrix();

        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.7,1,50,50); 
    glPopMatrix();

    ///sayap depan kiri
    glColor3d(1,0.75,0);
    glPushMatrix();
        glTranslated(0,0,-1.2);
        glRotated(50,0,1,0);
        glScaled(0.7,0.1,3);
        glRotated(-25,0,1,0);
        glutSolidCube(1);
    glPopMatrix();

    ///baling-baling
    glPushMatrix();
        glTranslated(-0.3,-0.15,-1.5);
        glRotated(90,0,1,0);

        ///baling baling depan sayap depan kiri 1
        glPushMatrix();
            glTranslated(0,0,0.6);
            glRotated(10*a,0,0,1);
            glScaled(0.05,0.05,0.05);
            kipasPesawat();
        glPopMatrix();

        ///baling baling belakang sayap depan kiri 1
        glPushMatrix();
            glTranslated(0,0,-0.6);
            glRotated(10*a,0,0,1);
            glScaled(0.05,0.05,0.05);
            kipasPesawat();
        glPopMatrix();

        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.7,1,50,50);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.2,-0.15,-0.9);
        glRotated(90,0,1,0);

        ///baling baling depan sayap depan kiri 2
        glPushMatrix();
            glTranslated(0,0,0.6);
            glRotated(10*a,0,0,1);
            glScaled(0.05,0.05,0.05);
            kipasPesawat();
        glPopMatrix();

        ///baling baling belakang sayap depan kiri 2
        glPushMatrix();
            glTranslated(0,0,-0.6);
            glRotated(10*a,0,0,1);
            glScaled(0.05,0.05,0.05);
            kipasPesawat();
        glPopMatrix();

        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.7,1,50,50);
    glPopMatrix();


    ///sayap belakang
    glPushMatrix();
        glTranslated(-2.8,0,0);
        glScaled(0.8,0.5,0.3);

        ///kanana
        glPushMatrix();
            glTranslated(0.4,0,1.5);
            glRotated(-30,0,1,0);
            glScaled(0.7,0.1,3);
            glRotated(10,0,1,0);
            glutSolidCube(1);
        glPopMatrix();

        ///kiri
        glPushMatrix();
            glTranslated(0.4,0,-1.5);
            glRotated(30,0,1,0);
            glScaled(0.7,0.1,3);
            glRotated(-10,0,1,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    ///sayap belakang tengah
    glPushMatrix();
        glTranslated(-2.7,0.5,0);
        glRotated(45,0,0,1);
        glScaled(0.8,2,0.1);
        glRotated(-20,0,0,1);
        glutSolidCube(0.5);
    glPopMatrix();
}

/// mendefinisikan rumah
void rumah(int R,int G,int B)
    {
    glColor3d(r[R%11],g[G%11],b[B%11]);
    glPushMatrix();
        glTranslated(0,0,0);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0.2,0,0);
        glScaled(0.3,0.3,1.001);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(-0.2,0,0);
        glScaled(0.3,0.3,1.001);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,0,0.2);
        glScaled(1.001,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,0,-0.2);
        glScaled(1.001,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();
    }

///menggambar deretan rumah dengan memanggil object rumah memanfaatkan looping
void drawRumah(int n,int R,int G){
    for(int i=0;i<n;i++){
        glPushMatrix();
            glTranslated(0,0.8+i,0);
            rumah(G,R,i);
        glPopMatrix();
    }
}

///environment
void environment(int n){

    /// Tanah
    glColor3d(0.25,0.25,0);
    glPushMatrix();
        glTranslated(0,0,0);
        glScaled(EN_SIZE*2,0.3,EN_SIZE*2);
        glutSolidCube(1);
    glPopMatrix();

    ///memanggil evironment tanah dan rumah dengan efek bergerak dengan looping
    for(int i=-(EN_SIZE/2)+1;i<(EN_SIZE/2);i+=2){
        for(int j=-(EN_SIZE/2)+1;j<(EN_SIZE/2);j+=2){
            if(tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1]!=0){
                glPushMatrix();
                    glTranslated(i,0,j);
                    drawRumah(tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1],i,j);
                glPopMatrix();
            }else if(i>=-5&&i<=5){}
            else{
                tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1]=(rand()%5)+1;
                glPushMatrix();
                    glTranslated(i,0,j);
                    drawRumah(tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1],i,j);
                glPopMatrix();
            }
        }
    }
}

///memanggil pesawat dan environmet
void draw(){ //
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;

    TIME = t;

    ///Pesawat
    if(rotX>11)rotX=11; //rot = rotasi
    if(rotX<-11)rotX=-11;
    if(rotZ>10)rotZ=10;
    if(rotZ<-15)rotZ=-15;

    glPushMatrix();
        glTranslated(0,1,0);
        glRotated(90,0,1,0);
        glRotated(5,0,0,1);
        glRotated(rotX,1,0,0);
        glRotated(rotY,0,1,0);
        glRotated(rotZ,0,0,1);

        glScaled(0.4,0.4,0.4);
        pesawat();
    glPopMatrix();

    ///Environment
    if(tX>=4.1)tX=4.1; // tx = translasi x
    if(tX<=-4.1)tX=-4.1;
    if(tY>0.1)tY= 0.1;
    if(tY<-15)tY= -15;

    glPushMatrix();
        glTranslated(tX,tY,tZ);
        environment(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ2);
        environment(3);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ3);
        environment(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ4);
        environment(5);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ5);
        environment(4);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ6);
        environment(2);
    glPopMatrix();

    tZ+=speed;
    tZ1+=speed;
    tZ2+=speed;
    tZ3+=speed;
    tZ4+=speed;
    tZ5+=speed;
    tZ6+=speed;

    if(tZ>=20)tZ=-110;
    if(tZ1>=20)tZ1=-110;
    if(tZ2>=20)tZ2=-110;
    if(tZ3>=20)tZ3=-110;
    if(tZ4>=20)tZ4=-110;
    if(tZ5>=20)tZ5=-110;
    if(tZ6>=20)tZ6=-110;

    if(rotX>0)rotX-=angleBackFrac;
    if(rotX<0)rotX+=angleBackFrac;
    if(rotY>0)rotY-=angleBackFrac;
    if(rotY<0)rotY+=angleBackFrac;
    if(rotZ>0)rotZ-=angleBackFrac;
    if(rotZ<0)rotZ+=angleBackFrac;

    speed += 0.0002;
    if(speed>=0.7)speed=0.7;
}

///mendefinisikan tampilan huruf
void drawStrokeText(const char* str,float x,float y,float z)
{
	  const char *c;
	  glPushMatrix();
	  glTranslatef(x, y+8,z);
	  glScalef(0.002f,0.002f,z);

	  for (c=str; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN   , *c); //font tulisan
	  }
	  glPopMatrix();
}

///mendefinisikan tampilan huruf dengan tampilan lebih kecil
void drawStrokeText2(const char* str,float x,float y,float z)
{
	  const char *c;
	  glPushMatrix();
	  glTranslatef(x, y+8,z);
	  glScalef(0.005f,0.005f,z);

	  for (c=str; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();
}

///membuat teks yang berubah-ubah didalam jendela
void drawStrokeChar(char c,float x,float y,float z)
{
	  glPushMatrix();
          glTranslatef(x, y+8,z);
          glScalef(0.002f,0.002f,z);
          glutStrokeCharacter(GLUT_STROKE_ROMAN , c);
	  glPopMatrix();
}

///menampilkan object yang akan ditampilkan dilayar
static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;
    double aa=a;

    if(!rot){
        a=0;
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // bersihkan layar dan buffer

    glLoadIdentity(); //replace the current matrix with the identity matrix

    gluLookAt(	0.0, 4.5, 10.0,
                0, 4, 0,
                0, 1.0f, 0.0f);

    if(START){

        glPushMatrix();
            glTranslated(0,0,0);
            glScaled(zoom,zoom,zoom);
            glRotated(a,0,1,0);
            glRotated(horizontal,0,1,0);
            glRotated(vertical,1,0,0);
            draw();
        glPopMatrix();

        ///menampilkan bantuan fungsi tombol pada keyboard
        drawStrokeText("NAIK:F, TURUN:J, KIRI:D, KANAN:K, MENU UTAMA:M",-8,0,0);
        drawStrokeText("KAMERA: ",-8,-0.5,0);
        drawStrokeText("ATAS:V , BAWAH:N, KIRI:G, KANAN:H",-7.5,-1,0);
        drawStrokeText("MEMPERBESAR:Z, MEMPERKECIL:X",-8,-1.5,0);
        drawStrokeText("WAKTU : ", 2.5,0,0);
        int mod,number=0;
        while(TIME){
            mod=TIME%10;
            number=number*10+mod;
            TIME/=10;
        }
        float tmp=0;
        while(number){
            mod=number%10;
            drawStrokeChar(mod+48,4+tmp,0,0);
            number/=10;
            tmp+=0.2;
        }
    }
    else{

        glPushMatrix();
            glTranslated(0,3,0);
            glRotated(aa,0,1,0);
            glScaled(1.5,1.5,1.5);
            pesawat();
        glPopMatrix();

        drawStrokeText("TEKAN S UNTUK MULAI",-1.5,-1,0);
        drawStrokeText2("Pesawat",-1,0,0);
    }

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    float frac = 0.3;
    float rotFrac = 1;
    switch (key)
    {
        case 'H' : horizontal -=5; break; ///menggerakkan kamera ke kanan
        case 'h' : horizontal -=5; break;
        case 'V' : vertical +=5; break; /// menggerakkan kamera ke atas
        case 'v' : vertical +=5; break;
        case 'G' : horizontal +=5; break; ///mengerakan kamera ke kiri
        case 'g' : horizontal +=5; break;
        case 'N' : vertical -=5; break; ///menggerakkan kamera ke bawah
        case 'n' : vertical -=5; break;
        case 'Q' : ///untuk keluar dari progra,
            exit(0);
            break;
        case 'q':
            exit(0);
            break;
        case 'Z': /// memperbesar (zoom in)
            zoom+=0.05;
            break;
        case 'z':
            zoom+=0.05;
            break;
        case 'X': /// memperkecil (zoom out)
            zoom-=0.05;
            break;
        case 'x':
            zoom-=0.05;
            break;
        case 'F': /// naik ke atas
            tY-=frac;
            rotZ+=rotFrac;
            break;
        case 'f':
            tY-=frac;
            rotZ+=rotFrac;
            break;
        case 'J': /// turun bawah
            tY+=frac;
            rotZ-=rotFrac;
            break;
        case 'j':
            tY+=frac;
            rotZ-=rotFrac;
            break;
        case 'D': ///kiri
            tX+=frac;
            rotX-=rotFrac*3;
            rotY+=rotFrac/2;
            break;
        case 'd':
            tX+=frac;
            rotX-=rotFrac*3;
            rotY+=rotFrac/2;
            break;
        case 'K': ///kanan
            tX-=frac;
            rotX+=rotFrac*3;
            rotY-=rotFrac/2;
            break;
        case 'k':
            tX-=frac;
            rotX+=rotFrac*3;
            rotY-=rotFrac/2;
            break;
        case 'S': ///memulain permainan
            START=true;
            break;
        case 's':
            START=true;
            break;
        case 'M': /// restart
            START=false;
            break;
        case 'm':
            START=false;
            break;

    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay(); /// membuat tampilan ketika tidak ditekan tombol apapun
}

///definisi lighting
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f }; //intensitas cahaya RGBA ambien
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f }; //intensitas cahaya RGBA yang menyebar
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; //intensitas cahaya RGBA specular
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f }; // posisi cahaya

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


/* Membuat Jendela view dan memanggil object yang telah dibuat*/

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);  // posisi di layar computer
	glutInitWindowSize(1366,720); // ukuran layar
    //untuk inisialisasi modus display. Fungsi tersebut meminta window yang bersifat double buffered, dengan warna RGB
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA); 

    glutCreateWindow("KELOMPOK 5");

    glutReshapeFunc(resize); 
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    ///PlaySound("starwars.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
