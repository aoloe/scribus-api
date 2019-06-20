#include "document.h"
#include "item.h"

#include "scribuscore.h"
#include "scribusdoc.h"
#include "selection.h"
#include "styles/styleset.h"
#include "styles/charstyle.h"

namespace API {

// TODO: compiles but produces a symbold not found error at run time
std::shared_ptr<Document> Document::getActive()
{
	// ScCore is a global variable created in main_*.cpp
	ScribusDoc* currDoc = ScCore->primaryMainWindow()->doc;
	if (currDoc == nullptr) {
		return {};
	}
	return std::make_shared<Document>(currDoc);
}

std::shared_ptr<Item> Document::getActiveItem()
{
    if (scribusDoc->m_Selection->count() != 1)
        return {};

    auto item = Item(scribusDoc->m_Selection->itemAt(0));

    // item->setPageNumber(pageNumber); TODO: find out the page number

    return std::make_shared<Item>(item);
}

std::vector<std::string> Document::getCharacterStyleNames()
{
    std::vector<std::string> result{};

    const StyleSet<CharStyle>* charStyles = & scribusDoc->charStyles();
    int n = charStyles->count();
    for (int i = 0; i < n; ++i )
    {
        const auto charStyle = (*charStyles)[i];
        result.push_back(charStyle.name().toStdString());
    }

    return result;
}

std::vector<std::string> Document::getParagraphStyleNames()
{
    std::vector<std::string> result{};

    const StyleSet<ParagraphStyle>* paragraphStyles = & scribusDoc->paragraphStyles();
    int n = paragraphStyles->count();
    for (int i = 0; i < n; ++i )
    {
        const ParagraphStyle paragraphStyle = (*paragraphStyles)[i];
        result.push_back(paragraphStyle.name().toStdString());
    }

    return result;
}

} // namespace
