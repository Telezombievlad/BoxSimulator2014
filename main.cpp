
#include "Game.h"

int main ()
{
    ColourStack colourStack  = {200, 200, 200, 1, 2, 4},
                colourStack1 = {100, 100, 100, 3, 4, 5};

    Keys keys  = {  'W',     'S',     'A',      'D',       'E', VK_LCONTROL},
         keys1 = {VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT, VK_RSHIFT, VK_RCONTROL};

    Player p  = Player (300, 200, 15, 5, 7, 10, 500 , keys,  {NULL, 0});
    Player p1 = Player (500, 300, 15, 2, 8, 10, 1000, keys1, {NULL, 0});

    createWindow ();

    while (!GetAsyncKeyState (VK_ESCAPE))
    {
        drawCycle (p, p1, &colourStack, &colourStack1);

        moveObject (&p);
        moveObject (&p1);

        control (&p);
        control (&p1);

        shoot (&p);
        shoot (&p1);

        moveBullets (&p);
        moveBullets (&p1);

        txSleep (1000/30);
    }


    return 0;
}


