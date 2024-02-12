#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "MathFunctionLibrary.h"
#include "OpenGL_Objects.h"
#include "ReadWriteFiles.h"
#include "Shader.h"
#include "Camera.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
	std::shared_ptr<ReadWriteFiles> ReadWriteTest = std::make_shared<ReadWriteFiles>();
	std::shared_ptr<MathFunctionLibrary> MathFuncLib = std::make_shared<MathFunctionLibrary>();

	Triangle TriangleTest;

	// Math Functions
	// ------------------------------

	/*Oppgave 1*/
	std::vector<Vertex> Oppgave1Vert;
	MathFuncLib->Andregradsfunksjon(-3, 3, 12, Oppgave1Vert);
	// Skriver ut andregradsfunksjonen til fil Oppgave 1
	ReadWriteTest->WriteToFile("Oppgave1Matematikk.txt", Oppgave1Vert);
	ReadWriteTest->ReadFromFileWriteIntoNewFile("Oppgave1Matematikk.txt", "Oppgave1Datapunkter.txt");

	/*Oppgave 2*/
	std::vector<Vertex> Oppgave2Vert;
	float pi = 2 * acos(0.0);
	MathFuncLib->TreDSpiral(0, pi / 6, 12, Oppgave2Vert);
	ReadWriteTest->WriteToFile("Oppgave2Matematikk.txt", Oppgave2Vert);
	ReadWriteTest->ReadFromFileWriteIntoNewFile("Oppgave2Matematikk.txt", "Oppgave2Datapunkter.txt");

	//ReadWriteTest->WriteToFile("C:/Test/TestWrite.txt", TriangleTest.VerticesVector);

	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// build and compile our shader program
	// ------------------------------------
	Shader ShaderProgram("VertexShader.vert", "FragmentShader.frag");

	unsigned int VBO, VAO;

	/////////Custom Array Oppgave 1/////////
	ReadWriteFiles ReadWrite;
	std::vector<Vertex> Opg1Vector;
	ReadWrite.FromDataToVertexVector("Oppgave1Datapunkter.txt", Opg1Vector);

	//Vertex Array Object - VAO
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//Vertex Buffer Object to hold vertices - VBO
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, Opg1Vector.size() * sizeof(Vertex), Opg1Vector.data(), GL_STATIC_DRAW);

	/////////Custom Array Oppgave 2/////////
	std::vector<Vertex> Opg2Vector;
	ReadWrite.FromDataToVertexVector("Oppgave2Datapunkter.txt", Opg1Vector);

	//glBufferData(GL_ARRAY_BUFFER, Opg2Vector.size() * sizeof(Vertex), Opg2Vector.data(), GL_STATIC_DRAW);

	// 1rst attribute buffer : vertices
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// 2nd attribute buffer : colors
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	///////////Line Array/////////
	//std::vector<Lines> LinesVector;
	//Lines LineObject;
	//LinesVector.push_back(LineObject);
	//for (auto it = LinesVector.begin(); it != LinesVector.end(); it++)
	//{
	//	//Vertex Array Object - VAO
	//	glGenVertexArrays(1, &VAO);
	//	glBindVertexArray(VAO);

	//	//Vertex Buffer Object to hold vertices - VBO
	//	glGenBuffers(1, &VBO);
	//	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//	glBufferData(GL_ARRAY_BUFFER, it->VerticesVector.size() * sizeof(Vertex), it->VerticesVector.data(), GL_STATIC_DRAW);

	//	// 1rst attribute buffer : vertices
	//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	//	glEnableVertexAttribArray(0);

	//	// 2nd attribute buffer : colors
	//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
	//	glEnableVertexAttribArray(1);

	//	glBindVertexArray(0);
	//}

	///////////Triangle Array/////////
	//std::vector<Triangle> TrianlgesVector;
	//Triangle TriangleObject;
	//TrianlgesVector.push_back(TriangleObject);
	//for (auto it = TrianlgesVector.begin(); it != TrianlgesVector.end(); it++)
	//{
	//	//Vertex Array Object - VAO
	//	glGenVertexArrays(1, &VAO);
	//	glBindVertexArray(VAO);

	//	//Vertex Buffer Object to hold vertices - VBO
	//	glGenBuffers(1, &VBO);
	//	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//	glBufferData(GL_ARRAY_BUFFER, it->VerticesVector.size() * sizeof(Vertex), it->VerticesVector.data(), GL_STATIC_DRAW);

	//	// 1rst attribute buffer : vertices
	//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	//	glEnableVertexAttribArray(0);

	//	// 2nd attribute buffer : colors
	//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
	//	glEnableVertexAttribArray(1);

	//	glBindVertexArray(0);
	//}

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	// glBindVertexArray(0);

	//float offset = 0.5f;

	// Enables the Depth Buffer
	//glEnable(GL_DEPTH_TEST);

	// Creates camera object
	Camera camera(SCR_WIDTH, SCR_HEIGHT, glm::vec3(0.0f, 0.0f, 2.0f));

	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// input
		// -----
		processInput(window);

		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//ourShader.setFloat("xOffset", offset); // Setting offset by the use of uniform and setfloat function to the VS

		// render the triangle
		ShaderProgram.use();

		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.Matrix(45.0f, 0.1f, 100.0f, ShaderProgram, "camMatrix");

		glBindVertexArray(VAO);

		glDrawArrays(GL_LINE_STRIP, 0, Opg1Vector.size());
		glDrawArrays(GL_LINE_STRIP, 0, Opg2Vector.size());

		//for (auto it = LinesVector.begin(); it != LinesVector.end(); it++)
		//{
		//	glDrawArrays(GL_LINE_STRIP, 0, it->VerticesVector.size());
		//}

		//for (auto it = TrianlgesVector.begin(); it != TrianlgesVector.end(); it++)
		//{
		//	glDrawArrays(GL_TRIANGLES, 0, it->VerticesVector.size());
		//}

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}