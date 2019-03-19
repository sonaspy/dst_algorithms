function read_dir(){
for file in `ls $1` 
do
 if [ -d $1"/"$file ]
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