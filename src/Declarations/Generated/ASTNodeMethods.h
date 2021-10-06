// THIS FILE GENERATED BY GenNodeTypes.py. DO NOT EDIT.
#ifndef INCLUDE_ASTNODEMETHODS
#define INCLUDE_ASTNODEMETHODS
#include "../StructDeclarations.h"
#include "ASTNodeType.h"
#include <apaz-libc.h>

/****************/
/* Info Structs */
/****************/
struct CompilationUnit_Info {
  char* fname;
};
typedef struct CompilationUnit_Info CompilationUnit_Info;

struct TopLevelDecl_Info {
  char* name;
};
typedef struct TopLevelDecl_Info TopLevelDecl_Info;

struct EnumDecl_Info {
  char* name;
};
typedef struct EnumDecl_Info EnumDecl_Info;

struct TraitDecl_Info {
  char* name;
};
typedef struct TraitDecl_Info TraitDecl_Info;

struct ClassDecl_Info {
  char* name;
};
typedef struct ClassDecl_Info ClassDecl_Info;

struct FunctionDecl_Info {
  char* name;
};
typedef struct FunctionDecl_Info FunctionDecl_Info;

struct CTypeDecl_Info {
  char* name;
  char* cname;
};
typedef struct CTypeDecl_Info CTypeDecl_Info;

struct GlobalVarDecl_Info {
  char* name;
  char* type;
};
typedef struct GlobalVarDecl_Info GlobalVarDecl_Info;

struct Expression_Info {
  char* method;
  List_ASTNode on_list;
  bool compile;
};
typedef struct Expression_Info Expression_Info;



/******************/
/* Struct Getters */
/******************/
static inline CompilationUnit_Info* ASTNode_CompilationUnit_getInfo(ASTNode* node) { return (CompilationUnit_Info*)node->typed_info; }
static inline TopLevelDecl_Info* ASTNode_TopLevelDecl_getInfo(ASTNode* node) { return (TopLevelDecl_Info*)node->typed_info; }
static inline EnumDecl_Info* ASTNode_EnumDecl_getInfo(ASTNode* node) { return (EnumDecl_Info*)node->typed_info; }
static inline TraitDecl_Info* ASTNode_TraitDecl_getInfo(ASTNode* node) { return (TraitDecl_Info*)node->typed_info; }
static inline ClassDecl_Info* ASTNode_ClassDecl_getInfo(ASTNode* node) { return (ClassDecl_Info*)node->typed_info; }
static inline FunctionDecl_Info* ASTNode_FunctionDecl_getInfo(ASTNode* node) { return (FunctionDecl_Info*)node->typed_info; }
static inline CTypeDecl_Info* ASTNode_CTypeDecl_getInfo(ASTNode* node) { return (CTypeDecl_Info*)node->typed_info; }
static inline GlobalVarDecl_Info* ASTNode_GlobalVarDecl_getInfo(ASTNode* node) { return (GlobalVarDecl_Info*)node->typed_info; }
static inline Expression_Info* ASTNode_Expression_getInfo(ASTNode* node) { return (Expression_Info*)node->typed_info; }


