/* Game state */

extern int   score;        /* total score so far */
extern int   lives;        /* lives remaining */
extern bool started;


extern struct rock *asteroids; /* array of rocks / pointer to linked-list */
extern struct missile *shots;  /* array of missiles / pointer to linked-list */

extern const float Dt; /* Time step for physics, needed for consistent motion */
