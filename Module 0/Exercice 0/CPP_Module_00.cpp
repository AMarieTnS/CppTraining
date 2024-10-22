#include <iostream>
#include <algorithm> 
using namespace std;

int main(int argc, char* argv[])
{
    string sLowSentence("");
    string sHighSentence("");

	if(argc > 1)
	{
    	for (int i = 1; i < argc; ++i) 
		{
      		sLowSentence += argv[i];
      	   	if (i < argc - 1) 
			{
       	       sLowSentence += " ";
       	   	}
      	}
    	sHighSentence.resize(sLowSentence.size());

    	transform(sLowSentence.begin(), sLowSentence.end(), sHighSentence.begin(), ::toupper);
	}
	else
	{
		sHighSentence = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
    cout << sHighSentence;
    return 0;
}
