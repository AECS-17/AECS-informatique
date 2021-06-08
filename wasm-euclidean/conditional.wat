;; Copyright 2021 Frédéric Wang. All rights reserved.
;; Use of this source code is governed by a BSD-style license that can be
;; found in the LICENSE.BSD file.
(func (export "main") (param $a i32) (result i32)
    local.get $a
    i32.const -2
    i32.ge_s
    if (result i32) ;; a >= -2
       local.get $a
       local.get $a
       i32.mul
       i32.const 4
       i32.sub
    else            ;; a <= -2
       local.get $a
       i32.const 2
       i32.add
    end
)
