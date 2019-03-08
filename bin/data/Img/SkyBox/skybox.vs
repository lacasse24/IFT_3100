#version 330 core
layout (location = 0) in vec3 aPos;

out vec3 TexCoords;

uniform mat4 gprojection;
uniform mat4 gview;

void main()
{
    TexCoords = aPos;
    gl_Position = gprojection * gview * vec4(aPos, 1.0);
}