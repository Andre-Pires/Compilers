/* $Id: tabid.h,v 1.1 2008/06/29 22:00:10 joao.c.fernandes Exp $ */
#ifndef _TABID_H_
#define _TABID_H_

void   *IDroot(void *swap);
void	IDpop(void),
	IDpush(void),
	IDprint(void);
int	IDnew(int,char*,int),
	IDreplace(int,char*,int),
	IDfind(char*,int*);

extern int IDdebug; /* set to 1 to get debug message in stdout */

#define IDtest (-1) /* probe IDfind and IDnew without error messages */

#endif /* _TABID_H_ */
