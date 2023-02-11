#include <citro2d.h>

typedef Vector2 {int x, y;};
typedef Rectangle {int left,top,right,bottom;};

typedef Animation{
    C2D_Sprite frames[];
    C2D_SpriteSheet spriteSheet;
    int totalFrames = C2D_SpriteSheetCount(C2D_SpriteSheet);
    int speed;
};

class AnimObject {
    Vector2 pos;
    Animation AnimSpr;
}

AnimObject mario = new AnimObject;