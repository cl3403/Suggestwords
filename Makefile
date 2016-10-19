OPTS = -g -Wall -std=c++11

suggestwords: suggestwords.cc
	g++ ${OPTS} -o suggestwords suggestwords.cc


