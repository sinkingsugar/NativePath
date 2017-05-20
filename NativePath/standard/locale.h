#ifndef _LOCALE_H_
#define _LOCALE_H_

#include "stdlib.h"

typedef struct __locale_struct
{
  /* Note: LC_ALL is not a valid index into this array.  */
  struct __locale_data *__locales[13]; /* 13 = __LC_LAST. */

  /* To increase the speed of this solution we add some special members.  */
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;

  /* Note: LC_ALL is not a valid index into this array.  */
  const char *__names[13];
} *__locale_t;

typedef __locale_t locale_t;

struct lconv
{
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
  char int_n_cs_precedes;
  char int_n_sep_by_space;
  char int_n_sign_posn;
  char int_p_cs_precedes;
  char int_p_sep_by_space;
  char int_p_sign_posn;
};

#define LC_ALL	    0
#define LC_COLLATE  1
#define LC_CTYPE    2
#define LC_MONETARY 3
#define LC_NUMERIC  4
#define LC_TIME     5
#define LC_MESSAGES 6

# define LC_CTYPE_MASK		(1 << LC_CTYPE)
# define LC_NUMERIC_MASK	(1 << LC_NUMERIC)
# define LC_TIME_MASK		(1 << LC_TIME)
# define LC_COLLATE_MASK	(1 << LC_COLLATE)
# define LC_MONETARY_MASK	(1 << LC_MONETARY)
# define LC_MESSAGES_MASK	(1 << LC_MESSAGES)
# define LC_PAPER_MASK		(1 << LC_PAPER)
# define LC_NAME_MASK		(1 << LC_NAME)
# define LC_ADDRESS_MASK	(1 << LC_ADDRESS)
# define LC_TELEPHONE_MASK	(1 << LC_TELEPHONE)
# define LC_MEASUREMENT_MASK	(1 << LC_MEASUREMENT)
# define LC_IDENTIFICATION_MASK	(1 << LC_IDENTIFICATION)
# define LC_ALL_MASK		(LC_CTYPE_MASK \
				 | LC_NUMERIC_MASK \
				 | LC_TIME_MASK \
				 | LC_COLLATE_MASK \
				 | LC_MONETARY_MASK \
				 | LC_MESSAGES_MASK \
				 | LC_PAPER_MASK \
				 | LC_NAME_MASK \
				 | LC_ADDRESS_MASK \
				 | LC_TELEPHONE_MASK \
				 | LC_MEASUREMENT_MASK \
				 | LC_IDENTIFICATION_MASK \
				 )

#ifdef __cplusplus
extern "C" {
#endif

extern locale_t uselocale(locale_t newloc);
extern char* setlocale(int category, const char *locale);
extern int __locale_mb_cur_max();
extern struct lconv* localeconv(void);

#define MB_CUR_MAX __locale_mb_cur_max()

extern long long int strtoll_l (const char * __nptr, char ** __endptr, int __base, __locale_t __loc);
extern unsigned long long int strtoull_l (const char * __nptr, char ** __endptr,int __base, __locale_t __loc);
extern unsigned long long int strtoull_l (const char * __nptr, char ** __endptr, int __base, __locale_t __loc);
extern double strtod_l (const char * __nptr, char ** __endptr, __locale_t __loc);
extern float strtof_l (const char * __nptr, char ** __endptr, __locale_t __loc);
extern long double strtold_l (const char * __nptr, char ** __endptr, __locale_t __loc);

extern int isxdigit(int __c);
extern int isdigit(int __c);
extern int isxdigit_l(int __c, __locale_t __loc);
extern int isdigit_l(int __c, __locale_t __loc);

#ifdef __cplusplus
}
#endif

#endif