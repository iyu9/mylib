namespace GLUtils
{
  static void DrawTexture(float x, float y, float w, float h)
  {
    glEnable(GL_TEXTURE_2D);
      glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0); glVertex3f(x, y, 0.0);
        glTexCoord2f(0.0, 1.0); glVertex3f(x, y + h, 0.0);
        glTexCoord2f(1.0, 1.0); glVertex3f(x + w, y + h, 0.0);
        glTexCoord2f(1.0, 0.0); glVertex3f(x + w, y, 0.0);
      glEnd();
    glDisable(GL_TEXTURE_2D);
  }

  static void DrawRect(float x, float y, float w, float h)
  {
    glBegin(GL_POLYGON);
      glVertex2d(x, y);
      glVertex2d(x + w, y);
      glVertex2d(x + w, y + h);
      glVertex2d(x, y + h);
    glEnd();
  }

  static void DrawLine(float start_x, float start_y, float end_x, float end_y, int width)
  {
    glLineWidth(width);

    glBegin(GL_LINES);
      glVertex2d(start_x, start_y);
      glVertex2d(end_x, end_y);
    glEnd();
  }

  static void DrawPoint(float x, float y, int width)
  {
    glLineWidth(width);

    glBegin(GL_POINTS);
      glVertex2d(x, y);
    glEnd();
  }

  static void DrawText(float start_x, float start_y, float end_x, float end_y)
  {
    // TWD
  }
};
