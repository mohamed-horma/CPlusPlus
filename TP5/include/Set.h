#ifndef Set_H
#define Set_H

#include <ostream>

template <typename T> class Set{ //

    private:
        class Node {
            private:
                T _value;
                Node * _next;
            public:
                Node(T value, Node * next = nullptr): _value(value), _next(next){}
                ~Node() = default;

                T getValue() const{
                    return _value;
                }

                Node * getNext() const{
                    return _next;
                }
                void setNext(Node * next){
                    _next = next;
                }
        };

        Node* list;

        static Node * removeNode(Node * list, T x){
            if (!list) return nullptr;

            if (list->getValue() == x) {
                Node * tmp = list->getNext();
                delete list;
                return tmp;
            }

            list->setNext(removeNode(list->getNext(), x));
            return list;
        }

        // friend declarations so free functions can access private member 'list'
        template <typename U>
        friend Set<U> operator&(const Set<U> & a, const Set<U> & b);

        template <typename U>
        friend Set<U> image(const Set<U> & set, U (*function)(U));

    public: //
        Set(): list(nullptr){}

        Set(T x): list(new Node(x)) {}

        // copy constructor (deep copy)
        Set(const Set & other) : list(nullptr) {
            if (!other.list) {
                list = nullptr;
                return;
            }
            // copy first node
            list = new Node(other.list->getValue());
            Node * dst = list;
            Node * src = other.list->getNext();
            while (src) {
                dst->setNext(new Node(src->getValue()));
                dst = dst->getNext();
                src = src->getNext();
            }
        }

        // assignment operator (deep copy)
        Set & operator=(const Set & other) {
            if (this == &other) return *this;

            // clear current list
            clear();

            if (!other.list) {
                list = nullptr;
                return *this;
            }

            // copy nodes from other
            list = new Node(other.list->getValue());
            Node * dst = list;
            Node * src = other.list->getNext();
            while (src) {
                dst->setNext(new Node(src->getValue()));
                dst = dst->getNext();
                src = src->getNext();
            }

            return *this;
        }

        void clear(){
            while(list){
                Node *tmp = list;
                list = list->getNext();
                delete tmp;
            }
        }

        ~Set(){
            clear();
        };

        bool isEmpty() const{
            return list == nullptr;
        }

        // Formatage : sans espaces superflus pour correspondre à la trace fournie
        std::ostream & flush(std::ostream & out) const{
            out << "{";
            Node * p = list;
            bool first = true;
            while (p) {
                if (!first) out << ",";
                out << p->getValue();
                first = false;
                p = p->getNext();
            }
            out << "}";
            return out;
        }

        bool contains(T x) const{
            Node * p = list;
            while (p) {
                if (p->getValue() == x){
                    return true;
                }
                p = p->getNext();
            }
            return false;
        }

        // insert: attache à la queue pour conserver l'ordre d'insertion
        void insert(T x){
            if (contains(x)) return;
            if (!list) {
                list = new Node(x);
                return;
            }
            Node * p = list;
            while (p->getNext()) p = p->getNext();
            p->setNext(new Node(x));
        }

        void remove(T x){
            list = removeNode(list, x);
        }

        // Check inclusion
        bool isSubsetOf(const Set & other) const {
            Node * p = list;
            while (p) {
                if (!other.contains(p->getValue()))
                    return false;
                p = p->getNext();
            }
            return true;
        }

        // Insert all elements of this into other
        void insertInto(Set & other) const {
            Node * p = list;
            while (p) {
                other.insert(p->getValue());
                p = p->getNext();
            }
        }

        // Remove all elements of this from other (other = other - this)
        void removeFrom(Set & other) const {
            Node * p = list;
            while (p) {
                other.remove(p->getValue());
                p = p->getNext();
            }
        }

        // Note: image declared as friend above
};

// =======================
// Opérateur <<
// =======================
template <typename T>
std::ostream & operator<<(std::ostream & out, const Set<T> & s) {
  return s.flush(out);
}

// =======================
// Fonctions externes
// =======================
template <typename T>
Set<T> singleton(T x) {
  return Set<T>(x);
}

template <typename T>
Set<T> emptySet() {
  return Set<T>();
}

template <typename T>
bool operator==(const Set<T> & a, const Set<T> & b) {
  return a.isSubsetOf(b) && b.isSubsetOf(a);
}

template <typename T>
bool operator<(const Set<T> & a, const Set<T> & b) {
  return a.isSubsetOf(b);
}

template <typename T>
bool operator>(const Set<T> & a, const Set<T> & b) {
  return b.isSubsetOf(a);
}

template <typename T>
Set<T> operator|(const Set<T> & a, const Set<T> & b) {
  Set<T> r = a;
  b.insertInto(r);
  return r;
}

template <typename T>
Set<T> operator-(const Set<T> & a, const Set<T> & b) {
  Set<T> r = a;
  b.removeFrom(r);
  return r;
}

template <typename T>
Set<T> operator^(const Set<T> & a, const Set<T> & b) {
  return (a - b) | (b - a);
}

// Intersection: accès direct à la liste de 'a' (friend déclaré dans la classe)
template <typename T>
Set<T> operator&(const Set<T> & a, const Set<T> & b) {
  Set<T> r;
  typename Set<T>::Node * p = a.list;
  while (p) {
    if (b.contains(p->getValue()))
      r.insert(p->getValue());
    p = p->getNext();
  }
  return r;
}

// Compute the image of a set by a function
template <typename T>
Set<T> image(const Set<T> & set, T (*function)(T)) {
  Set<T> r;
  typename Set<T>::Node * p = set.list;
  while (p) {
    r.insert(function(p->getValue()));
    p = p->getNext();
  }
  return r;
}

#endif // Set_H
