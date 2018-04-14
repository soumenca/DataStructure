#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]){
	FILE *fp;
	char fname[15];
    	char ch;
	int word, line, byte, i = 0;
	int tword = 0, tline = 0, tbyte = 0;
	
	if( argc == 1 ) {
      		printf("Write the file name as command line arguments\n");
		exit(0);
   	} 
    	
    	while(argc > 1){
		i++;
		word = 0;
		line = 0;
		byte = 0;
		fp = fopen(argv[i], "r");
    		if (fp == NULL){
        		printf("Cannot open file \n");
        		exit(0);
    		}
    		ch = fgetc(fp);
    		while (ch != EOF){
			byte++;
        		ch = fgetc(fp);
			switch(ch){
				case ' ':
					word++;
					break;
				case '\n':
					line++;
					word++;
					break;
				default:
					break;
			}
    		}
		word--;
		printf("	%d	%d	%d	%s\n", line, word, byte, argv[i]);
    		fclose(fp);
		argc--;
		tword = tword + word;
		tline = tline + line;
		tbyte = tbyte + byte;
	}
	if(i > 1){
		printf("	%d	%d	%d	total\n", tline, tword, tbyte);
	}	
	return 0;
}

