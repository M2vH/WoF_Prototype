#pragma once
#pragma region system include
#include <list>
#include <map>
#pragma endregion


#pragma region project include
#include "MoveObject.h"
#include "Time.h"
#include "Texture.h"
#include "EnumPlayerState.h"

#pragma endregion

#pragma region using
using namespace std;
#pragma endregion


/// <summary>
/// Animated Objects; Contains n blocks in m slices; Speed in FPS
/// </summary>
class GAnimObject :
	public CMoveObject
{
public:
#pragma region ctor
	// constructor
	GAnimObject(
		float _speed,
		SVector2 _blockSize,
		SVector2 _pos,
		SVector2 _size,
		CRenderer* _pRenderer,
		char** _pFileNames);
	//{
	//	m_animSpeed = _speed;
	//	m_blockSize = _blockSize;
	//	m_pTextureList = new list<CTexture*>;
	//}
	
		
		//CMoveObject(
		//	_pos,
		//	_size ,
		//	_pRenderer ,
		//	_pFileName );

	// GAnimObject();
	~GAnimObject();

#pragma endregion
#pragma region public override functions
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	void Update(float _deltaTime) override;

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer"></param>
	void Render(CRenderer* _pRenderer) override;
#pragma endregion

#pragma region public inline functions
	inline void SetSpeed(int _fps) { m_animSpeed = _fps; }

	inline void NextTexture();

	// inline void SetTexture(CTexture* _texture);
#pragma endregion
private:
#pragma region private primitive vars
	
	/// <summary>
	/// speed of animation in SECONDS pre Frame; SAMPLERATE
	/// </summary>
	float m_animSpeed;

	/// <summary>
	/// number of blocks per slice
	/// </summary>
	int m_blockCount;

	/// <summary>
	/// number of slices
	/// </summary>
	int m_sliceCount;
	/// <summary>
	/// width and height of a single block
	/// </summary>
	SVector2 m_blockSize;
	/// 
	
	EPlayerState m_PlayerState;


	list<CTexture*>* m_pTextureList;

	CTexture* m_pTextureArray[3];

	char** m_pFileNames; 

	int m_pIdleTextures[3];
	int m_pMoveTextures[3];

	int m_pstartIdle = 0;
	int m_pstartMove = 0;

#pragma endregion

};

