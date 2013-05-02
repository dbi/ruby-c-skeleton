Presentation
------------


PLAN
----

    tree -C

    cat test/skeleton_spec.rb

    cat lib/skeleton/skeleton_pure.rb

    time ruby -Ilib test/skeleton_spec.rb
    # real	0m11.654s

    cat lib/skeleton.rb

SETUP
-----

    tree -C

    cat ext/skeleton_ext/extconf.rb

    rake compile

    tree -C

    rake clobber

    vim Rakefile

OPTIMIZE
--------

    vim ext/skeleton_ext/skeleton_ext.c
    vim ext/skeleton_ext/skeleton_ext.h

    rake compile

    time ruby -Ilib test/skeleton_spec.rb
    # real	0m0.294s

    time ruby -Ilib -e "require 'skeleton';Skeleton::Performance.new.run"
    # real	0m0.111s

C API
-----

    VALUE & Qnil
    ALLOC_N
    kapitel i pickaxe
