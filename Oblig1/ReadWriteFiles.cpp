#include "ReadWriteFiles.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include "OpenGL_Objects.h"

ReadWriteFiles::ReadWriteFiles()
{
	std::vector<Vertex> VerticesVector;
}

void ReadWriteFiles::WriteToFile(std::string Filepath, std::vector<Vertex>& VertexVector)
{
	/*Writing to file*/
	//---------------------------------------------------------------------------
	std::fstream MyFile;
	MyFile.open(Filepath, std::ios::out); // Writemode into a text-file
	if (MyFile.is_open())
	{
		std::cout << "File has been opened correctly\n";
		for (Vertex Vert : VertexVector)
		{
			MyFile << "x: " << Vert.x << ", ";
			MyFile << "y: " << Vert.y << ", ";
			MyFile << "z: " << Vert.z << ", ";
			MyFile << "r: " << Vert.r << ", ";
			MyFile << "g: " << Vert.g << ", ";
			MyFile << "b: " << Vert.b << " \n";
		}
		
		MyFile.close();
	}
	else
	{
		std::cerr << "Error opening files." << std::endl;
	}
}

void ReadWriteFiles::AppendToFile(std::string Filepath)
{
	/*Appending into file*/
	//---------------------------------------------------------------------------
	std::fstream MyFile;
	MyFile.open(Filepath, std::ios::app); // Append mode
	if (MyFile.is_open())
	{
		std::cout << "File has been opened correctly\n";
		MyFile << "Text to put into file\n";
		MyFile << "Second line\n";
		MyFile.close();
	}
}

void ReadWriteFiles::ReadFromFile(std::string FileToRead)
{
	/*Reading from file*/
	//---------------------------------------------------------------------------
	std::fstream MyFile;
	MyFile.open(FileToRead, std::ios::in); // Read mode
	if (MyFile.is_open())
	{
		std::cout << "File has been opened correctly\n";
		std::string Line;
		while (std::getline(MyFile, Line))
		{
			std::cout << Line << std::endl;
		}
		MyFile.close();
	}
	else
	{
		std::cerr << "Error opening files." << std::endl;
	}
}

void ReadWriteFiles::ReadFromFileWriteIntoNewFile(std::string FileToRead, std::string NewDataFile)
{
	std::fstream MyFileRead;
	std::fstream MyFileWrite;
	MyFileRead.open(FileToRead, std::ios::in);
	MyFileWrite.open(NewDataFile, std::ios::out);

	if (MyFileRead.is_open() && MyFileWrite.is_open())
	{
		std::cout << "Reading file: " << FileToRead << std::endl;
		std::cout << "Starting to write into new file: " << NewDataFile << std::endl;
		std::string Line;
		while (std::getline(MyFileRead, Line))
		{
			RemovingUnwantedChars(Line);

			// Tokenize the line based on spaces
			std::istringstream iss(Line);
			std::vector<float> floats;
			float Number;
			while (iss >> Number)
			{
				floats.push_back(Number);
			}

			// Write the code to floats to the output file
			for (float Number : floats)
			{
				MyFileWrite << Number << " ";
			}
			MyFileWrite << std::endl;
		}
		MyFileRead.close();
		MyFileWrite.close();
		std::cout << "Commas removed successfully." << std::endl;
	}
	else
	{
		std::cerr << "Error opening files." << std::endl;
	}
}

void ReadWriteFiles::FromDataToVertexVector(std::string DataFileToVertexVector, std::vector<Vertex>& VerticesVector)
{
	std::fstream MyFile;
	MyFile.open(DataFileToVertexVector, std::ios::in); // Read mode
	if (MyFile.is_open())
	{
		std::cout << "File has been opened correctly\n";
		std::string Line;
		while (std::getline(MyFile, Line))
		{
			std::istringstream iss(Line);
			std::vector<float> floats;
			float Number;
			while (iss >> Number)
			{
				floats.push_back(Number);
			}
			float TempX = floats[0];
			float TempY = floats[1];
			float TempZ = floats[2];
			float TempR = floats[3];
			float TempG = floats[4];
			float TempB = floats[5];
			VerticesVector.emplace_back(Vertex{ TempX, TempY, TempZ, TempR, TempG, TempB });
		}

		std::cout << "Amount of Vertexes added to the vector: " << VerticesVector.size() << std::endl;
		MyFile.close();
	}
	else
	{
		std::cerr << "Error opening files." << std::endl;
	}
}

void ReadWriteFiles::RemovingUnwantedChars(std::string& Line)
{
	// Symbols and lines to remove:
	Line.erase(std::remove(Line.begin(), Line.end(), 'x'), Line.end());
	Line.erase(std::remove(Line.begin(), Line.end(), 'y'), Line.end());
	Line.erase(std::remove(Line.begin(), Line.end(), 'z'), Line.end());
	Line.erase(std::remove(Line.begin(), Line.end(), 'r'), Line.end());
	Line.erase(std::remove(Line.begin(), Line.end(), 'g'), Line.end());
	Line.erase(std::remove(Line.begin(), Line.end(), 'b'), Line.end());
	Line.erase(std::remove(Line.begin(), Line.end(), ':'), Line.end());
	Line.erase(std::remove(Line.begin(), Line.end(), ','), Line.end());
	Line.erase(std::remove(Line.begin(), Line.end(), 'f'), Line.end());
}