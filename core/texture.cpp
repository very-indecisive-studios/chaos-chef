#include "texture.h"

core::Texture::Texture(LPDIRECT3DTEXTURE9 &tD3D, int w, int h)
{
	textureD3D = tD3D;
	width = w;
	height = h;
}

core::Texture::~Texture()
{
	textureD3D->Release();
}

LPDIRECT3DTEXTURE9 & core::Texture::GetTextureD3D()
{
	return textureD3D;
}

int core::Texture::GetWidth()
{
	return width;
}

int core::Texture::GetHeight()
{
	return height;
}
