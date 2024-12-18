#include<iostream>
#include<string>
#include<fstream>
#include<locale.h>     
//locale.h kütüphanesi ile programda türkçe karakterleri kullanabilmek için kullandım

using namespace std;

const int MAX_KITAP_SAYISI = 100;


/*******************************************************************
		YAPMAK İSTEDİĞİMİZ İŞLEMLERİN FONKSİYONLARINI TANIMLAMA
*******************************************************************/


void uyeEkle();                              // Üye ekleme işlemini gerçekleştiren fonksiyon
void uyeleriDosyayaYaz();                    // Üyeleri dosyaya yazan fonksiyon
void kitapEkle();                            // Kitap ekleme işlemini gerçekleştiren fonksiyon
void kitaplariDosyayaYaz();                  // Kitapları dosyaya yazan fonksiyon
void kitapOduncAl();                         // Kitap ödünç alma işlemini gerçekleştiren fonksiyon
void oduncVerilenKitaplarListesi();          // Ödünç verilen kitapları listeleyen fonksiyon
void kitapIadeEt();                          // Kitap iade etme işlemini gerçekleştiren fonksiyon
void kitapSil();                             // Kitap silme işlemini gerçekleştiren fonksiyon
void uyeSil();                               // Üye silme işlemini gerçekleştiren fonksiyon
void listele_kaydedilen_kitaplar();          // Kaydedilen kitapları listeler
void kitapAra();                             // Kaydedilen kitabı arama fonksiyonu
void uyeAra();                               // Kaydedilen üyeyi bulma fonksiyonu

bool kullaniciGiris(string kullaniciAdi, string sifre)
{
	return (kullaniciAdi == "sifre" && sifre == "123");
}


/*******************************************************************
	MENU FONKSİYONUNU KULLANARAK PROGRAMI DURDURMA
	KOMUTU GİRİLENE KADAR TEKRAR KULLANMAYI SAĞLARIZ
*******************************************************************/


int menu()
{
	// yapabileceğimiz işlemleri seçme

	int secim;

	cout << endl << endl;
	cout << "\t\t*--------------------------" << endl;

	cout << endl << endl;
	cout << "\t\t" << "   1.Üye ekleme." << endl;

	cout << "\t\t" << "   2.Üyeleri listeleme." << endl;

	cout << "\t\t" << "   3.Kitap ekleme." << endl;

	cout << "\t\t" << "   4.Kitapları dosyala." << endl;

	cout << "\t\t" << "   5.Kitapları listele." << endl;

	cout << "\t\t" << "   6.Kitap ödünç verme." << endl;

	cout << "\t\t" << "   7.Kitap ödünç alanlar listesi." << endl;

	cout << "\t\t" << "   8.Kitap iade etme." << endl;

	cout << "\t\t" << "   9.Kitap silme." << endl;

	cout << "\t\t" << "   10.Üye silme işlemi." << endl;

	cout << "\t\t" << "   11.Kitap bulma." << endl;

	cout << "\t\t" << "   12.Üye bulma." << endl;

	cout << "\t\t" << "   0.Programı kapatınız" << endl << endl;

	cout << "\t\t*--------------------------" << endl << endl;


	cout << "\t\tLüthen yapmak istediğiniz işlemi giriniz.  ";
	cin >> secim;
	cout << endl << endl;

	return secim;
}

/*******************************************************************
		MAİN FONKSİYONU İLE YAPMAK İSTEDİĞİM SEÇİMİ YAPMA
*******************************************************************/

