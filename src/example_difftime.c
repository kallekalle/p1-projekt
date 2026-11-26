/*
The standard C library <time.h> includes difftime(), which calculates the time difference in seconds between two dates.
You can represent dates using struct tm, convert them to time_t with mktime(), and find the difference using difftime(). Dividing the resulting seconds by 86400 (60 * 60 * 24) gives the number of days
*/

#include <stdio.h>
#include <time.h>

int main(void) {
    // Note: tm_year is years since 1900, tm_mon is 0-indexed (0 = Jan)
    struct tm date1 = { .tm_year = 2026 - 1900, .tm_mon = 10, .tm_mday = 1, .tm_hour = 12 };
    struct tm date2 = { .tm_year = 2026 - 1900, .tm_mon = 10, .tm_mday = 26, .tm_hour = 12 };

    time_t t1 = mktime(&date1);
    time_t t2 = mktime(&date2);

    // difftime returns the difference in seconds
    double seconds = difftime(t2, t1);
    double days = seconds / (60 * 60 * 24);

    printf("Days between: %.0f\n", days);
    return 0;
}
