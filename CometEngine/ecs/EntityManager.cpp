#include "EntityManager.h"

size_t EntityManager::construct_entity() noexcept
{
	signatures.insert({ current_id, 0 });
	return current_id++;
}

void EntityManager::deconstruct_entity(size_t id) noexcept
{
	auto it = signatures.find(id);
	if (it != signatures.end()) signatures.erase(it);
}

std::optional<component_signature> EntityManager::get_signature(size_t id) const noexcept
{
	auto it = signatures.find(id);
	if (it == signatures.end()) return std::nullopt;


	return std::make_optional(it->second);
}

void EntityManager::set_signature(size_t id, size_t index, bool value) noexcept
{
	signatures[id].set(index, value);
}