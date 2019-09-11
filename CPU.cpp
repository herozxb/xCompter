#include "CPU.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

CPU::CPU()
{
	reset();
}

CPU::~CPU()
{
	// Destructor - has nothing to do
}


void CPU::reset()
{
	programCounter        = 0x0000;
	sumRegister           = 0x0000;
	ARegister             = 0x0000;
	BRegister             = 0x0000;
	instructionRegister   = 0x0000;
	memoryAddressRegister = 0x0000;
}



// Perform one clock cycles worth of emulation
void CPU::clock()
{
  temp = read(programCounter);
  opcode =(temp >> 8) & 0xff;
  printf("I am here and opcode is = %x \n", opcode);
  printf("I am here and programCounter = %x \n", programCounter);
    
  switch (opcode)
  {
    case 0x00:
        cout<<"I am here and NOP() "<<endl; 
        NOP();
        break;
    case 0x01: 
        cout<<"I am here and LDA() "<<endl; 
        LDA();
        break;
    case 0x02: 
        cout<<"I am here and ADD() "<<endl; 
        ADD(); //DONE
        break;
    case 0x03:
        cout<<"I am here and SUB() "<<endl; 
        SUB(); //DONE
        break;
    case 0x04:
        cout<<"I am here and STA() "<<endl; 
        STA(); //DONE
        break;
    case 0x05:
        cout<<"I am here and LDI() "<<endl; 
        LDI(); //DONE
        break;
    case 0x06:
        cout<<"I am here and JMP() "<<endl; 
        JMP(); //DONE
        break;
    case 0x07:
        cout<<"I am here and JC() "<<endl; 
        JC();  //DONE
        break;
    case 0x08: 
        cout<<"I am here and JZ() "<<endl; 
        JZ();  //DONE
        break;
    case 0x0E:
        cout<<"I am here and OUT() "<<endl; 
        OUT(); //DONE
        break;
    case 0x0F:
        cout<<"I am here and HLT() "<<endl; 
        HLT(); 
        break;
    default:
        break; 
  }
  
  sleep(2);
  cout<<"================================================================"<<endl;
  
  // Increment global clock count - This is actually unused unless logging is enabled
  // but I've kept it in because its a handy watch variable for debugging
  clock_count++;

}

///////////////////////////////////////////////////////////////////////////////
// BUS CONNECTIVITY

// Reads an 8-bit byte from the bus, located at the specified 16-bit address
uint16_t CPU::read(uint16_t a)
{
	// In normal operation "read only" is set to false. This may seem odd. Some
	// devices on the bus may change state when they are read from, and this 
	// is intentional under normal circumstances. However the disassembler will
	// want to read the data at an address without changing the state of the
	// devices on the bus
	
    printf("I am here and Function read( uint16_t address )'s address is =  %x \n", a);
	return bus->read(a, false);
}

// Writes a byte to the bus at the specified address
void CPU::write(uint16_t a, uint16_t d)
{
	bus->write(a, d);
}

/*
	uint16_t  sumRegister                = 0x0000;		// Accumulator Register
	uint16_t  ARegister                  = 0x0000;		// X Register
	uint16_t  BRegister                  = 0x0000;		// Y Register
	uint16_t  programCounter             = 0x0000;	    // Program Counter
	uint16_t  memoryAddressRegister      = 0x0000;	    // Program Counter
	uint16_t  instructionRegister        = 0x0000;		// Status Register
//*/


