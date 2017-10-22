#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

static void DrawRect(float x, float y, float w, float h)
{
  glBegin(GL_POLYGON);
	glVertex2d(x, y);
    glVertex2d(x + w, y);
    glVertex2d(x + w, y + h);
    glVertex2d(x, y + h);
  glEnd();
}

static void error_callback(int error, const char* description)
{
  fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scanmode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
  {
	glfwSetWindowShouldClose(window, GL_TRUE);
  }
}

int main()
{
  if (!glfwInit())
  {
    return 1;
  }

  GLFWwindow *window = glfwCreateWindow(640, 480, "SAMPLE", NULL, NULL);

  if (!window)
  {
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, key_callback);

  while (!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);
	DrawRect(0,0,1,1);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
