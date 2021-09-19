// THIS FILE GENERATED BY GenNodeTypes.py. DO NOT EDIT.
#ifndef INCLUDE_ASTNODEMETHODS
#define INCLUDE_ASTNODEMETHODS
#include <apaz-libc.h>
#include "ASTNodeType.h"

// To appease the linter.
// Find definitions in StructDeclarations.h.
struct ASTNode;
typedef struct ASTNode ASTNode;

static inline ASTNode* ASTNode_TopLevelDeclaration_new(Arena* arena, char* name, int status) { }
static inline char* ASTNode_TopLevelDeclaration_get_name(ASTNode* node) { }
static inline int ASTNode_TopLevelDeclaration_get_status(ASTNode* node) { }
static inline void ASTNode_TopLevelDeclaration_set_name(ASTNode* node, char* name) { }
static inline void ASTNode_TopLevelDeclaration_set_status(ASTNode* node, int status) { }
static inline void ASTNode_TopLevelDeclaration_destroy(ASTNode* node) { }
#endif // INCLUDE_ASTNODEMETHODS