import turtle
import math
turtle.setup(width=800, height=600)
pen = turtle.Turtle()
pen.speed(10)
pen.color('red')
pen.fillcolor('red')
pen.begin_fill()
t = 0
while t <= 2 * math.pi:
    x = 16 * math.pow(math.sin(t), 3)
    y = 13 * math.cos(t) - 5 * math.cos(2 * t) - 2 * math.cos(3 * t) - math.cos(4 * t)

    scale = 10
    pen.goto(x * scale, y * scale)
    t += 0.01
pen.end_fill()

pen.hideturtle()
turtle.done()
