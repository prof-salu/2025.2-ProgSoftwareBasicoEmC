#include <GL/glut.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	//COR PRETA
	glColor3f(0, 0, 0);
	
	//Desenha 5 pontos prenchidos
	glBegin(GL_POINTS);
		glVertex2f(0,0);
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.5,0.5);
		glVertex2f(-0.5,0.5);
		glVertex2f(0.5,-0.5);		
	glEnd();
	
	//Cor azul
	glColor3f(0, 0, 1);
	//Desenhando uma reta
	glBegin(GL_LINES);
		glVertex2f(0.7, 0.7);
		glVertex2f(-0.7, 0.7);
	glEnd();
	
	//Cor Verde
	glColor3f(0, 1, 0);
	//Desenhando o pentago
	glBegin(GL_POLYGON);
		glVertex2f(0.0, 0.5);
		glVertex2f(0.25, 0.25);
		glVertex2f(0.25, 0.0);
		glVertex2f(-0.25, 0.0);
		glVertex2f(-0.25, 0.25);				
	glEnd();
	
	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//Modo de exibição
	glutInitWindowSize(500, 500);//Dimensões da janela
	glutInitWindowPosition(100, 100);//Posição da janela
	glutCreateWindow("Pontos e retas");//Titulo da janela
	glutDisplayFunc(display);//Registra a função de desenho
	glClearColor(1,1,1,1);//DEFINE A COR DE FUNDO
	glutMainLoop();//Inicia o loop do glut
}