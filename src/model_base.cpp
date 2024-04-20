#include <model_base.h>

ModelBase::ModelBase(){}
ModelBase::~ModelBase(){}


int ModelBase::get_n_controls(){return n_controls_;};
int ModelBase::get_n_states(){return n_states_;};
int ModelBase::get_n_outputs(){return n_outputs_;};

double ModelBase::get_sample_time(){return dt_;};


SX ModelBase::eval(const SX &state, const SX &control, double dt)
{
    // RK4 integration of ode evaluated with casadis Symbolic expression SX
    SX state_next_ = state;
    for (int j = 0; j < (dt/dt_); j++)
    {        
        SX k1_ = ode_((vector<SX>){state_next_, control}).at(0);
        SX k2_ = ode_((vector<SX>){state_next_+dt_/2*k1_, control}).at(0);
        SX k3_ = ode_((vector<SX>){state_next_+dt_/2*k2_, control}).at(0);
        SX k4_ = ode_((vector<SX>){state_next_+dt_*k3_, control}).at(0);
        state_next_ += dt_/6*(k1_ + 2*k2_ + 2*k3_ + k4_);     
    }   
    return state_next_;
}


DM ModelBase::eval(const DM &state, const DM &control, double dt)
{
    // RK4 integration of ode evaluated with casadis Numeric expression DM
    DM state_next_ = state;
    for (int j = 0; j < (dt/dt_); j++)
    {        
        DM k1_ = ode_((vector<DM>){state_next_, control}).at(0);
        DM k2_ = ode_((vector<DM>){state_next_+dt_/2*k1_, control}).at(0);
        DM k3_ = ode_((vector<DM>){state_next_+dt_/2*k2_, control}).at(0);
        DM k4_ = ode_((vector<DM>){state_next_+dt_*k3_, control}).at(0);
        state_next_ += dt_/6*(k1_ + 2*k2_ + 2*k3_ + k4_);        
    }
    return state_next_;
}