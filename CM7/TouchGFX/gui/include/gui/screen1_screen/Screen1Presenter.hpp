#ifndef SCREEN1PRESENTER_HPP
#define SCREEN1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen1View;

class Screen1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen1Presenter(Screen1View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Screen1Presenter() {}

    virtual void setGears(int gear_state);
    virtual void setNstate(bool nlevel);
    virtual void setADC_2 (int ADC_2);
    virtual void setADC_3 (int ADC_3);
    virtual void updateStopwatch(int stopwatch_time);
    virtual void updateprevtime(int previous_time);
    virtual void sd_state(bool sdDetected);
    virtual void setRPM(int rpm);
    virtual void p_temp(int p_temperature);

private:
    Screen1Presenter();

    Screen1View& view;
};

#endif // SCREEN1PRESENTER_HPP
