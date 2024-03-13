
class bitmap {
private:
    unsigned long long size;
    unsigned long long len;
    unsigned char* bmp;
public:
    bitmap(unsigned long long sz) {
        len = (sz + 7) / 8;
        bmp = new unsigned char[len];
        size = sz;
    }
    ~bitmap() {
        delete[] bmp;
    }
    class bitRef {
    private:
        unsigned char* byte;
        short int offset;
    public:
        bitRef(unsigned char* bt, short int os) {
            byte = bt;
            offset = os;
        }
        operator bool() const {
            return (byte & (1 << offset)) >> offset;
        }
        void operator = (bool x) {
            if (x) {
                *byte = *byte | (1 << offset);
            }
            else {
                *byte = *byte & (~(1 << offset));
            }
        }
    };
    bitRef operator[] (unsigned long long x) {
        bitRef res(bmp + (x / 8), x % 8);
        return res;
    }
};


class uDecimal {
private:
    bitmap* num;
    unsigned long long sz;
    unsigned long long dp;
public:
    uDecimal(unsigned long long size, unsigned long long decP) {
        dp = decP;
        sz = size;
        num = new bitmap(size);
    }
    ~uDecimal() {
        delete num;
    }
    void operator = (uDecimal x&) {
        for (unsigned long long i = 0; i < sz; i++) {
            num[i] = x.num[i];
        }
    }
    uDecimal operator + (uDecimal x&) {
        uDecimal res(sz, dp);
        bool pass = false;
        for (unsigned long long i = 0; i < sz; i++) {
            *(res.num)[i] = (*num[i] != *(x.num)[i]) != pass;
            pass = ((*num[i] != *(x.num)[i]) && pass) || (*(num)[i] && *(x.num)[i]);
        }
        return res;
    }
    uDecimal operator - (uDecimal x&) {
    }
};
