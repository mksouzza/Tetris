#include "includes.h"
#include "my_functions.h"

///INICIAR
void iniciar(int *screent, volatile int *xit_program)
{
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    set_window_title("Dragon Tetris");
    pxit=xit_program;
    LOCK_VARIABLE(fecha_programa);
    LOCK_FUNCTION(fecha_programa);
    set_close_button_callback(fecha_programa);
    int i;
    for(i=0; i<11; i++)
    {
        vet2[i]=i;
    }
    for(i=0; i<11; i++)
    {
        m[vet2[i]].nam[0]=NULL;
        m[vet2[i]].nam[1]=NULL;
        m[vet2[i]].nam[2]=NULL;
    }
    *screent = TITLESCREEN;

}

///FECHAR
void fecha_programa()
{
    *pxit=TRUE;
}
END_OF_FUNCTION(fecha_programa)

///SISTEMA DE TELAS
void titlescreen(int *screent, volatile int *xit_program, volatile int *ptroca)
{

    ///VARIÁVEIS
    int ctroca=0;
    int ctroca2=0;
    int exit_screen = FALSE;

    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* title = load_bitmap("Sprites/Title Screen.bmp", NULL);
    BITMAP* title2 = load_bitmap("Sprites/Title2.bmp", NULL);

    ctroca=*ptroca/50;

    ///GAME LOOP

    while(!*xit_program && !exit_screen)
    {
        //INPUT
        troca_title();
        if(ctroca != *ptroca/50)
        {
            if(ctroca2==1) ctroca2=0;
            else ctroca2=1;
            ctroca=*ptroca/50;
        }

        if(ctroca2==1) draw_sprite(buffer, title, 0, 0);

        if(ctroca2==0) draw_sprite(buffer, title2, 0, 0);

        if(key[KEY_ENTER])
        {
            exit_screen = TRUE;
            *screent = MAINMENU;
        }

        if(key[KEY_ESC])
        {
            *xit_program = TRUE;
        }

        //UPDATE


        //DRAW
        draw_sprite(screen, buffer, 0, 0);
        draw_sprite(buffer, title2, 0, 0);

    }

    ///FINALIZAÇÃO
    destroy_bitmap(buffer);
    destroy_bitmap(title);
    destroy_bitmap(title2);

}

void mainmenu(int *screent, volatile int *xit_program)
{

    ///VARIÁVEIS
    int exit_screen = FALSE;
    int muda_tela = 1; //vai até 4.

    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* menu_play = load_bitmap("Sprites/Menu 1 Play.bmp", NULL);
    BITMAP* menu_inst = load_bitmap("Sprites/Menu Instruction.bmp", NULL);
    BITMAP* menu_records = load_bitmap("Sprites/Menu Records.bmp", NULL);
    BITMAP* menu_sair = load_bitmap("Sprites/Menu Sair.bmp", NULL);

    draw_sprite(buffer, menu_play, 0, 0);

    ///SONS


    ///GAME LOOP
    while(!*xit_program && !exit_screen)
    {

        //INPUT

        if(key[KEY_ESC])
        {
            *xit_program = TRUE;
        }

        if(key[KEY_DOWN])
        {
            while(key[KEY_DOWN]) {}
            exit_screen = FALSE;
            muda_tela++;

            switch(muda_tela)
            {
            case 1:
                draw_sprite(buffer, menu_play, 0, 0);
                break;

            case 2:
                draw_sprite(buffer, menu_inst, 0, 0);
                break;

            case 3:
                draw_sprite(buffer, menu_records, 0, 0);
                break;

            case 4:
                draw_sprite(buffer, menu_sair, 0, 0);
                break;

            default:
                if(muda_tela > 4)
                {
                    muda_tela = 1;
                    draw_sprite(buffer, menu_play, 0, 0);
                }

            }

        }

        if(key[KEY_UP])
        {
            while(key[KEY_UP]) {}
            exit_screen = FALSE;
            muda_tela--;

            switch(muda_tela)
            {
            case 1:
                draw_sprite(buffer, menu_play, 0, 0);
                break;

            case 2:
                draw_sprite(buffer, menu_inst, 0, 0);
                break;

            case 3:
                draw_sprite(buffer, menu_records, 0, 0);
                break;

            case 4:
                draw_sprite(buffer, menu_sair, 0, 0);
                break;

            default:
                if(muda_tela < 1)
                {
                    muda_tela = 4;
                    draw_sprite(buffer, menu_sair, 0, 0);
                }

            }

        }


        if(key[KEY_ENTER])
        {
            switch(muda_tela)
            {
            case 1:
                exit_screen = TRUE;
                *screent = DIFICULDADES;
                break;

            case 2:
                exit_screen = TRUE;
                *screent = INSTRUCTIONS;
                break;

            case 3:
                exit_screen = TRUE;
                *screent = RECORDSCREEN;
                break;

            case 4:
                *xit_program = TRUE;
                break;
            }
        }


        //DRAW
        draw_sprite(screen, buffer, 0, 0);

    }


    ///FINALIZAÇÃO
    destroy_bitmap(buffer);
    destroy_bitmap(menu_play);
    destroy_bitmap(menu_inst);
    destroy_bitmap(menu_records);
    destroy_bitmap(menu_sair);

}

