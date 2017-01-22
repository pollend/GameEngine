attribute vec3 in_Verts;
attribute vec2 in_Texcoords;

varying vec2 p_TexCoords;

void main(void)
{
 gl_Position = vec4(in_Verts.x, in_Verts.y, 0.0f, 1.0f);
 p_TexCoords = in_Texcoords;
}