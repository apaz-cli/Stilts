#!/bin/python

# [TokType, literal]

from typing import Literal


automata_description = """
/*
 * This file (Generated by GenTokTypes.py, edits will be overwritten) contains 
 * a set of rules for Stilts's NFA-based tokenizer.
 *
 * Every type of Stilts token is represented by a single deterministic finite 
 * automaton. Each automaton reads one character of the imput at a time. If 
 * the character matches a transition rule (start_range and end_range are both 
 * inclusive) and the DFA is currently in the matching start_state, then it 
 * will change state to the corresponding end_state. 
 *
 * There may be multiple transition rules that match. Ties are broken by 
 * taking the first applicable transition. If no transition rule applies, the 
 * DFA transitions into the 0 state, which is non-accepting, and no further 
 * input will be processed.
 *
 * Tokenization continues until one of the following:
 *   One or less of the DFAs are accepting
 *   The end of the file is reached.
 * At this point, we rewind to the last position where a DFA was accepting, 
 * and break any ties. We take that token, add it to the token stream, advance 
 * our position in the file, and continue for the next token. If there's no 
 * token to add because we're at the end of the file, or some type of syntax 
 * error occurred where there is no valid token to add, we stop processing and 
 * either end the token stream with the END_OF_FILE token, or throw an error.
 */
"""


def pcase(s): return [s.upper(), s.lower()]


def flowerbox(str, pad=0):
    pad = pad * ' '
    tb = pad + "/" + ("*"*(len(str)+4)) + "/\n"
    f.write(tb)
    f.write(pad + "/* " + str + " */\n")
    f.write(tb)


exact_tokens = [
    # Pragma
    pcase("native"),
    pcase("ctype"),

    # Types
    ["BOOL", "Bool"],
    ["CHAR", "Char"],
    ["UCHAR", "UChar"],
    ["SHORT", "Short"],
    ["USHORT", "UShort"],
    ["INT", "Int"],
    ["UINT", "UInt"],
    ["LONG", "Long"],
    ["FLOAT", "Float"],
    ["DOUBLE", "Double"],
    ["VOID", "Void"],

    # Control
    pcase('if'),
    pcase('else'),

    # Loops
    pcase('for'),
    pcase('while'),
    pcase('continue'),
    pcase('break'),
    pcase('in'),

    # Exceptions
    # makeLower('try'),
    # makeLower('catch'),
    # makeLower('finally'),

    # Classes
    pcase('class'),
    pcase('this'),
    pcase('operator'),
    # pcase('extends'),

    # Interfaces
    # trait is custom
    pcase('impl'),

    # Other containers
    pcase('enum'),

    # Access Modifiers
    pcase('private'),
    pcase('protected'),
    pcase('public'),

    # Builtin functions
    pcase('instanceof'),
    pcase('sizeof'),
    pcase('assert'),

    # Boolean literals
    pcase('true'),
    pcase('false'),

    # Separators
    ["LPAREN", "("],
    ["RPAREN", ")"],
    ["LBRACE", "{"],
    ["RBRACE", "}"],
    ["LBRACK", "["],
    ["RBRACK", "]"],
    ["LARROW", "<"],
    ["RARROW", ">"],
    ["SEMI", ";"],
    ["COMMA", ","],
    ["DOT", "."],
    ["STAR", "*"],
    ["EQUALS", "="],
    ["LAMBDA_ARROW", "=>"],

    # Operators
    ["BANG", "!"],
    ["TILDE", "~"],
    ["QUESTION", "?"],
    ["COLON", ":"],
    ["EQUAL", "=="],
    ["LE", "<="],
    ["GE", ">="],
    ["NOTEQUAL", "!="],
    ["AND", "&&"],
    ["OR", "||"],
    ["INC", "++"],
    ["DEC", "--"],
    ["ADD", "+"],
    ["SUB", "-"],
    ["DIV", "/"],
    ["AMP", "&"],
    ["BITOR", "|"],
    ["CARET", "^"],
    ["MOD", "%"],
    ["DEREF_ARROW", "->"],

    ["ADD_ASSIGN", "+="],
    ["SUB_ASSIGN", "-="],
    ["MUL_ASSIGN", "*="],
    ["DIV_ASSIGN", "/="],
    ["AND_ASSIGN", "&="],
    ["OR_ASSIGN", "|="],
    ["XOR_ASSIGN", "^="],
    ["MOD_ASSIGN", "%="],
]

