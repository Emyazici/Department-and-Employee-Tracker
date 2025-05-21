/*
* @file Proje1.h
* @description Bu program iki Struct yapısı üzerinde çalışır. Bu yapıları oluşturur, günceller ve bilgilerini yazdırır.
    Ayrıca Bu yapıların tutulduğu listelere göre dosyalama işlemlerini de yapar.
* @assignment 1.Proje
* @date 10.12.2024
* @author Emre Yazıcı emre_yazici@stu.fsm.edu.tr
*/

typedef struct
{
    char *calisanAdi;
    char *calisanSoyadi;
    unsigned short int birimKodu;
    float maas;
    int girisYili;
}Calisan;

typedef struct
{
    char *birimAdi;
    unsigned short int birimKodu;
    int calisanSayisi;
    Calisan **birimCalisanlar;
}Birim;

extern int birimSayisi;//Global degisken olarak birim sayisi tutulmustur

Birim birimOlustur(char *birimAdi,unsigned short int birimKodu); 
Calisan calisanOlustur(char *calisanAdi,char *calisanSoyadi,unsigned short int birimKodu,float maas,int girisYili);
int calisanSayisiHesapla(Birim **birimListesi);
void diziyeBirimEkle(Birim **birimListesi,Birim *birim); 
void birimeCalisanEkle(Birim **birimListesi,Calisan *calisan);
void printCalisan(Calisan calisan);
void printBirim(Birim birim);
void printTumBirimler(Birim **birimListesi);
float biriminMaasOrtalamasi(Birim birim);
void ortalamaMaasUstu(Birim **birimListesi);
void birimlerinEnYuksekMaasAlanlari(Birim **birimListesi);
void maasGuncelle(float yeniMaas,Birim **birimListesi);
void freeArrays(Birim **birimListesi);
void dosyayaYaz(char *dosyaIsmiCalisan,Birim **birimListesi,char *dosyaIsmiBirim);
void dosyadanOku(char *dosyaIsmiCalisan,Birim **birimListesi,char *dosyaIsmiBirim);
