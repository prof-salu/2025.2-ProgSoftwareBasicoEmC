#include <GL/glut.h>

void display(){
	//Limpa o canvas/tela
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Definindo a cor do desenho (RGB --> Red, Green, Blue)
	//(0-255, 0-255, 0-255)
	glColor3f(1, 0, 0);//vermelho
	
	glBegin(GL_POLYGON);
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.5, -0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(-0.5, 0.5);
	glEnd();
	
	glFlush();//Garante que tudo sera renderizado
	
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//Modo de exibição
	glutInitWindowSize(500, 500);//Dimensões da janela
	glutInitWindowPosition(100, 100);//Posição da janela
	glutCreateWindow("Quadrado vermelho");//Titulo da janela
	glutDisplayFunc(display);//Registra a função de desenho
	glutMainLoop();//Inicia o loop do glut
}





