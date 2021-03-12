#include <stdio.h>
#include <string.h>
#include <malloc.h>


void *reorg(char *s, char*ot)
{
    char *otvet= (char*)calloc(strlen(s), sizeof(char));
    int len1,kol,len;
    kol=0;
    len=0;
    int lenstr= strlen(s);
    for (int i=0; i<=lenstr;i++){//strchr
        if ((s[i]==' ')||(s[i]=='\t')||(i==lenstr)){
            if (kol==0) {
                kol++;
                len1=len;
                strncpy(otvet, s, len);
                len=0;
            }
            if ((kol!=0)&&(len1==len)){
                strncpy(otvet+(kol*len1+kol-1),s+(i-len)-1,len+1);
                kol++;
                len=0;
            }
            len=0;
        }
        else
            len++;
    }
    strcpy(ot, otvet);
    free(otvet);
}

int main() {
    char *str;
    char *str1;
    while (scanf(" %m[^\n]", &str) != EOF) {
        printf("Source string: %s\n",str);

        str1=(char*)calloc(strlen(str), sizeof(char));
        if (str1!=NULL) {
            reorg(str, str1);
            printf("Result string: %s \n", str1);
            free(str1);
            free(str);
        }

    }

    return 0;
}

