/* typekind_pro */
#ifndef typekind_pro_rt
#define typekind_pro_rt

/* inline_rt */
#if defined(__STDC_HOSTED__) && __STDC_HOSTED__
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
#else
    #define inline_rt inline
#endif

namespace{
    namespace rangtt{
        enum class type_enum{
            vd=0,
            sc,ss,si,sl,sll, /*   signed  */
            uc,us,ui,ul,ull, /*  unsigned */
            ch,bo,           /* char,bool */
            fl,db,ld,        /*   float   */

            /* ptr */
            fnp, /* function pointer */
            mfp, /* member function pointer */
            mdp, /* member data pointer */

            unknown=-1
        };
        enum class te_more{
            /* basic */
            /*  T  */
            vd=0,
            sc,ss,si,sl,sll, /*   signed  */
            uc,us,ui,ul,ull, /*  unsigned */
            ch,bo,           /* char,bool */
            fl,db,ld,        /*   float   */
            c16,c32,wc,      /* char16_t,char32_t,wchar_t */
                /* const */
                c_sc,c_ss,c_si,c_sl,c_sll,
                c_uc,c_us,c_ui,c_ul,c_ull,
                c_ch,c_bo,
                c_fl,c_db,c_ld,
                c_c16,c_c32,c_wc,
                /* volatile */
                v_sc,v_ss,v_si,v_sl,v_sll,
                v_uc,v_us,v_ui,v_ul,v_ull,
                v_ch,v_bo,
                v_fl,v_db,v_ld,
                v_c16,v_c32,v_wc,
                /* cv */
                cv_sc,cv_ss,cv_si,cv_sl,cv_sll,
                cv_uc,cv_us,cv_ui,cv_ul,cv_ull,
                cv_ch,cv_bo,
                cv_fl,cv_db,cv_ld,
                cv_c16,cv_c32,cv_wc,

            /* ptr */
            /*  T*  */
            vd_p,
            sc_p,ss_p,si_p,sl_p,sll_p, 
            uc_p,us_p,ui_p,ul_p,ull_p, 
            ch_p,bo_p,           
            fl_p,db_p,ld_p, 
            c16_p,c32_p,wc_p,
                /* const+ */
                c_vd_p,
                c_sc_p,c_ss_p,c_si_p,c_sl_p,c_sll_p,
                c_uc_p,c_us_p,c_ui_p,c_ul_p,c_ull_p,
                c_ch_p,c_bo_p,
                c_fl_p,c_db_p,c_ld_p,
                c_c16_p,c_c32_p,c_wc_p,
                    /* +const */
                    c_vd_p_c,
                    c_sc_p_c, c_ss_p_c, c_si_p_c, c_sl_p_c, c_sll_p_c,
                    c_uc_p_c, c_us_p_c, c_ui_p_c, c_ul_p_c, c_ull_p_c,
                    c_ch_p_c, c_bo_p_c,
                    c_fl_p_c, c_db_p_c, c_ld_p_c,
                    c_c16_p_c, c_c32_p_c, c_wc_p_c,
                    /* +volatile */
                    c_vd_p_v,
                    c_sc_p_v, c_ss_p_v, c_si_p_v, c_sl_p_v, c_sll_p_v,
                    c_uc_p_v, c_us_p_v, c_ui_p_v, c_ul_p_v, c_ull_p_v,
                    c_ch_p_v, c_bo_p_v,
                    c_fl_p_v, c_db_p_v, c_ld_p_v,
                    c_c16_p_v, c_c32_p_v, c_wc_p_v,
                    /* +cv */
                    c_vd_p_cv,
                    c_sc_p_cv, c_ss_p_cv, c_si_p_cv, c_sl_p_cv, c_sll_p_cv,
                    c_uc_p_cv, c_us_p_cv, c_ui_p_cv, c_ul_p_cv, c_ull_p_cv,
                    c_ch_p_cv, c_bo_p_cv,
                    c_fl_p_cv, c_db_p_cv, c_ld_p_cv,
                    c_c16_p_cv, c_c32_p_cv, c_wc_p_cv,
                /* volatile+ */
                v_vd_p,
                v_sc_p,v_ss_p,v_si_p,v_sl_p,v_sll_p,
                v_uc_p,v_us_p,v_ui_p,v_ul_p,v_ull_p,
                v_ch_p,v_bo_p,
                v_fl_p,v_db_p,v_ld_p,
                v_c16_p,v_c32_p,v_wc_p,
                    /* +const */
                    v_vd_p_c,
                    v_sc_p_c, v_ss_p_c, v_si_p_c, v_sl_p_c, v_sll_p_c,
                    v_uc_p_c, v_us_p_c, v_ui_p_c, v_ul_p_c, v_ull_p_c,
                    v_ch_p_c, v_bo_p_c,
                    v_fl_p_c, v_db_p_c, v_ld_p_c,
                    v_c16_p_c, v_c32_p_c, v_wc_p_c,
                    /* +volaitle */
                    v_vd_p_v,
                    v_sc_p_v, v_ss_p_v, v_si_p_v, v_sl_p_v, v_sll_p_v,
                    v_uc_p_v, v_us_p_v, v_ui_p_v, v_ul_p_v, v_ull_p_v,
                    v_ch_p_v, v_bo_p_v,
                    v_fl_p_v, v_db_p_v, v_ld_p_v,
                    v_c16_p_v, v_c32_p_v, v_wc_p_v,
                    /* +cv */
                    v_vd_p_cv,
                    v_sc_p_cv, v_ss_p_cv, v_si_p_cv, v_sl_p_cv, v_sll_p_cv,
                    v_uc_p_cv, v_us_p_cv, v_ui_p_cv, v_ul_p_cv, v_ull_p_cv,
                    v_ch_p_cv, v_bo_p_cv,
                    v_fl_p_cv, v_db_p_cv, v_ld_p_cv,
                    v_c16_p_cv, v_c32_p_cv, v_wc_p_cv,
                /* cv+ */
                cv_vd_p,
                cv_sc_p,cv_ss_p,cv_si_p,cv_sl_p,cv_sll_p,
                cv_uc_p,cv_us_p,cv_ui_p,cv_ul_p,cv_ull_p,
                cv_ch_p,cv_bo_p,
                cv_fl_p,cv_db_p,cv_ld_p,
                cv_c16_p,cv_c32_p,cv_wc_p,
                    /* +const */
                    cv_vd_p_c,
                    cv_sc_p_c, cv_ss_p_c, cv_si_p_c, cv_sl_p_c, cv_sll_p_c,
                    cv_uc_p_c, cv_us_p_c, cv_ui_p_c, cv_ul_p_c, cv_ull_p_c,
                    cv_ch_p_c, cv_bo_p_c,
                    cv_fl_p_c, cv_db_p_c, cv_ld_p_c,
                    cv_c16_p_c, cv_c32_p_c, cv_wc_p_c,
                    /* +volatile */
                    cv_vd_p_v,
                    cv_sc_p_v, cv_ss_p_v, cv_si_p_v, cv_sl_p_v, cv_sll_p_v,
                    cv_uc_p_v, cv_us_p_v, cv_ui_p_v, cv_ul_p_v, cv_ull_p_v,
                    cv_ch_p_v, cv_bo_p_v,
                    cv_fl_p_v, cv_db_p_v, cv_ld_p_v,
                    cv_c16_p_v, cv_c32_p_v, cv_wc_p_v,
                    /* +cv */
                    cv_vd_p_cv,
                    cv_sc_p_cv, cv_ss_p_cv, cv_si_p_cv, cv_sl_p_cv, cv_sll_p_cv,
                    cv_uc_p_cv, cv_us_p_cv, cv_ui_p_cv, cv_ul_p_cv, cv_ull_p_cv,
                    cv_ch_p_cv, cv_bo_p_cv,
                    cv_fl_p_cv, cv_db_p_cv, cv_ld_p_cv,
                    cv_c16_p_cv, cv_c32_p_cv, cv_wc_p_cv,

                /* +const */
                vd_p_c, sc_p_c, ss_p_c, si_p_c, sl_p_c, sll_p_c,
                uc_p_c, us_p_c, ui_p_c, ul_p_c, ull_p_c,
                ch_p_c, bo_p_c,
                fl_p_c, db_p_c, ld_p_c,
                c16_p_c, c32_p_c, wc_p_c,
                /* +volatile */
                vd_p_v, sc_p_v, ss_p_v, si_p_v, sl_p_v, sll_p_v,
                uc_p_v, us_p_v, ui_p_v, ul_p_v, ull_p_v,
                ch_p_v, bo_p_v,
                fl_p_v, db_p_v, ld_p_v,
                c16_p_v, c32_p_v, wc_p_v,
                /* +cv */
                vd_p_cv, sc_p_cv, ss_p_cv, si_p_cv, sl_p_cv, sll_p_cv,
                uc_p_cv, us_p_cv, ui_p_cv, ul_p_cv, ull_p_cv,
                ch_p_cv, bo_p_cv,
                fl_p_cv, db_p_cv, ld_p_cv,
                c16_p_cv, c32_p_cv, wc_p_cv,
            /* arr */
            /*  T[]  */
            sc_a,ss_a,si_a,sl_a,sll_a, 
            uc_a,us_a,ui_a,ul_a,ull_a, 
            ch_a,bo_a,           
            fl_a,db_a,ld_a, 
            c16_a,c32_a,wc_a,
                /* const */
                c_sc_a,c_ss_a,c_si_a,c_sl_a,c_sll_a,
                c_uc_a,c_us_a,c_ui_a,c_ul_a,c_ull_a,
                c_ch_a,c_bo_a,
                c_fl_a,c_db_a,c_ld_a,
                c_c16_a,c_c32_a,c_wc_a,
                /* volatile */
                v_sc_a,v_ss_a,v_si_a,v_sl_a,v_sll_a,
                v_uc_a,v_us_a,v_ui_a,v_ul_a,v_ull_a,
                v_ch_a,v_bo_a,
                v_fl_a,v_db_a,v_ld_a,
                v_c16_a,v_c32_a,v_wc_a,
                /* cv */
                cv_sc_a,cv_ss_a,cv_si_a,cv_sl_a,cv_sll_a,
                cv_uc_a,cv_us_a,cv_ui_a,cv_ul_a,cv_ull_a,
                cv_ch_a,cv_bo_a,
                cv_fl_a,cv_db_a,cv_ld_a,
                cv_c16_a,cv_c32_a,cv_wc_a,
            /* T*[] */
            vd_p_a,
            sc_p_a, ss_p_a, si_p_a, sl_p_a, sll_p_a,
            uc_p_a, us_p_a, ui_p_a, ul_p_a, ull_p_a,
            ch_p_a, bo_p_a,
            fl_p_a, db_p_a, ld_p_a,
            c16_p_a, c32_p_a, wc_p_a,
                /* const */
                c_vd_p_a,
                c_sc_p_a, c_ss_p_a, c_si_p_a, c_sl_p_a, c_sll_p_a,
                c_uc_p_a, c_us_p_a, c_ui_p_a, c_ul_p_a, c_ull_p_a,
                c_ch_p_a, c_bo_p_a,
                c_fl_p_a, c_db_p_a, c_ld_p_a,
                c_c16_p_a, c_c32_p_a, c_wc_p_a,
                /* volatile */
                v_vd_p_a,
                v_sc_p_a, v_ss_p_a, v_si_p_a, v_sl_p_a, v_sll_p_a,
                v_uc_p_a, v_us_p_a, v_ui_p_a, v_ul_p_a, v_ull_p_a,
                v_ch_p_a, v_bo_p_a,
                v_fl_p_a, v_db_p_a, v_ld_p_a,
                v_c16_p_a, v_c32_p_a, v_wc_p_a,
                /* cv */
                cv_vd_p_a,
                cv_sc_p_a, cv_ss_p_a, cv_si_p_a, cv_sl_p_a, cv_sll_p_a,
                cv_uc_p_a, cv_us_p_a, cv_ui_p_a, cv_ul_p_a, cv_ull_p_a,
                cv_ch_p_a, cv_bo_p_a,
                cv_fl_p_a, cv_db_p_a, cv_ld_p_a,
                cv_c16_p_a, cv_c32_p_a, cv_wc_p_a,
                    /* T* const[] */
                    vd_p_c_a, sc_p_c_a, ss_p_c_a, si_p_c_a, sl_p_c_a, sll_p_c_a,
                    uc_p_c_a, us_p_c_a, ui_p_c_a, ul_p_c_a, ull_p_c_a,
                    ch_p_c_a, bo_p_c_a,
                    fl_p_c_a, db_p_c_a, ld_p_c_a,
                    c16_p_c_a, c32_p_c_a, wc_p_c_a,

                    c_vd_p_c_a, c_sc_p_c_a, c_ss_p_c_a, c_si_p_c_a, c_sl_p_c_a, c_sll_p_c_a,
                    c_uc_p_c_a, c_us_p_c_a, c_ui_p_c_a, c_ul_p_c_a, c_ull_p_c_a,
                    c_ch_p_c_a, c_bo_p_c_a,
                    c_fl_p_c_a, c_db_p_c_a, c_ld_p_c_a,
                    c_c16_p_c_a, c_c32_p_c_a, c_wc_p_c_a,

                    v_vd_p_c_a, v_sc_p_c_a, v_ss_p_c_a, v_si_p_c_a, v_sl_p_c_a, v_sll_p_c_a,
                    v_uc_p_c_a, v_us_p_c_a, v_ui_p_c_a, v_ul_p_c_a, v_ull_p_c_a,
                    v_ch_p_c_a, v_bo_p_c_a,
                    v_fl_p_c_a, v_db_p_c_a, v_ld_p_c_a,
                    v_c16_p_c_a, v_c32_p_c_a, v_wc_p_c_a,

