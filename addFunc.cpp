#include "Game.h"

void colourChange (int* colour, int* colourSpeed)
{
    *colour += *colourSpeed;
    if (*colour >= 255) *colour = 255;
    if (*colour <   60) *colour =  60;
    if (60 >= *colour || *colour >= 255) *colourSpeed = -*colourSpeed;
}

Object::Object (double theX, double theY, double theR, double theVX, double theVY, double theMass) :
    x       (theX),
    y       (theY),
    r       (theR),
    vX     (theVX),
    vY     (theVY),
    mass (theMass)
{}


Bullet::Bullet (double theX, double theY, double theR, double theVX, double theVY, double theMass, int theTime) :
    Object (x, y, r, vX, vY, mass),
    time (theTime)
{}

Player::Player (double theX, double theY, double theR, double theVX, double theVY, double theMass, double theHp,
                Keys theKeys, Bullets theBullets) :
    Object (x, y, r, vX, vY, mass),
    hp           (theHp),
    keys       (theKeys),
    bullets (theBullets)
{}

void control (Player* player)
{
    //assert (!PlayerOk (player)? (PlayerDump (player), 0 : 1));

    assert (player);

    if      (GetAsyncKeyState (player->keys.upKey   )) player->vY -= WORLD.godsPower;
    else if (GetAsyncKeyState (player->keys.downKey )) player->vY += WORLD.godsPower;

    if      (GetAsyncKeyState (player->keys.leftKey )) player->vX -= WORLD.godsPower;
    else if (GetAsyncKeyState (player->keys.rightKey)) player->vX += WORLD.godsPower;

    if (GetAsyncKeyState (player->keys.healKey)) player->hp += 5;
}



