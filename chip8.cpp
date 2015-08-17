#include<string.h>
#include<iostream>
#include<stack>
#include<cstdio>
#include "chip8.h"

void chip8::redraw(){
        if(redraw)
        {
            // Redraw the screen.
        }
}

void chip8::reset() {
        R_I = 0x0;
        pc = 0x0;
        memset(v, 0, sizeof(v));
        clearscreen();
    }

void chip8::clearscreen()
    {
        memset(display,0, sizeof(display));
    }

void chip8::readfile(std::string file)
    {
        // Read file
        FILE *in;
        in = std::fopen( file.data(),"rb");
        fread( &memory[0x200], 0xfff, 1, in);           // reading into memory
        fclose(in);
    }

    void chip8::DecodeOpcode(WORD opcode)
    {
        switch (opcode & 0xf000)                        //opcode && 0xf000 gets the first digit of the opcode after "0x"
        {
		// 
		case 1: switch(opcode){
			case 0x00E0: //clear display
					break;
			case 0x00EE: //return from subroutine.
					pc = my_stack.pop();
					break;
			case 
			}
            default: break;
        }
    }

    WORD chip8::GetNextOpcode( )
    {
        //opcode is 16 bits. Since memory is 8 bits, we shift it to the right by 8 bits and OR it with the next opcode
        WORD code = 0 ;
        code = memory[pc];                              //get the first opcode
        code <<= 8 ;                                    //shift the first opcode 8 bits to the  left.
        code |= memory[pc+1] ;                          //get the result by ORing current value of code with next opcode.
        pc+=2 ;
        return code;
    }

    int chip8::emu() {
        pc = 0x200;
        opcode = GetNextOpcode();
        DecodeOpcode(opcode);
        // Redraw Graphics if flag is set
        // check key input 
        return 0;
    }

