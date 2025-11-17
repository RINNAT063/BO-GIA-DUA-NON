#include <iostream>    
#include <string>    
#include <iomanip>      
#include <limits>      
#include <algorithm>


// ======== MAU SAC ANSI =========
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"
#define PINK    "\033[38;5;207m"
#define ORANGE  "\033[38;5;208m"


using namespace std;
//class PhuongTien
class PhuongTien {
protected:
    string bienSo;
    string hangSx;
    int namSx;
public:
    // constructor - destructor
    PhuongTien() {
        bienSo = "00000";
        hangSx = "aaaaa";
        namSx = 0;
    }
    PhuongTien(string _bienSo, string _hangSx, int _namSx) {
        bienSo = _bienSo;
        hangSx = _hangSx;
        namSx = _namSx;
    }
    PhuongTien(const PhuongTien& p) {
        bienSo = p.bienSo;
        hangSx = p.hangSx;
        namSx = p.namSx;
    }
    virtual ~PhuongTien() {}


    // getter - setter
    string getBienSo() { return bienSo; }
    string getHangSX() { return hangSx; }
    int getNamSX() { return namSx; }


    void setBienSo(string bs) { bienSo = bs; }
    void setHangSX(string hsx) { hangSx = hsx; }
    void setNamSX(int nsx) { namSx = nsx; }


    // istream - ostream
    friend istream& operator>>(istream& is, PhuongTien& p) {
        cout << "Nhap bien so: ";
        getline(is, p.bienSo);
        cout << "Nhap hang san xuat: ";
        getline(is, p.hangSx);
        cout << "Nhap nam san xuat: ";
        is >> p.namSx;
        is.ignore();
        return is;
    }
    friend ostream& operator<<(ostream& os, PhuongTien& p) {
        p.HienThiThongTin();
        os << endl;
        return os;
    }
   
    bool operator < (const PhuongTien& other) {
        return namSx < other.namSx;
    }
    bool isSameBrand(const PhuongTien& other) {
        return hangSx == other.hangSx;
    }
    int tuoiXe(int namHienTai) {
        return namHienTai - namSx;
    }


    virtual void HienThiThongTin() {
        cout << " |Bien So Xe: " << bienSo << endl;
        cout << " | Hang Xe: " << hangSx << endl;
        cout << " | Nam San Xuat: " << namSx << endl;
    }
    virtual double TinhPhiBaoTri() {
        return 500000;
    }


    virtual string Loai() {
        return "PhuongTien";
    }


};
//class XeMay
class XeMay : public PhuongTien {
private:
    double congSuat;


public:
    // constructor - destructor
    XeMay(string _bienSo = "bienso", string _hangSX = "hangsx", int _namSX = 0, int _congSuat=0) :
        PhuongTien(_bienSo, _hangSX, _namSX) {
        congSuat= _congSuat;
    }


    XeMay(const XeMay& xm) : PhuongTien(xm) {
        congSuat = xm.congSuat;
    }


    ~XeMay() {}
    // getter - setter
    double getCongSuat() const { return congSuat; }
    void setCongSuat(double cs) { congSuat = cs; }
   
    // istream -  ostream
    friend istream& operator>>(istream& is, XeMay& x) {
        is >> (PhuongTien&)x;
        cout << "Nhap cong suat: ";
        is >> x.congSuat;
        is.ignore();
        return is;
    }
    friend ostream& operator<<(ostream& os, XeMay x) {
        x.HienThiThongTin();
        return os;
    }
   


    void HienThiThongTin() override {
        cout << BOLD << "----------------------------------------------" << RESET << "\n";
        cout << RED << BOLD << " [Xe May]" << RESET << "\n";
        cout << YELLOW << " | Bien so xe: " << RESET << getBienSo() << " \n";
        cout << YELLOW << " | Hang san xuat: " << RESET << getHangSX() << " \n";
        cout << YELLOW << " | Nam san xuat: " << RESET << getNamSX() << " \n";
        cout << YELLOW << " | Cong suat: " << RESET << congSuat << " \n";
        cout << YELLOW << " | Phi bao tri: " << RESET
            << fixed << setprecision(0) << TinhPhiBaoTri() << " \n";
    }
    double TinhPhiBaoTri() override {
        if (congSuat == 50) {
            return 300000;
        }
        else if (congSuat == 125) {
            return 500000;
        }
        return 700000;
    }


