/**
* @file Dugum
* @description Kromozom ve gen işlemleri yapan program.
* @course 1. öğretim B grubu
* @assignment 1. ödev
* @date 27.11.2024
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#ifndef genBagliListe_hpp
#define genBagliListe_hpp
#include "genDugum.hpp"

class genBagliListe
{
    public:
    genBagliListe();
    ~genBagliListe();
    void genSonaEkle(char gen);
    int genSayisi;
    void genSayisiArttir();
    void caprazlama();
    void genMutasyon(int sutun,int sira);
    void genSonraki(genDugum* gec);
    void genGuncelle(int sira);
    genDugum* genIlkFonksiyon();
    int genSayisiBul();
    void genEkle(char gen);
    void genleriBol1(genBagliListe* yeniListe);
    void genleriBirlestir(genDugum* gen1,genDugum*  gen2);
    void getFirstHalf(genBagliListe* yeniListe,genBagliListe* eskiListe);
    void getSecondHalf(genBagliListe* yeniListe,genBagliListe* eskiListe);
    char kucukGeniAl();
    void genEkranaYazdir(genBagliListe* kromozom);

    private:
    genDugum* genIlk;
    void genCikar(int sira);
};

#endif
