#ifndef GRAPHITE_SEQUENCE_H
#define GRAPHITE_SEQUENCE_H

#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include "core/util/Noncopyable.hpp"

namespace graphite
{
	class Sequence : private Noncopyable
	{
	public:
		typedef std::shared_ptr< Sequence > SharedPtr;

	    Sequence(const std::string& seq) :
		    m_seq(seq)
		{
		}

		~Sequence(){}

		const char* getSequence() const { return m_seq.c_str(); }
		size_t getLength() const { return m_seq.size(); }

		std::string getSequenceString() const { return m_seq; }
	private:
		std::string m_seq;
	};
}

#endif //GRAPHITE_SEQUENCE_H
