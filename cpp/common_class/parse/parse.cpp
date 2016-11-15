#include "../common/common.h"
#include <stack>
#include <typeinfo>
#include <cstdlib>

//Reference:
//https://ja.wikipedia.org/wiki/Interpreter_%E3%83%91%E3%82%BF%E3%83%BC%E3%83%B3

class Expression
{
  public:
    void interpret(std::stack<int> s);
};

class TerminalExpression_Number : Expression
{
  private:
    int number;

  public:
    TerminalExpression_Number(int number_)
    {
        number = number_;
    }

    void interpret(std::stack<int> s)
    {
        s.push(number);
    }
};

class TerminalExpression_Plus : Expression
{
  public:
    void interpret(std::stack<int> s)  { s.push( s.pop() + s.pop() ); }
};

class TerminalExpression_Minus : Expression
{
  public:
    void interpret(std::stack<int> s)  { s.push( - s.pop() + s.pop() ); }
};

class parser
{
  private:
    std::vector<Expression> parseTree; // only one NonTerminal Expression here

  public:
    parser(std::string s)
    {
      for (std::string token : s.split(" "))
      {
        if      (token.equals("+")) 
		  parseTree.add( new TerminalExpression_Plus() );
        else if (token.equals("-")) 
		  parseTree.add( new TerminalExpression_Minus() );
        // ...
        else                        
		  parseTree.add( new TerminalExpression_Number(atoi(token)));
      }
    }

    int evaluate()
    {
      std::stack<int> context = new std::stack<int>();
      for (Expression e : parseTree)
	  { 
		e.interpret(context);
	  }
      return context.pop();
    }
};

int main(void)
{
  std::string expression = "42 4 2 - +";
  parser* p = new parser(expression);
  std::cout << "'" + expression +"' equals " + p->evaluate() << std::endl;

  delete(p);
  return 0;
}
