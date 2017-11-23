
#ifndef H_fde1b82fdd1b2954c98ba29aa4a2af01_H
#define H_fde1b82fdd1b2954c98ba29aa4a2af01_H




//BEGIN_GROUP_COMMENT
/**
*/
//END_GROUP_COMMENT


//BEGIN_USER_SECTION_0

//END_USER_SECTION_0


namespace oldportal 
{
namespace util 
{
namespace serialization 
{
// global variables declaration
}// namespace serialization
}// namespace util
}// namespace oldportal


namespace oldportal 
{
namespace util 
{
namespace serialization 
{
// global methods declaration
std::vector< std::shared_ptr<oldportal::util::serialization::Serializable> > load_from_xml(pugi::xml_node& archive);

void save_to_xml(pugi::xml_node& archive, std::vector< std::shared_ptr<oldportal::util::serialization::Serializable> > root_objects);

}// namespace serialization
}// namespace util
}// namespace oldportal





#endif // H_fde1b82fdd1b2954c98ba29aa4a2af01_H

#ifdef OBJECTS_BUILDER_PROJECT_INLINES
#ifndef H_fde1b82fdd1b2954c98ba29aa4a2af01_INLINES_H
#define H_fde1b82fdd1b2954c98ba29aa4a2af01_INLINES_H
//BEGIN_USER_SECTION_1

//END_USER_SECTION_1


#endif // H_fde1b82fdd1b2954c98ba29aa4a2af01_INLINES_H

#endif //OBJECTS_BUILDER_PROJECT_INLINES