#include <GL/glut.h>
#include <math.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	//Cor roxo
	glColor3f(0.5, 0.0, 0.5);
	
	float cx = 0.0;
	float cy = 0.0;
	float raio = 0.5;
	int qtd_triangulos = 64;
	int i;
	
	glBegin(GL_POLYGON);
		for (i = 0; i < qtd_triangulos; i++){
			float angulo = 2.0 * M_PI * i / qtd_triangulos;
			float x = cx + raio * cosf(angulo);
			float y = cy + raio * sinf(angulo);
			glVertex2f(x, y);
		}
	glEnd();
	
	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//Modo de exibição
	glutInitWindowSize(500, 500);//Dimensões da janela
	glutInitWindowPosition(100, 100);//Posição da janela
	glutCreateWindow("Circulo");//Titulo da janela
	glutDisplayFunc(display);//Registra a função de desenho
	glutMainLoop();//Inicia o loop do glut
}