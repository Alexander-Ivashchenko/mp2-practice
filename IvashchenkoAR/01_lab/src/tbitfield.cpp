
// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
#include <stdexcept>


TBitField::TBitField(int len)
{
    if (len < 0) {
        throw std::invalid_argument("len must be non-negative");
    }
    BitLen = len;
    MemLen = (len + MASK_BITS) >> SHIFT_BITS; //  static const
    pMem = new TELEM[MemLen]();

}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {

        pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n >> SHIFT_BITS;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1u << (n & MASK_BITS); //  static const
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen) {
        throw std::out_of_range("bit index out of range");
    }
        pMem[GetMemIndex(n)] |= GetMemMask(n);
    
}

    void TBitField::ClrBit(const int n) // очистить бит
    {
        if (n < 0 || n >= BitLen) {
            throw std::out_of_range("bit index out of range");
        }
        pMem[GetMemIndex(n)] &= ~GetMemMask(n);

     }
    

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= BitLen) {
        throw std::out_of_range("bit index out of range");
    }

  return (pMem[GetMemIndex(n)] & GetMemMask(n)) >> (n & MASK_BITS);//  static const
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf) {
        return *this;
    }
    delete[] pMem;
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;

    pMem = new TELEM[MemLen];

        for(int i = 0; i < MemLen; i++) {
            pMem[i] = bf.pMem[i];

        }

    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    
    if (BitLen != bf.BitLen) {
        return 0;   
    }

    
    for (int i = 0; i < MemLen; i++) {
       
        if (pMem[i] != bf.pMem[i]) {
            return 0;  
        }
    }
    return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
   
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или" 
{
    TBitField res(max(BitLen, bf.BitLen)); 
    int i = 0;

    
    for (i = 0; i < min(MemLen, bf.MemLen); ++i) {
        res.pMem[i] = this->pMem[i] | bf.pMem[i];
    }

   
    while (i < MemLen) {
        res.pMem[i] = this->pMem[i];
        i++;
    }

 
    while (i < bf.MemLen) {
        res.pMem[i] = bf.pMem[i];
        i++;
    }

    return res;
}

TBitField TBitField::operator&(const TBitField& bf) // операция "и" 
{
    TBitField res(max(BitLen, bf.BitLen)); 

    for (int i = 0; i < min(MemLen, bf.MemLen); ++i) {
        res.pMem[i] = this->pMem[i] & bf.pMem[i];
    }

    return res;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField ans(*this);
    for (int i = 0; i < MemLen; i++) {
        ans.pMem[i] = ~ans.pMem[i];
    }
    int extra = MemLen * BITS_PER_ELEM - BitLen; 
    if (extra > 0) {
        ans.pMem[MemLen - 1] &= (1u << (BITS_PER_ELEM - extra)) - 1;
    }
    return ans;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    for (int i = 0; i < bf.BitLen; i++) {
        int x;
        istr >> x;
        if (x == 1) {
            bf.SetBit(i);
        }
        else {
            bf.ClrBit(i);
           }
   }

    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
        for (int i = 0; i < bf.BitLen; i++) {
            if (bf.GetBit(i)) {
                ostr << "1";
            }
            else {
                ostr << "0";
            }
    }
    return ostr;
}
