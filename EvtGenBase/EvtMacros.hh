// Useful macros.

// In copy constructors, deep copy pointers via CLONE
// and date members via COPY. 'other' is the name of the copied object

#define COPY_PTR( X ) X( other.X ? other.X->clone() : 0 )
#define COPY_MEM( X ) X( other.X )
