# coding = utf-8
def format_str_txt():
    file1 = open('text3.txt', 'r', encoding='utf-8') 
    file2 = open('text5.txt', 'w', encoding='utf-8') 
    lastline = ""
    cnt = 0
    try:
        for line in file1.readlines():
            if line == '\n':
                line = line.strip("\n")
            if line.count('-->') != 0:
                continue
            if line.replace('\n','').isnumeric():
                continue
            newline = line
            if lastline != '':
                newline = lastline + " " + line
            if len(newline) >= 80:
                newline = newline.replace('\n','') + '\n'
                lastline = ''
                cnt = cnt + 1
                if cnt % 10 == 0:
                    newline = newline + '\n'
                file2.write(newline)
                newline = ''
            else:
                lastline = newline
    finally:
        file1.close()
        file2.close()


if __name__ == '__main__':
    format_str_txt()
