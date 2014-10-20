typedef unsigned char BYTE;
typedef unsigned short int WORD;

int main() {
    BYTE memory[4096];     //memory
    BYTE v[16];                     //registers
    std::vector stack[16];                  //stack
    WORD pc;                         // programme counter
    WORD R_I;
    BYTE display[64][32];
}

// 0 to 1fff is for the interpreter.
// the game is stored in 0x200
void reset() {

}

//emulates one cycle.
int emu() {
    pc = 0x200;
    opcode = memory[pc] << 8 | memory[pc + 1];  // get the opcode from memory
    switch (opcode) {

    }
}