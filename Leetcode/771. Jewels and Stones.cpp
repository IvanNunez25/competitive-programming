class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        unordered_map < char, int > my_stones;
        for ( int i = 0; i < stones.length(); i++ )
            my_stones[ stones[i] ]++;
        
        int total = 0;
        for ( int i = 0; i < jewels.length(); i++ )
            total += my_stones[ jewels[i] ];

        return total;
    }
};