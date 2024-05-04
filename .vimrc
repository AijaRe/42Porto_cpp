function! CppClass(class_name)
    let hpp_file_name = a:class_name . '.hpp'
    let cpp_file_name = a:class_name . '.cpp'

    " Check if header file exists
    if filereadable(hpp_file_name) || filereadable(cpp_file_name)
        echomsg "Files already exist: " . hpp_file_name . ", " . cpp_file_name
        return
    endif

    let class_definition = [
        \ '#ifndef ' . toupper(a:class_name) . '_HPP',
        \ '#define ' . toupper(a:class_name) . '_HPP',
        \ '',
        \ '#include <iostream>',
        \ '',
        \ 'class ' . a:class_name,
        \ '{',
        \ 'private:',
        \ '    // Private members',
        \ '',
        \ 'public:',
        \ '    ' . a:class_name . '(void);',
        \ '    ' . a:class_name . '(' . a:class_name .' const & src);',
        \ '    ~' . a:class_name . '(void);',
        \ '    ' . a:class_name . ' & operator=(' . a:class_name .' const & src);',
        \ '};',
        \ '',
        \ '#endif // ' . toupper(a:class_name) . '_HPP'
    \ ]

    let class_implementation = [
        \ '#include "'. a:class_name . '.hpp"',
        \ '',
        \ a:class_name . '::' . a:class_name . '(void)',
        \ '{',
        \ '    std::cout << "' . a:class_name . ' default constructor called." << std::endl;',
        \ '	return ;',
        \ '}',
        \ '',
        \ a:class_name . '::' . a:class_name . '(' . a:class_name . ' const & src)',
        \ '{',
        \ '    std::cout << "' . a:class_name . ' copy constructor called." << std::endl;',
        \ '    *this = src;',
        \ '	return ;',
        \ '}',
        \ '',
        \ a:class_name . '::~' . a:class_name . '(void)',
        \ '{',
        \ '    std::cout << "' . a:class_name . ' destructor called." << std::endl;',
        \ '	return ;',
        \ '}',
        \ '',
        \ a:class_name . ' & ' . a:class_name . '::operator=(' . a:class_name . ' const & src)',
        \ '{',
        \ '    if (this != &src)',
        \ '        *this = src;',
        \ '    return (*this);',
        \ '}'
    \ ]

    call writefile(class_definition, hpp_file_name)
    call writefile(class_implementation, cpp_file_name)

    echo "Created files: " . hpp_file_name . ", " . cpp_file_name
endfunction

command! -nargs=1 CppClass call CppClass(<f-args>)
