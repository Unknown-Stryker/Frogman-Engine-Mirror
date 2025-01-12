﻿/*
Copyright © from 2024 to present, UNKNOWN STRYKER. All Rights Reserved.

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
#include "header_tool_engine.hpp"




void header_tool_engine::__generate_reflection_code(const header_file_root& tree_p) noexcept
{
	__traverse_reflection_tree(tree_p);
}


void header_tool_engine::__traverse_reflection_tree(const header_file_root& tree_p) noexcept
{
	(void)tree_p;
	//for (const auto& node :)
	//	__traverse_namespace_node(node);
}


void header_tool_engine::__traverse_namespace_node(const namespace_node& node_p) noexcept
{
	(void)node_p;
}


void header_tool_engine::__traverse_class_node(const class_node& node_p) noexcept
{
	(void)node_p;
}


void header_tool_engine::__traverse_struct_node(const struct_node& node_p) noexcept
{
	(void)node_p;
}