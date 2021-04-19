def delete_constructor(file, old_str, new_str):
    """
    替换文件中的字符串
    :param file:文件名
    :param old_str:就字符串
    :param new_str:新字符串
    :return:

    """
    newstr = old_str
    file_data = ""
    with open(file, "r", encoding="utf-8") as f:
        it = iter(f)
        for line in it:
            if old_str in line and "new" not in line:
                while line.replace(" ", "") != '}\n':
                    old_str = line
                    line = line.replace(old_str, new_str)
                    file_data += line
                    line = next(it)
                if line.replace(" ", "") == '}\n':
                    old_str = line
                    line = line.replace(old_str, new_str)
            file_data += line
            old_str = newstr
    with open(file, "w", encoding="utf-8") as f:
        f.write(file_data)

def create_message_id(file, old_str):
    """
    替换文件中的字符串
    :param file:文件名
    :param old_str:就字符串
    :return:

    """
    newstr = old_str
    file_data = ""
    re_str = ""
    with open(file, "r", encoding="utf-8") as f:
        it = iter(f)
        for line in it:
            if old_str in line:
                file_data += line
                line = next(it)
                file_data += line
                line = next(it)
                id = 0
                while line.replace(" ", "") != '}':
                    if "//" in line:
                        file_data += line
                        line = next(it)
                        continue
                    if "=" in line:
                        file_data += line
                        line = next(it)
                        continue

                    id += 1
                    re_str = " = " + str(id) + ";"
                    line = line.replace(";", re_str)
                    file_data += line
                    line = next(it)
            file_data += line
            old_str = newstr
    with open(file, "w", encoding="utf-8") as f:
        f.write(file_data)

def create_enum_id(file, old_str):
    """
    替换文件中的字符串
    :param file:文件名
    :param old_str:就字符串
    :return:

    """
    newstr = old_str
    file_data = ""
    re_str = ""
    with open(file, "r", encoding="utf-8") as f:
        it = iter(f)
        for line in it:
            if old_str in line:
                file_data += line
                line = next(it)
                file_data += line
                line = next(it)
                
                id = -1
                temp = ""
                temp_id = ""
                while line.replace(" ", "") != '}\n':
                    if "//" in line:
                        file_data += line
                        line = next(it)
                        continue
                    if "=" in line:
                        file_data += line
                        line = next(it)
                        continue
                    id += 1
                    re_str = " = " + str(id) + ";"
                    temp_id = re_str + "\n"
                    temp_line = line.replace(",", re_str)

                    # line = line.replace(",", re_str)
                    # else:
                    #     line = line.replace("\n", re_str) + "\n"
                    if line == temp_line:
                        file_data += temp_line.replace("\n", temp_id)
                    else:
                        file_data += temp_line
                    line = next(it)
            file_data += line
            old_str = newstr
    with open(file, "w", encoding="utf-8") as f:
        f.write(file_data)

def alter_function(file, old_str, new_str):
    """
    替换文件中的字符串
    :param file:文件名
    :param old_str:就字符串
    :param new_str:新字符串
    :return:

    """
    newstr = old_str
    file_data = ""
    with open(file, "r", encoding="utf-8") as f:
        it = iter(f)
        for line in it:
            if old_str in line:
                while line.replace(" ", "") != '}\n':
                    old_str = line
                    line = line.replace(old_str, new_str)
                    file_data += line
                    line = next(it)
                if line.replace(" ", "") == '}\n':
                    old_str = line
                    line = line.replace(old_str, new_str)
            file_data += line
            old_str = newstr
    with open(file, "w", encoding="utf-8") as f:
        f.write(file_data)


def alter(file, old_str, new_str):
    """
    替换文件中的字符串
    :param file:文件名
    :param old_str:就字符串
    :param new_str:新字符串
    :return:

    """
    file_data = ""
    with open(file, "r", encoding="utf-8") as f:
        for line in f:
            if old_str in line:
                line = line.replace(old_str, new_str)
            file_data += line
    with open(file, "w", encoding="utf-8") as f:
        f.write(file_data)

def alter_message(file):
    """
    替换文件中的字符串
    :param file:文件名
    :param old_str:就字符串
    :param new_str:新字符串
    :return:

    """
    file_data = ""
    with open(file, "r", encoding="utf-8") as f:
        # it = iter(f)
        for line in f:
            for key,value in info.items():
                if key in line:
                    sd = line.replace(key, value,1)
                    file_data += sd
            file_data += line
            print(line)
        file_data += line
    with open(file, "w", encoding="utf-8") as f:
        f.write(file_data)

info = dict()

def alter_namespace(file):
    """
    替换文件中的字符串
    :param file:文件名
    :param old_str:就字符串
    :param new_str:新字符串
    :return:

    """
    file_data = ""
    with open(file, "r", encoding="utf-8") as f:
        for line in f:
            if line == "\n":
                continue
            temp = line.split("\"")
            info[temp[1]] = "global." + temp[1]
        
        print("ss")
    #         file_data += line
    # with open(file, "w", encoding="utf-8") as f:
    #     f.write(file_data)


