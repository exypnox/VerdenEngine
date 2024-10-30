#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


class GameEngine {
private:
	int m_height;
	int m_width;
public:
	GameEngine();
	void Init();

};
int main() {
	GLFWwindow* window;
	if (!glfwInit()) { return -1; }

	window = glfwCreateWindow(1280, 720, "Saidahmad", NULL, NULL);

	if (!window) {
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "Err" << std::endl;
	}

	while (!glfwWindowShouldClose(window)) {
		glClear(GLFW_GREEN_BITS);

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);

		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	glfwTerminate();
	return 0;
}