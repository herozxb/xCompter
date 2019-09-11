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
	
	//*/
	
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

  /*
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
	//*/
	
	/***********************************************************
	Z = X * Y
  CODE:
	0:  LDA 0x20 
	1:  SUB 0x12
	2:  JC  0x06
	3:  LDA 0x13
	4:  OUT  
	5:  HLT
	6:  STA 0x20
	7:  LDA 0x0D
	8:  ADD 0x21
	9:  STA 0x0D
	A:  JMP 0x00
	B:
	
	DATA: 
	C: 1 
	D: product
	20: x
	21: y
	***********************************************************/

  
  //Instruction from 0x0000

	// 0
	ram[0x0000] = 0x0120;
	printf("ram[0x0000] is = %hx \n", ram[0x0000]);	

	// 1
	ram[0x0001] = 0x030C; 
	printf("ram[0x0001] is = %hx \n", ram[0x0001]);	

	// 2
	ram[0x0002] = 0x0706; 
	printf("ram[0x0002] is = %hx \n", ram[0x0002]);	

	// 3
	ram[0x0003] = 0x010D; 
	printf("ram[0x0003] is = %hx \n", ram[0x0003]);	

	// 4
	ram[0x0004] = 0x0E00; 
	printf("ram[0x0004] is = %hx \n", ram[0x0004]);	

	// 5
	ram[0x0005] = 0x0F00; 
	printf("ram[0x0005] is = %hx \n", ram[0x0005]);	

	// 6
	ram[0x0006] = 0x0420; 
	printf("ram[0x0006] is = %hx \n", ram[0x0006]);	

	// 7
	ram[0x0007] = 0x010D; 
	printf("ram[0x0007] is = %hx \n", ram[0x0007]);	
	
	// 8
	ram[0x0008] = 0x0221; 
	printf("ram[0x0008] is = %hx \n", ram[0x0008]);	

	// 9
	ram[0x0009] = 0x040D; 
	printf("ram[0x0009] is = %hx \n", ram[0x0009]);	
	
	// A
	ram[0x000A] = 0x0E00; 
	printf("ram[0x000A] is = %hx \n", ram[0x000A]);	
	
	// B
	ram[0x000B] = 0x0600; 
	printf("ram[0x000B] is = %hx \n", ram[0x000B]);	
	
	
	//DATA
	ram[0x800C] = 0x0001;
	printf("ram[0x800C] is = %hx \n", ram[0x800C]);	
		
	ram[0x800D] = 0x0000;
	printf("ram[0x800D] is = %hx \n", ram[0x800D]);	
	
	ram[0x8020] = 0x0003; //input X
	printf("ram[0x8020] is = %hx \n", ram[0x8020]);	
		
	ram[0x8021] = 0x0002; //input Y
	printf("ram[0x8021] is = %hx \n", ram[0x8021]);	
	//*/
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
