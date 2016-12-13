/*
 * OpenGL Sprite Class
 */
class GLSprite
{
private:
  int texture[99][99];

public:
  GLSprite(){}
  ~GLSprite(){}

  int** GetTexture()
  {
	return texture;	
  }
};
