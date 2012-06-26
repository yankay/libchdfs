libhadoop
=========

libhadoop is a pure c/c++ library for hadoop hdfs like libhdfs.

=========

Hadoop only has a pure java client but any other language. libhadoop is a pure c/c++ one. With it any c/c++ application such as NFS server can use hadoop/hdfs easier.
Python/Ruby/Perl cannot integrate with Java but they all can integrate with c/c++.So we can also make hadoop library for other language based on it!

=========

Why not libhdfs? The libhdfs is based on JNI, which means we must use a JVM to use it, its waste memory and may cause memory leak.
Why not thrift? To use thrift we must start a thrift server which works as a proxy. It's not very effectively. And the proxy can cause a single point failure. 



