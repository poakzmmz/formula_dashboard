#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void setGears (int gear_state);
    virtual void setNstate (bool nlevel);
    virtual void setADC_2 (int ADC_2);
    virtual void setADC_3 (int ADC_3);
    virtual void updateStopwatch(int stopwatch_time);
    virtual void updateprevtime(int previous_time);
    virtual void sd_state(bool sdDetected);
    virtual void setRPM(int rpm);
    virtual void p_temp(int p_temperature);
protected:
};

#endif // SCREEN1VIEW_HPP
