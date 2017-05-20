#ifndef _WCTYPE_H_
#define _WCTYPE_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _WCTYPE_T
#define _WCTYPE_T
typedef int wctype_t;
#endif

#ifndef _WCTRANS_T
#define _WCTRANS_T
typedef int wctrans_t;
#endif

extern int iswalnum(wint_t wc);
extern int iswalpha(wint_t wc);
extern int iswblank(wint_t wc);  // C99
extern int iswcntrl(wint_t wc);
extern int iswdigit(wint_t wc);
extern int iswgraph(wint_t wc);
extern int iswlower(wint_t wc);
extern int iswprint(wint_t wc);
extern int iswpunct(wint_t wc);
extern int iswspace(wint_t wc);
extern int iswupper(wint_t wc);
extern int iswxdigit(wint_t wc);
extern int iswctype(wint_t wc, wctype_t desc);
extern wctype_t wctype(const char* property);
extern wint_t towlower(wint_t wc);
extern wint_t towupper(wint_t wc);
extern wint_t towctrans(wint_t wc, wctrans_t desc);
extern wctrans_t wctrans(const char* property);

#ifdef __cplusplus
}
#endif

#endif /* _WCTYPE_H_ */