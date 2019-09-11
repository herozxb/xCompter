My 16 bits computer

Uses
* In Bus class you can change the memory's value, and input your program
* 0x0000 is the code starting point
* 0x8000 is the data starting point
* you can program your own algorithm by the ASM command:

* 1. NOP(do nothing)
* 2. LDA() #did not debug
* 3. ADD 0x0F (add register A and register B and put the result in register A )
* 4. SUB 0x0F (sub register A and register B and put the result in register A )
* 5. STA 0x03 (store register A, in the 0x8003 address)
* 6. LDI 0x03 (load data in address 0x8003 into register A)
* 7. JMP 0x07 (jump to the address 0x0007)
* 8. JC  0x07 (jump to the address 0x0007, if the carry (C) is 1 )
* 9. JZ  0x07 (jump to the address 0x0007, if the zero (Z) is 1 )
* 10. OUT (output the result of the register A)
* 11. HLT (stop) #did not debug

* I think these command make the computer Turing Complete