                    cv_vd_p_c_a, cv_sc_p_c_a, cv_ss_p_c_a, cv_si_p_c_a, cv_sl_p_c_a, cv_sll_p_c_a,
                    cv_uc_p_c_a, cv_us_p_c_a, cv_ui_p_c_a, cv_ul_p_c_a, cv_ull_p_c_a,
                    cv_ch_p_c_a, cv_bo_p_c_a,
                    cv_fl_p_c_a, cv_db_p_c_a, cv_ld_p_c_a,
                    cv_c16_p_c_a, cv_c32_p_c_a, cv_wc_p_c_a,
                    /* T* volatile[] */
                    vd_p_v_a, sc_p_v_a, ss_p_v_a, si_p_v_a, sl_p_v_a, sll_p_v_a,
                    uc_p_v_a, us_p_v_a, ui_p_v_a, ul_p_v_a, ull_p_v_a,
                    ch_p_v_a, bo_p_v_a,
                    fl_p_v_a, db_p_v_a, ld_p_v_a,
                    c16_p_v_a, c32_p_v_a, wc_p_v_a,

                    c_vd_p_v_a, c_sc_p_v_a, c_ss_p_v_a, c_si_p_v_a, c_sl_p_v_a, c_sll_p_v_a,
                    c_uc_p_v_a, c_us_p_v_a, c_ui_p_v_a, c_ul_p_v_a, c_ull_p_v_a,
                    c_ch_p_v_a, c_bo_p_v_a,
                    c_fl_p_v_a, c_db_p_v_a, c_ld_p_v_a,
                    c_c16_p_v_a, c_c32_p_v_a, c_wc_p_v_a,

                    v_vd_p_v_a, v_sc_p_v_a, v_ss_p_v_a, v_si_p_v_a, v_sl_p_v_a, v_sll_p_v_a,
                    v_uc_p_v_a, v_us_p_v_a, v_ui_p_v_a, v_ul_p_v_a, v_ull_p_v_a,
                    v_ch_p_v_a, v_bo_p_v_a,
                    v_fl_p_v_a, v_db_p_v_a, v_ld_p_v_a,
                    v_c16_p_v_a, v_c32_p_v_a, v_wc_p_v_a,

                    cv_vd_p_v_a, cv_sc_p_v_a, cv_ss_p_v_a, cv_si_p_v_a, cv_sl_p_v_a, cv_sll_p_v_a,
                    cv_uc_p_v_a, cv_us_p_v_a, cv_ui_p_v_a, cv_ul_p_v_a, cv_ull_p_v_a,
                    cv_ch_p_v_a, cv_bo_p_v_a,
                    cv_fl_p_v_a, cv_db_p_v_a, cv_ld_p_v_a,
                    cv_c16_p_v_a, cv_c32_p_v_a, cv_wc_p_v_a,
                    
                    /* T* const volatile[] */
                    vd_p_cv_a, sc_p_cv_a, ss_p_cv_a, si_p_cv_a, sl_p_cv_a, sll_p_cv_a,
                    uc_p_cv_a, us_p_cv_a, ui_p_cv_a, ul_p_cv_a, ull_p_cv_a,
                    ch_p_cv_a, bo_p_cv_a,
                    fl_p_cv_a, db_p_cv_a, ld_p_cv_a,
                    c16_p_cv_a, c32_p_cv_a, wc_p_cv_a,

                    c_vd_p_cv_a, c_sc_p_cv_a, c_ss_p_cv_a, c_si_p_cv_a, c_sl_p_cv_a, c_sll_p_cv_a,
                    c_uc_p_cv_a, c_us_p_cv_a, c_ui_p_cv_a, c_ul_p_cv_a, c_ull_p_cv_a,
                    c_ch_p_cv_a, c_bo_p_cv_a,
                    c_fl_p_cv_a, c_db_p_cv_a, c_ld_p_cv_a,
                    c_c16_p_cv_a, c_c32_p_cv_a, c_wc_p_cv_a,

                    v_vd_p_cv_a, v_sc_p_cv_a, v_ss_p_cv_a, v_si_p_cv_a, v_sl_p_cv_a, v_sll_p_cv_a,
                    v_uc_p_cv_a, v_us_p_cv_a, v_ui_p_cv_a, v_ul_p_cv_a, v_ull_p_cv_a,
                    v_ch_p_cv_a, v_bo_p_cv_a,
                    v_fl_p_cv_a, v_db_p_cv_a, v_ld_p_cv_a,
                    v_c16_p_cv_a, v_c32_p_cv_a, v_wc_p_cv_a,

                    cv_vd_p_cv_a, cv_sc_p_cv_a, cv_ss_p_cv_a, cv_si_p_cv_a, cv_sl_p_cv_a, cv_sll_p_cv_a,
                    cv_uc_p_cv_a, cv_us_p_cv_a, cv_ui_p_cv_a, cv_ul_p_cv_a, cv_ull_p_cv_a,
                    cv_ch_p_cv_a, cv_bo_p_cv_a,
                    cv_fl_p_cv_a, cv_db_p_cv_a, cv_ld_p_cv_a,
                    cv_c16_p_cv_a, cv_c32_p_cv_a, cv_wc_p_cv_a,

            /* function pointer (16) */
            /* name: fnp[_va][_ne][_cv]
             *   _va : variadic      (Args..., ...)
             *   _ne : noexcept
             *   _c  : pointer itself const
             *   _v  : pointer itself volatile
             *   _cv : pointer itself const volatile
             */

            /* no va (8) */
            fnp,           /* R(*)(Args...)                        */
            fnp_c,         /* R(* const)(Args...)                  */
            fnp_v,         /* R(* volatile)(Args...)               */
            fnp_cv,        /* R(* const volatile)(Args...)         */
            fnp_ne,        /* R(*)(Args...) noexcept               */
            fnp_c_ne,      /* R(* const)(Args...) noexcept         */
            fnp_v_ne,      /* R(* volatile)(Args...) noexcept      */
            fnp_cv_ne,     /* R(* const volatile)(Args...) noexcept*/

            /*  va (8) */
            fnp_va,        /* R(*)(Args..., ...)                   */
            fnp_va_c,      /* R(* const)(Args..., ...)             */
            fnp_va_v,      /* R(* volatile)(Args..., ...)          */
            fnp_va_cv,     /* R(* const volatile)(Args..., ...)    */
            fnp_va_ne,     /* R(*)(Args..., ...) noexcept          */
            fnp_va_c_ne,   /* R(* const)(Args..., ...) noexcept    */
            fnp_va_v_ne,   /* R(* volatile)(Args..., ...) noexcept */
            fnp_va_cv_ne,  /* R(* const volatile)(Args..., ...) noexcept */

            /* member function pointer */
                /* ========== non-variadic (24) ========== */
                /* ---- no noexcept (12) ---- */
                mfp_r_a,              /* no cv, no ref */
                mfp_r_a_lr,           /* no cv, & */
                mfp_r_a_rr,           /* no cv, && */
                mfp_r_a_c,            /* const */
                mfp_r_a_c_lr,         /* const & */
                mfp_r_a_c_rr,         /* const && */
                mfp_r_a_v,            /* volatile */
                mfp_r_a_v_lr,         /* volatile & */
                mfp_r_a_v_rr,         /* volatile && */
                mfp_r_a_cv,           /* const volatile */
                mfp_r_a_cv_lr,        /* const volatile & */
                mfp_r_a_cv_rr,        /* const volatile && */

                /* ---- with noexcept (12) ---- */
                mfp_r_a_ne,           /* no cv, no ref, noexcept */
                mfp_r_a_lr_ne,        /* no cv, &, noexcept */
                mfp_r_a_rr_ne,        /* no cv, &&, noexcept */
                mfp_r_a_c_ne,         /* const, noexcept */
                mfp_r_a_c_lr_ne,      /* const &, noexcept */
                mfp_r_a_c_rr_ne,      /* const &&, noexcept */
                mfp_r_a_v_ne,         /* volatile, noexcept */
                mfp_r_a_v_lr_ne,      /* volatile &, noexcept */
                mfp_r_a_v_rr_ne,      /* volatile &&, noexcept */
                mfp_r_a_cv_ne,        /* const volatile, noexcept */
                mfp_r_a_cv_lr_ne,     /* const volatile &, noexcept */
                mfp_r_a_cv_rr_ne,     /* const volatile &&, noexcept */

                /* ========== variadic (24) ========== */
                /* ---- no noexcept (12) ---- */
                mfp_r_a_va,           /* no cv, no ref */
                mfp_r_a_va_lr,        /* no cv, & */
                mfp_r_a_va_rr,        /* no cv, && */
                mfp_r_a_va_c,         /* const */
                mfp_r_a_va_c_lr,      /* const & */
                mfp_r_a_va_c_rr,      /* const && */
                mfp_r_a_va_v,         /* volatile */
                mfp_r_a_va_v_lr,      /* volatile & */
                mfp_r_a_va_v_rr,      /* volatile && */
                mfp_r_a_va_cv,        /* const volatile */
                mfp_r_a_va_cv_lr,     /* const volatile & */
                mfp_r_a_va_cv_rr,     /* const volatile && */

                /* ---- with noexcept (12) ---- */
                mfp_r_a_va_ne,        /* no cv, no ref, noexcept */
                mfp_r_a_va_lr_ne,     /* no cv, &, noexcept */
                mfp_r_a_va_rr_ne,     /* no cv, &&, noexcept */
                mfp_r_a_va_c_ne,      /* const, noexcept */
                mfp_r_a_va_c_lr_ne,   /* const &, noexcept */
                mfp_r_a_va_c_rr_ne,   /* const &&, noexcept */
                mfp_r_a_va_v_ne,      /* volatile, noexcept */
                mfp_r_a_va_v_lr_ne,   /* volatile &, noexcept */
                mfp_r_a_va_v_rr_ne,   /* volatile &&, noexcept */
                mfp_r_a_va_cv_ne,     /* const volatile, noexcept */
                mfp_r_a_va_cv_lr_ne,  /* const volatile &, noexcept */
                mfp_r_a_va_cv_rr_ne,  /* const volatile &&, noexcept */

            /* member data pointer (4) */
            mdp,        /* T   C::*     */
                mdp_c,      /* const T C::* */
                mdp_v,      /* volatile T C::* */
                mdp_cv,     /* const volatile T C::* */

            unknown=-1
        };
        using len_t=decltype(sizeof(0));
        template<typename T>
        te_more inline_rt typekind()                { return te_more::unknown;  }
        template<> te_more inline_rt typekind<void>()                { return te_more::vd;  }
        template<> te_more inline_rt typekind<signed char>()         { return te_more::sc;  }
        template<> te_more inline_rt typekind<short>()               { return te_more::ss;  }
        template<> te_more inline_rt typekind<int>()                 { return te_more::si;  }
        template<> te_more inline_rt typekind<long>()                { return te_more::sl;  }
        template<> te_more inline_rt typekind<long long>()           { return te_more::sll; }
        template<> te_more inline_rt typekind<unsigned char>()       { return te_more::uc;  }
        template<> te_more inline_rt typekind<unsigned short>()      { return te_more::us;  }
        template<> te_more inline_rt typekind<unsigned int>()        { return te_more::ui;  }
        template<> te_more inline_rt typekind<unsigned long>()       { return te_more::ul;  }
        template<> te_more inline_rt typekind<unsigned long long>()  { return te_more::ull; }
        template<> te_more inline_rt typekind<bool>()                { return te_more::bo;  }
        template<> te_more inline_rt typekind<char>()                { return te_more::ch;  }
        template<> te_more inline_rt typekind<float>()               { return te_more::fl;  }
        template<> te_more inline_rt typekind<double>()              { return te_more::db;  }
        template<> te_more inline_rt typekind<long double>()         { return te_more::ld;  }
        template<> te_more inline_rt typekind<char16_t>()            { return te_more::c16; }
        template<> te_more inline_rt typekind<char32_t>()            { return te_more::c32; }
        template<> te_more inline_rt typekind<wchar_t>()             { return te_more::wc;  }
            template<> te_more inline_rt typekind<const signed char>()        { return te_more::c_sc;  }
            template<> te_more inline_rt typekind<const short>()              { return te_more::c_ss;  }
            template<> te_more inline_rt typekind<const int>()                { return te_more::c_si;  }
            template<> te_more inline_rt typekind<const long>()               { return te_more::c_sl;  }
            template<> te_more inline_rt typekind<const long long>()          { return te_more::c_sll; }
            template<> te_more inline_rt typekind<const unsigned char>()      { return te_more::c_uc;  }
            template<> te_more inline_rt typekind<const unsigned short>()     { return te_more::c_us;  }
            template<> te_more inline_rt typekind<const unsigned int>()       { return te_more::c_ui;  }
            template<> te_more inline_rt typekind<const unsigned long>()      { return te_more::c_ul;  }
            template<> te_more inline_rt typekind<const unsigned long long>() { return te_more::c_ull; }
            template<> te_more inline_rt typekind<const bool>()               { return te_more::c_bo;  }
            template<> te_more inline_rt typekind<const char>()               { return te_more::c_ch;  }
            template<> te_more inline_rt typekind<const float>()              { return te_more::c_fl;  }
            template<> te_more inline_rt typekind<const double>()             { return te_more::c_db;  }
            template<> te_more inline_rt typekind<const long double>()        { return te_more::c_ld;  }
            template<> te_more inline_rt typekind<const char16_t>()           { return te_more::c_c16; }
            template<> te_more inline_rt typekind<const char32_t>()           { return te_more::c_c32; }
            template<> te_more inline_rt typekind<const wchar_t>()            { return te_more::c_wc;  }

