#pragma once
#include <vector>


class Vertex;

class MathFunctionLibrary
{
	float a = 0;
	float b = 0;
	float c = 0;
	float x = 0;
	float y = 0;
	float z = 0;

public:
	std::vector<Vertex> VerticesVector;

	void Andregradsfunksjon(float LavreGrense, float OvreGrense, float Opplosning, std::vector<Vertex>& VertVector);

	void TreDSpiral(float LavreGrense, float OvreGrense, float Opplosning, std::vector<Vertex>& VertVector);
};
