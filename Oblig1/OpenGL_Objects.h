#pragma once
#include <vector>

class Vertex
{
public:
	Vertex(float x, float y, float z, float r, float b, float g);
	float x, y, z, r, b, g;
};

class Triangle
{
public:
	Triangle();
	std::vector<Vertex> VerticesVector;
};

class Lines
{
public:
	Lines();
	std::vector<Vertex> VerticesVector;
};

class OpenGL_Objects
{
};
