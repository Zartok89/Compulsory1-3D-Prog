#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec3 aColor; // the color variable has attribute position 1
  
out vec3 ourColor; // specify a color output to the fragment shader

//uniform float xOffset;

// Imports the camera matrix from the main function
uniform mat4 camMatrix;

void main()
{
    gl_Position = camMatrix * vec4(aPos, 1.0); // see how we directly give a vec3 to vec4's constructor
    ourColor = aColor; // set ourColor to the input color we got from the vertex data
}
