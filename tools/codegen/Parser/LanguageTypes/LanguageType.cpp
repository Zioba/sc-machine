#include "Precompiled.hpp"

#include "LanguageType.hpp"

LanguageType::LanguageType(
	const Cursor &cursor, 
	const Namespace &currentNamespace
)
    : m_metaData(cursor)
    , m_enabled(m_metaData.GetFlag(kMetaEnable))
    , m_ptrTypeEnabled(!m_metaData.GetFlag(kMetaDisablePtrType))
    , m_constPtrTypeEnabled(!m_metaData.GetFlag(kMetaDisableConstPtrType))
    , m_accessModifier(cursor.GetAccessModifier())
    , m_currentNamespace(currentNamespace)
{
    
}

const MetaDataManager &LanguageType::GetMetaData(void) const
{
    return m_metaData;
}