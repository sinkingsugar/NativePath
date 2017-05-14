#ifndef time_h
#define time_h

#include "../NativePath.h"

struct tm
{
  int tm_sec;			/* Seconds.	[0-60] (1 leap second) */
  int tm_min;			/* Minutes.	[0-59] */
  int tm_hour;			/* Hours.	[0-23] */
  int tm_mday;			/* Day.		[1-31] */
  int tm_mon;			/* Month.	[0-11] */
  int tm_year;			/* Year	- 1900.  */
  int tm_wday;			/* Day of week.	[0-6] */
  int tm_yday;			/* Days in year.[0-365]	*/
  int tm_isdst;			/* DST.		[-1/0/1]*/

  long int tm_gmtoff;		/* Seconds east of UTC.  */
  const char *tm_zone;		/* Timezone abbreviation.  */
};

typedef long int time_t;
typedef long int clock_t;

//TODO
extern clock_t clock();
extern double difftime(time_t time1, time_t time0);
extern time_t mktime(tm* timeptr);
extern time_t time(time_t* timer);
extern char* asctime(const tm* timeptr);
extern char* ctime(const time_t* timer);
extern tm*    gmtime(const time_t* timer);
extern tm* localtime(const time_t* timer);
extern size_t strftime(char* s, size_t maxsize, const char* format, const tm* timeptr);

#endif