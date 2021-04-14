
#include "types.h"

static const char *TYPE_STRING[] = {
    "number",
    "string",
    "boolean",
    "undefined",
    "notype"
};

const char *get_text(Type type) {
    return TYPE_STRING[type];
}

static const Type plus[4][4] = {
    { NUMBER_TYPE, STRING_TYPE, NO_TYPE,     NO_TYPE      },
    { STRING_TYPE, STRING_TYPE, STRING_TYPE, STRING_TYPE  },
    { NO_TYPE,     STRING_TYPE, NO_TYPE,     NO_TYPE      },
    { NO_TYPE,     STRING_TYPE, NO_TYPE,     NO_TYPE      }
};

Type unify_plus(Type lt, Type rt) {
    return plus[lt][rt];
}

static const Type other[4][4] = {
    { NUMBER_TYPE, NO_TYPE, NO_TYPE, NO_TYPE  },
    { NO_TYPE,     NO_TYPE, NO_TYPE, NO_TYPE  },
    { NO_TYPE,     NO_TYPE, NO_TYPE, NO_TYPE  },
    { NO_TYPE,     NO_TYPE, NO_TYPE, NO_TYPE  }
};

Type unify_other_arith(Type lt, Type rt) {
    return other[lt][rt];
}

static const Type comp[4][4] = {
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE  },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE  },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE  },
    { NO_TYPE, NO_TYPE, NO_TYPE, NO_TYPE  }
};

Type unify_comp(Type lt, Type rt) {
    return comp[lt][rt];
}
