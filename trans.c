#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	char* S_What = NULL;
	char* D_What = NULL;
	char* Source = NULL;
	char* Dest = NULL;
	// check syntax 
	if (!is_valid(op, args)) {
		printf("Error: %s %s is not valid\n", op, args);
		strcpy(mcode, "Error");
		return 0;
	}

	if (strcmp(op, "mov")!=0)
		return 0;

	strcpy(args, args);
	Source = strtok(args, ",");
	Dest = strtok(NULL, "\n");

	S_What = Trans_What(Source);
	D_What = Trans_What(Dest);

	if (!strcmp(S_What, "reg") && !strcmp(D_What, "reg"))
		strcpy(mcode, "89");
	else if (!strcmp(S_What, "imm") && !strcmp(D_What, "reg"))
	{
		if (!strcmp(Dest, "%eax"))
			strcpy(mcode, "b8");
		else if (!strcmp(Dest, "%ecx"))
			strcpy(mcode, "b9");
		else if (!strcmp(Dest, "%edx"))
			strcpy(mcode, "ba");
		else if (!strcmp(Dest, "%ebx"))
			strcpy(mcode, "bb");
		else if (!strcmp(Dest, "%esp"))
			strcpy(mcode, "bc");
		else if (!strcmp(Dest, "%ebp"))
			strcpy(mcode, "bd");
		else if (!strcmp(Dest, "%esi"))
			strcpy(mcode, "be");
		else if (!strcmp(Dest, "%edi"))
			strcpy(mcode, "c0");
	}
	else if ((!strcmp(S_What, "mem1"))&& (!strcmp(D_What, "reg")))
		strcpy(mcode, "a1");
	else if ((!(strcmp(S_What, "mem2")) || (!strcmp(S_What, "mem3"))) && !strcmp(D_What, "reg"))
		strcpy(mcode, "8b");
	else if ((!strcmp(S_What, "reg")) && ((!(strcmp(D_What, "mem1")) || (!strcmp(D_What, "mem2")) || (!strcmp(D_What, "mem2")))))
		strcpy(mcode, "a3");

		return 1;
}

char* Trans_What(char* argm) {
	char* result = NULL;

		if (argm[0] == '%')
			result = "reg";
		else if (argm[0] == '$')
			result = "imm";
		else if ((argm[0] == '0' && argm[1] == 'x'))
			result = "mem1";
		else if (argm[0] == '(' && argm[1] == '%')
			result = "mem2";
		else if (argm[0] == '-' && argm[1] == '0' && argm[2] == 'x')
			result = "mem3";

	return result;
}