    string Loai() override { return "XeMay"; }
};


//class XeOto
class XeOto : public PhuongTien {
    int soChoNgoi;
    string kieuDang;
public:
    // constructor - destructor
    XeOto(string _bienSo = "bienso", string _hangSX = "hangsx", int _namSX = 0, int _soChoNgoi = 0, string _kieuDang = "kieudang") :
        PhuongTien(_bienSo, _hangSX, _namSX) {
        soChoNgoi = _soChoNgoi;
        kieuDang = _kieuDang;
    }
    XeOto(const XeOto& x) : PhuongTien(x) {
        soChoNgoi = x.soChoNgoi;
        kieuDang = x.kieuDang;
    }
    ~XeOto() {}


    // getter -setter
    int getSoChoNgoi() {
        return soChoNgoi;
    }
    void setSoChoNgoi(int x) {
        soChoNgoi = x;
    }
    string getKieuDang() {
        return kieuDang;
    }
    void setKieuDang(string k) {
        kieuDang = k;
    }
   
    // istream - ostream
    friend istream& operator>>(istream& in, XeOto& x) {
        in >> (PhuongTien&)x;
        cout << "Nhap so cho ngoi: ";
        in >> x.soChoNgoi;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nhap kieu dang: ";
        getline(in, x.kieuDang);
        return in;
    }
    friend ostream& operator<<(ostream& out, const XeOto& x) {
        out << (PhuongTien&)x
            << " | So cho: " << x.soChoNgoi
            << " | Kieu dang: " << x.kieuDang;
        return out;
    }
    void HienThiThongTin() override {
        cout << BOLD << "----------------------------------------------" << RESET << "\n";
        cout << RED << BOLD << " [Xe Oto]" << RESET << "\n";
        cout << YELLOW << " | Bien so xe: " << RESET << getBienSo() << " \n";
        cout << YELLOW << " | Hang san xuat: " << RESET << getHangSX() << " \n";
        cout << YELLOW << " | Nam san xuat: " << RESET << getNamSX() << " \n";
        cout << YELLOW << " | So cho: " << RESET << soChoNgoi << " \n";
        cout << YELLOW << " | Kieu dang: " << RESET << kieuDang << " \n";
        cout << YELLOW << " | Phi bao tri: " << RESET
            << fixed << setprecision(0) << TinhPhiBaoTri() << " \n";
    }
    double TinhPhiBaoTri() override {
        if (soChoNgoi == 4) {
            return 1000000;
        }
        else if (soChoNgoi == 7 || soChoNgoi == 9) {
            return 3000000;
        }
        else if (soChoNgoi == 16) {
            return 5000000;
        }
        return 7000000;
    }


    string Loai() override { return "XeOto"; }
};


//class XeTai
class XeTai : public PhuongTien {
    double taiTrong;
public:
    // constructor -  destructor
    XeTai(string _bienSo = "bienso", string _hangSX = "hangsx", int _namSX = 0, double _taiTrong = 0) : PhuongTien(_bienSo, _hangSX, _namSX) {
        taiTrong = _taiTrong;
    }
    XeTai(const XeTai& x) : PhuongTien(x) {
        taiTrong = x.taiTrong;
    }
    ~XeTai() {}
    // getter - setter
    int getTaiTrong() {
        return taiTrong;
    }
    void setTaiTrong(int x) {
        taiTrong = x;
    }
   
    // istream - ostream
    friend istream& operator>>(istream& in, XeTai& x) {
        in >> (PhuongTien&)x;
        cout << "Nhap tai trong (tan) : ";
        in >> x.taiTrong;
        return in;
    }
    friend ostream& operator<<(ostream& out, XeTai x) {
        out << (PhuongTien&)x << " | Tai trong: " << x.taiTrong;
        return out;
    }
   
    void HienThiThongTin() override {
        cout << BOLD << "----------------------------------------------" << RESET << "\n";
        cout << RED << BOLD << " [Xe Tai]" << RESET << "\n";
        cout << YELLOW << " | Bien so xe: " << RESET << getBienSo() << " \n";
        cout << YELLOW << " | Hang san xuat: " << RESET << getHangSX() << " \n";
        cout << YELLOW << " | Nam san xuat: " << RESET << getNamSX() << " \n";
        cout << YELLOW << " | Tai trong: " << RESET << taiTrong << " tan \n";
        cout << YELLOW << " | Phi bao tri: " << RESET
            << fixed << setprecision(0) << TinhPhiBaoTri() << " \n";
    }
    double TinhPhiBaoTri() override {
        if (taiTrong <= 6) {
            return 5000000;
        }
        else if (taiTrong >= 7 && taiTrong <= 15) {
            return 7000000;
        }
        else if (taiTrong >= 16 && taiTrong <= 40) {
            return 9000000;
        }
        return 11000000;
    }
    string Loai() override { return "XeTai"; }
};






