#include<chip8.h>
/*
	TODO
	file I/O
	SDL setup/destroy
	SDL keyboard input
	SDL draw
	decoder
*/
chip8::chip8(){
	init();	
}
chip8::init(){	
	reset();
	PC = 0x200;
	Delay_timer = 0;
	Sound_timer = 0;
	Index = 0;
}
chip8::reset(){
	//TODO look into std::fill
	memset(Reg, 0, sizeof(Reg)); 
	memset(Memory, 0, sizeof(Memory));
	memset(display, 0, sizeof(display));
	_stack = std::stacki<unsigned char>();
	//load charset
	for(int i=0;i<80;i++){
		Memory[i] = charset[i];
	}
}
chip8::cycle(){

}
