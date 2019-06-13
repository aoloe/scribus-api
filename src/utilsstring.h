#ifndef API_UTILS_STRING_LIB
#define API_UTILS_STRING_LIB

#include <string>
#include <sstream>

namespace API {
namespace String
{

/**
 * https://codereview.stackexchange.com/a/142912
 *
 * TODO:
 * - check if the stringstream is the fastest solution...
 */
template<typename Iterator>
std::string join(Iterator begin,
                 Iterator end,
                 const std::string & separator =", ")
{
    std::ostringstream ss;

    if(begin != end)
    {
        ss << *begin++;
    }    

    while(begin != end)
    {
        ss << separator;
        ss << *begin++;
    }

    return ss.str();
}

bool static startsWith(const std::string& string, const std::string& start)
{
	return string.size() >= start.size() && string.compare(0, start.size(), start) == 0;
}

}
}

#endif

