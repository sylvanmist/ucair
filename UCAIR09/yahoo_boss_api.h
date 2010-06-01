#ifndef __yahoo_boss_h__
#define __yahoo_boss_h__

#include <string>
#include "search_engine.h"

namespace ucair {

/// Wrapper for Yahoo! BOSS Search API
class YahooBossAPI: public SearchEngine {
public:

	std::string getSearchEngineId() const { return "yahoo"; }
	std::string getSearchEngineName() const { return "Yahoo!"; }
	bool fetchResults(Search &search, int start_pos, int result_count);
	int maxAllowedResultCount() const { return 100; }

	/*! \brief Builds a URL for a search page.
	 *  \param query query
	 *  \param start_pos start pos of the first result
	 *  \param result_count number of results to retrieve
	 *  \return page url
	 */
	static std::string buildURL(const SearchQuery &query, int start_pos, int result_count);

	/*! \brief Parses the HTML search page into a search instance.
	 *  \param[out] search search instance that receives results.
	 *              if it already contains content from a previous search page,
	 *              its result map and total result count will be updated.
	 *  \param[in] content HTML page content
	 *  \return true if succeeded
	 */
	static bool parsePage(Search &search, const std::string &content);

	/*! \brief Checks spelling.
	 *  \param[in] input input text
	 *  \param[out] output output text (with correct spelling)
	 *  \return true if succeeded
	 */
	static bool checkSpelling(const std::string &input, std::string &output);
};

}

#endif