custom_rules = """
/* IDENT */
#define IDENT_ACCEPTING 2
/* First char of idexnt, [_a-zA-Zalpha-omegaALPHA-OMEGA] */
static const DFARule IDENT_rule_1 = { .start_range = 'a', .end_range = 'z', .start_state = 1, .end_state = 2 };
static const DFARule IDENT_rule_2 = { .start_range = 'A', .end_range = 'Z', .start_state = 1, .end_state = 2 };
static const DFARule IDENT_rule_3 = { .start_range = '_', .end_range = '_', .start_state = 1, .end_state = 2 };
static const DFARule IDENT_rule_4 = { .start_range = 0xceb1, .end_range = 0xcf89, .start_state = 1, .end_state = 2 };
static const DFARule IDENT_rule_5 = { .start_range = 0xcea9, .end_range = 0xce91, .start_state = 1, .end_state = 2 };
/* Remaining chars of ident [_a-zA-Zalpha-omegaALPHA-OMEGA0-9] */
static const DFARule IDENT_rule_6 = { .start_range = 'a', .end_range = 'z', .start_state = 2, .end_state = 2 };
static const DFARule IDENT_rule_7 = { .start_range = 'A', .end_range = 'Z', .start_state = 2, .end_state = 2 };
static const DFARule IDENT_rule_8 = { .start_range = '_', .end_range = '_', .start_state = 2, .end_state = 2 };
static const DFARule IDENT_rule_9 = { .start_range = 0xceb1, .end_range = 0xcf89, .start_state = 2, .end_state = 2 };
static const DFARule IDENT_rule_10 = { .start_range = 0xcea9, .end_range = 0xce91, .start_state = 2, .end_state = 2 };
static const DFARule IDENT_rule_11 = { .start_range = '0', .end_range = '9', .start_state = 2, .end_state = 2 };

/* Whitespace (Any amount) */
#define WS_ACCEPTING 1
static const DFARule WS_rule_1 = { .start_range = ' ',   .end_range = ' ',   .start_state = 1, .end_state = 1 };
static const DFARule WS_rule_2 = { .start_range = '\\t', .end_range = '\\t', .start_state = 1, .end_state = 1 };
static const DFARule WS_rule_3 = { .start_range = '\\r', .end_range = '\\r', .start_state = 1, .end_state = 1 };
static const DFARule WS_rule_4 = { .start_range = '\\n', .end_range = '\\n', .start_state = 1, .end_state = 1 };

/* Multi-Line Comment */
#define ML_COMMENT_ACCEPTING 5
static const DFARule ML_COMMENT_rule_1 = { .start_range = '/', .end_range = '/', .start_state = 1, .end_state = 2 };
static const DFARule ML_COMMENT_rule_2 = { .start_range = '*', .end_range = '*', .start_state = 2, .end_state = 3 };
static const DFARule ML_COMMENT_rule_3 = { .start_range = '*', .end_range = '*', .start_state = 3, .end_state = 4 };
static const DFARule ML_COMMENT_rule_4 = { .start_range = '/', .end_range = '/', .start_state = 4, .end_state = 5 };
// Capture all but */ while inside comment
static const DFARule ML_COMMENT_rule_5 = { .start_range = 0, .end_range = NFASTATE_MAX, .start_state = 3, .end_state = 3 };

/* Single-Line Comment */
#define SL_COMMENT_ACCEPTING 4
static const DFARule SL_COMMENT_rule_1 = { .start_range = '/', .end_range = '/', .start_state = 1, .end_state = 2 };
static const DFARule SL_COMMENT_rule_2 = { .start_range = '/', .end_range = '/', .start_state = 2, .end_state = 3 };
static const DFARule SL_COMMENT_rule_3 = { .start_range = '\\n', .end_range = '\\n', .start_state = 3, .end_state = 4 };
// Capture all but \\n while inside comment
static const DFARule SL_COMMENT_rule_4 = { .start_range = 0, .end_range = NFASTATE_MAX, .start_state = 3, .end_state = 3 };

/* Import / Include */
#define IMPORT_ACCEPTING 8
static const DFARule IMPORT_rule_1 = { .start_range = 'i', .end_range = 'i', .start_state = 1, .end_state = 2 };
static const DFARule IMPORT_rule_2 = { .start_range = 'm', .end_range = 'i', .start_state = 2, .end_state = 3 };
static const DFARule IMPORT_rule_3 = { .start_range = 'p', .end_range = 'i', .start_state = 3, .end_state = 4 };
static const DFARule IMPORT_rule_4 = { .start_range = 'o', .end_range = 'i', .start_state = 4, .end_state = 5 };
static const DFARule IMPORT_rule_5 = { .start_range = 'r', .end_range = 'i', .start_state = 5, .end_state = 6 };
static const DFARule IMPORT_rule_6 = { .start_range = 't', .end_range = 'i', .start_state = 6, .end_state = 8 };
static const DFARule IMPORT_rule_7 = { .start_range = 'n', .end_range = 'i', .start_state = 2, .end_state = 3 };
static const DFARule IMPORT_rule_8 = { .start_range = 'c', .end_range = 'i', .start_state = 3, .end_state = 4 };
static const DFARule IMPORT_rule_9 = { .start_range = 'l', .end_range = 'i', .start_state = 4, .end_state = 5 };
static const DFARule IMPORT_rule_10 = { .start_range = 'u', .end_range = 'i', .start_state = 5, .end_state = 6 };
static const DFARule IMPORT_rule_11 = { .start_range = 'd', .end_range = 'i', .start_state = 6, .end_state = 7 };
static const DFARule IMPORT_rule_12 = { .start_range = 'e', .end_range = 'i', .start_state = 7, .end_state = 8 };

/* Trait / Interface */
#define TRAIT_ACCEPTING 10
static const DFARule TRAIT_rule_1  = { .start_range = 't', .end_range = 't', .start_state = 1, .end_state = 2 };
static const DFARule TRAIT_rule_2  = { .start_range = 'r', .end_range = 'r', .start_state = 2, .end_state = 3 };
static const DFARule TRAIT_rule_3  = { .start_range = 'a', .end_range = 'a', .start_state = 3, .end_state = 4 };
static const DFARule TRAIT_rule_4  = { .start_range = 'i', .end_range = 'i', .start_state = 4, .end_state = 5 };
static const DFARule TRAIT_rule_5  = { .start_range = 't', .end_range = 't', .start_state = 5, .end_state = 10 };
static const DFARule TRAIT_rule_6  = { .start_range = 'i', .end_range = 'i', .start_state = 1, .end_state = 2 };
static const DFARule TRAIT_rule_7  = { .start_range = 'n', .end_range = 'n', .start_state = 2, .end_state = 3 };
static const DFARule TRAIT_rule_8  = { .start_range = 't', .end_range = 't', .start_state = 3, .end_state = 4 };
static const DFARule TRAIT_rule_9  = { .start_range = 'e', .end_range = 'e', .start_state = 4, .end_state = 5 };
static const DFARule TRAIT_rule_10 = { .start_range = 'r', .end_range = 'r', .start_state = 5, .end_state = 6 };
static const DFARule TRAIT_rule_11 = { .start_range = 'f', .end_range = 'f', .start_state = 6, .end_state = 7 };
static const DFARule TRAIT_rule_12 = { .start_range = 'a', .end_range = 'a', .start_state = 7, .end_state = 8 };
static const DFARule TRAIT_rule_13 = { .start_range = 'c', .end_range = 'c', .start_state = 8, .end_state = 9 };
static const DFARule TRAIT_rule_14 = { .start_range = 'e', .end_range = 'e', .start_state = 9, .end_state = 10 };



"""

