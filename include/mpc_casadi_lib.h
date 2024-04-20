#ifndef MPC_CASADI_LIB_H
#define MPC_CASADI_LIB_H

#include <iostream>
#include <model_base.h>



class MPCCasadiLib
{
private:
    
int n_states_, n_controls_;
ModelBase *model_;


public:
    // SORO_MPC(SingleChamberSystem &model, bool trajectoryTracking);

    MPCCasadiLib();
    
    MPCCasadiLib(ModelBase *model);
    
    ~MPCCasadiLib();

    int get_n_states();


};

#endif