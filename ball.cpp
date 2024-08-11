#include <ball.h>

Ball::Ball()
{
}

Ball::Ball(int x, int y, int r)
{
    ball_x = x;
    ball_y = y;
    ball_radius = r;
}

void Ball::draw()
{
    DrawCircle(ball_x, ball_y, ball_radius, WHITE);
}

void Ball::ResetBoard()
{
    ball_x = GetScreenWidth() / 2;
    ball_y = GetScreenHeight() / 2;

    int speed[] = {1, -1};

    ball_speed_x *= speed[GetRandomValue(0, 1)];

    ball_speed_y *= speed[GetRandomValue(0, 1)];
}
void Ball::update()
{
    ball_x += ball_speed_x;

    ball_y += ball_speed_y;

    if (ball_x + ball_radius >= GetScreenWidth())
    {
        cpu_score++;
        ResetBoard();
    }

    if (ball_x - ball_radius <= 0)
    {
        player_score++;
        ResetBoard();
    }

    if (ball_y + ball_radius >= GetScreenHeight() || ball_y - ball_radius <= 0)
    {
        ball_speed_y *= -1;
    }
}