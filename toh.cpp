#include <graphics.h>
#include <conio.h>
#include <stack>
#include <vector>

using namespace std;

// Constants for the game
const int NUM_DISKS = 3;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int PEG_X[3] = {200, 400, 600};
const int PEG_Y = 500; // Adjusted for larger window size
const int DISK_HEIGHT = 20;
const int BASE_WIDTH = 200;  // Base width of the largest disk
const int PEG_HEIGHT = 300;  // Adjusted for larger window size

class Disk {
public:
    int size;
    Disk() : size(0) {}
    Disk(int s) : size(s) {}
};

class Peg {
public:
    stack<Disk> disks;

    void push(Disk disk) {
        disks.push(disk);
    }

    Disk pop() {
        Disk topDisk = disks.top();
        disks.pop();
        return topDisk;
    }

    Disk top() {
        return disks.top();
    }

    bool empty() {
        return disks.empty();
    }

    int getHeight() {
        return disks.size();
    }
};

class TowerOfHanoi {
private:
    Peg pegs[3];
    int selectedPeg;
    Disk diskToMove;
    bool isDragging;
    int mouseX, mouseY;
    int moveCount;
    bool isComputerMode;
    int numDisks;

public:
    TowerOfHanoi(int numDisks, bool isComputerMode) 
        : selectedPeg(-1), isDragging(false), diskToMove(Disk(0)), moveCount(0), isComputerMode(isComputerMode), numDisks(numDisks) {
        initializeGame();
    }

    void initializeGame() {
        for (int i = numDisks; i >= 1; --i) {
            pegs[0].push(Disk(i));
        }
        if (isComputerMode) {
            solveHanoi(numDisks, 0, 2, 1);
        }
    }

    void drawPegs() {
        for (int i = 0; i < 3; ++i) {
            setcolor(WHITE);
            line(PEG_X[i], PEG_Y, PEG_X[i], PEG_Y - PEG_HEIGHT);
        }
    }

    void drawDisks() {
        for (int i = 0; i < 3; ++i) {
            stack<Disk> temp = pegs[i].disks;
            int height = PEG_Y;
            while (!temp.empty()) {
                Disk disk = temp.top();
                temp.pop();
                int width = BASE_WIDTH - disk.size * 40;
                setfillstyle(SOLID_FILL, i + 2);  // Different color for each peg
                bar(PEG_X[i] - width / 2, height - DISK_HEIGHT, PEG_X[i] + width / 2, height);
                rectangle(PEG_X[i] - width / 2, height - DISK_HEIGHT, PEG_X[i] + width / 2, height);
                height -= DISK_HEIGHT;
            }
        }
    }

    void drawMoveCount() {
        char moveStr[20];
        sprintf(moveStr, "Moves: %d", moveCount);
        setcolor(WHITE);
        outtextxy(10, 10, moveStr);
    }

    void drawCompletionMessage() {
        if (pegs[2].getHeight() == numDisks) {
            setcolor(WHITE);
            outtextxy(WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2, "Game Completed!");
        }
    }

    int findPeg(int x, int y) {
        for (int i = 0; i < 3; ++i) {
            if (x >= PEG_X[i] - BASE_WIDTH / 2 && x <= PEG_X[i] + BASE_WIDTH / 2) {
                return i;
            }
        }
        return -1;
    }

    // void handleMouseEvents() {
    //     if (ismouseclick(WM_LBUTTONDOWN)) {
    //         getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
    //         selectedPeg = findPeg(mouseX, mouseY);
    //         if (selectedPeg != -1 && !pegs[selectedPeg].empty()) {
    //             diskToMove = pegs[selectedPeg].pop();
    //             isDragging = true;
    //         }
    //         clearmouseclick(WM_LBUTTONDOWN);
    //     }

    //     if (isDragging) {
    //         mouseX = mousex();
    //         mouseY = mousey();
    //         cleardevice();
    //         drawPegs();
    //         drawDisks();
    //         drawMoveCount();

    //         // Draw the disk being dragged
    //         int width = BASE_WIDTH - diskToMove.size * 40;
    //         setfillstyle(SOLID_FILL, 4);  // Color for the dragged disk
    //         bar(mouseX - width / 2, mouseY - DISK_HEIGHT / 2, mouseX + width / 2, mouseY + DISK_HEIGHT / 2);
    //         rectangle(mouseX - width / 2, mouseY - DISK_HEIGHT / 2, mouseX + width / 2, mouseY + DISK_HEIGHT / 2);
    //     }

