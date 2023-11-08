/*
 * File: _coder_maxDistToClosest_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Oct-2020 22:18:13
 */

#ifndef _CODER_MAXDISTTOCLOSEST_API_H
#define _CODER_MAXDISTTOCLOSEST_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_maxDistToClosest_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real_T maxDistToClosest(emxArray_real_T *seats);
extern void maxDistToClosest_api(const mxArray * const prhs[1], int32_T nlhs,
  const mxArray *plhs[1]);
extern void maxDistToClosest_atexit(void);
extern void maxDistToClosest_initialize(void);
extern void maxDistToClosest_terminate(void);
extern void maxDistToClosest_xil_terminate(void);

#endif

/*
 * File trailer for _coder_maxDistToClosest_api.h
 *
 * [EOF]
 */
