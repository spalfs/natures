#version 320 es
in highp vec2 pos;
in highp vec3 color;
in highp float sides;
uniform mat4 MVP;

out highp vec3 fColor;
out highp float vSides;

void main()
{
    gl_Position = MVP * vec4(pos, 0.0, 1.0);
    fColor = color;
    vSides = sides;
}
