#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calcul.h"
void getNumber(char* adresse)
{   
    char *token=NULL;
    int class;
    int adr;
    int nbr;
    ask:
    printf("entrez l'adresse ip");
    scanf("%s" , adresse);
    if(!check(adresse))
        goto ask;
    token=strtok(adresse,".");
    class=atoi(adresse);

    while(token!=NULL)
    {   
        
        
        adr=atoi(token);
        if(adr>=255 || adr<0)
        {
            printf("ip invalid\n");
            goto ask;
        }
        token=strtok(NULL,".");
    } 
    condition(class);
}
void condition(int class)
{
    if(class <= 127)
    {
        printf(" class A");

    }
    else if(class <= 191)
    {
        printf("class B");

    }
    else if(class <= 223)
    {
        printf("class C");

    }
    else if(class <= 239)
    {
        printf("class D");

    }
    else if(class <= 255)
    {
        printf("class E");

    }
}
int check(char *adresse)
{   
    int i;
    for(i=0 ; i<strlen(adresse) ; i++)
    {
        if(adresse[i]!='.'&&strchr("0123456789",adresse[i])==NULL)
        {
            return 0;
        }
    }
    return 1;
}
