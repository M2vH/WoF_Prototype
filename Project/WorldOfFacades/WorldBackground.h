#pragma once
#include "TexturedObject.h"
class GWorldBackground :
	public CTexturedObject
{
public:
#pragma region ctor
	
	/// <summary>
	/// The ctor; use this class together with player auto-positioning; 
	/// </summary>
	/// <param name="_pos">position in worldspace</param>
	/// <param name="_size">size in pixel</param>
	/// <param name="_pRenderer">the renderer for texture creation</param>
	/// <param name="_pFileName">the path to the image</param>
	GWorldBackground::GWorldBackground(SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName);

	~GWorldBackground();

#pragma endregion
#pragma region inline override functions
	/// <summary>
	/// The Update for every frame
	/// </summary>
	/// <param name="_deltaTime">the deltaTime</param>
	void Update(float _deltaTime) override;

	/// <summary>
	/// The render for every frame
	/// </summary>
	/// <param name="_pRenderer">the renderer of the engine</param>
	void Render(CRenderer* _pRenderer) override;

#pragma endregion

#pragma region private variables
	/// <summary>
	/// Fills the left half of the screen with the right side of the background;
	/// </summary>
	CTexturedObject* m_pLeftFill;
	
	/// <summary>
	/// Fills the right half of the screen with the left side of the background image;
	/// </summary>
	CTexturedObject* m_pRightFill;

#pragma endregion

};

