#include <string>
#include <iostream>
#include <fstream>  
#include<sstream>

using namespace std;
void dosyaOku();
int toplamTransfer();
void transferListele();
void supheliBul();
const int matrisBoyutu = 50;
//int matrix[matrisBoyutu][matrisBoyutu] = { 0 };



void dosyaOku(ifstream& kisiFirmaDosyası, ifstream& transferDosyasi, ofstream& toplamTransferDosyasi)
{
    const string kisiFirmaDosyaYolu = "C:/Users/Merve/Desktop/Algoritma/kisilervefirmalar.txt";
    const string transferDosyaYolu = "C:/Users/Merve/Desktop/Algoritma/transfer.txt";
    const string toplamTransferDosyasiYolu = "C:/Users/Merve/Desktop/Algoritma/toplam_transfer.txt";
}

int toplamTransfer()
{
    int satirToplami = 0;
    int geciciDegisken = 0;  // gecici değişken 
    int matrix[matrisBoyutu][matrisBoyutu] = { 0 };

    ifstream matrisOku("C:/Users/Merve/Desktop/Algoritma/transfer.txt");
    if (!matrisOku.is_open())
    {
        cout << "Dosya acilamadi!" << endl;
        return 1;
    }

    ofstream dosyayaYaz("C:/Users/Merve/Desktop/Algoritma/toplam_transfer.txt");
    if (!dosyayaYaz.is_open())
    {
        cout << "Dosya olusturulamadi!" << endl;
        return 1;
    }

    matrisOku.ignore(numeric_limits<streamsize>::max(), '\n'); //ID'leri işleme katmamak için bir satır atla 

    for (int i = 0; i < matrisBoyutu; i++)
    {
        satirToplami = 0; //  Her satırın toplamını sıfırla

        matrisOku.ignore(numeric_limits<streamsize>::max(), '\t'); //  bir sutün atla matrix toplamını doğru hesaplamak için 

        for (int j = 0; j < matrisBoyutu; j++)
        {
            matrisOku >> geciciDegisken;
            if (matrisOku.fail())
            {
                cout << "Veri okuma hatasi" << endl;
                return 1;
            }
            satirToplami += geciciDegisken;
            matrix[i][j] = geciciDegisken; //  matrix'e değerleri ekle
        }
        cout << satirToplami << endl;
        dosyayaYaz << satirToplami << endl;
    }

    for (int i = 0; i < matrisBoyutu; i++)
    {
        satirToplami = 0;
        for (int j = 0; j < matrisBoyutu; j++)
        {
            satirToplami += matrix[i][j];
        }

    }

    matrisOku.close();
    dosyayaYaz.close();
    return 0;
}

void transferListele(const char* dosyaAdi) {
    ifstream dosya("C:/Users/Merve/Desktop/Algoritma/toplam_transfer.txt");

    if (!dosya.is_open()) {
        cout << "Dosya acma hatasi!" << endl;

    }

    int sayilar[matrisBoyutu];
    int sayi;
    int sayiAdedi = 0;

    // Dosyadan sayıları oku ve diziye ekle
    while (dosya >> sayi && sayiAdedi < matrisBoyutu) {
        sayilar[sayiAdedi++] = sayi;
    }

    // Bubble Sort ile sırala
    for (int i = 0; i < sayiAdedi - 1; ++i) {
        for (int j = 0; j < sayiAdedi - i - 1; ++j) {
            if (sayilar[j] < sayilar[j + 1]) {
                int temp = sayilar[j];
                sayilar[j] = sayilar[j + 1];
                sayilar[j + 1] = temp;
            }
        }
    }

    // Sıralanmış diziyi alt alta yazdır
    cout << "Siralanan sayilar: " << endl;
    for (int i = 0; i < sayiAdedi; ++i) {
        cout << sayilar[i] << endl;
    }

    dosya.close();
}


struct KisiFirmaBilgisi {
    int ID;
    string ad;
    int maksimumKapasite;
    int vergiBeyani;
};