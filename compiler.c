#include <stdio.h>

#define COMMENT 1 /* 0000 0001 */
/* f |= to on */
/* f &= to off */

int main(){
	int c;
	int prev_c;
	FILE * source;
	
	source = fopen("final.txt", "r");
	
	if(source != NULL){
		while((c = fgetchar()) != EOF){
			if(c == '*' && prev_c == '('){
				flags |= COMMENT;
			}
			
			if(c == ')' && prev_c == '*'){
				flags &= COMMENT;
			}
			
			if(flags & COMMENT){
				prev_c = c;
				continue;
			}
			
			prev_c = c;
		}
	}
}