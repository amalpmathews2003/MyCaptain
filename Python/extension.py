file_name=input("Input the Filename: ")
extensions={"py":"python","cpp":"c++","js":"javascript","html":"html"}

file_ext=file_name.split(".")[1]
print(f"The extension of the file is :{extensions[file_ext]}")
