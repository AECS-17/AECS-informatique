;; Copyright 2021 Frédéric Wang. All rights reserved.
;; Use of this source code is governed by a BSD-style license that can be
;; found in the LICENSE.BSD file.
(func $gcd (export "main") (param $a i32) (param $b i32) (result i32)
    local.get $b
    if (result i32)
        loop
            local.get $b
            local.get $a
            local.get $b
            i32.rem_s
            local.set $b
            local.set $a
            local.get $b
            br_if 0 ;; Go back to the beginning of the loop if b is nonzero.
        end
        local.get $a
    else
       local.get $a
    end
)
