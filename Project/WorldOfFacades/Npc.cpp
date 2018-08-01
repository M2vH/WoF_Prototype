#pragma region project includes
#include "Npc.h"  
#pragma endregion


#pragma region constructor
	// constructor
	GNpc::GNpc(EEmotionType _type, SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName) : CMoveObject(_pos, _size, _pRenderer, _pFileName)
	{
		m_NpcState = ENPCState::WAITING;
		m_EmoType = _type;
		m_colType = ECollisionType::NPC;
		//m_isMovable = false;
	}
	
	// destructor
	GNpc::~GNpc()
	{
	}
#pragma endregion

#pragma region public override function
	// update every frame
	void GNpc::Update(float _deltaTime)
	{
		CMoveObject::Update(_deltaTime);
	}

	// render every frame
	void GNpc::Render(CRenderer * _pRenderer)
	{
		CMoveObject::Render(_pRenderer);
	}
	
#pragma endregion
