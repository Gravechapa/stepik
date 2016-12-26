#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main()
{
    std::map<int, int> map;
    std::string buffer;
    std::cin >> buffer;
    std::string buff;
    std::string buff1;
    int count;
    int power;
    for (int i = 0; i < buffer.size(); i++)
        {
            if (buffer[i] == '-')
                {
                    i++;
                    if (buffer[i] == 'x')
                        {
                            if (buffer.size() != i+1)
                                {
                                    if (buffer[i+1] == '^')
                                        {
                                            i += 2;
                                            buff1 = buffer[i];
                                            if (buffer.size() != i+1)
                                                while((buffer[i+1] >= '0')&&(buffer[i+1] <= '9'))
                                                    {
                                                        i++;
                                                        buff1 += buffer[i];
                                                        if (buffer.size() == i+1)
                                                            break;
                                                    }
                                            std::stringstream convert(buff1);
                                            convert >> power;
                                            count = -power--;
                                            std::map<int, int>::iterator  it= map.find(power);
                                            if( it != map.end() )
                                                it->second += count;
                                            else
                                                map.insert ( std::pair<int, int>(power, count) );
                                            continue;

                                        }
                                    else
                                        {

                                            power = 0;
                                            count = -1;
                                            std::map<int, int>::iterator  it= map.find(power);
                                            if( it != map.end() )
                                                it->second += count;
                                            else
                                                map.insert ( std::pair<int, int>(power, count) );
                                            continue;
                                        }
                                }
                            else
                               {   
									power = 0;
                                    count = -1; 
                                    std::map<int, int>::iterator  it= map.find(power);
                                    if( it != map.end() )
                                    	it->second += count;
                                    else
                                        map.insert ( std::pair<int, int>(power, count) );
                                    break;
                              }
                        }
                buff = buffer[i-1];
				buff += buffer[i];
                if (buffer.size() != i+1)
                	while((buffer[i+1] >= '0')&&(buffer[i+1] <= '9'))
                    	{   
                       		i++;
                            buff += buffer[i];
                            if (buffer.size() == i+1)
                            	break;
                        }
				std::stringstream convert(buff);
				convert >> count;
				if (buffer.size() != i+1)
					{
						if (buffer[i+1] == '*')
							{
								i += 2;
								if (buffer.size() != i+1)
                                	{
                                    	if (buffer[i+1] == '^')
                                        	{
                                            	i += 2;
                                            	buff1 = buffer[i];
                                           		if (buffer.size() != i+1)
                                                	while((buffer[i+1] >= '0')&&(buffer[i+1] <= '9'))
                                                    	{
                                                        	i++;
                                                        	buff1 += buffer[i];
                                                        	if (buffer.size() == i+1)
                                                            	break;
                                                    	}
                                            	std::stringstream convert(buff1);
                                            	convert >> power;
                                            	count *= power--;
                                            	std::map<int, int>::iterator  it= map.find(power);
                                            	if( it != map.end() )
                                                	it->second += count;
                                            	else
                                                	map.insert ( std::pair<int, int>(power, count) );
                                            	continue;

                                        	}
                                    	else
                                        	{
												power = 0;
                                            	std::map<int, int>::iterator  it= map.find(power);
                                            	if( it != map.end() )
                                                	it->second += count;
                                            	else
                                                	map.insert ( std::pair<int, int>(power, count) );
                                           		continue;
                                        	}
                                		}
                            		else
                               			{
                                    		power = 0;
                                    		std::map<int, int>::iterator  it= map.find(power);
                                    		if( it != map.end() )
                                        		it->second += count;
                                    		else
											map.insert ( std::pair<int, int>(power, count) );
                                    		break;
                              			}
                        		}
						else 
							continue;
							
					}
				else
					break;
                }
//////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (buffer[i] == '+')
                {
                    i++;
                    if (buffer[i] == 'x')
                        {
                            if (buffer.size() != i+1)
                                {
                                    if (buffer[i+1] == '^')
                                        {
                                            i += 2;
                                            buff1 = buffer[i];
                                            if (buffer.size() != i+1)
                                                while((buffer[i+1] >= '0')&&(buffer[i+1] <= '9'))
                                                    {
                                                        i++;
                                                        buff1 += buffer[i];
                                                        if (buffer.size() == i+1)
                                                            break;
                                                    }
                                            std::stringstream convert(buff1);
                                            convert >> power;
                                            count = power--;
                                            std::map<int, int>::iterator  it= map.find(power);
                                            if( it != map.end() )
                                                it->second += count;
                                            else
                                                map.insert ( std::pair<int, int>(power, count) );
                                            continue;

                                        }
                                    else
                                        {

                                            power = 0;
                                            count = 1;
                                            std::map<int, int>::iterator  it= map.find(power);
                                            if( it != map.end() )
                                                it->second += count;
                                            else
                                                map.insert ( std::pair<int, int>(power, count) );
                                            continue;
                                        }
                                }
                            else
                               {   
									power = 0;
                                    count = 1; 
                                    std::map<int, int>::iterator  it= map.find(power);
                                    if( it != map.end() )
                                    	it->second += count;
                                    else
                                        map.insert ( std::pair<int, int>(power, count) );
                                    break;
                              }
                        }
				buff = buffer[i];
                if (buffer.size() != i+1)
                	while((buffer[i+1] >= '0')&&(buffer[i+1] <= '9'))
                    	{   
                       		i++;
                            buff += buffer[i];
                            if (buffer.size() == i+1)
                            	break;
                        }
				std::stringstream convert(buff);
				convert >> count;
				if (buffer.size() != i+1)
					{
						if (buffer[i+1] == '*')
							{
								i += 2;
								if (buffer.size() != i+1)
                                	{
                                    	if (buffer[i+1] == '^')
                                        	{
                                            	i += 2;
                                            	buff1 = buffer[i];
                                           		if (buffer.size() != i+1)
                                                	while((buffer[i+1] >= '0')&&(buffer[i+1] <= '9'))
                                                    	{
                                                        	i++;
                                                        	buff1 += buffer[i];
                                                        	if (buffer.size() == i+1)
                                                            	break;
                                                    	}
                                            	std::stringstream convert(buff1);
                                            	convert >> power;
                                            	count *= power--;
                                            	std::map<int, int>::iterator  it= map.find(power);
                                            	if( it != map.end() )
                                                	it->second += count;
                                            	else
                                                	map.insert ( std::pair<int, int>(power, count) );
                                            	continue;

                                        	}
                                    	else
                                        	{
												power = 0;
                                            	std::map<int, int>::iterator  it= map.find(power);
                                            	if( it != map.end() )
                                                	it->second += count;
                                            	else
                                                	map.insert ( std::pair<int, int>(power, count) );
                                           		continue;
                                        	}
                                		}
                            		else
                               			{
                                    		power = 0;
                                    		std::map<int, int>::iterator  it= map.find(power);
                                    		if( it != map.end() )
                                        		it->second += count;
                                    		else
											map.insert ( std::pair<int, int>(power, count) );
                                    		break;
                              			}
                        		}
						else 
							continue;
							
					}
				else
					break;
                }
///////////////////////////////////////////////////////////////////////////////////////////////////////	
			         if (buffer[i] == 'x')
                        {
                            if (buffer.size() != i+1)
                                {
                                    if (buffer[i+1] == '^')
                                        {
                                            i += 2;
                                            buff1 = buffer[i];
                                            if (buffer.size() != i+1)
                                                while((buffer[i+1] >= '0')&&(buffer[i+1] <= '9'))
                                                    {
                                                        i++;
                                                        buff1 += buffer[i];
                                                        if (buffer.size() == i+1)
                                                            break;
                                                    }
                                            std::stringstream convert(buff1);
                                            convert >> power;
                                            count = power--;
                                            std::map<int, int>::iterator  it= map.find(power);
                                            if( it != map.end() )
                                                it->second += count;
                                            else
                                                map.insert ( std::pair<int, int>(power, count) );
                                            continue;

                                        }
                                    else
                                        {

                                            power = 0;
                                            count = 1;
                                            std::map<int, int>::iterator  it= map.find(power);
                                            if( it != map.end() )
                                                it->second += count;
                                            else
                                                map.insert ( std::pair<int, int>(power, count) );
                                            continue;
                                        }
                                }
                            else
                               {   
									power = 0;
                                    count = 1; 
                                    std::map<int, int>::iterator  it= map.find(power);
                                    if( it != map.end() )
                                    	it->second += count;
                                    else
                                        map.insert ( std::pair<int, int>(power, count) );
                                    break;
                              }
                        }
				buff = buffer[i];
                if (buffer.size() != i+1)
                	while((buffer[i+1] >= '0')&&(buffer[i+1] <= '9'))
                    	{   
                       		i++;
                            buff += buffer[i];
                            if (buffer.size() == i+1)
                            	break;
                        }
				std::stringstream convert(buff);
				convert >> count;
				if (buffer.size() != i+1)
					{
						if (buffer[i+1] == '*')
							{
								i += 2;
								if (buffer.size() != i+1)
                                	{
                                    	if (buffer[i+1] == '^')
                                        	{
                                            	i += 2;
                                            	buff1 = buffer[i];
                                           		if (buffer.size() != i+1)
                                                	while((buffer[i+1] >= '0')&&(buffer[i+1] <= '9'))
                                                    	{
                                                        	i++;
                                                        	buff1 += buffer[i];
                                                        	if (buffer.size() == i+1)
                                                            	break;
                                                    	}
                                            	std::stringstream convert(buff1);
                                            	convert >> power;
                                            	count *= power--;
                                            	std::map<int, int>::iterator  it= map.find(power);
                                            	if( it != map.end() )
                                                	it->second += count;
                                            	else
                                                	map.insert ( std::pair<int, int>(power, count) );
                                            	continue;

                                        	}
                                    	else
                                        	{
												power = 0;
                                            	std::map<int, int>::iterator  it= map.find(power);
                                            	if( it != map.end() )
                                                	it->second += count;
                                            	else
                                                	map.insert ( std::pair<int, int>(power, count) );
                                           		continue;
                                        	}
                                		}
                            		else
                               			{
                                    		power = 0;
                                    		std::map<int, int>::iterator  it= map.find(power);
                                    		if( it != map.end() )
                                        		it->second += count;
                                    		else
											map.insert ( std::pair<int, int>(power, count) );
                                    		break;
                              			}
                        		}
						else 
							continue;
							
					}
				else
					break;
        }
    std::string output = "";
    std::stringstream convert;
    int kostil = 0;
	for (auto it=map.rbegin(); it!=map.rend(); ++it)
        {
            if ((kostil == 1)&&(it->second >= 0))
                output += '+';
            kostil = 1;
            if (it->second == 0)
                continue;
            if (it->first == 0)
                {   
                    convert.str("");
                    convert.clear();
                    convert << it->second;
                    output += convert.str();
                    continue;
                }
            if (it->first == 1)
                {
                    if (it->second == 1)
                        {
                            output += 'x';
                            continue;
                        }
                    if (it->second == -1)
                        {
                            output += "-x";
                            continue;
                        }
                    convert.str("");
                    convert.clear();
                    convert << it->second;
                    output += convert.str() + "*x";
                    continue;
                }
            convert.str("");
            convert.clear();
            convert << it->second;
            output += convert.str() + "*x^";
            convert.str("");
            convert.clear();
            convert << it->first;
            output += convert.str();
        }
    std::cout << output << std::endl;
	return 0;
}
