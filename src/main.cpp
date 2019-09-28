//
// Created by jinho on 9/19/2019.
//
#include <iostream>
#include "antlr4-runtime.h"
#include "Python3Lexer.h"
#include "Python3Parser.h"

using namespace antlr4;
int main(int argc, const char* argv[]){
    const std::string filepath="../test_file/new.py";
    std::ifstream ifs;
    ifs.open(filepath);
    if (!ifs.good()) {
        std::cout<<"bad";
    }
    ANTLRInputStream input(ifs);
    Python3Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    for (auto token : tokens.getTokens()) {
        std::cout << token->toString() << std::endl;
    }
    
    Python3Parser parser(&tokens);
    tree::ParseTree* tree=parser.file_input();
    std::cout << tree->toStringTree(&parser) << std::endl;
    

    ifs.close();
    
}