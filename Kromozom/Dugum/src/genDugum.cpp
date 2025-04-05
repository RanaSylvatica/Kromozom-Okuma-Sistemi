/**
* @file Dugum
* @description Kromozom ve gen işlemleri yapan program.
* @course 1. öğretim B grubu
* @assignment 1. ödev
* @date 27.11.2024
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include "genDugum.hpp"
#include<iostream>
#include "Dugum.hpp"

using namespace std;
genDugum::genDugum(char gen)
{
    this->gen=gen;
    this->genSonraki=0;
    this->genOnceki=0;

}
 

