//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";
//
//
//int main()
//{
//	// Initialize GLFW
//	glfwInit();
//
//
//
//	// Tell GLFW what version of OpenGL we are using 
//	// In this case we are using OpenGL 3.3
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	// Tell GLFW we are using the CORE profile
//	// So that means we only have the modern functions
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//
//	GLfloat vertices[] =
//	{
//		-0.5f,-0.5f * float(sqrt(3)) / 3,0.0f,
//		0.5f,-0.5f * float(sqrt(3)) / 3,0.0f,
//		0.5f,0.5f * float(sqrt(3)) * 2 / 3,0.0f,
//		-0.5f,0.5f * float(sqrt(3)) * 2 / 3,0.0f
//		
//
//		//second
//	/*	0.5f,-0.5f * float(sqrt(3)) / 3,0.0f,
//		0.5f,0.5f * float(sqrt(3)) * 2 / 3,0.0f,
//		0.0f,0.5f * float(sqrt(3)) * 2 / 3,0.0f*/
//	};
//
//	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
//	GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
//
//	// Error check if the window fails to create
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	// Introduce the window into the current context
//	glfwMakeContextCurrent(window);
//
//
//
//	//Load GLAD so it configures OpenGL
//	gladLoadGL();
//	// Specify the viewport of OpenGL in the Window
//	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
//	glViewport(0, 0, 800, 800);
//
//	//###########SHADER
//	//Create shader
//	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	//Shader source link
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	//Convert machine langage(assembly language)
//	glCompileShader(vertexShader);
//
//	//Create shader
//	GLuint fragementshader = glCreateShader(GL_FRAGMENT_SHADER);
//	//Shader source link
//	glShaderSource(fragementshader, 1, &fragmentShaderSource, NULL);
//	//Convert machine langage(assembly language)
//	glCompileShader(fragementshader);
//
//	//Use two shader need to combine
//	GLuint shaderProgram = glCreateProgram();//셰이더 프로그램이 한가지 이기에 기본타입으로 생성해준다.
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragementshader);
//	
//	glLinkProgram(shaderProgram);//프로그램을 쉐이더 프로그램을 참조로 넘겨서 링커 과정을 해준다.
//	
//	glDeleteShader(vertexShader);//이미 프로그램내에 들어갔기에 삭제해 준다.
//	glDeleteShader(fragementshader);
//	
//
//	GLuint VAOs[1], VBOs[1];//원래는 배열 객체이지만 객체가 하나이니 하나만 필요함
//
//	glGenVertexArrays(1, VAOs);//배열 오브젝트
//	glGenBuffers(1, VBOs);//버퍼생성
//
//	glBindVertexArray(VAOs[0]);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);//VBOs랑 Buffer을 연결해줌 객체를 연결해준 것
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//외부에서 정점 셰이더와 통신하는 방법이다.
//	glEnableVertexAttribArray(0);//이렇게 하는 이유는 vertext Attribute의 위치 이기 때문이다.
//	
//								 
//
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);//배열의 연결을 끊어줌으로서 함수가 있는 VBOs또는 VAOs를 변경하지 않도록 바인딩을 해제 해준다.
//
//	// Specify the color of the background
//	glClearColor(1.0f, 0.67f, 0.0f, 1.0f);
//	// Clean the back buffer and assign the new color to it
//	glClear(GL_COLOR_BUFFER_BIT);
//	// Swap the back buffer with the front buffer
//	glfwSwapBuffers(window);
//
//	// Main while loop
//	while (!glfwWindowShouldClose(window))
//	{
//		// Specify the color of the background
//		glClearColor(1.0f, 0.67f, 0.0f, 1.0f);
//		// Clean the back buffer and assign the new color to it
//		glClear(GL_COLOR_BUFFER_BIT);
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAOs[0]);
//		glDrawArrays(GL_LINE_LOOP , 0, 4);//그리고 싶은 모양 설정 ,시작 정점의 위치, 그리는 정점의 수
//		//프레임마다 이미지가 교체되도록
//		glfwSwapBuffers(window);
//		// Take care of all GLFW events
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, VAOs);
//	glDeleteBuffers(1, VBOs);
//	glDeleteProgram(shaderProgram);//삭제하는 것을 보니 동적할당으로 구성되어있는 듯 하다.
//
//	// Delete window before ending the program
//	glfwDestroyWindow(window);
//	// Terminate GLFW before ending the program
//	glfwTerminate();
//	return 0;
//}

