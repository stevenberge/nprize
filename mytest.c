#include "netflix.h"
#include "basic.h"
#include <stdio.h>
unsigned int movieent[NENTRIES];
unsigned short moviedat[NENTRIES];
int movieidx[NMOVIES][4];
void my_load_bin(char *path, void *data, int len)
{
    FILE *fp;
    lg("Loading %s\n",path);
    fp=fopen(path,"rb");
	if(!fp) {
		lg("Cant open file\n");
		exit(1);
	}
	int t;
    if(len!=(t=fread(data,1,len,fp))) {
		printf("fread length:%d and len:%d\n",t,len);
        lg("Failed to read all data\n");
        exit(1);
    }
    fclose(fp);
}

int main(){
	my_load_bin(movieidx_path,movieidx,sizeof(movieidx));
	my_load_bin(movieent_path,movieent,sizeof(movieent));
	my_load_bin(moviedate_path,moviedat,sizeof(moviedat));
	return 0;
}
