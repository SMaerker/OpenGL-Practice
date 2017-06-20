#include "stdafx.h"
#include <string>
 const char* const vertShader =
"#version 430\r\n"
"in layout(location = 0) vec2 position;"
"void main()"
"{"
"gl_position = vec4(position, 0.0, 1.0);"
"}";


 const char* const fragShader =
	 "#version 430\r\n"
	 "out vec4 color;"
	 "void main()"
	 "{"
	 "color = vec4(1.0, 0.0, 0.0, 1.0);"
	 "}";