void gamescreen(int *screent, volatile int *xit_program)
{
    ///VARIÁVEIS
    int exit_screen = FALSE;
    int muda_tela = 1; //vai até 3.

    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* menu_easy = load_bitmap("Sprites/easy.bmp", NULL);
    BITMAP* menu_medium = load_bitmap("Sprites/medium.bmp", NULL);
    BITMAP* menu_hard = load_bitmap("Sprites/hard.bmp", NULL);

    draw_sprite(buffer, menu_easy, 0, 0);



    ///GAME LOOP
    while(!*xit_program && !exit_screen)
    {

        //INPUT

        if(*screent == DIFICULDADES)
        {
            if(key[KEY_BACKSPACE])
            {
                exit_screen = TRUE;
                *screent = MAINMENU;
            }
        }

        if(key[KEY_ESC])
        {
            *xit_program = TRUE;
        }

        if(key[KEY_DOWN])
        {
            while(key[KEY_DOWN]) {}
            exit_screen = FALSE;
            muda_tela++;

            switch(muda_tela)
            {
            case 1:
                draw_sprite(buffer, menu_easy, 0, 0);
                break;

            case 2:
                draw_sprite(buffer, menu_medium, 0, 0);
                break;

            case 3:
                draw_sprite(buffer, menu_hard, 0, 0);
                break;

            default:
                if(muda_tela > 3)
                {
                    muda_tela = 1;
                    draw_sprite(buffer, menu_easy, 0, 0);
                }

            }

        }

        if(key[KEY_UP])
        {
            while(key[KEY_UP]) {}
            exit_screen = FALSE;
            muda_tela--;

            switch(muda_tela)
            {
            case 1:
                draw_sprite(buffer, menu_easy, 0, 0);
                break;

            case 2:
                draw_sprite(buffer, menu_medium, 0, 0);
                break;

            case 3:
                draw_sprite(buffer, menu_hard, 0, 0);
                break;

            default:
                if(muda_tela < 1)
                {
                    muda_tela = 3;
                    draw_sprite(buffer, menu_hard, 0, 0);
                }

            }

        }


        if(key[KEY_ENTER])
        {
            switch(muda_tela)
            {
            case 1:
                exit_screen = TRUE;
                *screent = EASYSCREEN;
                break;

            case 2:
                exit_screen = TRUE;
                *screent = MEDIUMSCREEN;
                break;

            case 3:
                exit_screen = TRUE;
                *screent = HARDSCREEN;
                break;
            }
        }


        //DRAW
        draw_sprite(screen, buffer, 0, 0);

    }


    ///FINALIZAÇÃO
    destroy_bitmap(buffer);
    destroy_bitmap(menu_easy);
    destroy_bitmap(menu_medium);
    destroy_bitmap(menu_hard);

}

void instructions(int *screent, volatile int *xit_program)
{
    ///VARIÁVEIS
    int exit_screen = FALSE;

    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* instructions = load_bitmap("Sprites/Instructions.bmp", NULL);

    ///GAME LOOP
    while(!*xit_program && !exit_screen)
    {
        //INPUT

        if(key[KEY_ESC])
        {
            *xit_program = TRUE;
        }

        if(*screent == INSTRUCTIONS)
        {
            if(key[KEY_BACKSPACE])
            {
                exit_screen = TRUE;
                *screent = MAINMENU;
            }
        }


        //UPDATE


        //DRAW
        draw_sprite(screen, buffer, 0, 0);
        draw_sprite(buffer, instructions, 0, 0);

    }

    ///FINALIZAÇÃO
    destroy_bitmap(buffer);
    destroy_bitmap(instructions);

}

void recordscreen(int *screent, volatile int *xit_program)
{
    ///VARIÁVEIS
    int exit_screen = FALSE;

    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* rec = load_bitmap("Sprites/cat.bmp", NULL);

    FONT* pixelado1 = load_font("FONTE1.pcx", NULL,NULL);

    lerpt();
    orgpt();
    escpt();
    ///GAME LOOP
    while(!*xit_program && !exit_screen)
    {
        //INPUT

        if(key[KEY_ESC])
        {
            *xit_program = TRUE;
        }
        if(*screent == RECORDSCREEN)
        {
            if(key[KEY_BACKSPACE])
            {
                exit_screen = TRUE;
                *screent = MAINMENU;
            }
        }

        textprintf_ex(buffer,pixelado1,250,80,makecol(255,0,0),-1,"PRIMEIRO: %d %s",vet[0],m[vet2[0]].nam);
        textprintf_ex(buffer,pixelado1,250,110,makecol(255,0,0),-1,"SEGUNDO: %d %s",vet[1],m[vet2[1]].nam);
        textprintf_ex(buffer,pixelado1,250,140,makecol(255,0,0),-1,"TERCEIRO: %d %s",vet[2],m[vet2[2]].nam);
        textprintf_ex(buffer,pixelado1,250,170,makecol(255,0,0),-1,"QUARTO: %d %s",vet[3],m[vet2[3]].nam);
        textprintf_ex(buffer,pixelado1,250,200,makecol(255,0,0),-1,"QUINTO: %d %s",vet[4],m[vet2[4]].nam);
        textprintf_ex(buffer,pixelado1,250,230,makecol(255,0,0),-1,"SEXTO: %d %s",vet[5],m[vet2[5]].nam);
        textprintf_ex(buffer,pixelado1,250,260,makecol(255,0,0),-1,"SETIMO: %d %s",vet[6],m[vet2[6]].nam);
        textprintf_ex(buffer,pixelado1,250,290,makecol(255,0,0),-1,"OITAVO: %d %s",vet[7],m[vet2[7]].nam);
        textprintf_ex(buffer,pixelado1,250,320,makecol(255,0,0),-1,"NONO: %d %s",vet[8],m[vet2[8]].nam);
        textprintf_ex(buffer,pixelado1,250,350,makecol(255,0,0),-1,"DECIMO: %d %s",vet[9],m[vet2[9]].nam);


        //DRAW
        draw_sprite(screen, buffer, 0, 0);
        draw_sprite(buffer, rec, 0, 0);
    }

    ///FINALIZAÇÃO
    destroy_bitmap(buffer);
    destroy_bitmap(rec);

}

