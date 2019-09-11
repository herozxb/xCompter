#include <iostream>
#include <sstream>

#include "Bus.h"
#include "CPU.h"
using namespace std;


int main()
{
  cout<<"Hello World!"<<endl;
  CPU testCpu;
  Bus nes(testCpu);
  while(1)
  {
    //testCpu.clock();
    nes.cpu->clock();
  }
}
