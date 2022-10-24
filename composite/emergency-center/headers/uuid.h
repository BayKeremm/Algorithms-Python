#ifndef UUID_H
#define UUID_H

#include <string>

union UUID_t{
    __int128 val;
    unsigned char c[16];
};


class Uuid{
    private:
        UUID_t id;
    public:
        Uuid();
        bool operator==(Uuid&);
        friend std::ostream& operator<<(std::ostream&, const Uuid&);
};


#endif // UUID_H