int main()
{
	setlocale(LC_ALL, "Turkish");

	cout << endl;
	cout << "\t\t**" << endl;
	cout << "\t\t\tKÜTÜPHANE OTOMASYONUNA HOŞGELDİNİZ" << endl;
	cout << "\t\t**" << endl << endl;



	// Üyelerin bilgilerini kaydeden dosya

	ofstream uyelerDosyasi("C:\\Users\\Zehra Bağçe\\Desktop\\uyeler.txt", ios::app);
	uyelerDosyasi.close();

	string kullaniciAdi, sifre;

	cout << "\t\t" << "----------------------------------" << endl;
	cout << "\t\t" << "Admin Adi: ";
	getline(cin, kullaniciAdi);

	cout << "\t\t" << "Sifre: ";
	getline(cin, sifre);

	cout << "\t\t" << "----------------------------------" << endl;

	cout << endl;

	if (!kullaniciGiris(kullaniciAdi, sifre)) {
		cout << "\t\t" << "-------------------------Giris basarisiz!----------------------" << endl;
		return 0;
	}


	int secim = menu();

	// Menüyü göster ve kullanıcının seçimini al

	while (secim != 0)
	{
		switch (secim)
		{
		case 1: uyeEkle();
			break;

		case 2: uyeleriDosyayaYaz();
			break;

		case 3: kitapEkle();
			break;

		case 4: kitaplariDosyayaYaz();
			break;

		case 5: listele_kaydedilen_kitaplar();
			break;

		case 6: kitapOduncAl();
			break;

		case 7: oduncVerilenKitaplarListesi();
			break;

		case 8: kitapIadeEt();
			break;

		case 9: kitapSil();
			break;

		case 10: uyeSil();
			break;

		case 11: kitapAra();
			break;

		case 12: uyeAra();
			break;

		default:
			cout << "\t\tHatali secim yaptiniz, ana menuye yonlendiriliyorsunuz... " << endl;

		}

		secim = menu();
	}

	//0 girildiğinde program kapatılır

	cout << "\t\tProgram kapatıldı!!!" << endl;

	return 0;
}

/*******************************************************************
			YENİ ÜYELER EKLEME FONKSİYONU
*******************************************************************/


void uyeEkle()
{
	//kullanıcı bilgilerini klavyeden alma

	string ad, soyad, kullaniciAdi, id;

	cout << "\t\tAd: ";
	cin >> ad;

	cout << "\t\tSoyad: ";
	cin >> soyad;

	cout << "\t\tKullanıcı Adı: ";
	cin >> kullaniciAdi;

	cout << "\t\tÜye id:";
	cin >> id;


	// yeni üyeyi dosyaya kaydetme

	ofstream uyelerDosyasi("C:\\Users\\Zehra Bağçe\\Desktop\\uyeler.txt", ios::app);

	if (uyelerDosyasi.is_open())
	{

		uyelerDosyasi << "Ad:" << ad << " " << "Soyad:" << soyad << " " << "Kullanici Adi:" << kullaniciAdi << " " << "ID:" << id << endl;
		uyelerDosyasi.close();

		cout << "\t\tÜye başarıyla kaydedildi!" << endl;
	}
	else
	{
		cout << "\t\tDosya açılırken bir hata oluştu." << endl;
	}
}


/*******************************************************************
			 ÜYE OLAN KİŞİLERİ GÖSTEREN FONKSİYONU
*******************************************************************/

void uyeleriDosyayaYaz()
{
	//üye olanları gösterebilmesi için kaydettiğimiz üyelerin olduğu dosya girilir

	ifstream uyelerDosyasi("uyeler.txt");
	ofstream uyeListesiDosyası("uyeler_listesi.txt");

	string satir;

	if (uyelerDosyasi.is_open())
		//dosya açılır ve üyeler sırasıyla gösterilir
	{
		while (getline(uyelerDosyasi, satir))
		{
			cout << "\t\t" << satir << endl << endl;
		}

		uyelerDosyasi.close();
	}
	else
	{
		cout << "\t\tDosya açılırken bir hata oluştu." << endl << endl;
	}
}

/*******************************************************************
		KİTAP EKLEME FONKSİYONU
*******************************************************************/


void kitapEkle()
{
	//kitap eklemek için gerekli bilgiler kullanıcıdan alınır

	string kitapAdi, yazarAdi, kitapTuru;

	cout << "\t\tKitap Adi: ";

	cin.ignore();
	getline(cin, kitapAdi);

	cout << "\t\tYazar Adi: ";
	getline(cin, yazarAdi);

	cout << "\t\tKitap Türü: ";
	getline(cin, kitapTuru);

	//kitapları eklemek istediğimiz dosyaya ekleme yapılır

	ofstream kitaplarDosyasi("kitaplar.txt", ios::app);

	if (kitaplarDosyasi.is_open())
		//dosyaya kitaplar istenilen bilgiler doğrultusunda kaydedilir
	{
		kitaplarDosyasi << "Kitap Adi: " << kitapAdi << "\tYazar Adi: " << yazarAdi << "\tKitap Turu: " << kitapTuru << endl;
		kitaplarDosyasi.close();

		cout << "\t\tKitap basariyla eklendi!" << endl << endl;
	}
	else
	{
		cout << "\t\tDosya acilirken bir hata olustu." << endl << endl;
	}
}

/*******************************************************************
		EKLENEN KİTAPLARI GÖSTEREN FONKSİYONU
*******************************************************************/