custom_tokens = ['WS', 'IMPORT', 'SL_COMMENT', 'ML_COMMENT',
                 'IDENT', 'TRAIT', 'END_OF_FILE', 'INVALID']

# name, num_rules
customInfo = [
    ['IDENT', 11],
    ['WS', 4],
    ['ML_COMMENT', 5],
    ['SL_COMMENT', 4],
    ['IMPORT', 12],
    ['TRAIT', 14]
]


def writeExactRules(exact_tokens):
    for name, literal in exact_tokens:
        f.write(f'#define {name}_ACCEPTING {len(literal)+1}\n')
        for n, c in enumerate(literal):  # For each character
            f.write(
                f'static DFARule {name}_rule_{n+1} = {{ .start_range = \'{c}\', .end_range = \'{c}\', .start_state = {n+1}, .end_state = {n+2} }};\n')
        f.write('\n')


def writeCustomRules(custom_rules):
    f.write(custom_rules + "\n\n")


def writeExactSpace(exact_tokens):
    for name, literal in exact_tokens:
        f.write(f'static DFARule {name}_rules[{len(literal)}];\n')
        f.write(f'static DFA {name}_DFA;\n')


def writeCustomSpace(tups):
    for name, num_rules in tups:
        f.write(f'static DFARule {name}_rules[{num_rules}];\n')
        f.write(f'static DFA {name}_DFA;\n')


