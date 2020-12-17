#ifndef SRTF

#define SRTF
#define EXECUTE 1
#define NOT_EXECUTE 0
#define BLOQUER 2

typedef struct
{
    int id ;
    int AT ;
    int BT ;
    int CT ;
    int TAT ;
    int WT ;
    int RT ;
    int status ;
}Process ;


int short_process(Process **tab , int size , int ct , int copie_BT[]) ;

int search_ct(Process **tab , int size) ;

void srtf(Process **tab , int size) ;

void free_process(Process **tab , int size) ;

void print(Process **tab, int size) ;

Process * scan_process(int id) ;

#endif
