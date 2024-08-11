#include <raylib.h>
#include <iostream>
using namespace std;
class Paddle
{
protected:
    void LimitMovement();

public:
    Paddle();
    Paddle(float _x, float _y, float _height, float width);
    void draw();
    void update();
    float x;
    float y;
    float height;
    float width;
    float speed = 7;
};

class CpuPaddle : public Paddle
{
public:
    CpuPaddle();
    CpuPaddle(float _x, float _y, float _height, float _width);
    void update(float ball_y);
};
