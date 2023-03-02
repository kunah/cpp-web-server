#include <TestMacros.h>
#include <HTTPParser.h>

#include <fstream>

std::istream& safeGetline(std::istream& is, std::string& t)
{
    t.clear();

    std::istream::sentry se(is, true);
    std::streambuf* sb = is.rdbuf();

    for(;;) {
        int c = sb->sbumpc();
        switch (c) {
            case '\n':
                t += (char)c;
                if(t[t.size()-2] == '\r')
                    return is;
                continue;
            case '\r':
                t += (char)c;
//                if(sb->sgetc() == '\n')
//                    sb->sbumpc();
//                return is;
                continue;
            case std::streambuf::traits_type::eof():
                // Also handle the case when the last line has no line ending
                if(t.empty())
                    is.setstate(std::ios::eofbit);
                return is;
            default:
                t += (char)c;
        }
    }
}

TEST(testHTTPParser){

    std::string filePath = "dist/Test/testHeader.txt";
    std::ifstream file(filePath);

    if(!file.is_open()){
        Logger::error("Can't open file", filePath);
        throw std::runtime_error("Can't open file " + filePath);
    }
    std::vector<unsigned char>fileInfo;
    std::string tmp;
    while(file.good()){
        safeGetline(file, tmp);
        fileInfo.insert(fileInfo.end(), tmp.begin(), tmp.end());
    }
    file.close();

    HTTPParser parser(fileInfo, fileInfo.size());

    ASSERT_EQ(parser.url, "/ahoj/face.jpg")
    ASSERT_EQ(parser.version, "HTTP/1.1")
    ASSERT_EQ(parser.header.size(), 5)
    ASSERT_EQ(parser.body.empty(), true)

}