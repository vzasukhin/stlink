/*
 * Ugly, low performance, configurable level, logging "framework"
 */

#ifndef UGLYLOGGING_H
#define	UGLYLOGGING_H

#ifdef	__cplusplus
extern "C" {
#endif

enum ugly_loglevel {
	UDEBUG = 90,
	UINFO  = 50,
	UWARN  = 30,
	UERROR = 20,
	UFATAL = 10
};

int ugly_init(int maximum_threshold);
int ugly_log(int level, const char *tag, const char *format, ...);

#define DLOG(format, args...)   ugly_log(UDEBUG, __FILE__, format, ## args)
#define ILOG(format, args...)   ugly_log(UINFO, __FILE__, format, ## args)
#define WLOG(format, args...)   ugly_log(UWARN, __FILE__, format, ## args)
#define ELOG(format, args...)   ugly_log(UERROR, __FILE__, format, ## args)
#define fatal(format, args...)  ugly_log(UFATAL, __FILE__, format, ## args)

#ifdef	__cplusplus
}
#endif

#endif	/* UGLYLOGGING_H */