///DIFICULDADES
void easyscreen(int *screent, volatile int *xit_program, volatile int *timer, int *PONT, int *clocks, int*lines)
{
    ///VARIÁVEIS
    *lines=0;
    int tempo;
    *clocks=0;
    *PONT=0;
    bloco1 a;
    a.pos_x=5;
    a.pos_y=5;
    int velocidade=2;
    int descer=0;
    int descer2=0;
    int k=1;
    int peca;
    int peca2;
    int exit_screen = FALSE;
    int mat[yM][xM];
    int mat2[yM][xM];
    int i, j;
    int Xp[19][4][4]= {{
            {0,2,0,0},
            {0,2,0,0},
            {0,2,0,0},
            {0,2,0,0}
        },
        {   {0,0,0,0},
            {0,0,0,0},
            {2,2,2,2},
            {0,0,0,0}
        },
        {   {0,2,0,0},
            {0,2,0,0},
            {0,2,2,0},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,0,0,2},
            {0,2,2,2},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,2,2,0},
            {0,0,2,0},
            {0,0,2,0}
        },
        {   {0,0,0,0},
            {0,2,2,2},
            {0,2,0,0},
            {0,0,0,0}
        },
        {   {0,0,2,0},
            {0,0,2,0},
            {0,2,2,0},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,2,0,0},
            {0,2,2,2},
            {0,0,0,0}
        },
        {   {0,2,2,0},
            {0,2,0,0},
            {0,2,0,0},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {2,2,2,0},
            {0,0,2,0},
            {0,0,0,0}
        },
        {   {0,2,0,0},
            {0,2,2,0},
            {0,0,2,0},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,0,2,2},
            {0,2,2,0},
            {0,0,0,0}
        },
        {   {0,0,2,0},
            {0,2,2,0},
            {0,2,0,0},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,2,2,0},
            {0,0,2,2},
            {0,0,0,0}
        },

        {   {0,0,0,0},
            {0,2,2,0},
            {0,2,2,0},
            {0,0,0,0}
        },

        {   {0,0,0,0},
            {0,0,2,0},
            {0,2,2,2},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,0,2,0},
            {0,0,2,2},
            {0,0,2,0}
        },

        {   {0,0,0,0},
            {0,0,0,0},
            {0,2,2,2},
            {0,0,2,0}
        },
        {   {0,0,0,0},
            {0,0,2,0},
            {0,2,2,0},
            {0,0,2,0}
        }
    };
    srand((unsigned) time(NULL));
    peca2 = rand()%19;
    peca=peca2;
    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* bloco = load_bitmap("Sprites/bloco.bmp", NULL);
    BITMAP* game = load_bitmap("Sprites/Game Screen.bmp", NULL);

    ///FONTE
    FONT* pixelado1 = load_font("FONTE1.pcx", NULL,NULL);

    ///GERAR MATRIZ
    for(i=0; i<yM; i++)
    {
        for(j=0; j<xM; j++)
        {
            mat[i][j]=0;
        }
    }
    for(i=0; i<yM; i++)
    {
        mat[i][0]=1;
        mat[i][13]=1;
    }
    for(j=0; j<xM; j++)
    {
        mat[28][j]=1;
    }
    att_p(mat2,mat);
    descer=*timer/velocidade;
    tempo=*clocks/100;
    ///GAME LOOP
    while(!*xit_program && !exit_screen)
    {
        //INPUT
        if(*screent == EASYSCREEN)
        {
            if(key[KEY_BACKSPACE])
            {
                exit_screen = TRUE;
                *screent = DIFICULDADES;
            }
        }

        if(key[KEY_ESC])
        {
            *xit_program = TRUE;
        }
        if(k)
        {
            if(key[KEY_UP])
            {
                while(key[KEY_UP]) {}
                {
                    int h=1;
                    if(peca==1&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        h=0;
                        peca=0;
                    }
                    if(peca==0&&h==1&&ValidaMov(a.pos_x,a.pos_y,mat,3))peca=1;
                    if(peca>1&&peca<6&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        peca++;
                        h=0;
                    }
                    if(peca==6&&h==0&&ValidaMov(a.pos_x,a.pos_y,mat,3)) peca=2;
                    if(peca>5&&peca<10&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        peca++;
                        h=0;
                    }
                    if(peca==10&&h==0&&ValidaMov(a.pos_x,a.pos_y,mat,3)) peca=6;
                    if(peca==10&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        h=0;
                        peca=11;
                    }
                    if(peca==11&&h==1&&ValidaMov(a.pos_x,a.pos_y,mat,3))peca=10;
                    if(peca==12&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        h=0;
                        peca=13;
                    }
                    if(peca==13&&h==1&&ValidaMov(a.pos_x,a.pos_y,mat,3))peca=12;
                    if(peca>14&&peca<19&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        peca++;
                        h=0;
                    }
                    if(peca==19&&h==0&&ValidaMov(a.pos_x,a.pos_y,mat,3)) peca=15;
                }

            }
            if(key[KEY_DOWN])
            {
                if(ValidaMov(a.pos_x,a.pos_y,mat,0)) a.pos_y++;
                else k=0;
            }
            if(key[KEY_RIGHT])
            {
                while(key[KEY_RIGHT]) {}
                if(ValidaMov(a.pos_x,a.pos_y,mat,2)) a.pos_x++;
            }
            if(key[KEY_LEFT])
            {
                while(key[KEY_LEFT]) {}
                if(ValidaMov(a.pos_x,a.pos_y,mat,1)) a.pos_x--;
            }
            if(descer != *timer/velocidade)
            {
                if(descer2==1) descer2=0;
                else descer2=1;
                descer=*timer/velocidade;
            }
            if(descer2==1)
            {
                if(ValidaMov(a.pos_x,a.pos_y,mat,0))
                {
                    a.pos_y++;
                    descer2=0;
                }
                else k=0;
            }
        }
        if(*screent == DIFICULDADES)
        {
            if(key[KEY_BACKSPACE])
            {
                exit_screen = TRUE;
                *screent = MAINMENU;
            }
        }
        //UPDATE
        de_p(mat,mat2,Xp,a.pos_x,a.pos_y,peca);
        if(k==0)
        {
            reset_p(mat,mat2);
            a.pos_x=5;
            a.pos_y=0;
            k=1;
            peca=peca2;
            peca2 = rand()%19;
            cleanline(mat, PONT, lines);
            att_p(mat2,mat);
        }
        //DRAW
        for(i=0; i<yM; i++)
        {
            for(j=0; j<xM; j++)
            {
                if(mat[i][j]!=0) draw_sprite(buffer,bloco,j*21+235,i*21-10);
            }
        }
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                if(Xp[peca2][i][j]!=0) draw_sprite(buffer,bloco,j*21+630,i*21+400);
            }
        }
        if(tempo+2<*clocks/100)
        {
            descer=descer/2;
            tempo=*clocks/100;
        }

        int i=3,j;
        for(j=1; j<12; j++)
        {
            if(mat[5][j]==1)
            {
                exit_screen = TRUE;
                *screent = GAMEOVER;
            }
        }
        textprintf_ex(buffer,pixelado1,650,170,makecol(255,0,0),-1,"%d",*lines);
        textprintf_ex(buffer,pixelado1,110,170,makecol(255,0,0),-1,"%d",*PONT);
        textprintf_ex(buffer,pixelado1,650,70,makecol(255,0,0),-1,"%d",*clocks/100);
        draw_sprite(screen, buffer, 0, 0);
        draw_sprite(buffer, game, 0, 0);
    }

    ///FINALIZAÇÃO
    destroy_bitmap(buffer);
    destroy_bitmap(game);
    destroy_bitmap(bloco);
}