            template<> te_more inline_rt typekind<volatile signed char>()        { return te_more::v_sc;  }
            template<> te_more inline_rt typekind<volatile short>()              { return te_more::v_ss;  }
            template<> te_more inline_rt typekind<volatile int>()                { return te_more::v_si;  }
            template<> te_more inline_rt typekind<volatile long>()               { return te_more::v_sl;  }
            template<> te_more inline_rt typekind<volatile long long>()          { return te_more::v_sll; }
            template<> te_more inline_rt typekind<volatile unsigned char>()      { return te_more::v_uc;  }
            template<> te_more inline_rt typekind<volatile unsigned short>()     { return te_more::v_us;  }
            template<> te_more inline_rt typekind<volatile unsigned int>()       { return te_more::v_ui;  }
            template<> te_more inline_rt typekind<volatile unsigned long>()      { return te_more::v_ul;  }
            template<> te_more inline_rt typekind<volatile unsigned long long>() { return te_more::v_ull; }
            template<> te_more inline_rt typekind<volatile bool>()               { return te_more::v_bo;  }
            template<> te_more inline_rt typekind<volatile char>()               { return te_more::v_ch;  }
            template<> te_more inline_rt typekind<volatile float>()              { return te_more::v_fl;  }
            template<> te_more inline_rt typekind<volatile double>()             { return te_more::v_db;  }
            template<> te_more inline_rt typekind<volatile long double>()        { return te_more::v_ld;  }
            template<> te_more inline_rt typekind<volatile char16_t>()           { return te_more::v_c16; }
            template<> te_more inline_rt typekind<volatile char32_t>()           { return te_more::v_c32; }
            template<> te_more inline_rt typekind<volatile wchar_t>()            { return te_more::v_wc;  }

            template<> te_more inline_rt typekind<const volatile signed char>()        { return te_more::cv_sc;  }
            template<> te_more inline_rt typekind<const volatile short>()              { return te_more::cv_ss;  }
            template<> te_more inline_rt typekind<const volatile int>()                { return te_more::cv_si;  }
            template<> te_more inline_rt typekind<const volatile long>()               { return te_more::cv_sl;  }
            template<> te_more inline_rt typekind<const volatile long long>()          { return te_more::cv_sll; }
            template<> te_more inline_rt typekind<const volatile unsigned char>()      { return te_more::cv_uc;  }
            template<> te_more inline_rt typekind<const volatile unsigned short>()     { return te_more::cv_us;  }
            template<> te_more inline_rt typekind<const volatile unsigned int>()       { return te_more::cv_ui;  }
            template<> te_more inline_rt typekind<const volatile unsigned long>()      { return te_more::cv_ul;  }
            template<> te_more inline_rt typekind<const volatile unsigned long long>() { return te_more::cv_ull; }
            template<> te_more inline_rt typekind<const volatile bool>()               { return te_more::cv_bo;  }
            template<> te_more inline_rt typekind<const volatile char>()               { return te_more::cv_ch;  }
            template<> te_more inline_rt typekind<const volatile float>()              { return te_more::cv_fl;  }
            template<> te_more inline_rt typekind<const volatile double>()             { return te_more::cv_db;  }
            template<> te_more inline_rt typekind<const volatile long double>()        { return te_more::cv_ld;  }
            template<> te_more inline_rt typekind<const volatile char16_t>()           { return te_more::cv_c16; }
            template<> te_more inline_rt typekind<const volatile char32_t>()           { return te_more::cv_c32; }
            template<> te_more inline_rt typekind<const volatile wchar_t>()            { return te_more::cv_wc;  }

        template<> te_more inline_rt typekind<void*>()               { return te_more::vd_p; }
        template<> te_more inline_rt typekind<signed char*>()        { return te_more::sc_p; }
        template<> te_more inline_rt typekind<short*>()              { return te_more::ss_p; }
        template<> te_more inline_rt typekind<int*>()                { return te_more::si_p; }
        template<> te_more inline_rt typekind<long*>()               { return te_more::sl_p; }
        template<> te_more inline_rt typekind<long long*>()          { return te_more::sll_p;}
        template<> te_more inline_rt typekind<unsigned char*>()      { return te_more::uc_p; }
        template<> te_more inline_rt typekind<unsigned short*>()     { return te_more::us_p; }
        template<> te_more inline_rt typekind<unsigned int*>()       { return te_more::ui_p; }
        template<> te_more inline_rt typekind<unsigned long*>()      { return te_more::ul_p; }
        template<> te_more inline_rt typekind<unsigned long long*>() { return te_more::ull_p;}
        template<> te_more inline_rt typekind<bool*>()               { return te_more::bo_p; }
        template<> te_more inline_rt typekind<char*>()               { return te_more::ch_p; }
        template<> te_more inline_rt typekind<float*>()              { return te_more::fl_p; }
        template<> te_more inline_rt typekind<double*>()             { return te_more::db_p; }
        template<> te_more inline_rt typekind<long double*>()        { return te_more::ld_p; }
        template<> te_more inline_rt typekind<char16_t*>()           { return te_more::c16_p; }
        template<> te_more inline_rt typekind<char32_t*>()           { return te_more::c32_p; }
        template<> te_more inline_rt typekind<wchar_t*>()            { return te_more::wc_p;  }

            template<> te_more inline_rt typekind<const void*>()               { return te_more::c_vd_p; }
            template<> te_more inline_rt typekind<const signed char*>()        { return te_more::c_sc_p; }
            template<> te_more inline_rt typekind<const short*>()              { return te_more::c_ss_p; }
            template<> te_more inline_rt typekind<const int*>()                { return te_more::c_si_p; }
            template<> te_more inline_rt typekind<const long*>()               { return te_more::c_sl_p; }
            template<> te_more inline_rt typekind<const long long*>()          { return te_more::c_sll_p;}
            template<> te_more inline_rt typekind<const unsigned char*>()      { return te_more::c_uc_p; }
            template<> te_more inline_rt typekind<const unsigned short*>()     { return te_more::c_us_p; }
            template<> te_more inline_rt typekind<const unsigned int*>()       { return te_more::c_ui_p; }
            template<> te_more inline_rt typekind<const unsigned long*>()      { return te_more::c_ul_p; }
            template<> te_more inline_rt typekind<const unsigned long long*>() { return te_more::c_ull_p;}
            template<> te_more inline_rt typekind<const bool*>()               { return te_more::c_bo_p; }
            template<> te_more inline_rt typekind<const char*>()               { return te_more::c_ch_p; }
            template<> te_more inline_rt typekind<const float*>()              { return te_more::c_fl_p; }
            template<> te_more inline_rt typekind<const double*>()             { return te_more::c_db_p; }
            template<> te_more inline_rt typekind<const long double*>()        { return te_more::c_ld_p; }
            template<> te_more inline_rt typekind<const char16_t*>()           { return te_more::c_c16_p; }
            template<> te_more inline_rt typekind<const char32_t*>()           { return te_more::c_c32_p; }
            template<> te_more inline_rt typekind<const wchar_t*>()            { return te_more::c_wc_p;  }

            template<> te_more inline_rt typekind<volatile void*>()               { return te_more::v_vd_p; }
            template<> te_more inline_rt typekind<volatile signed char*>()        { return te_more::v_sc_p; }
            template<> te_more inline_rt typekind<volatile short*>()              { return te_more::v_ss_p; }
            template<> te_more inline_rt typekind<volatile int*>()                { return te_more::v_si_p; }
            template<> te_more inline_rt typekind<volatile long*>()               { return te_more::v_sl_p; }
            template<> te_more inline_rt typekind<volatile long long*>()          { return te_more::v_sll_p;}
            template<> te_more inline_rt typekind<volatile unsigned char*>()      { return te_more::v_uc_p; }
            template<> te_more inline_rt typekind<volatile unsigned short*>()     { return te_more::v_us_p; }
            template<> te_more inline_rt typekind<volatile unsigned int*>()       { return te_more::v_ui_p; }
            template<> te_more inline_rt typekind<volatile unsigned long*>()      { return te_more::v_ul_p; }
            template<> te_more inline_rt typekind<volatile unsigned long long*>() { return te_more::v_ull_p;}
            template<> te_more inline_rt typekind<volatile bool*>()               { return te_more::v_bo_p; }
            template<> te_more inline_rt typekind<volatile char*>()               { return te_more::v_ch_p; }
            template<> te_more inline_rt typekind<volatile float*>()              { return te_more::v_fl_p; }
            template<> te_more inline_rt typekind<volatile double*>()             { return te_more::v_db_p; }
            template<> te_more inline_rt typekind<volatile long double*>()        { return te_more::v_ld_p; }
            template<> te_more inline_rt typekind<volatile char16_t*>()           { return te_more::v_c16_p; }
            template<> te_more inline_rt typekind<volatile char32_t*>()           { return te_more::v_c32_p; }
            template<> te_more inline_rt typekind<volatile wchar_t*>()            { return te_more::v_wc_p;  }

            template<> te_more inline_rt typekind<const volatile void*>()               { return te_more::cv_vd_p; }
            template<> te_more inline_rt typekind<const volatile signed char*>()        { return te_more::cv_sc_p; }
            template<> te_more inline_rt typekind<const volatile short*>()              { return te_more::cv_ss_p; }
            template<> te_more inline_rt typekind<const volatile int*>()                { return te_more::cv_si_p; }
            template<> te_more inline_rt typekind<const volatile long*>()               { return te_more::cv_sl_p; }
            template<> te_more inline_rt typekind<const volatile long long*>()          { return te_more::cv_sll_p;}
            template<> te_more inline_rt typekind<const volatile unsigned char*>()      { return te_more::cv_uc_p; }
            template<> te_more inline_rt typekind<const volatile unsigned short*>()     { return te_more::cv_us_p; }
            template<> te_more inline_rt typekind<const volatile unsigned int*>()       { return te_more::cv_ui_p; }
            template<> te_more inline_rt typekind<const volatile unsigned long*>()      { return te_more::cv_ul_p; }
            template<> te_more inline_rt typekind<const volatile unsigned long long*>() { return te_more::cv_ull_p;}
            template<> te_more inline_rt typekind<const volatile bool*>()               { return te_more::cv_bo_p; }
            template<> te_more inline_rt typekind<const volatile char*>()               { return te_more::cv_ch_p; }
            template<> te_more inline_rt typekind<const volatile float*>()              { return te_more::cv_fl_p; }
            template<> te_more inline_rt typekind<const volatile double*>()             { return te_more::cv_db_p; }
            template<> te_more inline_rt typekind<const volatile long double*>()        { return te_more::cv_ld_p; }
            template<> te_more inline_rt typekind<const volatile char16_t*>()           { return te_more::cv_c16_p; }
            template<> te_more inline_rt typekind<const volatile char32_t*>()           { return te_more::cv_c32_p; }
            template<> te_more inline_rt typekind<const volatile wchar_t*>()            { return te_more::cv_wc_p;  }

