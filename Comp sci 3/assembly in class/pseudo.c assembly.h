#pragma once

//REGISTERS
int reg0, reg1, reg2, reg3,
    reg4, reg5, reg6, reg7;
    reg8, reg9, reg10, reg11;

// FLAGS
int LT, GT, EQ, NEQ, LTE, GTE;

//SET FLAGS
int comp(int regA, int regB)
{



    LT = regA < regB;
    GT = regA >regB;
    EQ = regA == regB;
    NEQ = regA != regB;
    LTE = regA <= regB;
    GTE = regA >= regB;
}