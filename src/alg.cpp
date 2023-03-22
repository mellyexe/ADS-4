// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value) 
{
  int count = 0;
  int left = 0, right = size - 1;
  int mid = 0;

  while (left <= right) {
    mid = (left + right) / 2;
    if (arr[mid] == value) {
      count++;
      int temp = mid - 1;
      while (temp >= left && arr[temp] == value) {
        count++;
        temp--;
      }
      temp = mid + 1;
      while (temp <= right && arr[temp] == value) {
        count++;
        temp++;
      }
      return count;
    }
    else if (arr[mid] < value)
      left = mid + 1;
    else if (arr[mid] > value)
      right = mid - 1;
  }
  return 0;
}

int countPairs1(int* arr, int len, int value)
{
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) count++;
    }
  }
  return count;
}

int countPairs2(int* arr, int len, int value)
{
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len && arr[i] + arr[j] <= value; j++) {
      if (arr[i] + arr[j] == value) count++;
    }
    if (arr[i] + arr[i + 1] > value) return count;
  }
  return count;
}

int countPairs3(int* arr, int len, int value)
{
  int count = 0;
  for (int i = 0; i < len - 1 && arr[i] <= value; i++)
    count += cbinsearch(arr + i + 1, len - i - 1, value - arr[i]);
  return count;
}
