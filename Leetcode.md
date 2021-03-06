# Leetcode


## [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) - [Solution](/Problems/5.%20Longest%20Palindromic%20Substring.cpp)
- 給定字串`s`，找出其中最長的回文字串
- 技巧：
    1. 動態規劃＋中心擴展
    2. [Manacher 算法](https://zh.wikipedia.org/wiki/%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2#Manacher%E7%AE%97%E6%B3%95)

## [51. N-Queens](https://leetcode.com/problems/n-queens/) - [Solution](/Problems/51_N_Queens.cpp)
- 給定`n`，輸出以`n*n`為棋盤的皇后棋擺放法
    - 皇后棋擺放法：同一行、列、斜角不能存在兩個皇后棋
- 技巧：
    - 注意到`1 <= n <= 9`：可以使用`int`儲存棋盤擺放狀態
    - 因為按照`row`枚舉，需要儲存的狀態有：`columns`、`diagonals_forward`、`diagonals_backward`
    - 計算對當前狀態的可放位置，等同於對下列兩項取 AND（`&`）：
        - `(1<<n)-1`（即，有`n`個`1`）
        - 上述三個儲存狀態（`columns`、`diagonals_forward`、`diagonals_backward`）沒佔用的位置：取非（`~`）
    - 列舉可以放的位置：
        - `x&(-x)`：獲得`x`的二進制表示中最低位`1`的位置
            - 該位置即為當前`row`中皇后棋要放的`column`值
        - `x&(x-1)`：將`x`二進制表示中最低位`1`變為`0`

## [52. N-Queens II](https://leetcode.com/problems/n-queens-ii/) - [Solution](/Problems/52_N_Queens_II.cpp)
- 給定`n`，輸出以`n*n`為棋盤的皇后棋擺放法**數量**
- 相關題： [51. N-Queens](#51-n-queens---solution)
    - 改為回傳數量

## [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) - [Solution](/Problems/88.%20Merge%20Sorted%20Array.cpp)
- 給定已排序的數組`nums1`、`nums2`與各自的元素數量`m`、`n`，合併`nums2`到`nums1`
    - 給定的`nums1`長度為`m+n`
- 技巧：逆向雙指針

## [120. Triangle](https://leetcode.com/problems/triangle/) - [Solution](/Problems/120.%20Triangle.cpp)
- 給定一個三角形數組`triangle`（每一層都比上一層多一個數），求出從頂走到底的最小花費
- 技巧：動態規劃
    - 每一層的第`j`個位置只和下一層的第`j`、`j+1`有關
    - 優化：由底向頂更改給定的變數`triangle`，空間複雜度為`0`

## [128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/submissions/) - [Solution](Problems/128.%20Longest%20Consecutive%20Sequence.cpp)
- 給定未排序數組`nums`，輸出其中連續數組的最長長度
- 技巧：使用`unordered_set`存取＋計算長度

## [135. Candy](https://leetcode.com/problems/candy/) - [Solution](Problems/135.%20Candy.cpp)
- 給定數組`ratings`，代表每個小孩的評分，回傳滿足以下條件的最小總糖果數
    1. 每個小孩至少會拿到`1`個糖果
    2. 相鄰評分更高的小孩會拿到較多糖果（可以同分，有一位拿到較少糖果）
- 技巧：遍歷＋紀錄當前升降序與糖果數
    - 若第`i`位同學評分比第`i-1`位同學高，則多拿一個糖果（`temp+1`）
    - 在遞減序列中，給第`i`位同學一個糖果，序列中的前面同學都多拿一個
        - 當前遞減序列的第一位置優先歸類為前一遞增序列
        - 當該同學所需要給的糖果數量`>`已經給的糖果數量，則將其納入遞減序列中
            - 檢查當

## [160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/) - [Solution](/Problems/160.%20Intersection%20of%20Two%20Linked%20Lists.cpp)
- 給定兩個 list 的 head：`headA`、`headB`，回傳相交的起始點，若無相交則回傳`NULL`
- 技巧：雙指針（`a`、`b`），到尾則從另一個的 list 的`head`再繼續。假設`ListA`長度為`m`、`ListB`長度為`n`：
        1.  `ListA`與`ListB`**有相交**，相交長度為`c`，則令`a+c=m`、`b+c=n`：`a`、`b`各走`a+b+c`次 → `a=b`
        2.  `ListA`與`ListB`**沒有相交**：
            1.  `m=n`：`a`、`b`各走`m=n`次 → `a=b=NULL`
            2.  `m!=n`：`a`、`b`各走`m+n`次 → `a=b=NULL`

## [167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) - [Solution](/Problems/167.%20Two%20Sum%20II%20-%20Input%20Array%20Is%20Sorted.cpp)
- 給定數組`numbers`與一數`target`，回傳`numbers`中兩數和為`target`的 index：**唯一解**

## [215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/) - [Solution](/Problems/215.%20Kth%20Largest%20Element%20in%20an%20Array.cpp)
- 給定數組`nums`與一數`k`，輸出`nums`中第`k`大的數
    - 等同求出第`n-k+1`小的數
- 技巧：快速排序法（二分查找）

## [241. Different Ways to Add Parentheses]() - [Solution](Problems/241.%20Different%20Ways%20to%20Add%20Parentheses.cpp)
- 給定運算式`expression`，輸出對任意運算加入括號可能會產生的所有結果
- 技巧：動態規劃
    - `dp[left][right]`代表從`operation[left]`到`operation[right]`會產生的不同結果

## [303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) - [Solution](/Problems/303_Range_Sum_Query_Immutable.cpp)
- 給定一數組`nums`，實現求**區間**和的 function
- 技巧：預先計算好所有前綴和，再根據給的 index 求出對應值

## [304. Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/) - [Solution](/Problems/304_Range_Sum_Query_2D_Immutable.cpp)
- 相關題：[303. Range Sum Query - Immutable](#303-range-sum-query---immutable)
- 給定一數組`matrix`，實現求**區域**和的 function
- 技巧：預先計算好**二維**前綴和，再根據給的行列 index 求出對應值
    - 注意更新及回傳的加減（加上沒有的、減去重疊的）— 集合概念

## [324. Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii/) - [Solution](Problems/324.%20Wiggle%20Sort%20II.cpp)
- 給定數組`nums`，將其改為符合「`nums[0]<nums[1]>nums[2]<nums[3]...`」條件的數組
- 技巧：複製另一個數組排序，根據大小重新填寫`nums`
    - [其他方法](https://leetcode.cn/problems/wiggle-sort-ii/solution/bai-dong-pai-xu-ii-by-leetcode-solution-no0s/)

## [406. Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height/) - [Solution](Problems/406.%20Queue%20Reconstruction%20by%20Height.cpp)
- 給定`people`，其中`people[i]=[h, k]`代表第`i`個人身高為`h`、`[0, i-1]`區間的人中，滿足身高`>=h`的有`k`個人。依照給定的資訊回傳正確的排列。
- 技巧：
    - 排序方式：身高由小到大，相同者`k`較大較前
    - 根據排序後的`people`的`k`資訊填入：由左到右第`k+1`個空位

## [450. Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/) - [Solution](/Problems/450_Delete_Node_in_a_BST.cpp)
- 給定一個二元樹根節點`root`與一數`key`，若`key`存在於此二元數內，則刪除並重組二元樹，回傳新的根節點
- 技巧：回溯法，在過程中記錄所尋找的點的**父節點**
    1. 對`key`節點**右**子樹的所有節點尋找最小值節點（最**左**葉節點）
    2. 對`key`節點**左**子樹的所有節點尋找最大值節點（最**右**葉節點）
    - 需注意的是，當`change_parent`（上述之父節點）與`key`節點（`target`）為同一個節點時，轉換的左右子樹會不同

## [462. Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/) - [Solution](Problems/462.%20Minimum%20Moves%20to%20Equal%20Array%20Elements%20II.cpp)
- 給定數組`nums`，求使得數組內所有數相等的最少操作次數
    - 一次操作定義為對數組內其中一個數`+1`或`-1`
- 技巧：**取中位數**而非平均數

## [478. Generate Random Point in a Circle](https://leetcode.com/problems/generate-random-point-in-a-circle/) - [Solution](/Problems/478.%20Generate%20Random%20Point%20in%20a%20Circle.cpp)
- 給定圓的半徑和圓心位置，實現產生圓內均勻隨機點的函式
- 技巧：`<random>`
    - `mt19937`：[梅森旋轉算法](https://zh.wikipedia.org/zh-tw/%E6%A2%85%E6%A3%AE%E6%97%8B%E8%BD%AC%E7%AE%97%E6%B3%95) - 偽隨機數產生演算法
    - `uniform_real_distribution`

## [497. Random Point in Non-overlapping Rectangles](https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/) - [Solution](/Problems/497.%20Random%20Point%20in%20Non-overlapping%20Rectangles.cpp)
- 給定一組矩形`rects`，`rects[i]=(a, b, x, y)`，`(a, b)`代表左下角座標、`(x, y)`代表右上角座標，`pick`：等機率輸出矩形範圍內的點
- 技巧：前綴和＋二分查找
    - 第`i`個矩形內的點有`(x-a+1)*(y-b+1)`個，根據此對每個點編號
    - 根據前綴和找出隨機選取的數對應的矩形，再計算座標位置

## [509. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/) - [Solution](Problems/509.%20Fibonacci%20Number.cpp)
- 給定`n`，算出`F(n)`
    - `F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)`

## [513. Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value/) - [Solution](/Problems/513.%20Find%20Bottom%20Left%20Tree%20Value.cpp)
- 給定二元樹的根節點`root`，找出該樹最底層最左邊的元素值
- 技巧：dfs / bfs

## [515. Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row/) - [Solution](/Problems/515.%20Find%20Largest%20Value%20in%20Each%20Tree%20Row.cpp)
- 給定一個二元數的節點`root`，輸出該樹由上到下每一層的最大元素
- 技巧：dfs＋高度紀錄

## [532. K-diff Pairs in an Array](https://leetcode.com/problems/k-diff-pairs-in-an-array/submissions/) - [Solution](/Problems/532.%20K-diff%20Pairs%20in%20an%20Array.cpp)
- 給定數組`nums`與一數`k`，輸出`nums`中數對相差為`k`的數量
- 技巧：排序＋雙指針

## [535. Encode and Decode TinyURL](https://leetcode.com/problems/encode-and-decode-tinyurl/) - [Solution](/Problems/535.%20Encode%20and%20Decode%20TinyURL.cpp)
- 對`longUrl`編碼為`shortUrl`、對`shortUrl`解碼為`longUrl`
- 技巧：hash table 應用

## [665. Non-decreasing Array](https://leetcode.com/problems/non-decreasing-array/) - [Solution](/Problems/665.%20Non-decreasing%20Array.cpp)
- 給定數組`nums`，判斷是否可以在**最多改變一個元素**的前提下，使該數組形成非遞減序列
- 技巧：列舉可能回傳`false`的情況
    1. 出現兩組`nums[i]>nums[i+1]`
    2. 僅出現一組`nums[i]>nums[i+1]`，但無法僅改變一個元素獲得非遞減序列：Ex. `[3, 4, 1, 2]`

## [710. Random Pick with Blacklist](https://leetcode.com/problems/random-pick-with-blacklist/) - [Solution](/Problems/710.%20Random%20Pick%20with%20Blacklist.cpp)
- 給定一數`n`與數組`blacklist`，`pick`等機率回傳`[0, n-1]`區間內的白名單數字
- 技巧：隨機選取`[0, (n-1)-(blacklist.size())]`區間內的數＋**映射**
    - `unordered_set`（hash table）存取黑名單
    - `unordered_map`存取黑名單→白名單的映射
    - 選取的數字若在黑名單，則使用映射轉為白名單數字


## [719. Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/) - [Solution](Problems/719.%20Find%20K-th%20Smallest%20Pair%20Distance.cpp)
- 給定數組`nums`與一數`k`，輸出其中第`k`小的數對差
    - 數對差：`nums`中選取兩數的距離
- 技巧：排序後，二分查找＋雙指針
    - 對每一個`mid`，計算小於`mid`的數對差有幾個

## [729. My Calendar I](https://leetcode.com/problems/my-calendar-i/) - [Solution](Problems/729.%20My%20Calendar%20I.cpp)
- 對給定的預定時間回傳是否有重複預定的情況
- 技巧：使用`set`紀錄、查找
    - [其他做法](https://leetcode.cn/problems/my-calendar-i/solution/wo-de-ri-cheng-an-pai-biao-i-by-leetcode-nlxr/)


## [732. My Calendar III](https://leetcode.com/problems/my-calendar-iii/) - [Solution](/Problems/732.%20My%20Calendar%20III.cpp)
- 給一組預定時間，對每一個`[start, end)`輸出當前所有預定時間的最大同時預定數量
- 技巧：`map`，對`start`加一、對`end`減一

## [820. Short Encoding of Words]() - [Solution](/Problems/820.%20Short%20Encoding%20of%20Words.cpp)
- 對給定字詞組`words`進行編碼，規則如下，輸出`s`的最小長度
    - `s`以`#`結尾
    - 對`indices[i]`，`s`從`indices[i]`到第一個`#`出現前的所有字母形成的字詞＝`words[i]`
- 技巧：
    - 從尾端照字典排序
    - 檢查`words[i-1]`是否為`words[i]`的後綴，若否則`s`新增`words[i-1]`＋`#`
    <!-- - 其他做法：字典樹 -->

## [829. Consecutive Numbers Sum](https://leetcode.com/problems/consecutive-numbers-sum/) - [Solution](/Problems/829_Consecutive_Numbers_Sum.cpp)
- 給定一數`n`，求連續正整數和為`n`的組數
- 技巧：從`x`到`x+k-1`（`k`個數），和為`n`
    - `(2x+k-1)*k=2n` → 對可整除`2n`的`k`，求出是否存在正整數`x`滿足此式

## [867. Transpose Matrix](https://leetcode.com/problems/transpose-matrix/) - [Solution](/Problems/867_Transpose_Matrix.cpp)
- 給定矩陣`matrix`，輸出轉置（transpose）矩陣

## [875. Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) - [Solution](/Problems/875.%20Koko%20Eating%20Bananas.cpp)
- 給定數列`piles`與`h`，`piles[i]`代表第`i`堆香蕉數量。每小時可吃`k`根香蕉，吃完一堆後下一小時才可吃下一堆。求在`h`小時內吃完所有香蕉的最小`k`值。
- 技巧：二分查找
    - 對每一次更新速度`speed`，計算吃完所需時間，若`<=h`則更新`high`，否則更新`low`

## [929. Unique Email Addresses](https://leetcode.com/problems/unique-email-addresses/) - [Solution](/Problems/929_Unique_Email_Addresses.cpp)
- 給定一組郵件地址`emails`，判斷其中有多少個不同的地址
    - 郵件地址分為`local`與`domain`
        - `local`：由英文小寫字母與`.`、`+`組成，遇`.`忽略，遇`+`忽略其後所有字母符號
        - `domain`：由英文小寫字母與`.`組成，組成不同則不同

## [968. Binary Tree Cameras](https://leetcode.com/problems/binary-tree-cameras/) - [Solution]()
- 給定二元樹的根節點`root`，輸出所需的最小監視器數量
    - 監視器：可以監控父節點、自己、子節點
- 技巧：`dfs`邊遍歷邊更新結果
    - 若兩個子節點有其中一個沒有被監控，則該節點須安裝監視器（`0`）
    - 若兩個子節點有其中一個有安裝監視器，則該節點為無安裝但有被監控（`1`）
    - 其他狀況：沒有被監控（`2`）

## [1037. Valid Boomerang](https://leetcode.com/problems/valid-boomerang/) - [Solution](/Problems/1037.%20Valid%20Boomerang.cpp)
- 給定一個點數組`points`，分別代表`x-y`平面上的座標，判斷三點是否不在同一線上
- 技巧：座標比例判斷

## [1048. Longest String Chain](https://leetcode.com/problems/longest-string-chain/) - [Solution](/Problems/1048.%20Longest%20String%20Chain.cpp)
- 給定一串字符`words`，判斷可以由其中元素組成的字符串最長長度
    - 若可以在不改變字符順序的前提下，對`words[a]`插入一個字符使其變為`words[b]`，則稱`words[a]`為`words[b]`的前身
- 技巧：排序後，動態規劃＋雙指針


## [1051. Height Checker](https://leetcode.com/problems/height-checker/)
- 對給定數組`heights`，輸出原數組與排序後數組不同位置的元素數量
- 技巧：注意`1 <= heights[i] <= 100`，直接使用`vector`存取所有高度數量
    - 利用前綴和算出該高度的 index 值應為何

## [1089. Duplicate Zeros](https://leetcode.com/problems/duplicate-zeros/submissions/) - [Solution](/Problems/1089.%20Duplicate%20Zeros.cpp)
- 給定長度固定的數組`arr`，將其中`0`的元素複寫，其餘元素順移。
- 對給定數組`arr`改動，不能改變`arr`長度
- 技巧：計算最末元素位置＋雙指針

## [1108. Defanging an IP Address](https://leetcode.com/problems/defanging-an-ip-address/) - [Solution](/Problems/1108.%20Defanging%20an%20IP%20Address.cpp)
- 給定`address`，將其中的`.`變為`[.]`

## [1710. Maximum Units on a Truck](https://leetcode.com/problems/maximum-units-on-a-truck/) - [Solution](Problems/1710.%20Maximum%20Units%20on%20a%20Truck.cpp)
- 給定數組`boxTypes`（`boxTypes[i]=[numberOfBoxes, numberOfUnitsPerBox]`）與一數`truckSize`代表箱子數，回傳最大可裝載數量
    - `numberOfBoxes`：第`i`種物品最多可有幾箱
    - `numberOfUnitsPerBox`：第`i`種物品一箱可放的數量
- 技巧：排序＋動態規劃（greedy）

## [1175. Prime Arrangements](https://leetcode.com/problems/prime-arrangements/) - [Solution](Problems/1175.%20Prime%20Arrangements.cpp)
- 給定數字`n`，求滿足「質數位置為質數值」的排序方法數（對`1e9+7`取餘數）
- 技巧：假設有`x`個質數，答案為`(x)!(n-x)!`

## [1200. Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/) - [Solution](Problems/1200.%20Minimum%20Absolute%20Difference.cpp)
- 給定數組`nums`，求所有具有最小絕對差值的數對（升序排列）
- 技巧：排序＋遍歷

## [1332. Remove Palindromic Subsequences](https://leetcode.com/problems/remove-palindromic-subsequences/) - [Solution](/Problems/1332.%20Remove%20Palindromic%20Subsequences.cpp)
- 給定一個僅由`a`、`b`組成的字串`s`，判斷最少需要移除幾個**回文子字串**才能使`s`變為空字串
    - 子字串：**不改變順序**下刪除字符形成的字串
- 技巧：由於只包含兩種字符，最多只需要刪除兩次（分別刪除同字符組成的子字串）

## [1354. Construct Target Array With Multiple Sums]() - [Solution](/Problems/1354.%20Construct%20Target%20Array%20With%20Multiple%20Sums.cpp)
- 給定一數組`target`，判斷是否可以由一串元素皆為`1`的數組`arr`演化為`target`，演化的定義如下：
    - 令`arr`的所有元素和為`x`
    - 在`arr`中其中一個元素變為`x`
    - 重複以上步驟
- 技巧：逆推
    - 如果存在很大的數（即，對同一位置操作多次），在該元素值小於當前其餘元素總和前都會是最大值，因此**使用`%`（取餘數）**
    - 注意`sum`有可能會溢位：使用`long long`
## [1423. Maximum Points You Can Obtain from Cards]() - [Solution](/Problems/1423.%20Maximum%20Points%20You%20Can%20Obtain%20from%20Cards.cpp)
- 給定數組`cardPoints`與一數`k`，`cardPoints[i]`代表第`i`張牌的分數。每一步可以拿取最末或最前的牌，輸出拿取`k`張牌可達到的最大分數
- 技巧：
    - 滑動窗口：剩下的一定是`cardPoints.size()-k`張**連續**卡牌

## [1642. Furthest Building You Can Reach](https://leetcode.com/problems/furthest-building-you-can-reach/) - [Solution](/Problems/1642.%20Furthest%20Building%20You%20Can%20Reach.cpp)
- 給定大樓高度`heights`、磚塊數量`bricks`、梯子數量`ladders`，輸出最遠可以到第幾棟大樓（從`0`開始）
    - 若`heights[i]<heights[i+1]`，則可以直接到第`i+1`棟大樓
    - 若否，則可以使用梯子或高度差對應數量的磚塊
-　技巧：
    - 優先使用磚塊
    - 使用`priority_queue`存取各棟間須使用的磚塊數量
    - 當磚塊用量超過持有數量，則以梯子取代使用過的磚塊中的最大值

## [1647. Minimum Deletions to Make Character Frequencies Unique](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/) - [Solution](Problems/1647.%20Minimum%20Deletions%20to%20Make%20Character%20Frequencies%20Unique.cpp)
- 給定僅包含小寫字母的字串`s`，求最少需要刪掉幾個字符才能達成「`s`內每一個字母出現次數皆不同」的條件
- 技巧：計數＋排序＋貪心

## [Offer II 091. 粉刷房子]() - [Solution](/Problems/Offer%20II%20091.%20%E7%B2%89%E5%88%B7%E6%88%BF%E5%AD%90.cpp)
- 給定數組`costs`，`costs[i][j]`代表第`i`棟房子塗上第`j`個顏色的花費，求滿足**相鄰不同色**的最小花費
    - 顏色有三種：紅色、藍色、綠色
- 技巧：動態規劃
    - 在計算顏色的時候**使用分別`+1`、`+2`再對`3`取餘數的方式**保證選到的是不同顏色

