#include <stdio.h>
#include <stdlib.h>
#include "srtf.h"

int main(int c , char **arg)
{
    int x , i ;
    if( c == 2)
    {
	x = atoi(arg[1]);
	Process **tab = malloc(sizeof(Process*) *x) ;

	if(tab != NULL)
	{
	    for(i = 0 ; i < x ; i++)
		tab[i] = scan_process(i+1) ;

	    srtf(tab , x) ;
	    printf("\n") ;

	    print(tab , x) ;
	}

	free(tab) ;
    }

    else
	printf("\n Usage : Entrez le nombre de processus en argument lors de l'exécution\n") ;

    return 0 ;
}
