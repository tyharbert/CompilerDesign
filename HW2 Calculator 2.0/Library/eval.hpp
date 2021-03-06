// Tyler Harbert
// header file for the evaluation procedures.

#ifndef EVAL_HPP
#define EVAL_HPP

#include <iostream>
#include "expr.hpp"
#include "value.hpp"

// Evaluation function
// This function uses the visitor pattern to traverse the AST and evaluate the expression
Value eval(Expr const*);

// Different evaluation functions for each Expr type
Value eval(Bool_Literal_Expr const* e);
Value eval(Int_Literal_Expr const* e);
Value eval(Or_Expr const* e);
Value eval(And_Expr const* e); 
Value eval(Neq_Expr const* e);
Value eval(Eq_Expr const* e);
Value eval(Lt_Expr const* e);
Value eval(Gt_Expr const* e);
Value eval(Lteq_Expr const* e);
Value eval(Gteq_Expr const* e);
Value eval(Add_Expr const* e);
Value eval(Sub_Expr const* e);
Value eval(Mul_Expr const* e);
Value eval(Div_Expr const* e);
Value eval(Mod_Expr const* e);
Value eval(Neg_Expr const* e);
Value eval(Pos_Expr const* e);
Value eval(Not_Expr const* e);

// Extra function to print the ast for testing
void print(Expr const*);

# endif