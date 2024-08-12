#include <ball.h>
#include <paddle.h>

class Game
{
public:
    Game();
    ~Game();
    Paddle Player;
    CpuPaddle cpu;
    Ball ball;
    void Initiate();
    void checkCollision();
    void draw();
    void update();
    int screenWidth;
    int screenHeight;
    Music music;
};