void mediumscreen(int *screent, volatile int *xit_program, volatile int *timer, int *PONT, int *clocks, int*lines)
{
    ///VARIÁVEIS
    *lines=0;
    int tempo;
    *clocks=0;
    *PONT=0;
    bloco1 a;
    a.pos_x=5;
    a.pos_y=5;
    int velocidade=2;
    int descer=0;
    int descer2=0;
    int k=1;
    int peca;
    int peca2;
    int exit_screen = FALSE;
    int mat[yM][xM];
    int mat2[yM][xM];
    int i, j;
    int Xp[19][4][4]= {{
            {0,2,0,0},
            {0,2,0,0},
            {0,2,0,0},
            {0,2,0,0}
        },
        {   {0,0,0,0},
            {0,0,0,0},
            {2,2,2,2},
            {0,0,0,0}
        },
        {   {0,2,0,0},
            {0,2,0,0},
            {0,2,2,0},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,0,0,2},
            {0,2,2,2},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,2,2,0},
            {0,0,2,0},
            {0,0,2,0}
        },
        {   {0,0,0,0},
            {0,2,2,2},
            {0,2,0,0},
            {0,0,0,0}
        },
        {   {0,0,2,0},
            {0,0,2,0},
            {0,2,2,0},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,2,0,0},
            {0,2,2,2},
            {0,0,0,0}
        },
        {   {0,2,2,0},
            {0,2,0,0},
            {0,2,0,0},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {2,2,2,0},
            {0,0,2,0},
            {0,0,0,0}
        },
        {   {0,2,0,0},
            {0,2,2,0},
            {0,0,2,0},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,0,2,2},
            {0,2,2,0},
            {0,0,0,0}
        },
        {   {0,0,2,0},
            {0,2,2,0},
            {0,2,0,0},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,2,2,0},
            {0,0,2,2},
            {0,0,0,0}
        },

        {   {0,0,0,0},
            {0,2,2,0},
            {0,2,2,0},
            {0,0,0,0}
        },

        {   {0,0,0,0},
            {0,0,2,0},
            {0,2,2,2},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,0,2,0},
            {0,0,2,2},
            {0,0,2,0}
        },

        {   {0,0,0,0},
            {0,0,0,0},
            {0,2,2,2},
            {0,0,2,0}
        },
        {   {0,0,0,0},
            {0,0,2,0},
            {0,2,2,0},
            {0,0,2,0}
        }
    };
    srand((unsigned) time(NULL));
    peca2 = rand()%19;
    peca=peca2;
    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* bloco = load_bitmap("Sprites/bloco.bmp", NULL);
    BITMAP* game = load_bitmap("Sprites/Game Screen.bmp", NULL);

    ///FONTE
    FONT* pixelado1 = load_font("FONTE1.pcx", NULL,NULL);

    ///GERAR MATRIZ
    for(i=0; i<yM; i++)
    {
        for(j=0; j<xM; j++)
        {
            mat[i][j]=0;
        }
    }
    for(i=0; i<yM; i++)
    {
        mat[i][0]=1;
        mat[i][13]=1;
    }
    for(j=0; j<xM; j++)
    {
        mat[28][j]=1;
    }
    att_p(mat2,mat);
    descer=*timer/velocidade;
    tempo=*clocks/100;
    ///GAME LOOP
    while(!*xit_program && !exit_screen)
    {
        //INPUT

        if(*screent == MEDIUMSCREEN)
        {
            if(key[KEY_BACKSPACE])
            {
                exit_screen = TRUE;
                *screent = DIFICULDADES;
            }
        }

        if(key[KEY_ESC])
        {
            *xit_program = TRUE;
        }
        if(k)
        {
            if(key[KEY_UP])
            {
                while(key[KEY_UP]) {}
                {
                    int h=1;
                    if(peca==1&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        h=0;
                        peca=0;
                    }
                    if(peca==0&&h==1&&ValidaMov(a.pos_x,a.pos_y,mat,3))peca=1;
                    if(peca>1&&peca<6&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        peca++;
                        h=0;
                    }
                    if(peca==6&&h==0&&ValidaMov(a.pos_x,a.pos_y,mat,3)) peca=2;
                    if(peca>5&&peca<10&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        peca++;
                        h=0;
                    }
                    if(peca==10&&h==0&&ValidaMov(a.pos_x,a.pos_y,mat,3)) peca=6;
                    if(peca==10&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        h=0;
                        peca=11;
                    }
                    if(peca==11&&h==1&&ValidaMov(a.pos_x,a.pos_y,mat,3))peca=10;
                    if(peca==12&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        h=0;
                        peca=13;
                    }
                    if(peca==13&&h==1&&ValidaMov(a.pos_x,a.pos_y,mat,3))peca=12;
                    if(peca>14&&peca<19&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        peca++;
                        h=0;
                    }
                    if(peca==19&&h==0&&ValidaMov(a.pos_x,a.pos_y,mat,3)) peca=15;
                }

            }
            if(key[KEY_DOWN])
            {
                if(ValidaMov(a.pos_x,a.pos_y,mat,0)) a.pos_y++;
                else k=0;
            }
            if(key[KEY_RIGHT])
            {
                while(key[KEY_RIGHT]) {}
                if(ValidaMov(a.pos_x,a.pos_y,mat,2)) a.pos_x++;
            }
            if(key[KEY_LEFT])
            {
                while(key[KEY_LEFT]) {}
                if(ValidaMov(a.pos_x,a.pos_y,mat,1)) a.pos_x--;
            }
            if(descer != *timer/velocidade)
            {
                if(descer2==1) descer2=0;
                else descer2=1;
                descer=*timer/velocidade;
            }
            if(descer2==1)
            {
                if(ValidaMov(a.pos_x,a.pos_y,mat,0))
                {
                    a.pos_y++;
                    descer2=0;
                }
                else k=0;
            }
        }
        if(*screent == DIFICULDADES)
        {
            if(key[KEY_BACKSPACE])
            {
                exit_screen = TRUE;
                *screent = MAINMENU;
            }
        }
        //UPDATE
        de_p(mat,mat2,Xp,a.pos_x,a.pos_y,peca);
        if(k==0)
        {
            reset_p(mat,mat2);
            a.pos_x=5;
            a.pos_y=0;
            k=1;
            peca=peca2;
            peca2 = rand()%19;
            cleanline(mat, PONT, lines);
            att_p(mat2,mat);
        }
        //DRAW
        for(i=0; i<yM; i++)
        {
            for(j=0; j<xM; j++)
            {
                if(mat[i][j]!=0) draw_sprite(buffer,bloco,j*21+235,i*21-10);
            }
        }
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                if(Xp[peca2][i][j]!=0) draw_sprite(buffer,bloco,j*21+630,i*21+400);
            }
        }
        if(tempo+2<*clocks/100)
        {
            descer=descer/2;
            tempo=*clocks/100;
        }

        int i=3,j;
        for(j=1; j<12; j++)
        {
            if(mat[5][j]==1)
            {
                exit_screen = TRUE;
                *screent = GAMEOVER;
            }
        }
        textprintf_ex(buffer,pixelado1,650,170,makecol(255,0,0),-1,"%d",*lines);
        textprintf_ex(buffer,pixelado1,110,170,makecol(255,0,0),-1,"%d",*PONT);
        textprintf_ex(buffer,pixelado1,650,70,makecol(255,0,0),-1,"%d",*clocks/100);
        draw_sprite(screen, buffer, 0, 0);
        draw_sprite(buffer, game, 0, 0);
    }

    ///FINALIZAÇÃO
    destroy_bitmap(buffer);
    destroy_bitmap(game);
    destroy_bitmap(bloco);
}

