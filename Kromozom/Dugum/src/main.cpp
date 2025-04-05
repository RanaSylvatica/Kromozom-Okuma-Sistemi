/**
* @file Dugum
* @description Kromozom ve gen işlemleri yapan program.
* @course 1. öğretim B grubu
* @assignment 1. ödev
* @date 27.11.2024
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<string>
using namespace std;
#include "genDugum.hpp"
#include "BagliListe.hpp"
#include "genBagliListe.hpp"
#include "Dugum.hpp"



int main()
{
    
    ifstream dosya("Dna.txt");
    string satir;
    BagliListe* liste=new BagliListe();

    while(getline(dosya,satir))//dosyadan her bir satiri alir ve satira aktarir. aktaramazsa 0 ciktisini verir.
    {

        genBagliListe* genListe=new genBagliListe();

        for (int i = 0; i<satir.length(); i++)
        {
            if(satir[i] != 32)
            {
                genListe->genSonaEkle(satir[i]);
            }
        }
        liste->sonaEkle(genListe);
    }



    ifstream dosya2("Islemler.txt");    
    string islem;

    while ((getline(dosya2,islem)))
    {
        stringstream ss(islem);
        char harf=' ';
        int sayi1=0;
        int sayi2=0;
        string karakter;
        int sayac=0;
        while(ss>>karakter)
        {
        
            if(isalpha(karakter[0]))
            {
                harf=karakter[0];
                sayac++;
            }
            else if(sayac==1)
            {
                sayi1=stoi(karakter);
                sayac++;
            }
            else if(sayac==2)
            {
                sayi2=stoi(karakter);
                sayac++;
            }
            

        }
        
        if(sayac==3)
        {
        switch (harf)
            {
            case 'C':
            {
                liste->sonaEkle(liste->caprazla(sayi1,sayi2));
                liste->sonaEkle(liste->caprazla(sayi2,sayi1));
                //liste->kromozomYazdir();

                cout<<"islem tamamlanmistir.";

                break;


            }
            case 'M':
                liste->genMutasyon(sayi1,sayi2);
                cout<<"islem tamamlanmistir.";
                //liste->kromozomYazdir();


                break;
            
            
            default:
                    cout<<"Lutfen gecerli bilgileri giriniz.";
                break;
            }
        }
        else if(sayac==1)
        {
            switch (harf)
                {
                case 'E':
                    liste->ekranaYaz();
                    break;
                case 'S':
                    delete liste;
                    cout<<"Tum dugumler silinmistir.";

                    return 0;
                
                default:
                    cout<<"Lutfen gecerli bilgileri giriniz.";
                    return 0;
                    break;
                }
        }
        else 
        {
        cout<<"Lutfen 1 veya 3 adet veri giriniz.";
        return 0;
        }
    }   
}