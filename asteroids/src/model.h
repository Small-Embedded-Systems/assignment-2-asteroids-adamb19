/* Asteroids Model */
struct point {
    float x,y;
};
typedef struct point coordinate_t;

/* Some insitial struct types if you want to usd them */
struct ship {
	float heading;
   float x,y;
	float vx,vy;
	float speed;
};
typedef struct ship tim;

/* initial structs for building linked lists there structs for the linked and other objects similar to show the mechanics as the lkinked don't work */
typedef struct rock {
    float x,y;
	float vx,vy;
	float size;
    struct rock *next;
}rock_t;

struct rock2 {
    float x,y;
	float vx,vy;
	float size;
};
typedef struct rock2 rockinfo;

typedef struct missile {
	float x,y;
	float vx,vy;
	float ttl;
  struct missile *next;
} missile_t;



 struct missile2 {
	float x,y;
	float vx,vy;
	float ttl;
	 float speed;
};
 typedef struct missile2 m;

/*method which should be shared to other methods*/
void physics(void);
void initialise_heap(void);
void initialise_rockheap(void);
rock_t *allocnode1(void);
missile_t *allocnode(void);
void freenode1(rock_t *n);
void freenode(missile_t *n);
//void fire(void);
