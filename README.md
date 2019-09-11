My 16 bits computer

Uses
* In Bus class you can change the memory's value, and input your program
* 0x0000 is the code starting point
* 0x0000 is the data starting point
* you can program your own algorithm by the ASM command:

* NOP(do nothing)
* LDA() #did not debug
* ADD 0x0F (add register A and register B and put the result in register A )
* SUB 0x0F (sub register A and register B and put the result in register A )
* STA 0x03 (store register A, in the 0x8003 address)
* LDI 0x03 (load data in address 0x8003 into register A)
* JMP 0x07 (jump to the address 0x0007)
* JC  0x07 (jump to the address 0x0007, if the carry (C) is 1 )
* JZ  0x07 (jump to the address 0x0007, if the zero (Z) is 1 )
* OUT (output the result of the register A)
* HLT (stop) #did not debug

