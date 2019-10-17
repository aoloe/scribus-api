#ifndef API_DOCUMENT_LIB
#define API_DOCUMENT_LIB

#include <memory>
#include <vector>
#include <string>

class ScribusDoc;

namespace API {

class Item;

class Document
{
	public:

		/**
		 * \brief Initialize an API document with a Scribus "core" document.
		 * \param doc A pointer to a ScribusDoc structure passed to the plugin as an argument.
		 */
		Document() :
			scribusDoc{nullptr}
		{
		}
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
         * /brief Get the name of the default character style
         */
		const std::string getDefaultCharacterStyleName() const;

        /**
         * /brief Get the names of all character styles
         */
        const std::vector<std::string> getCharacterStyleNames() const;

        /**
         * /brief Get the name of the default paragraph style
         */
		const std::string getDefaultParagraphStyleName() const;

        /**
         * /brief Get the names of all paragraph styles
         */
        const std::vector<std::string> getParagraphStyleNames() const;

	private:

        ScribusDoc* scribusDoc;
};

} // namespace

#endif
