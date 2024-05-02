//
// Created by alexp on 02/05/2024.
//

#ifndef HOSPITALBINARIO_TUPLE_H
#define HOSPITALBINARIO_TUPLE_H

#include <iostream>
#include <string>

template <class T>
class Tuple {
private:
    long long int index;
    T data;

public:
    Tuple();
    Tuple(const Tuple&);
    Tuple(const int&, const T&);

    long long int getIndex() const;
    T getData() const;

    void setIndex(const long long int&);
    void setData(const T&);

    Tuple& operator = (const Tuple&);

    bool operator == (const Tuple&) const;
    bool operator != (const Tuple&) const;
    bool operator < (const Tuple&) const;
    bool operator <= (const Tuple&) const;
    bool operator > (const Tuple&) const;
    bool operator >= (const Tuple&) const;

    bool operator == (const T&) const;
    bool operator != (const T&) const;
    bool operator < (const T&) const;
    bool operator <= (const T&) const;
    bool operator > (const T&) const;
    bool operator >= (const T&) const;

    template<class X>
    friend std::ostream& operator << (std::ostream&, const Tuple<X>&);

    template<class X>
    friend std::istream& operator >> (std::istream&, Tuple<X>&);
};

template<class T>
Tuple<T>::Tuple() : index(-1){}

template<class T>
Tuple<T>::Tuple(const Tuple& t) : index(t.index), data(t.data) {}

template<class T>
Tuple<T>::Tuple(const int& i, const T& e) : index(i), data(e){}

template<class T>
long long int Tuple<T>::getIndex() const {
    return index;
}

template<class T>
T Tuple<T>::getData() const {
    return data;
}

template<class T>
void Tuple<T>::setIndex(const long long int& i) {
    index = i;
}

template<class T>
void Tuple<T>::setData(const T& e) {
    data = e;
}

template<class T>
Tuple<T>& Tuple<T>::operator=(const Tuple& t) {

}

template<class T>
bool Tuple<T>::operator==(const Tuple& t) const {
    return index == t.getIndex();
}

template<class T>
bool Tuple<T>::operator!=(const Tuple& t) const {
    return !(*this == t);
}

template<class T>
bool Tuple<T>::operator<(const Tuple& t) const {
    return index < t.getIndex();
}

template<class T>
bool Tuple<T>::operator<=(const Tuple& t) const {
    return *this < t || *this == t;
}

template<class T>
bool Tuple<T>::operator>(const Tuple& t) const {
    return !(*this <= t);
}

template<class T>
bool Tuple<T>::operator>=(const Tuple& t) const {
    return !(*this < t);
}

template<class T>
bool Tuple<T>::operator==(const T& t) const {
    return index == t.getIndex();
}

template<class T>
bool Tuple<T>::operator!=(const T& t) const {
    return !(*this == t);
}

template<class T>
bool Tuple<T>::operator<(const T& t) const {
    return index < t.getIndex();
}

template<class T>
bool Tuple<T>::operator<=(const T& t) const {
    return *this < t || *this == t;
}

template<class T>
bool Tuple<T>::operator>(const T& t) const {
    return !(*this <= t);
}

template<class T>
bool Tuple<T>::operator>=(const T& t) const {
    return !(*this < t);
}

template<class X>
std::ostream& operator<<(std::ostream& os, const Tuple<X>& t){
    os << t.index << '*';
    os << t.data;

    return os;
}

template<class X>
std::istream& operator>>(std::istream& is, Tuple<X>& t){
    std::string myStr;

    getline(is, myStr, '*');
    t.index = stoll(myStr);

    getline(is, t.data, '#');

    return is;
}

#endif //HOSPITALBINARIO_TUPLE_H
