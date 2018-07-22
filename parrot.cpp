#include <string>
#include <iostream>
#include <curl/curl.h>

size_t callback(char *ptr, size_t size, size_t nmemb, std::string *stream) {
	std::cout << ptr << std::endl;
        return size * nmemb;
}

int main() {
	CURL *curl;
        CURLcode ret;

        curl = curl_easy_init();
        std::string chunk;

	if (curl == NULL) return 1;

	curl_easy_setopt(curl, CURLOPT_URL, "http://parrot.live");
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);

	ret = curl_easy_perform(curl);
	curl_easy_cleanup(curl);

	// ...
	if (ret != CURLE_OK) return 1;
        return 0;
}
