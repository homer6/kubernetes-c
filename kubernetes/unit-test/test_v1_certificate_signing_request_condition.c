#ifndef v1_certificate_signing_request_condition_TEST
#define v1_certificate_signing_request_condition_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_certificate_signing_request_condition_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_certificate_signing_request_condition.h"
v1_certificate_signing_request_condition_t* instantiate_v1_certificate_signing_request_condition(int include_optional);



v1_certificate_signing_request_condition_t* instantiate_v1_certificate_signing_request_condition(int include_optional) {
  v1_certificate_signing_request_condition_t* v1_certificate_signing_request_condition = NULL;
  if (include_optional) {
    v1_certificate_signing_request_condition = v1_certificate_signing_request_condition_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      kubernetes_v1_certificate_signing_request_condition_TYPE_Approved
    );
  } else {
    v1_certificate_signing_request_condition = v1_certificate_signing_request_condition_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      kubernetes_v1_certificate_signing_request_condition_TYPE_Approved
    );
  }

  return v1_certificate_signing_request_condition;
}


#ifdef v1_certificate_signing_request_condition_MAIN

void test_v1_certificate_signing_request_condition(int include_optional) {
    v1_certificate_signing_request_condition_t* v1_certificate_signing_request_condition_1 = instantiate_v1_certificate_signing_request_condition(include_optional);

	cJSON* jsonv1_certificate_signing_request_condition_1 = v1_certificate_signing_request_condition_convertToJSON(v1_certificate_signing_request_condition_1);
	printf("v1_certificate_signing_request_condition :\n%s\n", cJSON_Print(jsonv1_certificate_signing_request_condition_1));
	v1_certificate_signing_request_condition_t* v1_certificate_signing_request_condition_2 = v1_certificate_signing_request_condition_parseFromJSON(jsonv1_certificate_signing_request_condition_1);
	cJSON* jsonv1_certificate_signing_request_condition_2 = v1_certificate_signing_request_condition_convertToJSON(v1_certificate_signing_request_condition_2);
	printf("repeating v1_certificate_signing_request_condition:\n%s\n", cJSON_Print(jsonv1_certificate_signing_request_condition_2));
}

int main() {
  test_v1_certificate_signing_request_condition(1);
  test_v1_certificate_signing_request_condition(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_certificate_signing_request_condition_MAIN
#endif // v1_certificate_signing_request_condition_TEST
