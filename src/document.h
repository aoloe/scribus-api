#ifndef API_DOCUMENT_LIB
#define API_DOCUMENT_LIB

#include <memory>
#include <vector>
#include <string>
#include "third-party/optional/optional.h"


#include "scribusapi.h"

class ScribusDoc;

namespace API {

class Item;

class SCRIBUS_API Document
{
	public:

		/**
		 * \brief Initialize an API document with a Scribus "core" document.
		 * \param doc A pointer to a ScribusDoc structure passed to the plugin as an argument.
		 */
		Document(ScribusDoc* scribusDoc) :
			scribusDoc{scribusDoc}
		{
		}

		// TODO: return an optional shared_ptr
		/* static*/ std::shared_ptr<Document> getActive();
		bool isOpen() { return scribusDoc != nullptr; }

        /**
         * Return the first selected item, if any.
         */
        nonstd::optional<Item> getActiveItem();

        /**
         * /brief Get the names of all character styles
         */
        std::vector<std::string> getCharacterStyleNames();

        /**
         * /brief Get the names of all paragraph styles
         */
        std::vector<std::string> getParagraphStyleNames();

	private:

        ScribusDoc* scribusDoc;
};

} // namespace

#endif
