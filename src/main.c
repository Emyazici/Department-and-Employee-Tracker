/*
* @file main.c
* @description Bu program iki Struct yapısı üzerinde çalışır. Bu yapıları oluşturur, günceller ve bilgilerini yazdırır.
    Ayrıca Bu yapıların tutulduğu listelere göre dosyalama işlemlerini de yapar.
* @assignment 1.Proje
* @date 10.12.2024
* @author Emre Yazıcı emre_yazici@stu.fsm.edu.tr
*/

#include "Proje1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char*argv[]){
   if (argc!=3) //Dosya adlari ıcin kontrol
    {
        printf("Argumanlar Yanliss..\n");
        return 1;
    }
    char *calisanIsmiDosya=argv[1]; //Calisan dosyasinin ismi arguman 1 dan
    char *birimIsmiDosya=argv[2];  //Birim dosyasinin ismi arguman 2 den
    Birim **birimListesi = (Birim**)malloc(10*sizeof(Birim*)); //Birim Listesi Olusumu, 10 ile sinirlanmistir
    if (birimListesi==NULL)
    {
        printf("Bellek tahsisi başarısız!\n");
        exit(EXIT_FAILURE);
    }

    if (birimSayisi==0)  //Birimlerin Verisi Olusmamıs ise;
    {
        dosyadanOku(calisanIsmiDosya,birimListesi,birimIsmiDosya); //Dosyadan Birim ve Calisan Verilerini Diziye Aktar
        int calisanSayisi = calisanSayisiHesapla(birimListesi);
        if (birimSayisi!=0 && calisanSayisi==0)  //Birim verileri Dosyada Var Ancak Calisan Verileri Yoksa, Calisan Verileri Manuerl Olusturulur Rapordaki main senaryosu 1
        {
        printf("Birimler Dosyadan Alindi Ancak Calisan Dosyasi Bos oldugu Icin Calisanlar Manuel Olusturuldu!!!\n");
        Calisan calisan = calisanOlustur("Emre","Yazici",3,7500.46,2013);
        birimeCalisanEkle(birimListesi,&calisan);    
        Calisan calisan1 = calisanOlustur("Eren","Yazici",3,17500.45,2013);
        birimeCalisanEkle(birimListesi,&calisan1);
        Calisan calisan2 = calisanOlustur("Ayşe","Yazici",4,27500.46,2019);
        birimeCalisanEkle(birimListesi,&calisan2);
        Calisan calisan3= calisanOlustur("Osman","Işık",4,17500.45,2014);
        birimeCalisanEkle(birimListesi,&calisan3);
        Calisan calisan4= calisanOlustur("Cihan","Cafer",5,17500.45,2013);
        birimeCalisanEkle(birimListesi,&calisan4);
        Calisan calisan5= calisanOlustur("Vera","Durmuş",6,45000.06,2019);
        birimeCalisanEkle(birimListesi,&calisan5);
        Calisan calisan6= calisanOlustur("Şevval","KOç",6,17500.45,2013);
        birimeCalisanEkle(birimListesi,&calisan6);
        Calisan calisan7= calisanOlustur("Şevval","KOç",6,17500.45,2013);
        birimeCalisanEkle(birimListesi,&calisan7);
        calisanSayisi=calisanSayisiHesapla(birimListesi);
        if (calisanSayisi==0) //Eger birimlerin ici bos ise
        {
            printf("Calisanlarin Birim Kodu Herhangi bir Birimin Birim Kodu İle Uyusmasigi Icin Program Sonlandiriliyor...\n");
            exit(EXIT_SUCCESS);
        }
        
        printf("-----------------------------------\n");
        printCalisan(calisan1);
        printBirim(*birimListesi[3]);
        printTumBirimler(birimListesi);
        for (size_t i = 0; i < birimSayisi; i++)
        {
                if (birimListesi[i]->calisanSayisi!=0)
                {
                    printf("%s Biriminin Maas Ortalamasi: %.2f\n",birimListesi[i]->birimAdi,biriminMaasOrtalamasi(*birimListesi[i]));
                    printf("-----------------------------------\n");
                }else
                printf("%s Biriminde Calisan Olmadigi Icin Ortalama Hesaplanamadi!!!\n",birimListesi[i]->birimAdi);
        }
        ortalamaMaasUstu(birimListesi);
        printf("-----------------------------------\n");
        birimlerinEnYuksekMaasAlanlari(birimListesi);
        printf("-----------------------------------\n");
        maasGuncelle(45458.45,birimListesi);
        printf("-----------------------------------\n");
        printf("%.2f\n",calisan6.maas);
        
        printf("-----------------------------------\n");
        birimlerinEnYuksekMaasAlanlari(birimListesi);
        dosyayaYaz(calisanIsmiDosya,birimListesi,birimIsmiDosya);
        freeArrays(birimListesi);

        }else if (birimSayisi!=0 && calisanSayisi!=0)   //Birim ve Calisan Dosyalarında Veriler Varsa, Hem Birim Hem Calisan Bilgileri Dosyaya Gore Olusturulur rapordaki main senaryosu 2
            {
            printf("Dosyalara Gore Birim ve Calisanlar Olusturulmustur!!!!\n ");
            printCalisan(*birimListesi[0]->birimCalisanlar[0]);
            printBirim(*birimListesi[2]);
            printTumBirimler(birimListesi);
            for (size_t i = 0; i < birimSayisi; i++)
            {
                if (birimListesi[i]->calisanSayisi!=0)
                {
                    printf("%s Biriminin Maas Ortalamasi: %.2f\n",birimListesi[i]->birimAdi,biriminMaasOrtalamasi(*birimListesi[i]));
                    printf("-----------------------------------\n");
                }else
                printf("%s Biriminde Calisan Olmadigi Icin Ortalama Hesaplanamadi!!!\n",birimListesi[i]->birimAdi);
            }
            printf("-----------------------------\n");
            ortalamaMaasUstu(birimListesi);
            printf("-----------------------------------\n");
            birimlerinEnYuksekMaasAlanlari(birimListesi);
            printf("-----------------------------------\n");
            maasGuncelle(180001.49,birimListesi);
            printf("-----------------------------------\n");
            printf("%.2f\n",birimListesi[0]->birimCalisanlar[0]->maas);
        
            printf("-----------------------------------\n");
            birimlerinEnYuksekMaasAlanlari(birimListesi);
            dosyayaYaz(calisanIsmiDosya,birimListesi,birimIsmiDosya);
            freeArrays(birimListesi);
            }  
    }

    if (birimSayisi==0)  //Dosyalar Bos ise Her Iki Yapı da Manuel Olarak Olusturulur rapordaki Main senaryosu 3
    {
        printf("Birim Dosyasi Bos Oldugu Icin bilgiler Manuel Olusturuldu\n");
        Birim birim = birimOlustur("Muhendisler",3);
        diziyeBirimEkle(birimListesi,&birim);
        Birim birim1 = birimOlustur("Isciler",4);
        diziyeBirimEkle(birimListesi,&birim1);
        Birim birim2 = birimOlustur("Ciraklar",5);
        diziyeBirimEkle(birimListesi,&birim2);
        Birim birim3 = birimOlustur("Yoneticiler",6);
        diziyeBirimEkle(birimListesi,&birim3);
        printf("-----------------------------------\n");
        Calisan calisan = calisanOlustur("Emre","Yazici",3,7500.46,2013);
        birimeCalisanEkle(birimListesi,&calisan);    
        Calisan calisan1 = calisanOlustur("Eren","Yazici",3,17500.45,2013);
        birimeCalisanEkle(birimListesi,&calisan1);
        Calisan calisan2 = calisanOlustur("Ayşe","Yazici",4,27500.46,2019);
        birimeCalisanEkle(birimListesi,&calisan2);
        Calisan calisan3= calisanOlustur("Osman","Işık",4,17500.45,2014);
        birimeCalisanEkle(birimListesi,&calisan3);
        Calisan calisan4= calisanOlustur("Cihan","Cafer",5,17500.45,2013);
        birimeCalisanEkle(birimListesi,&calisan4);
        Calisan calisan5= calisanOlustur("Vera","Durmuş",6,45000.06,2019);
        birimeCalisanEkle(birimListesi,&calisan5);
        Calisan calisan6= calisanOlustur("Şevval","KOç",6,17500.45,2013);
        birimeCalisanEkle(birimListesi,&calisan6);
        Calisan calisan7= calisanOlustur("Şevval","KOç",6,17500.45,2013);
        birimeCalisanEkle(birimListesi,&calisan7);
        int calisanSayisi = calisanSayisiHesapla(birimListesi);
        if (calisanSayisi==0)
        {
            printf("Calisanlar Birimlere Eklenemedigi Icin Program Sonlandiriliyor!!!\n");
            exit(EXIT_SUCCESS);
        }
        
        printf("-----------------------------------\n");
        printCalisan(calisan);
        printBirim(birim2);
        printTumBirimler(birimListesi);
        for (size_t i = 0; i < birimSayisi; i++)
        {
                if (birimListesi[i]->calisanSayisi!=0)
                {
                    printf("%s Biriminin Maas Ortalamasi: %.2f\n",birimListesi[i]->birimAdi,biriminMaasOrtalamasi(*birimListesi[i]));
                    printf("-----------------------------------\n");
                }else
                printf("%s Biriminde Calisan Olmadigi Icin Ortalama Hesaplanamadi!!!\n",birimListesi[i]->birimAdi);
        }
        ortalamaMaasUstu(birimListesi);
        printf("-----------------------------------\n");
        birimlerinEnYuksekMaasAlanlari(birimListesi);
        printf("-----------------------------------\n");
        maasGuncelle(45458.45,birimListesi);
        printf("-----------------------------------\n");
        printf("%.2f\n",calisan6.maas);
        
        printf("-----------------------------------\n");
        birimlerinEnYuksekMaasAlanlari(birimListesi);
        dosyayaYaz(calisanIsmiDosya,birimListesi,birimIsmiDosya);
        freeArrays(birimListesi);
    }
    return 0;
}