#include <stdio.h>
#include <stdlib.h>
#include "srtf.h"


int search_ct(Process **tab , int size)
{
    int i , ct = tab[0]->AT ;

    for(i = 1 ; i < size ; i++)
	if(tab[i]->AT < ct)
	    ct = tab[i]->AT ;
    return ct ;
}

int short_process(Process **tab , int size , int ct , int copie_BT[])
{
    int i , min_bt  = 100000 , i_min = -1 ;

    for( i = 0 ; i < size ; i++)
	if(tab[i]->status != EXECUTE && tab[i]->AT <= ct && copie_BT[i] < min_bt)
	{
	    min_bt = copie_BT[i] ;
	    i_min = i ;
	}
    return i_min ;

}

void copie_BT(Process **tab , int size , int *copie)
{
    int i ;

    for( i = 0 ; i < size ; i++)
	copie[i] = tab[i]->BT ;
}

 
void srtf(Process **tab , int size)
{
    int i , ct = search_ct(tab , size) , i_sp , i_prec = -1 , copie[size];

    copie_BT(tab , size , copie) ;

    do
    {
	i_sp = short_process(tab , size , ct , copie) ;
	if(i_sp == -1)
	    break ;

	for(i = 0 ; i < size ; i++)
	    if(i != i_sp && tab[i]->status != EXECUTE && ct >= tab[i]->AT)
		tab[i]->WT++ ;
	ct++ ;

	tab[i_sp]->RT = ct - tab[i_sp]->AT ;
	copie[i_sp]-- ;

	if(i_prec >=0 && i_prec != i_sp && tab[i_prec]->status != EXECUTE)
	    tab[i_prec]->status = BLOQUER ;

	i_prec = i_sp ;

	printf("P%d ", tab[i_sp]->id) ;
	printf("->> ") ;
	
	if(copie[i_sp] <= 0)
	{
	    tab[i_sp]->status = EXECUTE ;
	    tab[i_sp]->RT = ct - tab[i_sp]->AT ;
	    tab[i_sp]->CT = ct ;
	    tab[i_sp]->TAT = ct - tab[i_sp]->AT ;
	}

    }while(ct) ;
    printf("Finish\n") ;
}


