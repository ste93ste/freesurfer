/**
 * @file  cmat.h
 * @brief prototypes for reading/writing a Connectome MATrix structure
 *
 * Prototypes and structures for manipulating, reading and writing  for the Connectome Matrix (CMAT)
 * structure.
 */
/*
 * Original Author: Bruce Fischl
 * CVS Revision Info:
 *    $Author: fischl $
 *    $Date: 2013/04/15 21:56:39 $
 *    $Revision: 1.4 $
 *
 * Copyright © 2011 The General Hospital Corporation (Boston, MA) "MGH"
 *
 * Terms and conditions for use, reproduction, distribution and contribution
 * are found in the 'FreeSurfer Software License Agreement' contained
 * in the file 'LICENSE' found in the FreeSurfer distribution, and here:
 *
 * https://surfer.nmr.mgh.harvard.edu/fswiki/FreeSurferSoftwareLicense
 *
 * Reporting: freesurfer@nmr.mgh.harvard.edu
 *
 */

/*-----------------------------------------------------
  INCLUDE FILES
  -------------------------------------------------------*/
#ifndef CMAT_H
#define CMAT_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "label.h"

typedef struct
{
 int  nlabels ;       // # of labels
 int   *labels ;      // annot value of each label
 LABEL ***splines ;    // nlabels x nlabels splines
 double **weights ;   // nlabels x nlabels measure of connection strength
} CMAT ;


CMAT  *CMATread(const char *fname) ;
int CMATwrite(CMAT *cmat, const char *fname) ;
CMAT *CMATalloc(int nlabels, int *labels) ;
int CMATfree(CMAT **pcmat) ;
CMAT *CMATtransform(CMAT *csrc, TRANSFORM *xform, MRI *mri_src, MRI *mri_dst, CMAT *cdst) ;

#if defined(__cplusplus)
};
#endif

#endif