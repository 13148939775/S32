编译方法：
1）X86方式
cmake -Bbuild -Hiceoryx_meta -DBUILD_TEST=ON -DINTROSPECTION=OFF -DBINDING_C=ON -DEXAMPLES=ON
cmake --build build