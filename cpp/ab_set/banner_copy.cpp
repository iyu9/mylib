#include <stdlib.h>
#include <string>
#include <iostream>

int main (int argc, char** argv)
{
  enum OutPutType
  {
	Banner,
	Bg,
	News
  };

  std::string src_dir  = "./";
  std::string dest_dir = "./";
  //const int pf_id = 0;
  const int type = 0;

  std::string root_dir[] =
  {
	"dummy/",
	"gesoten/",
	"hangame/",
	"mixi/",
	"mobage/",
	"nijiyome/",
	"rakuten/",
  };

  std::string name_tail[] = 
  {
	"",
	"_gc",
	"_hang",
	"_mixi",
	"_ym",
	"_njym",
	"_rktn",
  };

  std::string sub_dir[] =
  {
	"banner/",
	"bg/",
	"News/",
  };

  std::cout << "*START*" << std::endl;
  std::cout << "[0]:" + sizeof(root_dir[0]) << std::endl;
  std::cout << "[ARRAY]: " + sizeof(root_dir) << std::endl;


  for (int pf_id = 0; pf_id < (sizeof(root_dir) / sizeof(root_dir[0])); pf_id++)
  {

  std::cout << sizeof(root_dir[0]) / sizeof(root_dir) << std::endl;

  std::string exec_state1 = 
	"cp " + src_dir + "banner_1.*" + " " + dest_dir 
	  + root_dir[pf_id] + sub_dir[Banner] + "banner_1.jpg?" + name_tail[pf_id];
  system(exec_state1.c_str());
  std::cout << "EXEC(1): " << exec_state1 << std::endl;

  std::string exec_state2 = 
	"cp " + src_dir + "banner_2.*" + " " + dest_dir 
	  + root_dir[pf_id] + sub_dir[Banner] + "banner_2.jpg?" + name_tail[pf_id];
  system(exec_state2.c_str());
  std::cout << "EXEC(2): " << exec_state2 << std::endl;

  std::string exec_state3 = 
	"cp " + src_dir + "banner_3.*" + " " + dest_dir 
	  + root_dir[pf_id] + sub_dir[Banner] + "banner_3.jpg?" + name_tail[pf_id];
  system(exec_state3.c_str());
  std::cout << "EXEC(3): " << exec_state3 << std::endl;
  
  }

  std::cout << "*END*" << std::endl;
  /*
  //banner
  if (type == Banner)
  {
	env("cp" + src_dir + "banner_s" + " " + dest_dir + root_dir[pf_id] + sub_dir[0] + "banner_s" + name_tail);
	env("cp" + src_dir + "banner_m" + " " + dest_dir + root_dir[pf_id] + sub_dir[0] + "banner_m" + name_tail);
  }

  //bg
  if (type == Bg)
  {
	env("cp" + src_dir + "bg_event1" + " " + dest_dir + root_dir[pf_id] + sub_dir[0] + "bg_event1" + name_tail);
	env("cp" + src_dir + "bg_event2" + " " + dest_dir + root_dir[pf_id] + sub_dir[0] + "bg_event2" + name_tail);
	env("cp" + src_dir + "bg_event3" + " " + dest_dir + root_dir[pf_id] + sub_dir[0] + "bg_event3" + name_tail);	
  }

  //News
  if (type == News)
  {
	env("cp" + src_dir + "banner_1" + " " + dest_dir + root_dir[pf_id] + sub_dir[0] + "banner_1" + name_tail);
	env("cp" + src_dir + "banner_2" + " " + dest_dir + root_dir[pf_id] + sub_dir[0] + "banner_2" + name_tail);
	env("cp" + src_dir + "banner_3" + " " + dest_dir + root_dir[pf_id] + sub_dir[0] + "banner_3" + name_tail);
  }
  */

  return 0;  
}
