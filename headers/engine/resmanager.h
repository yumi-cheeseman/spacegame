#ifndef INCLUDES_ENGINE_RESMANAGER_H
#define INCLUDES_ENGINE_RESMANAGER_H

#include "common.h"

#include <list>
#include <string>

// TODO: Add support for an OnUnload event, so you can delete the resource how you like.

namespace Engine
{
	template <class T>
	class ResourceManager;

	// A wrapper class for a resource, keeps ResourceManager clean. It also keeps
	// track of how many times it is referenced.
	template <class T>
	class Resource
	{
		public:
			Resource(const std::string& Path, const std::string& Filename, const T& Underlying, ResourceManager<T>* Manager)
				: Path(Path), Filename(Filename), Underlying(Underlying), m_Manager(Manager), m_Refs(1)
			{ }
			
			void Reference( void )
			{
				++m_Refs;
			}
			
			void Free( void )
			{
				--m_Refs;
				
				if(m_Refs <= 0)
					m_Manager->Unload(this);
			}
			
			std::string Path;
			std::string Filename;
			T Underlying;
			
		private:
			ResourceManager<T>* m_Manager;
			unsigned int m_Refs;
	};
	
	template <class T>
	class ResourceManager
	{
		public:
			~ResourceManager();
			
			Resource<T>* Load(const std::string& Path, const std::string& Filename);
			void Unload(Resource<T>* Resource);
		
		protected:
			std::list<Resource<T>*> m_Resources;
			
			// A very dirty method of loading a specific type.
			virtual T Load(const std::string& Fullpath) = 0;
	};
}

#endif /* INCLUDES_ENGINE_RESMANAGER_H */

