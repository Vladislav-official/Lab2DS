// use stdafx.h in Visual Studio 2017 and earlier
#include "pch.h"
#include <utility>
#include <limits.h>
#include "Vector.h"
#include <vector>

Vector::Vector()
    : _array(nullptr)
    , _size(0)
{}

Vector::Vector(std::size_t size)
    : _array(static_cast<long int*>(malloc(size * sizeof(long int))))
    , _size(size)
{}

Vector::Vector(const Vector& vector)
    : _array(static_cast<long int*>(malloc(vector.size() * sizeof(long int))))
    , _size(vector.size())
{
    std::copy(vector._array, vector._array + _size, _array);
}

Vector::~Vector()
{
    if (_array) {
        free(_array);
        _array = nullptr;
    }
    _size = 0;
}

long int& Vector::operator[](std::size_t index) const
{
    return _array[index];
}

std::size_t Vector::size() const
{
    return _size;
}

Vector Vector::operator+(Vector vector) const
{
    Vector sum(this->size());

    if (this->size() != vector.size())
        return sum;

    
    for (int i = 0; i < sum.size(); i++) {
        sum[i] = *(this->_array+i) + vector[i];
    }

    return sum;
}

Vector Vector::operator-(Vector vector) const
{
    Vector diff(this->size());

    if (this->size() != vector.size())
        return diff;

    for (int i = 0; i < diff.size(); i++) {
        diff[i] = *(this->_array + i) - vector[i];
    }

    return diff;
}

bool Vector::operator==(Vector vector) const
{
    if (this->size() != vector.size())
        return false;

    for (int i = 0; i < vector.size(); i++) {
        if (*(this->_array + i) != vector[i])
            return false;
    }

    return true;
}

bool Vector::operator!=(Vector vector) const
{
    if (this->size() != vector.size())
        return true;

    for (int i = 0; i < vector.size(); i++) {
        if (*(this->_array + i) != vector[i])
            return true;
    }

    return false;
}

Vector operator*(Vector vector, double mult)
{
    Vector comp(vector.size());
    for (int i = 0; i < comp.size(); i++) {
        comp[i] = vector[i] * mult;
    }

    return comp;
}

Vector operator*(double mult, Vector vector)
{
    Vector comp(vector.size());
    for (int i = 0; i < comp.size(); i++) {
        comp[i] = mult * vector[i];
    }

    return comp;
}

std::ostream& operator<<(std::ostream& os, Vector vector)
{
    for (int i = 0; i < vector.size() - 1; i++) {
        os << vector[i] << " ";
    }
    os << vector[vector.size() - 1];

    return os;
}

std::istream& operator>> (std::istream& is, Vector vector)
{
    std::vector<double> victor;

    double num;
    while (is >> num) {
        victor.push_back(num);
    }

    vector = Vector(victor.size());

    for (int i = 0; i < vector.size(); i++) {
        vector[i] = victor[i];
    }

    return is;
}