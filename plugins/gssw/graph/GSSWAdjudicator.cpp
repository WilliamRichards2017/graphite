#include "GSSWAdjudicator.h"
#include "GSSWGraph.h"
#include "core/variants/VariantList.h"

namespace gwiz
{
namespace gssw
{
	GSSWAdjudicator::GSSWAdjudicator()
	{
	}

	GSSWAdjudicator::~GSSWAdjudicator()
	{
	}

	IVariantList::SharedPtr GSSWAdjudicator::adjudicateGraph(IGraph::SharedPtr graphPtr, IAlignmentReader::SharedPtr alignmentsReaderPtr)
	{
		auto variantList = std::make_shared< VariantList >();
		auto gsswGraphPtr = std::dynamic_pointer_cast< GSSWGraph >(graphPtr);
		if (graphPtr) // kind of punting for now. in the future this should be updated so it handles all igraphs the same
		{
			IAlignment::SharedPtr alignmentPtr;
			while (alignmentsReaderPtr->getNextAlignment(alignmentPtr))
			{
				auto graphMappingPtr = gsswGraphPtr->traceBackAlignment(alignmentPtr);
				gssw_node_cigar* nc = graphMappingPtr->cigar.elements;
				for (int i = 0; i < graphMappingPtr->cigar.length; ++i, ++nc)
				{
					auto variantPtr = gsswGraphPtr->getVariantFromNodeID(nc->node->id);
					if (variantPtr != nullptr)
					{
						// std::cout << "seq: " << nc->node->seq << std::endl;
						variantPtr->increaseCount(std::string(nc->node->seq, nc->node->len));
						variantList->addVariant(variantPtr);
					}
				}
			}
		}
		else
		{
			throw "adjudicateGraph has not been implemented for non-GSSWGraphs";
		}
		return variantList;
	}
}
}
