
typedef struct bulletStruct {
    float x,y;
    float v_x, v_y;
    float ttl;
    struct bulletStruct *next;
} bullets;

typedef struct asteroidStruct {
    float x,y;
    float v_x, v_y;
    float ttl;
    struct asteroidStruct *next;
} asteroids;


void initialise_bulletHeap(void);
bullets *allocnodeBullet(void);
void freenodeBulletStruct(bullets *bulletNum);

void initialise_asteroidHeap(void);
asteroids *allocnodeAsteroid(void);
void freenodeAsteroidStruct(asteroids *asteroidNum);
