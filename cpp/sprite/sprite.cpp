class Sprite
{
public:
  int resourceId;

public:
  bool Create();
  bool Delete();
};

/**/
int main()
{
  Sprite* spr = new Sprite();

  return 0;  
}
/**/
