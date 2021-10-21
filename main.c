#include "includes.h"
#include "my_functions.h"


///TIMERS
volatile int ticks;
volatile int troca;

void tick_counter()
{
    ticks++;
}

void troca_title()
{
    troca++;
}


///PROGRAMA
int main()
{
    ///VARIAVEIS
    volatile int exit_program = FALSE;
    int screen_state;
    int pont=0;
    int line=0;

    ///INICIAR
    iniciar(&screen_state, &exit_program);
    install_timer();

    ///TIMERS
    ticks = 0;
    LOCK_FUNCTION(tick_counter);
    LOCK_VARIABLE(ticks);
    install_int_ex(tick_counter, BPS_TO_TIMER(60));

    troca = 0;
    LOCK_FUNCTION(troca_title);
    LOCK_VARIABLE(troca);
    install_int_ex(troca_title, MSEC_TO_TIMER(250));

    ///SCREENS
    while(!exit_program)
    {

        if(screen_state == TITLESCREEN)
            titlescreen(&screen_state, &exit_program, &troca);

        if(screen_state == MAINMENU)
            mainmenu(&screen_state, &exit_program);

        if(screen_state == DIFICULDADES)
            gamescreen(&screen_state, &exit_program);

        if(screen_state == INSTRUCTIONS)
            instructions(&screen_state, &exit_program);

        if(screen_state == RECORDSCREEN)
            recordscreen(&screen_state, &exit_program);

        if(screen_state == GAMEOVER)
            gameover(&screen_state, &pont, &exit_program);

        if(screen_state == EASYSCREEN)
            easyscreen(&screen_state, &exit_program, &troca, &pont, &ticks, &line);

        if(screen_state == MEDIUMSCREEN)
            mediumscreen(&screen_state, &exit_program, &troca, &pont, &ticks, &line);

        if(screen_state == HARDSCREEN)
            hardscreen(&screen_state, &exit_program, &troca, &pont, &ticks, &line);
    }

    return 0;
}
END_OF_MAIN();
