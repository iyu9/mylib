#include <iostream>
#include <string>

class message
{
  public:
	int id;
	int cmd;
	int color;
	std::string text; 

  message()
  {
	id = 0;
	cmd = 0;
	color = 0;
	text = "TESTESTESSTSET";
  }
};

class script
{
  public:
	message msg;
	int charIndex;
	int textIndex;
	float time;

	void update() {
	  time++;

	  if (time > 100000)
	  {
		time = 0;
		charIndex++;
		std::cout << msg.text << std::endl;
	  }
	}

	void prev() {
	  
	}

	void next(){
	  
	} 
};

/**/
int main ()
{
  script* s = new script();
 
  while(1)
  {
	s->update();
  }

  return 0;  
}
/**/
