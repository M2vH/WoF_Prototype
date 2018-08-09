#pragma once

#pragma region system include
#include <map>
#include <string>
#pragma endregion

#pragma region project include
#include "Texture.h"
#pragma endregion


#pragma region forward decleration
//class CTexture;
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

/// <summary>
/// class to manage textures
/// </summary>
class CTextureManagement
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CTextureManagement() {}

	/// <summary>
	/// destructor
	/// </summary>
	~CTextureManagement()
	{
		// while textures in map
		while (m_pTextures.size() > 0)
		{
			// delete first texture
			delete m_pTextures.begin()->second;

			// erease fist pair
			m_pTextures.erase(m_pTextures.begin());
		}
	}
#pragma endregion

#pragma region public inline function
	inline CTexture* GetTexture(string _name)
	{
		// texture for return
		CTexture* pTexture = nullptr;

		// if key string exists
		if (m_pTextures.find(_name) != m_pTextures.end())
			pTexture = m_pTextures.find(_name)->second;

		// return texture or nullptr
		return pTexture;
	}

	/// <summary>
	/// add texture to map
	/// </summary>
	/// <param name="_name">name of texture</param>
	/// <param name="_pTexture">texture</param>
	inline void AddTexture(string _name, CTexture* _pTexture)
	{
		if (m_pTextures.find(_name) == m_pTextures.end())
			m_pTextures.insert(pair<string, CTexture*>(_name, _pTexture));
	}
#pragma endregion

private:
#pragma region private variable
	/// <summary>
	/// texture map
	/// </summary>
	map<string, CTexture*> m_pTextures;
#pragma endregion
};