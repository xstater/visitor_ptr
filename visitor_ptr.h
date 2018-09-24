#ifndef _XSTD_VISITOR_PTR_H_
#define _XSTD_VISITOR_PTR_H_

#include <memory>

namespace std{
    template <class Type>
    class visitor_ptr{
    public:
        visitor_ptr()
            :m_ptr(nullptr){}
        visitor_ptr(Type *rptr)
            :m_ptr(rptr){}
        visitor_ptr(const unique_ptr<Type> &ptr)
            :m_ptr(ptr.get()){}
        visitor_ptr(const shared_ptr<Type> &ptr)
            :m_ptr(ptr.get()){}
        visitor_ptr(const visitor_ptr<Type> &) = default;
        visitor_ptr(visitor_ptr<Type> &&) = default;
        ~visitor_ptr() = default;

        visitor_ptr &operator=(const visitor_ptr<Type> &) = default;
        visitor_ptr &operator=(visitor_ptr<Type> &&) = default;

        void reset()noexcept{
            m_ptr = nullptr;
        }
        void reset(Type *ptr)noexcept{
            m_ptr = ptr;
        }

        operator bool()const noexcept{
            return m_ptr != nullptr;
        }

        Type &operator*()const noexcept{
            return *m_ptr;
        }
        Type *operator->()const noexcept{
            return m_ptr;
        }

        Type *get()const noexcept{
            return m_ptr;
        }

    protected:
    private:
        Type *m_ptr;
    };
}

#endif //_XSTD_VISITOR_PTR_H_