// ============================ THEM CAC HAM MO RONG ============================


// === TIM XE THEO BIEN SO (chinh xac) ===
PhuongTien* timTheoBienSo(PhuongTien* ds[], int n, string bienSo) {
    for (int i = 0; i < n; i++) {
        if (ds[i]->getBienSo() == bienSo)
            return ds[i];
    }
    return nullptr;
}


// === SAP XEP TANG DAN THEO NAM SAN XUAT ===
void sapXepTheoNam(PhuongTien* ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[j]->getNamSX() < ds[i]->getNamSX())
                swap(ds[i], ds[j]);
        }
    }
}


// === DEM SO XE THEO HANG SAN XUAT ===
int demTheoHang(PhuongTien* ds[], int n, string hang) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i]->getHangSX() == hang)
            dem++;
    }
    return dem;
}


// === XE CO PHI BAO TRI CAO NHAT ===
PhuongTien* xePhiCaoNhat(PhuongTien* ds[], int n) {
    if (n == 0) return nullptr;
    PhuongTien* maxP = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i]->TinhPhiBaoTri() > maxP->TinhPhiBaoTri())
            maxP = ds[i];
    }
    return maxP;
}


void menu() {
    const string PAD = "                                   ";


    // Dòng trên
    cout << CYAN << BOLD;
    cout << PAD << "==============================================\n" << RESET;


    // Tiêu đề
    cout << PAD << CYAN << BOLD << "|" << RESET;
    cout << PINK << BOLD << "        QUAN LY PHUONG TIEN GIAO THONG      " << RESET;
    cout << CYAN << BOLD << "|\n" << RESET;


    // Dòng kẻ
    cout << PAD << CYAN << BOLD;
    cout << "==============================================\n" << RESET;


    // Các mục menu
    cout << PAD << CYAN << BOLD << "|" << RESET
        << YELLOW << BOLD << " 1. Them phuong tien                        " << RESET
        << CYAN << BOLD << "|\n" << RESET;


    cout << PAD << CYAN << BOLD << "|" << RESET
        << YELLOW << BOLD << " 2. Xuat danh sach phuong tien              " << RESET
        << CYAN << BOLD << "|\n" << RESET;


    cout << PAD << CYAN << BOLD << "|" << RESET
        << YELLOW << BOLD << " 3. Loc xe theo loai                        " << RESET
        << CYAN << BOLD << "|\n" << RESET;


    cout << PAD << CYAN << BOLD << "|" << RESET
        << YELLOW << BOLD << " 4. Tong phi bao tri tat ca xe              " << RESET
        << CYAN << BOLD << "|\n" << RESET;


    cout << PAD << CYAN << BOLD << "|" << RESET
        << YELLOW << BOLD << " 5. Tim xe theo bien so                     " << RESET
        << CYAN << BOLD << "|\n" << RESET;


    cout << PAD << CYAN << BOLD << "|" << RESET
        << YELLOW << BOLD << " 6. Sap xep theo nam san xuat               " << RESET
        << CYAN << BOLD << "|\n" << RESET;


    cout << PAD << CYAN << BOLD << "|" << RESET
        << YELLOW << BOLD << " 7. Dem xe theo hang san xuat               " << RESET
        << CYAN << BOLD << "|\n" << RESET;


    cout << PAD << CYAN << BOLD << "|" << RESET
        << YELLOW << BOLD << " 8. Xe co phi bao tri cao nhat              " << RESET
        << CYAN << BOLD << "|\n" << RESET;


    cout << PAD << CYAN << BOLD << "|" << RESET
        << YELLOW << BOLD << " 0. Thoat chuong trinh                      " << RESET
        << CYAN << BOLD << "|\n" << RESET;


   
    cout << PAD << CYAN << BOLD << "==============================================\n" << RESET;


    // Prompt nhập
    cout << PAD << BOLD << "Nhap lua chon: " << RESET;
}




