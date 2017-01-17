attribute vec3 in_position;

uniform mat4 in_transform;
uniform mat4 in_view;

void main(void)
{
    gl_Position = in_view * in_transform * vec4(in_position.xyz,1.0);
}