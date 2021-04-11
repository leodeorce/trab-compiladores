
#ifndef TYPES_H
#define TYPES_H

typedef enum {
    NUMBER_TYPE,
    STRING_TYPE,
    UNKNOWN_TYPE,
    BOOLEAN_TYPE,
    VOID_TYPE,
    NEVER_TYPE,
    ANY_TYPE,
    NO_TYPE
} Type;

const char *get_text(Type type);

Type unify_plus(Type, Type);
Type unify_other_arith(Type, Type);
Type unify_comp(Type, Type);

#endif // TYPES_H
