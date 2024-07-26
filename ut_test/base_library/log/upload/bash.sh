#!/bin/bash
# 源代码目录相对路径
src_dir=../../../../base_library/log/upload
# 测试代码目录相对路径
test_dir=../upload

#文件cover_report生成目录
build_dir="../../../../build/ut_test/base_library/log/upload"

cd $build_dir

#生成一个名为 init.info 的文件，其中包含了当前目录下的测试覆盖率数据。
lcov -d $src_dir -c -o init.info

#将名为 init.info 的 .info 文件中保存的测试覆盖率数据追加到名为 total.info 的 .info 文件中
lcov -a init.info -o total.info --rc lcov_branch_coverage=1
	
#移除最终得到的效果中与代码测试无关的文件目录
lcov --remove total.info '*/usr/include/*' '*/usr/lib/*' '*/usr/lib64/*' '*/src/log/*' '*/tests/*' '*/usr/local/include/*' '*/usr/local/lib/*' '*/usr/local/lib64/*' '*/home/miaow/work/S32G-UP/s32-Apps/third_part/*' -o final.info

#这段命令的作用是将已经生成的 final.info 文件转换为 HTML 格式的覆盖率报告。
#其中，-o cover_report 表示生成的 HTML 文件的目标路径为 cover_report ，
#--legend 表示在生成的 HTML 文件中显示图例信息，
#--title "lcov" 表示设置生成的 HTML 文件的标题为 lcov ，
#--prefix=$src_dir 表示从覆盖率数据中去掉 $src_dir 前缀，以便更好地排版和可读性。
genhtml -o cover_report --legend --title "lcov"  --prefix=$src_dir final.info --branch-coverage
