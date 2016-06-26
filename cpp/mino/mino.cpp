#include "mino.h"

mino::mino() {

}

mino::mino(int type) {
  switch(type) {
	//   * * 
	//   * * 
	case 0:
	  val[0][0] = 0; val[0][1] = 0; val[0][2] = 0; val[0][3] = 0;
	  val[1][0] = 0; val[1][1] = 1; val[1][2] = 1; val[1][3] = 0;
	  val[2][0] = 0; val[2][1] = 1; val[2][2] = 1; val[2][3] = 0;
	  val[3][0] = 0; val[3][1] = 0; val[3][2] = 0; val[3][3] = 0;
	//   *
	//   *
	//   * *
	case 1:
	  val[0][0] = 0; val[0][1] = 1; val[0][2] = 0; val[0][3] = 0;
	  val[1][0] = 0; val[1][1] = 1; val[1][2] = 0; val[1][3] = 0;
	  val[2][0] = 0; val[2][1] = 1; val[2][2] = 1; val[2][3] = 0;
	  val[3][0] = 0; val[3][1] = 0; val[3][2] = 0; val[3][3] = 0;
	  break;

	case 2:
	  val[0][0] = 0; val[0][1] = 0; val[0][2] = 1; val[0][3] = 0;
	  val[1][0] = 0; val[1][1] = 0; val[1][2] = 1; val[1][3] = 0;
	  val[2][0] = 0; val[2][1] = 0; val[2][2] = 1; val[2][3] = 0;
	  val[3][0] = 0; val[3][1] = 0; val[3][2] = 1; val[3][3] = 0;
	  break;

	case 3:
	  val[0][0] = 1; val[0][1] = 1; val[0][2] = 1; val[0][3] = 1;
	  val[1][0] = 1; val[1][1] = 1; val[1][2] = 1; val[1][3] = 1;
	  val[2][0] = 1; val[2][1] = 1; val[2][2] = 1; val[2][3] = 1;
	  val[3][0] = 1; val[3][1] = 1; val[3][2] = 1; val[3][3] = 1;
	  break;

	case 4:
	  val[0][0] = 1; val[0][1] = 1; val[0][2] = 1; val[0][3] = 1;
	  val[1][0] = 1; val[1][1] = 1; val[1][2] = 1; val[1][3] = 1;
	  val[2][0] = 1; val[2][1] = 1; val[2][2] = 1; val[2][3] = 1;
	  val[3][0] = 1; val[3][1] = 1; val[3][2] = 1; val[3][3] = 1;
	  break;

	case 5:
	  val[0][0] = 1; val[0][1] = 1; val[0][2] = 1; val[0][3] = 1;
	  val[1][0] = 1; val[1][1] = 1; val[1][2] = 1; val[1][3] = 1;
	  val[2][0] = 1; val[2][1] = 1; val[2][2] = 1; val[2][3] = 1;
	  val[3][0] = 1; val[3][1] = 1; val[3][2] = 1; val[3][3] = 1;
	  break;

	case 6:
	  val[0][0] = 1; val[0][1] = 1; val[0][2] = 1; val[0][3] = 1;
	  val[1][0] = 1; val[1][1] = 1; val[1][2] = 1; val[1][3] = 1;
	  val[2][0] = 1; val[2][1] = 1; val[2][2] = 1; val[2][3] = 1;
	  val[3][0] = 1; val[3][1] = 1; val[3][2] = 1; val[3][3] = 1;
	  break;

	case 7:
	  val[0][0] = 1; val[0][1] = 1; val[0][2] = 1; val[0][3] = 1;
	  val[1][0] = 1; val[1][1] = 1; val[1][2] = 1; val[1][3] = 1;
	  val[2][0] = 1; val[2][1] = 1; val[2][2] = 1; val[2][3] = 1;
	  val[3][0] = 1; val[3][1] = 1; val[3][2] = 1; val[3][3] = 1;
	  break;

	case 8:
	  val[0][0] = 1; val[0][1] = 1; val[0][2] = 1; val[0][3] = 1;
	  val[1][0] = 1; val[1][1] = 1; val[1][2] = 1; val[1][3] = 1;
	  val[2][0] = 1; val[2][1] = 1; val[2][2] = 1; val[2][3] = 1;
	  val[3][0] = 1; val[3][1] = 1; val[3][2] = 1; val[3][3] = 1;
	  break;
  }
}

void mino::rotate() {
    
}

void mino::print() {
  for(int y = 0; y < 4; y++) {
	for(int x = 0; x < 4; x++) {
	  std::cout << val[y][x];
	}

	std::cout << val[y][3] << std::endl;
  }  
}

mino::~mino() {

}

/**/
int main() {
  mino* m = new mino(0);
  m->print();

  println("");

  m = new mino(1);
  m->print();

  return 0;
}
/**/
