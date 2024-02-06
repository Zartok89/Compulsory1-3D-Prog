#include "OpenGL_Objects.h"

Vertex::Vertex(float x, float y, float z, float r, float b, float g)
				: x(x), y(y), z(z), r(r), b(b), g(g) {}

Triangle::Triangle()
{
	Vertex Vert1 = {0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f};
	Vertex Vert2 = {-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f};
	Vertex Vert3 = {0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f};
	VerticesVector.push_back(Vert1);
	VerticesVector.push_back(Vert2);
	VerticesVector.push_back(Vert3);
}
