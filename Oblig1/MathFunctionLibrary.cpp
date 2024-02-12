#include "MathFunctionLibrary.h"

#include <iostream>
#include <string>

#include "OpenGL_Objects.h"

void MathFunctionLibrary::Andregradsfunksjon(float LavreGrense, float OvreGrense, float Opplosning, std::vector<Vertex>& VertVector)
{
	int LeddNr = 0;
	float h = ((OvreGrense - LavreGrense) / Opplosning);

	std::cout << "Antall intervaller (n): " << Opplosning << std::endl;
	std::cout << "Opplosning (h): " << h << std::endl << std::endl;

	for (float i = LavreGrense; i <= OvreGrense; i += h)
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
		std::cout << " || Sum av ledd: " << Vertices.y << " \n\n";
		LeddNr++;

		if (DenDeriverte > 0)
		{
			Vertices.r = 0.f;
			Vertices.g = 1.f;
			Vertices.b = 0.f;
		}
		if (DenDeriverte == 0)
		{
			Vertices.r = 1.f;
			Vertices.g = 1.f;
			Vertices.b = 0.f;
		}
		if (DenDeriverte < 0)
		{
			Vertices.r = 1.f;
			Vertices.g = 0.f;
			Vertices.b = 0.f;
		}
		VertVector.push_back(Vertices);
	}
}

void MathFunctionLibrary::TreDSpiral(float LavreGrense, float OvreGrense, float Opplosning, std::vector<Vertex>& VertVector)
{
	int LeddNr = 0;
	float h = ((OvreGrense - LavreGrense) / Opplosning);

	std::cout << "Antall intervaller (n): " << Opplosning << std::endl;
	std::cout << "Opplosning (h): " << h << std::endl << std::endl;

	for (float i = LavreGrense; i <= OvreGrense; i += h)
	{
		Vertex Vertices;

		x = cos(i);
		y = sin(i);
		z = x/10;

		//float DenDeriverte = ((4 * x) + 1);

		Vertices.x = x;
		Vertices.y = y;
		Vertices.z = z;

		std::cout << "F(" << LeddNr << ") = " << "x: " << x << ", y: " << y << ", z: " << z << "\n" /*<< ", F'(" << LeddNr << ") = " << DenDeriverte*/;
		LeddNr++;

		//if (DenDeriverte > 0)
		//{
		//	Vertices.r = 0.f;
		//	Vertices.g = 1.f;
		//	Vertices.b = 0.f;
		//}
		//if (DenDeriverte == 0)
		//{
		//	Vertices.r = 1.f;
		//	Vertices.g = 1.f;
		//	Vertices.b = 0.f;
		//}
		//if (DenDeriverte < 0)
		//{
		//	Vertices.r = 1.f;
		//	Vertices.g = 0.f;
		//	Vertices.b = 0.f;
		//}
		VertVector.push_back(Vertices);
	}
}