#include <stdlib.h>
#include <stdio.h>

#define LOW_LIMIT 100
#define UP_LIMIT 99999
#define SEED time(NULL)

double getRandomNumber(double lower_limit, double upper_limit);
double calculatePi(int max_iteration);

int main()
{
    int num = getRandomNumber(LOW_LIMIT, UP_LIMIT);

    double estimated_pi = calculatePi(num);

    printf("%f is the calculated pi value", estimated_pi);

    return EXIT_SUCCESS;
}

double getRandomNumber(double lower_limit, double upper_limit)
{
    srand(SEED);
    int randomized_num = rand() % (UP_LIMIT +1 - LOW_LIMIT) + LOW_LIMIT;
    return randomized_num;
}

double calculatePi(int max_iteration)
{
    int count_inside=0;
    for(int i=0 ;i<max_iteration;i++)
    {
        double x = (double)rand()/RAND_MAX;
        double y = (double)rand()/RAND_MAX;
        if(x*x + y*y <= 1)
        {
            count_inside++;
        }
    }
    double calculated_pi = (double)count_inside / (double)max_iteration * 4;
    return calculated_pi;
}
