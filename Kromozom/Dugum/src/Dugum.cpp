/**
* @file Dugum
* @description Kromozom ve gen işlemleri yapan program.
* @course 1. öğretim B grubu
* @assignment 1. ödev
* @date 27.11.2024
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"
#include "genBagliListe.hpp"
#include<iostream>
#include<iomanip>
#include <fstream>
#include <string>
using namespace std;
Dugum::Dugum(genBagliListe* veri)
{
    this->genler=veri;
    onceki=sonraki=0;

}
    


