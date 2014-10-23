

typedef unsigned char BYTE;
typedef unsigned short int WORD;

int main() {
    BYTE memory[4096];                  //4 KB memory
    BYTE v[16];                         //16 registers
    std::stack my_stack[16];            //stack
    WORD pc;                            // programme counter
    WORD R_I;                           // Address register I
    BYTE display[64][32];               // Display
    BYTE opcode;                        // current opcode
    reset();
    //TODO Ask for file name
    readfile("");

}

// 0 to 1fff is for the interpreter.
// the game is stored in 0x200
void reset() {
    R_I = 0x0;
    pc = 0x0;
    memset(v, 0, sizeof(v));
    clearscreen();
}
// clears the screen
void clearscreen()
{
    memset(display,0, sizeof(display));
}
void readfile(String file)
{
    // Read file
    FILE *in;
    in = fopen( file,"rb");
    fread( &memory[0x200], 0xfff, 1, in);         // reading into memory
    fclose(in);
}
WORD GetNextOpcode( )
{
    //opcode is 16 bits. Since memory is 8 bits, we shift it to the right by 8 bits and OR it with the next opcode
    WORD code = 0 ;
    code = memory[pc];                              //get the first opcode
    code <<= 8 ;                                    //shift the first opcode 8 bits to the  left.
    code |= memory[pc+1] ;                          //get the result by ORing current value of code with next opcode.
    pc+=2 ;
    return code;
}
//emulates one cycle.
int emu() {
    pc = 0x200;
    opcode = memory[pc] << 8 | memory[pc + 1];  // get the opcode from memory
    switch (opcode) {

    }
}