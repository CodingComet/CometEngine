#pragma once
#include <vector>
#include <unordered_map>
#include <optional>
#include "common.h"

class EntityManager
{
public:
	size_t construct_entity() noexcept;
	void deconstruct_entity(size_t id) noexcept;
	void set_signature(size_t id, size_t index, bool value) noexcept;
	std::optional<component_signature> get_signature(size_t id) const noexcept;

	//private:
	size_t current_id;
	std::unordered_map<size_t, component_signature> signatures;
};
