/* simple node allocator for linked list */
#include <stdlib.h>
#include <node.h>

static const int bulletHeapSize = 5;
static bullets bulletHeap[bulletHeapSize];
static bullets *freenodesB;

static const int asteroidHeapSize = 10;
static asteroids asteroidHeap[asteroidHeapSize];
static asteroids *freenodesA;

void initialise_bulletHeap(void)
{
    int bulletNum;
    for( bulletNum=0 ; bulletNum<(bulletHeapSize-1) ;bulletNum++) {
        bulletHeap[bulletNum].next = &bulletHeap[bulletNum+1];
    }
    bulletHeap[bulletNum].next = NULL;
    freenodesB = &bulletHeap[0];
}

void initialise_asteroidHeap(void)
{
    int asteroidNum;
    for( asteroidNum=0 ; asteroidNum<(asteroidHeapSize-1) ;asteroidNum++) {
        asteroidHeap[asteroidNum].next = &asteroidHeap[asteroidNum+1];
    }
    asteroidHeap[asteroidNum].next = NULL;
    freenodesA = &asteroidHeap[0];
}



bullets *allocnodeBullet(void)
{
    bullets *node = NULL;
    if( freenodesB ) {
        node = freenodesB;
        freenodesB = freenodesB->next;
    }
    return node;
}


asteroids *allocnodeAsteroid(void)
{
    asteroids *node = NULL;
    if( freenodesA ) {
        node = freenodesA;
        freenodesA = freenodesA->next;
    }
    return node;
}



void freenodeBulletStruct
	(bullets *bulletNum){
    bulletNum->next = freenodesB;
    freenodesB = bulletNum;
}


void freenodeAsteroidStruct
	(asteroids *asteroidNum){
    asteroidNum->next = freenodesA;
    freenodesA = asteroidNum;
}
	