void kitaplariDosyayaYaz()
{
	//eklenen kitapları gösterebilmek için kitapları eklediğiimiz dosya açılır

	ifstream kitaplarDosyasi("kitaplar.txt");
	ofstream kitapListesiDosyasi("kitap_listesi.txt");

	if (kitaplarDosyasi.is_open() && kitapListesiDosyasi.is_open())
	{
		string line;

		//dosyanın açılması halinde eklenen kitaplar sırasıyla gösterilir

		while (getline(kitaplarDosyasi, line))
		{
			kitapListesiDosyasi << line << endl;
		}

		kitaplarDosyasi.close();
		kitapListesiDosyasi.close();

		cout << "\t\tKitaplar dosyaya yazildi." << endl;

	}
	else
	{
		cout << "\t\tDosya acilirken bir hata olustu." << endl << endl;
	}
}

/*******************************************************************
		KAYDEDİLEN KİTAPLARI LİSTELEYEN FONKSİYONU
*******************************************************************/

void listele_kaydedilen_kitaplar()
{
	//daha önceden kaydettiğimiz kitapların bulunduğu dosyayı açar

	ifstream dosya("kitaplar.txt");
	string kitaplar[MAX_KITAP_SAYISI];

	int kitap_sayisi = 0;

	if (dosya.is_open())
	{
		string satir;

		while (getline(dosya, satir))
		{
			kitaplar[kitap_sayisi] = satir;
			kitap_sayisi++;

			if (kitap_sayisi >= MAX_KITAP_SAYISI)
			{
				break;
			}
		}
		dosya.close();

		if (kitap_sayisi > 0)
		{
			cout << "\t\tKaydedilen Kitaplar:" << endl;
			for (int i = 0; i < kitap_sayisi; i++)
			{
				//kaydedilen kitapları sırasıyla for döngüsü kullanarak yazarız
				cout << "\t\t" << kitaplar[i] << endl;
			}
		}
		else
		{
			cout << "\t\tKaydedilen kitap bulunamadi." << endl;
		}
	}
	else
	{
		cout << "\t\tDosya acilamadi." << endl;
	}

}

/*******************************************************************
		KİTAP ÖDÜNÇ ALMA FONKSİYONU
*******************************************************************/

void kitapOduncAl()
{
	//ödünç almak istediğimiz kitap için gerekli bilgiler tanımlanır

	string kitapAdi, kullaniciAdi;

	cout << "\t\tKitap Adı: ";

	cin.ignore();
	getline(cin, kitapAdi);

	cout << "\t\tKullanıcı Adı: ";
	getline(cin, kullaniciAdi);

	//eklenen kitapların dosyası açılır

	ifstream kitaplarDosyasi("kitaplar.txt");
	ofstream oduncVerilenKitaplarDosyasi("odunc_verilen_kitaplar.txt", ios::app);

	if (kitaplarDosyasi.is_open() && oduncVerilenKitaplarDosyasi.is_open())
	{
		bool kitapBulundu = false;
		string satir;
		string oduncVerilenKitaplar;

		while (getline(kitaplarDosyasi, satir))
		{
			if (satir.find(kitapAdi) != string::npos)
			{
				kitapBulundu = true;
				oduncVerilenKitaplar += "Kitap Adı: " + kitapAdi + "\tKullanıcı Adı: " + kullaniciAdi + "\n";
			}
			else
			{
				oduncVerilenKitaplar += satir + "\n";
			}
		}

		kitaplarDosyasi.close();
		oduncVerilenKitaplarDosyasi << oduncVerilenKitaplar;
		oduncVerilenKitaplarDosyasi.close();

		if (kitapBulundu)
		{
			//istenilen kitap eğer önceden dosyaya kaydedildi ise bu metin gösterilir

			cout << "\t\tKitap ödünç verildi!" << endl;
			kitaplariDosyayaYaz();
		}
		else
		{
			cout << "\t\tKitap bulunamadı." << endl;
		}
	}
	else
	{
		cout << "\t\tDosya açılırken bir hata oluştu." << endl;
	}


}



/*******************************************************************
			ÖDÜNÇ VERİLEN KİTAPLARI GÖSTEREN FONKSİYON
*******************************************************************/

