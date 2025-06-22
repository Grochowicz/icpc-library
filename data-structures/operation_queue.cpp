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
template<typename T>
struct op_queue {
    op_stack<T> add, rem;
    void push(T val) {
        add.push(val);
    }
    void invert() {
        if(not rem.empty()) return;
        while(not add.empty()) {
            T u = add.top(); add.pop();
            rem.push(u);
        }
    }
    T ans() {
        invert();
        assert(not rem.empty());
        T res = rem.ans();
        if(not add.empty()) res = f(res,add.ans());
        return res;
    }
    T front() {
        invert();
        assert(not rem.empty());
        return rem.top();
    }
    void pop() {
        invert();
        assert(not rem.empty());
        rem.pop();
    }
    size_t size() {
        return add.size()+rem.size();
    }
    bool empty() {
        return add.empty() and rem.empty();
    }
};
