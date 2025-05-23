#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <cstring>
#include "cmsis_os2.h"

extern "C"
{
	#include "main.h"
	extern ADC_HandleTypeDef hadc1;
	extern ADC_HandleTypeDef hadc2;
	extern ADC_HandleTypeDef hadc3;
	extern TIM_HandleTypeDef htim4;

	extern osMessageQueueId_t gearStateQueueHandle;

	#include "stm32h7xx.h"

	long map(long x, long in_min, long in_max, long out_min, long out_max)
	{
			return (x - in_min) * (out_max - out_min + 1) / (in_max - in_min + 1) + out_min;
	}
}



/*
typedef enum GearState
{
    Neutral,
    FirstGear,
    SecondGear,
    ThirdGear,
    FourthGear,
    FifthGear,
    SixthGear
} GearState;
*/
Model::Model() : modelListener(0), ADC_VAL_2(50)
{

}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) ;

uint32_t lastDebounceTime = 0;
const uint32_t debounceDelay = 160;

uint32_t lastDebounceTime_2 = 0;
const uint32_t debounceDelay_2 = 160;

uint32_t lastDebounceTimeK6 = 0;
const uint32_t debounceDelayK6 = 50;

//static uint32_t last_tick = 0;
uint32_t interval = 250;

volatile int stopwatch_time = 0;  // stopwatch value
volatile bool running = false;         // stopwatch state
volatile int previous_time;
int gearState = 0;
bool N_state = false;
bool CLUTCH_FLAG = false;

int get_Oiltemp(void);
int get_Watertemp(void);

void Model::tick()
{

	/********** OIL **********/
	int oil_temp = get_Oiltemp();
    modelListener->setADC_2(oil_temp);

	/********** WATER **********/

    int water_temp = get_Watertemp();
    modelListener->setADC_3(water_temp);

	/********** PROCESSOR TEMPERATURE **********/
	HAL_ADC_Start(&hadc3);
	HAL_ADC_PollForConversion(&hadc3, 10);
	uint32_t raw_Ptemperature = HAL_ADC_GetValue(&hadc3);
	HAL_ADC_Stop(&hadc3);
    int vref = 3300;
    int vsense = (raw_Ptemperature * vref) / 65535;  // 16-bit ADC (0~65535)
    int V25 = 760;
    int Avg_Slope = 25;
    int p_temperature = (V25 - vsense) / Avg_Slope + 25;
    modelListener->p_temp(p_temperature);


	/********** RPM **********/



	/********** GEAR **********/
    uint32_t receivedGearState;
    osMessageQueueGet(gearStateQueueHandle, &receivedGearState, NULL, osWaitForever);

    switch(receivedGearState)
    {
    	case 0: modelListener->setNstate(1);
    	break;

    	default: modelListener->setGears(receivedGearState), modelListener->setNstate(0);
    	break;
    }

    modelListener->sd_state(false);


	/********** LAP TIME **********/
	static int lastTickTime = 0;
	int currentTickTime = HAL_GetTick();
	int deltaTime = currentTickTime - lastTickTime;
	lastTickTime = currentTickTime;
	if (HAL_GPIO_ReadPin(GPIOK, JOY_LEFT_Pin) == GPIO_PIN_RESET)
	{
		stopwatch_time = 0;
		running = 1;
		modelListener->updateprevtime(previous_time);
	}

	else if (HAL_GPIO_ReadPin(GPIOK, JOY_RIGHT_Pin) == GPIO_PIN_RESET)
	{
		running = 0;
		previous_time = stopwatch_time;
	}

	if (running)
	{
		stopwatch_time += deltaTime;
	}

	modelListener->updateStopwatch(stopwatch_time);

}

int get_Oiltemp(void)
{
    int adc_value_2 = 0;
    int ADC_VAL_2 = 0;
    HAL_ADC_Start(&hadc2);
    if (HAL_ADC_PollForConversion(&hadc2, 10) == HAL_OK)
    {
        adc_value_2 = HAL_ADC_GetValue(&hadc2);
    }
    HAL_ADC_Stop(&hadc2);
    ADC_VAL_2 = map(adc_value_2, 0, 65535, 0, 300);

    return ADC_VAL_2;
}

int get_Watertemp(void)
{
    int adc_value_1 = 0;
    int ADC_VAL_1 = 0;
    HAL_ADC_Start(&hadc1);
	if(HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
    {
        adc_value_1 = HAL_ADC_GetValue(&hadc1);
    }
    HAL_ADC_Stop(&hadc1);
	ADC_VAL_1 = map(adc_value_1, 0, 65535, 0 , 300);

	return ADC_VAL_1;
}

