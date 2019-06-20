#include "item.h"
#include "textframe.h"

#include "scribusdoc.h"
#include "styles/paragraphstyle.h"

namespace API {

TextFrame::TextFrame(std::shared_ptr<Item> item) :
	item{item}
{
}

std::shared_ptr<TextFrame> TextFrame::getFromItem(std::shared_ptr<Item> item)
{
	if (item->isTextFrame())
		return std::make_shared<TextFrame>(item);
	else
		return {};
}

/*
 * @todo:
 * - apply the style depending on the "type" of the current selection:
 *   - to the whole frame if a frame is selected
 *   - to the whole paragraphs in the selection if there is a selection
 *   - to the whole current paragraph if there is no selection but the cursor is in edit mode.
 *   - have a look at `void ScribusDoc::itemSelection_SetNamedCharStyle(const QString& name, Selection* customSelection)`
 */
void TextFrame::applyCharacterStyle(std::string styleName)
{
	CharStyle style;
	style.setParent(QString::fromStdString(styleName));
	item->getScribusItem()->doc()->itemSelection_ApplyCharStyle(style);

}

/**
 * @todo:
 * - apply the style depending on the "type" of the current selection:
 *   - to the whole frame if a frame is selected
 *   - to the whole paragraphs in the selection if there is a selection
 *   - to the whole current paragraph if there is no selection but the cursor is in edit mode.
 *   - have a look at `void ScribusDoc::itemSelection_SetNamedCharStyle(const QString& name, Selection* customSelection)`
 *   - a different approach might use the story-applyStyle(pos, style)  used in gtaction.cpp
 *   - it probably only works if we are already in edit mode and the cursor has a position
 *
 *
 * a good example for applying the paragraph style seems to be
 * void ScribusMainWindow::setNewCharStyle(const QString& name)
 * in scribus.cpp, which is called from the properties palette.
 *
 */
void TextFrame::applyParagraphStyle(std::string styleName)
{
	ParagraphStyle style;
	style.setParent(QString::fromStdString(styleName));
	item->getScribusItem()->doc()->itemSelection_ApplyParagraphStyle(style);
}
} // namespace