            template<> te_more inline_rt typekind<void* const>()               { return te_more::vd_p_c; }
            template<> te_more inline_rt typekind<signed char* const>()        { return te_more::sc_p_c; }
            template<> te_more inline_rt typekind<short* const>()              { return te_more::ss_p_c; }
            template<> te_more inline_rt typekind<int* const>()                { return te_more::si_p_c; }
            template<> te_more inline_rt typekind<long* const>()               { return te_more::sl_p_c; }
            template<> te_more inline_rt typekind<long long* const>()          { return te_more::sll_p_c; }
            template<> te_more inline_rt typekind<unsigned char* const>()      { return te_more::uc_p_c; }
            template<> te_more inline_rt typekind<unsigned short* const>()     { return te_more::us_p_c; }
            template<> te_more inline_rt typekind<unsigned int* const>()       { return te_more::ui_p_c; }
            template<> te_more inline_rt typekind<unsigned long* const>()      { return te_more::ul_p_c; }
            template<> te_more inline_rt typekind<unsigned long long* const>() { return te_more::ull_p_c; }
            template<> te_more inline_rt typekind<bool* const>()               { return te_more::bo_p_c; }
            template<> te_more inline_rt typekind<char* const>()               { return te_more::ch_p_c; }
            template<> te_more inline_rt typekind<float* const>()              { return te_more::fl_p_c; }
            template<> te_more inline_rt typekind<double* const>()             { return te_more::db_p_c; }
            template<> te_more inline_rt typekind<long double* const>()        { return te_more::ld_p_c; }
            template<> te_more inline_rt typekind<char16_t* const>()           { return te_more::c16_p_c; }
            template<> te_more inline_rt typekind<char32_t* const>()           { return te_more::c32_p_c; }
            template<> te_more inline_rt typekind<wchar_t* const>()            { return te_more::wc_p_c;  }
            template<> te_more inline_rt typekind<void* volatile>()               { return te_more::vd_p_v; }
            template<> te_more inline_rt typekind<signed char* volatile>()        { return te_more::sc_p_v; }
            template<> te_more inline_rt typekind<short* volatile>()              { return te_more::ss_p_v; }
            template<> te_more inline_rt typekind<int* volatile>()                { return te_more::si_p_v; }
            template<> te_more inline_rt typekind<long* volatile>()               { return te_more::sl_p_v; }
            template<> te_more inline_rt typekind<long long* volatile>()          { return te_more::sll_p_v; }
            template<> te_more inline_rt typekind<unsigned char* volatile>()      { return te_more::uc_p_v; }
            template<> te_more inline_rt typekind<unsigned short* volatile>()     { return te_more::us_p_v; }
            template<> te_more inline_rt typekind<unsigned int* volatile>()       { return te_more::ui_p_v; }
            template<> te_more inline_rt typekind<unsigned long* volatile>()      { return te_more::ul_p_v; }
            template<> te_more inline_rt typekind<unsigned long long* volatile>() { return te_more::ull_p_v; }
            template<> te_more inline_rt typekind<bool* volatile>()               { return te_more::bo_p_v; }
            template<> te_more inline_rt typekind<char* volatile>()               { return te_more::ch_p_v; }
            template<> te_more inline_rt typekind<float* volatile>()              { return te_more::fl_p_v; }
            template<> te_more inline_rt typekind<double* volatile>()             { return te_more::db_p_v; }
            template<> te_more inline_rt typekind<long double* volatile>()        { return te_more::ld_p_v; }
             template<> te_more inline_rt typekind<char16_t* volatile>()           { return te_more::c16_p_v; }
            template<> te_more inline_rt typekind<char32_t* volatile>()           { return te_more::c32_p_v; }
            template<> te_more inline_rt typekind<wchar_t* volatile>()            { return te_more::wc_p_v;  }
            template<> te_more inline_rt typekind<void* const volatile>()               { return te_more::vd_p_cv; }
            template<> te_more inline_rt typekind<signed char* const volatile>()        { return te_more::sc_p_cv; }
            template<> te_more inline_rt typekind<short* const volatile>()              { return te_more::ss_p_cv; }
            template<> te_more inline_rt typekind<int* const volatile>()                { return te_more::si_p_cv; }
            template<> te_more inline_rt typekind<long* const volatile>()               { return te_more::sl_p_cv; }
            template<> te_more inline_rt typekind<long long* const volatile>()          { return te_more::sll_p_cv; }
            template<> te_more inline_rt typekind<unsigned char* const volatile>()      { return te_more::uc_p_cv; }
            template<> te_more inline_rt typekind<unsigned short* const volatile>()     { return te_more::us_p_cv; }
            template<> te_more inline_rt typekind<unsigned int* const volatile>()       { return te_more::ui_p_cv; }
            template<> te_more inline_rt typekind<unsigned long* const volatile>()      { return te_more::ul_p_cv; }
            template<> te_more inline_rt typekind<unsigned long long* const volatile>() { return te_more::ull_p_cv; }
            template<> te_more inline_rt typekind<bool* const volatile>()               { return te_more::bo_p_cv; }
            template<> te_more inline_rt typekind<char* const volatile>()               { return te_more::ch_p_cv; }
            template<> te_more inline_rt typekind<float* const volatile>()              { return te_more::fl_p_cv; }
            template<> te_more inline_rt typekind<double* const volatile>()             { return te_more::db_p_cv; }
            template<> te_more inline_rt typekind<long double* const volatile>()        { return te_more::ld_p_cv; }
            template<> te_more inline_rt typekind<char16_t* const volatile>()           { return te_more::c16_p_cv; }
            template<> te_more inline_rt typekind<char32_t* const volatile>()           { return te_more::c32_p_cv; }
            template<> te_more inline_rt typekind<wchar_t* const volatile>()            { return te_more::wc_p_cv;  }
                
                template<> te_more inline_rt typekind<const void* const>()               { return te_more::c_vd_p_c; }
                template<> te_more inline_rt typekind<const signed char* const>()        { return te_more::c_sc_p_c; }
                template<> te_more inline_rt typekind<const short* const>()              { return te_more::c_ss_p_c; }
                template<> te_more inline_rt typekind<const int* const>()                { return te_more::c_si_p_c; }
                template<> te_more inline_rt typekind<const long* const>()               { return te_more::c_sl_p_c; }
                template<> te_more inline_rt typekind<const long long* const>()          { return te_more::c_sll_p_c; }
                template<> te_more inline_rt typekind<const unsigned char* const>()      { return te_more::c_uc_p_c; }
                template<> te_more inline_rt typekind<const unsigned short* const>()     { return te_more::c_us_p_c; }
                template<> te_more inline_rt typekind<const unsigned int* const>()       { return te_more::c_ui_p_c; }
                template<> te_more inline_rt typekind<const unsigned long* const>()      { return te_more::c_ul_p_c; }
                template<> te_more inline_rt typekind<const unsigned long long* const>() { return te_more::c_ull_p_c; }
                template<> te_more inline_rt typekind<const bool* const>()               { return te_more::c_bo_p_c; }
                template<> te_more inline_rt typekind<const char* const>()               { return te_more::c_ch_p_c; }
                template<> te_more inline_rt typekind<const float* const>()              { return te_more::c_fl_p_c; }
                template<> te_more inline_rt typekind<const double* const>()             { return te_more::c_db_p_c; }
                template<> te_more inline_rt typekind<const long double* const>()        { return te_more::c_ld_p_c; }
                template<> te_more inline_rt typekind<const char16_t* const>()           { return te_more::c_c16_p_c; }
                template<> te_more inline_rt typekind<const char32_t* const>()           { return te_more::c_c32_p_c; }
                template<> te_more inline_rt typekind<const wchar_t* const>()            { return te_more::c_wc_p_c;  }

                template<> te_more inline_rt typekind<volatile void* const>()               { return te_more::v_vd_p_c; }
                template<> te_more inline_rt typekind<volatile signed char* const>()        { return te_more::v_sc_p_c; }
                template<> te_more inline_rt typekind<volatile short* const>()              { return te_more::v_ss_p_c; }
                template<> te_more inline_rt typekind<volatile int* const>()                { return te_more::v_si_p_c; }
                template<> te_more inline_rt typekind<volatile long* const>()               { return te_more::v_sl_p_c; }
                template<> te_more inline_rt typekind<volatile long long* const>()          { return te_more::v_sll_p_c; }
                template<> te_more inline_rt typekind<volatile unsigned char* const>()      { return te_more::v_uc_p_c; }
                template<> te_more inline_rt typekind<volatile unsigned short* const>()     { return te_more::v_us_p_c; }
                template<> te_more inline_rt typekind<volatile unsigned int* const>()       { return te_more::v_ui_p_c; }
                template<> te_more inline_rt typekind<volatile unsigned long* const>()      { return te_more::v_ul_p_c; }
                template<> te_more inline_rt typekind<volatile unsigned long long* const>() { return te_more::v_ull_p_c; }
                template<> te_more inline_rt typekind<volatile bool* const>()               { return te_more::v_bo_p_c; }
                template<> te_more inline_rt typekind<volatile char* const>()               { return te_more::v_ch_p_c; }
                template<> te_more inline_rt typekind<volatile float* const>()              { return te_more::v_fl_p_c; }
                template<> te_more inline_rt typekind<volatile double* const>()             { return te_more::v_db_p_c; }
                template<> te_more inline_rt typekind<volatile long double* const>()        { return te_more::v_ld_p_c; }
                template<> te_more inline_rt typekind<volatile char16_t* const>()           { return te_more::v_c16_p_c; }
                template<> te_more inline_rt typekind<volatile char32_t* const>()           { return te_more::v_c32_p_c; }
                template<> te_more inline_rt typekind<volatile wchar_t* const>()            { return te_more::v_wc_p_c;  }

                template<> te_more inline_rt typekind<const volatile void* const>()               { return te_more::cv_vd_p_c; }
                template<> te_more inline_rt typekind<const volatile signed char* const>()        { return te_more::cv_sc_p_c; }
                template<> te_more inline_rt typekind<const volatile short* const>()              { return te_more::cv_ss_p_c; }
                template<> te_more inline_rt typekind<const volatile int* const>()                { return te_more::cv_si_p_c; }
                template<> te_more inline_rt typekind<const volatile long* const>()               { return te_more::cv_sl_p_c; }
                template<> te_more inline_rt typekind<const volatile long long* const>()          { return te_more::cv_sll_p_c; }
                template<> te_more inline_rt typekind<const volatile unsigned char* const>()      { return te_more::cv_uc_p_c; }
                template<> te_more inline_rt typekind<const volatile unsigned short* const>()     { return te_more::cv_us_p_c; }
                template<> te_more inline_rt typekind<const volatile unsigned int* const>()       { return te_more::cv_ui_p_c; }
                template<> te_more inline_rt typekind<const volatile unsigned long* const>()      { return te_more::cv_ul_p_c; }
                template<> te_more inline_rt typekind<const volatile unsigned long long* const>() { return te_more::cv_ull_p_c; }
                template<> te_more inline_rt typekind<const volatile bool* const>()               { return te_more::cv_bo_p_c; }
                template<> te_more inline_rt typekind<const volatile char* const>()               { return te_more::cv_ch_p_c; }
                template<> te_more inline_rt typekind<const volatile float* const>()              { return te_more::cv_fl_p_c; }
                template<> te_more inline_rt typekind<const volatile double* const>()             { return te_more::cv_db_p_c; }
                template<> te_more inline_rt typekind<const volatile long double* const>()        { return te_more::cv_ld_p_c; }
                template<> te_more inline_rt typekind<const volatile char16_t* const>()           { return te_more::cv_c16_p_c; }
                template<> te_more inline_rt typekind<const volatile char32_t* const>()           { return te_more::cv_c32_p_c; }
                template<> te_more inline_rt typekind<const volatile wchar_t* const>()            { return te_more::cv_wc_p_c;  }

                template<> te_more inline_rt typekind<const void* volatile>()               { return te_more::c_vd_p_v; }
                template<> te_more inline_rt typekind<const signed char* volatile>()        { return te_more::c_sc_p_v; }
                template<> te_more inline_rt typekind<const short* volatile>()              { return te_more::c_ss_p_v; }
                template<> te_more inline_rt typekind<const int* volatile>()                { return te_more::c_si_p_v; }
                template<> te_more inline_rt typekind<const long* volatile>()               { return te_more::c_sl_p_v; }
                template<> te_more inline_rt typekind<const long long* volatile>()          { return te_more::c_sll_p_v; }
                template<> te_more inline_rt typekind<const unsigned char* volatile>()      { return te_more::c_uc_p_v; }
                template<> te_more inline_rt typekind<const unsigned short* volatile>()     { return te_more::c_us_p_v; }
                template<> te_more inline_rt typekind<const unsigned int* volatile>()       { return te_more::c_ui_p_v; }
                template<> te_more inline_rt typekind<const unsigned long* volatile>()      { return te_more::c_ul_p_v; }
                template<> te_more inline_rt typekind<const unsigned long long* volatile>() { return te_more::c_ull_p_v; }
                template<> te_more inline_rt typekind<const bool* volatile>()               { return te_more::c_bo_p_v; }
                template<> te_more inline_rt typekind<const char* volatile>()               { return te_more::c_ch_p_v; }
                template<> te_more inline_rt typekind<const float* volatile>()              { return te_more::c_fl_p_v; }
                template<> te_more inline_rt typekind<const double* volatile>()             { return te_more::c_db_p_v; }
                template<> te_more inline_rt typekind<const long double* volatile>()        { return te_more::c_ld_p_v; }
                template<> te_more inline_rt typekind<const char16_t* volatile>()           { return te_more::c_c16_p_v; }
                template<> te_more inline_rt typekind<const char32_t* volatile>()           { return te_more::c_c32_p_v; }
                template<> te_more inline_rt typekind<const wchar_t* volatile>()            { return te_more::c_wc_p_v;  }

                template<> te_more inline_rt typekind<volatile void* volatile>()               { return te_more::v_vd_p_v; }
                template<> te_more inline_rt typekind<volatile signed char* volatile>()        { return te_more::v_sc_p_v; }
                template<> te_more inline_rt typekind<volatile short* volatile>()              { return te_more::v_ss_p_v; }
                template<> te_more inline_rt typekind<volatile int* volatile>()                { return te_more::v_si_p_v; }
                template<> te_more inline_rt typekind<volatile long* volatile>()               { return te_more::v_sl_p_v; }
                template<> te_more inline_rt typekind<volatile long long* volatile>()          { return te_more::v_sll_p_v; }
                template<> te_more inline_rt typekind<volatile unsigned char* volatile>()      { return te_more::v_uc_p_v; }
                template<> te_more inline_rt typekind<volatile unsigned short* volatile>()     { return te_more::v_us_p_v; }
                template<> te_more inline_rt typekind<volatile unsigned int* volatile>()       { return te_more::v_ui_p_v; }
                template<> te_more inline_rt typekind<volatile unsigned long* volatile>()      { return te_more::v_ul_p_v; }
                template<> te_more inline_rt typekind<volatile unsigned long long* volatile>() { return te_more::v_ull_p_v; }
                template<> te_more inline_rt typekind<volatile bool* volatile>()               { return te_more::v_bo_p_v; }
                template<> te_more inline_rt typekind<volatile char* volatile>()               { return te_more::v_ch_p_v; }
                template<> te_more inline_rt typekind<volatile float* volatile>()              { return te_more::v_fl_p_v; }
                template<> te_more inline_rt typekind<volatile double* volatile>()             { return te_more::v_db_p_v; }
                template<> te_more inline_rt typekind<volatile long double* volatile>()        { return te_more::v_ld_p_v; }
                template<> te_more inline_rt typekind<volatile char16_t* volatile>()           { return te_more::v_c16_p_v; }
                template<> te_more inline_rt typekind<volatile char32_t* volatile>()           { return te_more::v_c32_p_v; }
                template<> te_more inline_rt typekind<volatile wchar_t* volatile>()            { return te_more::v_wc_p_v;  }

