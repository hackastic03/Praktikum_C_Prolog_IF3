#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

void CreateListStatik(ListStatik *l) {
    int i;
    for(i = IDX_MIN; i < CAPACITY; i++) {
        ELMT(*l, i) = MARK;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l) {
    int i = IDX_MIN;
    int length = 0;
    while ((i < CAPACITY) && (ELMT(l, i) != MARK)) {
        i++;
        length++;
    }
    return length;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l) {
    return IDX_MIN;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListStatik l) {
    return listLength(l) - 1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i) {
    return ((i >= IDX_MIN) && (i < CAPACITY));
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListStatik l, IdxType i) {
    return ((i >= IDX_MIN) && (i < listLength(l)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l) {
    return (listLength(l) == 0);
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListStatik l) {
    return (listLength(l) == CAPACITY);
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l) {
    int n;
    scanf("%d", &n);
    while (n < IDX_MIN || n > CAPACITY) {
        scanf("%d", &n);
    }

    CreateListStatik(l);
    if (n != IDX_MIN) {
        int i;
        for(i = IDX_MIN; i < n; i++) {
            scanf("%d", &ELMT(*l, i));
        }
    }
    else {
        CreateListStatik(l);
    }
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali:
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void printList(ListStatik l) {
    printf("[");
    int i;
    for(i = IDX_MIN; i < listLength(l); i++) {
        printf("%d", ELMT(l, i));
        if (i < listLength(l) - 1) {
            printf(",");
        }
    }

    printf("]");
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    ListStatik l;
    CreateListStatik(&l);
    if (plus) {
        int i;
        for (i = IDX_MIN; i < listLength(l1); i++) {
            ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    }
    else {
        int i;
        for (i = IDX_MIN; i < listLength(l1); i++) {
            ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l;
}
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2) {
    if (listLength(l1) != listLength(l2)) {
        return false;
    }
    else {
        int i;
        for (i = IDX_MIN; i < listLength(l2); i++) {
            if (ELMT(l1, i) != ELMT(l2, i)) {
                return false;
            }
        }
    }
    return true;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val) {
    if (!isEmpty(l)) {
        int i;
        for (i = IDX_MIN; i < listLength(l); i++) {
            if (val == ELMT(l, i)) {
                return i;
            }
        }
        return IDX_UNDEF;
    }
    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min) { // Menggunakan pointer karena memodifikasi nilai max min, bukan membuat variabel max min baru
    *max = ELMT(l, IDX_MIN);
    *min = ELMT(l, IDX_MIN);
    int i;
    for (i = IDX_MIN; i < listLength(l); i++) {
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
    }
}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val) { // menggunakan pointer karena memodifikasi list tanpa membuat list baru
//    insertAt(l, val, 0);
    int i;
    for(i = listLength(*l); i > IDX_MIN; i--) {
        ELMT(*l, i) = ELMT(*l, i-1);
    }
    ELMT(*l, IDX_MIN) = val;
}
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElType val, IdxType idx) {
    int i;
    for(i = listLength(*l); i > idx; i--) {
        ELMT(*l, i) = ELMT(*l, i-1);
    }
    ELMT(*l, idx) = val;
}
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val) {
    //insertAt(l, val, listLength(*l));
    ELMT(*l, listLength(*l)) = val;

}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val) {
    // deleteAt(l, val, 0);
    *val = ELMT(*l, IDX_MIN);// misal EMLT(*l, IDX_MIN)= 1, berarti *val = 1(integer)???
    int i;
    for (i = IDX_MIN; i < listLength(*l); i++) {
        ELMT(*l, i) = ELMT(*l, i+1);
    }
    ELMT(*l, listLength(*l)) = MARK;
}
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
    int i;
    *val = ELMT(*l, idx);
    for (i = idx; i < listLength(*l); i++) {
        ELMT(*l, i) = ELMT(*l, i+1);
    }
    ELMT(*l, listLength(*l)) = MARK;
}
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val) {
    *val = ELMT(*l, listLength(*l) - 1);
    ELMT(*l, listLength(*l) - 1) = MARK;
    // deleteAt(*l, *val, listLength(*l));
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc) {
    // Bubble sort
    int i, j, temp;
    for (i = IDX_MIN; i < listLength(*l); i++) {
        for (j = i; j < listLength(*l); j++) {
            if (asc) {
                if (ELMT(*l, i) > ELMT(*l, j)) {
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, i);
                    ELMT(*l, i) = temp;
                }
            }
            else {
                if (ELMT(*l, i) < ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    }
}

//int main() {
//    int x = 1;
//    ListStatik l;
//    readList(&l);
//    printList(l);
//    printf("\n");
//    sortList(&l, true);
//    printList(l);
//    printf("\n");
//    printf("Panjang: %d\n", listLength(l));
//    deleteFirst(&l, &x);
//    printList(l);
//    printf("\nPanjang baru: %d\n", listLength(l));
//    insertLast(&l, x);
//    printList(l);
//    printf("\n");
//    return 0;
//}