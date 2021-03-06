// 0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。
// 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

// 示例 1：
// 输入: n = 5, m = 3
// 输出: 3

// 示例 2：
// 输入: n = 10, m = 17
// 输出: 2

// 限制：
// 1 <= n <= 10^5
// 1 <= m <= 10^6

class Solution
{
public:
    //https://blog.csdn.net/u011500062/article/details/72855826
    // 约瑟夫环
    int lastRemaining(int n, int m)
    {
        int res = 0;
        for (int i = 2; i <= n; i++)
        {
            res = (res + m) % i;
        }
        return res;
    }
};

// **问题1：**假设我们已经知道11个人时，胜利者的下标位置为6。那下一轮10个人时，胜利者的下标位置为多少？
// **答：**其实吧，第一轮删掉编号为3的人后，之后的人都往前面移动了3位，胜利这也往前移动了3位，所以他的下标位置由6变成3。

// **问题2：**假设我们已经知道10个人时，胜利者的下标位置为3。那下一轮11个人时，胜利者的下标位置为多少？
// **答：**这可以看错是上一个问题的逆过程，大家都往后移动3位，所以f(11,3)=f(10,3)+3f(11,3)=f(10,3)+3f(11,3)=f(10,3)+3。
// 不过有可能数组会越界，所以最后模上当前人数的个数，f(11,3)=（f(10,3)+3）%11f(11,3)=（f(10,3)+3）\%11f(11,3)=（f(10,3)+3）%11

// **问题3：**现在改为人数改为N，报到M时，把那个人杀掉，那么数组是怎么移动的？
// **答：**每杀掉一个人，下一个人成为头，相当于把数组向前移动M位。若已知N-1个人时，胜利者的下标位置位f(N−1,M)f(N-1,M)f(N−1,M)，
// 则N个人的时候，就是往后移动M为，(因为有可能数组越界，超过的部分会被接到头上，所以还要模N)，
// 既f(N,M)=(f(N−1,M)+M)%nf(N,M)=(f(N-1,M)+M)\%nf(N,M)=(f(N−1,M)+M)%n

// **注：**理解这个递推式的核心在于关注胜利者的下标位置是怎么变的。每杀掉一个人，其实就是把这个数组向前移动了M位。然后逆过来，
// 就可以得到这个递推式。