void oduncVerilenKitaplarListesi()
{
	//ödünç verilen kitapları gösterebilmek için ödünç verilenleri kaydedttiğimiz dosya açılır

	ifstream oduncDosyasi("odunc_verilen_kitaplar.txt");
	string satir;

	if (oduncDosyasi.is_open())
		//dosyanın açılması halinde liste yazılır
	{
		cout << "\t\tÖdünç Verilen Kitaplar Listesi:" << endl;

		while (getline(oduncDosyasi, satir))
		{
			cout << "\t\t- " << satir << endl;
		}

		oduncDosyasi.close();
	}
	else
	{
		cout << "\t\tDosya açılırken bir hata oluştu." << std::endl;
	}
}

/*******************************************************************
		KİTAP İADE ETME FONKSİYONU
*******************************************************************/


void kitapIadeEt()
{
	// İade edilecek kitap için gerekli bilgileri kullanıcıdan alınır

	string kitapAdi, kullaniciAdi;

	cout << "\t\tKitap Adı: ";

	cin.ignore();
	getline(cin, kitapAdi);

	cout << "\t\tKullanıcı Adı: ";
	getline(cin, kullaniciAdi);

	// Ödünç verilen kitaplar dosyası açılır

	ifstream oduncVerilenKitaplarDosyasi("odunc_verilen_kitaplar.txt");
	ofstream guncelKitaplarDosyasi("kitaplar.txt");
	ofstream gecmisIadelerDosyasi("gecmis_iadeler.txt", ios::app);

	if (oduncVerilenKitaplarDosyasi.is_open() && guncelKitaplarDosyasi.is_open() && gecmisIadelerDosyasi.is_open())
	{
		bool kitapBulundu = false;

		string satir;
		string guncelKitaplar;

		while (getline(oduncVerilenKitaplarDosyasi, satir))
		{
			if (satir.find(kitapAdi) != string::npos && satir.find(kullaniciAdi) != string::npos)
			{
				kitapBulundu = true;
				gecmisIadelerDosyasi << satir << endl; // İade geçmişi dosyasına kaydedilir
			}
			else
			{
				guncelKitaplar += satir + "\n";
			}
		}

		oduncVerilenKitaplarDosyasi.close();
		guncelKitaplarDosyasi << guncelKitaplar;
		guncelKitaplarDosyasi.close();
		gecmisIadelerDosyasi.close();

		if (kitapBulundu)
		{
			cout << "\t\tKitap başarıyla iade edildi!" << endl;
			oduncVerilenKitaplarListesi();
		}
		else
		{
			cout << "\t\tBelirtilen kitap ödünç alınmamış veya kullanıcı adı hatalı." << endl;
		}
	}
	else
	{
		cout << "\t\tDosya açılırken bir hata oluştu." << endl << endl;
	}
}


/*******************************************************************
		KAYDEDİLEN KİTAPLARI SİLME FONKSİYONU
*******************************************************************/


void kitapSil()
{
	//kaydedilen kitapları silmek için gerekli bilgiler istenir

	string kitapAdi;

	cout << "\t\tSilmek istediğiniz kitap adını giriniz: ";

	cin.ignore();
	getline(cin, kitapAdi);

	//silinmek istene kitap için kitapları kaydettiğimiz dosya açılır

	ifstream kitaplarDosyasi("kitaplar.txt");
	ofstream geciciDosya("gecici.txt");

	if (kitaplarDosyasi.is_open() && geciciDosya.is_open())
	{

		string satir;
		bool kitapBulundu = false;

		while (getline(kitaplarDosyasi, satir))
		{
			if (satir.find(kitapAdi) != string::npos)
			{
				kitapBulundu = true;

				cout << "\t\tKitap başarıyla silindi!" << endl;
			}
			else
			{
				geciciDosya << satir << endl;
			}
		}

		kitaplarDosyasi.close();
		geciciDosya.close();

		// Eğer kitap bulundu ve silindi ise gecici dosyayı kitaplar dosyasının üzerine taşınır

		if (kitapBulundu)
		{
			remove("kitaplar.txt");
			rename("gecici.txt", "kitaplar.txt");
		}
		else
		{
			remove("gecici.txt");
			cout << "\t\tKitap bulunamadı." << endl;
		}
	}
	else
	{
		cout << "\t\tDosya açılırken bir hata oluştu." << endl;
	}
}

/*******************************************************************
			 ÜYELERİ SİLME FONKSİYONU
*******************************************************************/


void uyeSil()

