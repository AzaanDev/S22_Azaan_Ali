#pragma once
#include "Maniac.h"
#include "Entity.h"

class LucidApp : public Maniac::ManiacApp
{
public:
	LucidApp();
	virtual void onUpdate() override;

	bool Collision(const Entity& x, const Entity& y);


private:
	Entity m_Player{ {"Assets/Images/image (1).png", "Assets/Images/test2.png" } };
	std::vector<Entity> m_Enemy{ { {"Assets/Images/asteroid.png"}} };
	int m_HorizontalSpeed{ 1 };
	int m_EnemyYSpeed{ -5 };
};

