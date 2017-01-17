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


GLint Texture::GetResourceID()
{
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