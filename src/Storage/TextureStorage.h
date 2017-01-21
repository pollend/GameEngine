#ifndef _TEXTURE_STORAGE_H_
#define _TEXTURE_STORAGE_H_

#include "Utility/Texture.h"
#include <map>
#include <string>
class Texture;
class TextureStorage
{
private:
	std::map<std::string,Texture*> _textures;
public:
	TextureStorage();
	~TextureStorage(void);

	/** 
	*append texture to the texturestorage
	**/
	Texture* AppendTexture(Texture* texture);

	/** 
	*removes the texture from the set 
	**/
	void DeleteTexture(std::string id);

	/**
	*tells if the texture is used
	**/
	bool IsTextureUsed(std::string id);

	/**
	*retrieves the texture from storage 
	**/
	Texture* GetTexture(std::string id);
};

#endif