// ============================ MAIN ============================


int main() {
    PhuongTien* ds[100];
    int n = 0;
    int chon;
    do {
        menu();
        cin >> chon;
        cin.ignore();
        switch (chon) {
        case 1: {
            cout << GREEN << "Chon loai xe (1 - XeMay, 2 - XeOto, 3 - XeTai): " << RESET;
            int loai;
            cin >> loai;
            cin.ignore();
            cout << "Nhap thong tin phuong tien:\n";


            PhuongTien* p = nullptr;


            if (loai == 1) {
                XeMay* xm = new XeMay();
                cin >> *xm;
                p = xm;
            }
            else if (loai == 2) {
                XeOto* xo = new XeOto();
                cin >> *xo;
                p = xo;
            }
            else if (loai == 3) {
                XeTai* xt = new XeTai();
                cin >> *xt;
                p = xt;
            }
            else {
                cout << RED << "Loai khong hop le!\n" << RESET;
                break;
            }


            ds[n++] = p;
            cout << GREEN <<" Da them phuong tien!\n" << RESET;
            break;
        }


        case 2: {
            if (n == 0) {
                cout << RED << "Danh sach rong!\n" << RESET;
                break;
            }
            cout << "\n============ ";
            cout << PINK << BOLD<< "DANH SACH PHUONG TIEN" << RESET;
            cout << " ===========\n";


            for (int i = 0; i < n; i++)
                ds[i]->HienThiThongTin();
            break;
        }


        case 3: { // Loc xe theo loai
            cout << "\n============ ";
            cout << PINK << BOLD << "DANH SACH XE CAN LOC" << RESET;
            cout << " ============\n";
            cout <<"Nhap loai xe can loc (XeMay / XeOto / XeTai): ";
            string loai;
            getline(cin, loai);


            bool timThay = false;
            for (int i = 0; i < n; i++) {
                if (ds[i]->Loai() == loai) {
                    if (!timThay) {
                        cout << "\n============= ";
                        cout << BLUE << BOLD << "DANH SACH " << loai << RESET;
                        cout << " ================\n";
                        timThay = true;
                    }
                    ds[i]->HienThiThongTin();
                }
            }


            if (!timThay)
                cout << RED << "Khong tim thay loai xe " << loai << "!\n" << RESET;
            break;
        }


        case 4: { // Tong phi bao tri
            double tong = 0;
            for (int i = 0; i < n; i++)
                tong += ds[i]->TinhPhiBaoTri();
            cout << YELLOW << "Tong phi bao tri tat ca xe: "
                << fixed << setprecision(0) << tong << " VND\n" << RESET;
            break;
        }


              // ========================= CASE 5: TIM XE =========================
        case 5: {
            cout << YELLOW << "Nhap bien so can tim: " << RESET;
            string bs;
            getline(cin, bs);
            PhuongTien* kq = timTheoBienSo(ds, n, bs);
            if (kq == nullptr) cout << RED << "Khong tim thay!\n" << RESET;
            else kq->HienThiThongTin();
            break;
        }


              // ========================= CASE 6: SAP XEP =========================
        case 6: {
            sapXepTheoNam(ds, n);
            cout << GREEN << "Da sap xep theo nam san xuat!\n" << RESET;
            break;
        }


              // ========================= CASE 7: DEM HANG ========================
        case 7: {
            cout << YELLOW << "Nhap hang san xuat can dem: " << RESET;
            string h;
            getline(cin, h);


            cout << BOLD << "So xe thuoc hang " << h << ": " << demTheoHang(ds, n, h) << endl << RESET;
            break;
        }


              // ===================== CASE 8: PHI BAO TRI MAX =====================
        case 8: {
            PhuongTien* p = xePhiCaoNhat(ds, n);
            if (p == nullptr) cout << RED << "Danh sach rong!\n" << RESET;
            else {
                cout << BOLD <<"Xe co phi bao tri cao nhat:\n" << RESET;
                p->HienThiThongTin();
            }
            break;
        }


        case 0: {
            cout << BOLD << "Thoat chuong trinh. Giai phong bo nho...\n" << RESET;
            for (int i = 0; i < n; i++)
                delete ds[i];
            break;
        }


        default:
            cout << RED << "Lua chon khong hop le!\n" << RESET;
            break;
        }


    } while (chon != 0);


    return 0;
}







