class IntVec {
public:
    explicit IntVec(size_t num = 0)
    :m_size(num),m_data(new int[m_size]){
        log("Contructor");
    }
    
    ~IntVec(){
        log("Deconstructor");
        if(m_data){
            delete [] m_data;
            m_data = 0;
        }
    }
    
    IntVec(const IntVec& other)
    :m_size(other.m_size), m_data(other.m_data) {
        log("Copy constructor");
        for (int i = 0; i < m_size; i++) {
            m_data[i] = other.m_data[i];
        }
    }
    
    IntVec& operator = (const IntVec &other) {
        log("Copy assigment operator");
        IntVec tmp(other);
        std::swap(m_size, tmp.m_size);
        std::swap(m_data, tmp.m_data);
        return *this;
    }
    
    
    
private:
    void log(const char* msg) {
        cout << "[" << this << "]" << msg << endl;
    }
    size_t m_size;
    int* m_data;
};


int main(){
    IntVec v1(20);
    IntVec v2;
    cout << "Assiging lvalue...\n";
    v2 = v1;
    cout << "Ending assigment lvalue...\n";
    return 0;
}
