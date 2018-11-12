#include "myas.h"

int is_valid(char *op, char *args)
{
	char Temp_args[256];
	char* S_What=NULL;
	char* D_What=NULL;
	char* Source=NULL;
	char* Dest=NULL;

	if(!strcpy(op,"mov"))
		return 0;
 
	strcpy(Temp_args, args);
	Source = strtok(Temp_args,",");
	Dest = strtok(NULL,"\n");

	if(Source == NULL || Dest == NULL)
		return 0;

	S_What = Argm_What(Source);	
	D_What = Argm_What(Dest);

	if(!strcmp(S_What,"mem")&&!strcmp(D_What,"mem"))
		return 0;
	else if(!strcmp(S_What,"imm")&&!strcmp(D_What,"imm"))
		return 0;
	else if(!strcmp(D_What, "imm"))
		return 0;

	return 1;
}

char* Argm_What(char* argm){
	
	char* result = NULL;

	if(argm[0]=='%')
		result = "reg";
	else if(argm[0]=='$')
		result = "imm";
	else if((argm[0]=='0' && argm[1]=='x'))
		result = "mem";
	else if(argm[0]=='(' && argm[1]=='%')
		result = "mem";
	else if(argm[0]=='-'&&argm[1]=='0'&&argm[2]=='x')
		result = "mem";

	return result;
}
