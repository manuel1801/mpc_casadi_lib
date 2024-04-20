// #include <include/mpc_casadi_lib.h>
#include <mpc_casadi_lib.h>



MPCCasadiLib::MPCCasadiLib()
{
    std::cout << "casadi obj created" << std::endl;
    n_states_ = 2;
}

MPCCasadiLib::MPCCasadiLib(ModelBase *model)
{
    model_ = model;
    n_states_ = 3;
}

int MPCCasadiLib::get_n_states()
{
    return n_states_;
}

MPCCasadiLib::~MPCCasadiLib()
{
    std::cout << "casadi obj destroyed" << std::endl;
}

