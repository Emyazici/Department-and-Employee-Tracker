##################################################
# * @file Makefile
# * @description Bu program iki Struct yapısı üzerinde çalışır. Bu yapıları oluşturur, günceller ve bilgilerini yazdırır.
# 	  Ayrıca Bu yapıların tutulduğu listelere göre dosyalama işlemlerini de yapar.
# * @assignment 1.Proje
# * @date 10.12.2024
# * @author Emre Yazıcı emre_yazici@stu.fsm.edu.tr
##################################################

all: projeGuz run

projeGuz: main.o Proje1.o
	gcc main.o Proje1.o -o projeGuz

main.o: main.c
	gcc -c main.c 

Proje1.o: Proje1.c Proje1.h
	gcc -c Proje1.c

clean:
	rm -f *.o projeGuz
#rm -rf *o projeGuz
#run : ./projeGuz

run:
	./projeGuz "Calisanlar.txt" "Birimler.txt"