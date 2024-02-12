#include "MathFunctionLibrary.h"

#include <iostream>
#include <string>

#include "OpenGL_Objects.h"

void MathFunctionLibrary::Andregradsfunksjon(float LavreGrense, float OvreGrense, float Oppløsning)
{
	int LeddNr = 0;

	for (int i = LavreGrense; i <= OvreGrense; i++)
	{
		Vertex Vertices;

		x = i;
		b = x;
		a = 2 * pow(x, 2);
		c = -3;

		Vertices.x = x;
		Vertices.y = a + b + c;
		std::cout << "F(" << LeddNr << ") = " << "a: " << a << ", b: " << b << ", c: " << c;
		std::cout << " || Sum av ledd: " << Vertices.y << " \n\n";
		VerticesVector.push_back(Vertices);
		LeddNr++;
	}
}