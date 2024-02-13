#pragma once
#include <vector>

class Vertex
{
public:
	Vertex();
	Vertex(float x, float y, float z, float r, float b, float g, float u, float v);
	float x, y, z, r, b, g, u, v;
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
