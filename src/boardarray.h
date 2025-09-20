#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            // TODO: IMPLEMENT THIS FUNCTION
            // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT
            int pos = -1;
            for(int i = 0; i < index; i++) {
                if(entry->compare(&array[i])) {
                    pos = i;
                    break;
                }
            }
            if(pos == -1){
                if(index < SIZE){
                    array[index] = *entry;
                    index++;
                }else{
                    cout << "Scoreboard is full. Entry cannot be added." << endl;
                }
                return;
            }
            if(index == SIZE) --index;
            for(int i = index; i > pos; i--){
                array[i] = array[i-1];
            }
            array[pos] = *entry;
            index++;
            
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};