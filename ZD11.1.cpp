int binarySearch(const int* array, int target, int min, int max) {
    while (min <= max) {
        int mid = min + (max - min) / 2; // Находим середину

        if (array[mid] > target) {
            max = mid - 1; // Искомое значение в нижней половине массива
        }
        else if (array[mid] < target) {
            min = mid + 1; // Искомое значение в верхней половине массива
        }
        else {
            return mid; // Элемент найден
        }
    }

    return -1; // Элемент не найден
}
