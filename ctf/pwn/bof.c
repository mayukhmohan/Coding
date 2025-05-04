#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void func(int key){
	char overflowme[32];
	printf("overflow me : ");
	gets(overflowme);	// smash me!
	if(key == 0xcafebabe){
		system("/bin/sh");
	}
	else{
		printf("Nah..\n");
	}
	printf("%x %s\n", key, overflowme);
}
int main(int argc, char* argv[]){
	func(0xdeadbeef);
	return 0;
}
