#include "engine/resmanager.h"

namespace Engine
{
	template <class T>
	ResourceManager<T>::~ResourceManager()
	{
		
	}
	
	template <class T>
	Resource<T>* ResourceManager<T>::Load(const std::string& Path, const std::string& Filename)
	{
		for(class std::list<Resource<T>*>::iterator i = m_Resources.begin(); i != m_Resources.end(); ++i)
		{
			if((*i)->Path.compare(Path) == 0)
				if((*i)->Filename.compare(Filename) == 0)
					return (*i);
		}
		
		std::string Fullpath = Path;
		Fullpath.append("/");
		Fullpath.append(Filename);
		
		T Underlying = Load(Fullpath);
		Resource<T>* Loaded = new Resource<T>(Path, Filename, Underlying, this);
		
		m_Resources.Add(Loaded);
		
		return Loaded;
	}
	
	template <class T>
	void ResourceManager<T>::Unload(Resource<T>* Resource)
	{
		if(!Resource)
			return;
		
		m_Resources.remove(Resource);
		delete Resource;
	}
}

