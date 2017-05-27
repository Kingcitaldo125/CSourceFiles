// Using c++11

#include <iostream>
#include <vector>
#include <ctime>
#include <typeinfo>

using namespace std;

class CronJob
{
	enum class state
	{RUNNING,WAITING};
public: 
	CronJob(bool rep);
	~CronJob();
	void activate();
	void deactivate();
	
	// The order to execute and when to execute it
	void addJob(string j, unsigned int h, unsigned int min, unsigned int sec);
private:
	bool repeat;
	bool running;
	unsigned int hour;
	unsigned int minute;
	unsigned int second;
	struct tm* getSystemTime();
	vector<string> jobs;
};

CronJob::CronJob(bool rep)
{
	repeat = rep;
	running = false;
}

CronJob::~CronJob()
{
	
}

struct tm* CronJob::getSystemTime()
{
	time_t t = time(0);
	struct tm* timeNow = localtime(&t);
	
	return timeNow;
}

void CronJob::activate()
{
	if(jobs.size() == 0)
	{
		cout << "No cron jobs to execute." << endl;
		return;
	}
	running = true;
	while(running)
	{
		struct tm* tt = getSystemTime();
		int nour;
		if(tt->tm_hour > 12)
		{
			nour = (tt->tm_hour - 12); // convert to 12 hour clock.
			if(nour == hour && tt->tm_min == minute && tt->tm_sec == second)
			{
				cout << jobs.at(0) << endl;
				deactivate();
			}
			
		}
		else
		{
			if(tt->tm_hour == hour)
			{
				cout << jobs.at(0) << endl;
				deactivate();
			}
		}
	}
}

void CronJob::deactivate()
{
	running = false;
	if(repeat)
		running = true;
}

void CronJob::addJob(string j, unsigned int h, unsigned int min, unsigned int sec)
{
	if(jobs.size() < 1)
	{
		hour = h;
		minute = min;
		second = sec;
		jobs.push_back(j);
	}
}

int main()
{
	CronJob cj(false);
	
	//ifstream iff;
	
	cj.addJob("Things.\n", 5, 50, 5);
	cj.activate();
	
	return 0;
}