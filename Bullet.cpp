#include "stdafx.h"
#include "Bullet.h"
#include <iostream>

Bullet::Bullet(sf::Texture const& bulletTexture, sf::Vector2f const& bulletPosition, sf::Vector2f &Direction, float Rotation, float Damage)
{
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setPosition(bulletPosition);
    bulletSprite.setRotation(Rotation);
    direction = Direction;
    rotation = Rotation;
    damage = Damage;
}

sf::IntRect GetBulletRect(sf::Sprite const& bullet)
{
    return sf::IntRect(bullet.getPosition().x, bullet.getPosition().y, 5, 5);
}

bool CheckCollisionWithMap(sf::Sprite const& bullet, Objects const& barriers)
{
    for (auto barrier : barriers)
    {
        if (GetBulletRect(bullet).intersects(barrier.rect) && (barrier.name == "solid"))
        {
            return true;
        }
    }
    return false;
}
void UpdateBullet(std::vector<Bullet*> & bullets, float elapsedTime, Objects const& objects)
{
    for (auto it = bullets.begin(); it != bullets.end();)
    {
        auto *bullet = *it;
        if (!CheckCollisionWithMap(bullet->bulletSprite, objects))
        {
            float offsetX = bullet->speed * elapsedTime * bullet->direction.x;
            float offsetY = bullet->speed * elapsedTime * bullet->direction.y;
            bullet->bulletSprite.move(offsetX, offsetY);
            ++it;
        }
        else
        {
            it = bullets.erase(it);
        }
    }

}

