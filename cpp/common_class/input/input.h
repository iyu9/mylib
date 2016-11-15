/*
 *	input manager class
 *	@tomii
 */
class input {
	private:
	char key;

	public:
	//constructors
	input();
	~input();
	
	//methods
	void read();
	char get_key();
};
