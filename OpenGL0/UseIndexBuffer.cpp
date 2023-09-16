//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
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
//		-0.5f,0.5f * float(sqrt(3)) /3,0.0f,
//		0.5f,0.5f * float(sqrt(3)) /3,0.0f,
//		
//	};
//
//	GLuint indices[] =
//	{
//		0,1,2,//아래 왼쪽
//		1,2,3//아래 오른쪽		
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
//	
//
//
//	GLuint VAOs[1], VBOs[1],EBO;//원래는 배열 객체이지만 객체가 하나이니 하나만 필요함
//
//	glGenVertexArrays(1, VAOs);//배열 오브젝트
//	//glGenBuffers(1, VBOs);//버퍼생성
//	glGenBuffers(1, &EBO);
//
//	glBindVertexArray(VAOs[0]);
//
//	//glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);//VBOs랑 Buffer을 연결해줌 객체를 연결해준 것
//	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//외부에서 정점 셰이더와 통신하는 방법이다.
//	glEnableVertexAttribArray(0);//이렇게 하는 이유는 vertext Attribute의 위치 이기 때문이다.
//
//
//
//
//	//glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);//배열의 연결을 끊어줌으로서 함수가 있는 VBOs또는 VAOs를 변경하지 않도록 바인딩을 해제 해준다.
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
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
//		//glDrawArrays(GL_LINE_LOOP, 0, 4);//그리고 싶은 모양 설정 ,시작 정점의 위치, 그리는 정점의 수
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		//프레임마다 이미지가 교체되도록
//		glfwSwapBuffers(window);
//		// Take care of all GLFW events
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, VAOs);
//	//glDeleteBuffers(1, VBOs);
//	
//	glDeleteBuffers(1, &EBO);
//
//	// Delete window before ending the program
//	glfwDestroyWindow(window);
//	// Terminate GLFW before ending the program
//	glfwTerminate();
//	return 0;
//}
//1 Easy Diffculty
//This only requires the change of a few variables!
//Exercise 1. Draw a square using 4 vertices and 6 indices
//Hint : create comments so you know which coordinate is which\
//
//GLfloat vertices[] =
//{
//	-0.5f,-0.5f * float(sqrt(3)) / 3,0.0f,
//	0.5f,-0.5f * float(sqrt(3)) / 3,0.0f,
//	-0.5f,0.5f * float(sqrt(3)) / 3,0.0f,
//	0.5f,0.5f * float(sqrt(3)) / 3,0.0f,
//
//};
//
//GLuint indices[] =
//{
//	0,1,2,//아래 왼쪽
//	1,2,3//아래 오른쪽		
//};
//
//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);