### 两个列表的最小索引和
### Minimum Index Sum of Two Lists

> 假设 Andy 和 Doris 想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。  
> 你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设答案总是存在。  

> Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.  
> You need to help them find out their **common interest** with the **least list index sum**. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.  

----------

#### I 哈希表

利用哈希表记录第一个数组及其下标，开始遍历第二个数组并判断其元素是否出现在哈希表中：  
1. 如果出现，则比较下标和与当前最小下标和  
   - 如果一样，则将其加入返回数组  
   - 如果较大，则不处理
   - 如果较小，则清空返回数组，将当前字符串作为唯一新元素
2. 如果未出现，则返回空数组

```cpp
vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
{
    unordered_map<string, int> mp;
    for(int i = 0; i < list1.size(); ++i)
        mp[list1[i]] = i;
    int min = 2001;
    vector<string> ret;
    for(int i = 0; i < list2.size(); ++i)
    {
        if(mp.count(list2[i]) && i + mp[list2[i]] <= min)
        {
            if(i +mp[list2[i]] < min)
            {
                min = i + mp[list2[i]];
                ret.clear();
            }
            ret.push_back(list2[i]);
        }
    }
    return ret;
}
```
