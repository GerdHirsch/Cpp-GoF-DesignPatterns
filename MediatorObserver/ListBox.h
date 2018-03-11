#ifndef LISTBOX_H
#define LISTBOX_H

#include <algorithm>
#include <set>
#include <functional>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "Event.h"

class ListBox;

class ListBoxEvent : public Event<ListBox>
{
public:
	ListBoxEvent(ListBox* listBox) : Event(listBox)	{}
};

class ListBoxListener
{
public:
	virtual void onItemSelected(ListBoxEvent listBoxEvent) = 0;
};

class ListBox
{
	typedef std::set<ListBoxListener*> ObserverSet;

public:
	ListBox() : selectedIndex(0)
	{
		std::string itemPrefix("item ");
		std::ostringstream oss;
		for(int i = 0; i < 11; ++i)
		{			
			oss.str("");
			oss << itemPrefix << i;
			items.push_back(oss.str());
		}
	}

	void simulateItemSelected(int itemIndex)
	{
		selectedIndex = itemIndex;
		ListBoxEvent listBoxEvent(this);
		// alle OBSERVER informieren
		std::for_each(observers.begin(), observers.end(), 
			std::bind2nd(std::mem_fun(&ListBoxListener::onItemSelected), listBoxEvent));		
	}

	const std::string& getSelectedItem()
	{
		return items[selectedIndex];
	}

	void addItemSelectedListener(ListBoxListener* observer)
	{
		observers.insert(observer);
	}
	void removeItemSelectedListener(ListBoxListener* observer)
	{
		ObserverSet::iterator it = observers.find(observer);
		if(it != observers.end())
		{
			observers.erase(it);
		}
	}
private:
	ObserverSet observers;
	int selectedIndex;
	std::vector<std::string> items;
};

#endif //LISTBOX_H