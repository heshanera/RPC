/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "prog.h"

bool_t
xdr_operands (XDR *xdrs, operands *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->line, 100))
		 return FALSE;
	 if (!xdr_char (xdrs, &objp->c))
		 return FALSE;
	return TRUE;
}