uint16_t CPU::NOP()
{
  //All the actions need the following instruction
  memoryAddressRegister = programCounter;
  instructionRegister   = read(memoryAddressRegister);
  programCounter++;
    
  return 0;
}
uint16_t CPU::LDA()
{
  //All the actions need the following instruction
  memoryAddressRegister = programCounter;
  instructionRegister   = read(memoryAddressRegister);
  programCounter++;
  
  //make the function
  memoryAddressRegister = 0x8000 | ( instructionRegister & 0x00ff);  //0x80 store the data
  ARegister = read(memoryAddressRegister);

  return 0;
}
uint16_t CPU::ADD()
{
  //All the actions need the following instruction
  memoryAddressRegister = programCounter;
	//printf("memoryAddressRegister is = %hx \n", memoryAddressRegister);
  instructionRegister   = read(memoryAddressRegister);
	//printf("instructionRegister is = %hx \n", instructionRegister);
  programCounter++;
  
  //make the function
  memoryAddressRegister = 0x8000 | ( instructionRegister & 0x00ff);  //0x80 store the data 
	//printf("instructionRegister is = %hx \n", memoryAddressRegister);
  BRegister = read(memoryAddressRegister);  
	//printf("ARegister is = %hx \n", ARegister); 
	//printf("BRegister is = %hx \n", BRegister);
  sumRegister = ARegister + BRegister;
	//printf("sumRegister is = %hx \n", sumRegister);
  ARegister = sumRegister;
  
  if((ARegister + BRegister) > 0xffff)
  {
    C = 1;
  }
  else
  {
    C = 0;
  }
  return 0;
}
uint16_t CPU::SUB()
{
  //All the actions need the following instruction
  memoryAddressRegister = programCounter;
  instructionRegister   = read(memoryAddressRegister);
  programCounter++;


  
  //make the function
  memoryAddressRegister = 0x8000 | ( instructionRegister & 0x00ff);  //0x80 store the data 
  BRegister = read(memoryAddressRegister);   
  sumRegister = ARegister - BRegister;
  ARegister = sumRegister;
  
  if((ARegister - BRegister) == 0x0000)
  {
    Z = 1;
  }
  else
  {
    Z = 0;
  }
  
  //printf("BRegister is = %hx \n", BRegister);
  
  if((ARegister - BRegister) == 0xFFFE)
  {
    C = 0;
  }
  else
  {
    C = 1;
  }
  return 0;
}

uint16_t CPU::STA()
{
  //All the actions need the following instruction
  memoryAddressRegister = programCounter;
  instructionRegister   = read(memoryAddressRegister);
  programCounter++;
 
  //make the function
  memoryAddressRegister = 0x8000 | ( instructionRegister & 0x00ff);  //0x80 store the data 
  printf("memoryAddressRegister is = %hx \n", memoryAddressRegister);
  write(memoryAddressRegister,ARegister);
  printf("ARegister is = %hx \n", ARegister);
  return 0;
}
uint16_t CPU::LDI()
{ //All the actions need the following instruction

  memoryAddressRegister = programCounter;
  
  printf("memoryAddressRegister is = %hx \n", memoryAddressRegister);
    
  instructionRegister   = read(memoryAddressRegister);
  
  printf("instructionRegister is = %hx \n", instructionRegister);

  memoryAddressRegister = 0x8000 | ( instructionRegister & 0x00FF );

  instructionRegister   = read(memoryAddressRegister);

  printf("instructionRegister 2 is = %hx \n", instructionRegister);
    
  programCounter++;
  
  //make the function
  ARegister = instructionRegister;
  return 0;
}
uint16_t CPU::JMP()
{ //All the actions need the following instruction
  memoryAddressRegister = programCounter;
	//printf("memoryAddressRegister is = %hx \n", memoryAddressRegister);
  instructionRegister   = read(memoryAddressRegister);
 	//printf("instructionRegister is = %hx \n", instructionRegister);
  programCounter++;
  
  //printf("programCounter is = %hx \n", programCounter);
  
  //make the function
  programCounter = instructionRegister & 0x00ff;
 	//printf("programCounter 2 is = %hx \n", programCounter);
  return 0;
}
uint16_t CPU::JC()
{ //All the actions need the following instruction
  memoryAddressRegister = programCounter;
  instructionRegister   = read(memoryAddressRegister);
  programCounter++;
  
  //make the function
  if( 1 == C )
  {
    cout<<"*********************"<<endl;
    cout<<"The C (Carry) is = "<<C<<endl;
    cout<<"*********************"<<endl;
    programCounter = instructionRegister & 0x00ff ;
    C = 0;
  }
  
  return 0;
}
uint16_t CPU::JZ()
{ //All the actions need the following instruction
  memoryAddressRegister = programCounter;
  instructionRegister   = read(memoryAddressRegister);
  programCounter++;
  
  //make the function
  if( 1 == Z )
  {
    cout<<"********************"<<endl;
    cout<<"The Z (Zero) is = "<<Z<<endl;
    cout<<"********************"<<endl;
    programCounter = instructionRegister & 0x00ff ;
    Z = 0;
  }
  return 0;
}

uint16_t CPU::OUT()
{ //All the actions need the following instruction
  memoryAddressRegister = programCounter;
  instructionRegister   = read(memoryAddressRegister);
  programCounter++;
  
  //make the function
  cout<<"**********************************"<<endl;
  cout<<"The output( A Register ) is = "<<ARegister<<endl;
  cout<<"**********************************"<<endl;
  return 0;
}

uint16_t CPU::HLT()
{ //All the actions need the following instruction
  //memoryAddressRegister = programCounter;
  //instructionRegister   = read(memoryAddressRegister);
  //programCounter++;
  while(1){
    cout<<"HLT"<<endl;
    sleep(10);
  }
  return 0;
}




