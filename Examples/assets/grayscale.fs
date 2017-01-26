uniform sampler2D in_BaseImage;
varying vec2 p_TexCoords;

uniform float in_red_factor;
uniform float in_green_factor;
uniform float in_blue_factor;
uniform int color;

void main()
{
    if(color == 0)
    {
        vec4 color = texture2D(in_BaseImage,p_TexCoords);
        float average = color.r*in_red_factor + color.g*in_green_factor + color.b * in_blue_factor;
        gl_FragColor = vec4(average, average, average, 1.0);
    }
    else
    {
        gl_FragColor = texture2D(in_BaseImage,p_TexCoords);
    }
}
