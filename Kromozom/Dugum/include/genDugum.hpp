/**
* @file Dugum
* @description Kromozom ve gen işlemleri yapan program.
* @course 1. öğretim B grubu
* @assignment 1. ödev
* @date 27.11.2024
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#ifndef genDugum_hpp
#define genDugum_hpp

class genDugum
{
public:
    genDugum(char gen);
    char gen;
    genDugum* genSonraki;
    genDugum* genOnceki;

};

#endif