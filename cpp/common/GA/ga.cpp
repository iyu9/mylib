#include <list>
#include <string>

class Indivisual
{
private:
	int idx;
	std::string name;
	int val;
};

class GA
{
private:
  std::list<Indivisual> current;
  std::list<Indivisual> future;

public:
  GA();
  ~GA();

  void CreateCurrent();
  void Evaluate();
  void Action();

  //sel action
  void Crossing();
  void Mutation();
  void Copying();
};

GA::GA() {}
GA::~GA(){}

void GA::CreateCurrent(){}
void GA::Evaluate(){}
void GA::Action(){}
void GA::Crossing(){}
void GA::Mutation(){}
void GA::Copying(){}

int main()
{
  GA* ga = new GA();
  return 0;
}
