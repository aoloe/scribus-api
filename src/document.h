#ifndef API_DOCUMENT_LIB
#define API_DOCUMENT_LIB

#include <memory>
#include <vector>
#include <string>

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

		static std::shared_ptr<Document> getActive();

        /**
         * Return the first selected item, if any.
         */
        std::shared_ptr<Item> getActiveItem();

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