def writeExactInit(exact_tokens):
    for name, literal in exact_tokens:
        for i in range(len(literal)):
            f.write(f'  {name}_rules[{i}] = {name}_rule_{i+1};\n')

        f.write(f'  {name}_DFA.rules = {name}_rules;\n')
        f.write(f'  {name}_DFA.num_rules = ARR_SIZE({name}_rules);\n')
        f.write(f'  {name}_DFA.accepting_state = {name}_ACCEPTING;\n')


def writeCustomInit(tups):
    for name, num_rules in tups:
        f.write(f'  /* {name} */\n')
        for i in range(num_rules):
            f.write(f'  {name}_rules[{i}] = {name}_rule_{i+1};\n')
        f.write(f'  {name}_DFA.rules = {name}_rules;\n')
        f.write(f'  {name}_DFA.num_rules = ARR_SIZE({name}_rules);\n')
        f.write(f'  {name}_DFA.accepting_state = {name}_ACCEPTING;\n\n')


def writeAllInit(dfa_names):
    for n, name in enumerate(dfa_names):
        f.write(f'  all_DFAs[{n}] = {name};\n')


with open("TokType.h", 'w') as f:
    # Header
    f.write('// THIS FILE GENERATED BY GenTokType.py. DO NOT EDIT.\n')
    f.write('#ifndef INCLUDE_TOKENS\n')
    f.write('#define INCLUDE_TOKENS\n')
    f.write('#include <apaz-libc.h>\n\n')

    # Declare token types
    f.write(f'#define NUM_TOKTYPES {len(exact_tokens) + len(custom_tokens)}\n')
    f.write('enum TokType {\n')
    [f.write(f"  {c},\n") for c in custom_tokens]
    [f.write(f"  {e[0]},\n") for e in exact_tokens]
    f.write('};\ntypedef enum TokType TokType;\n')

    # Declare reverse map from TokType to TOKNAME as a static array of string.
    dq = '"'
    nl = '\n'
    f.write(
        f'static const char* TokNameMap[] = {{{nl}{f", {nl}".join([f"  {dq}{name}{dq}" for name in [e[0] for e in exact_tokens] + custom_tokens])}\n}};{nl}{nl}')

    # Footer
    f.write("\n#endif // INCLUDE_TOKENS")

with open('Automata.h', 'w') as f:
    f.write('// THIS FILE GENERATED BY GenTokType.py. DO NOT EDIT.\n')
    f.write('#ifndef INCLUDE_AUTOMATA\n')
    f.write('#define INCLUDE_AUTOMATA\n')
    f.write('#include <apaz-libc.h>\n')
    f.write('#include "../../UTF-8.h"\n\n')

    f.write(automata_description + "\n\n")
    f.write(
        "typedef uint8_t NFAState;\n#define NFASTATE_MAX UINT8_MAX\n\nTYPE_DECLARE(DFARule);\nstruct DFARule {\n  // Start and end are inclusive\n  utf8_t start_range; utf8_t end_range;\n  NFAState start_state;\n  NFAState end_state;\n};\n\nTYPE_DECLARE(DFA);\nstruct DFA {\n  DFARule* rules;\n  size_t num_rules;\n  NFAState accepting_state;\n};\n\n")

    # Write rules
    flowerbox("Exact Tokenizer DFA Rules")
    writeExactRules(exact_tokens)
    f.write('\n')
    flowerbox("Custom Tokenizer DFA Rules")
    writeCustomRules(custom_rules)

    # Write space for DFAs
    flowerbox("DFA Space")
    writeExactSpace(exact_tokens)
    writeCustomSpace(customInfo)

    # Write space for array of all DFAs (What we actually want)
    flowerbox("All DFAs")
    dfa_names = [f"{n}_DFA" for n in [e[0]
                                      for e in exact_tokens] + custom_tokens[:len(custom_tokens)-2]]
    f.write(f'static DFA all_DFAs[{len(dfa_names)}];\n\n')

    # Write init function for what we actually want.
    f.write('/* Initializes the global variable all_DFAs. */\n')
    f.write('static inline DFA* initTokenizerDFAs() {\n')
    f.write("  /* Exact keyowrd rules */\n")
    writeExactInit(exact_tokens)
    writeCustomInit(customInfo)
    flowerbox(
        'Initialize DFA Array (The point of this entire painful episode)', pad=2)
    writeAllInit(dfa_names)
    f.write('  return all_DFAs;\n')
    f.write('}\n')

    f.write('#endif // INCLUDE_AUTOMATA\n')
