uniform sampler2D in_BaseImage;
varying vec2 p_TexCoords;

void main()
{

vec2 z;
z.x = 4.0 * (p_TexCoords.x - 0.5);
z.y = 4.0 * (p_TexCoords.y - 0.5);

int i;
for(i=0; i<100; i++) {
float x = (z.x * z.x - z.y * z.y) + -0.550;
float y = (z.y * z.x + z.x * z.y) + -0.550;

if((x * x + y * y) > 4.0) break;
    z.x = x;
    z.y = y;
}

float lrange = float(i) / 50.0;
gl_FragColor = vec4(lrange,0.0,0.0,1.0);

}
