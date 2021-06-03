#ifdef VECTOR_EXPORTS
#define VECTOR_API __declspec(dllexport)
#else
#define VECTOR_API __declspec(dllimport)
#endif

class VECTOR_API Vector
{
public:
    // constructor without parameters
    Vector();
    // constructor with size
    Vector(std::size_t size);
    // copy constructor
    Vector(const Vector& vec);
    // destructor
    ~Vector();

    long int& operator[](size_t index) const;
    std::size_t size() const;
    Vector operator+(const Vector vector) const;
    Vector operator-(const Vector vector) const;
    bool operator==(const Vector vector) const;
    bool operator!=(const Vector vector) const;
    friend VECTOR_API Vector operator*(const Vector vector, double mult);
    friend VECTOR_API Vector operator*(double mult, const Vector vector);
    friend VECTOR_API std::ostream& operator<<(std::ostream& os, const Vector vector);
    friend VECTOR_API std::istream& operator>>(std::istream& is, const Vector vector);

private:
    long int* _array;
    std::size_t _size;
};