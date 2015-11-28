#include<SDL.h>
#include<chip8.h>
#include<iostream>

int main(int argc, char *argv[]){
	if(argc<2){
		std::cout <<"USAGE chip8 game.rom"<<std::endl;	
		return 0;
	}
	chip8 CHIP8("asdada");
}