/****************/
/* Constructors */
/****************/
static inline ASTNode* ASTNode_CompilationUnit_new(Arena* arena) { ASTNode* node = (ASTNode*)Arena_malloc(arena, sizeof(ASTNode)+sizeof(CompilationUnit_Info)); CompilationUnit_Info* info = (CompilationUnit_Info*)(((char*)node) + sizeof(ASTNode)); node->typed_info = (void*)info; return node;}
static inline ASTNode* ASTNode_TopLevelDecl_new(Arena* arena) { ASTNode* node = (ASTNode*)Arena_malloc(arena, sizeof(ASTNode)+sizeof(TopLevelDecl_Info)); TopLevelDecl_Info* info = (TopLevelDecl_Info*)(((char*)node) + sizeof(ASTNode)); node->typed_info = (void*)info; return node;}
static inline ASTNode* ASTNode_EnumDecl_new(Arena* arena) { ASTNode* node = (ASTNode*)Arena_malloc(arena, sizeof(ASTNode)+sizeof(EnumDecl_Info)); EnumDecl_Info* info = (EnumDecl_Info*)(((char*)node) + sizeof(ASTNode)); node->typed_info = (void*)info; return node;}
static inline ASTNode* ASTNode_TraitDecl_new(Arena* arena) { ASTNode* node = (ASTNode*)Arena_malloc(arena, sizeof(ASTNode)+sizeof(TraitDecl_Info)); TraitDecl_Info* info = (TraitDecl_Info*)(((char*)node) + sizeof(ASTNode)); node->typed_info = (void*)info; return node;}
static inline ASTNode* ASTNode_ClassDecl_new(Arena* arena) { ASTNode* node = (ASTNode*)Arena_malloc(arena, sizeof(ASTNode)+sizeof(ClassDecl_Info)); ClassDecl_Info* info = (ClassDecl_Info*)(((char*)node) + sizeof(ASTNode)); node->typed_info = (void*)info; return node;}
static inline ASTNode* ASTNode_FunctionDecl_new(Arena* arena) { ASTNode* node = (ASTNode*)Arena_malloc(arena, sizeof(ASTNode)+sizeof(FunctionDecl_Info)); FunctionDecl_Info* info = (FunctionDecl_Info*)(((char*)node) + sizeof(ASTNode)); node->typed_info = (void*)info; return node;}
static inline ASTNode* ASTNode_CTypeDecl_new(Arena* arena) { ASTNode* node = (ASTNode*)Arena_malloc(arena, sizeof(ASTNode)+sizeof(CTypeDecl_Info)); CTypeDecl_Info* info = (CTypeDecl_Info*)(((char*)node) + sizeof(ASTNode)); node->typed_info = (void*)info; return node;}
static inline ASTNode* ASTNode_GlobalVarDecl_new(Arena* arena) { ASTNode* node = (ASTNode*)Arena_malloc(arena, sizeof(ASTNode)+sizeof(GlobalVarDecl_Info)); GlobalVarDecl_Info* info = (GlobalVarDecl_Info*)(((char*)node) + sizeof(ASTNode)); node->typed_info = (void*)info; return node;}
static inline ASTNode* ASTNode_Expression_new(Arena* arena) { ASTNode* node = (ASTNode*)Arena_malloc(arena, sizeof(ASTNode)+sizeof(Expression_Info)); Expression_Info* info = (Expression_Info*)(((char*)node) + sizeof(ASTNode)); node->typed_info = (void*)info; return node;}


/***********/
/* Getters */
/***********/
static inline char* ASTNode_CompilationUnit_get_fname(ASTNode* node) { return ASTNode_CompilationUnit_getInfo(node)->fname; }
static inline char* ASTNode_TopLevelDecl_get_name(ASTNode* node) { return ASTNode_TopLevelDecl_getInfo(node)->name; }
static inline char* ASTNode_EnumDecl_get_name(ASTNode* node) { return ASTNode_EnumDecl_getInfo(node)->name; }
static inline char* ASTNode_TraitDecl_get_name(ASTNode* node) { return ASTNode_TraitDecl_getInfo(node)->name; }
static inline char* ASTNode_ClassDecl_get_name(ASTNode* node) { return ASTNode_ClassDecl_getInfo(node)->name; }
static inline char* ASTNode_FunctionDecl_get_name(ASTNode* node) { return ASTNode_FunctionDecl_getInfo(node)->name; }
static inline char* ASTNode_CTypeDecl_get_name(ASTNode* node) { return ASTNode_CTypeDecl_getInfo(node)->name; }
static inline char* ASTNode_CTypeDecl_get_cname(ASTNode* node) { return ASTNode_CTypeDecl_getInfo(node)->cname; }
static inline char* ASTNode_GlobalVarDecl_get_name(ASTNode* node) { return ASTNode_GlobalVarDecl_getInfo(node)->name; }
static inline char* ASTNode_GlobalVarDecl_get_type(ASTNode* node) { return ASTNode_GlobalVarDecl_getInfo(node)->type; }
static inline char* ASTNode_Expression_get_method(ASTNode* node) { return ASTNode_Expression_getInfo(node)->method; }
static inline List_ASTNode ASTNode_Expression_get_on_list(ASTNode* node) { return ASTNode_Expression_getInfo(node)->on_list; }
static inline bool ASTNode_Expression_get_compile(ASTNode* node) { return ASTNode_Expression_getInfo(node)->compile; }


