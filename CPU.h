#ifndef CPU_H
#define CPU_H
#pragma once
#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <iostream>
#include "Bus.h"

using namespace std;
class Bus;

//16 bits of DATA, and 16 bits of Addresss
class CPU
{
public:
	CPU();
	~CPU();

public:
	uint16_t  sumRegister                = 0x0000;		// Accumulator Register
	uint16_t  ARegister                  = 0x0000;		// X Register
	uint16_t  BRegister                  = 0x0000;		// Y Register
	uint16_t  instructionRegister        = 0x0000;		// instructionRegister Register
	uint16_t  programCounter             = 0x0000;	// Program Counter
	uint16_t  memoryAddressRegister      = 0x0000;	// memoryAddressRegister

	void reset();	// Reset Interrupt - Forces CPU into known state
	void clock();	// Perform one clock cycle's worth of update

	// Link this CPU to a communications bus
	void ConnectBus(Bus *n) { bus = n; }

	bool C = 0;	// Carry Bit
	bool Z = 0;	// Zero
	
private:

	uint16_t  fetched     = 0x0000;   // Represents the working input value to the ALU
	uint16_t  temp        = 0x0000; // A convenience variable used everywhere
	uint16_t  addr_abs    = 0x0000; // All used memory addresses end up in here
	uint16_t  addr_rel    = 0x0000;   // Represents absolute address following a branch
	uint8_t   opcode      = 0x00;   // Is the instruction byte
	uint32_t  clock_count = 0;	   // A global accumulation of the number of clocks

	Bus     *bus = nullptr;
	uint16_t read(uint16_t a);
	void    write(uint16_t a, uint16_t d);

private:
  uint16_t fetch();
  uint16_t NOP();
  uint16_t LDA();
  uint16_t ADD();
  uint16_t SUB();
  uint16_t STA();
  uint16_t LDI();
  uint16_t JMP();
  uint16_t JC();
  uint16_t JZ();
  uint16_t OUT();
  uint16_t HLT();
};

// End of File 

#endif
