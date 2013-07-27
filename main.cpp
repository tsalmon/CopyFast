#include <iostream>
#include "CopyFast.h"
#include "main.h"
using namespace std;

void help()
{
  cout << "cf <filename 1> [<l1> <l2>] <filename 2> <l3> " << endl;
}

int main(int nbargs, char * args[])
{
  if(nbargs == 6)
    {
      file_copy(args[1], args[2], args[3], args[4], args[5]);
    }
  else if(nbargs == 4)// all origin file
    {
      //file_copy(args[1], "0", "" /*EoF*/, args[2], args[3]); 
    }
  else
    {
      help();
    }
}
