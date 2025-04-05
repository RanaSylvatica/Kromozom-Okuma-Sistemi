/**
* @file Dugum
* @description Kromozom ve gen işlemleri yapan program.
* @course 1. öğretim B grubu
* @assignment 1. ödev
* @date 27.11.2024
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#ifndef Dugum_hpp
#define Dugum_hpp
#include "genBagliListe.hpp"

class Dugum
{
public:
    Dugum(genBagliListe* veri);
    Dugum* onceki;
    Dugum* sonraki;
    void kromozomGetir(int sira);
    void caprazla(int kromozom1,int kromozom2);
    genBagliListe* genler;

private:
    Dugum* ilk;


};

#endif