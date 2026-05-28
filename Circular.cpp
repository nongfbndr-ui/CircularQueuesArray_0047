#include <iostream>
using namespace std;

class Queues
{
private:
    static const int max = 3;
    int FRONT, REAR;
    int queue_array[max];

public:
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    void insert()
    {
        int num;
        cout << "Enter a number : ";
        cin >> num;
        cout << endl;

        // cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "Queue Overflow!";
            return;
        }

        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else
        {
            // jika rear berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    void remove()
    {
        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue Underflow!";
            return;
        }
        cout << "Element deleted from the queue is: " << queue_array[FRONT] << endl;

        // cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            // jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    void display()
    {
        int FRONT_Position = FRONT;
        int REAR_Position = REAR;

        // cek apakah antrian kosong
        if (FRONT_Position == -1)
        {
            cout << "Queue is empty!";
            return;
        }

        cout << "Elements in the queue are...\n";

        // jika FRONT <= REAR, iterasi dari posisi FRONT hingga REAR
        if (FRONT_Position <= REAR_Position)
        {
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }

            cout << endl;
        }
        else
        {
            // jika FRONT <= REAR, iterasi dari posisi FRONT hingga akhir array
            while (FRONT_Position <= max - 1)
            {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }

            FRONT_Position = 0;

            // iterasi dari awal array hingga posisi REAR
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }
            cout << endl;
        }
    }
};

