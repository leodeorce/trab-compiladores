
#include "types.h"

static const char *TYPE_STRING[] = {
    "number",
    "string",
    "unknown",
    "boolean",
    "void",
    "never",
    "any",
    "none"
};

const char *get_text(Type type) {
    return TYPE_STRING[type];
}

static const Type plus[8][8] = {
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE }
};

Type unify_plus(Type lt, Type rt) {
    return plus[lt][rt];
}

static const Type other[8][8] = {
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE }
};

Type unify_other_arith(Type lt, Type rt) {
    return other[lt][rt];
}

static const Type comp[8][8] = {
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE }
};

Type unify_comp(Type lt, Type rt) {
    return comp[lt][rt];
}
