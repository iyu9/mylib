#ifdef GL_ES
precision mediump float;
#endif

#extension GL_OES_standard_derivatives : enable

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

const float PI = 3.14159;

void main( void )
{
    vec2 normalResolution = gl_FragCoord.xy / resolution.xy;
	    
    //init color while edit 
    float r = 0.0;
    float g = 0.0;
    float b = 0.0;
    float a = 0.0;

    //result color
    r = abs(cos(0.5 * time) * normalResolution.x);
    g = abs(sin(0.5 * time) * normalResolution.x);
    b = abs(cos(0.5 * time) * normalResolution.x);
    a = 1.0;
	
    float grad = sin(normalResolution.y);	
    gl_FragColor = vec4(r, g, b, 1.0);
}
