#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void){
	
	char name[100]="";
	int hasLastName=0;
	int newword=1;

	printf("Input:");
	fgets(name,sizeof(name),stdin);

	int len=strlen(name);
	   while (len > 0 && (name[len - 1] == '\n' || name[len - 1] == ' ')) {
        name[len - 1] = '\0';
        len--;
    }

    
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == ' ') {
             newword = 1;
        } else {
            if (newword) {
                name[i] = toupper(name[i]);
                if (i > 0) {
                    hasLastName = 1; 
                }
              newword = 0;
            } else {
                name[i] = tolower(name[i]);
            }
        }
    }

    
    if (!hasLastName && len > 0) {
        strcat(name, " N/A");
    }

    printf("Output: %s\n", name);

    return 0;
}

	

