#pragma once
#include "BackgroundStatic.h"
#include "WorldStatus.h"

/// <summary>
/// A class to display images depending on worldstatus;
/// Use this class to display MOON and SKY 
/// </summary>
class GWorldImage :
	public GBackgroundStatic
{
public:
	/// <summary>
	/// ctor;
	/// </summary>
	/// <param name="_fileNames">Array of filenames</param>
	/// <param name="_pos">position in screen space</param>
	/// <param name="_size">size of image</param>
	GWorldImage(char** _fileNames, SVector2 _pos, SVector2 _size, CRenderer* _pRenderer);
	
	/// <summary>
	/// destructor
	/// </summary>
	~GWorldImage();

#pragma region public override functions
	// update in case of world state change;
	/// <summary>
	/// update in case of world state change;
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	inline void Update(float _deltaTime) override;

	inline void Render(CRenderer* pRenderer) override;
#pragma endregion


private:
	/// <summary>
	/// the array containing the imagePaths
	/// </summary>
	char** m_pFileNames;

	/// <summary>
	/// The state the world is in;
	/// </summary>
	EWorldState m_lastWorldState = EWorldState::WORLD_STATE_4;

	/// <summary>
	/// Pointer to instance of worldStatus;
	/// </summary>
	GWorldStatus* m_pWorldStatus = nullptr;

	/// <summary>
	/// Array holding all textures;
	/// </summary>
	CTexture* m_pTextures[7];

};

