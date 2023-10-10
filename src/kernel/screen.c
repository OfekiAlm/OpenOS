#include "screen.h"

unsigned char *vidmem=(unsigned char *)0xb8000;

unsigned char x=0,y=0;

void screen_clear(){
	int i;
	for(i=0;i<4000;i+=2){
		vidmem[i]=0x20;
		vidmem[i+1]=0x07;
	}
	x=0;
	y=0;
}

void screen_scroll(){
	int i;
	for(i=160;i<4000;i+=2){
		vidmem[i-160]=vidmem[i];
	}
}

void screen_print(char *string){
	int i=0;
	while(string[i]){
		if(y==25){
			screen_scroll();
			y=24;
		}
		if(string[i]>0x1f&&string[i]!=0x7f){
			vidmem[2*(x+y*80)]=string[i];
			x++;
			if(x==80){
				y++;
				x=0;
			}
		}
		else{
			switch(string[i]){
			case 0x08:
				if(x!=0){
					x--;
				}
				break;
			case 0x09:
				x+=4;
				if(x>=80){
					x=0;
					y++;
				}
				break;
			case 0x0a:
				x=0;
				y++;
				break;
			}
		}
		i++;
	}
}
