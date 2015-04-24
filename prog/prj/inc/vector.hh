#ifndef VECTOR_HH
#define VECTOR_HH
#include <iostream>
/*!
 * \file
 * \brief Klasa przechowująca wektor
 * Zawiera podstawowe metody pozwalające stworzyć odpowiedni obiekt,
 * odczytywać i zapisywać dane do niego, wczytać i wydrukować na
 * standardowych strumieniach, a także odjąć od niego inny wektor.
 */
template <typename TYPE> class Vector;
template <typename TYPE> std::istream & operator>> (std::istream &, Vector<TYPE> &);
template <typename TYPE> std::ostream & operator<< (std::ostream &, const Vector<TYPE> &);

template <typename TYPE> class Vector {
		/*!
		 * \brief Przeciążenie standardowego operatora wejściowego dla
		 * wektora. Wczytuje wektor. W sumie nie potrzebne, ale
		 * skoro przeciążam wyjście, to wejście też przeciążę. A co!
		 * \param[in,out] inp - strumień wejściowy
		 * \param[out] vect - wektor
		 * \return Zwraca referencję do zmodyfikowanego strumienia.
		 */
		friend std::istream & operator>> <> (std::istream &, Vector<TYPE> &);
		/*!
		 * \brief Przeciążenie standardowego operatora wyjściowego dla
		 * wektora. Wyświetla wektor.
		 * \param[in,out] out - strumień wyjściowy
		 * \param[in] vect - wektor
		 * \return Zwraca referencję do zmodyfikowanego strumienia.
		 */
		friend std::ostream & operator<< <> (std::ostream &, const Vector<TYPE> &);
	private:
		TYPE *_data;
		int _size;
    public:
    	/*!
		 * \brief Konstruktor wektora
		 * \param[in] size - rozmiar, domyślnie SIZE
		 */
		Vector(const int size=0) {_size=size; _data=new TYPE [_size];}
		/*!
		 * \brief Konstruktor wektora z możliwością inicjowania danymi
		 * \param[in] size - rozmiar
		 * \param[in] *data - dane
		 */
		Vector(const int& size, const TYPE *data);
		/*!
		 * \brief Operator dostępu do współrzędnych wektora
		 * \param[in] i - numer danej
		 * \return Referencja do odpowiedniego elementu
		 */
		TYPE& operator[](const int& i) {return _data[i];}
		/*!
		 * \brief Operator dostępu do współrzędnych wektora
		 * \param[in] i - numer danej
		 * \return Referencja do odpowiedniego elementu
		 */
		const TYPE operator[](const int& i) const {return _data[i];}
		/*!
		 * \brief Operacja odejmowania wektorów
		 * \return Zwraca wynik w postaci wektora
		 */
		Vector operator-(const Vector& vect) const;
		/*!
		 * \brief Operacja odejmowania wektorów
		 * \return Zwraca wynik w postaci wektora
		 */
		Vector& operator-=(const Vector& vect);
		/*!
		 * \brief Operacja dodawania wektorów
		 * \return Zwraca wynik w postaci wektora
		 */
		Vector operator+(const Vector& vect) const;
		/*!
		 * \brief Operacja dodawania wektorów
		 * \return Zwraca wynik w postaci wektora
		 */
		Vector& operator+=(const Vector& vect);
		/*!
		 * \brief Operacja mnożenia wektora przez stałą
		 * \return Zwraca wynik w postaci wektora
		 */
		Vector operator*(const long& scale) const;
		/*!
		 * \brief Operacja mnożenia wektora przez stałą
		 * \return Zwraca wynik w postaci wektora
		 */
		Vector& operator*=(const long& scale);
		/*!
		 * \brief Zmienia zawartość wektora
		 * \param[in] Vector - nowa zawartość wektora
		 */
		Vector& operator=(const Vector& vect);
};

//template <typename TYPE>
//std::istream & operator>> (std::istream & inp, Vector<TYPE> & vect) {
//	char chr;
//
//    if(!(inp >> chr) || chr != '(')
//        inp.setstate(std::ios::failbit);
//	for(int i=0; i<vect._size; i++)
//		inp >> vect[i] >> chr;
//    if(chr != ')') inp.setstate(std::ios::failbit);
//
//    return inp;
//}
//
//template <typename TYPE>
//std::ostream & operator << (std::ostream & out, const Vector<TYPE> & vect) {
//	out << "( ";
//	for(int i=0; i < vect._size; i++)
//		out << vect[i] << (i<vect._size-1 ? ", ": " )");
//    return out;
//}
//
//template <typename TYPE>
//Vector<TYPE>::Vector(const int size, const TYPE *data) {
//    _size=size;
//    _data=new TYPE [size];
//    for(int i=0; i<size; i++) _data[i]=data[i];
//}
//
//template <typename TYPE>
//Vector<TYPE> Vector<TYPE>::operator-(Vector vect) {
//    TYPE *temp = new TYPE[_size];
//    for(int i=0; i<_size; i++)
//	temp[i]=_data[i]-vect[i];
//    return Vector(_size, temp);
//}

#endif
