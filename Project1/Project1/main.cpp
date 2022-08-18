#include <cmath>
#include <iostream>

bool CollisionCircleRec(float rectX, float rectY, float circleX, float circleY, float distance, float radius, float width, float height, float pointX, float pointY);

int main()
{
	float x = 10;
	float y = 10;
	float cx = 10;
	float cy = 10;
	float distancia = 0;
	float r = 3;
	float w = 10;
	float h = 10;
	float px = 0;
	float py = 0;

	if (CollisionCircleRec(x, y, cx, cy, distancia, r, w, h, px, py))
	{
		std::cout << "Chocan" << std::endl;
	}
}

bool CollisionCircleRec(float rectX, float rectY, float circleX, float circleY, float distance, float radius, float width, float height, float pointX, float pointY)
{
	pointX = circleX;
	if (pointX < rectX)
	{
		pointX = rectX;
	}
	if (pointX > rectX + width)
	{
		pointX = rectX + width;
	}

	pointY = circleY;
	if (pointY < rectY)
	{
		pointY = rectY;
	}
	if (pointY > rectY + height)
	{
		pointY = rectY + height;
	}

	distance = sqrt((circleX - pointX) * (circleX - pointX) + (circleY - pointY) * (circleY - pointY));

	if (distance < radius)
	{
		return true;
	}
	return false;
}

bool CollsionSpheres(float distance, float distance2, float circleX, float circleY, float circleZ, float circle2X, float circle2Y, float circle2Z, float radius1, float radius2)
{
	distance = sqrt((circleX - circle2X) * (circleX - circle2X) + (circleY - circle2Y) * (circleY - circle2Y));

	distance2 = sqrt((distance * distance) + (circleZ - circle2Z) * (circleZ - circle2Z));

	if (distance2 < radius1 + radius2)
	{
		return true;
	}
}