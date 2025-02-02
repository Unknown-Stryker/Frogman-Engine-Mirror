﻿/*
Copyright © from 2022 to present, UNKNOWN STRYKER. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma warning (disable: 4819) //1 > C:\Users\leeho\OneDrive\문서\GitHub\Frogman - Engine\SDK\Third - Party\Libraries\Robin - Hood - Hash\robin_hood.h(1, 1) : warning C4819 : The file contains a character that cannot be represented in the current code page(949).Save the file in Unicode format to prevent data loss

#include <FE/hash.hpp>


FE::random_integer<var::uint64> FE::hash_base::s_random_integer;
FE::uint64 FE::hash_base::s_seed = s_random_integer.ranged_random_integer(0, FE::max_value<var::uint64>);