#include <iostream>

class Liquor;
class Tobacco;
class Necessity;

class Visitor {

public:

	virtual double visit(Liquor* aLiquorItem) = 0;
	virtual double visit(Tobacco* aTobaccoItem) = 0;
	virtual double visit(Necessity* aNecessityItem) = 0;

};

class Visitable {

public:

	virtual double accept(Visitor& aVisitor) = 0;

};

class Item {

private:

	double m_price;

public:
	Item(double aPrice)
	{

		m_price = aPrice;

	}

	double price() {

		return m_price;

	};

};

class Liquor : public Item, public Visitable {

public:
	Liquor(double aPrice) : Item(aPrice) {}

	double accept(Visitor& aVisitor)
	{
		return aVisitor.visit(this);
	}

};

class Necessity : public Item, public Visitable {

public:
	Necessity(double aPrice) : Item(aPrice) {}

	double accept(Visitor& aVisitor)
	{
		return aVisitor.visit(this);
	}

};

class Tobacco : public Item, public Visitable {

public:
	Tobacco(double aPrice) : Item(aPrice) {}

	double accept(Visitor& aVisitor)
	{
		return aVisitor.visit(this);
	}

};

class TaxVisitor : public Visitor {

public:

	virtual double visit(Liquor* aLiquorItem)
	{
		std::cout << "Liquor item price with tax" << std::endl;
		return aLiquorItem->price() * 1.18;
	};

	virtual double visit(Tobacco* aTobaccoItem)
	{
		std::cout << "Tobacco item price with tax" << std::endl;
		return aTobaccoItem->price() * 1.32;
	};
	
	virtual double visit(Necessity* aNecessityItem) {
		std::cout << "Necessity item price with tax" << std::endl;
		return aNecessityItem->price() * 1.0;
	};

};

class HolidayTaxVisitor : public Visitor {

public:

	virtual double visit(Liquor* aLiquorItem)
	{
		std::cout << "Liquor item price with holiday tax" << std::endl;
		return aLiquorItem->price() * 1.08;
	};

	virtual double visit(Tobacco* aTobaccoItem)
	{
		std::cout << "Tobacco item price with holiday tax" << std::endl;
		return aTobaccoItem->price() * 1.15;
	};

	virtual double visit(Necessity* aNecessityItem) {
		std::cout << "Necessity item price with holiday tax" << std::endl;
		return aNecessityItem->price() * 1.0;
	};

};

void main()
{

	TaxVisitor aTaxVisitor;
	HolidayTaxVisitor aHolidayTaxVisitor;

	Necessity milk(3.47);
	Tobacco cigars(5.00);
	Liquor vodka(12.00);

	std::cout << milk.accept(aTaxVisitor) << std::endl;
	std::cout << cigars.accept(aTaxVisitor) << std::endl;
	std::cout << vodka.accept(aTaxVisitor) << std::endl;

	std::cout << milk.accept(aHolidayTaxVisitor) << std::endl;
	std::cout << cigars.accept(aHolidayTaxVisitor) << std::endl;
	std::cout << vodka.accept(aHolidayTaxVisitor) << std::endl;

	system("pause");

}