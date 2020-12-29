#include "symtab.h"
#include "scanner.h"

/*search the name in sym_tab and return it */
Attributes& Symbol_table::get(string name)
{
    map<string, Attributes>::iterator it=sym_tab.find(name);
    return it->second;
}

/*search for the name and set it to double we gets*/
void Symbol_table::set(string name, double nv)
{
    auto it=get(name);
    if(it.is_const){
        error("cannot change constant");
    }else{
        map<string, Attributes>::iterator it=sym_tab.find(name);
        it->second.value=nv;
    }
}

/* search for the name in the map  if found return true else false*/
bool Symbol_table::is_declared(string name)
{
        map<string, Attributes>::iterator it=sym_tab.find(name);
        //find return end if it isn't find the value
        if(it==sym_tab.end()){
            return false;
        }
        else{
            return true;
        }

}
/* declare on a value if it doesn't exist */
void Symbol_table::declare(string name, double nv, bool ic)
{
    if(is_declared(name)==false){
        Attributes a= Attributes(nv,ic);
        sym_tab.insert({name,a});

    }
}

