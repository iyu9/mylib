class sound
{
  int type;
};

class sound_manager
{
  sound_manager();
  ~sound_manager();

  void load();
  void save();

  bool change_vol();

  void play();
  void play_se();
  void play_voice();
};
