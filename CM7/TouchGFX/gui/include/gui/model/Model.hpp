#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    int ADC_VAL_2;

protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
