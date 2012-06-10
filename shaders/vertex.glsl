#version 150

in vec3 position;
//in vec3 color;
uniform mat4 MVP;

//out vec3 Color;

void main()
{
    //Color = color;
    vec4 v = vec4( position, 1.0 );
    gl_Position = MVP * v;
}