    //     if (ismouseclick(WM_LBUTTONUP)) {
    //         getmouseclick(WM_LBUTTONUP, mouseX, mouseY);
    //         int targetPeg = findPeg(mouseX, mouseY);
    //         if (targetPeg != -1 && (pegs[targetPeg].empty() || pegs[targetPeg].top().size > diskToMove.size)) {
    //             pegs[targetPeg].push(diskToMove);
    //             moveCount++;
    //         } else {
    //             pegs[selectedPeg].push(diskToMove);  // Return the disk to the original peg if move is invalid
    //         }
    //         isDragging = false;
    //         clearmouseclick(WM_LBUTTONUP);
    //     }
    // }
void handleMouseEvents() {
    if (ismouseclick(WM_LBUTTONDOWN)) {
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
        selectedPeg = findPeg(mouseX, mouseY);
        if (selectedPeg != -1 && !pegs[selectedPeg].empty()) {
            diskToMove = pegs[selectedPeg].top();  // Get the top disk to check size
            pegs[selectedPeg].pop();  // Remove from stack temporarily
            isDragging = true;
        }
        clearmouseclick(WM_LBUTTONDOWN);
    }

    if (isDragging) {
        mouseX = mousex();
        mouseY = mousey();
        cleardevice();
        drawPegs();
        drawDisks();
        drawMoveCount();

        // Draw the disk being dragged
        int width = BASE_WIDTH - diskToMove.size * 40;
        setfillstyle(SOLID_FILL, 4);  // Color for the dragged disk
        bar(mouseX - width / 2, mouseY - DISK_HEIGHT / 2, mouseX + width / 2, mouseY + DISK_HEIGHT / 2);
        rectangle(mouseX - width / 2, mouseY - DISK_HEIGHT / 2, mouseX + width / 2, mouseY + DISK_HEIGHT / 2);

        // Draw remaining disks on the selected peg
        stack<Disk> temp = pegs[selectedPeg].disks;
        int height = PEG_Y;
        while (!temp.empty()) {
            Disk disk = temp.top();
            temp.pop();
            if (disk.size != diskToMove.size) {
                int width = BASE_WIDTH - disk.size * 40;
                setfillstyle(SOLID_FILL, selectedPeg + 2);  // Different color for each peg
                bar(PEG_X[selectedPeg] - width / 2, height - DISK_HEIGHT, PEG_X[selectedPeg] + width / 2, height);
                rectangle(PEG_X[selectedPeg] - width / 2, height - DISK_HEIGHT, PEG_X[selectedPeg] + width / 2, height);
            }
            height -= DISK_HEIGHT;
        }
    }

    if (ismouseclick(WM_LBUTTONUP)) {
        getmouseclick(WM_LBUTTONUP, mouseX, mouseY);
        int targetPeg = findPeg(mouseX, mouseY);
        if (targetPeg != -1 && (pegs[targetPeg].empty() || pegs[targetPeg].top().size > diskToMove.size)) {
            pegs[targetPeg].push(diskToMove);
            moveCount++;
        } else {
            pegs[selectedPeg].push(diskToMove);  // Return the disk to the original peg if move is invalid
        }
        isDragging = false;
        clearmouseclick(WM_LBUTTONUP);
    }
}

    void moveDisk(int from, int to) {
        cleardevice();
        Disk disk = pegs[from].pop();
        pegs[to].push(disk);
        moveCount++;
        drawPegs();
        drawDisks();
        drawMoveCount();
        delay(500);  // Animation delay
    }

    void solveHanoi(int n, int from, int to, int aux) {
        if (n == 1) {
            moveDisk(from, to);
            return;
        }
        solveHanoi(n - 1, from, aux, to);
        moveDisk(from, to);
        solveHanoi(n - 1, aux, to, from);
    }

    void run() {
        while (1) {
            // Clear screen and draw the pegs and disks
            cleardevice();
            drawPegs();
            drawDisks();
            drawMoveCount();
            drawCompletionMessage();
            if (!isComputerMode) {
                handleMouseEvents();
            }

            // Break the loop if a key is pressed
            if (kbhit()) {
                break;
            }

            delay(10);  // Small delay to reduce CPU usage
        }

        // Close the graphics mode
        closegraph();
    }
};

void drawButton(int x, int y, int width, int height, const char* text) {
    setcolor(WHITE);
    rectangle(x, y, x + width, y + height);
    int textX = x + (width - textwidth((char*)text)) / 2;  // Cast to char*
    int textY = y + (height - textheight((char*)text)) / 2;  // Cast to char*
    outtextxy(textX, textY, (char*)text);  // Cast to char*
}

void displayMenu() {
    setcolor(WHITE);
    outtextxy(WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 - 60, (char*)"Tower of Hanoi");  // Cast to char*
    drawButton(WINDOW_WIDTH / 2 - 75, WINDOW_HEIGHT / 2 - 30, 150, 30, "User Mode");
    drawButton(WINDOW_WIDTH / 2 - 75, WINDOW_HEIGHT / 2 + 10, 150, 30, "Computer Mode");
}

int main() {
    // Initialize graphics mode with larger window size
    int gd = DETECT, gm;
    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT);

    // Display menu
    displayMenu();

    bool isUserMode = true;
    bool isOptionSelected = false;

    while (!isOptionSelected) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);

            if (x >= WINDOW_WIDTH / 2 - 75 && x <= WINDOW_WIDTH / 2 + 75) {
                if (y >= WINDOW_HEIGHT / 2 - 30 && y <= WINDOW_HEIGHT / 2) {
                    isUserMode = true;
                    isOptionSelected = true;
                } else if (y >= WINDOW_HEIGHT / 2 + 10 && y <= WINDOW_HEIGHT / 2 + 40) {
                    isUserMode = false;
                    isOptionSelected = true;
                }
            }
        }
        delay(10);
    }

    // Create and run the Tower of Hanoi game
    TowerOfHanoi game(NUM_DISKS, !isUserMode);
    game.run();

    return 0;
}
