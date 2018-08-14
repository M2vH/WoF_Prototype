#include "WorldStatus.h"

inline void GWorldStatus::RemoveObject(CObject * _pObj)
{
	m_pRemoveObjects.push_front(_pObj);
}

inline void GWorldStatus::CleanMainSceneObjects()
{
	for (CObject* pObj : m_pMainSceneObjects)
		RemoveObject(pObj);

}

inline void GWorldStatus::CleanTheMainScene()
{
	GWorldStatus::CleanMainSceneObjects();
}

/// <summary>
/// take every object from removeList;
/// find in every other list and remove;
/// </summary>
void GWorldStatus::Refresh()
{
	while (m_pRemoveObjects.size() > 0)
	{
		// get first object in remove list
		CObject* pObj = m_pRemoveObjects.front();

		// remove pointer from scene list
		m_pMainSceneObjects.remove(pObj);

		//// remove pointer from player list
		//m_pPlayerObjects.remove(pObj);

		//// remove pointer from persistant list
		//m_pPersistantObjects.remove(pObj);

		//// remove pointer from ui list
		//m_pUIObjects.remove(pObj);

		// delete first object in list
		m_pRemoveObjects.pop_front();

		//delete pObj;
	}
}


/// <summary>
/// destructor
/// </summary>
GWorldStatus::~GWorldStatus()
{
	// ToDo (m2vh) clean this class
	// by deleting the lists;
	// make sure to clear the lists first;
}

/// <summary>
/// Add an object to a list
/// </summary>
/// <param name="_pObj">the object to copy</param>
/// <param name="_pList">the list to insert</param>
void GWorldStatus::AddObject(CObject * _pObj, list<CObject*>& _pList)
{
	// add object to list
	// objects come from CM;
	// and will return to CM;
	// we push_back() to keep sorting;
	_pList.push_front(_pObj);
	

}

/// <summary>
/// the pointer to the instance of this class
/// </summary>
GWorldStatus* GWorldStatus::m_instance = nullptr;

