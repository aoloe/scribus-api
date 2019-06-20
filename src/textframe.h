#ifndef API_TEXTFRAME_LIB
#define API_TEXTFRAME_LIB

#include <memory>

#include "item.h"

#include "scribusapi.h"
#include "pageitem_textframe.h"

namespace API {

class Item;

class SCRIBUS_API TextFrame
{
	public:
		TextFrame(std::shared_ptr<Item> item);
		~TextFrame() {}

		/**
		 * @brief  Get item as a TextFrame. If item cannot be returned as a text frame, it returns a nullptr.
		 */
		static std::shared_ptr<TextFrame> getFromItem(std::shared_ptr<Item> item);

		/**
		 * @brief  Apply the character style at the current cursor position.
		 */
		void applyCharacterStyle(std::string styleName);
		/**
		 * @brief  Apply the paragraph style at the current cursor position.
		 *
		 */
		void applyParagraphStyle(std::string styleName);

	private:
		std::shared_ptr<Item> item;

};

} // namespace

#endif
