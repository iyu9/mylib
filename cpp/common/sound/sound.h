#include "../common/common.h"

class sound
{
private:
  int playingResID;

  enum fileType
  {
    wav,
    ogg,
    mp3        
  }
  
public:
  sound();
  ~sound();

  bool play(int resID);
  bool stop();
  bool volume(float vol);
};
