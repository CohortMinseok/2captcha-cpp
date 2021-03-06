#include <cstdio>

#include "curl_http.hpp"
#include "api2captcha.hpp"

int main (int ac, char ** av)
{
   api2captcha::curl_http_t http;
   http.set_verbose (true);

   api2captcha::client_t client;
   client.set_http_client (&http);
   client.set_api_key (API_KEY);

   api2captcha::capy_t cap;
   cap.set_site_key ("PUZZLE_Abc1dEFghIJKLM2no34P56q7rStu8v");
   cap.set_url ("https://www.mysite.com/captcha/");
   cap.set_api_server ("https://jp.api.capy.me/");

   try
   {
      client.solve (cap);
      printf ("code '%s'\n", cap.code ().c_str ());
   }
   catch (std::exception & e)
   {
      fprintf (stderr, "Failed: %s\n", e.what ());
   }

   return 0;   
}
