#ifndef SHARED_PTR_H
#define SHARED_PTR_H
#include<iostream>
template <typename T>
class Sh_Ptr
{
    T *m_ptr;
    int *m_counter=new int (0);

public:
    Sh_Ptr(T *num=nullptr){m_ptr=num;
                  (*m_counter)++;}

    Sh_Ptr(Sh_Ptr &num){m_ptr=num.m_ptr;
                        m_counter=num.m_counter;
                       (*m_counter)++;}

    Sh_Ptr(Sh_Ptr &&num){num.m_counter=m_counter;}
    ~Sh_Ptr(){(*m_counter)--;
              if (*m_counter==0) std::cerr<< std::string{"\n0\n"};
             delete m_ptr;}

    int counter(){return *m_counter;}
};


#endif // SHARED_PTR_H
