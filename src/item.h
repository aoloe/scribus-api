#ifndef API_ITEM_LIB
#define API_ITEM_LIB

#include <memory>

#include "scribusapi.h"

#include "pageitem_textframe.h"

namespace API {

class TextFrame;

class SCRIBUS_API Item
{
	public:
		Item(PageItem* item) :
			scribusItem{item} {}

		bool isTextFrame() const { return scribusItem->asTextFrame(); }
		PageItem* getScribusItem() const { return scribusItem; }

	private:
		PageItem* scribusItem;
};

} // namespace

#endif
