#include <iostream>
#include <vector>
#include <map>

void print_cube(const std::vector< std::vector< std::vector<int> > >&  cube) {
    for (const auto& item : cube) {
        for (const auto& item1 : item) {
            for (const auto& item2 : item1) {
                std::cout << item2 << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
void change_L_angle(std::vector<int> &step, char ax, std::vector<int> &idx) {
    if (ax == 'z') {
        int tmp = step[1];
        if (idx[0] == 0) {
            step[1] = step[2];
            step[2] = -tmp;
        } else {
            step[1] = -step[2];
            step[2] = tmp;
        }
    }
    if (ax == 'x') {
        int tmp = step[0];
        if (idx[2] == 0) {
            step[0] = step[1];
            step[1] = -tmp;
        } else {
            step[0] = -step[1];
            step[1] = tmp;
        }
    }
    if (ax == 'y') {
        int tmp = step[0];
        if (idx[1] == 2) {
            step[0] = step[2];
            step[2] = -tmp;
        } else {
            step[0] = -step[2];
            step[2] = tmp;
        }
    }
}

void change_R_angle(std::vector<int> &step, char ax, std::vector<int> &idx) {
    if (ax == 'z') {
        int tmp = step[1];
        if (idx[0] == 0) {
            step[1] = -step[2];
            step[2] = tmp;
        } else {
            step[1] = step[2];
            step[2] = -tmp;
        }
    }
    if (ax == 'x') {
        int tmp = step[0];
        if (idx[2] == 0) {
            step[0] = -step[1];
            step[1] = tmp;
        } else {
            step[0] = step[1];
            step[1] = -tmp;
        }
    }
    if (ax == 'y') {
        int tmp = step[0];
        if (idx[1] == 2) {
            step[0] = -step[2];
            step[2] = tmp; 
        } else {
            step[0] = step[2];
            step[2] = -tmp;
        }
    }
}

void change_cube(std::vector< std::vector< std::vector<int> > >& cb, int &count, 
                std::vector<int> &idx, std::vector<int> &step, char &ax) {
    cb[idx[0]][idx[1]][idx[2]] = 1;
    char c;
    while ((c = std::cin.get()) != 'S') {
        if (c == 'L') {
            change_L_angle(step, ax, idx);
        }
        if (c == 'R') {
            change_R_angle(step, ax, idx);
        }
        //std::cout << c << ' ' << step[0] << ' '<<step[1]<<' '<<step[2]<<std::endl;
        if (c == 'F') {
            if ((idx[0] + step[0] < 3) && (idx[0] + step[0] >= 0)) {
                if ((idx[1] + step[1] < 3) && (idx[1] + step[1] >= 0)) {
                    if ((idx[2] + step[2] < 3) && (idx[2] + step[2] >= 0)) {
                        idx[0] += step[0];
                        idx[1] += step[1];
                        idx[2] += step[2];  
                        if (!cb[idx[0]][2 - idx[1]][idx[2]]) {
                            ++count;
                        }
                        cb[idx[0]][2 - idx[1]][idx[2]] = 1;
                    } else {
                        if (ax == 'z') {
                            if (idx[0] == 0) {
                                step[0] = 1;
                            } else {
                                step[0] = -1;
                            }
                        }
                        if (ax == 'y') {
                            if (idx[1] == 0) {
                                step[1] = 1;
                            } else {
                                step[1] = -1;
                            }
                        }
                        ax = 'x';
                        step[2] = 0;
                    }
                } else {
                    if (ax == 'z') {
                        if (idx[0] == 0) {
                            step[0] = 1;
                        } else {
                            step[0] = -1;
                        }
                    }
                    if (ax == 'x') {
                        if (idx[2] == 0) {
                            step[2] = 1;
                        } else {
                            step[2] = -1;
                        }
                    }
                    ax = 'y';
                    step[1] = 0;
                }
            } else {
                if (ax == 'y') {
                    if (idx[1] == 0) {
                        step[1] = 1;
                    } else {
                        step[1] = -1;
                    }
                }
                if (ax == 'x') {
                    if (idx[2] == 0) {
                        step[2] = 1;
                    } else {
                        step[2] = -1;
                    }
                }
                ax = 'z';
                step[0] = 0;
            }
        //std::cout << ax <<' '<< "Z=" <<idx[0]<<"; Y="<<idx[1]<<"; X="<<idx[2]<<std::endl; 
        }
    }
}

int main() {
    std::vector<int> step{0, 1, 0};
    std::vector<int> idx{0, 1, 1};
    int count = 1;
    char ax = 'z';
    std::vector< std::vector< std::vector<int> > > cube(3, 
    std::vector<std::vector<int> > (3, std::vector<int> (3, 0)));
    change_cube(cube, count, idx, step, ax);
    std::cout << count << std::endl;
    //print_cube(cube);

    return 0;
}
