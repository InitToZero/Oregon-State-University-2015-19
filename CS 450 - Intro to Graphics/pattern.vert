#version 330 compatibility

uniform float	uTimeV;		// "Time", from Animate( )
const float PI = 	3.14159265;

out vec2 vST;
out vec3 vColor;

void
main( )
{ 

	//Get ST and vertex coords
	vST = gl_MultiTexCoord0.st;
	vec3 vert = gl_Vertex.xyz;

	//Set the color and position
	vColor = vec3(cos(vert.x* (uTimeV+.2) * 2 * PI), cos(vert.y* (uTimeV+.2) * 2 * PI), pow((vert.z*uTimeV),2));
	gl_Position = gl_ModelViewProjectionMatrix * vec4(vert.xyz, 1.0);
	
}