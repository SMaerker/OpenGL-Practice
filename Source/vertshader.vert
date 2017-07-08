#version 430

in layout(location = 0) vec3 position;
in layout(location = 1) vec3 vertColor;


uniform mat4 fullMat;

out vec3 theColor;

void main(){

gl_Position = fullMat * vec4(position, 1.0);
theColor = vertColor;
}