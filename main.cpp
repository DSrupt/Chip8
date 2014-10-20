#include <iostream>

using namespace std;
// opcodes aka instructions
// internal cpu memeory = register
/*  main loop:
                fetch instruction
                 decode instruction
                 execute instruction

*/
int main() {
    return 0;
}

void disassemble(uint8_t *buffer, int pc) {
    uint8_t *code = &buffer[pc];                //gets code stored in the buffer at the current programme counter
    uint8_t first4bits = code[0] >> 4;

}
