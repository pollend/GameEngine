attribute vec3 in_position;
attribute vec2 in_texcoords;
attribute vec3 in_normals;

uniform mat4 in_transform;
uniform mat4 in_view;

uniform sampler2D in_BaseImage;

varying vec2 p_TexCoords;
varying vec3 p_normals;
varying vec3 p_camPosition;

void main(void)
{
    p_camPosition = (in_view * in_transform * vec4(in_position.xyz,1.0)).xyz;
    gl_Position = in_view * in_transform * vec4(in_position.xyz,1.0);
    p_TexCoords = in_texcoords;
    p_normals =   ( in_transform * vec4(in_normals,0.0)).xyz;
}