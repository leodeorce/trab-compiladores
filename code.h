#ifndef CODE_H
#define CODE_H

#include "ast.h"

/**
 * Caminha pela AST e gera o código MIPS em stdout.
 * @param ast AST
 */
void emit_code(AST *ast);

#endif
