#ifndef RS_PARSER_H
#define RS_PARSER_H

#include <ios>
#include <string>

using namespace std;

// Math consts
//#define M_PI             3.1415926535897932384626433832795
#define F_G              9.81
#define M_E              2.71828182845904523536
#define H_LEET           1337

// Defines
#define MAX_EXPR_LEN   255
#define MAX_TOKEN_LEN  80

#define CALC_END -1
#define CALC_L_BRACKET -2
#define CALC_R_BRACKET -3
#define CALC_NUMBER -4


// Operations
#define OP_PLUS          0
#define OP_MINUS         1
#define OP_MULTIPLY      2
#define OP_DIVIDE        3
#define OP_PERCENT       4
#define OP_POWER         5
#define OP_UMINUS        6

#define OP_SIN           7
#define OP_COS           8
#define OP_TG            9
#define OP_CTG           10
#define OP_ARCSIN        11
#define OP_ARCCOS        12
#define OP_ARCTG         13
#define OP_ARCCTG        14
#define OP_SH            15
#define OP_CH            16
#define OP_TH            17
#define OP_CTH           18
#define OP_EXP           19
#define OP_LG            20
#define OP_LN            21
#define OP_SQRT          22
#define OP_IN            23
#define CALC_PI          24
#define CALC_G           25
#define CALC_LEET        26

/*****************************************************************************/

struct RS_ParserNode
{
    double value;
    RS_ParserNode *left;
    RS_ParserNode *right;
    RS_ParserNode(
        double _value = 0.0,
        RS_ParserNode *_left = nullptr,
        RS_ParserNode *_right = nullptr
    )
    {
        value = _value;
        left = _left;
        right = _right;
    }
};

/*****************************************************************************/

class RS_Parser
{
    private:
    RS_ParserNode *root;
        char *expr;
        char curToken[MAX_TOKEN_LEN];
        int typToken;
        int pos;
        double result;
    private:
        RS_ParserNode *CreateNode(
            double _value = 0.0,
            RS_ParserNode *_left = nullptr,
            RS_ParserNode *_right = nullptr
        );
        RS_ParserNode *Expr(void);
        RS_ParserNode *Expr1(void);
        RS_ParserNode *Expr2(void);
        RS_ParserNode *Expr3(void);
        RS_ParserNode *Expr4(void);
        bool GetToken(void);
        bool IsDelim(void);
        bool IsLetter(void);
        bool IsDigit(void);
        bool IsPoint(void);
        double CalcTree(RS_ParserNode *tree);
        void  DelTree(RS_ParserNode *tree);
        void SendError(int errNum);
    public:
        RS_Parser();
        ~RS_Parser();
        bool Compile(char *expr);
        double Evaluate();
        double GetResult(void);
};

/*****************************************************************************/

#endif // RS_PARSER_H
