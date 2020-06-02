// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
// 说明：
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
#include <vector>
using namespace std;
//时间O(N),空间O(N) hash_set去重 2 * (a + b + c) - (a + a + b + b + c) = c
//空间O(1)
//异或操作， 满足交换律和结合律，相等异或为0,0和a异或等于a
//则全部进行异或则是一个数
int singleNumber(vector<int>& nums) 
{
    int a =0;
    for(auto n : nums)
    {
        a ^= n;
    };

    return a;
};

//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
//时间O(N)，空间O(N)--将输入数组存储到 HashSet，然后使用 HashSet 中数字和的三倍与数组之和比较。
// 3 * (a + b + c) - (a + a + a + b + b + b + c) = 2 c
//要求时间O(N),空间O(1)
//Thinking

// ones ^= num：记录至目前元素num，二进制某位出现 11 次（当某位出现 33 次时有 ones = 1ones=1 ，与 twos = 1twos=1 共同表示“出现 33 次”）；
// twos |= ones & num：记录至目前元素num，二进制某位出现 22 次 （当某位出现 22 次时，twos = 1twos=1 且 ones = 0ones=0 ）；
// threes = ones & twos：记录至目前元素num，二进制某位出现 33 次（即当 onesones 和 twostwos 对应位同时为 11 时 three = 1three=1 ）。
// one &= ~threes, two &= ~threes：将 onesones, twostwos 中出现了 33 次的对应位清零，实现 “不考虑进位的三进制加法” 。

//Thinking
int singleNumber_2(vector<int>& nums) 
{
    int ones = 0;
    int twos = 0;
    int threes = 0;
    for (int num : nums)
    {
        twos |= ones & num; // 二进制某位出现1次时twos = 0，出现2, 3次时twos = 1；
        ones ^= num;  // 二进制某位出现2次时ones = 0，出现1, 3次时ones = 1；
        threes = ones & twos; // 二进制某位出现3次时（即twos = ones = 1时）three = 1，其余即出现1, 2次时three = 0；
        ones &= ~threes; // 将二进制下出现3次的位置零，实现`三进制下不考虑进位的加法`；
        twos &= ~threes;
    }
    return ones;
}


//给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
vector<int> singleNumber_3(vector<int>& nums) 
{
    //找出a^b
    int a_xor_b = 0;
    for(auto n : nums)
    {
        a_xor_b ^= n;
    };
    //a_xor_b的每一位的1表示该位1位奇数
    int diff = a_xor_b & (-a_xor_b); //将a_xor_b保留最右一位1的后面的值，其余为0
    int ret = 0;
    for(auto n : nums)
    {
        if(n & diff) //说明n与diff那位的1也是1
        { 
            ret ^= n;
        }
    };
    return {ret,a_xor_b^ret};
}