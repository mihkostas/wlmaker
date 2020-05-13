#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void CreateTable(char ***table,int,int);

int main( int argc, char *argv[] ) {
	FILE *fp,*fpout;
	int i,j,n;
	char **strs;
	char buff[30];
	
	if(!strcmp(argv[1],"-help")){
	 printf("wlmaker <filename> <lines>\nAuto lines max number are 130 and less");
	 exit(2);
	}
	
	if(argv[2] == NULL){n=130;}else{n= atoi(argv[2])+1;}
	
	CreateTable(&strs,n,30);
	
	fp = fopen(argv[1],"r");
	if(fp==NULL){printf("Error: file does not exist or is NULL\n");exit(2);}
	
	fpout = fopen("wordlist_out.txt","w");
	if(fpout==NULL){printf("Error: output file has not been created");exit(2);}
	
	for(i=0;!feof(fp);i++){
		
		fscanf(fp,"%s",buff);
	    strcpy(strs[i], buff);
	    
	}
    n = i;
	
	for(i=0;i<n;i++){fprintf(fpout,"%s\n",strs[i]);}
	
	for(i=0;i<n;i++){
		
		for(j=0;j<n;j++){
			fprintf(fpout,"%s%s\n",strs[i],strs[j]);
			
			}
	 
		
	}
	
	
	
	fclose(fp);
	fclose(fpout);
	free(strs);
	printf("The file wordlist_out.txt has been created successfully");
	return 0;
	
}


void CreateTable(char ***table,int h,int w){
	int i;
	*table = (char**)malloc(h*sizeof(char*));
	
	for(i=0;i<h;i++){
	  *(*table+i) = (char*)malloc(w*sizeof(char));
	}	
	
	
	
}
