#include <GLFW/glfw3.h>
#include <iostream>

#include "GLVec.h"
#include "GLSL.h"
#include "GLUtils.h"
#include "GLBuiltInCallback.h"
#include "GLBmpLoader.hpp"

const int g_windowWidth = 640;
const int g_windowHeight = 480;

GLVec2 pos;
BMP *bmp;

void CustomInit()
{
  GLUtils::CheckRenderTexture();

  bmp = new BMP("sample.bmp");
  glBindTexture(GL_TEXTURE_2D, bmp->texture);
}

void MainLoop()
{
  glClear(GL_COLOR_BUFFER_BIT);

  //2dRect
  //glColor3f(0, 1, 0);
  //GLUtils::DrawRect(pos.x, pos.y, 0.5f, 0.5f);

  //2dTexture
  glColor3f(1, 1, 1);
  GLUtils::DrawTexture(-0.8f + pos.x, -0.8f + pos.y, 1.6f, 1.6f);

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

  GLFWwindow *window =
    glfwCreateWindow(g_windowWidth, g_windowHeight, "SAMPLE", NULL, NULL);

  if (!window)
  {
    std::cout << "create window failed";
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, key_callback);
  glfwSetCursorPosCallback(window, cursor_pos_callback);

  CustomInit();

  while (!glfwWindowShouldClose(window))
  {
    MainLoop();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
