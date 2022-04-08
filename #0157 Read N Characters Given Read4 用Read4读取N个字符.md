### 用Read4读取N个字符
### Read N Characters Given Read4

> 给你一个文件，并且该文件只能通过给定的 `read4` 方法来读取，请实现一个方法使其能够读取 n 个字符。  
> **read4 方法**：  
> API `read4` 可以从文件中读取 `4` 个连续的字符，并且将它们写入缓存数组 `buf` 中。  
> 返回值为实际读取的字符个数。  

> Given a `file` and assume that you can only read the file using a given method `read4`, implement a method to read `n` characters.  
> **Method read4**:  
> The API `read4` reads **four consecutive characters** from `file`, then writes those characters into the buffer array `buf4`.  
> The return value is the number of actual characters read.  

----------

#### I 简单模拟

利用 `read4()` 对字符串进行读取，比较 `n` 和目前读取的字符串大小，如果超过，则可以读取 `n` 个字符，返回即可，如果未超过且读取结束，则只能读取全部字符串的长度并返回  

```cpp
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution 
{
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) 
    {
        int ret = 0;
        for(int i = 0; i < n; i += 4)
        {
            ret += read4(buf + i);
            if(ret >= n)
                return n;
        }
        return ret;
    }
};
```
