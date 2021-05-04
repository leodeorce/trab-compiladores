
#ifndef TYPES_H
#define TYPES_H

typedef enum {
    NUMBER_TYPE,
    STRING_TYPE,
    BOOLEAN_TYPE,
    UNDEFINED_TYPE,
    NO_TYPE
} Type;

typedef enum {  // Basic conversions between types.
    N2S,
    B2S,
    U2S,
    N2U,
    S2U,
    B2U,
    NONE,
} Conv;

const char *get_text(Type type);

Type unify_plus(Type, Type);
Type unify_other_arith(Type, Type);
Type unify_comp(Type, Type);

#endif // TYPES_H
