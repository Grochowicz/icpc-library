int f(int a, int b) {
    return a|b;
}
template<typename T>
struct op_stack {
    vector<T> stk, op;
    void push(T val) {
        stk.push_back(val);
        if(op.empty()) op.push_back(val);
        else op.push_back(f(op.back(),val));
    }
    T ans() {
        return op.back();
    }
    T top() {
        return stk.back();
    }
    void pop() {
        stk.pop_back();
        op.pop_back();
    }
    size_t size() {
        return stk.size();
    }
    bool empty() {
        return stk.empty();
    }
};
