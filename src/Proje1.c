/*
* @file Proje1.c
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
int birimSayisi = 0;
Birim birimOlustur(char *birimAdi,unsigned short int birimKodu){
    Birim birim;
    birim.birimAdi=(char*)malloc(30+1);
    if (birim.birimAdi == NULL)
    {
        printf("Bellek Tahsisi Hatasi (birimadi)\n");
        exit(EXIT_FAILURE);
    }

    birim.birimCalisanlar = (Calisan **)malloc(20 * sizeof(Calisan*)); //Her bir birim icin 20 calisan siniri konulmuştur
    if (birim.birimCalisanlar==NULL)
    {
        printf("Bellek Tahsisi Hatasi (birimCalisnlar)\n");
        exit(EXIT_FAILURE);
    }

    strcpy(birim.birimAdi,birimAdi);
    birim.birimKodu=birimKodu;
    birim.calisanSayisi=0;
    printf("%s Adli Birim Basariyla Olusturuldu\n",birim.birimAdi);
    
    return birim;
}

Calisan calisanOlustur(char *calisanAdi,char *calisanSoyadi,unsigned short int birimKodu,float maas,int girisYili){
    Calisan calisan;
    calisan.calisanAdi=(char*)malloc(30+1);
    if (calisan.calisanAdi==NULL)
    {
        printf("Bellek Tahsisi Hatasi (calisanAdi)\n");
        exit(EXIT_FAILURE);
    }

    calisan.calisanSoyadi=(char*)malloc(30+1);
    if (calisan.calisanSoyadi==NULL)
    {
        printf("Bellek Tahsisi Hatasi (calisanSoyadi)\n");
        exit(EXIT_FAILURE);
    }
    
    strcpy(calisan.calisanAdi,calisanAdi);
    strcpy(calisan.calisanSoyadi,calisanSoyadi);
    calisan.birimKodu=birimKodu;
    calisan.maas=maas;
    calisan.girisYili=girisYili;
    printf("%s Adli Calisan Basari Ile Olusturuldu\n",calisan.calisanAdi);
    
    return calisan;
}

int calisanSayisiHesapla(Birim **birimListesi){ //Butun Calisan Sayisini Hesaplar
    int sayi = 0;
    for (size_t i = 0; i < birimSayisi; i++)
    {
        for (size_t j = 0; j < birimListesi[i]->calisanSayisi; j++)
        {
            sayi++;
        }
    }
    return sayi;
}

void diziyeBirimEkle(Birim **birimListesi,Birim *birim){
    if (birimSayisi==10) //Birim Sayisi Kontrolu, Doluysa Birim Eklenmez
    {
        printf("Birim Listesi Doldugu Icin Birim Eklenememistir\n");
        return;
    }else{
        (birimListesi)[birimSayisi]=birim;
        printf("%s Birimi Birimler Listesine Eklenmistir\n",birim->birimAdi);
        printf("-----------------------------------\n");
        birimSayisi++;
    }
}

void birimeCalisanEkle(Birim **birimListesi, Calisan *calisan){
    for (size_t j = 0; j < birimSayisi; j++) //Birim Listesi gezilir
    {
        for (size_t k = 0; k < birimListesi[j]->calisanSayisi; k++) //her birimin calisanlari tek tek gezilir
        {                      
            if (strcmp(birimListesi[j]->birimCalisanlar[k]->calisanAdi,calisan->calisanAdi)==0) //Eger Ayni Calisan 2 defa eklenmek isteniyorsa fonksiyon sonlanir
            {
                printf("%s Adinda Calisan Zaten Mevcut Oldugu icin Listeye Eklenemedi..\n",calisan->calisanAdi);
                return;
            }
        }
    }
      
    int i; 
    if (birimSayisi>0)
    {
        for (i = 0; i < birimSayisi; i++)//Birim Listesi gezilir
        {
            if ((birimListesi)[i]->birimKodu == calisan->birimKodu) //Eger birim kodu, calisan kodu ile eslesirse calisan birime eklenir
            {
                (birimListesi)[i]->birimCalisanlar[(birimListesi)[i]->calisanSayisi]=calisan;
                printf("%s adli çalışan %s birimine eklendi\n",calisan->calisanAdi,(birimListesi)[i]->birimAdi);
                (birimListesi)[i]->calisanSayisi++; //Birimin Calisan sayisi arttirilir
                printf("-----------------------------------\n");
                break;
            }
        }
    }else{
        printf("Birimler Olusmamis..\n");//Birim sayisi 0 ise;
        return;
    }
}

void printCalisan(Calisan calisan){
    printf("Calisan Adi: %s\n",calisan.calisanAdi);
    printf("Calisan Soyadi: %s\n",calisan.calisanSoyadi);
    printf("Calisan Birim Kodu: %d\n",calisan.birimKodu);
    printf("Calisan Maasi: %.2f\n",calisan.maas);
    printf("Calisan Giris Yili: %d\n",calisan.girisYili);
    printf("-----------------------------------\n");
}

void printBirim(Birim birim){
    printf("Birim Adi: %s\n",birim.birimAdi);
    printf("Birim Kodu: %d\n",birim.birimKodu);
    printf("Calisan Sayisi: %d\n",birim.calisanSayisi);
    for (int i = 0; i < birim.calisanSayisi; i++)
    {
       printf("%d. Calisan Adi: %s\n",i+1,birim.birimCalisanlar[i]->calisanAdi);
        printf("%d. Calisan Soyadi: %s\n",i+1,birim.birimCalisanlar[i]->calisanSoyadi);
        printf("%d. Calisan Birim Kodu: %d\n",i+1,birim.birimCalisanlar[i]->birimKodu);
        printf("%d. Calisan Maasi: %.2f\n",i+1,birim.birimCalisanlar[i]->maas);
        printf("%d. Calisan Giris Yili: %d\n",i+1,birim.birimCalisanlar[i]->girisYili);
    }
    printf("-----------------------------------\n");
}

void printTumBirimler(Birim **birimListesi){
    for (int i = 0; i < birimSayisi; i++)
    {
        printBirim(*(birimListesi[i]));
        printf("-----------------------------------\n");
    }
}

float biriminMaasOrtalamasi(Birim birim){
    float ortalamaMaas = 0.0;
    float toplamMaas = 0.0;
    
    for (int i = 0; i < birim.calisanSayisi; i++)
    {
        toplamMaas+=birim.birimCalisanlar[i]->maas;
        
    }
    if (toplamMaas==0.00) //Eger toplam maas 0 sa hic calisan olmadigi anlamina gelir
    {
       return 0;
    }else
    return toplamMaas/birim.calisanSayisi; //toplam maas calisan sayisina bolunerek ortalama return edilir
}

void ortalamaMaasUstu(Birim **birimListesi){
    float ortalama = 0.0;
    int i = 0;
    for (i = 0; i < birimSayisi; i++)
    {
        int j;
        ortalama=biriminMaasOrtalamasi(*(birimListesi[i]));
        if (ortalama==0) //ortalama 0 ise calisan olmadigi mesaji verilir
        {
            printf("%s Biriminde Calisan Olmadigi Icin Ortalama Maas Ustu Hesaplanamadi!!!\n",birimListesi[i]->birimAdi);
        }
        
        for (size_t k = 0; k < birimListesi[i]->calisanSayisi; k++)
        {
            if ( (float)ortalama == birimListesi[i]->birimCalisanlar[k]->maas) //Eger otalama calisanlarin maasina esit ise herkes ayni maasi alir
        {
            printf("%s Biriminde Herkes Ayni Maasi Aldigi Icin Ortalama Ustu Kimse Maas Almiyor...\n",birimListesi[i]->birimAdi);
            
        }
        }
        
        for (j = 0; j < birimListesi[i]->calisanSayisi; j++)
        {
            if (birimListesi[i]->birimCalisanlar[j]->maas > ortalama)
            {
                printf("%s Biriminde %s Adli Calisan Ortalamanin Ustunde Maas Aliyor\n",birimListesi[i]->birimAdi,birimListesi[i]->birimCalisanlar[j]->calisanAdi);
            }
            
        }
    }
}

void birimlerinEnYuksekMaasAlanlari(Birim **birimListesi){
    float enYuksekMass = 0.00;
    int i;
    int j;
    int kont = 0; //En yuksek maas alanin index ini tutar
    
    for (i = 0; i < birimSayisi; i++)
    {       
        enYuksekMass=0.00;
        kont=0;
        if (birimListesi[i]->calisanSayisi==0)
        {
            printf("%s Biriminde Calisan Yok...\n",birimListesi[i]->birimAdi);
        }else{
            float ort = biriminMaasOrtalamasi(*birimListesi[i]);
            for (j = 0; j < birimListesi[i]->calisanSayisi; j++)
            {
                if (birimListesi[i]->birimCalisanlar[j]->maas > enYuksekMass)
                {
                enYuksekMass=birimListesi[i]->birimCalisanlar[j]->maas;
                kont=j;
                }
            }
                if (ort != enYuksekMass)
                {
                printf("%s Biriminde %s Adli Calisan En Yukses Maasi Aliyor\n",birimListesi[i]->birimAdi,birimListesi[i]->birimCalisanlar[kont]->calisanAdi);
                }else{
                printf("%s Biriminde Kimse En Yuksek Maasi Almiyor, Herkes Ayni Maasi Aliyor\n",birimListesi[i]->birimAdi);
            }
        }
    }
}

void maasGuncelle(float yeniMaas,Birim **birimListesi) {
    int kont = -1; //Maas degisimi olduysa 0 a esitlenir
    for (size_t i = 0; i < birimSayisi; i++)
    {
        for (size_t j = 0; j <birimListesi[i]->calisanSayisi; j++)
        {
            if (birimListesi[i]->birimCalisanlar[j]->maas<yeniMaas && birimListesi[i]->birimCalisanlar[j]->girisYili<2014)//Yil ve maas sarti uygun ise
            {
                birimListesi[i]->birimCalisanlar[j]->maas=yeniMaas;
                
                printf("%s nin maaşı %.2f oldu\n",birimListesi[i]->birimCalisanlar[j]->calisanAdi,yeniMaas);
                kont = 0;
            }
        }
    }
    if (kont==-1)//Maas degisimi olmamis ise;
    {
        printf("Sartlar Uymadigi Icin Kimsenin Maasi Degismedi!!!\n");
    }
    printf("-----------------------------------\n");
}

void freeArrays(Birim **birimListesi){
    for (size_t i = 0; i < birimSayisi; i++)
    {
        free((birimListesi)[i]->birimAdi);
        for (size_t j = 0; j < birimListesi[i]->calisanSayisi; j++)
        {
            free((birimListesi)[i]->birimCalisanlar[j]->calisanAdi);
            free((birimListesi)[i]->birimCalisanlar[j]->calisanSoyadi);
        }
        free((birimListesi)[i]->birimCalisanlar);
    }
    free(birimListesi);
}

void dosyayaYaz(char *dosyaIsmiCalisan,Birim **birimListesi,char *dosyaIsmiBirim){
    FILE *dosyaCalisan=fopen(dosyaIsmiCalisan,"w"); 
    if (dosyaCalisan==NULL)
    {
        printf("Dosya Acilamiyor...\n");
        exit(EXIT_FAILURE);
    }

    FILE *dosyaBirim = fopen(dosyaIsmiBirim,"w");
    if (dosyaBirim==NULL)
    {
        printf("Dosya Acilamiyor...\n");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    int j = 0;
    if (birimSayisi==0)
    {
        printf("Birim Olmadigi Icin Calisanlara ve Birimlere erisilemiyor!!!\n");
        exit(EXIT_FAILURE);
    }else{
        
        for (i = 0; i < birimSayisi; i++)
          {
            if (birimListesi[i]->calisanSayisi==0)
            {
                printf("%s Biriminde Calisan Olmadigi Icin Bu Birim Icin Calisan Yazdirilmadi!!!\n",birimListesi[i]->birimAdi);
            }else{
                    for ( j = 0; j< birimListesi[i]->calisanSayisi; j++) //Calisan Bilgileri Dosyaya Yazdirilir
                    {
                        fprintf(dosyaCalisan,"%s\n",birimListesi[i]->birimCalisanlar[j]->calisanAdi);
                        fprintf(dosyaCalisan,"%s\n",birimListesi[i]->birimCalisanlar[j]->calisanSoyadi);
                        fprintf(dosyaCalisan, "%hu\n", birimListesi[i]->birimCalisanlar[j]->birimKodu); 
                        fprintf(dosyaCalisan, "%.2f\n", birimListesi[i]->birimCalisanlar[j]->maas);    
                        fprintf(dosyaCalisan, "%d\n", birimListesi[i]->birimCalisanlar[j]->girisYili); 
                        printf("%s Biriminin %d. Calisani Yazdirildi\n",birimListesi[i]->birimAdi,j+1);
                    }
                 }
          }
        }

    i=0;
    j=0;

    for ( i = 0; i < birimSayisi; i++) //Birim Bilgileri Ilgili Dosyaya Yazdirilir
    {
        fprintf(dosyaBirim,"%s\n",birimListesi[i]->birimAdi);
        fprintf(dosyaBirim, "%hu\n",birimListesi[i]->birimKodu); 
        fprintf(dosyaBirim, "%hu\n",birimListesi[i]->calisanSayisi); 
        printf("%d. Birim Yazdirildi\n",i+1);
    }
    printf("-----------------------------------\n");
    fclose(dosyaCalisan);
    fclose(dosyaBirim);
}

void dosyadanOku(char *dosyaIsmiCalisan,Birim **birimListesi,char *dosyaIsmiBirim){
    FILE *dosyaCalisan=fopen(dosyaIsmiCalisan,"r"); //Calisanlar Icin Okuma Islemi
    if (dosyaCalisan==NULL)
    {
        printf("Dosya Acilamiyor...\n");
        return;
    }

    FILE *dosyaBirim = fopen(dosyaIsmiBirim,"r"); //Birimler İçin Okuma İşlemi
    if (dosyaBirim==NULL)
    {
        printf("Dosya Acilamiyor...\n");
        return;
    }

    if (fgetc(dosyaBirim)==EOF) //Birim Dosyasi nin icerik kontrolu
    {
        printf("Birimler Dosyasi Bos oldugu Icin Dosyadan Veriler Diziye Aktarilamadi!!! Lutfen Verileri Kendiniz Olusturunuz\n");
        fclose(dosyaBirim);
        return;
    }else{
    int satirSayisi = 0;
    char ch;
    rewind(dosyaBirim);//Dosya pozisyonu basa alindi

    // Dosyayı karakter karakter oku
        while ((ch = fgetc(dosyaBirim)) != EOF) {
            if (ch == '\n') { // Satır sonu karakteri kontrolü
                satirSayisi++;
            }
        }
        rewind(dosyaBirim);//Dosya pozisyonu basa alindi
        for (size_t i = 0; i < satirSayisi/3; i++) //Ilgili veriler okunup birim olusturuldu
        {
            char name[30];
            int birimKodu;
            int calisanSayisi;
            fgets(name,sizeof(name),dosyaBirim);
            name[strcspn(name,"\n")]='\0';
            fscanf(dosyaBirim,"%d\n",&birimKodu);
            fscanf(dosyaBirim,"%d\n",&calisanSayisi);
            Birim *newBirim = (Birim*)malloc(sizeof(Birim));
            if (newBirim==NULL)
            {
                printf("Bellek Hatasi birimOlustur!!!\n");
            }
            
            *newBirim = birimOlustur(name,birimKodu);
            diziyeBirimEkle(birimListesi,newBirim);
            printf("%zu. Birim Dosyadan Okundu\n",i+1);
        }
    fclose(dosyaBirim);
        
    }

    if (fgetc(dosyaCalisan)==EOF) //Calisan Dosyasinin Icerik Kontrolu
    {
        printf("Calisanlar Dosyasi Bos oldugu Icin Dosyadan Veriler Diziye Aktarilamadi!!!\n");
        fclose(dosyaCalisan);
        return;
    }else{
        int satirSayisi = 0;
        char ch;
        rewind(dosyaCalisan);//Dosya pozisyonu basa alindi

    // Dosyayı karakter karakter oku
        while ((ch = fgetc(dosyaCalisan)) != EOF) {
            if (ch == '\n') { // Satır sonu karakteri kontrolü
                satirSayisi++;
            }
        }
        rewind(dosyaCalisan);//Dosya pozisyonu basa alindi
        for (size_t i = 0; i < satirSayisi/5; i++) //Dosyadaki verilere gore calisanlar olusturuldu
        {
            char calisanAdi[30];
            char calisanSoyadi[30];
            unsigned short int birimKodu;
            float maas;
            int girisYili;

            fgets(calisanAdi,sizeof(calisanAdi),dosyaCalisan);
            calisanAdi[strcspn(calisanAdi,"\n")]='\0';
            fgets(calisanSoyadi,sizeof(calisanSoyadi),dosyaCalisan);
            calisanSoyadi[strcspn(calisanSoyadi,"\n")]='\0';
            fscanf(dosyaCalisan,"%hu\n",&birimKodu);
            fscanf(dosyaCalisan,"%f\n",&maas);
            fscanf(dosyaCalisan,"%d\n",&girisYili);
            Calisan *newCalisan = (Calisan*)malloc(sizeof(Calisan));
            *newCalisan = calisanOlustur(calisanAdi,calisanSoyadi,birimKodu,maas,girisYili);
            birimeCalisanEkle(birimListesi,newCalisan);
            printf("%zu. calisan dosyadan okundu...\n",i+1);
        }

        int calisanSayi = calisanSayisiHesapla(birimListesi);
        if (calisanSayi == 0)//Calisanlar Birimlerde Degilse Program Sonlandirilsin
        {
            printf("Calisanlarin Birim Kodu Herhangi bir Birimin Birim Kodu İle Uyusmasigi Icin Program Sonlandiriliyor...\n");
            exit(EXIT_SUCCESS);
        }
        
        fclose(dosyaCalisan);
    }
} 
