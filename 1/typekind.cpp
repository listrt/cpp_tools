/* typekind */
#ifndef typekind_rt
#define typekind_rt

/* inline_rt */
#if defined(_MSC_VER)
    #define inline_rt __forceinline
#elif defined(__GNUC__) || defined(__clang__)
    #define inline_rt __attribute__((always_inline)) inline
#elif defined(__INTEL_COMPILER) || defined(__ICC)
    #define inline_rt __forceinline
#elif defined(__DMC__) || defined(_DIGITAL_MARS)
    #define inline_rt __inline
#else
    #define inline_rt inline
#endif

namespace{
    namespace rangtt{
        /* basic type:enum */
        enum class type_enum{
            vd=0,
            sc,ss,si,sl,sll, /*   signed  */
            uc,us,ui,ul,ull, /*  unsigned */
            ch,bo,           /* char,bool */
            fl,db,ld,        /*   float   */
            /* ptr */
            vdp,scp,ssp,sip,slp,sllp,
            ucp,usp,uip,ulp,ullp,
            chp,bop,
            flp,dbp,ldp,

            fnp, /* function pointer */
            mfp, /* member function pointer */
            mdp, /* member data pointer */
            unknown=-1
        };
        /* basic type */
        type_enum inline_rt typekind(void)                { return type_enum::vd;  }
        type_enum inline_rt typekind(signed char)         { return type_enum::sc;  }
        type_enum inline_rt typekind(short)               { return type_enum::ss;  }
        type_enum inline_rt typekind(int)                 { return type_enum::si;  }
        type_enum inline_rt typekind(long)                { return type_enum::sl;  }
        type_enum inline_rt typekind(long long)           { return type_enum::sll; }
        type_enum inline_rt typekind(unsigned char)       { return type_enum::uc;  }
        type_enum inline_rt typekind(unsigned short)      { return type_enum::us;  }
        type_enum inline_rt typekind(unsigned int)        { return type_enum::ui;  }
        type_enum inline_rt typekind(unsigned long)       { return type_enum::ul;  }
        type_enum inline_rt typekind(unsigned long long)  { return type_enum::ull; }
        type_enum inline_rt typekind(bool)                { return type_enum::bo;  }
        type_enum inline_rt typekind(char)                { return type_enum::ch;  }
        type_enum inline_rt typekind(float)               { return type_enum::fl;  }
        type_enum inline_rt typekind(double)              { return type_enum::db;  }
        type_enum inline_rt typekind(long double)         { return type_enum::ld;  }
        
        type_enum inline_rt typekind(void*)               { return type_enum::vdp; }
        type_enum inline_rt typekind(signed char*)        { return type_enum::scp; }
        type_enum inline_rt typekind(short*)              { return type_enum::ssp; }
        type_enum inline_rt typekind(int*)                { return type_enum::sip; }
        type_enum inline_rt typekind(long*)               { return type_enum::slp; }
        type_enum inline_rt typekind(long long*)          { return type_enum::sllp;}
        type_enum inline_rt typekind(unsigned char*)      { return type_enum::ucp; }
        type_enum inline_rt typekind(unsigned short*)     { return type_enum::usp; }
        type_enum inline_rt typekind(unsigned int*)       { return type_enum::uip; }
        type_enum inline_rt typekind(unsigned long*)      { return type_enum::ulp; }
        type_enum inline_rt typekind(unsigned long long*) { return type_enum::ullp;}
        type_enum inline_rt typekind(bool*)               { return type_enum::bop; }
        type_enum inline_rt typekind(char*)               { return type_enum::chp; }
        type_enum inline_rt typekind(float*)              { return type_enum::flp; }
        type_enum inline_rt typekind(double*)             { return type_enum::dbp; }
        type_enum inline_rt typekind(long double*)        { return type_enum::ldp; }
        /* nullptr */
        #if __cplusplus>=201103L
        type_enum inline_rt typekind(decltype(nullptr))   { return type_enum::vdp; }
        #endif
        /* remove "const" and "volatile" */
        #ifndef use_rm_cv_rt
        #define use_rm_cv_rt
        template<typename T>
        struct rm_cv{using t=T;};
        template<typename T>
        struct rm_cv<const T>{using t=T;};
        template<typename T>
        struct rm_cv<volatile T>{using t=T;};
        template<typename T>
        struct rm_cv<const volatile T>{using t=T;};
        
