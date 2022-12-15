#ifndef GLOBAL_H
#define GLOBAL_H
typedef int KeyType;


typedef struct elementtype
{
    KeyType	key;
    int year;
    float age;
    int	tmp;
    short int etype;
    union
    {
        int	year;
        float age;
        void *ptr;
        char par;
    } info;
} ElementType;

#define MAXELEMENTS 100

typedef ElementType QueueEntry;
#define MAXQUEUE MAXELEMENTS

typedef ElementType StackEntry;
#define MAXSTACK MAXELEMENTS

typedef ElementType ListEntry;
#define MAXLIST MAXELEMENTS

typedef ElementType TreeEntry;


typedef ElementType GraphEntry;
#define MAXVERTEX 6

#endif




