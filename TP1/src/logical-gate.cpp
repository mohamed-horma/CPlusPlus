#include <iostream>


bool logical_gate(bool a, bool b){
    
    static bool state[4] = {false, false, false, true};
    int index = int(a)*2 + int(b);
    
    return state[index];
}