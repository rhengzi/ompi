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
/**
 * @file
 */
#ifndef _MCA_SVC_STDIO_
#define _MCA_SVC_STDIO_

#include "mca/svc/svc.h"
#if defined(c_plusplus) || defined(__cplusplus)
extern "C" {
#endif


/**
 * Component open/close/init
 */
int mca_svc_stdio_component_open(void);
int mca_svc_stdio_component_close(void);
mca_svc_base_module_t* mca_svc_stdio_component_init(void);

/**
 * Module init/fini
 */
int mca_svc_stdio_module_init(mca_svc_base_module_t*);
int mca_svc_stdio_module_fini(mca_svc_base_module_t*);

extern mca_svc_base_module_t mca_svc_stdio_module;
extern mca_svc_base_component_t mca_svc_stdio_component;

#if defined(c_plusplus) || defined(__cplusplus)
}
#endif
#endif