        #endif
        /* is_same */
        #ifndef use_is_same_rt
        #define use_is_same_rt
        template<typename T,typename U>
        struct is_same{static const int v=0;};
        template<typename T>
        struct is_same<T,T>{static const int v=1;};
        #endif
        /* function pointer */
        template<typename R, typename... Args>
        type_enum inline_rt typekind(R(*)(Args...))               { return type_enum::fnp; }

        template<typename R, typename... Args>
        type_enum inline_rt typekind(R(*)(Args..., ...))          { return type_enum::fnp; }

        #if __cplusplus >= 201703L
        template<typename R, typename... Args>
        type_enum inline_rt typekind(R(*)(Args...) noexcept)      { return type_enum::fnp; }

        template<typename R, typename... Args>
        type_enum inline_rt typekind(R(*)(Args..., ...) noexcept) { return type_enum::fnp; }
        #endif

        /* member function pointer: mfp */

        /* no ref ,no noexcept */
        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...))                     { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) const)               { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) volatile)            { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) const volatile)      { return type_enum::mfp; }

        /* & ,no noexcept */
        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) &)                   { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) const &)             { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) volatile &)          { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) const volatile &)    { return type_enum::mfp; }

        /* && , no noexcept */
        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) &&)                  { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) const &&)            { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) volatile &&)         { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) const volatile &&)   { return type_enum::mfp; }

        #if __cplusplus >= 201703L
        /* ref, noexcept */
        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) noexcept)                    { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) const noexcept)              { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) volatile noexcept)           { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) const volatile noexcept)     { return type_enum::mfp; }

        /* & ,noexcept */
        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) & noexcept)                  { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) const & noexcept)            { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) volatile & noexcept)         { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) const volatile & noexcept)   { return type_enum::mfp; }

        /* &&,noexcept */
        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) && noexcept)                 { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) const && noexcept)           { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) volatile && noexcept)        { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args...) const volatile && noexcept)  { return type_enum::mfp; }
        #endif

        /* C-style variadic member function pointer */

        /* no ref, no noexcept */
        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...))                    { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) const)              { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) volatile)           { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) const volatile)     { return type_enum::mfp; }

        /* &, no noexcept */
        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) &)                  { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) const &)            { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) volatile &)         { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) const volatile &)   { return type_enum::mfp; }

        /* &&, no noexcept */
        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) &&)                 { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) const &&)           { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) volatile &&)        { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) const volatile &&)  { return type_enum::mfp; }

        #if __cplusplus >= 201703L
        /* no ref, noexcept */
        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) noexcept)                   { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) const noexcept)             { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) volatile noexcept)          { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) const volatile noexcept)    { return type_enum::mfp; }

        /* &, noexcept */
        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) & noexcept)                 { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) const & noexcept)           { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) volatile & noexcept)        { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) const volatile & noexcept)  { return type_enum::mfp; }

        /* &&, noexcept */
        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) && noexcept)                { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) const && noexcept)          { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) volatile && noexcept)       { return type_enum::mfp; }

        template<typename C, typename R, typename... Args>
        type_enum inline_rt typekind(R(C::*)(Args..., ...) const volatile && noexcept) { return type_enum::mfp; }
        #endif

        /* member data ptr*/
        template<typename C, typename R>
        type_enum inline_rt typekind(R C::*) { return type_enum::mdp; }

        /* every type */
        template<typename T>
        type_enum inline_rt typekind(T)  {
            using U=typename rm_cv<T>::t;
            if(!(is_same<T,U>::v))
                return typekind(U());
            return type_enum::unknown;
                                         }
        /* ptr */
        template <typename T>
        type_enum inline_rt typekind(const T*)          { return typekind(static_cast<T*>(0)); }
        template <typename T>
        type_enum inline_rt typekind(volatile T*)       { return typekind(static_cast<T*>(0)); }
        template <typename T>
        type_enum inline_rt typekind(const volatile T*) { return typekind(static_cast<T*>(0)); }
    }
}
#endif
/*
 * type_enum typekind(void){...} -> typekind()
 *
 * include:
 *     basic type
 *     basic pointer type
 *     function pointer
 *     member function pointer
 *     member data pointer
 */
