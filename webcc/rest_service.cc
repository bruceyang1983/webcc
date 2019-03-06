#include "webcc/rest_service.h"

#include "webcc/logger.h"

namespace webcc {

// -----------------------------------------------------------------------------

void RestListService::Handle(const RestRequest& request,
                             RestResponse* response) {
  if (request.method == http::kGet) {
    Get(UrlQuery(request.url_query_str), response);
  } else if (request.method == http::kPost) {
    Post(request.content, response);
  } else {
    LOG_ERRO("RestListService doesn't support '%s' method.",
             request.method.c_str());
  }
}

// -----------------------------------------------------------------------------

void RestDetailService::Handle(const RestRequest& request,
                               RestResponse* response) {
  if (request.method == http::kGet) {
    Get(request.url_sub_matches, UrlQuery(request.url_query_str), response);
  } else if (request.method == http::kPut) {
    Put(request.url_sub_matches, request.content, response);
  } else if (request.method == http::kPatch) {
    Patch(request.url_sub_matches, request.content, response);
  } else if (request.method == http::kDelete) {
    Delete(request.url_sub_matches, response);
  } else {
    LOG_ERRO("RestDetailService doesn't support '%s' method.",
             request.method.c_str());
  }
}

}  // namespace webcc
