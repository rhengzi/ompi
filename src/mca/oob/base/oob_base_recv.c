/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University.
 *                         All rights reserved.
 * Copyright (c) 2004-2005 The Trustees of the University of Tennessee.
 *                         All rights reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart, 
 *                         University of Stuttgart.  All rights reserved.
 * $COPYRIGHT$
 * 
 * Additional copyrights may follow
 * 
 * $HEADER$
 */


#include "ompi_config.h"
#include "include/constants.h"
#include "mca/oob/oob.h"
#include "mca/oob/base/base.h"
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#include <string.h>
#include "util/bufpack.h"


/*
* Similiar to unix recv(2)
*
* @param peer (IN)    Opaque name of peer process or MCA_OOB_NAME_ANY for wildcard receive.
* @param msg (IN)     Array of iovecs describing user buffers and lengths.
* @param types (IN)   Parallel array to iovecs describing data type of each iovec element.
* @param count (IN)   Number of elements in iovec array.
* @param tag (IN)     User defined tag for matching send/recv.
* @param flags (IN)   May be MCA_OOB_PEEK to return up to the number of bytes provided in the
*                     iovec array without removing the message from the queue.
* @return             OMPI error code (<0) on error or number of bytes actually received.
*/
int mca_oob_recv(ompi_process_name_t* peer, struct iovec *msg, int count, int* tag, int flags)
{
    return(mca_oob.oob_recv(peer, msg, count, tag, flags));
}

/*
* Similiar to unix recv(2)
*
* @param peer (IN)    Opaque name of peer process or MCA_OOB_NAME_ANY for wildcard receive.
* @param buffer (OUT) Buffer that the OOB creates to recv this message...
* @param tag (IN)     User defined tag for matching send/recv.
*                     iovec array without removing the message from the queue.
* @return             OMPI error code (<0) on error or number of bytes actually received.
*/
int mca_oob_recv_packed(ompi_process_name_t* peer, ompi_buffer_t *buf, int* tag)
{
    int rc;
    struct iovec msg[1];

	/* setup iov */
	msg[0].iov_base = NULL;
	msg[0].iov_len  = 0;

    rc = mca_oob.oob_recv(peer, msg, 1, tag, MCA_OOB_ALLOC);
    if(rc < 0)
        return rc;

    /* initialize buffer */
	return ompi_buffer_init_preallocated (buf, msg[0].iov_base, msg[0].iov_len);
}

