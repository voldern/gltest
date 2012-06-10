#version 150

//in vec3 Color;
uniform vec3 boxColor;

out vec4 outColor;

void main()
{
    outColor = vec4(boxColor, 1.0);
}

