#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Engine
{
private:
    string engineType;
    int horsepower;
    int torque;
    string fuelType;
    float engineCapacity;

public:
    void setEngineType(string et)
    {
        engineType = et;
    }

    void setHorsepower(int h)
    {
        horsepower = h;
    }

    void setTorque(int t)
    {
        torque = t;
    }

    void setFuelType(string ft)
    {
        fuelType = ft;
    }

    void setEngineCapacity(float ec)
    {
        engineCapacity = ec;
    }

    void showEngine()
    {
        cout << "\tEngine Type: " << engineType << endl;
        cout << "\tHorses: " << horsepower << "HP" << endl;
        cout << "\tTorque: " << torque << "nm" << endl;
        cout << "\tFuel Type: " << fuelType << endl;
        cout << "\tEngine Capacity: " << engineCapacity << "L" << endl;
        return;
    }
};

class Car
{
private:
    Engine* engine;
    int wheelSize;
    string color;
    int doorsNumber;
    string type;
    string brand;
    string model;

public:

    Car(Engine* e)
    {
        engine = e;
    }

    void setWheelSize(int ws)
    {
        wheelSize = ws;
    }

    void setColor(string c)
    {
        color = c;
    }

    void setDoorsNumber(int dn)
    {
        doorsNumber = dn;
    }

    void setType(string t)
    {
        type = t;
    }

    void setBrand(string b)
    {
        brand = b;
    }

    void setModel(string m)
    {
        model = m;
    }

    void showCar()
    {
        cout << "\t" << brand << " " << model << " " << type << endl;
        cout << "\n\t----Engine---" << endl << endl;
        engine->showEngine();
        cout << endl << "\t----Details----" << endl << endl;
        cout << "\tSize of Wheels: " << wheelSize << "``" << endl;
        cout << "\tColor: " << color << endl;
        cout << "\tNumber of Doors: " << doorsNumber << endl;
        return;
    }
};

class BuilderEngine
{
protected:
	Engine * engine;

public:
	void newEngine()
	{
		engine = new Engine();
	}

	Engine* getEngine()
	{
		return engine;
	}

	virtual void buildEngineMain()=0;
	virtual void buildFuelType()=0;
	virtual void buildEngineCapacity()=0;
};

class BuilderCar
{
protected:
    Car * car;

public:
    void newCar(Engine* e)
    {
        car = new Car(e);
    }

    Car getCar()
    {
        return* car;
    }

    virtual void buildWheelSize()=0;
    virtual void buildColor()=0;
    virtual void buildDoorsNumber()=0;
    virtual void buildType()=0;
    virtual void buildBrand()=0;
    virtual void buildModel()=0;
};

class EngineV8:public BuilderEngine
{
public :

	EngineV8():BuilderEngine(){}

    void buildEngineMain()
    {
        int choose;
        cout << "[1] V8" << endl;
        cout << "[2] V8 Turbo " << endl;
        cout << "[3] V8 BiTurbo" << endl;
        cout << "[4] V8 QuadTurbo" << endl << endl;
        cout << "Which type of engine do you prefer?" << endl;
        cout << "My choose: ";
        cin >> choose;

        switch(choose)
        {
        case 1:
            engine->setEngineType("V8");
            engine->setHorsepower(240);
            engine->setTorque(310);
            break;
        case 2:
            engine->setEngineType("V8 Turbo");
            engine->setHorsepower(300);
            engine->setTorque(410);
            break;
        case 3:
            engine->setEngineType("V8 BiTurbo");
            engine->setHorsepower(380);
            engine->setTorque(500);
            break;
        case 4:
            engine->setEngineType("V8 QuadTurbo");
            engine->setHorsepower(600);
            engine->setTorque(800);
            break;
        }
    }

	void buildFuelType()
	{
	    int choose;
	    cout << endl << "[1] Gasoline" << endl;
	    cout << "[2] Hybrid" << endl;
	    cout << "[3] Diesel" << endl;
	    cout << "[4] Gasoline + LPG" << endl;
	    cout << "Which Fuel Type do you prefer?" << endl;
	    cout << "My choose: ";
	    cin >> choose;

	    switch(choose)
	    {
        case 1:
            engine->setFuelType("Gasoline");
            break;
        case 2:
            engine->setFuelType("Hybrid");
            break;
        case 3:
            engine->setFuelType("Diesel");
            break;
        case 4:
            engine->setFuelType("Gasoline + LPG");
            break;
	    }

	}

	void buildEngineCapacity()
	{
	    int choose;
	    cout << endl << "[1] 3.6" << endl;
	    cout << "[2] 4.2" << endl;
	    cout << "[3] 5.0" << endl;
	    cout << "[4] 5.7" << endl;
	    cout << "What size of engine do you want?" << endl;
	    cout << "My choose: ";
	    cin >> choose;

	    switch(choose)
	    {
        case 1:
            engine->setEngineCapacity(3.6);
            break;
        case 2:
            engine->setEngineCapacity(4.2);
            break;
        case 3:
            engine->setEngineCapacity(5.0);
            break;
        case 4:
            engine->setEngineCapacity(5.7);
            break;
	    }
	}
};

class BMW:public BuilderCar
{
public:

	BMW():BuilderCar(){}

    void buildWheelSize()
    {
        car->setWheelSize(20);
    }

    void buildColor()
    {
        car->setColor("black-pink");
    }

    void buildDoorsNumber()
    {
        car->setDoorsNumber(3);
    }

    void buildType()
    {
        car->setType("coupe");
    }

    void buildBrand()
    {
        car->setBrand("BMW");
    }

    void buildModel()
    {
        car->setModel("M5");
    }
};

class Director
{
private:
	BuilderEngine* builderEngine;
	BuilderCar* builderCar;

public:
    void setBuilder(BuilderEngine* be, BuilderCar* bc)
    {
        builderEngine = be;
        builderCar = bc;
    }

    Car getCar()
    {
        return builderCar->getCar();
    }

    void prepare()
    {
        builderEngine->newEngine();
        builderEngine->buildEngineMain();
        builderEngine->buildFuelType();
        builderEngine->buildEngineCapacity();
        builderCar->newCar(builderEngine->getEngine());
        builderCar->buildBrand();
        builderCar->buildColor();
        builderCar->buildDoorsNumber();
        builderCar->buildModel();
        builderCar->buildType();
        builderCar->buildWheelSize();
    }
};

int main()
{
	Director* director = new  Director();


	BuilderEngine* engine001 = new EngineV8();
    BuilderCar* car001 = new BMW();

    director->setBuilder(engine001, car001);
    system("cls");
    cout << "ZESTAW 1" << endl;
    director->prepare();
    Car fcar001 = director->getCar();

    system("cls");
    cout << "\n\nZESTAW 1\n\n";
	fcar001.showCar();

    return 0;
}
