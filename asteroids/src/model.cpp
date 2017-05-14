/* Asteroids model */
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#include "model.h"
#include "utils.h"
#include "asteroids.h"
#include "controller.h"




static const int MAXSize = 40;//the maxsize of missile is 40 
static const int rockMaxSize=100;//the maxsizeof the asteriod
static missile_t a[MAXSize]; //assignment of the maxsize
static rock_t b[rockMaxSize]; //assignment of max size;
static missile_t *freenodes;//a pointer to the freenodes for missiles
static rock_t *freenodes1;//a  point o the frerenodes for the rocks
missile_t *active3;//a other pointer to missiles
rock_t *active4;//a pointer to the asteeroids

/*intialise the heap of missiles*/
void initialise_heap(void)
{
    int c;
    for(c=0 ; c<(MAXSize-1) ; c++){
        a[c].next = &a[c+1];
    }
    a[c].next = NULL;
    freenodes=&a[0];
}

/*intialise heap for the rocks*/
void initialise_Rockheap(void)
{
    int d;
    for(d=0 ; d<(rockMaxSize-1) ; d++){
        b[d].next = &b[d+1];
    }
    b[d].next = NULL;
    freenodes1=&b[0];
}

/*
rock_t *allocnode(void)
{
    rock_t *m = NULL;
    if( freenodes1 ) {
        m = freenodes1;
        freenodes1 = freenodes1->next;
    }
    return m;
}
//the method to allocate free nodes to missiles
missile_t *allocnode1(void)
{
    missile_t *m1 = NULL;
    if( freenodes ) {
        m1 = freenodes;
        freenodes = freenodes->next;
    }
    return m1;
}
*/

//go though missiles and check for free space
void freenode(missile_t *n)
{
    n->next = freenodes;
    freenodes = n;
}
/*freenode allocated to rocks*/
void freenode1(rock_t *m){
	m->next = freenodes1;
    freenodes1 = m;
}

/*all the assigned variables of missiles*/
void strike(struct missile *r)
{
	tim *k;
    r->x = k->x;//missile x is equal to ship .x
    r->y = k->y;//missile y is equal to ship.y
    r->vx =k->vy;//missile vy is equal to ship vy
    r->vy = k->vx;//missile vx is equal to ship vx
    r->ttl = 20; /* how long to live (s) */
}

/*all assigned variables of rocks*/
void Rockstrike(struct rock *r)
{
    r->x = randrange(10,200);//rock x is a variable between 10 and 200
    r->y = randrange(10,300);//rock y is a variable between 10 and 300;
    r->vx =randrange(-1,2);//rock vx is random between -1 and 2
    r->vy = randrange(-1,2);//rock y velocity is between -1 and 2
	
	/*if velocity components equal to zero than chnage to 1*/
    if((r->vy=0) ||( r->vx=0)){
			r->vy=1;
			r->vx=1;
		}
}

/*update metrhod for missiles*/
void update(struct missile *l)
{
	//iterate through the linked list and change the missiles by velocity and speed
    for( ; l ; l = l->next ) {
        l->x += l->vx * Dt; 
        l->y += l->vy * Dt;
        
        /*if it goes out of screen it should come back*/
        if( l->y > 270 ){
            l->y = 0;
        }
        else if( l->x<=0){
					l->x=480;
				}	
        else if(l->x>=480){
					l->x=0;
				}
				else if( l->y <=0 ){
            l->y = 270;
        }
				
				/*time will decrease constantly by dt*/
        l->ttl -= Dt;
        /* before moving on to the next element,
           check if it is still valid (has steps left)
           I have to do  this now, so I can remove the
           element from the linked-list
        */
				/*when the variable is less or equal to zero the missile will expire and there will be a free space in the linked list"*/
        if( l->next->ttl<=0 ) {
            struct missile *expired = l->next;
            l->next = l->next->next;
            freenode(expired);
        }
    }
}
/*the update function for rocks */
void updaterock(struct rock *l)
{
	/*iterate through the rocks and check the speed of the rock*/
    for( ; l ; l = l->next ) {
        l->x += l->vx * Dt; 
        l->y += l->vy * Dt;
        
        /*wrap arounbd*/
        if( l->y > 270 ){
            l->y = 0;
        }
        else if( l->x<=0){
					l->x=480;
				}	
        else if(l->x>=480){
					l->x=0;
				}
				else if( l->y <=0 ){
            l->y = 270;
        }
    }
}
/*updateing the missile list
void missile_system(void)
{
        struct missile *spark = allocnode();
        if(spark) {
             put the new particle at the front of the list 
            spark->next = active3;
            active3 = spark;
            strike(spark);
        update(active3);
}
				}
updating the rock list
		void rock_system(void)
{
        struct rock *spark1 = allocnode1();
        if(spark1) {
             put the new particle at the front of the list 
            spark1->next = active4;
            active4 = spark1;
            Rockstrike(spark1);
        updaterock(active4);
}
				}	
				*/
/*update the physics method*/
void physics(void)
{
	/*
	rock_system();
	missile_system();
	*/
}