/*
Easy Difficulty
These only require the change of a few numbers or words!
Exercise 1. Change the equilateral triangle to a right triangle
Hint: don't forget the coordinates are always between -1.0f and 1.0f
	GLfloat vertices[] =
	{
		0.0.f,-0.5f * float(sqrt(3)) / 3,0.0f,
		0.5f,-0.5f * float(sqrt(3)) / 3,0.0f,
		0.0f,0.5f * float(sqrt(3)) * 2 / 3,0.0f,

	};


Exercise 2. Draw points instead of Triangles
Hint: use GL POINTS
while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_POINTS, 0, 3);//그리고 싶은 모양 설정 ,시작 정점의 위치, 그리는 정점의 수
		//프레임마다 이미지가 교체되도록
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}


2 Medium Difficulty
These require the use of a function and the change of some variables!
Exercise 1. Draw a square
Hint: add three more vertices and don't forget about glDrawArrays
GLfloat vertices[] =
	{
		0.0f,-0.5f * float(sqrt(3)) / 3,0.0f,
		0.5f,-0.5f * float(sqrt(3)) / 3,0.0f,
		0.0f,0.5f * float(sqrt(3)) * 2 / 3,0.0f,
		//second
		0.5f,-0.5f * float(sqrt(3)) / 3,0.0f,
		0.5f,0.5f * float(sqrt(3)) * 2 / 3,0.0f,
		0.0f,0.5f * float(sqrt(3)) * 2 / 3,0.0f
		/*-0.5f,-0.5f * float(sqrt(3)) / 3,0.0f,
		0.5f,-0.5f * float(sqrt(3)) / 3,0.0f,
		0.0f,0.5f * float(sqrt(3)) * 2 / 3,0.0f,*/
//	};
//	while (!glfwWindowShouldClose(window))
//	{
//		// Specify the color of the background
//		glClearColor(1.0f, 0.67f, 0.0f, 1.0f);
//		// Clean the back buffer and assign the new color to it
//		glClear(GL_COLOR_BUFFER_BIT);
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 6);//그리고 싶은 모양 설정 ,시작 정점의 위치, 그리는 정점의 수
//		glBindVertexArray(VAO);
//		//프레임마다 이미지가 교체되도록
//		glfwSwapBuffers(window);
//		// Take care of all GLFW events
//		glfwPollEvents();
//	}
//
//Exercise 2. Change VAO and VBO into VAOs and VBOs, and make
//them into arrays of size 1
//Hint: there are multiple places you need to modify
// GLuint VAOs[1], VBOs[1];//원래는 배열 객체이지만 객체가 하나이니 하나만 필요함
//
//glGenVertexArrays(1, VAOs);//배열 오브젝트
//glGenBuffers(1, VBOs);//버퍼생성
//
//glBindVertexArray(VAOs[0]);
//
//glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);//VBOs랑 Buffer을 연결해줌 객체를 연결해준 것
//
//3 Hard Difficulty
//This requires the change of multiple numbers and words!
//Exercise 1. Draw the outline of a square using GL LINE LOOP and 2D
//coordinates (get rid of the z axis)
//Hint: google how GL LINE LOOP works and modify glVertexAttribPointer and gl-
//DrawArrays
//GLfloat vertices[] =
	//{
	//-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
	//	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
	//	0.5f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
	//	-0.5f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f

	//};
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//외부에서 정점 셰이더와 통신하는 방법이다.
	//glDrawArrays(GL_LINE_LOOP, 0, 4);//그리고 싶은 모양 설정 ,시작 정점의 위치, 그리는 정점의 수
//*/