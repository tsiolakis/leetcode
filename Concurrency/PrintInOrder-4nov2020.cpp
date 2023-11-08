class Foo {
public:
    Foo() {}
    bool firstDone = false;
    bool secondDone = false;
    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstDone = true;
    }
    void second(function<void()> printSecond) {
        while (!firstDone) {
            this_thread::sleep_for(chrono::milliseconds(1));
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondDone = true;
    }
    void third(function<void()> printThird) {
        while (!secondDone) {
            this_thread::sleep_for(chrono::milliseconds(1));
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
