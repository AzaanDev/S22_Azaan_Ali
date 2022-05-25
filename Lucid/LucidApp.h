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
	Entity m_Player{ {"Assets/Images/ship.png"} };
	std::vector<Entity> m_Enemy;
	std::vector<Entity> m_Laser;
	int m_HorizontalSpeed{ 0 };
	int m_VerticalSpeed{ 0 };
	int m_LaserSpeed{ 10 };
	int m_EnemyYSpeed{ -3 };
};

