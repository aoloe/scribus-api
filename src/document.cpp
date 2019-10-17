#include "document.h"
#include "item.h"

#include "scribuscore.h"
#include "scribusdoc.h"
#include "selection.h"
#include "styles/styleset.h"
#include "styles/charstyle.h"
#include "styles/paragraphstyle.h"
// #include "ui/stylemanager.h"

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

const std::string Document::getDefaultCharacterStyleName() const
{
	return scribusDoc->charStyles().getDefault()->name().toStdString();
}

const std::vector<std::string> Document::getCharacterStyleNames() const
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

const std::string Document::getDefaultParagraphStyleName() const
{
	return scribusDoc->paragraphStyles().getDefault()->name().toStdString();
}

const std::vector<std::string> Document::getParagraphStyleNames() const
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

void Document::createCharacterStyle(std::string name)
{
	CharStyle characterStyle;
	characterStyle.setName(QString::fromStdString(name));
	StyleSet<CharStyle> styleSet;
	styleSet.create(characterStyle);
	scribusDoc->redefineCharStyles(styleSet, false);
	// TODO: find out if it is necessary / makes sense to update the style manager
	// afaict, the style manager is now updated, but not the text palette
	// ScCore->primaryMainWindow()->styleMgr()->setDoc(scribusDoc);
}

void Document::createParagraphStyle(std::string name)
{
	ParagraphStyle paragraphStyle;
	paragraphStyle.setName(QString::fromStdString(name));
	StyleSet<ParagraphStyle> styleSet;
	styleSet.create(paragraphStyle);
	scribusDoc->redefineStyles(styleSet, false);
	// TODO: find out if it is necessary / makes sense to update the style manager
	// afaict, the style manager is now updated, but not the text palette
	// ScCore->primaryMainWindow()->styleMgr()->setDoc(scribusDoc);
}

} // namespace
