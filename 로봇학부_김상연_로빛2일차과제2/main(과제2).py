import pygame
import random
import sys

pygame.init()
width, height = 800, 600
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("자율주행 시뮬레이션")
clock = pygame.time.Clock()

WHITE = (255, 255, 255)
RED = (255, 0, 0)
BLUE = (0, 0, 255)
GREEN = (0, 255, 0)

class circle:
    #원의 초기위치,속도,반지름
    def __init__(self):
        self.x = width // 2
        self.y = height // 2
        self.speed_x = 4.0
        self.speed_y = 4.0
        self.radius = 20  
    #이동 방법
    def move(self):
        self.x += self.speed_x
        self.y += self.speed_y
        #벽에 부딪히면 벡터를 반대로 바꿈
        if self.x - self.radius < 0 or self.x + self.radius > width:
            self.speed_x = -self.speed_x
            

        if self.y - self.radius < 0 or self.y + self.radius > height:
            self.speed_y = -self.speed_y
           
    #원을 화면에 그림    
    def draw(self):
        pygame.draw.circle(screen, RED, (int(self.x), int(self.y)), self.radius)
        
        front_x = int(self.x + self.speed_x * 4)
        front_y = int(self.y + self.speed_y * 4)

#pygame 이용        
def main():  
    robot = circle()

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        robot.move()
        screen.fill(WHITE)
        robot.draw()
        pygame.display.flip()
        clock.tick(60)

if __name__ == "__main__":
    main()