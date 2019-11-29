#version 120
uniform float time;
void main()
{
    // transform the vertex position
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
	gl_Position.x += tan(0.5 + cos(time) * gl_Position.x)*cos(tan(sin(time)));
	gl_Position.y += tan(0.5 + sin(time) * gl_Position.y)*cos(tan(sin(time)));

	
    // transform the texture coordinates
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;
    // forward the vertex color
    gl_FrontColor = gl_Color;
}