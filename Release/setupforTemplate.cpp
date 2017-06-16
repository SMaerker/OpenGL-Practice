// setupforTemplate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glew\GL\glew.h>
#include <glut\freeglut.h>
#include <gl\GL.h>





void init() {
	GLuint VAOs[1];

	glGenVertexArrays(1, VAOs);
	glBindVertexArray(VAOs[0]);
	
	GLfloat verts[12 + 6 * 3] = {
		//Triangle 1
		 -0.90, -0.90 ,	//0
		 +0.00, +1.00, +0.00,

		 +0.85, -0.90 ,	//1
		 +0.00, +1.00, +0.00,


		 -0.90, +0.85 ,	//2
		 +0.00, +1.00, +0.00,


		// Triangle 2
		 +0.90, -0.85 ,	//3 
		 +0.00, +1.00, +0.00,


		 +0.90, +0.90 ,	//4
		 +0.00, +1.00, +0.00,


		 -0.85, +0.90 	//5
		 + 0.00, +1.00, +0.00,

	};


	GLuint bufferID;
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 5, 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 5, (char*)(sizeof(GL_FLOAT) * 2));
	

	GLushort indices[] = { 0, 1, 2, 3, 4, 5 };
	GLuint indexID;

	glGenBuffers(1, &indexID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
	glFlush();
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(argv[0]);
	

	if (glewInit()) {
		printf("There was an error initiating glew\n");
		exit(EXIT_FAILURE);

	}

	init();

	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}
