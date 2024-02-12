#pragma once
#include <vector>


class Vertex;

class MathFunctionLibrary
{

	float a = 0;
	float b = 0;
	float c = 0;
	float x = 0;

public:
	std::vector<Vertex> VerticesVector;

	void Andregradsfunksjon(float LavreGrense, float OvreGrense, float Oppløsning);

};
