#include <iostream>

#include <cstdio>

#include <cstring>

using namespace std;

const int MAXNODES = 10, INF = 9999;

void fnDijkstra(int[][MAXNODES], int[], int[], int[], int, int, int);

int main()

{

    int n, cost[MAXNODES][MAXNODES], dist[MAXNODES], visited[MAXNODES], path[MAXNODES], i, j, source, dest, flag1 = 0, flag2 = 0, choice;

    char city[20][20], src[20], dst[20];

    cout << "\nEnter the number of cities: ";

    cin >> n;

    cout << "\nEnter the names of " << n << " cities: \n";

    for (i = 0; i < n; i++)

        std::cin >> city[i];

    cout << "\nEnter distance of one city to another in the order given (Enter 0 for same city and 9999 if the city is not reachable): \n";

    for (i = 0; i < n; i++)

    {

        cout << "\nEnter distance of " << city[i] << " from all cities: \n";

        for (j = 0; j < n; j++)

            cin >> cost[i][j];
    }

    while (1)

    {

        cout << "\n\n1.Open Dijkstra\n2.Exit";

        cout << "\nEnter your choice: ";

        cin >> choice;

        switch (choice)

        {

        case 1:
            cout << "\nEnter the source city: " << endl;

            cin >> src;

            for (i = 0; i < n; i++)

            {

                if (strcmp(src, city[i]) == 0)

                {

                    source = i;

                    flag1 = 1;
                }
            }

            if (flag1 == 0)

            {

                cout << "\nEntered source city is not mentioned in the list.";

                cout << "\nEnter the source city: " << endl;

                cin >> src;

                for (i = 0; i < n; i++)

                {

                    if (strcmp(src, city[i]) == 0)

                    {

                        source = i;

                        flag1 = 1;
                    }
                }
            }

            cout << "\nEnter the destination city: " << endl;

            cin >> dst;

            for (i = 0; i < n; i++)

            {

                if (strcmp(dst, city[i]) == 0)

                {

                    dest = i;

                    flag2 = 1;
                }
            }

            if (flag2 == 0)

            {

                cout << "\nEntered destination city is not mentioned in the list.";

                cout << "\nEnter the destination city: " << endl;

                cin >> dst;

                for (i = 0; i < n; i++)

                {

                    if (strcmp(dst, city[i]) == 0)

                    {

                        dest = i;

                        flag2 = 1;
                    }
                }
            }

            cout << "\nThe path of shortest distance is: \n";

            fnDijkstra(cost, dist, path, visited, source, dest, n);

            if (dist[dest] == INF)

                cout << dest << " not reachable" << endl;

            else

            {

                cout << endl;

                i = dest;

                do

                {

                    cout << city[i] << "<--";

                    i = path[i];

                } while (i != source);

                cout << city[i];

                cout << "\n\nThe shortest path distance is: " << dist[dest] << " km" << endl;
            }

            break;

        case 2:
            exit(0);
        }
    }

    return 0;
}

void fnDijkstra(int c[MAXNODES][MAXNODES], int d[MAXNODES], int p[MAXNODES], int s[MAXNODES], int so, int de, int n)

{

    int i, j, a, b, min;

    for (i = 0; i < n; i++)

    {

        s[i] = 0;

        d[i] = c[so][i];

        p[i] = so;
    }

    s[so] = 1;

    for (i = 1; i < n; i++)

    {

        min = INF;

        a = -1;

        for (j = 0; j < n; j++)

        {

            if (s[j] == 0)

            {

                if (d[j] < min)

                {

                    min = d[j];

                    a = j;
                }
            }
        }

        if (a == -1)

            return;

        s[a] = 1;

        if (a == de)

            return;

        for (b = 0; b < n; b++)

        {

            if (s[b] == 0)

            {

                if (d[a] + c[a][b] < d[b])

                {

                    d[b] = d[a] + c[a][b];

                    p[b] = a;
                }
            }
        }
    }
}