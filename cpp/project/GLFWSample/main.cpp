#include <GLFW/glfw3.h>
#include <iostream>

#include "GLVec.hpp"
#include "GLUtils.hpp"
#include "GLBuiltInCallback.hpp"

GLVec2 pos;

static void MainLoop()
{
  glClear(GL_COLOR_BUFFER_BIT);

  //2dRect
  glColor3f(1, 0, 0);
  GLUtils::DrawRect(pos.x, pos.y, 1.0f, 1.0f);

  //2dLine
  glColor3f(0, 1, 0);
  GLUtils::DrawLine(pos.x, pos.y, 1.0f, 1.0f, 20);

  glFlush();
}

int main()
{
  glfwSetErrorCallback(error_callback);
  if (!glfwInit())
  {
    std::cout << "init failed";
    return 1;
  }

  GLFWwindow *window = glfwCreateWindow(640, 480, "SAMPLE", NULL, NULL);

  if (!window)
  {
    std::cout << "create window failed";
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, key_callback);
  glfwSetCursorPosCallback(window, cursor_pos_callback);

  while (!glfwWindowShouldClose(window))
  {
    MainLoop();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
