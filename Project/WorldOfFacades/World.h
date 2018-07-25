#pragma once

#pragma region project include
#include "TexturedObject.h"  
#pragma endregion

/// <summary>
/// world class
/// </summary>
class GWorld : public CTexturedObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	/// <param name="_pFileName">file path name (relative)</param>
	GWorld(CRenderer* _pRenderer, const char* _pFileName) : CTexturedObject(SVector2(), SVector2(), _pRenderer, _pFileName) {}
	
	/// <summary>
	/// destructor
	/// </summary>
	~GWorld() {}
#pragma endregion

#pragma region public function
	/// <summary>
	/// initialize world
	/// </summary>
	void Init();
#pragma endregion
};