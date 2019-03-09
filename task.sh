function read_dir(){
for file in `ls $1` #注意此处这是两个反引号，表示运行系统命令
do
 if [ -d $1"/"$file ] #注意此处之间一定要加上空格，否则会报错
 then
 read_dir $1"/"$file
 else
    if [ ${file:0-4} = "orig" ]
    then
        rm -f $1"/"$file
    fi
 fi
done
}
read_dir $1