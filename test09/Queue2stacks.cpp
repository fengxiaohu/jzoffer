#include<stack>
#include<exception>
using namespace std;
template <typename T> class CQueue
{
    public:
    CQueue(void);
    ~CQueue(void);
    void appendTail(const T& value);
    T deletehead();
    private:
    stack<T> s1;
    stack<T> s2;
};
template <typename T> CQueue<T>::CQueue(void)
{
    
} 
template <typename T> CQueue<T>::~CQueue(void)
{

}
template <typename T> void CQueue<T>::appendTail(const T& value)
{
    s1.push(value);
}
template <typename T> T CQueue<T>::deletehead()
{

    if(s2.size()<=0)
    {
        while(!s1.empty())
        {
            T& data = s1.top();
            s1.pop();
            s2.push(data);
        }
    }
    T head = s2.top();
    s2.pop();
    return head;
}

void Test(char actual,char expect)
{
    if(actual == expect)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}
int main(int argc,char** argv)
{
    CQueue<char> queue;
    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');
    char head = queue.deletehead();
    Test(head, 'a');

    head = queue.deletehead();
    Test(head, 'b');

    queue.appendTail('d');
    head = queue.deletehead();
    Test(head, 'c');

    queue.appendTail('e');
    head = queue.deletehead();
    Test(head, 'd');

    head = queue.deletehead();
    Test(head, 'e');

    return 0;
     
}



