;; Copyright 2021 Frédéric Wang. All rights reserved.
;; Use of this source code is governed by a BSD-style license that can be
;; found in the LICENSE.BSD file.
(func $gcd (export "main") (param $a i32) (param $b i32) (result i32)
    local.get $b
    i32.eqz
    if (result i32)
        local.get $a
    else
        local.get $b
        local.get $a
        local.get $b
        i32.rem_s
        call $gcd ;; call gcd recursively
    end
)
