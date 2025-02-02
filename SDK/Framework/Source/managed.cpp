/*
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
#include <FE/framework/managed.hpp>




BEGIN_NAMESPACE(FE::framework)


managed::managed(FE::uint32 max_concurrency_p) noexcept
	: m_thread_local_ref_tables(std::make_unique<FE::block_pool<FE::PoolPageCapacity::_256KB, managed::ref_block_size, FE::SIMD_auto_alignment>[]>(max_concurrency_p))
{
}


END_NAMESPACE
