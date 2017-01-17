varying vec2 p_TexCoords;
varying vec3 p_normals;

uniform mat4 in_light;
uniform mat4 in_transform;
uniform mat4 in_view;

uniform sampler2D in_BaseImage;

varying vec3 p_camPosition;


void main()
{
	vec3 llight = (in_light * vec4(0.0,0.0,0.0,1.0)).xyz;
	vec3 lhalfangle = normalize((p_camPosition + llight)/length(p_camPosition + llight));

	float lfinal = ((20.0+8.0)/(8.0*3.14)) * max(dot(p_normals,lhalfangle),0.0);
	gl_FragColor = texture2D(in_BaseImage,p_TexCoords) * lfinal;
}