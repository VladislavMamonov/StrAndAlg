#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>

#define MAX_LEVEL 4
const float P = 0.5;

using namespace std;


class skiplist
{
private:
  class snode
  {
  public:
    int value;
    snode **forw;

    snode(int level, int &value)
    {
      forw = new snode * [level + 1];
      memset(forw, 0, sizeof(snode*) * (level + 1));
      this->value = value;
    }

    ~snode()
    {
      delete [] forw;
    }
  };

  float frand();
  int random_level();

public:
  snode *header;
  int value;
  int level;

  skiplist()
  {
    header = new snode(MAX_LEVEL, value);
    level = 0;
  }

  ~skiplist()
  {
    delete header;
  }

  void display();

  bool contains(int&);
  void insert_element(int&);
  void delete_element(int&);
};
