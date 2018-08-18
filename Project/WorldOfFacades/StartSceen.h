#pragma once
#include "Scene.h"

class CMusic;
class GStartSceen :
	public CScene
{
public:
	GStartSceen() : CScene() {}

	virtual void Init() override;

	virtual void Clean() override;

private:
	CMusic* m_pBackgroundMusic;
};

