#include "test.h"

int main() {
    BufferOperation obj;
    obj.CreateInputBuffer();

    while (true) {
        obj.ShowPrompt();
        obj.ReadInput();
        int ret_val = obj.ProcessInput();

        if (ret_val == 0 || ret_val == 1 || ret_val == -1)
            break;

        std::cin.get();
    }
    return 0;
}
