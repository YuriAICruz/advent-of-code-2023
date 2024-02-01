#pragma once
#include <iterator>
#include <string>

namespace core
{
    class stringUtils
    {
    public:
        class stringSplitter
        {
            class iterator : public std::iterator<std::input_iterator_tag, std::string, long, std::string*, std::string>
            {
                const std::string& delimiter;
                std::string data;
                std::string piece;
                long pos;

            public:
                explicit iterator(const std::string& rawData, const std::string& delimiter) : delimiter(delimiter),
                    pos(0)
                {
                    data = std::string{rawData};
                    iterate();
                }

                iterator& iterate()
                {
                    int pos = data.find(delimiter);
                    if (pos != std::string::npos)
                    {
                        piece = data.substr(0, pos);
                        data.erase(0, pos + delimiter.length());
                        return *this;
                    }

                    piece = std::string{data};
                    data = "";
                    return *this;
                }

                iterator& operator++()
                {
                    return iterate();
                }

                iterator operator++(int)
                {
                    iterator retval = *this;
                    ++(*this);
                    return retval;
                }

                bool operator==(iterator other) const
                {
                    return pos + data.length() + piece.length() == other.pos + other.data.length() + other.piece.
                        length();
                }

                bool operator!=(iterator other) const
                {
                    return !(*this == other);
                }

                reference operator*() const
                {
                    return piece;
                }
            };

        public:
            const std::string delimiter;
            const std::string data;

            explicit stringSplitter(const std::string& rawData, const std::string delimiter) : data(rawData),
                delimiter(delimiter)
            {
            }

            iterator begin() { return iterator(data, delimiter); }
            iterator end() { return iterator("", delimiter); }
        };

        static stringSplitter split(const std::string& rawData, const std::string& delimiter)
        {
            return stringSplitter{rawData, delimiter};
        }

        static stringSplitter split(const std::string& rawData, const char* delimiter)
        {
            return stringSplitter{rawData, delimiter};
        }
    };
}
