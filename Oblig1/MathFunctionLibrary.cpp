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

void MathFunctionLibrary::TreDSpiral(float LavreGrense, float OvreGrense, float Opplosning, float Radius, std::vector<Vertex>& VertVector)
{
	int LeddNr = 0;
	float h = ((OvreGrense - LavreGrense) / Opplosning);

	std::cout << "Antall intervaller (n): " << Opplosning << std::endl;
	std::cout << "Opplosning (h): " << h << std::endl << std::endl;

	for (float i = LavreGrense; i <= OvreGrense; i += h)
	{
		Vertex Vertices;

		x = i * Radius * cos(i);
		y = i * Radius * sin(i);
		z = i;

		Vertices.x = x;
		Vertices.y = y;
		Vertices.z = z;
		Vertices.r = -sin(i / 10);
		Vertices.g = 1;
		Vertices.b = cos(i / 5);

		std::cout << "F(" << LeddNr << ") = " << "x: " << x << ", y: " << y << ", z: " << z
			<< ", r: " << Vertices.r << ", g: " << Vertices.g << ", b: " << Vertices.b
			<< ", u: " << "\n";
		LeddNr++;

		VertVector.push_back(Vertices);
	}
}

void MathFunctionLibrary::ToVariabel(float LavreGrense, float OvreGrense, float Opplosning, std::vector<Vertex>& VertVector)
{
	int LeddNr = 0;
	float h = ((OvreGrense - LavreGrense) / Opplosning);

	std::cout << "Antall intervaller (n): " << Opplosning << std::endl;
	std::cout << "Opplosning (h): " << h << std::endl << std::endl;

	// Lage trekanter
	for (float i = LavreGrense; i <= OvreGrense; i += h)
	{
		x = i;

		for (float j = LavreGrense; j <= OvreGrense; j += h)
		{
			Vertex Vertices;

			y = j;
			z = pow(i, 2) + y;

			// Punkt 1
			Vertices.x = x;
			Vertices.y = y;
			Vertices.z = z;
			Vertices.r = 0.5;
			Vertices.g = 1;
			Vertices.b = 0.5;
			VertVector.push_back(Vertices);

			// Punkt 2
			Vertices.x = x + h;
			Vertices.y = y;
			Vertices.z = pow(x+h, 2) + y;
			Vertices.r = 0.5;
			Vertices.g = 1;
			Vertices.b = 0.5;
			VertVector.push_back(Vertices);

			// Punkt 3
			Vertices.x = x;
			Vertices.y = y + h;
			Vertices.z = pow(x, 2) + y + h;
			Vertices.r = 0.5;
			Vertices.g = 1;
			Vertices.b = 0.5;
			VertVector.push_back(Vertices);

			// Punkt 4
			Vertices.x = x;
			Vertices.y = y + h;
			Vertices.z = pow(x, 2) + y + h;
			Vertices.r = 0.5;
			Vertices.g = 1;
			Vertices.b = 0.5;
			VertVector.push_back(Vertices);

			// Punkt 5
			Vertices.x = x + h;
			Vertices.y = y + h;
			Vertices.z = pow(x+h, 2) + y + h;
			Vertices.r = 0.5;
			Vertices.g = 1;
			Vertices.b = 0.5;
			VertVector.push_back(Vertices);

			// Punkt 6
			Vertices.x = x + h;
			Vertices.y = y;
			Vertices.z = pow(x+h, 2) + y;
			Vertices.r = 0.5;
			Vertices.g = 1;
			Vertices.b = 0.5;
			VertVector.push_back(Vertices);

			//std::cout << "F(" << LeddNr << ") = " << "x: " << x << ", y: " << y << ", z: " << z
			//	<< ", r: " << Vertices.r << ", g: " << Vertices.g << ", b: " << Vertices.b
			//	<< ", u: " << Vertices.u << ", v: " << Vertices.v
			//	<< "\n";

			LeddNr++;
		}
	}
}