{
	string kullaniciAdi;

	cout << "\t\tSilmek istediğiniz üyenin kullanıcı adını giriniz: : ";
	cin.ignore();
	getline(cin, kullaniciAdi);

	//silmek istenen üye için üyeleri kaydedttiğimiz dosya açılır

	ifstream uyelerDosyasi("uyeler.txt");
	ofstream geciciDosya("gecici.txt");

	if (uyelerDosyasi.is_open() && geciciDosya.is_open())
	{

		string satir;
		bool uyeBulundu = false;

		while (getline(uyelerDosyasi, satir))
		{
			if (satir.find(kullaniciAdi) != string::npos)
			{
				uyeBulundu = true;

				cout << "\t\tÜye başarıyla silindi!" << endl;
			}
			else
			{
				geciciDosya << satir << endl;
			}
		}

		uyelerDosyasi.close();
		geciciDosya.close();

		//Eğer üye bulundu ve silindi ise geçici dosyayı üyeler dosyasının üzerine taşır


		if (uyeBulundu)
		{
			remove("uyeler.txt");
			rename("gecici.txt", "uyeler.txt");
		}
		else
		{
			remove("gecici.txt");
			cout << "\t\tÜye bulunamadı." << endl;
		}
	}
	else
	{
		cout << "\t\tDosya açılırken bir hata oluştu." << endl;
	}

}


/*******************************************************************
			 KAYDEDİLEN KİTABI ARAYAN FONKSİYON
********************************************************************/


void kitapAra()
{
	// Aranacak kitap adını veya yazarını alın
	string aranan;

	cout << "\t\tAranacak Kitap Adı veya Yazarı: ";
	cin.ignore();

	// Önceki girişlerin tamamını atlamak için
	getline(cin, aranan);

	// Kaydedilen kitapları okumak için dosyayı aç
	ifstream kitaplarDosyasi("kitaplar.txt");

	if (kitaplarDosyasi.is_open())
	{
		string kitapAdi, yazarAdi, kitapTuru;
		bool kitapBulundu = false;

		// Kitapları tek tek oku
		while (getline(kitaplarDosyasi, kitapAdi) && getline(kitaplarDosyasi, yazarAdi) && getline(kitaplarDosyasi, kitapTuru))
		{
			// Aranan kelimeyi kitap adında veya yazar adında içeren kitapları bul
			if (kitapAdi.find(aranan) != string::npos || yazarAdi.find(aranan) != string::npos)
			{
				cout << "\t\tKitap Adı: " << kitapAdi << endl;

				cout << "\t\tYazar Adı: " << yazarAdi << endl;

				cout << "\t\tKitap Turu: " << kitapTuru << endl << endl;

				kitapBulundu = true;
			}
		}

		kitaplarDosyasi.close();

		// Eğer aranan kitap bulunamazsa buna dair bir mesaj ver
		if (!kitapBulundu)
		{
			cout << "\t\tAranan kitap bulunamadı." << endl;
		}
	}
	else
	{
		cout << "\t\tDosya açılırken bir hata oluştu." << endl;
	}
}

/*******************************************************************
			 KAYDEDİLEN ÜYEYİ ARAYAN FONKSİYON
********************************************************************/


void uyeAra()
{
	string ad, soyad, kullaniciAdi, id;
	cout << "\t\t" << "Aramak istediginiz uyenin adini ve soyadini giriniz: " << endl << endl;

	cout << "\t\t" "Ad: ";
	cin.ignore();
	getline(cin, ad);
	cout << endl;

	cout << "\t\t" << "Soyad: ";
	cin.ignore();
	getline(cin, soyad);
	cout << endl;

	ifstream uyelerDosyasi("uyeler.txt");

	string uyeAdi, uyeSoyadi;
	bool uyeBulundu = false;

	while (getline(uyelerDosyasi, uyeAdi, ','))
	{
		getline(uyelerDosyasi, uyeSoyadi, ',');

		if (uyeAdi == ad && uyeSoyadi == soyad)
		{
			uyeBulundu = true;
			break;
		}
	}

	uyelerDosyasi.close();

	if (uyeBulundu)
	{
		cout << "\t\t" << "----------------------------------" << endl;
		cout << "\t\t" << "Üye bulundu!" << endl;
		cout << "\t\t" << "Ad: " << ad << endl;
		cout << "\t\t" << "Soyad: " << soyad << endl;
		cout << "\t\t" << "Kullanıcı Adı: " << kullaniciAdi << endl;
		cout << "\t\t" << "ID: " << id << endl;
		cout << "\t\t" << "----------------------------------" << endl;

	}
	else
	{
		cout << "\t\t------------------------Uye bulunamadı!------------------------" << endl;
	}

}


/*******************************************************************
					PROJE SONU
********************************************************************/