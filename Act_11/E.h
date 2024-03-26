#ifndef E_H_INCLUDED
#define E_H_INCLUDED

class E {
    private:
        char element;
    public:
        void setElement(const char&);
        char getElement();
        bool operator == (const E&) const;
        bool operator != (const E&) const;
        bool operator <= (const E&) const;
        bool operator >= (const E&) const;
        bool operator > (const E&) const;
        bool operator < (const E&) const;
        friend std::ostream& operator << (std::ostream&, E&);
};

void E::setElement(const char& e){
    element = e;
}

char E::getElement(){
    return element;
}

bool E::operator == (const E& e) const {
    return element == e.element;
    }

bool E::operator != (const E& e) const {
    return element != e.element;
    }

bool E::operator >= (const E& e) const {
    return element >= e.element;
    }

bool E::operator > (const E& e) const {
    return element > e.element;
    }

bool E::operator <= (const E& e) const {
    return element <= e.element;
    }

bool E::operator < (const E& e) const {
    return element < e.element;
    }

std::ostream& operator << (std::ostream& os, E& s){
    std::string aux;
    aux = s.element;
    os << aux;
    return os;
}


#endif // E_H_INCLUDED
