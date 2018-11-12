#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* Argm_What(char* argm){
	
	if(argm[0]=='%')
		return "reg";
	else if(argm[0]=='$')
		return "imm";
	else if((argm[0]=='0' && argm[1]=='x'))
		return "mem";
	else if(argm[0]=='(' && argm[1]=='%')
		return "mem";
}
// complete this header file
