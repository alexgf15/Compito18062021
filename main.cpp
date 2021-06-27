
#include <iostream>
using namespace std;


class Shape {
public:
    virtual double getArea() const =0;

    friend std::ostream &operator<<(std::ostream &os, const Shape &shape) {
        os<<shape.getArea();
        return os;
    }
    bool operator<(const Shape &rhs) const;

    bool operator>(const Shape &rhs) const;

    bool operator<=(const Shape &rhs) const;

    bool operator>=(const Shape &rhs) const;
    bool operator==(const Shape &rhs) const;

    };

class Rectangle : public Shape{
    double base,altezza;
public:
    Rectangle(double b, double h):  altezza(h),base(b){};
    double getArea() const { return base*altezza;}

};

class Circle : public Shape{
    double raggio;
public:
    explicit Circle(double r): raggio(r){}
    double getArea() const { return raggio*raggio*3.14;}
};

class Triangle : public Shape{
    double base,altezza;
public:
    Triangle(double a, double b):  altezza(a),base(b){};
    double getArea() const {return (base*altezza)/2;}
};

bool Shape::operator<(const Shape &rhs) const
{
    return this->getArea()<rhs.getArea();
}
bool Shape::operator>(const Shape &rhs) const {
    return this->getArea()>rhs.getArea();
}
bool Shape::operator<=(const Shape &rhs) const {
    return this->getArea()<=rhs.getArea();
}
bool Shape::operator>=(const Shape &rhs) const {
    return this->getArea() >= rhs.getArea();
}

bool Shape::operator==(const Shape &rhs) const {
    return this->getArea() == rhs.getArea();
}

template <class T> class Nodo
{
    public:
    T valore;
    Nodo * successivo;
    Nodo(T val):valore(val),successivo(nullptr){}

};

template <class T> class Coda
{
 Nodo<T> *fronte, *fine;

public:
Coda(): fronte(nullptr),fine(nullptr){}

void inserisci( T key);
T preleva();
bool isempty();

template<class U>
friend
ostream & operator<<(ostream & out, const Coda<U> & c);
};

template<class T>void Coda<T>::inserisci(T val)
{
    Nodo<T> * nuovo= new Nodo<T>(val);
    if(fine==nullptr)
    {
        fronte=fine=nuovo;
    }
    else
    {
    fine->successivo=nuovo;
    fine=nuovo;
    }

}

template<class T> T Coda<T>::preleva()
{
  Nodo<T> *temp=fronte;
  fronte=fronte->successivo;

  if(fronte==nullptr)
    fine=fronte;

  return temp->valore;
}

template<class T>bool Coda<T>::isempty()
{
    if((fronte==nullptr)&&(fine==nullptr))
        return true;
    else
        return false;

}


template<class U>
ostream & operator<<(ostream & out, const Coda<U> & c)
{
    Nodo<U> *temp=nullptr;

    if(c.isempty())
    {
        out<<"La coda e' vuota"<<endl;
    }

    else
    {
        temp=c.preleva();
        while(temp!=nullptr)
        {
            out<<*(temp->valore)<<endl;
        }
    }

}

void Creacoda(Coda<Rectangle> &R ,Coda<Triangle> &T,Coda<Circle> &C,int n )
{
    char scelta;
    double base,altezza,raggio;
    for(int i=0;i<n;i++)
 {
  cout<<"Shape N."<< i+1 <<endl;
  cout<<" Per scegliere che tipo di forma creare,"<<endl;
  cout<<" inserisci 'R'(Rettangolo),'T'(Triangolo) oppure 'C'(Cerchio): ";
  cin>>scelta;
}

     Coda<Rectangle > CodaRectangle;
    Coda<Circle> CodaCircle;
    Coda<Triangle> CodaTriangle;

  while(scelta!='R' && scelta!='T' && scelta!='C')
  {
   cout<<endl<<" Errore! Inserisci 'R'(Rettangolo),'T'(Triangolo) oppure 'C'(Cerchio): ";
   cin>>scelta;
  }

 switch (scelta)
 {


               case 1: {
                cout << "inserisci la base " << endl;
                cin >> base;
                cout << "inserisci l'altezza " << endl;
                cin >> altezza  ;
                CodaRectangle.inserisci(Rectangle(base,altezza));
            }break;

            case 2: {
                cout << "Inserisci il raggio " << endl;
                cin >> raggio;
                CodaCircle.inserisci(Circle(raggio));
            } break;
            case 3: {
                cout << "inserisci la base " << endl;
                cin >> base;
                cout << "inserisci l'altezza" << endl;
                cin >> altezza;
                CodaTriangle.inserisci(Triangle(base,altezza));
            } break;


        }
}

int main()
{



}
