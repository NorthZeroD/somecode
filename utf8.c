#include <stdio.h>
#include <string.h>
#include <stdint.h>

static const uint8_t utf8_byte_count_map[] = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3, 4,4,4,4,4,4,4,4,5,5,5,5,6,6,6,6,
};

size_t u8chbc(const char *s) {
    return utf8_byte_count_map[(uint8_t)*s];
}

size_t u8strlen(const char *s) {
    size_t cnt = 0;
    while (*s != 0) {
        ++cnt;
        s += u8chbc(s);
    }
    return cnt;
}

void pchs(const char *s) {
    printf("%s -> %zu => %zu\n", s, strlen(s), u8strlen(s));
}

int main() {
    const char *s = "你";
    pchs(s);
    const char *s1 = "𰻞";
    pchs(s1);

    const char *s2 = "12345";
    pchs(s2);
    const char *s3 = "今天是个好日子";
    pchs(s3);
    const char *s4 = "🤓";
    pchs(s4);

    const char *ss = "👨‍👩‍👧‍👦"; // Emoji ZWJ Sequence
    pchs(ss);
    while (*ss != 0) {
        size_t n = u8chbc(ss);
        static char buf[8];
        snprintf(buf, n + 1, "%s", ss);
        printf("%s (", buf);
        for (size_t i = 0; i < n; ++i) {
            printf(" %hhX", buf[i]);
        }
        printf(" ) -> %zu\n", n);
        ss += n;
    }
    return 0;
}
