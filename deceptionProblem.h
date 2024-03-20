#define MaxBit 50

typedef struct Deception deception_t;
typedef void (*fpterFunction)(deception_t*);
typedef void (*fpterDisplay)(deception_t*);
typedef void (*fptrDelete)(deception_t*) ;

typedef struct Deception
{
    char* Dbinary;//Deception bit(random configuration)
    long long* Dvalue;//Deception value
    fptrDelete Delete;//destructor
    fpterFunction Function;//calculation function
    fpterDisplay Display;//show input and answer 
    
}deception_t;

//constructor
deception_t *D_new(const char* const str);

void D_delete(deception_t* const D);

void D_function(deception_t* const D);

void D_display(deception_t* const D);

//random 
static inline int getRandom(int min,int max)
{
    return (rand()%(max-min+1)+min);
}