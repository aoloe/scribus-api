#ifndef API_ITEM_LIB
#define API_ITEM_LIB

#include "third-party/optional/optional.h"

#include "scribusapi.h"

#include "pageitem_textframe.h"

namespace API {

class SCRIBUS_API Item
{
	public:
		Item(PageItem* item) :
			scribusPageItem{item} {}

	private:
		PageItem* scribusPageItem;
};

} // namespace

#endif
