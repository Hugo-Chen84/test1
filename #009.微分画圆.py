import math
import turtle
distance = 0
while distance < 200*math.pi:
    turtle.forward(1)
    distance+=1
    turtle.right(9/(5*math.pi))
turtle.circle(200)
turtle.done()
