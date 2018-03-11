#ifndef OBSERVERMANAGER_H
#define OBSERVERMANAGER_H

#include <algorithm>
#include <set>
#include <functional>

template<class OBSERVER, class EVENT>
class ObserverManager
{
	typedef std::set<OBSERVER*> ObserverSet;
public:
	void add(OBSERVER* observer)
	{
		observers.insert(observer);
	}

	void remove(OBSERVER* observer)
	{
		typename ObserverSet::iterator it = observers.find(observer);
		if(it != observers.end())
		{
			observers.erase(it);
		}
	}

	typedef void (OBSERVER::*EventHandler)(EVENT eventObject);
	void notify(EventHandler handler, EVENT eventObject)
	{
        // alle OBSERVER informieren
		std::for_each(observers.begin(), observers.end(), 
			std::bind2nd(std::mem_fun(handler), eventObject));
	}

private:
	ObserverSet observers;
};

#endif //OBSERVERMANAGER_H
