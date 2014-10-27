#include <iostream>
#include<"chip8.cpp">
using namespace std;
// opcodes aka instructions
// internal cpu memeory = register
/*  main loop:
                fetch instruction
                 decode instruction
                 execute instruction

*/
int main() {
    chip8 chip;
    chip.reset();
    chip.readfile("~/PONG");
    chip.reset();
    //TODO Ask for file name
    for(int i=0;i<4096;i+= sizeof(BYTE))
    {
        std::cout<< chip.memory[i];
    }
    return 0;
}

void disassemble(uint8_t *buffer, int pc) {
    uint8_t *code = &buffer[pc];                //gets code stored in the buffer at the current programme counter
    uint8_t first4bits = code[0] >> 4;

}
