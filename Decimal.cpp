
class bitmap {
private:
    unsigned long long size;
    unsigned long long len;
    unsigned char* bmp;
public:
    bitmap(unsigned long long sz) {
        len = (sz + 3) / 4;
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
        bitRef res(bmp + (x / 4), x % 4);
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
};
