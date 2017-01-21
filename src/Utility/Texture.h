#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "string"
#include <GL/glut.h>
#include <stdlib.h>

enum TextureType{
	TEXTURE_R,
	TEXTURE_RG,
	TEXTURE_RGB,
	TEXTURE_RGBA
};


class Texture
{
private:

	GLuint _textureID;
	int _width;
	int _height;
	int _widthBuffer;
	int _heightBuffer;
	GLint _resourceID;

	std::string _textureName;

public:
	Texture(const char * path);
	Texture(int width, int height,TextureType textureType);
	~Texture(void);

	/** 
	*returns the file name of the asset 
	**/
	std::string GetFilename();

	GLint GetResourceID() const;

	/** 
	*returns the texcoords value minus the buffer area outside of the texture area
	**/
	float GetWidthScale();

	/** 
	*returns the texcoords height 
	**/
	float GetHeightScale();

	/** 
	*returns width to height ratio of the texture 
	**/
	float WidthToHeightRatio();

	/** 
	*returns height to width ratio of the texture 
	**/
	float HeightToWidthRatio();
	
};

#endif

