#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG

char s[100], o[100];
int i, j, ls, tmp;
char stack[100][30], top = 0;

int main()
{
	gets(s);
	ls = strlen(s);
	top = 0;
	for(i=0; i<ls; i++){
		if( s[i] == ' ' )   continue;
		else if( s[i] == '.'  ||  ('0' <= s[i]  &&  s[i] <= '9') ){
			stack[top][0] = ' ';  j = 1; 
			while( s[i] == '.'  ||  ('0' <= s[i]  &&  s[i] <= '9') ){
				stack[top][j ++] = s[i];
				i ++;
			}
			stack[top][j ++] = '\0';  top ++;
		}
		else if( s[i] == '+'  ||  s[i] == '-'){
			if( stack[top - 1][0] == '+' || stack[top - 1][0] == '-' ){
				tmp = strlen(stack[top - 1]);
				for(j=tmp; j>=1; j--){
					stack[top - 1][j + 1] = stack[top - 1][j];
				}
				stack[top - 1][1] = '(';
				stack[top - 1][tmp + 1] = ')';
				stack[top - 1][tmp + 2] = '\0';
			}

			tmp = strlen(stack[top - 2]);
			stack[top - 2][0] = s[i];
			stack[top - 2][ tmp ] = s[i];
			for(j=1; j<=strlen(stack[top - 1]); j++){
				stack[top - 2][ tmp + j ] = stack[top - 1][j];
			}
			top --;
		}
		else if( s[i] == '*'  ||  s[i] == '/'){
			if( stack[top - 2][0] == '+'  ||  stack[top - 2][0] == '-' ){
				tmp = strlen(stack[top - 2]);
				for(j=tmp; j>=1; j--){
					stack[top - 2][j + 1] = stack[top - 2][j];
				}
				stack[top - 2][1] = '(';
				stack[top - 2][tmp + 1] = ')';
				stack[top - 2][tmp + 2] = '\0';
			}
			
			
			if( stack[top - 1][0] != ' ' ){
				tmp = strlen(stack[top - 1]);
				for(j=tmp; j>=1; j--){
					stack[top - 1][j + 1] = stack[top - 1][j];
				}
				stack[top - 1][1] = '(';
				stack[top - 1][tmp + 1] = ')';
				stack[top - 1][tmp + 2] = '\0';
			}

			tmp = strlen(stack[top - 2]);
			stack[top - 2][0] = s[i];
			stack[top - 2][ tmp ] = s[i];
			for(j=1; j<=strlen(stack[top - 1]); j++){
				stack[top - 2][ tmp + j ] = stack[top - 1][j];
			}
			top --;
		}
		else  break;
	}
	
	puts(stack[0]+1);
	//system("pause");
	return 0;
}