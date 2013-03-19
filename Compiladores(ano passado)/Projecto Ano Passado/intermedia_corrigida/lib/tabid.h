/* $Id: tabid.h,v 1.1 2005/10/17 12:51:02 prs Exp $ */
#ifndef _TABID_H_
#define _TABID_H_

typedef int (*IDfunc)(int,char*,int);
void   *IDroot(void *swap);
void	IDpop(void),
	IDpush(void),
	IDprint(void);
int	IDnew(int,char*,int),
	IDreplace(int,char*,int),
	IDfind(char*,int*),
	IDforall(IDfunc);

extern int IDdebug; /* set to 1 to get debug message in stdout */

#define IDtest (-1) /* probe IDfind and IDnew without error messages */

#endif /* _TABID_H_ */
