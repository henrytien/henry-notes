


## visual studio 

- delete all blank  
    ```
    What also works is this regex pattern:

    ^\s*$\n
    Then CTRL+Enter to replace all lines.

    Explanation of the above pattern:

    -----------------------------------------------
    |  ^ | beginning of string anchor             |
    -----------------------------------------------
    | \s | any whitespace character               |
    -----------------------------------------------
    | '*'| zero or more repetitions               |
    -----------------------------------------------
    |  $ | end of string anchor                   |
    -----------------------------------------------
    | \n | new line                               |
    ---------------------------------------------
    ```
    [Visual Studio Code - delete all blank lines - regex](https://stackoverflow.com/questions/36350324/visual-studio-code-delete-all-blank-lines-regex)
