#pragma once

#include "Tuple.h"
#include <set>

class Relation {

 private:

  string name;
  Scheme scheme;
  set<Tuple> tuples;

 public:


  Relation(const string& name, const Scheme& scheme)
    : name(name), scheme(scheme) { }

    Relation()
    {}


  void addTuple(const Tuple& tuple) {
    tuples.insert(tuple);
  }

  string toString() const {
    stringstream out;
    for (auto& tuple : tuples)
      out << tuple.toString(scheme) << endl;
    return out.str();
  }

  Relation select(int index, const string& value) const {
    Relation result(name, scheme);
    for (auto& tuple : tuples)
      if (tuple.at(index) == value)
      result.addTuple(tuple);
    return result;
  }


  Relation select(unsigned int index1, unsigned int index2) {
    return Relation();
  }

  Relation project(vector<unsigned int> colsToKeep) {
    return Relation();
  }

  Relation rename(vector<string> newnames) {
    return Relation();
  }

  unsigned int size() {
    return tuples.size();
  }

  string getName() {
    return name;
  }

  void setScheme(Scheme s) {
    scheme = s;
  }

  void setName(string n) {
    name = n;
  }




};