void hardscreen(int *screent, volatile int *xit_program, volatile int *timer, int *PONT, int *clocks, int *lines)
{
    ///VARIÁVEIS
    *lines=0;
    int tempo;
    *clocks=0;
    *PONT=0;
    bloco1 a;
    a.pos_x=5;
    a.pos_y=5;
    int velocidade=1;
    int descer=0;
    int descer2=0;
    int k=1;
    int peca;
    int peca2;
    int exit_screen = FALSE;
    int mat[yM][xM];
    int mat2[yM][xM];
    int i, j;
    int Xp[19][4][4]= {{
            {0,2,0,0},
            {0,2,0,0},
            {0,2,0,0},
            {0,2,0,0}
        },
        {   {0,0,0,0},
            {0,0,0,0},
            {2,2,2,2},
            {0,0,0,0}
        },
        {   {0,2,0,0},
            {0,2,0,0},
            {0,2,2,0},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,0,0,2},
            {0,2,2,2},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,2,2,0},
            {0,0,2,0},
            {0,0,2,0}
        },
        {   {0,0,0,0},
            {0,2,2,2},
            {0,2,0,0},
            {0,0,0,0}
        },
        {   {0,0,2,0},
            {0,0,2,0},
            {0,2,2,0},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,2,0,0},
            {0,2,2,2},
            {0,0,0,0}
        },
        {   {0,2,2,0},
            {0,2,0,0},
            {0,2,0,0},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {2,2,2,0},
            {0,0,2,0},
            {0,0,0,0}
        },
        {   {0,2,0,0},
            {0,2,2,0},
            {0,0,2,0},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,0,2,2},
            {0,2,2,0},
            {0,0,0,0}
        },
        {   {0,0,2,0},
            {0,2,2,0},
            {0,2,0,0},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,2,2,0},
            {0,0,2,2},
            {0,0,0,0}
        },

        {   {0,0,0,0},
            {0,2,2,0},
            {0,2,2,0},
            {0,0,0,0}
        },

        {   {0,0,0,0},
            {0,0,2,0},
            {0,2,2,2},
            {0,0,0,0}
        },
        {   {0,0,0,0},
            {0,0,2,0},
            {0,0,2,2},
            {0,0,2,0}
        },

        {   {0,0,0,0},
            {0,0,0,0},
            {0,2,2,2},
            {0,0,2,0}
        },
        {   {0,0,0,0},
            {0,0,2,0},
            {0,2,2,0},
            {0,0,2,0}
        }
    };
    srand((unsigned) time(NULL));
    peca2 = rand()%19;
    peca=peca2;
    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* bloco = load_bitmap("Sprites/bloco.bmp", NULL);
    BITMAP* game = load_bitmap("Sprites/Game Screen.bmp", NULL);

    ///FONTE
    FONT* pixelado1 = load_font("FONTE1.pcx", NULL,NULL);

    ///GERAR MATRIZ
    for(i=0; i<yM; i++)
    {
        for(j=0; j<xM; j++)
        {
            mat[i][j]=0;
        }
    }
    for(i=0; i<yM; i++)
    {
        mat[i][0]=1;
        mat[i][13]=1;
    }
    for(j=0; j<xM; j++)
    {
        mat[28][j]=1;
    }
    att_p(mat2,mat);
    descer=*timer/velocidade;
    tempo=*clocks/100;
    ///GAME LOOP
    while(!*xit_program && !exit_screen)
    {
        //INPUT
        if(*screent == HARDSCREEN)
        {
            if(key[KEY_BACKSPACE])
            {
                exit_screen = TRUE;
                *screent = DIFICULDADES;
            }
        }

        if(key[KEY_ESC])
        {
            *xit_program = TRUE;
        }
        if(k)
        {
            if(key[KEY_UP])
            {
                while(key[KEY_UP]) {}
                {
                    int h=1;
                    if(peca==1&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        h=0;
                        peca=0;
                    }
                    if(peca==0&&h==1&&ValidaMov(a.pos_x,a.pos_y,mat,3))peca=1;
                    if(peca>1&&peca<6&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        peca++;
                        h=0;
                    }
                    if(peca==6&&h==0&&ValidaMov(a.pos_x,a.pos_y,mat,3)) peca=2;
                    if(peca>5&&peca<10&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        peca++;
                        h=0;
                    }
                    if(peca==10&&h==0&&ValidaMov(a.pos_x,a.pos_y,mat,3)) peca=6;
                    if(peca==10&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        h=0;
                        peca=11;
                    }
                    if(peca==11&&h==1&&ValidaMov(a.pos_x,a.pos_y,mat,3))peca=10;
                    if(peca==12&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        h=0;
                        peca=13;
                    }
                    if(peca==13&&h==1&&ValidaMov(a.pos_x,a.pos_y,mat,3))peca=12;
                    if(peca>14&&peca<19&&ValidaMov(a.pos_x,a.pos_y,mat,3))
                    {
                        peca++;
                        h=0;
                    }
                    if(peca==19&&h==0&&ValidaMov(a.pos_x,a.pos_y,mat,3)) peca=15;
                }

            }
            if(key[KEY_DOWN])
            {
                if(ValidaMov(a.pos_x,a.pos_y,mat,0)) a.pos_y++;
                else k=0;
            }
            if(key[KEY_RIGHT])
            {
                while(key[KEY_RIGHT]) {}
                if(ValidaMov(a.pos_x,a.pos_y,mat,2)) a.pos_x++;
            }
            if(key[KEY_LEFT])
            {
                while(key[KEY_LEFT]) {}
                if(ValidaMov(a.pos_x,a.pos_y,mat,1)) a.pos_x--;
            }
            if(descer != *timer/velocidade)
            {
                if(descer2==1) descer2=0;
                else descer2=1;
                descer=*timer/velocidade;
            }
            if(descer2==1)
            {
                if(ValidaMov(a.pos_x,a.pos_y,mat,0))
                {
                    a.pos_y++;
                    descer2=0;
                }
                else k=0;
            }
        }
        if(*screent == DIFICULDADES)
        {
            if(key[KEY_BACKSPACE])
            {
                exit_screen = TRUE;
                *screent = MAINMENU;
            }
        }
        //UPDATE
        de_p(mat,mat2,Xp,a.pos_x,a.pos_y,peca);
        if(k==0)
        {
            reset_p(mat,mat2);
            a.pos_x=5;
            a.pos_y=0;
            k=1;
            peca=peca2;
            peca2 = rand()%19;
            cleanline(mat, PONT, lines);
            att_p(mat2,mat);
        }
        //DRAW
        for(i=0; i<yM; i++)
        {
            for(j=0; j<xM; j++)
            {
                if(mat[i][j]!=0) draw_sprite(buffer,bloco,j*21+235,i*21-10);
            }
        }
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                if(Xp[peca2][i][j]!=0) draw_sprite(buffer,bloco,j*21+630,i*21+400);
            }
        }
        if(tempo+2<*clocks/100)
        {
            descer=descer/2;
            tempo=*clocks/100;
        }

        int i=3,j;
        for(j=1; j<12; j++)
        {
            if(mat[5][j]==1)
            {
                exit_screen = TRUE;
                *screent = GAMEOVER;
            }
        }
        textprintf_ex(buffer,pixelado1,650,170,makecol(255,0,0),-1,"%d",*lines);
        textprintf_ex(buffer,pixelado1,110,170,makecol(255,0,0),-1,"%d",*PONT);
        textprintf_ex(buffer,pixelado1,650,70,makecol(255,0,0),-1,"%d",*clocks/100);
        draw_sprite(screen, buffer, 0, 0);
        draw_sprite(buffer, game, 0, 0);
    }

    ///FINALIZAÇÃO
    destroy_bitmap(buffer);
    destroy_bitmap(game);
    destroy_bitmap(bloco);
}

