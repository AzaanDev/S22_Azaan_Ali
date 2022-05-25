#pragma once
#include "Maniac.h"
#include <vector>

class Entity
{
public:
	Entity(const std::vector<std::string>& fileName);
	int GetX() const;
	int GetY() const;
	int GetZ() const;
	bool GetSolid() const;
	int GetActiveImage() const;
	int GetWidth() const;
	int GetHeight() const;
	bool GetDelete() const;

	void SetX(int x);
	void SetY(int y);
	void SetZ(int z);
	void SetSolid(bool s);
	void SetActiveImage(int i);
	void SetDelete(bool d);

	void Draw();

private:
	int xPos = 0, yPos = 0, zPos = 0;
	bool Solid{ true };
	bool Delete{ false };
	int m_ActiveImage{ 0 };
	std::vector<Maniac::Sprite> m_Images;
};

