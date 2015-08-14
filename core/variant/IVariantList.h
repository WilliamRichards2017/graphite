#ifndef GRAPHITE_IVARIANTLIST_H
#define GRAPHITE_IVARIANTLIST_H

#include <boost/noncopyable.hpp>

#include "core/region/Region.h"
#include "IVariant.h"

#include <vector>
#include <algorithm>
#include <iostream>

namespace graphite
{
	/* class IVariant; */
	/*
	 * An iterface for variant readers. Provides a very sparse
	 * framework for a variant reader. This will allow flexibility
	 * for all file types and implementations.
	 */
	class IVariantList : private boost::noncopyable
	{
	public:
		typedef std::shared_ptr< IVariantList > SharedPtr;
		IVariantList(){}
		virtual ~IVariantList() {}

		virtual bool getNextVariant(IVariant::SharedPtr& variantPtr) = 0;
		virtual size_t getCount() = 0;
		virtual void sort() = 0;
		virtual void printToVCF(std::ostream& out) = 0;
	};

} // end namespace graphite

#endif //GRAPHITE_IVARIANTLIST_H
