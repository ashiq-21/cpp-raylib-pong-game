#include <ball.h>
#include <paddle.h>

class Game
{
public:
    Game();
    Paddle Player;
    CpuPaddle cpu;
    Ball ball;
    void Initiate();
    void checkCollision();
    void draw();
    int screenWidth;
    int screenHeight;
};