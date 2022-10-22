/*
 * @file      : eigens.h
 * @author    : Zhi Liu
 * @email     : zhiliu.mind@gmail.com
 * @homepage  : http://iridescent.ink
 * @date      : Sat Oct 22 2022
 * @version   : v0.0
 * @license   : The Apache License 2.0
 * @note      : 
 * 
 * The Apache 2.0 License (MIT)
 * Copyright (C) 2013 Zhi Liu
 *
 *Licensed under the Apache License, Version 2.0 (the "License");
 *you may not use this file except in compliance with the License.
 *You may obtain a copy of the License at
 *
 *http://www.apache.org/licenses/LICENSE-2.0
 *
 *Unless required by applicable law or agreed to in writing, software
 *distributed under the License is distributed on an "AS IS" BASIS,
 *WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *See the License for the specific language governing permissions and
 *limitations under the License.
 */

#include <cmatrix.h>

int cmeig(cmatrix *pA, cmatrix *pS, cmatrix *pV);

