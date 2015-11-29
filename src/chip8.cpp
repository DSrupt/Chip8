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
			{ 
				switch(opcode & 0xFF){ 
					//Get last 8bits	
					case 0xEE:
					{
						//00EE return from subroutine call. 
						PC = _stack.pop();
						PC+=2;
					}
					break;
					case 0xE0:
					{
						//00E0 clear display
						memset(displayBuffer, 0, sizeof(displayBuffer));
						PC+=2;
					}
					break;			
				}
			}
			break;
		case 1:
			{
				// 1nnn Jump to nnn
				PC = opcode & 0x0FFF;
				PC+=2;
			}
			break;
		case 2:
			{
				// 2nnn Call subroutine at nnn.
				_stack.push(PC);
				PC = opcode & 0x0FFF;
				PC+=2;
			}
			break;
		case 3:
			{
				// 3xKK Skip next instruction if Vx = kk.
				if(Reg[(opcode>>8)&0xF]==(opcode&&0xFF)){
					PC +=2;
				}
				PC+=2;
			}
			break;
		case 4:
			{
				// 4xKK Skip next instruction if Vx != kk
				if(Reg[(opcode>>8)&0xF]!=(opcode&&0xFF)){
					PC +=2;
				}
				PC+=2;
			}
			break;
		case 5:
			{
				//5xy0 Skip next instruction if Vx = Vy
				if(Reg[opcode>>8 & 0xF] == Reg[opcode>>4 & 0xF]){
					PC +=2;
				}
				PC+=2;
			}
			break;
		case 6:
			{
				// 6xkk Set Vx to kk
				Reg[opcode >>8 & 0xF] = opcode & 0xFF;
				PC+=2;
			}
			break;
		case 7:
			{
				//7xkk Vx = Vx + kk
				Reg[opcode>>8 & 0xF]  = Reg[opcode>>8 & 0xF] + (opcode & 0xFF);
				PC+=2;
			}
			break;
		case 8:
			{
				switch(opcode & 0xF){
					int x = Reg[opcode>>8 & 0xF];
					int y = Reg[opcode>>4 & 0xF];
					case 1:
						{
							//Vx=Vy
							Reg[x] = Reg[y];	
							PC+=2;
						}
						break;
					case 2:
						{
							//Set Vx = Vx OR Vy
							Reg[x] = Reg[x] | Reg[y];
							PC+=2;
						}
						break;
					case 3:
						{
							//Set Vx = Vx XOR Vy
							Reg[x] = Reg[x] ^ Reg[y];
							PC+=2;
						}
						break;
					case 4:
						{
							//Set Vx = Vx + Vy, set VF = carry.
							if(Reg[x]+Reg[y] > 255){
								Reg[0xF] = 1;
							}
							else{
								Reg[0xF] = 0;
							}
							Reg[x] = Reg[x] + Reg[y];
							Reg[x] = Reg[x] & 0xFF;
							PC+=2;
						}
						break;
					case 5:
						{
							//Set Vx = Vx - Vy, set VF = NOT borrow
							if(Reg[x]>Reg[y]){
								Reg[0xF] = 1;
							}
							else{
								Reg[0xF] = 0;
							}
							Reg[x] = Reg[x] - Reg[y];
							PC+=2;
						}
						break;
					case 6:
						{
							if(Reg[x] & 0x1 = 1){
								Reg[0xF] = 1;
							}
							else{
								Reg[0xF] = 0;
							}
							Reg[x] = Reg[x] >> 1;
							PC+=2;
						}
						break;
					case 7:
						{
							if(Reg[y] > Reg[x]){
								Reg[0xF] = 1;
							}
							else{
								Reg[0xF] = 0;
							}
							Reg[x] = Reg[y] - Reg[x];
							PC+=2;
						}
						break;
					case 0xE:
						{
							if(Reg[x] & 0x80){
								Reg[0xF] = 1;
							}
							else{
								Reg[0xF] = 0;
							}
							Reg[x] *=2;
							PC+=2;
						}
						break;	
				}
			}
			break;
		case 9:
			{
				int x = Reg[opcode>>8 & 0xF];
				int y = Reg[opcode>>4 & 0xF];
				if(Reg[x] != Reg[y]){
					PC+=2;
				}
				PC+=2;
			}
			break;
		case 0xA:
			{
				Index = opcode & 0xFFF;
				PC+=2;
			}
			break;
		case 0xB:
			{
				PCv = (opcode & 0xFFF) + Reg[0];
				PC+=2;
			}
			break;
		case 0xC:
			{
				Reg[x] = (rand() + 255) & (opcode & 0xFF);			
				PC+=2;
			}
			break;
		case 0xD:
			{
				PC+=2;
			}
			break;
		case E:
			{
				PC+=2;
			}
			break;
		case F:
			{
				PC+=2;
			}
			break;
		default:

	}
}

void chip8::render(){

}
