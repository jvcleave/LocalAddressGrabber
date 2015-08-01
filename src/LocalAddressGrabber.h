/*
 *  LocalAddressGrabber.h
 *  converted from http://lists.apple.com/archives/darwin-dev/2004/Nov/msg00137.html
 *
 *  Created by jason van cleave on 11/29/11.
 *  Copyright 2011 jasonvancleave.com. All rights reserved.
 *
 */

#include "ofMain.h"


#include <arpa/inet.h>
#include <net/if.h>
#include <ifaddrs.h>

class LocalAddressGrabber
{
public:

	static vector<string>& availableList(void){
		struct ifaddrs *myaddrs;
		struct ifaddrs *ifa;
		struct sockaddr_in *s4;
		int status;
		
		char buf[64];

		vector<string> interfaces;
		
		status = getifaddrs(&myaddrs);
		if (status != 0)
		{
			perror("getifaddrs");
			
		}
		
		for (ifa = myaddrs; ifa != NULL; ifa = ifa->ifa_next)
		{
			if (ifa->ifa_addr == NULL) continue;
			if ((ifa->ifa_flags & IFF_UP) == 0) continue;
			
			if (ifa->ifa_addr->sa_family == AF_INET)
			{
				s4 = (struct sockaddr_in *)(ifa->ifa_addr);
				if (inet_ntop(ifa->ifa_addr->sa_family, (void *)&(s4->sin_addr), buf, sizeof(buf)) == NULL)
				{
					printf("%s: inet_ntop failed!\n", ifa->ifa_name);
				}
				else
				{
					ofLogNotice() << ifa -> ifa_name;
					interfaces.push_back(ifa -> ifa_name);
					
				}
			}
		}
		
		freeifaddrs(myaddrs);

	}

	static string getIpAddress(const string& interface)
	{
		string output = "NOT FOUND";
		struct ifaddrs *myaddrs;
		struct ifaddrs *ifa;
		struct sockaddr_in *s4;
		int status;
		
		char buf[64];
		
		status = getifaddrs(&myaddrs);
		if (status != 0)
		{
			perror("getifaddrs");
			
		}
		
		for (ifa = myaddrs; ifa != NULL; ifa = ifa->ifa_next)
		{
			if (ifa->ifa_addr == NULL) continue;
			if ((ifa->ifa_flags & IFF_UP) == 0) continue;
			
			if (ifa->ifa_addr->sa_family == AF_INET)
			{
				s4 = (struct sockaddr_in *)(ifa->ifa_addr);
				if (inet_ntop(ifa->ifa_addr->sa_family, (void *)&(s4->sin_addr), buf, sizeof(buf)) == NULL)
				{
					printf("%s: inet_ntop failed!\n", ifa->ifa_name);
				}
				else
				{
					if(ofToString(ifa->ifa_name) == interface)
					{
						freeifaddrs(myaddrs);
						return ofToString(buf);
					}
				}
			}
		}

		ofLogWarning() << output;	
		freeifaddrs(myaddrs);
		return output;
	}
};
