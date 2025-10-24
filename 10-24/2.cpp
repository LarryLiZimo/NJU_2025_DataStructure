#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>

#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
//#define int ll



using namespace std;

inline int Read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    do {
        x = x * 10 + (ch - '0');
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return x * f;
}
template<typename Iterator>
void Sort(Iterator first, Iterator last) {
    if (first == last) return; // 空序列

    for (Iterator i = first + 1; i != last; ++i) {
        auto key = *i; // 当前要插入的元素
        Iterator j = i;

        // 将大于key的元素向后移动
        while (j != first && *(j - 1) > key) {
            *j = *(j - 1);
            --j;
        }

        *j = key; // 插入key到正确位置
    }
}

template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front_ptr;
    Node* back_ptr;
    size_t queue_size;

public:
    Queue() : front_ptr(nullptr), back_ptr(nullptr), queue_size(0) {}

    ~Queue() {
        while (!empty()) {
            pop();
        }
    }

    void push(const T& value) {
        Node* new_node = new Node(value);
        if (empty()) {
            front_ptr = back_ptr = new_node;
        }
        else {
            back_ptr->next = new_node;
            back_ptr = new_node;
        }
        ++queue_size;
    }

    void pop() {
        if (!empty()) {
            Node* temp = front_ptr;
            front_ptr = front_ptr->next;
            delete temp;
            --queue_size;
            if (empty()) {
                back_ptr = nullptr;
            }
        }
    }

    T& front() {
        return front_ptr->data;
    }

    const T& front() const {
        return front_ptr->data;
    }

    T& back() {
        return back_ptr->data;
    }

    const T& back() const {
        return back_ptr->data;
    }

    bool empty() const {
        return queue_size == 0;
    }

    size_t size() const {
        return queue_size;
    }
};
template<typename T>
class Vector {
private:
    T* data;
    size_t capacity;
    size_t len;

public:
    Vector() : data(nullptr), capacity(0), len(0) {}

    ~Vector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (len >= capacity) {
            size_t new_capacity = capacity == 0 ? 1 : capacity * 2;
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < len; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        data[len++] = value;
    }

    void pop_back() {
        if (len > 0) {
            --len;
        }
    }

    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    size_t size() const {
        return len;
    }

    bool empty() const {
        return len == 0;
    }

    T* begin() {
        return data;
    }

    T* end() {
        return data + len;
    }
};

#define FUCKING_DS
#ifdef FUCKING_DS
#define sort Sort
#define vector Vector
#define queue Queue
#endif

const int N = 1006;
int n,sn[N][2],a[N];
typedef pair<int, int> pi;
vector<int> x[N * 2];
void dfs(int cur, int row, int col) {
    if (a[cur] <= 0) {
        return;
    }
    x[col + N].push_back(a[cur]);
    dfs(sn[cur][0], row + 1, col - 1);
    dfs(sn[cur][1], row + 1, col + 1);
}
signed main() {
    n = Read();
    queue<int*>q;
    q.push(&sn[0][0]);
    for (int i = 1; i <= n; i++) {
        a[i] = Read();
        *q.front() = i;
        q.pop();
        if (a[i] > 0) {
            q.push(&sn[i][0]);
            q.push(&sn[i][1]);
        }
    }
    dfs(1,0,0);
    int ok = 0;
    for (int i = -n; i <= n; i++) {
        if (!x[i+N].empty()) {
            if (ok) {
                cout << "| ";
            }
            ok = 1;
            sort(x[i + N].begin(), x[i + N].end());
            for (int j = 0; j < x[i + N].size(); j++) {
                cout << x[i + N][j] << " ";
            }
        }
    }
    cout << endl;
}