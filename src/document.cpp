#include "document.h"
#include "item.h"

#include "scribuscore.h"
#include "scribusdoc.h"
#include "selection.h"

namespace API {

std::shared_ptr<Document> Document::getActive()
{
	// ScCore is a global variable created in main_*.cpp
	ScribusDoc* currDoc = ScCore->primaryMainWindow()->doc;
	if (currDoc == nullptr) {
		return {};
	}
	return std::make_shared<Document>(currDoc);
}

nonstd::optional<Item> Document::getActiveItem()
{
	if (!isOpen())
		return {};

    if (scribusDoc->m_Selection->count() != 1)
        return {};

    auto item = Item(scribusDoc->m_Selection->itemAt(0));

    // item->setPageNumber(pageNumber); TODO: find out the page number

    return {item};
}

} // namespace
