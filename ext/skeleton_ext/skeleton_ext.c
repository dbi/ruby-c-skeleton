#include "skeleton_ext.h"

static VALUE run(int argc, VALUE* argv, VALUE self) {
  int i;
  for (i = 0; i < 10000; ++i) {
    for (i = 0; i < 10000; ++i) {
      rb_genrand_real(); // functionally the same as: rb_eval_string("rand");
    }
  }
  return Qnil;
}

void Init_skeleton_ext(void) {
  VALUE rb_mSkeleton = rb_define_module("Skeleton");
  VALUE rb_cPerformance = rb_define_class_under(rb_mSkeleton, "Performance", rb_cObject);
  rb_define_method(rb_cPerformance, "run", run, -1);
}
