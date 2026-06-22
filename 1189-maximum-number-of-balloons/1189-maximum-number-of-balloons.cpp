class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string balloon = "balon";
        int f[5] = {0};

        for(auto ch : text){
            for(int i = 0; i < 5; i++){
                f[i] += !(ch ^ balloon[i]);
            }
        }
        return min({f[0], f[1], f[2] >> 1, f[3] >> 1, f[4]});

    }
};