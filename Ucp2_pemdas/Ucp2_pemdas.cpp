#include <iostream>
#include <vector>
using namespace std;


class penerbit;
//! Class pengarang.
    /*! fungsi, method dari fungsu ini. */
class pengarang {
public:
    string nama; /*!<Variabel untuk menyimpan nama*/
    vector<penerbit*> daftar_penerbit; 
    pengarang(string pNama) :nama(pNama) /*!<menyimpan nama penerbit ke dalam variabel nama>*/
    {
        cout << "Daftar pengarang pada penerbit " << nama << endl;
    }
    ~pengarang() {
        cout << "Daftar pengarang pada penerbit " << nama << endl;
    }
    void tambahPenerbit(penerbit*);
    void cetakPenerbit();
};
//! Class penerbit//
class penerbit {
public:
    string nama; /*!<variabel nama untuk menyimpan data*/
    vector<pengarang*> daftar_pengarang;

    penerbit(string pNama) :nama(pNama) {
        cout << "Daftar penerbit yang di ikuti " << nama << endl;
    }
    ~penerbit() {
        cout << "Daftar penerbit yang di ikuti \"" << nama << endl;
    }
    void tambahPengarang(pengarang*); /*!<menambahkan pengarang>*/
    void cetakPengarang();/*!<mencetak pengarang>*/

};
//! void pengarang.
/*!<menambahkan daftar penerbit baru kedalam daftar penerbit>*/
void pengarang::tambahPenerbit(penerbit* pPenerbit) {
     daftar_penerbit.push_back(pPenerbit);
}
void pengarang::cetakPenerbit() {
    cout << "Daftar pengrang pada penerbit \"" << this->nama << "\":\n";
    for (auto& a : daftar_penerbit) {
        cout << a->nama << "\n";
    }
    cout << endl;
}
void penerbit::tambahPengarang(pengarang* pPengarang) {
    daftar_pengarang.push_back(pPengarang);
    pPengarang->tambahPenerbit(this);
}
void penerbit::cetakPengarang() {
    cout << "Daftar pengarang pada penerbit \"" << this->nama << "\":\n";
    for (auto& a : daftar_pengarang) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

int main()
{
    penerbit* varPenerbit1 = new penerbit("Gama Press");
    penerbit* varPenerbit2 = new penerbit("Intan Pariwara");
    pengarang* varpengarang1 = new pengarang("Joko");
    pengarang* varpengarang2 = new pengarang("Lia");
    pengarang* varpengarang3 = new pengarang("Giga");
    pengarang* varpengarang4 = new pengarang("Asroni");


    varPenerbit1->tambahPengarang(varpengarang1);
    varPenerbit1->tambahPengarang(varpengarang2);
    varPenerbit1->tambahPengarang(varpengarang3);
    varPenerbit2->tambahPengarang(varpengarang3);
    varPenerbit2->tambahPengarang(varpengarang4);

    varPenerbit1->cetakPengarang();
    varPenerbit2->cetakPengarang();
    varpengarang1->cetakPenerbit();
    varpengarang2->cetakPenerbit();
    varpengarang3->cetakPenerbit();
    varpengarang4->cetakPenerbit();

    delete varpengarang1;
    delete varpengarang2;
    delete varpengarang3;
    delete varpengarang4;

    return 0;

}