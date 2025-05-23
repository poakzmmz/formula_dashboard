#include <gui/screen1_screen/Screen1View.hpp>
void getRGBFromTemp(int value, uint8_t& r, uint8_t& g, uint8_t& b);

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::setGears(int gear_state)
{
	Unicode::snprintf(Gear_statBuffer, GEAR_STAT_SIZE, "%d", gear_state);
	Gear_stat.invalidate();
}

void Screen1View::setNstate(bool nlevel)
{
	Gear_stat.setVisible(!nlevel);
	Gear_stat.invalidate();
	N_stat.setVisible(nlevel);
	N_stat.invalidate();
}

void Screen1View::setADC_2(int ADC_2) // Oil temperature
{
	uint8_t r, g, b;
	getRGBFromTemp(ADC_2, r, g, b); //Temperature-based text color
	Oil.setColor(touchgfx::Color::getColorFromRGB(r, g, b));
	Unicode::snprintf(OilBuffer, OIL_SIZE, "%d", ADC_2);
	Oil.invalidate();

	//Unicode::snprintf(RpmBuffer, RPM_SIZE, "%d", ADC_2);
	//Rpm.invalidate();
	//for RPM UI TEST...
}

void Screen1View::setADC_3(int ADC_3) // Coolant temperature (water)
{
	uint8_t r, g, b;
	getRGBFromTemp(ADC_3, r, g, b); //Temperature-based text color
	Water.setColor(touchgfx::Color::getColorFromRGB(r, g, b));
	Unicode::snprintf(WaterBuffer, WATER_SIZE, "%d", ADC_3);
	Water.invalidate();
}

void Screen1View::sd_state(bool sdDetected)
{
	Sd_detect.setVisible(sdDetected); // 나중에 수정.
	Sd_detect.invalidate();
}

void Screen1View::setRPM(int rpm)
{
	Unicode::snprintf(RpmBuffer, RPM_SIZE, "%d", rpm);
	Rpm.invalidate();
}

void Screen1View::p_temp(int p_temperature)
{
	Unicode::snprintf(P_tempBuffer, P_TEMP_SIZE, "%d", p_temperature);
}

void Screen1View::updateprevtime (int previous_time)
{
	if(previous_time / 60000 < 10)
	{
		if((previous_time / 1000) % 60 < 10)
		{
			Unicode::snprintf(Laptime_previousBuffer, LAPTIME_PREVIOUS_SIZE,  "0%d:0%d.%d",
				                  previous_time / 60000,
				                  (previous_time / 1000) % 60,
				                  previous_time % 1000);
			Laptime_previous.invalidate();
		}

		else if ((previous_time / 1000) % 60 >= 10)
		{
			Unicode::snprintf(Laptime_previousBuffer, LAPTIME_PREVIOUS_SIZE,  "0%d:%d.%d",
								previous_time / 60000,
								(previous_time / 1000) % 60,
						        previous_time % 1000);
			Laptime_previous.invalidate();
		}
	}
	else if(previous_time / 60000 >= 10)
	{
		if((previous_time / 1000) % 60 < 10)
		{
			Unicode::snprintf(Laptime_previousBuffer, LAPTIME_PREVIOUS_SIZE,  "%d:0%d.%d",
				                  previous_time / 60000,
				                  (previous_time / 1000) % 60,
				                  previous_time % 1000);
			Laptime_previous.invalidate();
		}

		else if ((previous_time / 1000) % 60 >= 10)
		{
			Unicode::snprintf(Laptime_previousBuffer, LAPTIME_PREVIOUS_SIZE,  "%d:%d.%d",
								previous_time / 60000,
								(previous_time / 1000) % 60,
						        previous_time % 1000);
			Laptime_previous.invalidate();
		}
	}




}

void Screen1View::updateStopwatch (int stopwatch_time)
{

	if(stopwatch_time / 60000 < 10)
	{
		if((stopwatch_time / 1000) % 60 < 10)
		{
			Unicode::snprintf(Laptime_realtimeBuffer, LAPTIME_REALTIME_SIZE,  "0%d:0%d.%d",
				                  stopwatch_time / 60000,
				                  (stopwatch_time / 1000) % 60,
				                  stopwatch_time % 1000);
			Laptime_realtime.invalidate();
		}

		else if ((stopwatch_time / 1000) % 60 >= 10)
		{
			Unicode::snprintf(Laptime_realtimeBuffer, LAPTIME_REALTIME_SIZE,  "0%d:%d.%d",
								stopwatch_time / 60000,
								(stopwatch_time / 1000) % 60,
						        stopwatch_time % 1000);
			Laptime_realtime.invalidate();
		}
	}
	else if(stopwatch_time / 60000 >= 10)
	{
		if((stopwatch_time / 1000) % 60 < 10)
		{
			Unicode::snprintf(Laptime_realtimeBuffer, LAPTIME_REALTIME_SIZE,  "%d:0%d.%d",
				                  stopwatch_time / 60000,
				                  (stopwatch_time / 1000) % 60,
				                  stopwatch_time % 1000);
			Laptime_realtime.invalidate();
		}

		else if ((stopwatch_time / 1000) % 60 >= 10)
		{
			Unicode::snprintf(Laptime_realtimeBuffer, LAPTIME_REALTIME_SIZE,  "%d:%d.%d",
								stopwatch_time / 60000,
								(stopwatch_time / 1000) % 60,
						        stopwatch_time % 1000);
			Laptime_realtime.invalidate();
		}
	}
}

void getRGBFromTemp(int value, uint8_t& r, uint8_t& g, uint8_t& b)
{
    if (value < 60)
    {
        r = 255; g = 255; b = 255; // 흰색
    }
    else if (value < 90)
    {
        r = 0; g = 255; b = 0;     // 초록색
    }
    else if (value < 110)
    {
        r = 255; g = 165; b = 0;   // 주황색
    }
    else
    {
        r = 255; g = 0; b = 0;     // 빨간색
    }
}
