#include <iostream>

using namespace std;

class Kvector {
    int *m;
    int len;
public:
    static int total_len;
    Kvector(int sz = 0, int value = 0) {
        cout << this << " : Kvector( " << sz << ", " << value << ")" << endl;
        if(sz > 0) {
            this->m = new int[sz];
            for(int i = 0; i < sz; i++)
                this->m[i] = value;
        }
        else this->m = nullptr;
        this->len = sz;
        total_len += this->len;
    }
    Kvector(const Kvector& v) {
        this->m = new int[v.len];
        this->len = v.len;
        for(int i = 0; i < this->len; i++)
            this->m[i] = v.m[i];
        cout << this << " : Kvector(*" << &v << ")" << endl;
        total_len += this->len;
    }
    ~Kvector() {
        cout << this << " : ~Kvector() \n";
        delete[] m;
        total_len -= this->len;
    }
    Kvector& operator = (Kvector& k);
    friend bool operator == (const Kvector& lsh, const Kvector& rsh);
    int& operator [] (int n);
    friend ostream& operator << (ostream& os, Kvector& k);
    void print() const;
    void clear();
    int size();
};
Kvector& Kvector::operator = (Kvector& k) {
    delete[] this->m;
    this->len = k.len;
    this->m = new int[this->len];
    for(int i = 0; i < this->len; i++)
        this->m[i] = k.m[i];
    return *this;
}
bool operator == (const Kvector& lsh, const Kvector& rsh) {
    if(lsh.len != rsh.len)
        return false;
    for(int i = 0; i < lsh.len; i++)
        if(lsh.m[i] != rsh.m[i])
            return false;
    return true;
}
bool operator != (const Kvector& lsh, const Kvector& rsh) {
    return !(lsh == rsh);
}
int& Kvector::operator [] (int n) {
    return this->m[n];
}
ostream& operator << (ostream& os, Kvector& k) {
    for(int i = 0; i < k.len; i++)
        os << k.m[i] << ' ';
    return os;
}
void Kvector::print() const {
    for(int i = 0; i < this->len; i++) 
        cout << this->m[i] << " ";
    cout << endl;
}
void Kvector::clear() {
    total_len -= this->len;
    delete[] m;
    m = nullptr;
    this->len = 0;
}
int Kvector::size() { return len; }
int Kvector::total_len = 0;

int main() {
    Kvector v1(3); v1.print();
    Kvector v2(2, 9); v2.print();
    Kvector v3(v2); v3.print();
    cout << (v1 == v2) << endl;
    cout << (v3 == v2) << endl;
    v3 = v2 = v1;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
    return 0;
    // Kvector v1(3); v1.print();
    // const Kvector v2(2, 9); v2.print();
    // Kvector v3(v2); v3.print();
    
    // cout << "total length = " << Kvector::total_len << endl;
    // v2.print();
    // v3.print();
    // cout << "total length = " << Kvector::total_len << endl;
}