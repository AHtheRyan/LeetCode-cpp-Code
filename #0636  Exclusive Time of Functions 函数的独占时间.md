### 函数的独占时间
### Exclusive Time of Functions

> 有一个**单线程** CPU 正在运行一个含有 `n` 道函数的程序。每道函数都有一个位于 `0` 和 `n-1` 之间的唯一标识符。  
> 函数调用**存储在一个`调用栈`上**：当一个函数调用开始时，它的标识符将会推入栈中。而当一个函数调用结束时，它的标识符将会从栈中弹出。标识符位于栈顶的函数是**当前正在执行的函数**。每当一个函数开始或者结束时，将会记录一条日志，包括函数标识符、是开始还是结束、以及相应的时间戳。  
> 给你一个由日志组成的列表 `logs`，其中 `logs[i]` 表示第 `i` 条日志消息，该消息是一个按 `"{function_id}:{"start" | "end"}:{timestamp}"` 进行格式化的字符串。例如，`"0:start:3"` 意味着标识符为 `0` 的函数调用在时间戳 `3` 的**起始开始执行**；而 `"1:end:2"` 意味着标识符为 `1` 的函数调用在时间戳 `2` 的**末尾结束执行**。注意，函数可以**调用多次，可能存在递归调用**。  
> 函数的**独占时间**定义是在这个函数在程序所有函数调用中执行时间的总和，调用其他函数花费的时间不算该函数的独占时间。例如，如果一个函数被调用两次，一次调用执行 `2` 单位时间，另一次调用执行 `1` 单位时间，那么该函数的**独占时间**为 `2 + 1 = 3`。  
> 以数组形式返回每个函数的A**独占时间**，其中第 `i` 个下标对应的值表示标识符 `i` 的函数的独占时间。  

> On a **single-threaded** CPU, we execute a program containing `n` functions. Each function has a unique ID between `0` and `n-1`.  
> Function calls are **stored in** a `call stack`: when a function call starts, its ID is pushed onto the stack, and when a function call ends, its ID is popped off the stack. The function whose ID is at the top of the stack is **the current function being executed**. Each time a function starts or ends, we write a log with the ID, whether it started or ended, and the timestamp.  
> You are given a list `logs`, where `logs[i]` represents the `ith` log message formatted as a string `"{function_id}:{"start" | "end"}:{timestamp}"`. For example, `"0:start:3"` means a function call with function ID `0` **started at the beginning** of timestamp `3`, and `"1:end:2"` means a function call with function ID `1` **ended at the end** of timestamp `2`. Note that a function can be called **multiple times, possibly recursively**.  
> A function's **exclusive time** is the sum of execution times for all function calls in the program. For example, if a function is called twice, one call executing for `2` time units and another call executing for `1` time unit, the exclusive time is `2 + 1 = 3`.  
> Return *the **exclusive time** of each function in an array, where the value at the `ith` index represents the exclusive time for the function with ID `i`*.  

----------

#### I 栈

对每个字符串进行简单分割后，可以获得三个部分：  
- 函数代号
- 状态是开始还是结束
- 当前时间  

由于只需要单向考虑每个函数，可以用栈来解决，栈中记录函数的代号以及开始的时间，具体分类如下：  
- 当前状态是结束：此时栈中必然存在记录，且与当前结束状态的函数呈对应关系，因此可以直接计算时长，并记录，然后将栈顶元素弹出
  - 如果此时栈空，则继续判断  
  - 如果此时栈非空，则说明存在函数内调用，需要将外层函数的时长做调整，将其开始时间重新假定成**当前状态处理函数的结束时间 + 1**即可  
- 如果当前状态是开始，则
  - 如果栈空，说明新的函数开始了，可以重新进行计算，直接将当前数值入栈即可  
  - 如果栈非空，则说明出现了函数内调用，我们可以假定调用函数已经结束，计算其时长并记录，后续在根据被调函数的结束时间进行修改即可  

```cpp
vector<int> exclusiveTime(int n, vector<string>& logs) 
{
    vector<int> ret(n, 0);
    stack<pair<int, int>> stk;
    for(auto& log : logs)
    {
        int index = 0;
        int task = 0;
        int time = 0;
        string condition;

        while(log[index] != ':')
            task = task * 10 + log[index++] - '0';
        ++index;
        while(log[index] != ':')
            condition += log[index++];
        ++index;
        while(index < log.size())
            time = time * 10 + log[index++] - '0';

        if(condition == "end")
        {
            auto cur = stk.top();
            int sum = time - cur.second + 1;
            ret[cur.first] += sum;
            stk.pop();
            if(!stk.empty())
                stk.top().second = time + 1;
        }
        else
        {
            if(!stk.empty())
            {
                auto cur = stk.top();
                ret[cur.first] += time - cur.second;
            }
            stk.push({task, time});
        }
    }
    return ret;
}
```
