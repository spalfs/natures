#version 320 es
layout(points) in;
layout(line_strip, max_vertices = 64) out;

in highp vec3 vColor[];
in highp float vSides[];
out highp vec3 fColor;

const float PI = 3.1415926;

void main()
{
  fColor = vColor[0];

  for (int i = 0; i <= 4; i++) {	        // Angle between each side in radians
	
	vec4 offset = vec4(vSides[0] *.8,-vSides[0] *1.1, 0.0, 0.0);
	if(i==1)
		offset = vec4(vSides[0] *.8,vSides[0] *1.1, 0.0, 0.0);
	if(i==2)
		offset = vec4(-vSides[0] *.8,vSides[0] *1.1, 0.0, 0.0);
	if(i==3)
		offset = vec4(-vSides[0] *.8,-vSides[0] *1.1, 0.0, 0.0);
	if(i==4)
		offset = vec4(vSides[0] *.8,-vSides[0] *1.1, 0.0, 0.0);
	
	
    gl_Position = gl_in[0].gl_Position - offset;

    EmitVertex();
  }
  EndPrimitive();
}
