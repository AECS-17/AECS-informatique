;; Copyright 2021 Frédéric Wang. All rights reserved.
;; Use of this source code is governed by a BSD-style license that can be
;; found in the LICENSE.BSD file.
(func (export "main") (param $a i32) (param $b i32) (result i32)
    ;; Return the of integers a and b.
    local.get $a
    local.get $b
    i32.add
)
