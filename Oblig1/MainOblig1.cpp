#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <stb/stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

	// Math Functions
	// ------------------------------

	/*Oppgave 1*/
	std::vector<Vertex> Oppgave1Vert;
	MathFuncLib->Andregradsfunksjon(-3, 3, 12, Oppgave1Vert);
	ReadWriteTest->WriteToFile("Oppgave1Matematikk.txt", Oppgave1Vert);
	ReadWriteTest->ReadFromFileWriteIntoNewFile("Oppgave1Matematikk.txt", "Oppgave1Datapunkter.txt");

	/*Oppgave 2*/
	std::vector<Vertex> Oppgave2Vert;
	float pi = 2 * acos(0.0);
	MathFuncLib->TreDSpiral(0, (pi / 6) * 100, 100, 1, Oppgave2Vert);
	ReadWriteTest->WriteToFile("Oppgave2Matematikk.txt", Oppgave2Vert);
	ReadWriteTest->ReadFromFileWriteIntoNewFile("Oppgave2Matematikk.txt", "Oppgave2Datapunkter.txt");

	/*Oppgave 3*/
	std::vector<Vertex> Oppgave3Vert;
	MathFuncLib->ToVariabel(-5, 5, 10, Oppgave3Vert);
	ReadWriteTest->WriteToFile("Oppgave3Matematikk.txt", Oppgave3Vert);
	ReadWriteTest->ReadFromFileWriteIntoNewFile("Oppgave3Matematikk.txt", "Oppgave3Datapunkter.txt");

	/////////Custom Array Oppgave 1/////////
	ReadWriteFiles ReadWrite;
	std::vector<Vertex> Opg1Vector;
	ReadWrite.FromDataToVertexVector("Oppgave1Datapunkter.txt", Opg1Vector);

	/////////Custom Array Oppgave 2/////////
	std::vector<Vertex> Opg2Vector;
	ReadWrite.FromDataToVertexVector("Oppgave2Datapunkter.txt", Opg2Vector);

	/////////Custom Array Oppgave 3/////////
	std::vector<Vertex> Opg3Vector;
	ReadWrite.FromDataToVertexVector("Oppgave3Datapunkter.txt", Opg3Vector);

	unsigned int indices[] = {
	0, 1, 3, // first triangle
	1, 2, 3,  // second triangle
	3, 4, 1,  // second triangle
	1, 3, 6  // second triangle
	};

	// world space positions of our cubes
	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

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

	unsigned int VBO, VAO, EBO;

	//Vertex Array Object - VAO
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//Vertex Buffer Object to hold vertices - VBO
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	//glBufferData(GL_ARRAY_BUFFER, Opg1Vector.size() * sizeof(Vertex), Opg1Vector.data(), GL_STATIC_DRAW);

	//glBufferData(GL_ARRAY_BUFFER, Opg2Vector.size() * sizeof(Vertex), Opg2Vector.data(), GL_STATIC_DRAW);

	glBufferData(GL_ARRAY_BUFFER, Opg3Vector.size() * sizeof(Vertex), Opg3Vector.data(), GL_STATIC_DRAW);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 1rst attribute buffer : vertices
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// 2nd attribute buffer : colors
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// 3nd attribute buffer : UV
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

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
	glEnable(GL_DEPTH_TEST);

	//// load and create a texture
	//// -------------------------
	//unsigned int texture1, texture2;
	//// texture 1
	//// ---------
	//glGenTextures(1, &texture1);
	//glBindTexture(GL_TEXTURE_2D, texture1);
	//// set the texture wrapping parameters
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//// set texture filtering parameters
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//// load image, create texture and generate mipmaps
	//int width, height, nrChannels;
	////stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
	////// The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
	////unsigned char* data = stbi_load("brick1.jpg", &width, &height, &nrChannels, 0);
	////if (data)
	////{
	////	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	////	glGenerateMipmap(GL_TEXTURE_2D);
	////}
	////else
	////{
	////	std::cout << "Failed to load texture" << std::endl;
	////}
	////stbi_image_free(data);
	//// texture 2
	//// ---------
	//glGenTextures(1, &texture2);
	//glBindTexture(GL_TEXTURE_2D, texture2);
	//// set the texture wrapping parameters
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//// set texture filtering parameters
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	//data = stbi_load("brick2.jpg", &width, &height, &nrChannels, 0);
	//if (data)
	//{
	//	// note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	//	glGenerateMipmap(GL_TEXTURE_2D);
	//}
	//else
	//{
	//	std::cout << "Failed to load texture" << std::endl;
	//}
	//stbi_image_free(data);

	// tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
	// -------------------------------------------------------------------------------------------
	ShaderProgram.use(); // don't forget to activate/use the shader before setting uniforms!
	// either set it manually like so:
	glUniform1i(glGetUniformLocation(ShaderProgram.ID, "texture1"), 0);
	// or set it via the texture class
	ShaderProgram.setInt("texture2", 1);

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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//ourShader.setFloat("xOffset", offset); // Setting offset by the use of uniform and setfloat function to the VS

		// bind textures on corresponding texture units
		//glActiveTexture(GL_TEXTURE0);
		//glBindTexture(GL_TEXTURE_2D, texture1);
		//glActiveTexture(GL_TEXTURE1);
		//glBindTexture(GL_TEXTURE_2D, texture2);

		// render container
		ShaderProgram.use();

		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.Matrix(45.0f, 0.1f, 1000.0f, ShaderProgram, "camMatrix");

		glBindVertexArray(VAO);

		//for (unsigned int i = 0; i < 10; i++)
		//{
		//	// calculate the model matrix for each object and pass it to shader before drawing
		//	glm::mat4 model = glm::mat4(1.0f);
		//	model = glm::translate(model, cubePositions[i]);
		//	float angle = 20.0f * i;
		//	model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		//	ShaderProgram.setMat4("model", model);

		//	glDrawArrays(GL_TRIANGLES, 0, 36);
		//}

		//glDrawArrays(GL_LINE_STRIP, 0, Opg1Vector.size());
		//glDrawArrays(GL_LINE_STRIP, 0, Opg2Vector.size());
		glDrawArrays(GL_TRIANGLES, 0, Opg3Vector.size());
		//glDrawElements(GL_TRIANGLES, Opg3Vector.size(), GL_UNSIGNED_INT, 0);

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
	glDeleteBuffers(1, &EBO);

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