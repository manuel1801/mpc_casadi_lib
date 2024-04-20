

#include <iostream>
#include <mpc_casadi_lib/mpc_casadi_lib.h>
#include <mpc_casadi_lib/model_base.h>

using namespace std;


int main()
{

    ModelBase *m = new ModelBase;


    MPCCasadiLib my_mpc_lib;
    MPCCasadiLib my_mpc_lib2(m);

    cout << my_mpc_lib.get_n_states() << endl;
    cout << my_mpc_lib2.get_n_states() << endl;
    

    
    return 0;
}