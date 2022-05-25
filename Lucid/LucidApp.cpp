#include "LucidApp.h"

LucidApp::LucidApp()
{
	SetKeyPressedCallBack([this](const Maniac::KeyPressedEvent& e) {
		switch (e.GetKey())
		{
		case MANIAC_KEY_LEFT:
			m_HorizontalSpeed = -5;
			break;
		case MANIAC_KEY_RIGHT:
			m_HorizontalSpeed = 5;
			break;
		case MANIAC_KEY_UP:
			m_VerticalSpeed = 5;
			break;
		case MANIAC_KEY_DOWN:
			m_VerticalSpeed = -5;
			break;
		case MANIAC_KEY_SPACE:
			m_Laser.push_back({ {"Assets/Images/laser.png"} });
			m_Laser.back().SetY(m_Player.GetY() + m_Player.GetHeight());
			m_Laser.back().SetX(m_Player.GetX() + 20);
			break;
		}
		});
	SetKeyReleasedCallBack([this](const Maniac::KeyReleasedEvent& e) {
		m_HorizontalSpeed = 0;
		m_VerticalSpeed = 0;
		});

	m_Player.SetX(200);
	m_Player.SetY(200);
	srand(time(0));
}

void LucidApp::onUpdate()
{
	int random = (rand() % 10) + 1;
	int random2 = (rand() % 10) + 1;
	if (random == 3 && random2 == 3)
	{
		m_Enemy.push_back({ {"Assets/Images/Circle.png"} });
		m_Enemy.back().SetX((rand() % (Maniac::Window::getWindow()->getWidth() - m_Enemy.back().GetWidth()) + m_Enemy.back().GetWidth()));
		m_Enemy.back().SetY(Maniac::Window::getWindow()->getHeight() - m_Enemy.back().GetHeight());
	}

	m_Player.SetX(m_Player.GetX() + m_HorizontalSpeed);
	m_Player.SetY(m_Player.GetY() + m_VerticalSpeed);


	for (int i = 0; i < m_Enemy.size(); i++)
	{
		m_Enemy[i].SetY(m_Enemy[i].GetY() + m_EnemyYSpeed);
		if (m_Enemy[i].GetY() < 1)
			m_Enemy[i].SetY(Maniac::Window::getWindow()->getHeight() - m_Enemy[i].GetHeight());
	}

	if (m_Player.GetX() < 1)
	{
		m_Player.SetX(Maniac::Window::getWindow()->getWidth() - m_Player.GetWidth());
	}

	if (m_Player.GetX() > Maniac::Window::getWindow()->getWidth())
	{
		m_Player.SetX(2);
	}

	if (m_Player.GetY() < 1)
	{
		m_Player.SetY(Maniac::Window::getWindow()->getHeight() - m_Player.GetHeight());
	}

	if (m_Player.GetY() > Maniac::Window::getWindow()->getHeight())
	{
		m_Player.SetY(2);
	}

	std::vector<Entity> newLasers;

	for (int i = 0; i < m_Laser.size(); i++)
	{
		m_Laser[i].SetY(m_Laser[i].GetY() + m_LaserSpeed);
		if (m_Laser[i].GetY() < Maniac::Window::getWindow()->getHeight())
		{
			newLasers.push_back(m_Laser[i]);
		}
	}

	m_Laser = newLasers;
	newLasers.clear();

	std::vector<Entity> newEnemy;

	for (int i = 0; i < m_Enemy.size(); i++)
	{
		if (Collision(m_Player, m_Enemy[i]))
		{
			exit(0);
		}
	}

	for (int i = 0; i < m_Laser.size(); i++)
	{
		for (int j = 0; j < m_Enemy.size(); j++)
		{
			if (Collision(m_Laser[i], m_Enemy[j]))
			{
				m_Laser[i].SetDelete(true);
				m_Enemy[j].SetDelete(true);
			}
		}
	}

	for (int i = 0; i < m_Laser.size(); i++)
	{
		if (!m_Laser[i].GetDelete())
			newLasers.push_back(m_Laser[i]);
	}

	m_Laser = newLasers;
	newLasers.clear();

	for (int i = 0; i < m_Enemy.size(); i++)
	{
		if (!m_Enemy[i].GetDelete())
			newEnemy.push_back(m_Enemy[i]);
	}

	m_Enemy = newEnemy;
	newEnemy.clear();

	m_Player.Draw();

	for (int i = 0; i < m_Laser.size(); i++)
		m_Laser[i].Draw();

	for (int i = 0; i < m_Enemy.size(); i++)
		m_Enemy[i].Draw();

}

bool LucidApp::Collision(const Entity& x, const Entity& y)
{
	int xLeft = x.GetX();
	int xRight = x.GetX() + x.GetWidth();
	int yLeft = y.GetX();
	int yRight = y.GetX() + y.GetWidth();

	int xBottom = x.GetY();
	int xTop = x.GetY() + x.GetHeight();
	int yBottom = y.GetY();
	int yTop = y.GetY() + y.GetHeight();


	bool CollideX{ false };
	if ((xLeft <= yLeft && yLeft <= xRight) ||
		(yLeft <= xLeft && xLeft <= yRight) )
	{
		CollideX = true;
	}

	bool CollideY{ false };
	if ((xBottom <= yBottom && yBottom <= xTop) ||
		(yBottom <= xBottom && xBottom <= yTop))
	{
		CollideY = true;
	}

	return CollideX && CollideY;
}
