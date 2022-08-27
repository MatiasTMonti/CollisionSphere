#include <cmath>
#include <iostream>

struct Vector3
{
	float x, y, z;
};

struct Cube
{
	Vector3 pos;
	Vector3 size;
};

struct Sphere
{
	Vector3 pos;
	float radius;
};

bool CollisionCircleRec(float rectX, float rectY, float circleX, float circleY, float distance, float radius, float width, float height, float pointX, float pointY);
bool CollisionSphereCube(Vector3 p, Sphere sphere, Cube cube, float hypotenuse1, float distance);

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

	Vector3 p;

	Sphere sphere;
	Cube cube;
	float hypotenuse1;

	if (CollisionCircleRec(x, y, cx, cy, distancia, r, w, h, px, py))
	{
		std::cout << "Chocan" << std::endl;
	}

	CollisionSphereCube(p, sphere, cube, hypotenuse1, distancia);
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

bool CollisionSphereCube(Vector3 p, Sphere sphere, Cube cube, float hypotenuse1, float distance)
{
	p.x = sphere.pos.x;

	if (p.x < cube.pos.x) p.x = cube.pos.x;
	if (p.x > cube.pos.x + cube.size.x) p.x = cube.pos.x + cube.size.x;

	p.y = sphere.pos.y;

	if (p.y < cube.pos.y) p.y = cube.pos.y;
	if (p.y > cube.pos.y + cube.size.y) p.y = cube.pos.y + cube.size.y;

	p.z = sphere.pos.z;

	if (p.z < cube.pos.z) p.z = cube.pos.z;
	if (p.z > cube.pos.z + cube.size.z) p.z = cube.pos.z + cube.size.z;

	hypotenuse1 = sqrt((sphere.pos.x - p.x) * (sphere.pos.x - p.x) + (sphere.pos.y - p.y) * (sphere.pos.y - p.y));

	distance = sqrt(hypotenuse1 * hypotenuse1 + (sphere.pos.z - p.z) * (sphere.pos.z - p.z));

	if (distance < sphere.radius) {
		std::cout << "Colisiona" << std::endl;
	}
}