/***********/
/* Setters */
/***********/
static inline void ASTNode_CompilationUnit_set_fname(ASTNode* node, char* fname) { ASTNode_CompilationUnit_getInfo(node)->fname = fname; }
static inline void ASTNode_TopLevelDecl_set_name(ASTNode* node, char* name) { ASTNode_TopLevelDecl_getInfo(node)->name = name; }
static inline void ASTNode_EnumDecl_set_name(ASTNode* node, char* name) { ASTNode_EnumDecl_getInfo(node)->name = name; }
static inline void ASTNode_TraitDecl_set_name(ASTNode* node, char* name) { ASTNode_TraitDecl_getInfo(node)->name = name; }
static inline void ASTNode_ClassDecl_set_name(ASTNode* node, char* name) { ASTNode_ClassDecl_getInfo(node)->name = name; }
static inline void ASTNode_FunctionDecl_set_name(ASTNode* node, char* name) { ASTNode_FunctionDecl_getInfo(node)->name = name; }
static inline void ASTNode_CTypeDecl_set_name(ASTNode* node, char* name) { ASTNode_CTypeDecl_getInfo(node)->name = name; }
static inline void ASTNode_CTypeDecl_set_cname(ASTNode* node, char* cname) { ASTNode_CTypeDecl_getInfo(node)->cname = cname; }
static inline void ASTNode_GlobalVarDecl_set_name(ASTNode* node, char* name) { ASTNode_GlobalVarDecl_getInfo(node)->name = name; }
static inline void ASTNode_GlobalVarDecl_set_type(ASTNode* node, char* type) { ASTNode_GlobalVarDecl_getInfo(node)->type = type; }
static inline void ASTNode_Expression_set_method(ASTNode* node, char* method) { ASTNode_Expression_getInfo(node)->method = method; }
static inline void ASTNode_Expression_set_on_list(ASTNode* node, List_ASTNode on_list) { ASTNode_Expression_getInfo(node)->on_list = on_list; }
static inline void ASTNode_Expression_set_compile(ASTNode* node, bool compile) { ASTNode_Expression_getInfo(node)->compile = compile; }


/**************/
/* Print Node */
/**************/
static inline void ASTNode_CompilationUnit_print(ASTNode* node) { const char* name = ASTNodeTypeNameMap[node->type]; printf("Type: %s\n", TokNameMap[node->type]);}
static inline void ASTNode_TopLevelDecl_print(ASTNode* node) { const char* name = ASTNodeTypeNameMap[node->type]; printf("Type: %s\n", TokNameMap[node->type]);}
static inline void ASTNode_EnumDecl_print(ASTNode* node) { const char* name = ASTNodeTypeNameMap[node->type]; printf("Type: %s\n", TokNameMap[node->type]);}
static inline void ASTNode_TraitDecl_print(ASTNode* node) { const char* name = ASTNodeTypeNameMap[node->type]; printf("Type: %s\n", TokNameMap[node->type]);}
static inline void ASTNode_ClassDecl_print(ASTNode* node) { const char* name = ASTNodeTypeNameMap[node->type]; printf("Type: %s\n", TokNameMap[node->type]);}
static inline void ASTNode_FunctionDecl_print(ASTNode* node) { const char* name = ASTNodeTypeNameMap[node->type]; printf("Type: %s\n", TokNameMap[node->type]);}
static inline void ASTNode_CTypeDecl_print(ASTNode* node) { const char* name = ASTNodeTypeNameMap[node->type]; printf("Type: %s\n", TokNameMap[node->type]);}
static inline void ASTNode_GlobalVarDecl_print(ASTNode* node) { const char* name = ASTNodeTypeNameMap[node->type]; printf("Type: %s\n", TokNameMap[node->type]);}
static inline void ASTNode_Expression_print(ASTNode* node) { const char* name = ASTNodeTypeNameMap[node->type]; printf("Type: %s\n", TokNameMap[node->type]);}

typedef void (*ASTNodePrintFn)(ASTNode*);
static inline ASTNodePrintFn AST_dispatch_print(ASTNodeType type) {
  switch(type) {
    case CompilationUnit: return ASTNode_CompilationUnit_print;
    case TopLevelDecl: return ASTNode_TopLevelDecl_print;
    case EnumDecl: return ASTNode_EnumDecl_print;
    case TraitDecl: return ASTNode_TraitDecl_print;
    case ClassDecl: return ASTNode_ClassDecl_print;
    case FunctionDecl: return ASTNode_FunctionDecl_print;
    case CTypeDecl: return ASTNode_CTypeDecl_print;
    case GlobalVarDecl: return ASTNode_GlobalVarDecl_print;
    case Expression: return ASTNode_Expression_print;
    default: return (ASTNodePrintFn)NULL; // Have fun dereferencing null, lmao
  }
}

static inline void AST_print(AST* ast, TraversalOrder order) {
  if (order == POSTORDER)
    for (size_t i = 0; i < ast->num_children; i++)
      AST_print(ast->children + i, order);
  if (order == POSTORDER_BACKWARD)
    for (int i = ast->num_children; i --> 0;)
      AST_print(ast->children + i, order);
  AST_dispatch_print(ast->type)(ast);
  if (order == PREORDER)
    for (size_t i = 0; i < ast->num_children; i++)
      AST_print(ast->children + i, order);  
  if (order == PREORDER_BACKWARD)
    for (int i = ast->num_children; i --> 0;)
      AST_print(ast->children + i, order);
}

#endif // INCLUDE_ASTNODEMETHODS