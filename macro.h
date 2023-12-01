#ifndef MACRO_H
#define MACRO_H

#define FALSE 0
#define TRUE !FALSE
#define NOTEQUAL(a1,a2,b1,b2) ( ( (a1) != (b1) ) || ( (a2) != (b2) ) )
#define ISEQUAL(a1,a2,b1,b2) ( ( (a1) == (b1) ) && ( (a2) == (b2) ) )

#endif
