/**
* @file Dugum
* @description Kromozom ve gen işlemleri yapan program.
* @course 1. öğretim B grubu
* @assignment 1. ödev
* @date 27.11.2024
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include "BagliListe.hpp"
#include<iostream>
using namespace std;
#include<iomanip>
#include <fstream>
#include <string>


BagliListe::BagliListe()
{
    ilk=0;
}
BagliListe::~BagliListe()
{
    Dugum* gec=ilk;
    while(gec!=0)
    {
        Dugum* sil=gec;//gecici
        //delete gec; bir sonraki dugumu gostermeliyiz
        gec=gec->sonraki;
        delete sil->genler;
        delete sil;//once sile geci verdik. sili sildik. gecle ilerleyip silmeye devam edecegiz
    }
   
}
void BagliListe::sonaEkle(genBagliListe* veri)
{
    Dugum* yeni=new Dugum(veri);
    if(ilk==0)
    {
        ilk=yeni;
        return;
    }
    Dugum* gec=ilk;
    while(gec->sonraki!=0)
        gec=gec->sonraki;
    
    gec->sonraki=yeni;
    yeni->onceki=gec;
    
}
void BagliListe::kromozomSonaEkle(genBagliListe* veri)
{
    //Yeni düğüm oluşturma
    Dugum* yeni=new Dugum(veri);

    //Hata var!!!!
    if(ilk==0)
    {
        ilk=yeni;
        return;
    }
    Dugum* gec=ilk;
    while(gec->sonraki!=0)
        gec=gec->sonraki;
    
    gec->sonraki=yeni;
    yeni->onceki=gec;
    
    
}




Dugum* BagliListe::kromozomGetir(int sira)
{
    int sayac=0;
    Dugum* gec=ilk;
    while(gec!=0)
    {
        if(sayac==sira)
            return gec;
        gec=gec->sonraki;

        sayac++;


    }
     //belirtilen sırada bir kromozom yoksa  
}

void BagliListe::genMutasyon(int sutun,int sira)
{
   
    Dugum* gec=ilk;
   
    int sutunSayac=0;
    int satirSayac=0;

    while(gec!=0)
    {
        if(sutunSayac==sutun)
        {
            genDugum* genilk= gec->genler->genIlkFonksiyon();

            while(genilk!=0){
            if(satirSayac==sira)
            {
                gec->genler->genGuncelle(satirSayac);
                return;
            }
            gec->genler->genSonraki(genilk);
            satirSayac++;
            }
        }
        gec=gec->sonraki;
        sutunSayac++;
    }
   

}



genBagliListe* BagliListe::caprazla(int satirNo1, int satirNo2)
{
   Dugum* gec=ilk;

   genBagliListe* yeniGenListe=new genBagliListe();
   gec->genler->getFirstHalf(yeniGenListe,kromozomGetir(satirNo1)->genler);
   gec->genler->getSecondHalf(yeniGenListe,kromozomGetir(satirNo2)->genler);
   return yeniGenListe;

}

void BagliListe::ekranaYaz()
{
    Dugum* gec=ilk;
    string cikti=" ";
    while(gec!=0)
    {
    cikti+=gec->genler->kucukGeniAl();
    gec=gec->sonraki;
    }
    cout<<cikti;
}


void BagliListe::kromozomYazdir()
{
    Dugum* gec=ilk;
    while(gec!=0)
    {
        gec->genler->genEkranaYazdir(gec->genler);
        cout<<endl;
        gec=gec->sonraki;
    }

}


