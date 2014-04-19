#ifndef GAME_H
#define GAME_H

#include "TXLib.h"
#include "Structs.h"

#define DELTA 0.00001
#define OUT_OF_ARRAY( index, arraySize )  \
    assert (    0 <= index    );          \
    assert (index <  arraySize);


void moveObject  (Object* object, bool bouncy = true);
void shoot       (Player* player);
void moveBullets (Player* player);

void drawPlayer   (Player player, ColourStack* colourStack);
void drawBullets  (Player player);
void createWindow ();
void drawCycle    (Player p, Player p1, ColourStack* colourStack, ColourStack* colourStack1);

void control      (Player* player);
void colourChange (int* colour, int* speed);

Player newPlayer (double x, double y, double r, double vX, double vY, double mass, int hp,
                  int upKey, int downKey, int leftKey, int rightKey, int healKey, int shootKey,
                  Bullet bullets[]);
Bullet newBullet  (double x, double y, double r, double vX, double vY, double mass, int time);

#endif
