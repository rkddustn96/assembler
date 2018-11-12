#include "myas.h"

int is_valid(char *op, char *args)
{
	char Temp_args[256];
	char* S_What, D_What;
	char* Source;
	char* Dest;

	if(op != "mov")
		return 0;

	strcpy(Temp_args, args);
	Source = strtok(Temp_args,',');
	Dest = strtok(Temp_args,'\n');

	S_What = Argm_What(Source);	
	D_What = Argm_What(Dest);

	if(strcmp(S_What,"mem")&&strcmp(D_What,"mem"))
		return 0;
	else if(strcmp(S_What,"imm")&&strcmp(D_What,"imm"))
		return 0;
	else if(srtcmp(D_what, "imm"))
		return 0;

	return 1;
}
