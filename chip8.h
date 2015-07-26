/* 
 * File:   chip8.h
 * Author: akhilthampy
 *
 * Created on October 27, 2014, 2:07 PM
 */

#ifndef CHIP8_H
#define	CHIP8_H
typedef unsigned char BYTE;
typedef unsigned short int WORD;

class chip8{
public:
    BYTE memory[4096];                  //4 KB memory
    BYTE v[16];                         //16 registers
    std::stack<BYTE> my_stack;          //stack
    WORD pc;                            // program counter
    WORD R_I;                           // Address register I
    BYTE display[64][32];               // Display
    BYTE opcode;                        // current opcode
    bool redraw;
    
    void Redraw();

    // 0 to 1fff is for the interpreter.
    // the game is stored in 0x200
    void reset();

    // clears the screen
    void clearscreen();

    void readfile(std::string file);

    void DecodeOpcode(WORD opcode);

    WORD GetNextOpcode();

    //emulates one cycle.
    int emu();
};

#endif	/* CHIP8_H */

