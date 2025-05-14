#include<stdio.h>  
#include<setjmp.h>  

jmp_buf ebuf;  

int f2(){
        printf("2");
        longjmp(ebuf,3);
}

int main(){  
	int i;  
	printf("1");  
	i=setjmp(ebuf);  
	if(i==0){  
		f2();  
		printf("This will not be printed.");  
	}
	printf("%d",i);  
	return 0;  
}
