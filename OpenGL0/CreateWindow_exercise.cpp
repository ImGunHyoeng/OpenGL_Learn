//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//int main()
//{
//	 Initialize GLFW
//	glfwInit();
//
//
//
//	 Tell GLFW what version of OpenGL we are using 
//	 In this case we are using OpenGL 3.3
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	 Tell GLFW we are using the CORE profile
//	 So that means we only have the modern functions
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//
//
//	 Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
//	GLFWwindow* window = glfwCreateWindow(400, 225, "YoutubeOpenGL", NULL, NULL);
//
//	 Error check if the window fails to create
//	if(window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	 Introduce the window into the current context
//	glfwMakeContextCurrent(window);
//
//
//
//	Load GLAD so it configures OpenGL
//	gladLoadGL();
//	 Specify the viewport of OpenGL in the Window
//	 In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
//	glViewport(0, 0, 400, 225);
//
//
//
//	 Specify the color of the background
//	glClearColor(1.0f, 0.67f, 0.0f, 1.0f);
//	 Clean the back buffer and assign the new color to it
//	glClear(GL_COLOR_BUFFER_BIT);
//	 Swap the back buffer with the front buffer
//	glfwSwapBuffers(window);
//
//	float angle = 0.0f;
//	double prev_time = glfwGetTime();
//	double time = 0.0f;
//	 Main while loop
//	while (!glfwWindowShouldClose(window))
//	{
//		time = glfwGetTime();
//		glfwSwapBuffers(window);
//		 Take care of all GLFW events
//		if (time-prev_time>=0.1f)
//		{
//			angle += 0.1f;
//			prev_time = time;
//		}
//		glClearColor((float)sin(angle), (float)cos(angle), (float)tan(angle), 1.0f);
//		 Clean the back buffer and assign the new color to it
//		glClear(GL_COLOR_BUFFER_BIT);
//		glfwSwapBuffers(window);
//		std::cout << time << std::endl;
//		glfwPollEvents();
//	}
//
//
//
//	 Delete window before ending the program
//	glfwDestroyWindow(window);
//	 Terminate GLFW before ending the program
//	glfwTerminate();
//	return 0;
//}
//easy
//1st Exercise: make window color Orange
// {
//		glClearColor(1.0f, 0.67f, 0.0f, 1.0f);
// }
//2st Exercise: control window size
//{
//	GLFWwindow* window = glfwCreateWindow(400, 225, "YoutubeOpenGL", NULL, NULL);
//	glViewport(0, 0, 400, 225);
//}
//3st Exercise: window name setting
//GLFWwindow* window = glfwCreateWindow(400, 225, "I made this", NULL, NULL);
//
//middle
//{
//	glclearcolor(1.0f, 0.67f, 0.0f, 1.0f);
//	 clean the back buffer and assign the new color to it
//glclear(gl_color_buffer_bit);
// swap the back buffer with the front buffer
//glfwswapbuffers(window);
//
//
//
// main while loop
//while (!glfwwindowshouldclose(window))
//{
//	glfwswapbuffers(window);
//	 take care of all glfw events
//	glfwpollevents();
//}
//}
//
//
//hard
//
// 	float angle = 0.0f;
//double prev_time = glfwGetTime();
//double time = 0.0f;
// Main while loop
//while (!glfwWindowShouldClose(window))
//{
//	time = glfwGetTime();
//	glfwSwapBuffers(window);
//	 Take care of all GLFW events
//	if (time - prev_time >= 0.1f)
//	{
//		angle += 0.1f;
//		prev_time = time;
//	}
//	glClearColor((float)sin(angle), (float)cos(angle), (float)tan(angle), 1.0f);
//	 Clean the back buffer and assign the new color to it
//	glClear(GL_COLOR_BUFFER_BIT);
//	glfwSwapBuffers(window);
//	std::cout << time << std::endl;
//	glfwPollEvents();
//}
//
//
