int binarySearchRecursive(const int* array, int target, int min, int max) {
    if (min > max) {
        return -1; // ������� ������: ������� �� ������
    }

    int mid = min + (max - min) / 2;

    if (array[mid] > target) {
        return binarySearchRecursive(array, target, min, mid - 1);
    }
    else if (array[mid] < target) {
        return binarySearchRecursive(array, target, mid + 1, max);
    }
    else {
        return mid; // ������� ������
    }
}