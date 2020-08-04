int main(int argc, char const *argv[]) {
  int nums[2][3] = {{16, 18, 20}, {25, 26, 27}};
  int size = static_cast<int>(sizeof(nums) / sizeof(int));

  printf("element is: %d\n", nums[0][0]);
  printf("element address is: %p\n", &nums[0][0]);
  printf("element is: %d\n", nums[0][1]);
  printf("element address is: %p\n", &nums[0][1]);
  printf("element is: %d\n", nums[0][2]);
  printf("element address is: %p\n", &nums[0][2]);
  printf("element is: %d\n", nums[1][0]);
  printf("element address is: %p\n", &nums[1][0]);
  printf("element is: %d\n", nums[1][1]);
  printf("element address is: %p\n", &nums[1][1]);
  printf("element is: %d\n", nums[1][2]);
  printf("element address is: %p\n", &nums[1][2]);
  printf("---------------\n");

  printf("-element address is: %p\n", nums);
  printf("-element address is: %p\n", nums + 1);
  // printf("-element address is: %d\n", *(*nums+1));
  // printf("-element address is: %d\n", **nums);
  // printf("-element address is: %d\n", **nums);
  printf("-element address is: %d\n", *(*(nums+1)+1));
  // printf("-element address is: %d\n", **nums);
  // printf("-element address is: %d\n", **nums);



  return 0;
}
