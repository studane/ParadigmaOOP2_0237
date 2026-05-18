#include <iostream>
using namespace std;

class RekeningBank {
protected:
    string nama;
    long long saldo;
public:
    RekeningBank(string n, long long s) : nama(n), saldo(s) {}
    virtual void potongAdmin() = 0;
    void info() { cout << nama << " | Saldo: Rp " << saldo << "\n"; }
    virtual ~RekeningBank() {}
};

class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string n, long long s) : RekeningBank(n, s) {}
    void potongAdmin() override { saldo -= 15000; }
};

class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string n, long long s) : RekeningBank(n, s) {}
    void potongAdmin() override {}
};

class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string n, long long s) : RekeningBank(n, s) {}
    void potongAdmin() override { if (saldo <= 10000000) saldo -= 50000; }
};

int main() {
    RekeningBank* rekening[] = {
        new RekeningKonvensional("Budi", 500000),
        new RekeningSyariah("Siti", 500000),
        new RekeningPremium("Andi", 15000000),
        new RekeningPremium("Dewi", 8000000)
    };

    cout << "=== Sebelum Potong Admin ===\n";
    for (auto r : rekening) r->info();

    for (auto r : rekening) r->potongAdmin();

    cout << "\n=== Setelah Potong Admin ===\n";
    for (auto r : rekening) r->info();

    for (auto r : rekening) delete r;
}