/**
* @file Dugum
* @description Kromozom ve gen işlemleri yapan program.
* @course 1. öğretim B grubu
* @assignment 1. ödev
* @date 27.11.2024
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include "genBagliListe.hpp"
#include<iostream>
using namespace std;
#include<iomanip>
#include <fstream>
#include <string>

genBagliListe::genBagliListe()
{
    genIlk=0;
    genSayisi=0;
}
genBagliListe::~genBagliListe()
{
    genDugum* gec=genIlk;
    while(gec!=0)
    {
        genDugum* sil=gec;//gecici
        //delete gec; bir sonraki dugumu gostermeliyiz
        gec=gec->genSonraki;
        delete sil;//once sile geci verdik. sili sildik. gecle ilerleyip silmeye devam edecegiz
    }
}
void genBagliListe::genSonaEkle(char veri)
{
    genDugum* yeni=new genDugum(veri);
    if(genIlk==0)
    {
        genIlk=yeni;
        genSayisi++;
        return;
    }
    genDugum* gec=genIlk;
    while(gec->genSonraki!=0)
        gec=gec->genSonraki;
    
    gec->genSonraki=yeni;
    yeni->genOnceki=gec;
    genSayisi++;
}

genDugum* genGetir(int sira)
{
    genDugum* ilk=0;
    int sayac=0;
    genDugum* gec=ilk;
    while(gec!=0)
    {
        if(sayac==sira)
            return gec;
        gec=gec->genSonraki;

        sayac++;
    }
    return 0; //belirtilen sırada bir kromozom yoksa
}

void genBagliListe::genCikar(int sira)
{
   genDugum*sil=genGetir(sira);
   if(sil==0)return;
   genDugum* genOnceki=sil->genOnceki;
   genDugum* genSonraki=sil->genSonraki;
   delete sil;
   
   if(genSonraki)
   {
    genSonraki->genOnceki=genOnceki;
   }
    if(genOnceki)
    {
        genOnceki->genSonraki=genSonraki;
    }
    else
        genIlk=genSonraki;
}


void genBagliListe::genSayisiArttir()
{
    genSayisi++;
}
void caprazlama(int kromozom1,int kromozom2)
{
   
}
genDugum* genBagliListe::genIlkFonksiyon()
{
    genDugum*gec=genIlk;
    return gec;
}
void genBagliListe::genSonraki(genDugum* gec)
{
    gec=gec->genSonraki;
}
void genBagliListe::genGuncelle(int sira)
{
    genDugum* gec=genIlk;
    int satirSayac=0;

    while(gec!=0)
    {
        if(satirSayac==sira)
        {
            gec->gen='X';
            return;
        }
        gec=gec->genSonraki;
        satirSayac++;

    }

}
int genBagliListe::genSayisiBul()
{
    genDugum*gec=genIlk;
    int sayac=0;

    while(gec!=0)
    {
        gec=gec->genSonraki;
        sayac++;
    }
    return sayac;
    
}

void genBagliListe::getFirstHalf(genBagliListe* yeniListe,genBagliListe* eskiListe)
{
    genDugum*gec=eskiListe->genIlk;
    int yarisi=eskiListe->genSayisiBul()/2;
    int sayac=1;
    char kopyalananVeri;
        while(gec!=0 && sayac<= yarisi)
        {
            kopyalananVeri=gec->gen;
            
            yeniListe->genSonaEkle(kopyalananVeri);
            gec=gec->genSonraki;
            sayac++;
        }
        return;
}

void genBagliListe::getSecondHalf(genBagliListe* yeniListe,genBagliListe* eskiListe)
{
    genDugum*gec=eskiListe->genIlk;
    int yarisi=eskiListe->genSayisiBul()/2;
    int sayac=1;
    char kopyalananVeri;
    while(gec!=0)
    {
        kopyalananVeri=gec->gen;
        if(eskiListe->genSayisiBul()%2==0)
        {
            if(sayac>=(yarisi+1))
            yeniListe->genSonaEkle(kopyalananVeri);
        }
        else 
        {
            if(sayac>(yarisi+1))
            yeniListe->genSonaEkle(kopyalananVeri);
        }
        gec=gec->genSonraki;
        sayac++;
    }
    return;

    
}
void genBagliListe::genEkranaYazdir(genBagliListe* kromozom)
{
    genDugum* gec=kromozom->genIlk;
    while(gec!=0)
    {
        cout<<gec->gen<<" ";
        gec=gec->genSonraki;

    }
}
char genBagliListe::kucukGeniAl()
{
    genDugum* gec=genIlk;
    char sonuc=' ';

    if(genIlk==0)
    {
        return 0;
    }
    while(gec->genSonraki!=0)
    {
        gec=gec->genSonraki;
    }
   
    while(gec!=0)
    {
        if((genIlk->gen)>(gec->gen))
        {
            sonuc=gec->gen;
            return sonuc;
        }
        gec=gec->genOnceki;
    }
    return genIlk->gen;

    
}







