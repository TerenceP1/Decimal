
class bitmap {
private:
    unsigned long long size;
    unsigned long long len;
    unsigned char* bmp;
public:
    bitmap(unsigned long long sz){
        len=(sz+3)/4;
        bmp=new unsigned char[len];
        size=sz;
    }
    ~bitmap(){
        delete[] bmp;
    }
};
