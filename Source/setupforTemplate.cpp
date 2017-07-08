// setupforTemplate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ShapeData.h"
#include "ShapeGenerator.h"

int programID;
unsigned int theta;

int width = 500;
int height = 500;


void uploadShaders(GLuint vertID, GLuint fragID){
	std::ifstream vert("vertshader.vert");
	std::ifstream frag("fragshader.frag");
	std::string Line;
	std::string Source;
	const char *adapterA[1];
	const char *adapterB[1];
	if (vert.is_open()){

		while (std::getline(vert, Line)){
			Source += (Line + '\n');
		}
		adapterA[0] = Source.c_str();
		vert.close();
		glShaderSource(vertID, 1, adapterA, 0);
		Source.clear();
		Line.clear();
	}

	if (frag.is_open()){

		while (std::getline(frag, Line)){
			Source += (Line + '\n');
		}
		adapterB[0] = Source.c_str();
		frag.close();
		glShaderSource(fragID, 1, adapterB, 0);
		frag.close();
	}
}

void setupShaders(){
	GLuint vertShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	uploadShaders(vertShaderID, fragShaderID);

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


	//ShapeData h = ShapeGenerator::getDefaultShape();

	ShapeData h = ShapeGenerator::getDefaultShape();

	GLuint bufferID;
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, h.vertSize, h.vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, 0, sizeof(GL_FLOAT) * 6, 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, 0, sizeof(GL_FLOAT) * 6, (char*)(sizeof(GL_FLOAT) * 3));

	GLuint indexID;
	glGenBuffers(1, &indexID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, h.indSize, h.indices, GL_STATIC_DRAW);
	
}

void updateVerts(void){
	theta++;
	glutPostRedisplay();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glViewport(0, 0, width, height);

	glm::mat4 translationMatrix = glm::translate(glm::mat4(), glm::vec3(-0.5f, -0.5f, -3.5f));
	glm::mat4 rotationMatrix = glm::rotate(glm::mat4(), static_cast<float>(theta) / 10000, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 projectionMatrix = glm::perspective(glm::radians(60.0f), (static_cast<float>(width) / height), 0.1f, 100.0f);

	glm::mat4 fullMatrix = projectionMatrix * translationMatrix * rotationMatrix;

	GLint fullLocation = glGetUniformLocation(programID, "fullMat");

	glUniformMatrix4fv(fullLocation, 1, GL_FALSE, &fullMatrix[0][0]);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);


	 
	rotationMatrix = glm::rotate(glm::mat4(), static_cast<float>(theta) / 10000, glm::vec3(0.0f, 0.5f, 0.3f));
	translationMatrix = glm::translate(glm::mat4(), glm::vec3(20.0f, 2.3f, -40.0f));

	fullMatrix = projectionMatrix *translationMatrix * rotationMatrix;

	glUniformMatrix4fv(fullLocation, 1, GL_FALSE, &fullMatrix[0][0]);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);


	glFlush();

}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(width, height);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(argv[0]);
	glEnable(GL_DEPTH_TEST);

	if (glewInit()) {
		printf("There was an error initiating glew\n");
		exit(EXIT_FAILURE);

	}
	
	setupShaders();
	init();
	

	glutIdleFunc(updateVerts);
	glutDisplayFunc(display);

	glutMainLoop();




	return 0;
}
