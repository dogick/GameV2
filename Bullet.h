#pragma once
#include <SFML/Graphics.hpp>
#include "Var.h"

struct Bullet
{
	Bullet(sf::Texture const& bulletTexture, sf::Vector2f const& bulletPosition, sf::Vector2f &Direction, float Rotation, float Damage);
    sf::Sprite bulletSprite;
	sf::Vector2f position;
	sf::Vector2f direction;
	float rotation;
	float damage;
	float speed = 2000;

};

void UpdateBullet(std::vector<Bullet*> & bullets, float elapsedTime, Objects const& objects);
sf::IntRect GetBulletRect(sf::Sprite const& bullet);
bool CheckCollisionWithMap(sf::Sprite const& bullet, Objects const& barriers);
void UpdateBullet(std::vector<Bullet*> & bullets, float elapsedTime, Objects const& objects);