template <typename T>
class DynamicVector {
public:
    explicit DynamicVector(int initial_capacity = 4)
        : _size(0), _capacity(initial_capacity), _data(nullptr) {
        if (_capacity > 0) {
            _data = new T[_capacity];
        }
    }

    ~DynamicVector() {
        clear();
        delete[] _data;
    }

    void push_back(const T& value) {
        if (_size >= _capacity) {
            grow();
        }
        _data[_size++] = value;
    }

    void push_front(const T& value) {
        if (_size >= _capacity) {
            grow();
        }
        // Shift all elements one position to the right
        for (int i = _size; i > 0; --i) {
            _data[i] = _data[i - 1];
        }
        _data[0] = value;
        _size++;
    }

    void pop_back() {
        if (_size > 0) {
            _size--;
        }
    }

    void pop_front() {
        if (_size > 0) {
            // Shift all elements one position to the left
            for (int i = 0; i < _size - 1; ++i) {
                _data[i] = _data[i + 1];
            }
            _size--;
        }
    }

    T& back() {
        return _data[_size - 1];
    }

    const T& back() const {
        return _data[_size - 1];
    }

    T& front() {
        return _data[0];
    }

    const T& front() const {
        return _data[0];
    }

    T& operator[](int index) {
        return _data[index];
    }

    const T& operator[](int index) const {
        return _data[index];
    }

    int size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }

    void clear() {
        _size = 0;
    }

    void erase(int index) {
        if (index < 0 || index >= _size) {
            return;
        }

        for (int i = index; i < _size - 1; ++i) {
            _data[i] = _data[i + 1];
        }
        _size--;
    }

private:
    T* _data;
    int _size;
    int _capacity;

    void grow() {
        _capacity *= 2;
        T* new_data = new T[_capacity];
        for (int i = 0; i < _size; ++i) {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
    }
};
