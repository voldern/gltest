#version 150

in vec2 position;
uniform mat4 MVP;

void main()
{
    vec4 v = vec4( position, 0.0, 1.0 );
    gl_Position = MVP * v;
}

