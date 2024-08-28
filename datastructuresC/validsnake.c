#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

#define HEIGHT 20
#define WIDTH 20

int keyBoardHit(char* keyHit)
{
    scanf("%c", keyHit);
    return *keyHit;
}
void changemode(int);
int  kbhit(void);
/*int main(void)
{
  int ch;
  changemode(1);
  while ( !kbhit() )
  {
    putchar('.');
  }
 
  ch = getchar();
 
  printf("\nGot %c\n", ch);
 
  changemode(0);
  return 0;
} */
 
void changemode(int dir)
{
  static struct termios oldt, newt;
 
  if ( dir == 1 )
  {
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
  }
  else
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}
 
int kbhit (void)
{
  struct timeval tv;
  fd_set rdfs;
 
  tv.tv_sec = 0;
  tv.tv_usec = 0;
 
  FD_ZERO(&rdfs);
  FD_SET (STDIN_FILENO, &rdfs);
 
  select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &rdfs);
 
}
int flag; 
int deneme;


// Function to generate the fruit 
// within the boundary 
void setup(int* gameover, int* x, int* y, int* fruitx, int* fruity, int* score) 
{ 
    *gameover = 0; 
  
    // Stores height and width 
    *x = HEIGHT / 2; 
    *y = WIDTH / 2; 
label1: 
    *fruitx = rand() % 20; 
    if (*fruitx == 0) 
        goto label1; 
label2: 
    *fruity = rand() % 20; 
    if (*fruity == 0) 
        goto label2; 
    *score = 0; 
} 
  
// Function to draw the boundaries 
void draw(int* x, int* y, int* fruitx, int* fruity, int* score) 
{ 
    //system("cls"); 
    int i, j;
    for (i = 0; i < HEIGHT; i++) { 
        for (j = 0; j < WIDTH; j++) { 
            if (i == 0 || i == WIDTH - 1 
                || j == 0 
                || j == HEIGHT - 1) { 
                printf("#"); 
            } 
            else { 
                if (i == *x && j == *y) 
                    printf("0"); 
                else if (i == *fruitx 
                         && j == *fruity) 
                    printf("*"); 
                else
                    printf(" "); 
            } 
        } 
        printf("\n"); 
    } 
  
    // Print the score after the 
    // game ends 
    printf("score = %d", *score); 
    printf("\n"); 
    printf("press X to quit the game"); 
} 
  
// Function to take the input 
void input(int* gameover, char* keyHit) 
{ 
    //char keyHit;
    *gameover = 0;
    //changemode(1);
    
    if (keyBoardHit(keyHit)) { 
        switch (*keyHit) { 
        case 'a': 
            flag = 1; 
            break; 
        case 's': 
            flag = 2; 
            break; 
        case 'd': 
            flag = 3; 
            break; 
        case 'w': 
            flag = 4; 
            break; 
        case 'x': 
            *gameover = 1; 
            break; 
        } 
    } 
    //changemode(0);
} 
  
// Function for the logic behind 
// each movement 
void logic(int* gameover, int* x, int* y, int* fruitx, int* fruity, int* score) 
{ 
    //sleep(0.01); 
    
    *gameover = 0;
    switch (flag) { 
    case 1: 
        
        (*y)--; 
        break; 
    case 2: 
        (*x)++; 
        break; 
    case 3: 
        (*y)++; 
        break; 
    case 4: 
        (*x)--; 
        break; 
    default: 
        break; 
    } 
  
    // If the game is over 
    if (*x < 0 || *x > HEIGHT 
        || *y < 0 || *y > WIDTH) 
        *gameover = 1; 
  
    // If snake reaches the fruit 
    // then update the score 
    if (*x == *fruitx && *y == *fruity) { 
    label3: 
        *fruitx = rand() % 20; 
        if (*fruitx == 0) 
            goto label3; 
  
    // After eating the above fruit 
    // generate new fruit 
    label4: 
        *fruity = rand() % 20; 
        if (*fruity == 0) 
            goto label4; 
       *score += 10; 
    } 
} 
  
// Driver Code 
int main() 
{ 
    int m, n; 
    int gameover;
    char keyhit;
    int x, y, fruitx, fruity;
    int score;
  
    // Generate boundary 
    setup(&gameover, &x, &y, &fruitx, &fruity, &score); 
  
    // Until the game is over 
    while (!gameover) { 
  
        // Function Call 
        draw(&x, &y, &fruitx, &fruity, &score); 
        changemode(1);
        input(&gameover, &keyhit); 
        changemode(0);
        logic(&gameover, &x, &y, &fruitx, &fruity, &score); 
    } 
} 