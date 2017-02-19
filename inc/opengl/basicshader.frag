#version 320 es
in highp vec3 fColor;
out highp vec4 outColor;


void main()
{
  outColor = vec4(fColor, 1.0);
}