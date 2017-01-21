uniform sampler2D in_BaseImage;
varying vec2 p_TexCoords;

void main()
{
float r = texture2D(in_BaseImage,p_TexCoords+vec2(.01,0)).x;
float g = texture2D(in_BaseImage,p_TexCoords+vec2(-.01,0)).y;
float b = texture2D(in_BaseImage,p_TexCoords+vec2(0,-.01)).z;
gl_FragColor = vec4(r,g,b,1.0);// texture2D(in_BaseImage,p_TexCoords);

}
