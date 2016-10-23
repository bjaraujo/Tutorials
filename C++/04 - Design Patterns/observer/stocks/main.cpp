
#include <vector>
#include <iostream>

class Observer
{
protected:

	int m_observerId;

public:

	virtual void update(double ibmPrice, double applPrice, double googPrice) = 0;

	int id() 
	{
		return m_observerId;
	}

};

class Subject {

public:

	virtual void subscribe(Observer* anObserver) = 0;
	virtual void unsubscribe(Observer* anObserver) = 0;
	virtual void notify() = 0;

};

class StockGrabber : public Subject {

private:

	double m_ibmPrice;
	double m_applPrice;
	double m_googPrice;

	std::vector<Observer*> m_observers;

public:

	virtual void subscribe(Observer* anObserver) 
	{

		std::cout << "-- SUBSCRIBE OBSERVER " << anObserver->id() << " --" << std::endl;

		m_observers.push_back(anObserver);
	
	}

	void unsubscribe(Observer* anObserver) 
	{

		std::cout << "-- OBSERVER DELETED " << anObserver->id() << " --" << std::endl;

		m_observers.erase(std::find(m_observers.begin(), m_observers.end(), anObserver));

	}
	
	void notify() 
	{

		for (size_t i = 0; i < m_observers.size(); i++)
		{
			std::cout << "-- NOTIFY OBSERVER " << m_observers[i]->id() << " --" << std::endl;

			m_observers[i]->update(m_ibmPrice, m_applPrice, m_googPrice);
		}

	};

	void setIbmPrice(double newIbmPrice)
	{
		m_ibmPrice = newIbmPrice;
		this->notify();
	}

	void setApplPrice(double newApplrice)
	{
		m_applPrice = newApplrice;
		this->notify();
	}

	void setGoogPrice(double newGoogPrice)
	{
		m_googPrice = newGoogPrice;
		this->notify();
	}

};

class StockObserver : public Observer {

private:

	double m_ibmPrice;
	double m_applPrice;
	double m_googPrice;

	StockGrabber* m_stockGrabber;

	static int m_observerIdTracker;

public:

	StockObserver(StockGrabber* aStockGrabber)
	{
		m_stockGrabber = aStockGrabber;
		m_observerId = m_observerIdTracker++;

		std::cout << "-- OBSERVER CREATED " << m_observerId << " --" << std::endl;

		m_stockGrabber->subscribe(this);

	}

	static void Init()
	{

		m_observerIdTracker = 0;

	}

	void update(double ibmPrice, double applPrice, double googPrice)
	{
		m_ibmPrice = ibmPrice;
		m_applPrice = applPrice;
		m_googPrice = googPrice;

		std::cout << "-- OBSERVER NOTIFIED " << m_observerId << " --" << std::endl;
		std::cout << "Prices: " << std::endl;
		std::cout << "IBM: " << ibmPrice << std::endl;
		std::cout << "APPLE: " << applPrice << std::endl;
		std::cout << "GOOGLE: " << googPrice << std::endl;

	}

};

int StockObserver::m_observerIdTracker;

void main()
{

	StockObserver::Init();

	StockGrabber aStockGrabber;

	StockObserver aStockObserver1(&aStockGrabber);

	aStockGrabber.setIbmPrice(95);
	aStockGrabber.setApplPrice(301);
	aStockGrabber.setGoogPrice(1221);

	StockObserver aStockObserver2(&aStockGrabber);

	aStockGrabber.setIbmPrice(98);
	aStockGrabber.setApplPrice(280);
	aStockGrabber.setGoogPrice(1403);

	aStockGrabber.unsubscribe(&aStockObserver1);

	aStockGrabber.setIbmPrice(102);
	aStockGrabber.setApplPrice(300);
	aStockGrabber.setGoogPrice(1100);

	system("pause");

}