#include <iostream>
#include <sstream>

#include "Bus.h"
#include "CPU.h"
using namespace std;


int main()
{
  cout<<"Hello World!"<<endl;
  CPU cpu;
  Bus bus(cpu);
  while(1)
  {
    bus.cpu->clock();
  }
}
