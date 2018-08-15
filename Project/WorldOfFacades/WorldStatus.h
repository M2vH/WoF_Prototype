#pragma once
#include <iostream>	// TODO: DELETE
#include <string>	// TODO: DELETE
#include "Macro.h"	// ToDo: Delete

#pragma region system include
#include <list>
#pragma endregion


#pragma region project includes
#include "EnumWorldState.h"
#pragma endregion

#pragma region forward declaration
class CObject;
#pragma endregion

#pragma region namespace
using namespace std;
#pragma endregion



/// <summary>
/// singleton class; use Get() to get an instance;
/// </summary>
class GWorldStatus
{
public:
#pragma region public function

	/// <summary>
	/// get an instance of WorldStatus;
	/// </summary>
	/// <returns></returns>
	static GWorldStatus* Get() {
		return (!m_instance) ? m_instance = new GWorldStatus : m_instance;
	}

	/// <summary>
	/// Get the state the world is in;
	/// </summary>
	EWorldState GetState() { return m_worldState; };

	/// <summary>
	/// Set the status of the world; 
	/// Use bitshift to increase state;
	/// </summary>
	/// <param name="_newState">bitshift the GetState</param>
	void SetState(EWorldState _newState) {
		if (
			_newState < EWorldState::WORLD_STATE_1 ||
			_newState > EWorldState::WORLD_STATE_7)
		{
			return;
		}
		else
		{
			m_worldState = _newState;
		}

	};
#pragma endregion

#pragma region public general functions

	/// <summary>
	/// Internaly used to put objects in removeList
	/// </summary>
	/// <param name="_pObj"></param>
	virtual void RemoveObject(CObject* _pObj);

	/// <summary>
	/// Delete objects from the lists and
	/// Clear the remove object list;
	/// </summary>
	virtual void Refresh();
#pragma endregion

#pragma region public mainscene object list
	/// <summary>
	/// Add objects from MainSceen to WorldStatus list;
	/// </summary>
	/// <param name="_pObj">the object to copy</param>
	virtual void AddMainSceneObject(CObject* _pObj) { AddObject(_pObj, m_pMainSceneObjects); }

	/// <summary>
	/// Get the SceneObjects for the MainScene
	/// </summary>
	/// <returns></returns>
	virtual list<CObject*> GetMainSceneObjects() { return m_pMainSceneObjects; }

	virtual void CleanMainSceneObjects();

	/// <summary>
	/// clean all mainscene lists
	/// </summary>
	virtual void CleanTheMainScene();

#pragma endregion
#pragma region public mainscene persistant list
	/// <summary>
	/// Add object to WorldStatus persistant list
	/// </summary>
	/// <param name="_pObj"></param>
	virtual void AddMainPersistObject(CObject* _pObj) { AddObject(_pObj, m_pMainPersistObjects); }

	/// <summary>
	/// get the MainScene persistant list
	/// </summary>
	/// <returns></returns>
	virtual list<CObject*> GetMainPersistObjects() { return m_pMainPersistObjects; }

	/// <summary>
	/// Put all MainScene persistant objects into removeList;
	/// </summary>
	virtual void CleanMainPersistObjects();
#pragma endregion

#pragma region public house scene object list
	virtual void AddHouseSceneObject(CObject* _pObj) { AddObject(_pObj, m_pHouseSceneObjects); }

	virtual list<CObject*> GetHouseSceneObjects() { return m_pHouseSceneObjects; }

	virtual void CleanHouseSceneObjects();

#pragma endregion
#pragma region public house persistant list

	virtual void AddHousePersistObject(CObject* _pObj) { AddObject(_pObj, m_pHousePersistObjects); }

	virtual list<CObject*> GetHousePersistObjects() { return m_pHousePersistObjects; }

	virtual void CleanHousePersistObjects();

#pragma endregion

	virtual void CleanTheHouseSceen();

private:
#pragma region private ctor
	/// <summary>
	/// private ctor; we are singleton;
	/// </summary>
	GWorldStatus() {
		m_worldState = EWorldState::WORLD_STATE_4;
		LOG_MESSAGE("World status: ", "Object created.");
	};
#pragma endregion
#pragma region destructor
	~GWorldStatus();

#pragma endregion
#pragma region private variables
	/// <summary>
	/// The instance of this singleton
	/// </summary>
	static GWorldStatus* m_instance;

	/// <summary>
	/// The state the world is in.
	/// </summary>
	EWorldState m_worldState = EWorldState::WORLD_STATE_1;
#pragma endregion
#pragma region private lists for mainscene

	list<CObject*> m_pRemoveObjects;

	/// <summary>
	/// The SceneObjects of the MainScene
	/// </summary>
	list<CObject*> m_pMainSceneObjects;

	// add persistant list
	/// <summary>
	/// the PersistantObjects of the MainScene
	/// </summary>
	list<CObject*> m_pMainPersistObjects;
#pragma endregion
#pragma region private list for housescene
	// scene object list

	list<CObject*> m_pHouseSceneObjects;

	list<CObject*> m_pHousePersistObjects;

	// persistant object list
#pragma endregion

#pragma region private function
	void AddObject(CObject* _pObj, list<CObject*> &_pList);
#pragma endregion





};

