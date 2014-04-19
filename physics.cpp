#include "Game.h"

void moveObject (Object* object, bool bouncy/*= true*/)
{
    assert (object);

    object->x += object->vX * WORLD.dT;
    object->y += object->vY * WORLD.dT;

    if (bouncy)
    {
        if (0 >= object->x - object->r || object->x + object->r >= WORLD.width ) object->vX = -object->vX;
        if (0 >= object->y - object->r || object->y + object->r >= WORLD.height) object->vY = -object->vY;
    }
    else
    {
        if (0 >= object->x - object->r || object->x + object->r >= WORLD.width ) object->vX = 0;
        if (0 >= object->y - object->r || object->y + object->r >= WORLD.height) object->vY = 0;
    }

    if (0 >= object->x - object->r) object->x = object->r;
    if (0 >= object->y - object->r) object->y = object->r;

    if (object->x + object->r >= WORLD.width ) object->x = WORLD.width  - object->r;
    if (object->y + object->r >= WORLD.height) object->y = WORLD.height - object->r;

    if (object->vX > 0)
    {
        object->vX -= WORLD.dV;
        if (object->vX < 0) object->vX = 0;
    }
    else if (object->vX < 0)
    {
        object->vX += WORLD.dV;
        if (object->vX > 0) object->vX = 0;
    }

    if (object->vY > 0)
    {
        object->vY -= WORLD.dV;
        if (object->vY < 0) object->vY = 0;
    }
    else if (object->vY < 0)
    {
        object->vY += WORLD.dV;
        if (object->vY > 0) object->vY = 0;
    }
}

#define BULLET_SPEED_KOEFICIENT 4
#define BULLET_COORDS_CHANGE_KOEFFICIENT 7
#define BULLET_PLAYER_STOPPER_KOEFFICIENT 20

void shoot (Player* player)
{
    assert (player);
    assert (player->bullets.bullets);

    if (GetAsyncKeyState (player->keys.shootKey) &&
        player->bullets.bullets[player->bullets.nextBulletIndex].time <= 0)
    {
        Bullet nextBul = Bullet (player->x + BULLET_COORDS_CHANGE_KOEFFICIENT * player->vX,
                                 player->y + BULLET_COORDS_CHANGE_KOEFFICIENT * player->vY, 5,
                                 BULLET_SPEED_KOEFICIENT * player->vX, BULLET_SPEED_KOEFICIENT * player->vY,
                                 1, 90);

        player->vX -= nextBul.vX/BULLET_PLAYER_STOPPER_KOEFFICIENT;
        player->vY -= nextBul.vY/BULLET_PLAYER_STOPPER_KOEFFICIENT;

        player->bullets.bullets[player->bullets.nextBulletIndex] = nextBul;

        player->bullets.nextBulletIndex++;
        if (player->bullets.nextBulletIndex > BULLET_COUNT-1) player->bullets.nextBulletIndex = 0;
    }

}

void moveBullets (Player* player)
{
    assert (player);

    for (int j = 0; j < BULLET_COUNT; j++)
    {
        OUT_OF_ARRAY( j, BULLET_COUNT );

        if (player->bullets.bullets[j].time <= 0)
        {
            continue;
        }

        moveObject (&player->bullets.bullets[j]);

        player->bullets.bullets[j].time--;
    }
}
