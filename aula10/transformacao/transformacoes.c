#include <GL/glut.h>

//Transformações
	//translação (translation)
	//rotação (rotation)
	//Escala (scale)

float quadradoX = 0;
float quadradoY = 0;
float incremento = 0.1;
float raio = 0.1;
float angulo = 0;

void display(){
	//Limpa a tela
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Definindo a cor do desenho
	glColor3f(1.0, 0.0, 0.0);//(R, G, B) [Vermelho]
	glPushMatrix();
		//glTranslatef(posX, posY, posZ);
		glTranslatef(quadradoX, quadradoY, 0.0);
		//glRotatef(graus [0-360], eixoX, eixoY, eixoZ);
		glRotatef(angulo, 0.0, 0.0, 1.0);
		//glScalef(tamanhoX, tamanhoY, tamanhoZ);
		glScalef(raio, raio, raio);
		
		glBegin(GL_QUADS);
			glVertex2f(-0.1, -0.1);
			glVertex2f(0.1, -0.1);
			glVertex2f(0.1, 0.1);
			glVertex2f(-0.1, 0.1);
		glEnd();
	//Restaura a matriz de transformação
	glPopMatrix();
	
	//Troca os buffers para exibir o que foi destruido
	glutSwapBuffers();
}

void atualizaCena(int value){
	//Atualiza a posição do quadrado
	quadradoX += incremento;	
	
	if(quadradoX > 0.9 || quadradoX < -0.9){
		incremento *= -1;
		raio += 0.1;
		angulo += 15;
	}   
	         
	//Define a janela para o redesenho
	glutPostRedisplay();
	
	glutTimerFunc(16, atualizaCena, 0);
}

void redimensionar(int largura, int altura){
	//Define a porção da janela utilizada para o desenho
	glViewport(0, 0,largura, altura);	
	//Define as operações de matrix
	glMatrixMode(GL_PROJECTION);
	//Reseta a matrix de projeção
	glLoadIdentity();
	//Define uma projeção ortogonal
	//limites [esquerdo, direito, inferior, superior, perto, longe]
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Quadrado em movimento");	
	glClearColor(0, 0, 0, 0);	
	glutDisplayFunc(display);
	glutReshapeFunc(redimensionar);
	glutTimerFunc(16, atualizaCena, 0);
	glutMainLoop();
}