alter_namespace("ac.txt")
alter_message("GlobalServer.proto")

def replace_empty_line(file):
    """
    替换文件中的字符串
    :param file:文件名
    :return:
    """
    file_data = ""
    with open(file, "r", encoding="utf-8") as f:
        for line in f:
            if line == '\n':
                line = line.strip("\n")
            file_data += line
    with open(file,"w",encoding="utf-8") as f:
        f.write(file_data)

def delete_line(file, old_str):
    """
    替换文件中的字符串
    :param file:文件名
    :param old_str:就字符串
    :param new_str:新字符串
    :return:

    """
    file_data = ""
    with open(file, "r", encoding="utf-8") as f:
        for line in f:
            if old_str in line:
                line = ""
            file_data += line
    with open(file, "w", encoding="utf-8") as f:
        f.write(file_data)       


# alter("ClientPackets.cs", "public sealed class", "message")
# alter("ClientPackets.cs", ": Packet", "")
# alter_function("ClientPackets.cs", "IsCanFastRead", "")
# alter_function("ClientPackets.cs", "FastWriteObject", "")
# alter_function("ClientPackets.cs", "FastReadObject", "")
# alter_function("ClientPackets.cs", "IsCanFastWirte", "")
# alter("ClientPackets.cs", "public string", "string")
# alter("ClientPackets.cs", " { get; set; }", ";")
# alter("ClientPackets.cs", "public int", "int32")
# alter("ClientPackets.cs", "public String", "string")
# alter("ClientPackets.cs", "public long", "int64")
# alter("ClientPackets.cs", "public bool", "bool")
# delete_constructor("ClientPackets.cs", "()", "")
# replace_empty_line("ClientPackets.cs")
# create_message_id("ClientPackets.cs","message")
# """
# 替换List为repeated
# """
# alter("ClientPackets.cs", "public List<", "repeated ")
# alter("ClientPackets.cs", ">", "")

# """
# 去掉最后的public
# """
# alter("ClientPackets.cs", "public", "")
# """


"""
处理global 
"""
# alter("Global.proto", " : byte", "")
# alter("Global.proto", "public ", " ")
# alter("Global.proto", "[Description(\"", "//")
# alter("Global.proto", "\")]", "")
# alter("Global.proto", ",", ";")
# create_enum_id("Global.proto","enum")
# create_enum_id("Global.proto","MessageType")


"""
处理stat 
"""
# replace_empty_line("stat.proto")
# create_enum_id("stat.proto","enum")


"""
加上消息类型
"""
# alter_message("C2S.proto","message ","message C2S")


# ServerPackets.cs

# alter("ServerPackets.cs", "public sealed class", "message")
# alter("ServerPackets.cs", ": Packet", "")
# alter_function("ServerPackets.cs", "IsCanFastRead", "")
# alter_function("ServerPackets.cs", "FastWriteObject", "")
# alter_function("ServerPackets.cs", "FastReadObject", "")
# alter_function("ServerPackets.cs", "IsCanFastWirte", "")
# alter("ServerPackets.cs", "public string", "string")
# alter("ServerPackets.cs", " { get; set; }", ";")
# alter("ServerPackets.cs", "public int", "int32")
# alter("ServerPackets.cs", "public String", "string")
# alter("ServerPackets.cs", "public long", "int64")
# alter("ServerPackets.cs", "public bool", "bool")
# delete_constructor("ServerPackets.cs", "()", "")
# replace_empty_line("ServerPackets.cs")
# create_message_id("ServerPackets.cs","message")

# """
# 替换List为repeated
# """
# alter("ServerPackets.cs", "public List<", "repeated ")
# alter("ServerPackets.cs", ">", "")

# """
# 去掉最后的public
# """
# alter("ServerPackets.cs", "public", "")
# """

# alter_message("ServerPackets.cs","message ","message S2C")

# """
# 处理ServerGlobalProto
# """
# alter_function("GlobalServer.proto", "=>", "")
# alter("GlobalServer.proto", "public sealed class", "message")
# alter("GlobalServer.proto", "public int", "int32")
# alter("GlobalServer.proto", "public String", "string")
# alter("GlobalServer.proto", "public long", "int64")
# alter("GlobalServer.proto", "public bool", "bool")
# alter("GlobalServer.proto", " { get; set; }", ";")

# alter("GlobalServer.proto", " { get = 3;  set = 3; }", ";")

# alter("GlobalServer.proto", "\t", "")

# create_message_id("GlobalServer.proto","message")
# create_enum_id("GlobalServer.proto","enum")
# alter("GlobalServer.proto", "List<", "repeated ")
# alter("GlobalServer.proto", ">", "")
# replace_empty_line("GlobalServer.proto")
# delete_line("GlobalServer.proto", "private")
# alter("GlobalServer.proto", ">", "")
# alter("GlobalServer.proto", " { get; set; }", ";")
