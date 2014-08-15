ruby_fstools
============

ruby fstools は Ruby 拡張機能の作り方の練習で書きました。

** コンパイル

```
git clone git@github.com:takuya/ruby_fstools.git
cd ruby_fstools
make
```

** File.cp / File.copy

Ruby の 1.8 時代に存在した File.cp の機能を C 言語拡張で書いています。

```
require './fstools'
File.copy("README.md", "copied.md")
```


** 参考資料

http://i.loveruby.net/w/RubyExtensionProgrammingGuide.html

http://www.metareal.org/2007/06/14/ruby-extension-struct-rstring-macros/

http://docs.ruby-lang.org/ja/1.8.7/method/File/s/copy.html

http://java.ociweb.com/mark/NFJS/RubyCExtensions.pdf

http://ruby.gfd-dennou.org/tutorial/ruby-ext/

http://stackoverflow.com/questions/2180079/how-can-i-copy-a-file-on-unix-using-c
