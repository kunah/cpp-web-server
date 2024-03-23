<<<<<<< HEAD
#include <WebServer.h>
#include <HTTPMappingRegistrar.h>
#include <ProcessClasses/HTTPTextProcess.h>
#include <ProcessClasses/HTTPBinaryProcess.h>
#include "URL/PatternURL.h"
using namespace std::string_literals;

void show_regex_error(const std::regex_error& e) {
    std::string err_message = e.what();

#   define CASE(type, msg) \
    case std::regex_constants::type: err_message += " ("s + #type "):\n  "s + msg; \
        break
    switch (e.code()) {
        CASE(error_collate, "The expression contains an invalid collating element name");
        CASE(error_ctype, "The expression contains an invalid character class name");
        CASE(error_escape, "The expression contains an invalid escaped character or a trailing escape");
        CASE(error_backref, "The expression contains an invalid back reference");
        CASE(error_brack, "The expression contains mismatched square brackets ('[' and ']')");
        CASE(error_paren, "The expression contains mismatched parentheses ('(' and ')')");
        CASE(error_brace, "The expression contains mismatched curly braces ('{' and '}')");
        CASE(error_badbrace, "The expression contains an invalid range in a {} expression");
        CASE(error_range, "The expression contains an invalid character range (e.g. [b-a])");
        CASE(error_space, "There was not enough memory to convert the expression into a finite state machine");
        CASE(error_badrepeat, "one of *?+{ was not preceded by a valid regular expression");
        CASE(error_complexity, "The complexity of an attempted match exceeded a predefined level");
        CASE(error_stack, "There was not enough memory to perform a match");
    }
#   undef CASE

    std::cout << err_message << ". \n\n";
}

void regular_expression_checker(const std::string& text,
                                const std::string& regex,
                                const std::regex::flag_type flags) {
    std::cout << "Text: " << quoted(text) << "\nRegex: " << quoted(regex) << '\n';
    try {
        const std::regex re{regex, flags};
        const bool matched = std::regex_match(text, re);

        std::stringstream out;
        out << (matched ? "MATCH!\n" : "DOES NOT MATCH!\n");

        std::smatch m;
        out << "First match" << std::endl;
        if (std::regex_search(text, m, re); !m.empty()) {
            out << "prefix = [" << m.prefix().str().data() << "]\n";

            for (std::size_t i{}; i != m.size(); ++i)
                out << "  m[" << i << "] = [" << m[i].str().data() << "]\n";

            out << "suffix = [" << m.suffix().str().data() << "]\n";
        }

        out << "Multiple matches" << std::endl;
        auto words_begin = std::sregex_iterator(text.begin(), text.end(), re);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            std::regex re2(R"([[:alnum:]]+)", flags);
            std::smatch m2;
            std::string matched = match.str();
            std::regex_search(matched, m2, re2);
            out << "  " << match.str() << " content: "
                << m2[0].str()
                << '\n';
        }

        std::cout << out.str() << '\n';

    } catch (std::regex_error& ex) {
        show_regex_error(ex);
    }
}

int main() {
    constexpr std::regex::flag_type your_flags
            = std::regex::flag_type{0}
              // Choose one of the supported grammars:
              | std::regex::ECMAScript
//              | std::regex::basic
//              | std::regex::extended
//              | std::regex::awk
//              | std::regex::grep
//              | std::regex::egrep
    // Choose any of the next options:
//              | std::regex::icase
//              | std::regex::nosubs
//              | std::regex::optimize
//              | std::regex::collate
    ;

//    regular_expression_checker("/pokus/{tento}/{thisisit}", R"(\{[[:alnum:]]+\})", your_flags);
//    regular_expression_checker("/pokus/{tento}/what/{thisisit2}", R"(\{[[:alnum:]]+\})", your_flags);
//    regular_expression_checker("{tento}", R"(^\{[[:alnum:]]+\})", your_flags);
//    regular_expression_checker("/{tento}/pokus", R"((\{?[[:alnum:]]+\}?))", your_flags);
//    regular_expression_checker("/{tento}/pokus", R"(\{?[[:alnum:]]+\}?)", your_flags);

    std::map<int, std::shared_ptr<URL>> uris;

    try{
        PatternURL first("/pokus/{tento}/pokus/proste/to/{je}");
        uris[0] = std::make_shared<URL>(first);
    }
    catch(std::regex_error & err){
        show_regex_error(err);
    }
=======
#include <TestMacros.h>

int main(){

    RUN_ALL_TESTS
>>>>>>> 46092fc700e112ec85a4bc33ae113e0c8776a688

    return 0;
}