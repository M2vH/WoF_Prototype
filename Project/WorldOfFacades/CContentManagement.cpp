#pragma region project include
#include "ContentManagement.h"
#include "Object.h"
#pragma endregion

#pragma region constructor
// destructor
CContentManagement::~CContentManagement()
{
	// as long as there is a object in list delete first element
	while (m_pSceneObjects.size() > 0)
		m_pSceneObjects.pop_front();

	// as long as there is a object in list delete first element
	while (m_pPersistantObjects.size() > 0)
		m_pPersistantObjects.pop_front();

	// as long as there is a object in list delete first element
	while (m_pUIObjects.size() > 0)
		m_pUIObjects.pop_front();
}
#pragma endregion

#pragma region public function
// update every frame
void CContentManagement::Update(float _deltaTime)
{
	// update every scene object
	for each (CObject* pObj in m_pSceneObjects)
		pObj->Update(_deltaTime);

	// update every persistant object
	for (CObject* pObj : m_pPersistantObjects)
		pObj->Update(_deltaTime);

	// update every ui object
	for (CObject* pObj : m_pUIObjects)
		pObj->Update(_deltaTime);

	// remove object in remove list
	while (m_pRemoveObjects.size() > 0)
	{
		// get first object in remove list
		CObject* pObj = m_pRemoveObjects.front();

		// remove pointer from scene list
		m_pSceneObjects.remove(pObj);

		// remove pointer from persistant list
		m_pPersistantObjects.remove(pObj);

		// remove pointer from ui list
		m_pUIObjects.remove(pObj);

		// delete first object in list
		m_pRemoveObjects.pop_front();
	}
}

// render every frame
void CContentManagement::Render(CRenderer * _pRenderer)
{
	// render every scene object
	for each (CObject* pObj in m_pSceneObjects)
		pObj->Render(_pRenderer);

	// render every persistant object
	for (CObject* pObj : m_pPersistantObjects)
		pObj->Render(_pRenderer);

	// render every ui object
	for (CObject* pObj : m_pUIObjects)
		pObj->Render(_pRenderer);
}

// remove object
void CContentManagement::RemoveObject(CObject * _pObj)
{
	// add object to remove list
	m_pRemoveObjects.push_front(_pObj);
}

void CContentManagement::SortList(list<CObject*>& _pList)
{

}

#pragma endregion

#pragma region private function
// add object to list
void CContentManagement::AddObject(CObject * _pObj, list<CObject*>& _pList)
{
	// add object to list
	_pList.push_front(_pObj);

	// sort list
	SortList(_pList);
}
#pragma endregion