#include <iostream>

#include "Parser.h"
#include "Interpreter.h"

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



  Parser p = Parser(myTokens);

  p.removeComment();

  p.datalogProgram();

  Interpreter i = Interpreter(p.getDataLog());

  i.run();

  cout << i.getDataBase().toString();

  return 0;
}

// int main() {

//   vector<string> names = { "ID", "Name", "Major" };

//   Scheme scheme(names);

//   Relation relation("student", scheme);

//   vector<string> values[] = {
//     {"'42'", "'Ann'", "'CS'"},
//     {"'32'", "'Bob'", "'CS'"},
//     {"'64'", "'Ned'", "'EE'"},
//     {"'16'", "'Jim'", "'EE'"},
//   };

//   for (auto& value : values) {
//     Tuple tuple(value);
//     cout << tuple.toString(scheme) << endl;
//     relation.addTuple(tuple);
//   }

//   cout << "relation:" << endl;
//   cout << relation.toString();

//   Relation result = relation.select(2, "'CS'");

//   cout << "select Major='CS' result:" << endl;
//   cout << result.toString();

// }

