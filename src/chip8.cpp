#include<chip8.h>
/*
	TODO
	file I/O
	SDL setup/destroy
	SDL keyboard input
	SDL draw
	decoder
*/
chip8::chip8(const std::string &file){
	init();	
	read(file);
	run();
}
void chip8::init(){	
	if(SDL_Init(SDL_INIT_VIDEO) == -1){
		std::cout<<"SDL Error"<<std::endl;
	}
	reset();
	PC = 0x200;
	Delay_timer = 0;
	Sound_timer = 0;
	Index = 0;
	display = SDL_CreateRGBSurface(0,10,10,32,0,0,0,0);
	SDL_FillRect(display, NULL, SDL_MapRGB(display->format, 255, 255, 255));
}
void chip8::read(const std::string &file){
	// Read file into Memory starting from 0x200
	//Check if file will fit in Memory
}
void chip8::reset(){
	//TODO look into std::fill
	memset(Reg, 0, sizeof(Reg)); 
	memset(Memory, 0, sizeof(Memory));
	memset(displayBuffer, 0, sizeof(displayBuffer));
	_stack = std::stack<unsigned char>();
	//load charset
	for(int i=0;i<80;i++){
		Memory[i] = charset[i];
	}
}
void chip8::run(){
	while(state){ // state will be modified by cycle()
		// Get keyboard input
		cycle();
		render();
	}

}
void chip8::cycle(){
		unsigned char opcode = Memory[PC]; 	//First 8bits	
		opcode = opcode<<8; 			// shift left by 8bits
		opcode = opcode | Memory[PC+1]; 	//Get last 8bits
		PC+=2;
		decode(opcode);
		//TODO implement timers
}

void chip8::decode(int opcode){
	switch(opcode>>12){
		case 0: 
			switch(opcode & 0xFF){ 
				//Get last 8bits	
				case 0xEE:
					//0x00EE return from subroutine call. 
					PC = _stack.pop();
					break;
				case 0xE0:
					//0x00E0 clear display
					memset(displayBuffer, 0, sizeof(displayBuffer));
					break;			
			}
			break;
		case 1:
			// 0x1nnn Jump to nnn
			PC = opcode & 0x0FFF;
			break;
		case 2:
			// 0x2nnn Call subroutine at nnn.
			_stack.push(PC);
			PC = opcode & 0x0FFF;
			break;
	}
}

void chip8::render(){

}
