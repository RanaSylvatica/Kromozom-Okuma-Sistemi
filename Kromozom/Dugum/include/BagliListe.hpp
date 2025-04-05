/**
* @file Dugum
* @description Kromozom ve gen işlemleri yapan program.
* @course 1. öğretim B grubu
* @assignment 1. ödev
* @date 27.11.2024
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#ifndef BagliListe_hpp
#define BagliListe_hpp
#include "Dugum.hpp"
#include "genBagliListe.hpp"

class BagliListe
{
    public:
    BagliListe();
    ~BagliListe();
    void sonaEkle(genBagliListe* veri);
    void kromozomSonaEkle(genBagliListe* veri);
    void yazdir();
    Dugum* kromozomGetir(int sira);
    void genMutasyon(int sutun,int sira);
    genBagliListe* caprazla(int saitNo1,int satirNo2);
    void kromozomBirlestir(Dugum* kromozom1,Dugum* kromozom2);
    void sonKromozomuGetir(BagliListe* veri);
    void ekranaYaz();

void kromozomYazdir();

    private:
    Dugum* ilk=0;

};
#endif
