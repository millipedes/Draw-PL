#include "shape/point_test.h"
#include "shape/line_test.h"
#include "shape/rectangle_test.h"

int main(void) {
  if(point_test())
    printf("[POINT_TEST]: PASSED\n");
  else
    printf("[POINT_TEST]: FAILED\n");
  if(line_test())
    printf("[LINE_TEST]: PASSED\n");
  else
    printf("[LINE_TEST]: FAILED\n");
  if(rectangle_test())
    printf("[LINE_TEST]: PASSED\n");
  else
    printf("[LINE_TEST]: FAILED\n");
  return 0;
}
