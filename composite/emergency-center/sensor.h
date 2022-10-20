#ifndef SENSOR_H_
#define SENSOR_H_

class Sensor
{
    protected:
        int  ID;
        int gen;
    public:
        Sensor(int id, int gen);
        Sensor() = default;
        virtual ~Sensor() = default;
        int generation();
        int id();
        void test();
        virtual void panic();
};
#endif

/*use virtual destructors to avoid static binding to the base class destructor
test calls panic, if you do not define panic as virtual
you will have static binding to the member function of the base class
*/