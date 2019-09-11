#ifndef BUS_H
#define BUS_H
#pragma once
#include <stdio.h>
#include <cstdint>
#include <array>
#include "CPU.h"

class CPU;

class Bus
{
public:
	Bus(CPU cpu_);
	~Bus();

public: // Devices on bus
	CPU *cpu;	

	// Fake RAM for this part of the series
	std::array<uint16_t, 64 * 1024> ram;


public: // Bus Read & Write
	void write(uint16_t addr, uint16_t data);
	uint16_t read(uint16_t addr, bool bReadOnly = false);
};
#endif
