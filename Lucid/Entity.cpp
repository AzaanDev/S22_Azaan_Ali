#include "Entity.h"

Entity::Entity(const std::vector<std::string>& fileName) : m_Images(fileName.begin(), fileName.end())
{

}

int Entity::GetX() const
{
	return xPos;
}

int Entity::GetY() const
{
	return yPos;
}

int Entity::GetZ() const
{
	return zPos;
}

bool Entity::GetSolid() const
{
	return Solid;
}

int Entity::GetActiveImage() const
{
	return m_ActiveImage;
}

int Entity::GetWidth() const
{
	return m_Images[m_ActiveImage].GetWidth();
}

int Entity::GetHeight() const
{
	return m_Images[m_ActiveImage].GetHeight();
}

bool Entity::GetDelete() const
{
	return Delete;
}

void Entity::SetX(int x)
{
	xPos = x;
}
void Entity::SetY(int y)
{
	yPos = y;
}
void Entity::SetZ(int z)
{
	zPos = z;
}

void Entity::SetSolid(bool s)
{
	Solid = s;
}

void Entity::SetActiveImage(int i) 
{
	m_ActiveImage = i;
}

void Entity::SetDelete(bool d)
{
	Delete = d;
}

void Entity::Draw()
{
	Maniac::Render::Draw(m_Images[m_ActiveImage], xPos, yPos, zPos);
}
