#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::setGears (int gear_state)
{
	view.setGears (gear_state);
}

void Screen1Presenter::setNstate (bool nlevel)
{
	view.setNstate(nlevel);
}

void Screen1Presenter::setADC_2(int ADC_2)
{
	view.setADC_2(ADC_2);
}

void Screen1Presenter::updateprevtime(int previous_time)
{
	view.updateprevtime(previous_time);
}

void Screen1Presenter::updateStopwatch(int stopwatch_time)
{
	view.updateStopwatch(stopwatch_time);
}

void Screen1Presenter::sd_state(bool sdDetected)
{
	view.sd_state(sdDetected);
}

void Screen1Presenter::setRPM(int rpm)
{
	view.setRPM(rpm);
}

void Screen1Presenter::setADC_3(int ADC_3)
{
	view.setADC_3(ADC_3);
}

void Screen1Presenter::p_temp(int p_temperature)
{
	view.p_temp(p_temperature);
}
