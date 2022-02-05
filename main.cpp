#include <iostream>

#include "Parser.h"

int main(int argc, char* argv[]) {

  vector<Token> myTokens;
  
  string fileName = argv[1];
  
  Token t;

  Scanner s = Scanner(s.ReadFile(fileName));

  while(!(t.checkEnd())) {
    // cout << "size: " << s.GetSize() << endl;
    t = s.scanToken();
    // cout << t.toString() << endl;
    myTokens.push_back(t);

  }

  // for(unsigned i = 0; i < myTokens.size(); i++) {
  //   cout << myTokens.at(i).toString() << endl;
  // }

  // cout << "Total Tokens = " << s.GetTokenNum() << endl << endl;

  Parser p = Parser(myTokens);

  p.removeComment();

  p.datalogProgram();

  return 0;
}
