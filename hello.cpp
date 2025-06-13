#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

#define width 1024
#define height 768
const char title[] = "shitware";

int main() {

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
  if (window == NULL)  {
    std::cout << "Window creation failed. Session terminated." << std::endl;
    glfwTerminate();
    return -1;
    }

  glfwMakeContextCurrent(window); //you must make the OpenGL context current before calling GLAD

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Cannot initialize GLAD" << std::endl;
    return -1;
  }

  glViewport (0, 0, width, height); // tell OpenGL the size of the window to draw in

  do {
    glfwSwapBuffers(window);
    glfwPollEvents();
  } while(!glfwWindowShouldClose(window)); //keeps drawing the same frame until we close it

  glfwTerminate();
  return 0;
}
