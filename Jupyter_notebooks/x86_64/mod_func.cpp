#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;
#if defined(__cplusplus)
extern "C" {
#endif

extern void _CaDynamics_E2_reg(void);
extern void _Ca_HVA_reg(void);
extern void _Ca_LVAst_reg(void);
extern void _Ih_reg(void);
extern void _Im_reg(void);
extern void _K_Pst_reg(void);
extern void _K_Tst_reg(void);
extern void _NaTa_t_reg(void);
extern void _NaTs2_t_reg(void);
extern void _Nap_Et2_reg(void);
extern void _ProbAMPANMDA2_reg(void);
extern void _ProbAMPANMDA_3_reg(void);
extern void _ProbAMPANMDA_David_reg(void);
extern void _ProbAMPANMDA_EMS_reg(void);
extern void _ProbGABAAB_EMS_reg(void);
extern void _ProbUDFsyn2_reg(void);
extern void _SK_E2_reg(void);
extern void _SKv3_1_reg(void);
extern void _epsp_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," \"mods/CaDynamics_E2.mod\"");
    fprintf(stderr," \"mods/Ca_HVA.mod\"");
    fprintf(stderr," \"mods/Ca_LVAst.mod\"");
    fprintf(stderr," \"mods/Ih.mod\"");
    fprintf(stderr," \"mods/Im.mod\"");
    fprintf(stderr," \"mods/K_Pst.mod\"");
    fprintf(stderr," \"mods/K_Tst.mod\"");
    fprintf(stderr," \"mods/NaTa_t.mod\"");
    fprintf(stderr," \"mods/NaTs2_t.mod\"");
    fprintf(stderr," \"mods/Nap_Et2.mod\"");
    fprintf(stderr," \"mods/ProbAMPANMDA2.mod\"");
    fprintf(stderr," \"mods/ProbAMPANMDA_3.mod\"");
    fprintf(stderr," \"mods/ProbAMPANMDA_David.mod\"");
    fprintf(stderr," \"mods/ProbAMPANMDA_EMS.mod\"");
    fprintf(stderr," \"mods/ProbGABAAB_EMS.mod\"");
    fprintf(stderr," \"mods/ProbUDFsyn2.mod\"");
    fprintf(stderr," \"mods/SK_E2.mod\"");
    fprintf(stderr," \"mods/SKv3_1.mod\"");
    fprintf(stderr," \"mods/epsp.mod\"");
    fprintf(stderr, "\n");
  }
  _CaDynamics_E2_reg();
  _Ca_HVA_reg();
  _Ca_LVAst_reg();
  _Ih_reg();
  _Im_reg();
  _K_Pst_reg();
  _K_Tst_reg();
  _NaTa_t_reg();
  _NaTs2_t_reg();
  _Nap_Et2_reg();
  _ProbAMPANMDA2_reg();
  _ProbAMPANMDA_3_reg();
  _ProbAMPANMDA_David_reg();
  _ProbAMPANMDA_EMS_reg();
  _ProbGABAAB_EMS_reg();
  _ProbUDFsyn2_reg();
  _SK_E2_reg();
  _SKv3_1_reg();
  _epsp_reg();
}

#if defined(__cplusplus)
}
#endif
