#include <paddle.h>

Paddle::Paddle()
{
}

Paddle::Paddle(float _x, float _y, float _width, float _height)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
}

void Paddle::LimitMovement()
{
    if (y <= 0)
    {
        y = 0;
    }
    if (y + height >= GetScreenHeight())
    {
        y = GetScreenHeight() - height;
    }
}

void Paddle::draw()
{
    DrawRectangle(x, y, width, height, WHITE);
}

void Paddle::update()
{
    if (IsKeyDown(KEY_UP))
    {
        y -= speed;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        y += speed;
    }
    LimitMovement();
}

void CpuPaddle::update(float ball_y)
{
    if (y + height / 2 > ball_y)
    {
        y -= speed;
    }
    if (y + height / 2 <= ball_y)
    {
        y += speed;
    }
    LimitMovement();
}

CpuPaddle::CpuPaddle()
{
}

CpuPaddle::CpuPaddle(float _x, float _y, float _width, float _height)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
}