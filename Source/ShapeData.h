#pragma once
#include "stdafx.h"
#include <algorithm>
struct ShapeData{

	//default constructor
	ShapeData() :	vertices(0), indices(0),
					vertSize(0), indSize(0)
					{printf("Default constructor invoked\n");};


	 //copy constructor
	ShapeData(const ShapeData &data) : vertSize(data.vertSize), indSize(data.indSize),
										vertices(new float[data.vertSize]), indices(new GLushort[data.indSize]){
											printf("Copy constructor invoked\n"); 
											memcpy(vertices, data.vertices, data.vertSize);
											memcpy(indices, data.indices, data.indSize);

											std::cout << vertices[3];

										};

	//~ShapeData() { delete vertices; delete indices; };

	GLuint vertSize;
	GLuint indSize;

	float *vertices;
	GLushort *indices;
};