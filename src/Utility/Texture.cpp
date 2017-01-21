#include "Utility/Texture.h"

#include <boost/log/trivial.hpp>
#include <lodepng.h>
#include <fstream>


Texture::Texture(const char * path)
{

	BOOST_LOG_TRIVIAL(trace) << "loading image file:" <<  path;

	_textureName = path;

	std::ifstream file(path, std::ios::binary | std::ios::ate);
	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg);

	char* buffer = new char[size]();
	if (!file.read(buffer, size))
	{
		BOOST_LOG_TRIVIAL(error) << "Failed to open:" << path;
		file.close();
		delete(buffer);
		return;
	}


	unsigned int width, height;
	unsigned char* loutput;
	lodepng_decode32(&loutput, &width, &height,(unsigned char*) buffer,size);

	glGenTextures(1, (&_textureID));

	glBindTexture(GL_TEXTURE_2D,_textureID);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S , GL_REPEAT );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,loutput);
}

Texture::Texture(int width, int height,TextureType textureType)
{
	glGenTextures(1, &_textureID);
	glBindTexture(GL_TEXTURE_2D, _textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 600, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);


//	glGenTextures(1, (&_textureID));
//	glBindTexture(GL_TEXTURE_2D,_textureID);
//	switch (textureType)
//	{
//		case TEXTURE_R:
//			glTexImage2D(GL_TEXTURE_2D, 0, GL_R16F, width, height, 0, GL_R, GL_FLOAT, NULL);
//			break;
//
//		case TEXTURE_RG:
//			glTexImage2D(GL_TEXTURE_2D, 0, GL_RG16F, width, height, 0, GL_RG, GL_FLOAT, NULL);
//			break;
//
//		case TEXTURE_RGB:
//			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, width, height, 0, GL_RGB, GL_FLOAT, NULL);
//			break;
//
//		case TEXTURE_RGBA:
//			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
//			break;
//	}
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 800, 600, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
//	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
//	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);


}
std::string Texture::GetFilename()
{
	return _textureName;
}

float Texture::GetWidthScale()
{
	return (((float)_width) /((float)(_width +_widthBuffer)));
}

float Texture::GetHeightScale()
{
	return (((float)_height) /((float)(_height +_heightBuffer)));
}


GLint Texture::GetResourceID() {
	return _textureID;
}


Texture::~Texture(void)
{
	glDeleteTextures(1,&_textureID);
}


float Texture::WidthToHeightRatio()
{
	return ((float)_width)/((float)_height);
}

float Texture::HeightToWidthRatio()
{
	return ((float)_height)/((float)_width);
}