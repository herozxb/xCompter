#include "Bus.h"
#include <stdio.h>
#include <unistd.h>



Bus::Bus(CPU cpu_)
{
  cpu = &cpu_;
	// Connect CPU to communication bus
	cpu->ConnectBus(this);
	// Clear RAM contents, just in case :P
	for (auto &i : ram) i = 0x0000;
	
	
	/***********************************************************
	0: LDI 0x03
	1: STA 0x0F
	2: LDI 0x00
	3: ADD 0x0F
	4: OUT 
	5: JMP 0x03
	***********************************************************/
	
	/*
	//Instruction from 0x0000
	// 0
	ram[0x0000] = 0x0503;
	printf("ram[0x0000] is = %hx \n", ram[0x0000]);	
	// 1
	ram[0x0001] = 0x040F; 
	printf("ram[0x0001] is = %hx \n", ram[0x0001]);	
	// 2
	ram[0x0002] = 0x0500; 
	printf("ram[0x0002] is = %hx \n", ram[0x0002]);	
	// 3
	ram[0x0003] = 0x020F; 
	printf("ram[0x0003] is = %hx \n", ram[0x0003]);	
	// 4
	ram[0x0004] = 0x0E00; 
	printf("ram[0x0004] is = %hx \n", ram[0x0004]);	
	// 5
	ram[0x0005] = 0x0603; 
	printf("ram[0x0005] is = %hx \n", ram[0x0005]);	
	
	*/
	
	/***********************************************************
	0x8000 0x01
	0x8001 0x02
	0x8002 0x03
	0x8003 0x04
	0x8004 0x05
	0x800F 0x0A
	***********************************************************/
	
	//Data from 0x8000
  ram[0x8000] = 0x0001; 
	printf("ram[0x8000] is = %hx \n", ram[0x8000]);	
	ram[0x8001] = 0x0002; 
	printf("ram[0x8001] is = %hx \n", ram[0x8001]);	
  ram[0x8002] = 0x0003; 
	printf("ram[0x8002] is = %hx \n", ram[0x8002]);	
	ram[0x8003] = 0x0004;
	printf("ram[0x8003] is = %hx \n", ram[0x8003]);	
	ram[0x8004] = 0x0005;
	printf("ram[0x8004] is = %hx \n", ram[0x8004]);	
	
	ram[0x800F] = 0x2710;
	printf("ram[0x800F] is = %hx \n", ram[0x800F]);	
	
	
  /***********************************************************
	0: OUT 
	1: ADD 0x0F
	2: JC  0x04
	3: JMP 0x00
	4: SUB 0x0F 
	5: OUT
	6: JZ  0x00
	7: JMP 0x04
	***********************************************************/
	
		//Instruction from 0x0000
	// 0
	ram[0x0000] = 0x0E00;
	printf("ram[0x0000] is = %hx \n", ram[0x0000]);	
	// 1
	ram[0x0001] = 0x020F; 
	printf("ram[0x0001] is = %hx \n", ram[0x0001]);	
	// 2
	ram[0x0002] = 0x0704; 
	printf("ram[0x0002] is = %hx \n", ram[0x0002]);	
	// 3
	ram[0x0003] = 0x0600; 
	printf("ram[0x0003] is = %hx \n", ram[0x0003]);	
	// 4
	ram[0x0004] = 0x030F; 
	printf("ram[0x0004] is = %hx \n", ram[0x0004]);	
	// 5
	ram[0x0005] = 0x0E00; 
	printf("ram[0x0005] is = %hx \n", ram[0x0005]);	
	// 6
	ram[0x0006] = 0x0800; 
	printf("ram[0x0004] is = %hx \n", ram[0x0004]);	
	// 7
	ram[0x0007] = 0x0604; 
	printf("ram[0x0005] is = %hx \n", ram[0x0005]);	
	
}


Bus::~Bus()
{
}

void Bus::write(uint16_t addr, uint16_t data)
{
	if (addr >= 0x0000 && addr <= 0xFFFF)
		ram[addr] = data;
}

uint16_t Bus::read(uint16_t addr, bool bReadOnly)
{

	if (addr >= 0x0000 && addr <= 0xFFFF)
	{
	  printf("I am here and addr is = %hx \n", addr);
	  printf("I am here and ram[addr] is = = %hx \n", ram[addr]);
		return ram[addr];
	}
	else
	{
	  return 0x0000;
	}
}
