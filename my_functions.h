#include "includes.h"
#ifndef _my_functions_h
#define _my_functions_h
#define yM 29
#define xM 14


///INICIAR
void iniciar(int *screent, volatile int *xit_program);

///FECHAR
void fecha_programa();
volatile int *pxit;

///SISTEMA DE TELAS
enum {TITLESCREEN, MAINMENU, INSTRUCTIONS, RECORDSCREEN, GAMEOVER, DIFICULDADES, EASYSCREEN, MEDIUMSCREEN, HARDSCREEN};
void titlescreen(int *screent, volatile int *xit_program, volatile int *ptroca);
void mainmenu(int *screent, volatile int *xit_program);
void instructions(int *screent, volatile int *xit_program);
void gamescreen(int *screent, volatile int *xit_program);
void recordscreen(int *screent, volatile int *xit_program);
void easyscreen(int *screent, volatile int *xit_program, volatile int *timer, int *PONT, int *clocks, int *lines);
void mediumscreen(int *screent, volatile int *xit_program, volatile int *timer, int *PONT, int *clocks, int *lines);
void hardcreen(int *screent, volatile int *xit_program, volatile int *timer, int *PONT, int *clocks, int *lines);

///MOVIMENTAÇÃO E PONTUAÇÃO
int ValidaMov(int PosX, int PosY,int mat[29][14],int mov);
void att_p(int mat1[29][14],int mat2[29][14]);
void reset_p(int mat1[29][14],int mat2[29][14]);
void de_p(int mat1[29][14],int mat2[29][14],int mat3[7][4][4],int pox,int poy,int d);
void cleanline(int mat[29][14], int *PONT, int *lines);
void gameover(int *screent, int *PONT, volatile int *xit_program);

///BLOCOS
typedef struct
{
    int pos_y;
    int pos_x;
}bloco1;

///ARQUIVO DE TEXTO
typedef struct
{
    char nam[5];
} p;
p m[11];
int vet[11],vet2[11];
FILE *fp;
#endif // _my_functions_h