                template<> te_more inline_rt typekind<const volatile void* volatile>()               { return te_more::cv_vd_p_v; }
                template<> te_more inline_rt typekind<const volatile signed char* volatile>()        { return te_more::cv_sc_p_v; }
                template<> te_more inline_rt typekind<const volatile short* volatile>()              { return te_more::cv_ss_p_v; }
                template<> te_more inline_rt typekind<const volatile int* volatile>()                { return te_more::cv_si_p_v; }
                template<> te_more inline_rt typekind<const volatile long* volatile>()               { return te_more::cv_sl_p_v; }
                template<> te_more inline_rt typekind<const volatile long long* volatile>()          { return te_more::cv_sll_p_v; }
                template<> te_more inline_rt typekind<const volatile unsigned char* volatile>()      { return te_more::cv_uc_p_v; }
                template<> te_more inline_rt typekind<const volatile unsigned short* volatile>()     { return te_more::cv_us_p_v; }
                template<> te_more inline_rt typekind<const volatile unsigned int* volatile>()       { return te_more::cv_ui_p_v; }
                template<> te_more inline_rt typekind<const volatile unsigned long* volatile>()      { return te_more::cv_ul_p_v; }
                template<> te_more inline_rt typekind<const volatile unsigned long long* volatile>() { return te_more::cv_ull_p_v; }
                template<> te_more inline_rt typekind<const volatile bool* volatile>()               { return te_more::cv_bo_p_v; }
                template<> te_more inline_rt typekind<const volatile char* volatile>()               { return te_more::cv_ch_p_v; }
                template<> te_more inline_rt typekind<const volatile float* volatile>()              { return te_more::cv_fl_p_v; }
                template<> te_more inline_rt typekind<const volatile double* volatile>()             { return te_more::cv_db_p_v; }
                template<> te_more inline_rt typekind<const volatile long double* volatile>()        { return te_more::cv_ld_p_v; }
                template<> te_more inline_rt typekind<const volatile char16_t* volatile>()           { return te_more::cv_c16_p_v; }
                template<> te_more inline_rt typekind<const volatile char32_t* volatile>()           { return te_more::cv_c32_p_v; }
                template<> te_more inline_rt typekind<const volatile wchar_t* volatile>()            { return te_more::cv_wc_p_v;  }

                template<> te_more inline_rt typekind<const void* const volatile>()               { return te_more::c_vd_p_cv; }
                template<> te_more inline_rt typekind<const signed char* const volatile>()        { return te_more::c_sc_p_cv; }
                template<> te_more inline_rt typekind<const short* const volatile>()              { return te_more::c_ss_p_cv; }
                template<> te_more inline_rt typekind<const int* const volatile>()                { return te_more::c_si_p_cv; }
                template<> te_more inline_rt typekind<const long* const volatile>()               { return te_more::c_sl_p_cv; }
                template<> te_more inline_rt typekind<const long long* const volatile>()          { return te_more::c_sll_p_cv; }
                template<> te_more inline_rt typekind<const unsigned char* const volatile>()      { return te_more::c_uc_p_cv; }
                template<> te_more inline_rt typekind<const unsigned short* const volatile>()     { return te_more::c_us_p_cv; }
                template<> te_more inline_rt typekind<const unsigned int* const volatile>()       { return te_more::c_ui_p_cv; }
                template<> te_more inline_rt typekind<const unsigned long* const volatile>()      { return te_more::c_ul_p_cv; }
                template<> te_more inline_rt typekind<const unsigned long long* const volatile>() { return te_more::c_ull_p_cv; }
                template<> te_more inline_rt typekind<const bool* const volatile>()               { return te_more::c_bo_p_cv; }
                template<> te_more inline_rt typekind<const char* const volatile>()               { return te_more::c_ch_p_cv; }
                template<> te_more inline_rt typekind<const float* const volatile>()              { return te_more::c_fl_p_cv; }
                template<> te_more inline_rt typekind<const double* const volatile>()             { return te_more::c_db_p_cv; }
                template<> te_more inline_rt typekind<const long double* const volatile>()        { return te_more::c_ld_p_cv; }
                template<> te_more inline_rt typekind<const char16_t* const volatile>()           { return te_more::c_c16_p_cv; }
                template<> te_more inline_rt typekind<const char32_t* const volatile>()           { return te_more::c_c32_p_cv; }
                template<> te_more inline_rt typekind<const wchar_t* const volatile>()            { return te_more::c_wc_p_cv;  }

                template<> te_more inline_rt typekind<volatile void* const volatile>()               { return te_more::v_vd_p_cv; }
                template<> te_more inline_rt typekind<volatile signed char* const volatile>()        { return te_more::v_sc_p_cv; }
                template<> te_more inline_rt typekind<volatile short* const volatile>()              { return te_more::v_ss_p_cv; }
                template<> te_more inline_rt typekind<volatile int* const volatile>()                { return te_more::v_si_p_cv; }
                template<> te_more inline_rt typekind<volatile long* const volatile>()               { return te_more::v_sl_p_cv; }
                template<> te_more inline_rt typekind<volatile long long* const volatile>()          { return te_more::v_sll_p_cv; }
                template<> te_more inline_rt typekind<volatile unsigned char* const volatile>()      { return te_more::v_uc_p_cv; }
                template<> te_more inline_rt typekind<volatile unsigned short* const volatile>()     { return te_more::v_us_p_cv; }
                template<> te_more inline_rt typekind<volatile unsigned int* const volatile>()       { return te_more::v_ui_p_cv; }
                template<> te_more inline_rt typekind<volatile unsigned long* const volatile>()      { return te_more::v_ul_p_cv; }
                template<> te_more inline_rt typekind<volatile unsigned long long* const volatile>() { return te_more::v_ull_p_cv; }
                template<> te_more inline_rt typekind<volatile bool* const volatile>()               { return te_more::v_bo_p_cv; }
                template<> te_more inline_rt typekind<volatile char* const volatile>()               { return te_more::v_ch_p_cv; }
                template<> te_more inline_rt typekind<volatile float* const volatile>()              { return te_more::v_fl_p_cv; }
                template<> te_more inline_rt typekind<volatile double* const volatile>()             { return te_more::v_db_p_cv; }
                template<> te_more inline_rt typekind<volatile long double* const volatile>()        { return te_more::v_ld_p_cv; }
                template<> te_more inline_rt typekind<volatile char16_t* const volatile>()           { return te_more::v_c16_p_cv; }
                template<> te_more inline_rt typekind<volatile char32_t* const volatile>()           { return te_more::v_c32_p_cv; }
                template<> te_more inline_rt typekind<volatile wchar_t* const volatile>()            { return te_more::v_wc_p_cv;  }

