uniform sampler2D in_BaseImage;
varying vec2 p_TexCoords;

uniform vec2 red_shift;
uniform vec2 green_shift;
uniform vec2 blue_shift;


void main()
{
float r = texture2D(in_BaseImage,p_TexCoords+red_shift).x;
float g = texture2D(in_BaseImage,p_TexCoords+green_shift).y;
float b = texture2D(in_BaseImage,p_TexCoords+blue_shift).z;
gl_FragColor = vec4(r,g,b,1.0);



}
