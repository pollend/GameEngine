attribute vec3 in_Verts;
attribute vec2 in_TexCoords;
attribute vec3 in_Normals;

uniform mat4 in_Transform;
uniform mat4 in_View;

uniform sampler2D in_BaseImage;

varying vec2 p_TexCoords;
varying vec3 p_normals;
varying vec3 p_camPosition;

uniform float in_ballon_factor;

void main(void)
{
    p_camPosition = (in_View * in_Transform * vec4(in_Verts.xyz,1.0)).xyz;
    p_TexCoords = in_TexCoords;
    p_normals =   ( in_Transform * vec4(in_Normals,0.0)).xyz;
    gl_Position = in_View * ((in_Transform * vec4(in_Verts.xyz,1.0)) + (vec4(p_normals*in_ballon_factor,0)));
}