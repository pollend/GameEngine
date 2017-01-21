attribute vec3 in_Verts;
attribute vec2 in_TexCoords;

varying vec2 p_TexCoords;
varying vec3 p_camPosition;

void main(void)
{
p_camPosition = in_Verts;
p_TexCoords = in_TexCoords;
}