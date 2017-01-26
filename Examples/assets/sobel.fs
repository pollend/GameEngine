#version 120

uniform sampler2D in_BaseImage;
varying vec2 p_TexCoords;


void main()
{
    vec4 top         = texture2D(in_BaseImage, vec2(p_TexCoords.x, p_TexCoords.y + 1.0 / 200.0));
    vec4 bottom      = texture2D(in_BaseImage, vec2(p_TexCoords.x, p_TexCoords.y - 1.0 / 200.0));
    vec4 left        = texture2D(in_BaseImage, vec2(p_TexCoords.x - 1.0 / 300.0, p_TexCoords.y));
    vec4 right       = texture2D(in_BaseImage, vec2(p_TexCoords.x + 1.0 / 300.0, p_TexCoords.y));
    vec4 topLeft     = texture2D(in_BaseImage, vec2(p_TexCoords.x - 1.0 / 300.0, p_TexCoords.y + 1.0 / 200.0));
    vec4 topRight    = texture2D(in_BaseImage, vec2(p_TexCoords.x + 1.0 / 300.0, p_TexCoords.y + 1.0 / 200.0));
    vec4 bottomLeft  = texture2D(in_BaseImage, vec2(p_TexCoords.x - 1.0 / 300.0, p_TexCoords.y - 1.0 / 200.0));
    vec4 bottomRight = texture2D(in_BaseImage, vec2(p_TexCoords.x + 1.0 / 300.0, p_TexCoords.y - 1.0 / 200.0));
    vec4 sx = -topLeft - 2 * left - bottomLeft + topRight   + 2 * right  + bottomRight;
    vec4 sy = -topLeft - 2 * top  - topRight   + bottomLeft + 2 * bottom + bottomRight;
    gl_FragColor = sqrt(sx * sx + sy * sy);
}
