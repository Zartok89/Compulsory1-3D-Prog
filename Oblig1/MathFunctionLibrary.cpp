#include "MathFunctionLibrary.h"

#include <iostream>
#include <string>

#include "OpenGL_Objects.h"

void MathFunctionLibrary::Andregradsfunksjon(float LavreGrense, float OvreGrense, float Opplosning)
{
	int LeddNr = 0;
	float h = ((OvreGrense - LavreGrense) / Opplosning);

	std::cout << "Antall intervaller (n): " << Opplosning << std::endl;
	std::cout << "Opplosning (h): " << h << std::endl << std::endl;

	for (int i = LavreGrense; i <= OvreGrense; i++)
	{
		Vertex Vertices;

		x = i;
		b = x;
		a = 2 * pow(x, 2);
		c = -3;

		float DenDeriverte = ((4 * x) + 1);

		Vertices.x = x;
		Vertices.y = a + b + c;

		std::cout << "F(" << LeddNr << ") = " << "a: " << a << ", b: " << b << ", c: " << c << ", F'(" << LeddNr << ") = " << DenDeriverte;
		std::cout << " || Sum av ledd: " << Vertices.y <<" \n\n";
		VerticesVector.push_back(Vertices);
		LeddNr++;
	}
}