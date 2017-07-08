#include "stdafx.h"
#include "ShapeGenerator.h"


ShapeGenerator::ShapeGenerator(){
}


ShapeGenerator::~ShapeGenerator(){
}

const ShapeData ShapeGenerator::getDefaultShape(){
	ShapeData data;

	float vertData[] = {
		-1.0f, +1.0f, +1.0f, // 0
		+1.0f, +0.0f, +0.0f, // Colour
		+1.0f, +1.0f, +1.0f, // 1
		+1.0f, +0.0f, +0.0f, // Colour
		+1.0f, +1.0f, -1.0f, // 2
		+1.0f, +0.0f, +0.0f, // Colour
		-1.0f, +1.0f, -1.0f, // 3
		+1.0f, +0.0f, +0.0f, // Colour

		-1.0f, +1.0f, -1.0f, // 4
		+0.0f, +0.0f, +1.0f, // Colour
		+1.0f, +1.0f, -1.0f, // 5
		+0.0f, +0.0f, +1.0f, // Colour
		+1.0f, -1.0f, -1.0f, // 6
		+0.0f, +0.0f, +1.0f, // Colour
		-1.0f, -1.0f, -1.0f, // 7
		+0.0f, +0.0f, +1.0f, // Colour

		+1.0f, +1.0f, -1.0f, // 8
		+0.0f, +1.0f, +0.0f, // Colour
		+1.0f, +1.0f, +1.0f, // 9
		+0.0f, +1.0f, +0.0f, // Colour
		+1.0f, -1.0f, +1.0f, // 10
		+0.0f, +1.0f, +0.0f, // Colour
		+1.0f, -1.0f, -1.0f, // 11
		+0.0f, +1.0f, +0.0f, // Colour

		-1.0f, +1.0f, +1.0f, // 12
		+0.0f, +1.0f, +1.0f, // Colour
		-1.0f, +1.0f, -1.0f, // 13
		+0.0f, +1.0f, +1.0f, // Colour
		-1.0f, -1.0f, -1.0f, // 14
		+0.0f, +1.0f, +1.0f, // Colour
		-1.0f, -1.0f, +1.0f, // 15
		+0.0f, +1.0f, +1.0f, // Colour

		+1.0f, +1.0f, +1.0f, // 16
		+1.0f, +1.0f, +0.0f, // Colour
		-1.0f, +1.0f, +1.0f, // 17
		+1.0f, +1.0f, +0.0f, // Colour
		-1.0f, -1.0f, +1.0f, // 18
		+1.0f, +1.0f, +0.0f, // Colour
		+1.0f, -1.0f, +1.0f, // 19
		+1.0f, +1.0f, +0.0f, // Colour

		+1.0f, -1.0f, -1.0f, // 20
		+1.0f, +0.0f, +1.0f, // Colour
		-1.0f, -1.0f, -1.0f, // 21
		+1.0f, +0.0f, +1.0f, // Colour
		-1.0f, -1.0f, +1.0f, // 22
		+1.0f, +0.0f, +1.0f, // Colour
		+1.0f, -1.0f, +1.0f, // 23
		+1.0f, +0.0f, +1.0f // Colour

	};


	GLushort indexData[36] = { 
		0, 1, 2, 0, 2, 3, // Top
		4, 5, 6, 4, 6, 7, // Front
		8, 9, 10, 8, 10, 11, // Right
		12, 13, 14, 12, 14, 15, // Left
		16, 17, 18, 16, 18, 19, // Back
		20, 22, 21, 20, 23, 22, // Bottom 
	};

	data.vertices = vertData;
	data.indices = indexData;

	data.vertSize = sizeof(vertData);
	data.indSize = sizeof(indexData);


	return data;
}

const ShapeData ShapeGenerator::getPyramid(){
	ShapeData data;

	float vertData[] = {
		-1.0f, -1.0f, +1.0f,	// vert 0
		+1.0f, +0.0f, +0.0f,	// colr 0
		+1.0f, -1.0f, +1.0f,	// vert 1
		+1.0f, +0.0f, +0.0f,	// colr 1
		-1.0f, -1.0f, -1.0f,	// vert 2
		+1.0f, +0.0f, +0.0f,	// colr 2
		+1.0f, -1.0f, -1.0f,	// vert 3
		+1.0f, +0.0f, +0.0f,    // colr 3

		+0.0f, +1.0f, +0.0f,	// vert 4
		+1.0f, +1.0f, +0.0f,	// colr 4



	};


	GLushort indexData[] = {
		0, 1, 2, 0, 2, 3, 2, 1, 3,
		2, 3, 4, 0, 2, 4,
		1, 3, 4, 0, 1, 4
	};

	data.vertices = vertData;
	data.indices = indexData;

	data.vertSize = sizeof(vertData);
	data.indSize = sizeof(indexData);


	return data;
}