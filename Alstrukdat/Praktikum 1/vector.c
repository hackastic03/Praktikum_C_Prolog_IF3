/* File: vector.h */
/* Tanggal: 03 September 2022 */
#include "../../Pra-Praktikum/Praktikum 1/point.h"
#include <stdio.h>
#include <math.h>

#ifndef VECTOR_H
#define VECTOR_H

/* *** Definisi ABSTRACT DATA TYPE VECTOR *** */
#define VECTOR POINT
/* *** Notasi Akses: Selektor VECTOR *** */
#define AbsisComponent(V) Absis(V)
#define OrdinatComponent(V) Ordinat(V)

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
void CreateVector(VECTOR *v, float x, float y) {
    Absis(*v) = x;
    Ordinat(*v) = y;
}
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v) {
    printf("%.02f,%.02f", Absis(v), Ordinat(v));
}
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v) {
    return sqrt(pow(AbsisComponent(v), 2) + pow(OrdinatComponent(v), 2));
}
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
VECTOR Add(VECTOR a, VECTOR b) {
    VECTOR c;
    AbsisComponent(c) = AbsisComponent(a) + AbsisComponent(b);
    OrdinatComponent(c) = OrdinatComponent(a) + OrdinatComponent(b);
    return c;
}
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
VECTOR Substract(VECTOR a, VECTOR b) {
    VECTOR c;
    AbsisComponent(c) = AbsisComponent(a) - AbsisComponent(b);
    OrdinatComponent(c) = OrdinatComponent(a) - OrdinatComponent(b);
    return c;
}
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
float Dot(VECTOR a, VECTOR b) {
    return ((AbsisComponent(a) * AbsisComponent(b)) + (OrdinatComponent(a) * OrdinatComponent(b)));
}
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
VECTOR Multiply(VECTOR v, float s) {
    VECTOR c;
    AbsisComponent(c) = AbsisComponent(v) * s;
    OrdinatComponent(c) = OrdinatComponent(v) * s;
    return c;
}
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * v.x, s * v.y) */

#endif