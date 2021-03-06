//Tyler Harbert
// code file for the elaboration procedures for type checking the expression.

#include "elaborate.hpp"

// Elaborate function
// This function uses the visitor pattern to traverse the AST and type check each expression
Type* elaborate(Expr const* e){
    
    struct V: Visit {
        Type* result;
        
        void visit(Bool_Literal_Expr const* e) { result = elaborate(e); }
        void visit(Int_Literal_Expr const* e) { result = elaborate(e); }
        void visit(Or_Expr const* e) { result = elaborate(e); }
        void visit(And_Expr const* e) { result = elaborate(e); }
        void visit(Neq_Expr const* e) { result = elaborate(e); }
        void visit(Eq_Expr const* e) { result = elaborate(e); }
        void visit(Lt_Expr const* e) { result = elaborate(e); }
        void visit(Gt_Expr const* e) { result = elaborate(e); }
        void visit(Lteq_Expr const* e) { result = elaborate(e); }
        void visit(Gteq_Expr const* e) { result = elaborate(e); }
        void visit(Add_Expr const* e) { result = elaborate(e); }
        void visit(Sub_Expr const* e) { result = elaborate(e); }
        void visit(Mul_Expr const* e) { result = elaborate(e); }
        void visit(Div_Expr const* e) { result = elaborate(e); }
        void visit(Mod_Expr const* e) { result = elaborate(e); }
        void visit(Neg_Expr const* e) { result = elaborate(e); }
        void visit(Pos_Expr const* e) { result = elaborate(e); }
        void visit(Not_Expr const* e) { result = elaborate(e); }
    };
    
    V v;
    e->accept(v);
    return v.result;
}

// Different elaboration functions for each Expr type

Type* elaborate(Bool_Literal_Expr const* e){
    return get_bool_type();
}

Type* elaborate(Int_Literal_Expr const* e){
    return get_int_type();
}

Type* elaborate(Or_Expr const* e){
    Type* bool_type = get_bool_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == bool_type)
        if (t2 == bool_type)
            return bool_type;
    
    throw std::runtime_error("|| type error.");
}

Type* elaborate(And_Expr const* e){
    Type* bool_type = get_bool_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == bool_type)
        if (t2 == bool_type)
            return bool_type;
    
    throw std::runtime_error("&& type error.");
}

Type* elaborate(Neq_Expr const* e){
    Type* bool_type = get_bool_type();
    Type* int_type = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == bool_type)
        if (t2 == bool_type)
            return bool_type;
    
    if (t1 == int_type)
        if (t2 == int_type)
            return bool_type;
    
    throw std::runtime_error("!= type error.");
}

Type* elaborate(Eq_Expr const* e){
    Type* bool_type = get_bool_type();
    Type* int_type = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == bool_type)
        if (t2 == bool_type)
            return bool_type;
    
    if (t1 == int_type)
        if (t2 == int_type)
            return bool_type;
    
    throw std::runtime_error("== type error.");
}

Type* elaborate(Lt_Expr const* e){
    Type* int_type = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == int_type)
        if (t2 == int_type)
            return get_bool_type();
    
    throw std::runtime_error("< type error.");
}

Type* elaborate(Gt_Expr const* e){
    Type* int_type = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == int_type)
        if (t2 == int_type)
            return get_bool_type();
    
    throw std::runtime_error("> type error.");
}

Type* elaborate(Lteq_Expr const* e){
    Type* int_type = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == int_type)
        if (t2 == int_type)
            return get_bool_type();
    
    throw std::runtime_error("<= type error.");
}

Type* elaborate(Gteq_Expr const* e){
    Type* int_type = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == int_type)
        if (t2 == int_type)
            return get_bool_type();
    
    throw std::runtime_error(">= type error.");
}

Type* elaborate(Add_Expr const* e){
    Type* int_type = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == int_type)
        if (t2 == int_type)
            return int_type;
    
    throw std::runtime_error("add type error.");
}

Type* elaborate(Sub_Expr const* e){
    Type* int_type = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == int_type)
        if (t2 == int_type)
            return int_type;
    
    throw std::runtime_error("subtract type error.");
}

Type* elaborate(Mul_Expr const* e){
    Type* int_type = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == int_type)
        if (t2 == int_type)
            return int_type;
    
    throw std::runtime_error("* type error.");
}

Type* elaborate(Div_Expr const* e){
    Type* int_type = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == int_type)
        if (t2 == int_type)
            return int_type;
    
    throw std::runtime_error("/ type error.");
}

Type* elaborate(Mod_Expr const* e){
    Type* int_type = get_int_type();
    Type* t1 = elaborate(e->e1);
    Type* t2 = elaborate(e->e2);
    
    if (t1 == int_type)
        if (t2 == int_type)
            return int_type;
    
    throw std::runtime_error("% type error.");
}

Type* elaborate(Neg_Expr const* e){
    Type* bool_type = get_bool_type();
    Type* t = elaborate(e->ex);
    
    if (t == bool_type)
        return bool_type;
    
    throw std::runtime_error("! type error.");
}

Type* elaborate(Pos_Expr const* e){
    Type* int_type = get_int_type();
    Type* t = elaborate(e->ex);
    
    if (t == int_type)
        return int_type;
    
    throw std::runtime_error("negative type error.");
}

Type* elaborate(Not_Expr const* e){
    Type* int_type = get_int_type();
    Type* t = elaborate(e->ex);
    
    if (t == int_type)
        return int_type;
    
    throw std::runtime_error("positive type error.");
}