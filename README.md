My 16 bits computer

Uses
* In Bus class you can change the memory's value, and input your program
* 0x0000 is the code starting point
* 0x8000 is the data starting point
* you can program your own algorithm by the ASM command:

* 1. NOP(do nothing) ###Debug Down
* 2. LDA()  ###Debug Down
* 3. ADD 0x0F (add register A and register B and put the result in register A,{if register A + register B > 0xFFFF then Carry(C) = 1 } )  ###Debug Down
* 4. SUB 0x0F (sub register A and register B and put the result in register A,{if((ARegister - BRegister) == 0xFFFE) Carry(C) = 0 else Carry(C) = 1 } (this is the Ben Eater's hardware's definition, he define the SUB like this ) )  ###Debug Down
* 5. STA 0x03 (store register A, in the 0x8003 address)  ###Debug Down
* 6. LDI 0x03 (load data in address 0x8003 into register A)  ###Debug Down
* 7. JMP 0x07 (jump to the address 0x0007)  ###Debug Down
* 8. JC  0x07 (jump to the address 0x0007, if the carry (C) is 1 )  ###Debug Down
* 9. JZ  0x07 (jump to the address 0x0007, if the zero (Z) is 1 )  ###Debug Down
* 10. OUT (output the result of the register A)  ###Debug Down
* 11. HLT (stop) #did not debug  ###Debug Down

* I think these command make the computer Turing Complete

