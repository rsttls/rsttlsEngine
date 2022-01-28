#include "gameObject.h"

int gameObject::draw()
{
    if (texture.texture != nullptr)
    {
        int error = texture.draw(renderer, position.x - (texture.rect.w / 2) - *cameraX, position.y - (texture.rect.h / 2) - *cameraY);
        if (error != 0)
            logger.logSDL();
        return error;
    }
    return 0;
}
int gameObject::update()
{
    if (*rotation < 0)
        *rotation += 360;
    if (*rotation >= 360)
        *rotation -= 360;
    return 0;
}

int gameObject::loadTexture(const char *path)
{
    int ret = texture.loadImage(renderer, path);

    return ret;
}



int amogusObject::update()
{
    if (direction == true)
    {
        *flip = flipHorizontal;
        position.x += 15;
        if (position.x > 500)
            direction = false;
    }
    else
    {
        *flip = flipNone;
        position.x -= 15;
        if (position.x < -500)
            direction = true;
    }
    return 0;
}

int physicsObject::update()
{
    if (*rotation < 0)
        *rotation += 360;
    if (*rotation >= 360)
        *rotation -= 360;

    velocity.x += acceleration.x;
    velocity.y += acceleration.y;

    velocity.x -= velocity.x * friction;
    velocity.y -= velocity.y * friction;

    if (velocity.x >= maxSpeed)
        velocity.x = maxSpeed;
    else if (velocity.x <= -maxSpeed)
        velocity.x = -maxSpeed;

    if (velocity.y >= maxSpeed)
        velocity.y = maxSpeed;
    else if (velocity.y <= -maxSpeed)
        velocity.y = -maxSpeed;

    position.x += velocity.x;
    position.y += velocity.y;

    return 0;
}
