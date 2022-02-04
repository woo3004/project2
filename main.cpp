#include <iostream>

#include "Scanner.h"
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

  for(unsigned i = 0; i < myTokens.size(); i++) {
    cout << myTokens.at(i).toString() << endl;
  }

  cout << "Total Tokens = " << s.GetTokenNum() << endl;

  Parser p = Parser(myTokens);

  cout << endl << typeName(p.tokenType()) << endl;

  return 0;
}

// int main() {

//   vector<Token> tokens = {
//     Token(COMMA,",",2),
//     Token(ID,"Ted",2),
//     Token(COMMA,",",2),
//     Token(ID,"Zed",2),
//     Token(RIGHT_PAREN,")",2),
//   };

//   Parser p = Parser(tokens);
//   p.idList();

// }

