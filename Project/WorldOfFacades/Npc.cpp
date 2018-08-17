#pragma region Copyright
/*
	This code was written by
	Marco von Hagen & Jugurtha Lafi
	August 2018
*/
#pragma endregion

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
	//m_pWorldStatus = GWorldStatus::Get();

}

// destructor
GNpc::~GNpc()
{
	// ToDo: Clean up the dialog;
}
#pragma endregion

#pragma region public override function
// update every frame
void GNpc::Update(float _deltaTime)
{
	
	m_pDialog->SetText(GetNPCState());
	CMoveObject::Update(_deltaTime);
}

// render every frame
void GNpc::Render(CRenderer * _pRenderer)
{
	CMoveObject::Render(_pRenderer);

	// render dialog as last
	m_pDialog->Render(_pRenderer);

}

void GNpc::SetNPCState(ENPCState _state)
{
	if (_state == ENPCState::VISITED)
	{

		//	// ToDo (m2vh) Find better mechanic
		GWorldStatus::Get()->SetState((EWorldState)(GWorldStatus::Get()->GetState()<< 1));

	}
	m_NpcState = _state;
}

#pragma endregion
