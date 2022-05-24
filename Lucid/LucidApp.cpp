#include "LucidApp.h"

LucidApp::LucidApp()
{
	SetKeyPressedCallBack([this](const Maniac::KeyPressedEvent& e) {
		switch (e.GetKey())
		{
		case MANIAC_KEY_LEFT:
			m_HorizontalSpeed = -5;
			m_Player.SetActiveImage(1);
			break;
		case MANIAC_KEY_RIGHT:
			m_HorizontalSpeed = 5;
			m_Player.SetActiveImage(0);
			break;
		}
		});
	SetKeyReleasedCallBack([this](const Maniac::KeyReleasedEvent& e) {
		m_HorizontalSpeed = 0;
		});

	m_Enemy[0].SetX(600);
	m_Enemy[0].SetY(600);

}

void LucidApp::onUpdate()
{
	m_Player.SetX(m_Player.GetX() + m_HorizontalSpeed);
	if (m_Enemy[0].GetY() < 0)
		m_EnemyYSpeed *= -1;
	else if (m_Enemy[0].GetY() > Maniac::Window::getWindow()->getHeight() - m_Enemy[0].GetHeight())
		m_EnemyYSpeed *= -1;

	m_Enemy[0].SetY(m_Enemy[0].GetY() + m_EnemyYSpeed);

	if (Collision(m_Player, m_Enemy[0]))
	{
		exit(0);
	}

	m_Player.Draw();
	m_Enemy[0].Draw();
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
