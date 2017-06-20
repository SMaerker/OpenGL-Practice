// setupforTemplate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glew\GL\glew.h>
#include <glut\freeglut.h>
#include <gl\GL.h>
#include <glm\glm.hpp>

//extern const char* const vertShader;
//extern const char* const fragShader;

const char* const vertShader =
"#version 430\r\n"
"in layout(location = 0) vec3 position;"
"in layout(location = 1) vec3 vertColor;"
"out vec3 theColor;"
"void main()"
"{"
"gl_Position = vec4(position, 1.0);"
"theColor = vertColor;"
"}";

const char* const fragShader =
"#version 430\r\n"
"in vec3 theColor;"
"out vec4 daColor;"
"void main()"
"{"
"daColor = vec4(theColor, 1.0);"
"}";

void setupShaders(){
	GLuint vertShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	int programID;

	const char *adapter[1];
	adapter[0] = vertShader;


	const GLchar *const *foo = &vertShader;
	const GLchar *const *bar = &fragShader;
	glShaderSource(vertShaderID, 1, foo, 0);
	glShaderSource(fragShaderID, 1, bar, 0);

	programID = glCreateProgram();

	glCompileShader(vertShaderID);
	glCompileShader(fragShaderID);

	glAttachShader(programID, vertShaderID);
	glAttachShader(programID, fragShaderID);

	glLinkProgram(programID);
	

	glUseProgram(programID);

}

void init() {

	
	GLuint VAOs[1];

	glGenVertexArrays(1, VAOs);
	glBindVertexArray(VAOs[0]);
	
	GLfloat verts[36] = {
		//Triangle 1
		 -1.00, +1.00, -1.00, 	//0
		 +0.00, +1.00, +0.00,

		 +1.00, +1.00 ,	-1.00,//1
		 +0.00, +1.00, +0.00,


		 -0.00, -1.00 ,	-1.00,//2
		 +0.00, +1.00, +0.00,


		// Triangle 2
		 -1.00, -1.00 ,-0.00,	//3 
		 +0.00, +0.00, +1.00,


		 +1.00, -1.00 ,0.00,	//4
		 +0.00, +0.00, +1.00,


		 -0.00, +1.00, 0.00,//5
		 +0.00, +0.00, +1.00,

	};


	GLuint bufferID;
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 6, 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 6, (char*)(sizeof(GL_FLOAT) * 3));
	

	GLushort indices[] = { 0, 1, 2, 3, 4, 5 };
	GLuint indexID;

	glGenBuffers(1, &indexID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

}


void updateVerts(void){

}

void display(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
	glEnable(GL_DEPTH_TEST);

	if (glewInit()) {
		printf("There was an error initiating glew\n");
		exit(EXIT_FAILURE);

	}

	

	init();

	setupShaders();

	glutIdleFunc(updateVerts);
	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}
