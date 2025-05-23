#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }


    virtual void setGears (int gear_state) {};
    virtual void setNstate (bool nlevel) {};
    virtual void setADC_2 (int ADC_2) {};
    virtual void setADC_3 (int ADC_3) {};
    virtual void updateprevtime(int previous_time){};
    virtual void updateStopwatch(int stopwatch_time){};
    virtual void sd_state(bool sdDetected){};
    virtual void setRPM(int rpm){};
    virtual void p_temp(int p_temperature){};


protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
