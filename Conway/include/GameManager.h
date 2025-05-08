#include <vector>

class GameManager {
    public:
        GameManager(int size);
        
        void update();
        void render();

        int getBorderCellCount(int x, int y);
    
    private:
        int size;
        std::vector<std::vector<bool>> matrix;
};