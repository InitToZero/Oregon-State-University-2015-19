#version 330 compatibility

uniform float	uTimeF;		// "Time", from Animate( )
const float PI = 	3.14159265;

in vec2 vST;
in vec3 vColor;

void
main( )
{

	vec3 myColor = vColor ;
	float val = (sin(uTimeF * PI));
	
	//These are the scaling rectangles
	if( vST.s >= vColor.x && vST.t >= vColor.y && vST.s<val && vST.t<val) {
	myColor = vec3(sin((uTimeF-.5)*2), cos(uTimeF), sin(uTimeF));
	}

	gl_FragColor = vec4( myColor,  1. );
}