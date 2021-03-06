#ifndef STRUCTS_H
#define STRUCTS_H

#define BULLET_COUNT 1024

struct Vector
{
    double x, y;
};

struct Colour
{
    int red, green, blue;
};

struct ColourStack
{
    Colour colour, colourSpeed;
};

struct Keys
{
    int upKey, downKey, leftKey, rightKey, healKey, shootKey;
};

struct Object
{
    double x, y, r, vX, vY, mass;

    Object (double theX, double theY, double theR, double theVX, double theVY, double theMass);
};

struct Bullet : public Object
{
    int time;

    Bullet (double theX, double theY, double theR, double theVX, double theVY, double theMass, int theTime);
};

struct Bullets
{
    Bullet* bullets;
    int nextBulletIndex;
};

struct Player : public Object
{
    double hp;
    Keys keys;
    Bullets bullets;

    Player (double theX, double theY, double theR, double theVX, double theVY, double theMass, double theHp,
                Keys theKeys, Bullets theBullets);
};

struct World
{
    int width, height, dT;
    double dV, godsPower;
};

const World WORLD = {1200, 900, 1, 0.001, 0.5};

#endif
