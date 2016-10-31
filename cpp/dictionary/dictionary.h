/*
 * Custom Dictionary Class
 */
class T dictionary_element
{
  public:
	std::string key;
	T value;
	
  T get_value(std::string key)
  {
	return value;
  }

  std::string get_key(T value)
  {
	return key;	
  }
};
