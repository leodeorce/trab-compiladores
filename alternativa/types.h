
#ifndef TYPES_H
#define TYPES_H

typedef enum{
    NUMBER_TYPE,
    STRING_TYPE,
    UNKNOWN_TYPE,
    BOOLTYPE_TYPE,
    VOID_RW_TYPE,
    NEVER_TYPE, 
    ANY_TYPE, // Used when we need to pass a non-existing type to a function.
} Type;

const char *get_text(Type type);

// Type unify_plus(Type lt, Type rt);
// Type unify_other_arith(Type lt, Type rt);
// Type unify_comp(Type lt, Type rt);

#endif // TYPES_H