                template<> te_more inline_rt typekind<const volatile void* const volatile>()               { return te_more::cv_vd_p_cv; }
                template<> te_more inline_rt typekind<const volatile signed char* const volatile>()        { return te_more::cv_sc_p_cv; }
                template<> te_more inline_rt typekind<const volatile short* const volatile>()              { return te_more::cv_ss_p_cv; }
                template<> te_more inline_rt typekind<const volatile int* const volatile>()                { return te_more::cv_si_p_cv; }
                template<> te_more inline_rt typekind<const volatile long* const volatile>()               { return te_more::cv_sl_p_cv; }
                template<> te_more inline_rt typekind<const volatile long long* const volatile>()          { return te_more::cv_sll_p_cv; }
                template<> te_more inline_rt typekind<const volatile unsigned char* const volatile>()      { return te_more::cv_uc_p_cv; }
                template<> te_more inline_rt typekind<const volatile unsigned short* const volatile>()     { return te_more::cv_us_p_cv; }
                template<> te_more inline_rt typekind<const volatile unsigned int* const volatile>()       { return te_more::cv_ui_p_cv; }
                template<> te_more inline_rt typekind<const volatile unsigned long* const volatile>()      { return te_more::cv_ul_p_cv; }
                template<> te_more inline_rt typekind<const volatile unsigned long long* const volatile>() { return te_more::cv_ull_p_cv; }
                template<> te_more inline_rt typekind<const volatile bool* const volatile>()               { return te_more::cv_bo_p_cv; }
                template<> te_more inline_rt typekind<const volatile char* const volatile>()               { return te_more::cv_ch_p_cv; }
                template<> te_more inline_rt typekind<const volatile float* const volatile>()              { return te_more::cv_fl_p_cv; }
                template<> te_more inline_rt typekind<const volatile double* const volatile>()             { return te_more::cv_db_p_cv; }
                template<> te_more inline_rt typekind<const volatile long double* const volatile>()        { return te_more::cv_ld_p_cv; }
                template<> te_more inline_rt typekind<const volatile char16_t* const volatile>()           { return te_more::cv_c16_p_cv; }
                template<> te_more inline_rt typekind<const volatile char32_t* const volatile>()           { return te_more::cv_c32_p_cv; }
                template<> te_more inline_rt typekind<const volatile wchar_t* const volatile>()            { return te_more::cv_wc_p_cv;  }
            template<> te_more inline_rt typekind<signed char[]>()        { return te_more::sc_a; }
            template<> te_more inline_rt typekind<short[]>()              { return te_more::ss_a; }
            template<> te_more inline_rt typekind<int[]>()                { return te_more::si_a; }
            template<> te_more inline_rt typekind<long[]>()               { return te_more::sl_a; }
            template<> te_more inline_rt typekind<long long[]>()          { return te_more::sll_a; }
            template<> te_more inline_rt typekind<unsigned char[]>()      { return te_more::uc_a; }
            template<> te_more inline_rt typekind<unsigned short[]>()     { return te_more::us_a; }
            template<> te_more inline_rt typekind<unsigned int[]>()       { return te_more::ui_a; }
            template<> te_more inline_rt typekind<unsigned long[]>()      { return te_more::ul_a; }
            template<> te_more inline_rt typekind<unsigned long long[]>() { return te_more::ull_a; }
            template<> te_more inline_rt typekind<char[]>()               { return te_more::ch_a; }
            template<> te_more inline_rt typekind<bool[]>()               { return te_more::bo_a; }
            template<> te_more inline_rt typekind<float[]>()              { return te_more::fl_a; }
            template<> te_more inline_rt typekind<double[]>()             { return te_more::db_a; }
            template<> te_more inline_rt typekind<long double[]>()        { return te_more::ld_a; }
            template<> te_more inline_rt typekind<char16_t[]>()           { return te_more::c16_a; }
            template<> te_more inline_rt typekind<char32_t[]>()           { return te_more::c32_a; }
            template<> te_more inline_rt typekind<wchar_t[]>()            { return te_more::wc_a;  }
                template<> te_more inline_rt typekind<const signed char[]>()        { return te_more::c_sc_a; }
                template<> te_more inline_rt typekind<const short[]>()              { return te_more::c_ss_a; }
                template<> te_more inline_rt typekind<const int[]>()                { return te_more::c_si_a; }
                template<> te_more inline_rt typekind<const long[]>()               { return te_more::c_sl_a; }
                template<> te_more inline_rt typekind<const long long[]>()          { return te_more::c_sll_a; }
                template<> te_more inline_rt typekind<const unsigned char[]>()      { return te_more::c_uc_a; }
                template<> te_more inline_rt typekind<const unsigned short[]>()     { return te_more::c_us_a; }
                template<> te_more inline_rt typekind<const unsigned int[]>()       { return te_more::c_ui_a; }
                template<> te_more inline_rt typekind<const unsigned long[]>()      { return te_more::c_ul_a; }
                template<> te_more inline_rt typekind<const unsigned long long[]>() { return te_more::c_ull_a; }
                template<> te_more inline_rt typekind<const char[]>()               { return te_more::c_ch_a; }
                template<> te_more inline_rt typekind<const bool[]>()               { return te_more::c_bo_a; }
                template<> te_more inline_rt typekind<const float[]>()              { return te_more::c_fl_a; }
                template<> te_more inline_rt typekind<const double[]>()             { return te_more::c_db_a; }
                template<> te_more inline_rt typekind<const long double[]>()        { return te_more::c_ld_a; }
                template<> te_more inline_rt typekind<const char16_t[]>()           { return te_more::c_c16_a; }
                template<> te_more inline_rt typekind<const char32_t[]>()           { return te_more::c_c32_a; }
                template<> te_more inline_rt typekind<const wchar_t[]>()            { return te_more::c_wc_a;  }
                template<> te_more inline_rt typekind<volatile signed char[]>()        { return te_more::v_sc_a; }
                template<> te_more inline_rt typekind<volatile short[]>()              { return te_more::v_ss_a; }
                template<> te_more inline_rt typekind<volatile int[]>()                { return te_more::v_si_a; }
                template<> te_more inline_rt typekind<volatile long[]>()               { return te_more::v_sl_a; }
                template<> te_more inline_rt typekind<volatile long long[]>()          { return te_more::v_sll_a; }
                template<> te_more inline_rt typekind<volatile unsigned char[]>()      { return te_more::v_uc_a; }
                template<> te_more inline_rt typekind<volatile unsigned short[]>()     { return te_more::v_us_a; }
                template<> te_more inline_rt typekind<volatile unsigned int[]>()       { return te_more::v_ui_a; }
                template<> te_more inline_rt typekind<volatile unsigned long[]>()      { return te_more::v_ul_a; }
                template<> te_more inline_rt typekind<volatile unsigned long long[]>() { return te_more::v_ull_a; }
                template<> te_more inline_rt typekind<volatile char[]>()               { return te_more::v_ch_a; }
                template<> te_more inline_rt typekind<volatile bool[]>()               { return te_more::v_bo_a; }
                template<> te_more inline_rt typekind<volatile float[]>()              { return te_more::v_fl_a; }
                template<> te_more inline_rt typekind<volatile double[]>()             { return te_more::v_db_a; }
                template<> te_more inline_rt typekind<volatile long double[]>()        { return te_more::v_ld_a; }
                template<> te_more inline_rt typekind<volatile char16_t[]>()           { return te_more::v_c16_a; }
                template<> te_more inline_rt typekind<volatile char32_t[]>()           { return te_more::v_c32_a; }
                template<> te_more inline_rt typekind<volatile wchar_t[]>()            { return te_more::v_wc_a;  }
                template<> te_more inline_rt typekind<const volatile signed char[]>()        { return te_more::cv_sc_a; }
                template<> te_more inline_rt typekind<const volatile short[]>()              { return te_more::cv_ss_a; }
                template<> te_more inline_rt typekind<const volatile int[]>()                { return te_more::cv_si_a; }
                template<> te_more inline_rt typekind<const volatile long[]>()               { return te_more::cv_sl_a; }
                template<> te_more inline_rt typekind<const volatile long long[]>()          { return te_more::cv_sll_a; }
                template<> te_more inline_rt typekind<const volatile unsigned char[]>()      { return te_more::cv_uc_a; }
                template<> te_more inline_rt typekind<const volatile unsigned short[]>()     { return te_more::cv_us_a; }
                template<> te_more inline_rt typekind<const volatile unsigned int[]>()       { return te_more::cv_ui_a; }
                template<> te_more inline_rt typekind<const volatile unsigned long[]>()      { return te_more::cv_ul_a; }
                template<> te_more inline_rt typekind<const volatile unsigned long long[]>() { return te_more::cv_ull_a; }
                template<> te_more inline_rt typekind<const volatile char[]>()               { return te_more::cv_ch_a; }
                template<> te_more inline_rt typekind<const volatile bool[]>()               { return te_more::cv_bo_a; }
                template<> te_more inline_rt typekind<const volatile float[]>()              { return te_more::cv_fl_a; }
                template<> te_more inline_rt typekind<const volatile double[]>()             { return te_more::cv_db_a; }
                template<> te_more inline_rt typekind<const volatile long double[]>()        { return te_more::cv_ld_a; }
                template<> te_more inline_rt typekind<const volatile char16_t[]>()           { return te_more::cv_c16_a; }
                template<> te_more inline_rt typekind<const volatile char32_t[]>()           { return te_more::cv_c32_a; }
                template<> te_more inline_rt typekind<const volatile wchar_t[]>()            { return te_more::cv_wc_a;  }
            template<> te_more inline_rt typekind<void*[]>()               { return te_more::vd_p_a; }
            template<> te_more inline_rt typekind<signed char*[]>()        { return te_more::sc_p_a; }
            template<> te_more inline_rt typekind<short*[]>()              { return te_more::ss_p_a; }
            template<> te_more inline_rt typekind<int*[]>()                { return te_more::si_p_a; }
            template<> te_more inline_rt typekind<long*[]>()               { return te_more::sl_p_a; }
            template<> te_more inline_rt typekind<long long*[]>()          { return te_more::sll_p_a; }
            template<> te_more inline_rt typekind<unsigned char*[]>()      { return te_more::uc_p_a; }
            template<> te_more inline_rt typekind<unsigned short*[]>()     { return te_more::us_p_a; }
            template<> te_more inline_rt typekind<unsigned int*[]>()       { return te_more::ui_p_a; }
            template<> te_more inline_rt typekind<unsigned long*[]>()      { return te_more::ul_p_a; }
            template<> te_more inline_rt typekind<unsigned long long*[]>() { return te_more::ull_p_a; }
            template<> te_more inline_rt typekind<char*[]>()               { return te_more::ch_p_a; }
            template<> te_more inline_rt typekind<bool*[]>()               { return te_more::bo_p_a; }
            template<> te_more inline_rt typekind<float*[]>()              { return te_more::fl_p_a; }
            template<> te_more inline_rt typekind<double*[]>()             { return te_more::db_p_a; }
            template<> te_more inline_rt typekind<long double*[]>()        { return te_more::ld_p_a; }
            template<> te_more inline_rt typekind<char16_t*[]>()           { return te_more::c16_p_a; }
            template<> te_more inline_rt typekind<char32_t*[]>()           { return te_more::c32_p_a; }
            template<> te_more inline_rt typekind<wchar_t*[]>()            { return te_more::wc_p_a;  }
                template<> te_more inline_rt typekind<const void*[]>()               { return te_more::c_vd_p_a; }
                template<> te_more inline_rt typekind<const signed char*[]>()        { return te_more::c_sc_p_a; }
                template<> te_more inline_rt typekind<const short*[]>()              { return te_more::c_ss_p_a; }
                template<> te_more inline_rt typekind<const int*[]>()                { return te_more::c_si_p_a; }
                template<> te_more inline_rt typekind<const long*[]>()               { return te_more::c_sl_p_a; }
                template<> te_more inline_rt typekind<const long long*[]>()          { return te_more::c_sll_p_a; }
                template<> te_more inline_rt typekind<const unsigned char*[]>()      { return te_more::c_uc_p_a; }
                template<> te_more inline_rt typekind<const unsigned short*[]>()     { return te_more::c_us_p_a; }
                template<> te_more inline_rt typekind<const unsigned int*[]>()       { return te_more::c_ui_p_a; }
                template<> te_more inline_rt typekind<const unsigned long*[]>()      { return te_more::c_ul_p_a; }
                template<> te_more inline_rt typekind<const unsigned long long*[]>() { return te_more::c_ull_p_a; }
                template<> te_more inline_rt typekind<const char*[]>()               { return te_more::c_ch_p_a; }
                template<> te_more inline_rt typekind<const bool*[]>()               { return te_more::c_bo_p_a; }
                template<> te_more inline_rt typekind<const float*[]>()              { return te_more::c_fl_p_a; }
                template<> te_more inline_rt typekind<const double*[]>()             { return te_more::c_db_p_a; }
                template<> te_more inline_rt typekind<const long double*[]>()        { return te_more::c_ld_p_a; }
                template<> te_more inline_rt typekind<const char16_t*[]>()           { return te_more::c_c16_p_a; }
                template<> te_more inline_rt typekind<const char32_t*[]>()           { return te_more::c_c32_p_a; }
                template<> te_more inline_rt typekind<const wchar_t*[]>()            { return te_more::c_wc_p_a;  }
                template<> te_more inline_rt typekind<volatile void*[]>()               { return te_more::v_vd_p_a; }
                template<> te_more inline_rt typekind<volatile signed char*[]>()        { return te_more::v_sc_p_a; }
                template<> te_more inline_rt typekind<volatile short*[]>()              { return te_more::v_ss_p_a; }
                template<> te_more inline_rt typekind<volatile int*[]>()                { return te_more::v_si_p_a; }
                template<> te_more inline_rt typekind<volatile long*[]>()               { return te_more::v_sl_p_a; }
                template<> te_more inline_rt typekind<volatile long long*[]>()          { return te_more::v_sll_p_a; }
                template<> te_more inline_rt typekind<volatile unsigned char*[]>()      { return te_more::v_uc_p_a; }
                template<> te_more inline_rt typekind<volatile unsigned short*[]>()     { return te_more::v_us_p_a; }
                template<> te_more inline_rt typekind<volatile unsigned int*[]>()       { return te_more::v_ui_p_a; }
                template<> te_more inline_rt typekind<volatile unsigned long*[]>()      { return te_more::v_ul_p_a; }
                template<> te_more inline_rt typekind<volatile unsigned long long*[]>() { return te_more::v_ull_p_a; }
                template<> te_more inline_rt typekind<volatile char*[]>()               { return te_more::v_ch_p_a; }
                template<> te_more inline_rt typekind<volatile bool*[]>()               { return te_more::v_bo_p_a; }
                template<> te_more inline_rt typekind<volatile float*[]>()              { return te_more::v_fl_p_a; }
                template<> te_more inline_rt typekind<volatile double*[]>()             { return te_more::v_db_p_a; }
                template<> te_more inline_rt typekind<volatile long double*[]>()        { return te_more::v_ld_p_a; }
                template<> te_more inline_rt typekind<volatile char16_t*[]>()           { return te_more::v_c16_p_a; }
                template<> te_more inline_rt typekind<volatile char32_t*[]>()           { return te_more::v_c32_p_a; }
                template<> te_more inline_rt typekind<volatile wchar_t*[]>()            { return te_more::v_wc_p_a;  }
                template<> te_more inline_rt typekind<const volatile void*[]>()               { return te_more::cv_vd_p_a; }
                template<> te_more inline_rt typekind<const volatile signed char*[]>()        { return te_more::cv_sc_p_a; }
                template<> te_more inline_rt typekind<const volatile short*[]>()              { return te_more::cv_ss_p_a; }
                template<> te_more inline_rt typekind<const volatile int*[]>()                { return te_more::cv_si_p_a; }
                template<> te_more inline_rt typekind<const volatile long*[]>()               { return te_more::cv_sl_p_a; }
                template<> te_more inline_rt typekind<const volatile long long*[]>()          { return te_more::cv_sll_p_a; }
                template<> te_more inline_rt typekind<const volatile unsigned char*[]>()      { return te_more::cv_uc_p_a; }
                template<> te_more inline_rt typekind<const volatile unsigned short*[]>()     { return te_more::cv_us_p_a; }
                template<> te_more inline_rt typekind<const volatile unsigned int*[]>()       { return te_more::cv_ui_p_a; }
                template<> te_more inline_rt typekind<const volatile unsigned long*[]>()      { return te_more::cv_ul_p_a; }
                template<> te_more inline_rt typekind<const volatile unsigned long long*[]>() { return te_more::cv_ull_p_a; }
                template<> te_more inline_rt typekind<const volatile char*[]>()               { return te_more::cv_ch_p_a; }
                template<> te_more inline_rt typekind<const volatile bool*[]>()               { return te_more::cv_bo_p_a; }
                template<> te_more inline_rt typekind<const volatile float*[]>()              { return te_more::cv_fl_p_a; }
                template<> te_more inline_rt typekind<const volatile double*[]>()             { return te_more::cv_db_p_a; }
                template<> te_more inline_rt typekind<const volatile long double*[]>()        { return te_more::cv_ld_p_a; }
                template<> te_more inline_rt typekind<const volatile char16_t*[]>()           { return te_more::cv_c16_p_a; }
                template<> te_more inline_rt typekind<const volatile char32_t*[]>()           { return te_more::cv_c32_p_a; }
                template<> te_more inline_rt typekind<const volatile wchar_t*[]>()            { return te_more::cv_wc_p_a;  }
                    template<> te_more inline_rt typekind<void* const[]>()               { return te_more::vd_p_c_a; }
                    template<> te_more inline_rt typekind<signed char* const[]>()        { return te_more::sc_p_c_a; }
                    template<> te_more inline_rt typekind<short* const[]>()              { return te_more::ss_p_c_a; }
                    template<> te_more inline_rt typekind<int* const[]>()                { return te_more::si_p_c_a; }
                    template<> te_more inline_rt typekind<long* const[]>()               { return te_more::sl_p_c_a; }
                    template<> te_more inline_rt typekind<long long* const[]>()          { return te_more::sll_p_c_a; }
                    template<> te_more inline_rt typekind<unsigned char* const[]>()      { return te_more::uc_p_c_a; }
                    template<> te_more inline_rt typekind<unsigned short* const[]>()     { return te_more::us_p_c_a; }
                    template<> te_more inline_rt typekind<unsigned int* const[]>()       { return te_more::ui_p_c_a; }
                    template<> te_more inline_rt typekind<unsigned long* const[]>()      { return te_more::ul_p_c_a; }
                    template<> te_more inline_rt typekind<unsigned long long* const[]>() { return te_more::ull_p_c_a; }
                    template<> te_more inline_rt typekind<char* const[]>()               { return te_more::ch_p_c_a; }
                    template<> te_more inline_rt typekind<bool* const[]>()               { return te_more::bo_p_c_a; }
                    template<> te_more inline_rt typekind<float* const[]>()              { return te_more::fl_p_c_a; }
                    template<> te_more inline_rt typekind<double* const[]>()             { return te_more::db_p_c_a; }
                    template<> te_more inline_rt typekind<long double* const[]>()        { return te_more::ld_p_c_a; }
                    template<> te_more inline_rt typekind<char16_t* const[]>()           { return te_more::c16_p_c_a; }
                    template<> te_more inline_rt typekind<char32_t* const[]>()           { return te_more::c32_p_c_a; }
                    template<> te_more inline_rt typekind<wchar_t* const[]>()            { return te_more::wc_p_c_a;  }
                    template<> te_more inline_rt typekind<const void* const[]>()               { return te_more::c_vd_p_c_a; }
                    template<> te_more inline_rt typekind<const signed char* const[]>()        { return te_more::c_sc_p_c_a; }
                    template<> te_more inline_rt typekind<const short* const[]>()              { return te_more::c_ss_p_c_a; }
                    template<> te_more inline_rt typekind<const int* const[]>()                { return te_more::c_si_p_c_a; }
                    template<> te_more inline_rt typekind<const long* const[]>()               { return te_more::c_sl_p_c_a; }
                    template<> te_more inline_rt typekind<const long long* const[]>()          { return te_more::c_sll_p_c_a; }
                    template<> te_more inline_rt typekind<const unsigned char* const[]>()      { return te_more::c_uc_p_c_a; }
                    template<> te_more inline_rt typekind<const unsigned short* const[]>()     { return te_more::c_us_p_c_a; }
                    template<> te_more inline_rt typekind<const unsigned int* const[]>()       { return te_more::c_ui_p_c_a; }
                    template<> te_more inline_rt typekind<const unsigned long* const[]>()      { return te_more::c_ul_p_c_a; }
                    template<> te_more inline_rt typekind<const unsigned long long* const[]>() { return te_more::c_ull_p_c_a; }
                    template<> te_more inline_rt typekind<const char* const[]>()               { return te_more::c_ch_p_c_a; }
                    template<> te_more inline_rt typekind<const bool* const[]>()               { return te_more::c_bo_p_c_a; }
                    template<> te_more inline_rt typekind<const float* const[]>()              { return te_more::c_fl_p_c_a; }
                    template<> te_more inline_rt typekind<const double* const[]>()             { return te_more::c_db_p_c_a; }
                    template<> te_more inline_rt typekind<const long double* const[]>()        { return te_more::c_ld_p_c_a; }
                    template<> te_more inline_rt typekind<const char16_t* const[]>()           { return te_more::c_c16_p_c_a; }
                    template<> te_more inline_rt typekind<const char32_t* const[]>()           { return te_more::c_c32_p_c_a; }
                    template<> te_more inline_rt typekind<const wchar_t* const[]>()            { return te_more::c_wc_p_c_a;  }
                    template<> te_more inline_rt typekind<volatile void* const[]>()               { return te_more::v_vd_p_c_a; }
                    template<> te_more inline_rt typekind<volatile signed char* const[]>()        { return te_more::v_sc_p_c_a; }
                    template<> te_more inline_rt typekind<volatile short* const[]>()              { return te_more::v_ss_p_c_a; }
                    template<> te_more inline_rt typekind<volatile int* const[]>()                { return te_more::v_si_p_c_a; }
                    template<> te_more inline_rt typekind<volatile long* const[]>()               { return te_more::v_sl_p_c_a; }
                    template<> te_more inline_rt typekind<volatile long long* const[]>()          { return te_more::v_sll_p_c_a; }
                    template<> te_more inline_rt typekind<volatile unsigned char* const[]>()      { return te_more::v_uc_p_c_a; }
                    template<> te_more inline_rt typekind<volatile unsigned short* const[]>()     { return te_more::v_us_p_c_a; }
                    template<> te_more inline_rt typekind<volatile unsigned int* const[]>()       { return te_more::v_ui_p_c_a; }
                    template<> te_more inline_rt typekind<volatile unsigned long* const[]>()      { return te_more::v_ul_p_c_a; }
                    template<> te_more inline_rt typekind<volatile unsigned long long* const[]>() { return te_more::v_ull_p_c_a; }
                    template<> te_more inline_rt typekind<volatile char* const[]>()               { return te_more::v_ch_p_c_a; }
                    template<> te_more inline_rt typekind<volatile bool* const[]>()               { return te_more::v_bo_p_c_a; }
                    template<> te_more inline_rt typekind<volatile float* const[]>()              { return te_more::v_fl_p_c_a; }
                    template<> te_more inline_rt typekind<volatile double* const[]>()             { return te_more::v_db_p_c_a; }
                    template<> te_more inline_rt typekind<volatile long double* const[]>()        { return te_more::v_ld_p_c_a; }
                    template<> te_more inline_rt typekind<volatile char16_t* const[]>()           { return te_more::v_c16_p_c_a; }
                    template<> te_more inline_rt typekind<volatile char32_t* const[]>()           { return te_more::v_c32_p_c_a; }
                    template<> te_more inline_rt typekind<volatile wchar_t* const[]>()            { return te_more::v_wc_p_c_a;  }
                    template<> te_more inline_rt typekind<const volatile void* const[]>()               { return te_more::cv_vd_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile signed char* const[]>()        { return te_more::cv_sc_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile short* const[]>()              { return te_more::cv_ss_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile int* const[]>()                { return te_more::cv_si_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile long* const[]>()               { return te_more::cv_sl_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile long long* const[]>()          { return te_more::cv_sll_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile unsigned char* const[]>()      { return te_more::cv_uc_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile unsigned short* const[]>()     { return te_more::cv_us_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile unsigned int* const[]>()       { return te_more::cv_ui_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile unsigned long* const[]>()      { return te_more::cv_ul_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile unsigned long long* const[]>() { return te_more::cv_ull_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile char* const[]>()               { return te_more::cv_ch_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile bool* const[]>()               { return te_more::cv_bo_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile float* const[]>()              { return te_more::cv_fl_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile double* const[]>()             { return te_more::cv_db_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile long double* const[]>()        { return te_more::cv_ld_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile char16_t* const[]>()           { return te_more::cv_c16_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile char32_t* const[]>()           { return te_more::cv_c32_p_c_a; }
                    template<> te_more inline_rt typekind<const volatile wchar_t* const[]>()            { return te_more::cv_wc_p_c_a;  }

                    template<> te_more inline_rt typekind<void* volatile[]>()               { return te_more::vd_p_v_a; }
                    template<> te_more inline_rt typekind<signed char* volatile[]>()        { return te_more::sc_p_v_a; }
                    template<> te_more inline_rt typekind<short* volatile[]>()              { return te_more::ss_p_v_a; }
                    template<> te_more inline_rt typekind<int* volatile[]>()                { return te_more::si_p_v_a; }
                    template<> te_more inline_rt typekind<long* volatile[]>()               { return te_more::sl_p_v_a; }
                    template<> te_more inline_rt typekind<long long* volatile[]>()          { return te_more::sll_p_v_a; }
                    template<> te_more inline_rt typekind<unsigned char* volatile[]>()      { return te_more::uc_p_v_a; }
                    template<> te_more inline_rt typekind<unsigned short* volatile[]>()     { return te_more::us_p_v_a; }
                    template<> te_more inline_rt typekind<unsigned int* volatile[]>()       { return te_more::ui_p_v_a; }
                    template<> te_more inline_rt typekind<unsigned long* volatile[]>()      { return te_more::ul_p_v_a; }
                    template<> te_more inline_rt typekind<unsigned long long* volatile[]>() { return te_more::ull_p_v_a; }
                    template<> te_more inline_rt typekind<char* volatile[]>()               { return te_more::ch_p_v_a; }
                    template<> te_more inline_rt typekind<bool* volatile[]>()               { return te_more::bo_p_v_a; }
                    template<> te_more inline_rt typekind<float* volatile[]>()              { return te_more::fl_p_v_a; }
                    template<> te_more inline_rt typekind<double* volatile[]>()             { return te_more::db_p_v_a; }
                    template<> te_more inline_rt typekind<long double* volatile[]>()        { return te_more::ld_p_v_a; }
                    template<> te_more inline_rt typekind<char16_t* volatile[]>()           { return te_more::c16_p_v_a; }
                    template<> te_more inline_rt typekind<char32_t* volatile[]>()           { return te_more::c32_p_v_a; }
                    template<> te_more inline_rt typekind<wchar_t* volatile[]>()            { return te_more::wc_p_v_a;  }
                    template<> te_more inline_rt typekind<const void* volatile[]>()               { return te_more::c_vd_p_v_a; }
                    template<> te_more inline_rt typekind<const signed char* volatile[]>()        { return te_more::c_sc_p_v_a; }
                    template<> te_more inline_rt typekind<const short* volatile[]>()              { return te_more::c_ss_p_v_a; }
                    template<> te_more inline_rt typekind<const int* volatile[]>()                { return te_more::c_si_p_v_a; }
                    template<> te_more inline_rt typekind<const long* volatile[]>()               { return te_more::c_sl_p_v_a; }
                    template<> te_more inline_rt typekind<const long long* volatile[]>()          { return te_more::c_sll_p_v_a; }
                    template<> te_more inline_rt typekind<const unsigned char* volatile[]>()      { return te_more::c_uc_p_v_a; }
                    template<> te_more inline_rt typekind<const unsigned short* volatile[]>()     { return te_more::c_us_p_v_a; }
                    template<> te_more inline_rt typekind<const unsigned int* volatile[]>()       { return te_more::c_ui_p_v_a; }
                    template<> te_more inline_rt typekind<const unsigned long* volatile[]>()      { return te_more::c_ul_p_v_a; }
                    template<> te_more inline_rt typekind<const unsigned long long* volatile[]>() { return te_more::c_ull_p_v_a; }
                    template<> te_more inline_rt typekind<const char* volatile[]>()               { return te_more::c_ch_p_v_a; }
                    template<> te_more inline_rt typekind<const bool* volatile[]>()               { return te_more::c_bo_p_v_a; }
                    template<> te_more inline_rt typekind<const float* volatile[]>()              { return te_more::c_fl_p_v_a; }
                    template<> te_more inline_rt typekind<const double* volatile[]>()             { return te_more::c_db_p_v_a; }
                    template<> te_more inline_rt typekind<const long double* volatile[]>()        { return te_more::c_ld_p_v_a; }
                    template<> te_more inline_rt typekind<const char16_t* volatile[]>()           { return te_more::c_c16_p_v_a; }
                    template<> te_more inline_rt typekind<const char32_t* volatile[]>()           { return te_more::c_c32_p_v_a; }
                    template<> te_more inline_rt typekind<const wchar_t* volatile[]>()            { return te_more::c_wc_p_v_a;  }
                    template<> te_more inline_rt typekind<volatile void* volatile[]>()               { return te_more::v_vd_p_v_a; }
                    template<> te_more inline_rt typekind<volatile signed char* volatile[]>()        { return te_more::v_sc_p_v_a; }
                    template<> te_more inline_rt typekind<volatile short* volatile[]>()              { return te_more::v_ss_p_v_a; }
                    template<> te_more inline_rt typekind<volatile int* volatile[]>()                { return te_more::v_si_p_v_a; }
                    template<> te_more inline_rt typekind<volatile long* volatile[]>()               { return te_more::v_sl_p_v_a; }
                    template<> te_more inline_rt typekind<volatile long long* volatile[]>()          { return te_more::v_sll_p_v_a; }
                    template<> te_more inline_rt typekind<volatile unsigned char* volatile[]>()      { return te_more::v_uc_p_v_a; }
                    template<> te_more inline_rt typekind<volatile unsigned short* volatile[]>()     { return te_more::v_us_p_v_a; }
                    template<> te_more inline_rt typekind<volatile unsigned int* volatile[]>()       { return te_more::v_ui_p_v_a; }
                    template<> te_more inline_rt typekind<volatile unsigned long* volatile[]>()      { return te_more::v_ul_p_v_a; }
                    template<> te_more inline_rt typekind<volatile unsigned long long* volatile[]>() { return te_more::v_ull_p_v_a; }
                    template<> te_more inline_rt typekind<volatile char* volatile[]>()               { return te_more::v_ch_p_v_a; }
                    template<> te_more inline_rt typekind<volatile bool* volatile[]>()               { return te_more::v_bo_p_v_a; }
                    template<> te_more inline_rt typekind<volatile float* volatile[]>()              { return te_more::v_fl_p_v_a; }
                    template<> te_more inline_rt typekind<volatile double* volatile[]>()             { return te_more::v_db_p_v_a; }
                    template<> te_more inline_rt typekind<volatile long double* volatile[]>()        { return te_more::v_ld_p_v_a; }
                    template<> te_more inline_rt typekind<volatile char16_t* volatile[]>()           { return te_more::v_c16_p_v_a; }
                    template<> te_more inline_rt typekind<volatile char32_t* volatile[]>()           { return te_more::v_c32_p_v_a; }
                    template<> te_more inline_rt typekind<volatile wchar_t* volatile[]>()            { return te_more::v_wc_p_v_a;  }
                    template<> te_more inline_rt typekind<const volatile void* volatile[]>()               { return te_more::cv_vd_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile signed char* volatile[]>()        { return te_more::cv_sc_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile short* volatile[]>()              { return te_more::cv_ss_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile int* volatile[]>()                { return te_more::cv_si_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile long* volatile[]>()               { return te_more::cv_sl_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile long long* volatile[]>()          { return te_more::cv_sll_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile unsigned char* volatile[]>()      { return te_more::cv_uc_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile unsigned short* volatile[]>()     { return te_more::cv_us_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile unsigned int* volatile[]>()       { return te_more::cv_ui_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile unsigned long* volatile[]>()      { return te_more::cv_ul_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile unsigned long long* volatile[]>() { return te_more::cv_ull_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile char* volatile[]>()               { return te_more::cv_ch_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile bool* volatile[]>()               { return te_more::cv_bo_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile float* volatile[]>()              { return te_more::cv_fl_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile double* volatile[]>()             { return te_more::cv_db_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile long double* volatile[]>()        { return te_more::cv_ld_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile char16_t* volatile[]>()           { return te_more::cv_c16_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile char32_t* volatile[]>()           { return te_more::cv_c32_p_v_a; }
                    template<> te_more inline_rt typekind<const volatile wchar_t* volatile[]>()            { return te_more::cv_wc_p_v_a;  }

                    template<> te_more inline_rt typekind<void* const volatile[]>()               { return te_more::vd_p_cv_a; }
                    template<> te_more inline_rt typekind<signed char* const volatile[]>()        { return te_more::sc_p_cv_a; }
                    template<> te_more inline_rt typekind<short* const volatile[]>()              { return te_more::ss_p_cv_a; }
                    template<> te_more inline_rt typekind<int* const volatile[]>()                { return te_more::si_p_cv_a; }
                    template<> te_more inline_rt typekind<long* const volatile[]>()               { return te_more::sl_p_cv_a; }
                    template<> te_more inline_rt typekind<long long* const volatile[]>()          { return te_more::sll_p_cv_a; }
                    template<> te_more inline_rt typekind<unsigned char* const volatile[]>()      { return te_more::uc_p_cv_a; }
                    template<> te_more inline_rt typekind<unsigned short* const volatile[]>()     { return te_more::us_p_cv_a; }
                    template<> te_more inline_rt typekind<unsigned int* const volatile[]>()       { return te_more::ui_p_cv_a; }
                    template<> te_more inline_rt typekind<unsigned long* const volatile[]>()      { return te_more::ul_p_cv_a; }
                    template<> te_more inline_rt typekind<unsigned long long* const volatile[]>() { return te_more::ull_p_cv_a; }
                    template<> te_more inline_rt typekind<char* const volatile[]>()               { return te_more::ch_p_cv_a; }
                    template<> te_more inline_rt typekind<bool* const volatile[]>()               { return te_more::bo_p_cv_a; }
                    template<> te_more inline_rt typekind<float* const volatile[]>()              { return te_more::fl_p_cv_a; }
                    template<> te_more inline_rt typekind<double* const volatile[]>()             { return te_more::db_p_cv_a; }
                    template<> te_more inline_rt typekind<long double* const volatile[]>()        { return te_more::ld_p_cv_a; }
                    template<> te_more inline_rt typekind<char16_t* const volatile[]>()           { return te_more::c16_p_cv_a; }
                    template<> te_more inline_rt typekind<char32_t* const volatile[]>()           { return te_more::c32_p_cv_a; }
                    template<> te_more inline_rt typekind<wchar_t* const volatile[]>()            { return te_more::wc_p_cv_a;  }
                    template<> te_more inline_rt typekind<const void* const volatile[]>()               { return te_more::c_vd_p_cv_a; }
                    template<> te_more inline_rt typekind<const signed char* const volatile[]>()        { return te_more::c_sc_p_cv_a; }
                    template<> te_more inline_rt typekind<const short* const volatile[]>()              { return te_more::c_ss_p_cv_a; }
                    template<> te_more inline_rt typekind<const int* const volatile[]>()                { return te_more::c_si_p_cv_a; }
                    template<> te_more inline_rt typekind<const long* const volatile[]>()               { return te_more::c_sl_p_cv_a; }
                    template<> te_more inline_rt typekind<const long long* const volatile[]>()          { return te_more::c_sll_p_cv_a; }
                    template<> te_more inline_rt typekind<const unsigned char* const volatile[]>()      { return te_more::c_uc_p_cv_a; }
                    template<> te_more inline_rt typekind<const unsigned short* const volatile[]>()     { return te_more::c_us_p_cv_a; }
                    template<> te_more inline_rt typekind<const unsigned int* const volatile[]>()       { return te_more::c_ui_p_cv_a; }
                    template<> te_more inline_rt typekind<const unsigned long* const volatile[]>()      { return te_more::c_ul_p_cv_a; }
                    template<> te_more inline_rt typekind<const unsigned long long* const volatile[]>() { return te_more::c_ull_p_cv_a; }
                    template<> te_more inline_rt typekind<const char* const volatile[]>()               { return te_more::c_ch_p_cv_a; }
                    template<> te_more inline_rt typekind<const bool* const volatile[]>()               { return te_more::c_bo_p_cv_a; }
                    template<> te_more inline_rt typekind<const float* const volatile[]>()              { return te_more::c_fl_p_cv_a; }
                    template<> te_more inline_rt typekind<const double* const volatile[]>()             { return te_more::c_db_p_cv_a; }
                    template<> te_more inline_rt typekind<const long double* const volatile[]>()        { return te_more::c_ld_p_cv_a; }
                    template<> te_more inline_rt typekind<const char16_t* const volatile[]>()           { return te_more::c_c16_p_cv_a; }
                    template<> te_more inline_rt typekind<const char32_t* const volatile[]>()           { return te_more::c_c32_p_cv_a; }
                    template<> te_more inline_rt typekind<const wchar_t* const volatile[]>()            { return te_more::c_wc_p_cv_a;  }
                    template<> te_more inline_rt typekind<volatile void* const volatile[]>()               { return te_more::v_vd_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile signed char* const volatile[]>()        { return te_more::v_sc_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile short* const volatile[]>()              { return te_more::v_ss_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile int* const volatile[]>()                { return te_more::v_si_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile long* const volatile[]>()               { return te_more::v_sl_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile long long* const volatile[]>()          { return te_more::v_sll_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile unsigned char* const volatile[]>()      { return te_more::v_uc_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile unsigned short* const volatile[]>()     { return te_more::v_us_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile unsigned int* const volatile[]>()       { return te_more::v_ui_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile unsigned long* const volatile[]>()      { return te_more::v_ul_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile unsigned long long* const volatile[]>() { return te_more::v_ull_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile char* const volatile[]>()               { return te_more::v_ch_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile bool* const volatile[]>()               { return te_more::v_bo_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile float* const volatile[]>()              { return te_more::v_fl_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile double* const volatile[]>()             { return te_more::v_db_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile long double* const volatile[]>()        { return te_more::v_ld_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile char16_t* const volatile[]>()           { return te_more::v_c16_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile char32_t* const volatile[]>()           { return te_more::v_c32_p_cv_a; }
                    template<> te_more inline_rt typekind<volatile wchar_t* const volatile[]>()            { return te_more::v_wc_p_cv_a;  }
                    template<> te_more inline_rt typekind<const volatile void* const volatile[]>()               { return te_more::cv_vd_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile signed char* const volatile[]>()        { return te_more::cv_sc_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile short* const volatile[]>()              { return te_more::cv_ss_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile int* const volatile[]>()                { return te_more::cv_si_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile long* const volatile[]>()               { return te_more::cv_sl_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile long long* const volatile[]>()          { return te_more::cv_sll_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile unsigned char* const volatile[]>()      { return te_more::cv_uc_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile unsigned short* const volatile[]>()     { return te_more::cv_us_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile unsigned int* const volatile[]>()       { return te_more::cv_ui_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile unsigned long* const volatile[]>()      { return te_more::cv_ul_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile unsigned long long* const volatile[]>() { return te_more::cv_ull_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile char* const volatile[]>()               { return te_more::cv_ch_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile bool* const volatile[]>()               { return te_more::cv_bo_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile float* const volatile[]>()              { return te_more::cv_fl_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile double* const volatile[]>()             { return te_more::cv_db_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile long double* const volatile[]>()        { return te_more::cv_ld_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile char16_t* const volatile[]>()           { return te_more::cv_c16_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile char32_t* const volatile[]>()           { return te_more::cv_c32_p_cv_a; }
                    template<> te_more inline_rt typekind<const volatile wchar_t* const volatile[]>()            { return te_more::cv_wc_p_cv_a;  }

                template<typename T> 
                te_more inline_rt typekind(T){return typekind<T>();}

                template<typename T, len_t N>
                te_more inline_rt typekind(T(&)[N]) { return typekind<T[]>(); }

                /* function pointer */
                /* no va, no noexcept */
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(*)(Args...))                       { return te_more::fnp; }
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(* const&)(Args...))                { return te_more::fnp_c; }
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(* volatile&)(Args...))             { return te_more::fnp_v; }
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(* const volatile&)(Args...))       { return te_more::fnp_cv; }

                /* no va, noexcept */
                #if defined(__cpp_noexcept_function_type)
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(*)(Args...) noexcept)              { return te_more::fnp_ne; }
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(* const&)(Args...) noexcept)       { return te_more::fnp_c_ne; }
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(* volatile&)(Args...) noexcept)    { return te_more::fnp_v_ne; }
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(* const volatile&)(Args...) noexcept) { return te_more::fnp_cv_ne; }
                #endif

                /* va, no noexcept */
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(*)(Args..., ...))                  { return te_more::fnp_va; }
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(* const&)(Args..., ...))           { return te_more::fnp_va_c; }
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(* volatile&)(Args..., ...))        { return te_more::fnp_va_v; }
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(* const volatile&)(Args..., ...))  { return te_more::fnp_va_cv; }

                /* va, noexcept */
                #if defined(__cpp_noexcept_function_type)
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(*)(Args..., ...) noexcept)         { return te_more::fnp_va_ne; }
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(* const&)(Args..., ...) noexcept)  { return te_more::fnp_va_c_ne; }
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(* volatile&)(Args..., ...) noexcept) { return te_more::fnp_va_v_ne; }
                template<typename R, typename... Args>
                te_more inline_rt typekind(R(* const volatile&)(Args..., ...) noexcept) { return te_more::fnp_va_cv_ne; }
                #endif

                /* member function pointer: mfp */

                /* no ref ,no noexcept */
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...))                     { return te_more::mfp_r_a; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) const)               { return te_more::mfp_r_a_c; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) volatile)            { return te_more::mfp_r_a_v; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) const volatile)      { return te_more::mfp_r_a_cv; }

                /* & ,no noexcept */
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) &)                   { return te_more::mfp_r_a_lr; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) const &)             { return te_more::mfp_r_a_c_lr; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) volatile &)          { return te_more::mfp_r_a_v_lr; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) const volatile &)    { return te_more::mfp_r_a_cv_lr; }

                /* && , no noexcept */
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) &&)                  { return te_more::mfp_r_a_rr; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) const &&)            { return te_more::mfp_r_a_c_rr; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) volatile &&)         { return te_more::mfp_r_a_v_rr; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) const volatile &&)   { return te_more::mfp_r_a_cv_rr; }

                #if defined(__cpp_noexcept_function_type)
                /* ref, noexcept */
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) noexcept)                    { return te_more::mfp_r_a_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) const noexcept)              { return te_more::mfp_r_a_c_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) volatile noexcept)           { return te_more::mfp_r_a_v_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) const volatile noexcept)     { return te_more::mfp_r_a_cv_ne; }

                /* & ,noexcept */
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) & noexcept)                  { return te_more::mfp_r_a_lr_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) const & noexcept)            { return te_more::mfp_r_a_c_lr_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) volatile & noexcept)         { return te_more::mfp_r_a_v_lr_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) const volatile & noexcept)   { return te_more::mfp_r_a_cv_lr_ne; }

                /* &&,noexcept */
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) && noexcept)                 { return te_more::mfp_r_a_rr_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) const && noexcept)           { return te_more::mfp_r_a_c_rr_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) volatile && noexcept)        { return te_more::mfp_r_a_v_rr_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args...) const volatile && noexcept)  { return te_more::mfp_r_a_cv_rr_ne; }
                #endif

                /* C-style variadic member function pointer */

                /* no ref, no noexcept */
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...))                    { return te_more::mfp_r_a_va; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) const)              { return te_more::mfp_r_a_va_c; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) volatile)           { return te_more::mfp_r_a_va_v; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) const volatile)     { return te_more::mfp_r_a_va_cv; }

                /* &, no noexcept */
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) &)                  { return te_more::mfp_r_a_va_lr; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) const &)            { return te_more::mfp_r_a_va_c_lr; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) volatile &)         { return te_more::mfp_r_a_va_v_lr; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) const volatile &)   { return te_more::mfp_r_a_va_cv_lr; }

                /* &&, no noexcept */
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) &&)                 { return te_more::mfp_r_a_va_rr; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) const &&)           { return te_more::mfp_r_a_va_c_rr; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) volatile &&)        { return te_more::mfp_r_a_va_v_rr; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) const volatile &&)  { return te_more::mfp_r_a_va_cv_rr; }

                #if defined(__cpp_noexcept_function_type)
                /* no ref, noexcept */
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) noexcept)                   { return te_more::mfp_r_a_va_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) const noexcept)             { return te_more::mfp_r_a_va_c_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) volatile noexcept)          { return te_more::mfp_r_a_va_v_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) const volatile noexcept)    { return te_more::mfp_r_a_va_cv_ne; }

                /* &, noexcept */
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) & noexcept)                 { return te_more::mfp_r_a_va_lr_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) const & noexcept)           { return te_more::mfp_r_a_va_c_lr_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) volatile & noexcept)        { return te_more::mfp_r_a_va_v_lr_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) const volatile & noexcept)  { return te_more::mfp_r_a_va_cv_lr_ne; }

                /* &&, noexcept */
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) && noexcept)                { return te_more::mfp_r_a_va_rr_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) const && noexcept)          { return te_more::mfp_r_a_va_c_rr_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) volatile && noexcept)       { return te_more::mfp_r_a_va_v_rr_ne; }
                template<typename C, typename R, typename... Args>
                te_more inline_rt typekind(R(C::*)(Args..., ...) const volatile && noexcept) { return te_more::mfp_r_a_va_cv_rr_ne; }
                #endif
            }
}

#endif/////////////
/*
 ____      _    _   _  ____ _____ _____ 
|  _ \    / \  | \ | |/ ___|_   _|_   _|
| |_) |  / _ \ |  \| | |  _  | |   | |  
|  _ <  / ___ \| |\  | |_| | | |   | |  
|_| \_\/_/   \_\_| \_|\____| |_|   |_|  

*/
