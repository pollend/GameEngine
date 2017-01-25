uniform sampler2D in_BaseImage;
varying vec2 p_TexCoords;

void main()
{
    vec4 color = texture2D(in_BaseImage,p_TexCoords);
    float average = (color.r + color.g + color.b) / 3.0;
    gl_FragColor = vec4(average, average, average, 1.0);
}
