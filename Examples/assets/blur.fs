#version 120

uniform sampler2D in_BaseImage;
varying vec2 p_TexCoords;

uniform float in_xblur;
uniform float in_yblur;

const float blurSizeH = 1.0 / 300.0;
const float blurSizeV = 1.0 / 200.0;

void main()
{
    vec4 sum = vec4(0.0);
    for (int x = -4; x <= 4; x++)
        for (int y = -4; y <= 4; y++)
            sum += texture2D(
                in_BaseImage,
                vec2(p_TexCoords.x + x * in_xblur, p_TexCoords.y + y * in_yblur)
            ) / 81.0;
    gl_FragColor = sum;
}