///MOVIMENTAÇÃO
int ValidaMov(int PosX, int PosY,int mat[29][14],int mov)
{
    int i,j;
    if(mov ==0)
    {
        for(i=PosY; i<4+PosY; i++)
        {
            for(j=PosX; j<4+PosX; j++)
            {
                if(mat[i][j]==2)
                {
                    if(mat[i+1][j]==1)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    if(mov ==2)
    {
        for(i=PosY; i<4+PosY; i++)
        {
            for(j=PosX; j<4+PosX; j++)
            {
                if(mat[i][j]==2)
                {
                    if(mat[i][j+1]==1)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    if(mov ==1)
    {
        for(i=PosY; i<4+PosY; i++)
        {
            for(j=PosX; j<4+PosX; j++)
            {
                if(mat[i][j]==2)
                {
                    if(mat[i][j-1]==1)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    if(mov ==3)
    {
        for(i=PosY; i<4+PosY; i++)
        {
            for(j=PosX; j<4+PosX; j++)
            {
                if(mat[i][j]==2)
                {
                    if(mat[i][j-1]==1||mat[i][j+1]==1||mat[i+1][j]==1)
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
}
void att_p(int mat1[29][14],int mat2[29][14])
{

    int i,j;
    for(i=0; i<28; i++)
    {
        for(j=0; j<13; j++)
        {
            mat1[i][j]=mat2[i][j];
            if(mat1[i][j]==2)mat1[i][j]=1;
        }
    }
}
void reset_p(int mat1[29][14],int mat2[29][14])
{

    int i,j;
    for(i=0; i<28; i++)
    {
        for(j=0; j<13; j++)
        {
            if(mat1[i][j]==2)mat1[i][j]=1;
            mat2[i][j]=mat1[i][j];
        }
    }
}
void de_p(int mat1[29][14],int mat2[29][14],int mat3[7][4][4],int pox,int poy,int d)
{
    att_p(mat1,mat2);
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(mat1[i+poy][j+pox]==0)
            {
                mat1[i+poy][j+pox]=mat3[d][i][j];
            }
        }
    }
}

///PONTUAÇÃO
//LIMPA LINHA E CALCULA PONTO
void cleanline(int mat[29][14], int *PONT, int *lines)
{
    int mat2[29][14];
    int i,j,h;

    for(i=0; i<28; i++)
    {
        if(mat[i][0]&&mat[i][1]&&mat[i][2]&&mat[i][3]&&mat[i][4]&&mat[i][5]&&mat[i][6]&&mat[i][7]&&mat[i][8]&&mat[i][9]&&mat[i][10]&&mat[i][11]&&mat[i][12]&&mat[i][13])
        {
            for(j=1; j<13; j++)
            {
                mat[i][j]=0;
                mat2[i][j]=mat[i-1][j];
                mat[i][j]=mat2[i][j];
                mat2[i-1][j]=mat[i-2][j];
                mat[i-1][j]=mat2[i-1][j];
                mat2[i-2][j]=mat[i-3][j];
                mat[i-2][j]=mat2[i-2][j];
                mat2[i-3][j]=mat[i-4][j];
                mat[i-3][j]=mat2[i-3][j];
                mat2[i-4][j]=mat[i-5][j];
                mat[i-4][j]=mat2[i-4][j];
                mat2[i-5][j]=mat[i-6][j];
                mat[i-5][j]=mat2[i-5][j];
            }
            *lines+=1;
            *PONT+=100;
        }
    }
}

//LER PONTUAÇÃO
void lerpt()
{
    fp=fopen("rc.txt","r+");
    int i;
    for(i=0; i<10; i++)
    {
        fscanf(fp,"%d %s",&vet[i],&m[vet2[i]].nam);
    }
    rewind(fp);
}
END_OF_FUNCTION(lerpt);

//ORGANIZAR PONTUAÇAO
void orgpt()
{
    int i,j,aux,aux2;
    for(j=0; j<11; j++)
    {
        for(i=0; i<11; i++)
        {
            if(vet[i]<vet[j])
            {
                aux=vet[i];
                vet[i]=vet[j];
                vet[j]=aux;
                aux2=vet2[i];
                vet2[i]=vet2[j];
                vet2[j]=aux2;
            }
        }
    }
    for(i=0; i<11; i++)
    {
        printf("%d %s\n",vet[i],m[vet2[i]].nam);
    }
}
END_OF_FUNCTION(orgpt);

//ESCREVE A PONTUAÇAO
void escpt()
{
    fclose(fp);
    fp=fopen("rc.txt","w");
    fclose(fp);
    fp=fopen("rc.txt","r+");
    rewind(fp);
    int i;
    for(i=0; i<10; i++)
    {
        fprintf(fp,"%d %s\n",vet[i],m[vet2[i]].nam);
    }
    rewind(fp);
}
END_OF_FUNCTION(escpt);


///ACABA JOGO
void gameover(int *screent, int *PONT, volatile int *xit_program)
{
    int exit_screen = FALSE;

    BITMAP* acabou = load_bitmap("Sprites/gameover.bmp", NULL);
    FONT* pixelado1 = load_font("FONTE1.pcx", NULL,NULL);

    draw_sprite(screen, acabou, 0, 0);
    textprintf_ex(screen,pixelado1,400,300,makecol(255,0,0),-1,"%d",*PONT);

    if(key[KEY_ESC])
    {
        *xit_program = TRUE;
    }
    if(*screent == GAMEOVER)
    {
        if(key[KEY_BACKSPACE])
        {
            exit_screen = TRUE;
            *screent = MAINMENU;
        }
    }
    //SALVA NOME

    BITMAP* buffer = NULL;
    int caret=0;

    buffer = create_bitmap(320, 240);

    do
    {
        if(keypressed())
        {
            int  newkey   = readkey();
            char ASCII    = newkey & 0xff;
            char scancode = newkey >> 8;

            // a character key was pressed; add it to the string
            if(ASCII >= 32 && ASCII <= 126)
            {
                if(caret < 4 - 1)
                {
                    m[10].nam[caret] = ASCII;
                    caret++;
                    m[10].nam[caret] = '\0';
                }
            }
            else if(scancode == KEY_BACKSPACE)
            {
                if (caret > 0) caret--;
                m[10].nam[caret] = '\0';
            }

        }

        // all drawing goes here
        clear(buffer);
        textout(buffer, pixelado1, m[10].nam, 10, 20, makecol(255, 255, 255));
        vline(buffer, caret * 38, 38, 48, makecol(255, 255, 255));
        blit(buffer, screen, 0, 0, 400, 400, 320, 240);

    }
    while(!key[KEY_ENTER]);

    vet[10]=*PONT;
    lerpt();
    orgpt();
    escpt();
    vet[10]=0;
    *screent=TITLESCREEN;
    destroy_bitmap(buffer);

    destroy_bitmap(acabou);
}
