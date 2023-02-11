#include <citro2d.h>

typedef Vector2 {int x, y;};

typedef AnimatedSprite{
    C2D_Sprite frames[];
    C2D_SpriteSheet spriteSheet;
};

class Object {
    Vector2 pos;
    AnimatedSprite AnimSpr;
}