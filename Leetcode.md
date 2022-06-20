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

## [160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/) - [Solution](/Problems/160.%20Intersection%20of%20Two%20Linked%20Lists.cpp)
- 給定兩個 list 的 head：`headA`、`headB`，回傳相交的起始點，若無相交則回傳`NULL`
- 技巧：雙指針（`a`、`b`），到尾則從另一個的 list 的`head`再繼續。假設`ListA`長度為`m`、`ListB`長度為`n`：
        1.  `ListA`與`ListB`**有相交**，相交長度為`c`，則令`a+c=m`、`b+c=n`：`a`、`b`各走`a+b+c`次 → `a=b`
        2.  `ListA`與`ListB`**沒有相交**：
            1.  `m=n`：`a`、`b`各走`m=n`次 → `a=b=NULL`
            2.  `m!=n`：`a`、`b`各走`m+n`次 → `a=b=NULL`

## [167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) - [Solution](/Problems/167.%20Two%20Sum%20II%20-%20Input%20Array%20Is%20Sorted.cpp)
- 給定數組`numbers`與一數`target`，回傳`numbers`中兩數和為`target`的 index：**唯一解**

## [303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) - [Solution](/Problems/303_Range_Sum_Query_Immutable.cpp)
- 給定一數組`nums`，實現求**區間**和的 function
- 技巧：預先計算好所有前綴和，再根據給的 index 求出對應值

## [304. Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/) - [Solution](/Problems/304_Range_Sum_Query_2D_Immutable.cpp)
- 相關題：[303. Range Sum Query - Immutable](#303-range-sum-query---immutable)
- 給定一數組`matrix`，實現求**區域**和的 function
- 技巧：預先計算好**二維**前綴和，再根據給的行列 index 求出對應值
    - 注意更新及回傳的加減（加上沒有的、減去重疊的）— 集合概念

## [450. Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/) - [Solution](/Problems/450_Delete_Node_in_a_BST.cpp)
- 給定一個二元樹根節點`root`與一數`key`，若`key`存在於此二元數內，則刪除並重組二元樹，回傳新的根節點
- 技巧：回溯法，在過程中記錄所尋找的點的**父節點**
    1. 對`key`節點**右**子樹的所有節點尋找最小值節點（最**左**葉節點）
    2. 對`key`節點**左**子樹的所有節點尋找最大值節點（最**右**葉節點）
    - 需注意的是，當`change_parent`（上述之父節點）與`key`節點（`target`）為同一個節點時，轉換的左右子樹會不同

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

## [532. K-diff Pairs in an Array](https://leetcode.com/problems/k-diff-pairs-in-an-array/submissions/) - [Solution](/Problems/532.%20K-diff%20Pairs%20in%20an%20Array.cpp)
- 給定數組`nums`與一數`k`，輸出`nums`中數對相差為`k`的數量
- 技巧：排序＋雙指針

## [719. Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/) - [Solution](Problems/719.%20Find%20K-th%20Smallest%20Pair%20Distance.cpp)
- 給定數組`nums`與一數`k`，輸出其中第`k`小的數對差
    - 數對差：`nums`中選取兩數的距離
- 技巧：排序後，二分查找＋雙指針
    - 對每一個`mid`，計算小於`mid`的數對差有幾個

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

## [1332. Remove Palindromic Subsequences](https://leetcode.com/problems/remove-palindromic-subsequences/) - [Solution](/Problems/1332.%20Remove%20Palindromic%20Subsequences.cpp)
- 給定一個僅由`a`、`b`組成的字串`s`，判斷最少需要移除幾個**回文子字串**才能使`s`變為空字串
    - 子字串：**不改變順序**下刪除字符形成的字串
- 技巧：由於只包含兩種字符，最多只需要刪除兩次（分別刪除同字符組成的子字串）